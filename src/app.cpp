#include "includes.h"

GloryApp::~GloryApp() {

    glDeleteBuffers(1, &ebo);
    glDeleteBuffers(1, &vbo);

    glDeleteVertexArrays(1, &vao);

    SDL_GL_DeleteContext(context);
    SDL_DestroyWindow(window);

}

void GloryApp::init_sdl(void) {

    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

    window = SDL_CreateWindow(
        "GLory",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
        SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

    context = SDL_GL_CreateContext(window);

}

void GloryApp::process_events(void) {

    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                done = true;
                break;
            case SDL_KEYDOWN:
                if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
                    done = true;
                }
                break;
        }
    }

}

void GloryApp::run_timing(void) {

    SDL_Delay(17);

}

void GloryApp::draw_triangle(void) {

    //glDrawArrays(GL_TRIANGLES, 0, 3);
    // using the element array. six values, uints, no offset
    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);

}

void GloryApp::render(void) {

    // Clear the screen to black
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    draw_triangle();

    SDL_GL_SwapWindow(window);

}

GLuint GloryApp::init_test(void) {

    // create a vertex array object (vao)
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    // allocate a vertex buffer object on the video card
    glGenBuffers(1, &vbo);

    // allocate an element buffer objecct on the video card
    glGenBuffers(1, &ebo);

    GLuint elements[] = {
        0, 1, 2,
        2, 3, 0
    };

    GLfloat vertices[] = {
        // x      y     r     g     b
        -0.5f,  0.5f, 1.0f, 0.0f, 0.0f, // top left
         0.5f,  0.5f, 0.0f, 1.0f, 0.0f, // top right
         0.5f, -0.5f, 0.0f, 0.0f, 1.0f, // bottom right
        -0.5f, -0.5f, 1.0f, 1.0f, 1.0f  // bottom left
    };

    // make it an array buffer
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    // tell the video card how much to allocate
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // same for elements
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elements), elements, GL_STATIC_DRAW);

    // load shader programs
    GLuint prog = sm.create_program("shaders/vertex/cornercolor.glsl", "shaders/fragment/cornercolor.glsl");

    glUseProgram(prog);

    // tell shader program how to interact outside itself
    GLint posAttrib = glGetAttribLocation(prog, "position");
    glEnableVertexAttribArray(posAttrib);
    glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), 0);

    GLint colAttrib = glGetAttribLocation(prog, "color");
    glEnableVertexAttribArray(colAttrib);
    glVertexAttribPointer(colAttrib, 3, GL_FLOAT, GL_FALSE,
                          5 * sizeof(GLfloat),
                          (void*)(2 * sizeof(GLfloat)));

    return 0;

}

int GloryApp::run(void) {

    debugout("Running glory");

    init_sdl();
    auto uniColor = init_test();

    auto t_start = std::chrono::high_resolution_clock::now();

    while (!done) {
        run_timing();
        process_events();
        render();

        auto t_now = std::chrono::high_resolution_clock::now();
        float time = std::chrono::duration_cast<std::chrono::duration<float>>(t_now - t_start).count();

        glUniform3f(uniColor, (sin(time * 4.0f) + 1.0f) / 2.0f, 0.0f, 0.0f);

    }

    debugout("Finished running glory");

    SDL_Quit();

    return 0;

}