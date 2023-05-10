#ifndef COMMONFUNC_H_INCLUDED
#define COMMONFUNC_H_INCLUDED
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

using namespace std;

static SDL_Window* g_window;
static SDL_Renderer* g_screen;
static SDL_Event g_event;
// music
static Mix_Music *g_music;
static Mix_Chunk *pressButton;
static Mix_Chunk *pointSound;
static Mix_Chunk *gameOver;
typedef struct Input {
    int left_;
    int right_;
};
//screen
const int FRAME_PER_SECOND = 30; // fps
const int SCREEN_WIDTH = 1080;
const int SCREEN_HEIGHT = 540;
const string WINDOW_TITLE = "                                                                                                                                                                   falling";

int *createArr(int *arr);

bool check_1(SDL_Rect rect1, SDL_Rect rect2);
// music
Mix_Music*  loadMusic(string filePath,Mix_Music* music );


#endif // COMMONFUNC_H_INCLUDED
