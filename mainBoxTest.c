#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "box.h"
int main(){
  
    SDL_Renderer *renderer;
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		SDL_Window *win = SDL_CreateWindow("title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
		
		renderer = SDL_CreateRenderer(win, -1, 0);
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		}
    }

    SDL_Event event;

    box_t *box = box_create("box.png", 400, 300, renderer, box_update, box_collide);

    while(1){

        SDL_PollEvent(&event);
        if(event.type == SDL_QUIT){
            break;
        }

        SDL_RenderClear(renderer);

        
        SDL_RenderCopy(renderer, box->tex, &box->src, &box->dst);
        SDL_RenderPresent(renderer);
        SDL_Delay(1000/60);
    }   
   

    return 0;
}
