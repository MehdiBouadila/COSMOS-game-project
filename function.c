#include "fonctionsmenu.h"







void initBackground(Image *Background)
{
 
 Background->Img = IMG_Load("menu 1.jpg");
 
 
 if(Background->Img == NULL)
 {
 
 printf("L'nitialisation du background a echouee!\n");
 	return;
 }
 
 Background->pos1.x = 0;
 Background->pos1.y = 0;
 
 Background->pos2.x = 0;
 Background->pos2.y = 0;
 Background->pos2.w = SCREEN_W;
 Background->pos2.h = SCREEN_H;
 
  }



void animation(SDL_Surface *Screen, SDL_Surface *menu[])

{

  int i;
  SDL_Rect posbackground;
  posbackground.x=0;
  posbackground.y=0;
  
  
  for(i = 0; i<4; i++)
  {

   SDL_BlitSurface(menu[i], NULL, Screen, &posbackground);
   SDL_Flip(Screen);
   SDL_Delay(20);
  }
   }
   
  void newgame(SDL_Surface *Screen, SDL_Surface *retour) 
{      
SDL_Surface *newgamescreen;


newgamescreen = IMG_Load("newgame.jpg");



	SDL_Rect posbackground, posreturn;
	
	posbackground.x = 0;
	posbackground.y = 0;
	
	posreturn.x = 20;
	posreturn.y = 300;
	
	SDL_BlitSurface(newgamescreen, NULL, Screen, &posbackground);
	SDL_BlitSurface(retour, NULL, Screen, &posreturn);
	

}


	
	


void settings(SDL_Surface *Screen, SDL_Surface *retour, int *volume, int *p)
{
	
	SDL_Rect posvol, posplusvol, posmoinsvol, posfullscreen, posnormalscreen, posbackground, posreturn;
	SDL_Surface *VOL[4], *volplus = NULL, *volmoins = NULL, *fullscreen = NULL, *normalscreen = NULL, *settingsscreen = NULL, *Return = NULL;
	int z = *p, back = 0;
	Mix_Chunk *clickSound;
	clickSound=Mix_LoadWAV("click.wav");
	
	Mix_VolumeMusic(*volume);
	
	posvol.x = 330;
	posvol.y = 190;
	
	posbackground.x = 0;
	posbackground.y = 0;
	
	posplusvol.x = 480;
	posplusvol.y = 200;
	
	posmoinsvol.x = 290;
	posmoinsvol.y = 200;
	
	posfullscreen.x = 300;
	posfullscreen.y = 270;
	
	posnormalscreen.x = 430;
	posnormalscreen.y = 270;
	
	posreturn.x = 20;
	posreturn.y = 300;
	
settingsscreen = IMG_Load("settings.png");
Return = IMG_Load("return.png");
volplus = IMG_Load("plus.png");
volmoins = IMG_Load("moins.png");

fullscreen = IMG_Load("expand.png");
normalscreen = IMG_Load("compress.png");	
	
VOL[0]=IMG_Load("volu0.png");
VOL[1]=IMG_Load("volu2.png");
VOL[2]=IMG_Load("volu6.png");
VOL[3]=IMG_Load("volu8.png");


	
	 SDL_BlitSurface(settingsscreen, NULL, Screen, &posbackground);
        SDL_BlitSurface(VOL[z], NULL, Screen, &posvol);
        SDL_BlitSurface(volplus, NULL, Screen, &posplusvol);
        SDL_BlitSurface(volmoins, NULL, Screen, &posmoinsvol);
        SDL_BlitSurface(fullscreen, NULL, Screen, &posfullscreen);
        SDL_BlitSurface(normalscreen, NULL, Screen, &posnormalscreen);
        SDL_BlitSurface(retour, NULL, Screen, &posreturn);
        SDL_Flip(Screen);

	
	                  
        
        

      	
        
         int x, y;
                  
  	SDL_Event event2; 
      		while(SDL_PollEvent(&event2))
      			{

          		switch(event2.type)
          		{
          		case SDL_MOUSEMOTION:
                                        x = event2.motion.x;
                                        y = event2.motion.y;

					if(x >= posmoinsvol.x && x <= posmoinsvol.x+posmoinsvol.w && y >= posmoinsvol.y && y <= posmoinsvol.y+posmoinsvol.h)
						{         
						Mix_PlayChannel(-1, clickSound, 0);
				                volmoins = IMG_Load("moinsp.png");
				                 
        SDL_BlitSurface(volmoins, NULL, Screen, &posmoinsvol);
   		   
						}
		else if(x >= posplusvol.x && x <= posplusvol.x+posplusvol.w && y >= posplusvol.y && y <= posplusvol.y+posplusvol.h)
						{         
						Mix_PlayChannel(-1, clickSound, 0);
				                volplus = IMG_Load("plusp.png");
   		   SDL_BlitSurface(volplus, NULL, Screen, &posplusvol);
						}
						break;
						
          		case SDL_MOUSEBUTTONUP:
                 	{ 
                 	
              
                 	 if((*volume) == 0)
                 	 {
                 	 z=0;
   		       Mix_VolumeMusic(0);
   		       }
                 	// if((event2.button.button==SDL_BUTTON_LEFT)&&(event2.motion.x>=posreturn.x && event2.motion.x<=posreturn.x+posreturn.w && event2.motion.y>=posreturn.y && event2.motion.y<=posreturn.y+posreturn.h))
                 	
                 	 
   		       do
   		       {
   		  if((event2.button.button==SDL_BUTTON_LEFT)&&(event2.motion.x>=posmoinsvol.x && event2.motion.x<=posmoinsvol.x+posmoinsvol.w && event2.motion.y>=posmoinsvol.y && event2.motion.y<=posmoinsvol.y+posmoinsvol.h))
   		       
   		       {
   		      
   		       
                        
                        (*volume)+=32;
                        Mix_VolumeMusic((*volume));
                      	z--;
                       
                        
                       }
                        else if((event2.button.button==SDL_BUTTON_LEFT)&&(event2.motion.x>=posplusvol.x && event2.motion.x<=posplusvol.x+posplusvol.w && event2.motion.y>=posplusvol.y && event2.motion.y<=posplusvol.y+posplusvol.h))
                        
                       
                         {
                       
                      
                        (*volume)-=32;
                        Mix_VolumeMusic((*volume));
                        
                       	z++;
                       	
                       	
                        }
                        
                        }
                        while((*volume)<0 && (*volume)>128);
                      
                        if((event2.button.button==SDL_BUTTON_LEFT)&&(event2.motion.x>=posfullscreen.x && event2.motion.x<=posfullscreen.x+posfullscreen.w && event2.motion.y>=posfullscreen.y && event2.motion.y<=posfullscreen.y+posfullscreen.h))
   		       
   		       {
                        
                      Screen = SDL_SetVideoMode(1400, 900, 32, SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE);
                     
                        
                        }
                          else if((event2.button.button==SDL_BUTTON_LEFT)&&(event2.motion.x>=posnormalscreen.x && event2.motion.x<=posnormalscreen.x+posnormalscreen.w && event2.motion.y>=posnormalscreen.y && event2.motion.y<=posnormalscreen.y+posnormalscreen.h))
   		       
   		       {
                        
                      Screen = SDL_SetVideoMode(SCREEN_W, SCREEN_H, 32 ,SDL_HWSURFACE|SDL_RESIZABLE);
                    
                        
                        }
		       
   		       }
   		       
   		       
                    
                     
                        }
       }
       
      

(*p)=z;



        }

