#include <SDL2/SDL.h>
#include "tree.h"


typedef struct renderer{
    SDL_Renderer *renderer;
    SDL_Window *win;
    tree_t *tree;
    char running;
    SDL_Event event;
}renderer_t;


void renderer_init(const char *title, int xpos, int ypos, int screenWidth, int screenHeight, renderer_t *r);

void update(renderer_t *r);

void draw(renderer_t *r);

void eventHandler(renderer_t *r);

void clean(renderer_t *r);



