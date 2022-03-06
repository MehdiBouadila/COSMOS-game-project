#ifndef FONCTION_H
#define FONCTION_H
#define SCREEN_W 800
#define SCREEN_H 400
#include <SDL/SDL_timer.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>


typedef struct{
SDL_Rect pos1;
SDL_Rect pos2;
SDL_Surface *Img;
} Image;


typedef struct
{

SDL_Rect Position;
TTF_Font *Font;
SDL_Surface *surfaceTexte;
SDL_Color textColor;
char Text[50];

}Text;

void initBackground(Image *Background);

 
void animation(SDL_Surface *Screen, SDL_Surface *menu[]);

void settings(SDL_Surface *Screen, SDL_Surface *retour, int *volume, int *p);
void newgame(SDL_Surface *Screen, SDL_Surface *retour);



#endif // FONCTION_H_INCLUDED
