#include <stdio.h>
#include </usr/include/SDL2/SDL.h>

#define VERSION "0.01-prealpha"

#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"

void printAction(char *msg) {
    printf("%s%s%s\t\t\t",RED,msg,RESET);
}

void printStatus(short i) {
    if (i) printf("%s[OK]%s\n",GREEN,RESET);
    else   printf("%s[FAIL]\nERROR DETAILS: %s%s%s\n",RED,YELLOW,SDL_GetError(),RESET);
}

int main() {
    int hres,vres;
    printf("===============================================\n|  mmmmmm   mm   m        mmm   mmmm  mm   m  |\n|  #        ##   #      m\"   \" m\"  \"m #\"m  #  |\n|  #mmmmm  #  #  #      #      #    # # #m #  |\n|  #       #mm#  #      #      #    # #  # #  |\n|  #      #    # #mmmmm  \"mmm\"  #mm#  #   ##  |\n================================GAME==ENGINE===\n\n");
    printf("Enter Horizontal Resolution:\t");
    scanf("%d",&hres);
    printf("Enter Vertical Resolution:\t");
    scanf("%d",&vres);
    
    printAction("Initialising SDL...");
    if (!SDL_Init(SDL_INIT_EVERYTHING)) printStatus(1);
    else printStatus(0);
    printAction("Detecting Gamepads/Joysticks...");
    printf("\n\n%s  %sDetected%s_____________________________\n\n%s",RED,GREEN,RED,RESET);
    short i;
    for (i = 0; i < SDL_NumJoysticks(); i++) printf("  %s%s%s\n",GREEN,SDL_JoystickNameForIndex(i),RESET);
    printf("  %s_____________________________________%s\n\n",RED,RESET);
    /* START 3D */
    puts("Press Enter to Launch Game");
    getchar();

    SDL_Window *win = SDL_CreateWindow("Falcon",0,0,hres,vres,SDL_WINDOW_FULLSCREEN|SDL_WINDOW_OPENGL);
    SDL_GL_CreateContext(win);
    /* START MAKING OPENGL CALLS HERE */
    SDL_GL_SwapWindow(win);
    return 0;
}
