#ifndef HEADERS_H
#define HEADERS_H


#define height 600
#define width 800

void SDL_ExitWithError(char message[], SDL_Window* window, SDL_Renderer *renderer, SDL_Texture *texture);
void SDL_DrawCircle(SDL_Renderer* renderer, int center_x, int center_y, int R, SDL_Window* window, SDL_Texture* texture);
void SDL_DrawNeedles(SDL_Renderer *renderer, struct tm actual_time, int Radius, SDL_Window* window);
void SDL_RenderDrawNeedlesRect(SDL_Renderer *renderer, int x_pos, int y_pos);
void SDL_DrawNeedle_sec(SDL_Renderer *renderer, struct tm actual_time, int Radius, SDL_Window* window);
void TTF_ClkDigits(SDL_Window* window, SDL_Renderer *renderer,SDL_Texture* texture);
void TTF_DrawDate(SDL_Window* window, SDL_Renderer *renderer, SDL_Texture* texture, int x_pos, int y_pos, struct tm actual_time);
void SDL_Accueil(SDL_Window* window, SDL_Renderer* renderer, SDL_Texture* texture);
	

struct tm Get_Time(void);



#endif