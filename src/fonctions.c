
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <SDL.h>
#include <SDL_ttf.h>

#include "headers.h"

void SDL_Accueil(SDL_Window* window, SDL_Renderer* renderer, SDL_Texture* texture)
{
	SDL_Surface *texte1 = NULL;
	SDL_Surface *texte2 = NULL;
	TTF_Font* font = NULL;

	SDL_Color color = {110, 160, 230, 255};
	
	SDL_Rect texte_pos1 = {width/2-190, height/2-200, 0, 0}; 
	SDL_Rect texte_pos2 = {width/2-190, height/2, 0, 0}; 
	
	char hi_user[30] = {"Horloge"};
	char hi_user_tool[30] = {"C/SDL2"};
	


	font = TTF_OpenFont("fonts/ROCK.TTF", 100);
	if (font == NULL)
	{
		TTF_CloseFont(font);
		SDL_ExitWithError("Ouverture de la police d'ecriture", window, renderer, texture);
	}


	texte1 = TTF_RenderText_Solid(font, hi_user, color);
	texte2 = TTF_RenderText_Solid(font, hi_user_tool, color);
	


	if(NULL == texte1 || NULL == texte2)
	{
		SDL_FreeSurface(texte1); //n oublie pas de toutes les free
		TTF_CloseFont(font);
		SDL_ExitWithError("Impossible de creer l'une des surface", window, renderer, texture);
	}
	TTF_CloseFont(font);


	texture = SDL_CreateTextureFromSurface(renderer, texte1);
	SDL_FreeSurface(texte1);

	if (NULL == texture)
	{	
		SDL_ExitWithError("Impossible de creer la surface", window, renderer, texture);
	}


	if(SDL_QueryTexture(texture, NULL, NULL, &texte_pos1.w, &texte_pos1.h) != 0)
	{
		SDL_ExitWithError("Impossible de charger la texture texte en memoire", window, renderer, texture);
	}


	//Copier dans le rendu la texture chargee en memoire
	if (SDL_RenderCopy(renderer, texture, NULL, &texte_pos1) != 0)
	{
		SDL_ExitWithError("Impossible d'afficher le texte", window, renderer, texture);
	}




	/*--------*/
	

	texture = SDL_CreateTextureFromSurface(renderer, texte2);
	SDL_FreeSurface(texte2);

	if (NULL == texture)
	{	
		SDL_ExitWithError("Impossible de creer la surface", window, renderer, texture);
	}


	if(SDL_QueryTexture(texture, NULL, NULL, &texte_pos2.w, &texte_pos2.h) != 0)
	{
		SDL_ExitWithError("Impossible de charger la texture texte en memoire", window, renderer, texture);
	}


	//Copier dans le rendu la texture chargee en memoire
	if (SDL_RenderCopy(renderer, texture, NULL, &texte_pos2) != 0)
	{
		SDL_ExitWithError("Impossible d'afficher le texte", window, renderer, texture);
	}




	SDL_RenderPresent(renderer); 
	SDL_Delay(2000);

}






void TTF_ClkDigits(SDL_Window* window, SDL_Renderer *renderer,SDL_Texture* texture)
{
	SDL_Surface *texte_12 = NULL;
	SDL_Surface *texte_3 = NULL;
	SDL_Surface *texte_6 = NULL;
	SDL_Surface *texte_9 = NULL;
	
	TTF_Font* font = NULL;
	SDL_Color color = {110, 160, 230, 255};
	
	SDL_Rect text_12_pos = {width/2-17, 30, 0, 0};
	SDL_Rect text_9_pos = {130, height/2 - 20, 0, 0};
	SDL_Rect text_6_pos = {width/2-10, height-65 , 0, 0};
	SDL_Rect text_3_pos = {width-150, height/2-20, 0, 0};

	char h12[30], h3[30], h6[30], h9[30];


	font = TTF_OpenFont("fonts/ROCK.TTF", 30);
	if (font == NULL)
	{
		TTF_CloseFont(font);
		SDL_ExitWithError("Ouverture de la police d'ecriture", window, renderer, texture);
	}

	
	itoa(12, h12, 10);
	itoa(3, h3, 10);
	itoa(6, h6, 10);
	itoa(9, h9, 10);


	texte_12 = TTF_RenderText_Solid(font, h12, color);
	texte_3 = TTF_RenderText_Solid(font, h3, color);
	texte_6 = TTF_RenderText_Solid(font, h6, color);
	texte_9 = TTF_RenderText_Solid(font, h9, color);
	
	if(NULL == texte_9 || NULL == texte_6 || NULL == texte_3 || NULL == texte_12)
	{
		SDL_FreeSurface(texte_12); //n oublie pas de toutes les free
		TTF_CloseFont(font);
		SDL_ExitWithError("Impossible de creer l'une des surface", window, renderer, texture);
	}
	TTF_CloseFont(font);


	texture = SDL_CreateTextureFromSurface(renderer, texte_12);
	SDL_FreeSurface(texte_12);

	if (NULL == texture)
	{	
		SDL_ExitWithError("Impossible de creer la surface", window, renderer, texture);
	}


	if(SDL_QueryTexture(texture, NULL, NULL, &text_12_pos.w, &text_12_pos.h) != 0)
	{
		SDL_ExitWithError("Impossible de charger la texture texte en memoire", window, renderer, texture);
	}


	//Copier dans le rendu la texture chargee en memoire
	if (SDL_RenderCopy(renderer, texture, NULL, &text_12_pos) != 0)
	{
		SDL_ExitWithError("Impossible d'afficher le texte", window, renderer, texture);
	}





	/*-------*/
	

	texture = SDL_CreateTextureFromSurface(renderer, texte_3);
	SDL_FreeSurface(texte_3);

	if (NULL == texture)
	{	
		SDL_ExitWithError("Impossible de creer la surface", window, renderer, texture);
	}


	if(SDL_QueryTexture(texture, NULL, NULL, &text_3_pos.w, &text_3_pos.h) != 0)
	{
		SDL_ExitWithError("Impossible de charger la texture texte en memoire", window, renderer, texture);
	}


	//Copier dans le rendu la texture chargee en memoire
	if (SDL_RenderCopy(renderer, texture, NULL, &text_3_pos) != 0)
	{
		SDL_ExitWithError("Impossible d'afficher le texte", window, renderer, texture);
	}


	/*-------*/
	
	texture = SDL_CreateTextureFromSurface(renderer, texte_6);
	SDL_FreeSurface(texte_6);

	if (NULL == texture)
	{	
		SDL_ExitWithError("Impossible de creer la surface", window, renderer, texture);
	}


	if(SDL_QueryTexture(texture, NULL, NULL, &text_6_pos.w, &text_6_pos.h) != 0)
	{
		SDL_ExitWithError("Impossible de charger la texture texte en memoire", window, renderer, texture);
	}


	//Copier dans le rendu la texture chargee en memoire
	if (SDL_RenderCopy(renderer, texture, NULL, &text_6_pos) != 0)
	{
		SDL_ExitWithError("Impossible d'afficher le texte", window, renderer, texture);
	}





	/*-------*/
	
	texture = SDL_CreateTextureFromSurface(renderer, texte_9);
	SDL_FreeSurface(texte_9);

	if (NULL == texture)
	{	
		SDL_ExitWithError("Impossible de creer la surface", window, renderer, texture);
	}


	if(SDL_QueryTexture(texture, NULL, NULL, &text_9_pos.w, &text_9_pos.h) != 0)
	{
		SDL_ExitWithError("Impossible de charger la texture texte en memoire", window, renderer, texture);
	}


	//Copier dans le rendu la texture chargee en memoire
	if (SDL_RenderCopy(renderer, texture, NULL, &text_9_pos) != 0)
	{
		SDL_ExitWithError("Impossible d'afficher le texte", window, renderer, texture);
	}




}








void TTF_DrawDate(SDL_Window* window, SDL_Renderer *renderer,SDL_Texture* texture, int x_pos, int y_pos, struct tm actual_time)
{
	
	SDL_Surface *texte = NULL;
	TTF_Font* font = NULL;
	SDL_Color color = {110, 160, 230, 255};
	
	SDL_Rect text_pos = {x_pos, y_pos, 0, 0};


	font = TTF_OpenFont("fonts/ROCK.TTF", 30);
	if (font == NULL)
	{
		TTF_CloseFont(font);
		SDL_ExitWithError("Ouverture de la police d'ecriture", window, renderer, texture);
	}


	char day[30] = {0}; 
	char year[30] = {0};
	char month[30] = {0};

	itoa(actual_time.tm_mday, day, 10);
	itoa(actual_time.tm_year-100, year, 10);
	itoa(actual_time.tm_mon+1, month, 10);
	
	if (actual_time.tm_mday < 10) //Pour avoir le format 0X
	{
		day[1] = day[0];
		day[0] = 48; 
	}
	
	strcat(day, "/");
	strcat(day, month);
	strcat(day, "/");
	strcat(day, year);

	texte = TTF_RenderText_Solid(font, day, color);
	if(NULL == texte)
	{
		SDL_FreeSurface(texte);
		TTF_CloseFont(font);
		SDL_ExitWithError("Impossible de creer la surface", window, renderer, texture);
	}
	TTF_CloseFont(font);


	texture = SDL_CreateTextureFromSurface(renderer, texte);
	SDL_FreeSurface(texte);

	if (NULL == texture)
	{	
		SDL_ExitWithError("Impossible de creer la surface", window, renderer, texture);
	}


	if(SDL_QueryTexture(texture, NULL, NULL, &text_pos.w, &text_pos.h) != 0)
	{
		SDL_ExitWithError("Impossible de charger la texture texte en memoire", window, renderer, texture);
	}


	//Copier dans le rendu la texture chargee en memoire
	if (SDL_RenderCopy(renderer, texture, NULL, &text_pos) != 0)
	{
		SDL_ExitWithError("Impossible d'afficher le texte", window, renderer, texture);
	}


}



struct tm Get_Time(void)
{
    time_t currentTime;
    struct tm localTime;

    time(&currentTime);
    localTime = *localtime(&currentTime); 

    return localTime;
}



    




void SDL_DrawCircle(SDL_Renderer *renderer, int center_x, int center_y, int R, SDL_Window* window, SDL_Texture* texture)
{
	int x, y;
	for (int angle=0; angle<360; angle++)
	{
		x = center_x + (int)R*cos(angle*M_PI/180);
		y = center_y + (int)R*sin(angle*M_PI/180); 
	

		if(SDL_RenderDrawPoint(renderer, x, y) != 0)
		{
			SDL_ExitWithError("Draw Point", window, renderer, NULL);
		}
	
	}


	TTF_ClkDigits(window, renderer, texture);



}




void SDL_DrawNeedles(SDL_Renderer *renderer, struct tm actual_time, int Radius, SDL_Window* window)
{
	int x, y;
	int hour = actual_time.tm_hour;
	int min = actual_time.tm_min;
	int sec = actual_time.tm_sec;

	double angle_h = (hour%12)*30;
	x = width/2 + (int)(Radius-120)*sin(angle_h*M_PI/180.0);
	y = height/2 - (int)(Radius-120)*cos(angle_h*M_PI/180.0);

	if(SDL_RenderDrawLine(renderer, width/2, height/2, x, y) != 0)
	{
		SDL_ExitWithError("Draw Line", window, renderer, NULL);
	}


	double angle_m = min*6;
	x = width/2 + (int)(Radius-18)*sin(angle_m*M_PI/180.0);
	y = height/2 - (int)(Radius-18)*cos(angle_m*M_PI/180.0);

	if(SDL_RenderDrawLine(renderer, width/2, height/2, x, y) != 0)
	{
		SDL_ExitWithError("Draw Line", window, renderer, NULL);
	}



	double angle_s = sec*6;
	x = width/2 + (int)Radius*sin(angle_s*M_PI/180.0);
	y = height/2 - (int)Radius*cos(angle_s*M_PI/180.0);

	if(SDL_RenderDrawLine(renderer, width/2, height/2, x, y) != 0)
	{
		SDL_ExitWithError("Draw Line", window, renderer, NULL);
	}

}



void SDL_DrawNeedle_sec(SDL_Renderer *renderer, struct tm actual_time, int Radius, SDL_Window* window)
{
	int x, y;
	int sec = actual_time.tm_sec;

	double angle_s = sec*6;
	x = width/2 + (int)Radius*sin(angle_s*M_PI/180.0);
	y = height/2 - (int)Radius*cos(angle_s*M_PI/180.0);

	if(SDL_RenderDrawLine(renderer, width/2, height/2, x, y) != 0)
	{
		SDL_ExitWithError("Draw Line", window, renderer, NULL);
	}

}







void SDL_RenderDrawNeedlesRect(SDL_Renderer *renderer, int x_pos, int y_pos)
{
	SDL_Point points[5];


	points[0].x = width/2 - 20; 
	points[0].y = height/2 + 20;


	points[1].x = width/2 + 20; 
	points[1].y = height/2 - 20;




	points[2].x = x_pos + 20; 
	points[2].y =  y_pos - 20;

	points[3].x = x_pos - 20; 
	points[3].y = y_pos + 20;

	points[4] = points[0];
	
	SDL_RenderDrawLines(renderer, points, 5);

}




void SDL_ExitWithError(char message[], SDL_Window* window, SDL_Renderer* renderer, SDL_Texture *texture)
{
	SDL_Log("Erreur; %s > %s \n", message, SDL_GetError());

	if (texture != NULL)
	{
		SDL_DestroyTexture(texture);
	}

	if (renderer != NULL)
	{
		SDL_DestroyRenderer(renderer);
	}

	if (window != NULL)
	{
		SDL_DestroyWindow(window);
	}


	SDL_Quit();
	exit(EXIT_FAILURE);

}

