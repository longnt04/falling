#ifndef SDL_UTILS_H_INCLUDED
#define SDL_UTILS_H_INCLUDED
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <SDL_ttf.h>
using namespace std;
void initSDL(SDL_Window* &window, SDL_Renderer* &renderer);

void logSDLError(std::ostream& os,
const std::string &msg, bool fatal = false);

void quitSDL(SDL_Window* window, SDL_Renderer* renderer);
void TTF();
void waitUntilKeyPressed();

#endif // SDL_UTILS_H_INCLUDED
