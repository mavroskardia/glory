class GloryApp {

    void init_sdl(void);
    GLuint init_test(void);
    void init_textures(void);

    void run_timing(void);
    void process_events(void);
    void render(void);

    void draw_triangle(void);

    bool done = false;
    int ticks;

    ShaderManager sm;
    GLuint vao;
    GLuint ebo, vbo;
    GLuint prog;

    SDL_Window *window;
    SDL_GLContext context;

public:

    ~GloryApp();

    int run(void);

};
