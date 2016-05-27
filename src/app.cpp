#include "includes.h"

GloryApp::~GloryApp() {

    SDL_DestroyWindow(window);

}

void GloryApp::init_sdl(void) {

    SDL_Init(SDL_INIT_EVERYTHING);

    window = SDL_CreateWindow(
        "GLory",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
        SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

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

void GloryApp::run_timing() {

    SDL_Delay(17);

}

void GloryApp::render(void) {

    // draw_triangle();

    SDL_GL_SwapWindow(window);

}

void GloryApp::init_test(void) {

    glGenVertexArrays(1, &vaid);
    glBindVertexArray(vaid);

}

int GloryApp::run(void) {

    debugout("Running glory");

    init_sdl();
    init_test();

    while (!done) {
        run_timing();
        process_events();
        render();
    }

    debugout("Finished running glory");

    SDL_Quit();

    return 0;

}