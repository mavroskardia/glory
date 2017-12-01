class GloryApp {

    void init_sdl(void);
    void init_textures(void);
    void init_shaders(void);
    void init_buffers(void);
    void init_matrices(void);

    void process_events(void);
    void render(void);
    void update(const float dt);

    bool done = false;
    int ticks;

    ShaderManager sm;
    TextureManager tm;

    GLuint vao;
    GLuint ebo, vbo;

    GLint posAttrib, colAttrib, texAttrib;
    GLint uniModel, uniView, uniProj;
    GLuint uniColor;

    glm::mat4 model;
    glm::mat4 view;
    glm::mat4 proj;

    SDL_Window *window;
    SDL_GLContext context;

public:

    ~GloryApp();

    int run(void);

};
