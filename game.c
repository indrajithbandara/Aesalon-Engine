#include <stdio.h>
#include </usr/include/SDL2/SDL.h>

int main() {
    int hres,vres;
    printf("Enter Horizontal Resolution:\t");
    scanf("%d",&hres);
    printf("Enter Vertical Resolution:\t");
    scanf("%d",&vres);
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *win = SDL_CreateWindow("Falcon",0,0,hres,vres,SDL_WINDOW_FULLSCREEN|SDL_WINDOW_OPENGL);
    SDL_GL_CreateContext(win);
    /*START MAKING OPENGL CALLS HERE.*/
    SDL_GL_SwapWindow(win);
    return 0;
}
