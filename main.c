#include "Renderer.h"
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int main(){
    
    renderer_t *r = malloc(sizeof(renderer_t));

    renderer_init("title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, r);
    pthread_t t1, t2, t3;
    pthread_create(&t1, NULL, eventHandler, (void*)r);
    pthread_create(&t2, NULL, draw, (void*)r);
    pthread_create(&t3, NULL, update, (void*)r);
    
    pthread_join(t1, NULL);

    while(r->running){
        //eventHandler(r);
        update(r);
        draw(r);
        SDL_Delay(1000 / 60);
    }

    clean(r);
    return 0;
}
