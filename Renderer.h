#ifndef RENDERER_H
#define RENDERER_H

#include <SDL2/SDL.h>
#include "tree.h"
#include <stdlib.h>
#include <stdio.h>
typedef struct tree tree_t;
typedef struct renderer{
    SDL_Renderer *renderer;
    SDL_Window *win;
    tree_t *tree;
    char running;
    SDL_Event event;
}renderer_t;


void renderer_init(const char *title, int xpos, int ypos, int screenWidth, int screenHeight, renderer_t *r);

void update(void *r);

void draw(void *r);

void* eventHandler(void *r);

void clean(renderer_t *r);


#endif
