class GloryApp {

    void init_sdl(void);
    GLuint init_test(void);

    void run_timing(void);
    void process_events(void);
    void render(void);

    void draw_triangle(void);

    bool done = false;

    ShaderManager sm;
    GLuint vao;
    GLuint ebo, vbo;

    SDL_Window *window;
    SDL_GLContext context;

public:

    ~GloryApp();

    int run(void);

};
