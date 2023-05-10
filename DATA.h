#ifndef DATA_H_INCLUDED
#define DATA_H_INCLUDED
// map data
#define distance 50
#define fontwidth 15
#define DEFAULT_X 30
static SDL_Rect g_overRect = {(SCREEN_WIDTH - 540)/2, 20, 540, 360};
//button
static SDL_Rect playRect = {(SCREEN_WIDTH - 149)/2,410 - 160, 149,96};
static SDL_Rect playRect1 = {(SCREEN_WIDTH - 149)/2,410 - 80, 149,96};
static SDL_Rect exitRect = {(SCREEN_WIDTH - 149)/2,410 - 150 + 100, 149,96};
static SDL_Rect leftImg = {0, 0, 150, 98};
static SDL_Rect rightImg = {150, 0, 150, 98};
static SDL_Rect leftBackImg = {0, 0, 57, 57};
static SDL_Rect rightBackImg = {57, 0, 57, 57};
//score
static SDL_Rect scoreRect = {30,10 , 30 , 40};
static SDL_Rect hscoreRect = {30, 50, 30, 40};
static string score_str = "Score: ";
static string highscore_str = "High score: ";
//menu map
static SDL_Rect map1Rect = {200, 130, 300, 150};
static SDL_Rect map2Rect = {580, 130, 300, 150};
static SDL_Rect map3Rect = {390, 335, 300, 150};
static SDL_Rect map1nameRect = {275, 295, 150, 20};
static SDL_Rect map2nameRect = {667, 295, 125, 20};
static SDL_Rect map3nameRect = {459, 500, 138, 20};
static SDL_Rect titleRect = {340, 20, 400 , 80};
static SDL_Rect backRect = {0, 0, 50, 50};
//map
const int  MAP_1 =  1;
const int  MAP_2 =  2;
const int  MAP_3 =  3;
static SDL_Rect mapp2 = {0, 0, 333/4, 303/4};
static SDL_Rect mapp3 = {0, 0, 50, 100};
//delay time
const int delayTime = 26;
#endif // DATA_H_INCLUDED
