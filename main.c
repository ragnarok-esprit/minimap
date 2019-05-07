#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include"SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
//#include "SDL/SDL_rotozoom.h"
#include "fonction.h"



int main ()
{
SDL_Surface *screen=NULL;
SDL_Surface *image=NULL;
/***/SDL_Surface *mini_map=NULL;
/***/SDL_Surface *point=NULL;
SDL_Surface *detective=NULL;
/***/SDL_Surface *sprite_petit=NULL;
SDL_Surface *kalb=NULL;
SDL_Surface *rota=NULL;
Mix_Music *song=NULL;
/***/SDL_Rect positionecran,positiondet,pospoint,possprite,pospetit;
SDL_Event event;
//double a=0,r=1;
int done=1;
if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS, 1024)==-1)
	{
		printf("%s",Mix_GetError());
	}
song=Mix_LoadMUS("music.mp3");
Mix_PlayMusic(song,0);
screen = SDL_SetVideoMode(1370,800,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
if(SDL_Init(SDL_INIT_VIDEO)!=0){

printf("Unable to set 1350x400 video :%s\n",SDL_GetError());
return -1 ;
}
char personom[20]="minisprite.png";

 image=IMG_Load("back.png");
 point=SDL_LoadBMP("minidet.bmp");
 kalb=IMG_Load("kalb.png");
if(image==NULL){
printf("Unable to load bitmap :%s\n",SDL_GetError());
return -1;
}
//mini_map=SDL_LoadBMP("miniback.bmp");
char mapnom[20]="miniback.bmp";

positionecran.x=0;
positionecran.y=0;
SDL_BlitSurface(image,NULL,screen,&positionecran);
positiondet.x=30;
positiondet.y=200;



possprite.x=70;
possprite.y=200;
detective=SDL_LoadBMP("detective.bmp");
if(detective==NULL){
printf("Unable to load bitmap :%s\n",SDL_GetError());
return -1;
}

SDL_SetColorKey(detective,SDL_SRCCOLORKEY,SDL_MapRGB(detective->format,255,255,255));
SDL_SetColorKey(point,SDL_SRCCOLORKEY,SDL_MapRGB(point->format,255,255,255));



SDL_BlitSurface(detective,NULL,screen,&positiondet);
SDL_EnableKeyRepeat(10,10);

    while (done)

    {

        SDL_PollEvent(&event);
        switch(event.type)
        {

            case SDL_QUIT:

                done = 0;
                break;

        case SDL_KEYDOWN:
switch (event.key.keysym.sym)
{
    case SDLK_ESCAPE:

        done = 0;
        break;

case SDLK_UP :
positiondet.y-=10;
break;
case SDLK_DOWN :

positiondet.y+=10;
break;

case SDLK_RIGHT :

positiondet.x+=10;
break;

case SDLK_LEFT :

positiondet.x-=10;
break;



case SDLK_z:
possprite.y-=10;
break;
case SDLK_s:

possprite.y+=10;
break;

case SDLK_d:

possprite.x+=10;
break;

case SDLK_q:

possprite.x-=10;
break;


default:
break;
}
break;
default:
break;
}
/*
a+=1;
r+=0.01;
printf("%f\t%f\n",a,r);
rota=rotozoomSurface(kalb, a,r, 1);
if(r>=20){
	r=1;
	printf("kk\n" );
}
*/
/*pospoint.x=(positiondet.x)*0.2;
pospoint.y=40;
pospetit.x=(possprite.x)*0.2;
pospetit.y=40;*/
SDL_BlitSurface(image,NULL,screen,&positionecran);
//SDL_BlitSurface(mini_map,NULL,screen,0);
//SDL_BlitSurface(point,NULL,screen,&pospoint);
//SDL_BlitSurface(sprite_petit,NULL,screen,&pospetit);
SDL_BlitSurface(detective,NULL,screen,&positiondet);




//el eppel mta3 el fonctionnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnn



miniMap (screen , positiondet, mapnom,personom );
//SDL_BlitSurface(rota,NULL,screen,NULL);
SDL_Flip(screen);
    }
Mix_FreeMusic(song);
SDL_FreeSurface(image);
SDL_FreeSurface(detective);

return 0 ;
}
