class GloryApp {
    void init_sdl(void);
    void init_test(void);

    void run_timing(void);
    void process_events(void);
    void render(void);

    bool done = false;

    SDL_Window *window;
    SDL_GLContext glcontext;
    GLuint vaid;
public:
    ~GloryApp();

    int run(void);
};
