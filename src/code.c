#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <SDL.h>
#include <SDL_ttf.h>

#include "headers.h"


int main(int argc, char **argv)
{
	SDL_Window *window = NULL;
	SDL_Renderer *renderer = NULL;
	SDL_Texture* texture = NULL;
	if(SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		SDL_ExitWithError("Initialisation de la video", NULL, NULL, NULL);
	}

	if (TTF_Init() != 0)
	{
		SDL_ExitWithError("Initialisation de la SDL_ttf", window, NULL, NULL);
	}



	if (SDL_CreateWindowAndRenderer(width, height, 0, &window, &renderer) != 0)
	{
		SDL_ExitWithError("Creation Windows and Render", window, renderer, NULL);
	}


	SDL_SetWindowTitle(window, "Horloge - C/SDL2");


	if(SDL_SetRenderDrawColor(renderer, 112, 168, 237, SDL_ALPHA_OPAQUE) != 0)
	{
		SDL_ExitWithError("Render Draw Color", window, renderer, NULL);
	}



	SDL_Accueil(window, renderer, texture);

	SDL_bool program_launched = SDL_TRUE;

	while(program_launched)
	{
		struct tm actual_time = Get_Time();

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
		SDL_RenderClear(renderer);
		SDL_SetRenderDrawColor(renderer, 112, 168, 237, SDL_ALPHA_OPAQUE);
		SDL_DrawCircle(renderer, width/2, height/2, 280, window, texture);
		SDL_DrawNeedles(renderer, actual_time, 260, window);

		SDL_SetRenderDrawColor(renderer, 170, 170, 170, 255);
		SDL_DrawNeedle_sec(renderer, actual_time, 260, window);
		SDL_SetRenderDrawColor(renderer, 112, 168, 237, SDL_ALPHA_OPAQUE);


		//Draw 2nd fig
		TTF_DrawDate(window, renderer, texture, 10, 10, actual_time);
//33px

		SDL_RenderPresent(renderer); 

		SDL_Event event;
		while(SDL_PollEvent(&event))
		{
			switch(event.type)
			{
				case SDL_QUIT:
					program_launched = SDL_FALSE;
					break;

				default:
					break;
			}
		}

		SDL_Delay(10);

	}


	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	TTF_Quit();
	SDL_Quit();


	return 0;

}