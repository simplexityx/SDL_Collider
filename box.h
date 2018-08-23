#ifndef BOX_H
#define BOX_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>



typedef struct box box_t;
typedef void (*UPDATE_FUNC)(box_t *);
typedef void (*COLLISION_FUNC)(box_t *);

typedef struct velocity{
    int x, y;
}velocity_t;



struct box{
    SDL_Texture *tex;
    SDL_Rect src, dst;
    int id;
    UPDATE_FUNC up;
    COLLISION_FUNC col;
    velocity_t vel;
};




box_t *box_create(const char *filepath, int xPos, int yPos, SDL_Renderer *rend, UPDATE_FUNC upfunc, COLLISION_FUNC colfunc);

void box_destroy(box_t *box);

void box_update(box_t *b);

void box_collide(box_t *b);


#endif