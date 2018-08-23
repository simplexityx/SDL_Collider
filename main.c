#include "Renderer.h"



int main(){

    renderer_t *r = malloc(sizeof(renderer_t));

    renderer_init("title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, r);
    
    while(r->running == 1){
        eventHandler(r);
        update(r);
        draw(r);
    }

    clean(r);

    return 0;
}
