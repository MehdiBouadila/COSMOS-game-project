#include "fonctionsmenu.h"


int main()
{
 
int done = 1, x, y, i = 1;
int volume = 128, z = 0, p = 0;
SDL_Surface *Screen = NULL, *menu[10], *settingsscreen = NULL, *newgamescreen = NULL;
SDL_Surface *newGame = NULL, *resume = NULL, *options = NULL, *quit = NULL, *abt = NULL, *retour = NULL;

Image Background;
Text t;
Mix_Music *Musique;

Mix_Chunk *clickSound;
SDL_Event event;

SDL_Rect posNG, posResume, posOptions, posQuit, posAbt, posretour;

 retour = IMG_Load("return.png");

 


Mix_AllocateChannels(16);

//Positions initialisation

        posNG.x = 150;
	posNG.y = 90;
	posResume.x = 150;
	posResume.y = 160;
	posOptions.x = 150;
	posOptions.y = 230;
	posQuit.x = 150;
	posQuit.y = 300;
        //posAbt.x=0;
        //posAbt.y=0;
       


 
//Images loading

menu[0] = IMG_Load("lampe-1.png");
menu[1] = IMG_Load("lampe0.png");
menu[2] = IMG_Load("lampe1.png");
menu[3] = IMG_Load("lampe2.png");
menu[4] = IMG_Load("lampe3.png");
menu[5] = IMG_Load("lampe4.png");
menu[6] = IMG_Load("lampe5.png");
menu[7] = IMG_Load("lampe6.png");
menu[8] = IMG_Load("lampe7.png");
menu[9] = IMG_Load("lampe8.png");








    newGame = IMG_Load("newgamenotpressed.png");
    resume = IMG_Load("resumenotpressed.png");
    options = IMG_Load("settingsnotpressed.png");
    quit = IMG_Load("quitnotpressed.png");
   // abt = IMG_Load("bouton");
  
   
   
 //SDL initialisations   
 SDL_Init(SDL_INIT_VIDEO);
TTF_Init();
 
 
 
 //Music settings
 if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
 {
 printf("%s", Mix_GetError());
 }
 
 Musique = Mix_LoadMUS("Music.mp3");
 Mix_PlayMusic(Musique, -1);
 clickSound=Mix_LoadWAV("click.wav");



//Initialisations

Screen = SDL_SetVideoMode(SCREEN_W, SCREEN_H, 32, SDL_HWSURFACE|SDL_SRCALPHA);

 
 initBackground(&Background);
 

if(!Screen)
 {
 printf("Unable to set video at this size : %s !\n", SDL_GetError());
 
return 1;
 }
 
 if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO)!=0)
{
printf("Unable to inizialize SDL: %s \n",SDL_GetError());
return 1;
}



//Text settings
 
t.Position.x = 400;
t.Position.y = 8;
t.textColor.r = 255;
t.textColor.g = 198;
t.textColor.b = 153;
t.Font = TTF_OpenFont("JandaManateeSolid.ttf", 70);


//Displaying menu buttons on screen

SDL_BlitSurface(newGame, NULL, Screen, &posNG);
SDL_BlitSurface(resume, NULL, Screen, &posResume);
SDL_BlitSurface(options, NULL, Screen, &posOptions);
SDL_BlitSurface(quit, NULL, Screen, &posQuit);
SDL_Flip(Screen);


int lvl = 0;
int op = 0;


 while(done)
 {
 if(lvl == 0 && op == 0 )
 {
 
 SDL_BlitSurface(Background.Img, &Background.pos2, Screen, &Background.pos1);
 t.surfaceTexte = TTF_RenderText_Solid(t.Font, "COSMOS", t.textColor);
SDL_BlitSurface(t.surfaceTexte, NULL, Screen, &t.Position);
 SDL_BlitSurface(newGame, NULL, Screen, &posNG);
SDL_BlitSurface(resume, NULL, Screen, &posResume);
SDL_BlitSurface(options, NULL, Screen, &posOptions);
SDL_BlitSurface(quit, NULL, Screen, &posQuit);
 animation(Screen, menu);
 
  while(SDL_PollEvent(&event))
                {
                        switch(event.type)
                        {
                             case SDL_QUIT:
                                done = 0;
                                break;
                              
                              
                              
                              case SDL_MOUSEMOTION:
                                        x = event.motion.x;
                                        y = event.motion.y;

					if(x >= posNG.x && x <= posNG.x+posNG.w && y >= posNG.y && y <= posNG.y+posNG.h)
						{         
						Mix_PlayChannel(-1, clickSound, 0);
							  newGame = IMG_Load("newgamepressed.png");
                                                        resume = IMG_Load("resumenotpressed.png");
                                                        options = IMG_Load("settingsnotpressed.png");
                                                        quit = IMG_Load("quitnotpressed.png");
                                                  
                                                        
						}
					

					 if(x >= posResume.x && x <= posResume.x+posResume.w && y >= posResume.y && y <= posResume.y+posResume.h)
						{
							   Mix_PlayChannel(-1, clickSound, 0);
                                                         newGame = IMG_Load("newgamenotpressed.png");
                                                         resume = IMG_Load("resumepressed.png");
                                                         options = IMG_Load("settingsnotpressed.png");
                                                         quit = IMG_Load("quitnotpressed.png");
                                                       
                                                     
						}
						
					 if(x >= posOptions.x && x <= posOptions.x+posOptions.w && y >= posOptions.y && y <= posOptions.y+posOptions.h)
						{
						            Mix_PlayChannel(-1, clickSound, 0);
						            newGame = IMG_Load("newgamenotpressed.png");
                                                          resume = IMG_Load("resumenotpressed.png");
                                                          options = IMG_Load("Settingspressed.png");
                                                          quit = IMG_Load("quitnotpressed.png");
                                                          
                                                         
						}
						

						
						
	                                      if(x >= posQuit.x && x <= posQuit.x+posQuit.w && y >= posQuit.y && y <= posQuit.y+posQuit.h)
						{
						             Mix_PlayChannel(-1, clickSound, 0);
						             newGame = IMG_Load("newgamenotpressed.png");
                                                           resume = IMG_Load("resumenotpressed.png");
                                                           options = IMG_Load("settingsnotpressed.png");
                                                           quit = IMG_Load("quitpressed.png");
                                                           
                                                         
						}
						
					
		
					
		break;		
		

//Game loop

 	
					
case SDL_MOUSEBUTTONDOWN:
        			if ((event.button.button == SDL_BUTTON_LEFT)&&(x>=posQuit.x && x<=posQuit.x+posQuit.w && y>=posQuit.y && y<=posQuit.y+posQuit.h))
					return(0);
					
					else if((event.button.button == SDL_BUTTON_LEFT)&&(x>=posNG.x && x<=posNG.x+posNG.w && y>=posNG.y && y<=posNG.y+posNG.h))
				 {
				lvl = 1;
				
           }
          		
          		
				
				else if((event.button.button == SDL_BUTTON_LEFT)&&(x>=posOptions.x && x<=posOptions.x+posOptions.w && y>=posOptions.y && y<=posOptions.y+posOptions.h))
				
                                        lvl = 2;
					


case SDL_KEYDOWN: 
                                                 
switch(event.key.keysym.sym)

            {
           case SDLK_ESCAPE:
           done = 0;
           break;

            case SDLK_UP:
                if (i==1)
                    i=4;

                else
                    i--;
                break;

            case SDLK_DOWN:

                if(i==4)
                    i=1;

                else
                
                    i++;
                break;
                
               

                


            }
            
    


 if (i==1)
{
newGame = IMG_Load("newgamepressed.png");
resume = IMG_Load("resumenotpressed.png");
options = IMG_Load("settingsnotpressed.png");
quit = IMG_Load("quitnotpressed.png");
Mix_PlayChannel(-1, clickSound, 0);
switch(event.key.keysym.sym){ 
           case SDLK_RETURN:
           lvl = 1;
           break;

 }
}



if (i == 2)
{
newGame = IMG_Load("newgamenotpressed.png");
resume = IMG_Load("resumepressed.png");
options = IMG_Load("settingsnotpressed.png");
quit = IMG_Load("quitnotpressed.png");
Mix_PlayChannel(-1, clickSound, 0);
}


if  (i == 3)
{
newGame = IMG_Load("newgamenotpressed.png");
resume = IMG_Load("resumenotpressed.png");
options = IMG_Load("Settingspressed.png");
quit = IMG_Load("quitnotpressed.png");
Mix_PlayChannel(-1, clickSound, 0);

}


 if (i == 4)
 {
newGame = IMG_Load("newgamenotpressed.png");
resume = IMG_Load("resumenotpressed.png");
options = IMG_Load("settingsnotpressed.png");
quit = IMG_Load("quitpressed.png");
Mix_PlayChannel(-1, clickSound, 0);
 
 switch(event.key.keysym.sym){ 
           case SDLK_RETURN:
           done = 0;
           break;
           }
           }
           }
           

 }
 }
 
else if(lvl == 1)
 {
 SDL_FreeSurface(Screen);
newgame(Screen, retour);
while(SDL_PollEvent(&event))
                {
                        switch(event.type)
                        {
                        case SDL_MOUSEBUTTONDOWN:
        			if ((event.button.button == SDL_BUTTON_LEFT)&&(x>=posretour.x && x<=posretour.x+posretour.w && y>=posretour.y && y<=posretour.y+posretour.h))
        			lvl = 0;
        			break;
        			}
        			}
 }

 else if(lvl == 2)
 {
 SDL_FreeSurface(Screen);
settings(Screen, retour, &volume, &p);
SDL_Event event3;
while(SDL_PollEvent(&event3))
                {
                 switch(event3.type)
                        {
                        case SDL_KEYDOWN: 
                                                 
switch(event.key.keysym.sym)
 {
 case SDLK_h:
        			//if ((event.button.button == SDL_BUTTON_LEFT)&&(x>=posretour.x && x<=posretour.x+posretour.w && y>=posretour.y && y<=posretour.y+posretour.h))
        			printf("HI");
        			lvl = 0;
        			break;
        			}
        			break;
        			}
        			}
 }
 
SDL_Flip(Screen);



//Displaying text on screen


 
 
 //Mouse control
 
               
 

 
								
//}
 
//}

				
                                                    
 
 
 /*
SDL_BlitSurface(Background.Img, &Background.pos2, Screen, &Background.pos1);
SDL_BlitSurface(newGame, NULL, Screen, &posNG);
SDL_BlitSurface(resume, NULL, Screen, &posResume);
SDL_BlitSurface(options, NULL, Screen, &posOptions);
SDL_BlitSurface(quit, NULL, Screen, &posQuit);
SDL_Flip(Screen);
*/

		   
		   
       }            

 
 
//}

// }
 
 SDL_FreeSurface(Background.Img);
 SDL_FreeSurface(t.surfaceTexte);
 SDL_FreeSurface(newGame);
 SDL_FreeSurface(resume);
 SDL_FreeSurface(options);
 SDL_FreeSurface(quit);
 Mix_FreeMusic(Musique);
 Mix_FreeChunk(clickSound);
 
 //TTF_CloseFont(t.Font);
// TTF_Quit();
 SDL_Quit();
 
 
 

	
	
 
 
 return 0;
 }
