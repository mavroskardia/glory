#include "includes.h"

void GloryApp::init(void) {
    SDL_Init(SDL_INIT_EVERYTHING);
}

void GloryApp::process_events(void) {

}

void GloryApp::render(void) {

}

int GloryApp::run(void) {
    debugout("Running glory");

    init();

    while (!done) {
        // run_timing();
        process_events();
        render();
    }

    debugout("Finished running glory");
    return 0;
}