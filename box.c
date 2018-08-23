#include "box.h"


SDL_Texture *TextureManager(const char *filepath,SDL_Renderer *rend){
    SDL_Surface *s = IMG_Load(filepath);
    SDL_Texture *tex = SDL_CreateTextureFromSurface(rend, s);
    SDL_FreeSurface(s);
    return tex;
}

static int a = 0;

int getID(){
    a++;
    return a;
}

box_t *box_create(const char *filepath, int xPos, int yPos, SDL_Renderer *rend, UPDATE_FUNC upfunc, COLLISION_FUNC colfunc){

    box_t *newBox = malloc(sizeof(box_t));

    newBox->src.x = newBox->src.y = 0;
    newBox->dst.x = xPos;
    newBox->dst.y = yPos;
    newBox->dst.w = newBox->dst.h = newBox->src.w = newBox->src.h = 32;

    newBox->tex = TextureManager(filepath, rend);

    newBox->up = upfunc;    
    newBox->col = colfunc;

    newBox->vel.x = rand() % 10;
    newBox->vel.y = rand() % 10;

    newBox->id = getID();

    return newBox;
}



void box_destroy(box_t *box){

    SDL_DestroyTexture(box->tex);
    free(box);
    return;
}



void box_update(box_t *b){
    b->dst.x += b->vel.x;
    b->dst.y += b->vel.y;
    return;
}

void box_collide(box_t *b){

    if(b->dst.x > 800 || b->dst.x < 0 || b->dst.y > 600 || b->dst.y < 0){
        b->vel.x *= -1;
        b->vel.y *= -1;
    }
    //TODO collider with other boxes
    return;
}




