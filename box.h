#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

typedef struct box{
    SDL_Texture *tex;
    SDL_Rect src, dst;

}box_t;


box_t *box_create();






