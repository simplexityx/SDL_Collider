#include "Renderer.h"


int compareInts(void *a, void *b){
    if(*(int*)a > *(int*)b)
        return 1;
    else 
        return -1;
}

void renderer_init(const char *title, int xpos, int ypos, int screenWidth, int screenHeight, renderer_t *r){

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		r->win = SDL_CreateWindow(title, xpos, ypos, screenWidth, screenHeight, 0);
		
		r->renderer = SDL_CreateRenderer(r->win, -1, 0);
		if (r->renderer) {
			SDL_SetRenderDrawColor(r->renderer, 255, 255, 255, 255);
		}
    }
    r->tree = tree_create(compareInts);
    r->running = 1;
    return;
}



void update(renderer_t *r){

    

}


void draw(renderer_t *r){

}

void eventHandler(renderer_t *r){

    SDL_PollEvent(&r->event);
    if (r->event.type == SDL_QUIT) {
		r->running = 0;
    }
}

void clean(renderer_t *r){

    SDL_DestroyRenderer(r->renderer);
    SDL_DestroyWindow(r->win);
    
    //TODO make a destroy tree function
    free(r->tree);
    free(r);
    return;
}   

