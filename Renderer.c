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

    box_t *b = box_create("box.png", 400, 300, r->renderer, box_update, box_collide);
    box_t *b2 = box_create("box.png", 400, 100, r->renderer, box_update, box_collide);

    tree_insert(r->tree, b);
    tree_insert(r->tree, b2);
    return;
}



void update(void *r){
    renderer_t *re = r;
    while(re->running != 0){
        tree_update(re->tree);
        SDL_Delay(1000/60);

    }
}


void draw(void *r){
    renderer_t *re = r;
    while(re->running != 0){
    SDL_RenderClear(re->renderer);
    tree_draw(re->tree, re);
    SDL_RenderPresent(re->renderer);
    SDL_Delay(1000/60);
    
    }
}

void* eventHandler(void *r){
    renderer_t *re = r;
    while(re->running != 0){
        SDL_PollEvent(&re->event);
        if (re->event.type == SDL_QUIT) {
            re->running = 0;
        }else if(re->event.type == SDL_MOUSEBUTTONDOWN){
            int x, y;
            SDL_GetMouseState(&x, &y);
            box_t *b = box_create("box.png", x, y, re->renderer, box_update, box_collide);
            tree_insert(re->tree, b);
            SDL_Delay(1000/60);
        }
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

