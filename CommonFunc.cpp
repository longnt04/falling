#include "CommonFunc.h"
#include <bits/stdc++.h>

int *createArr(int *arr){
        set<int> rdom {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        int rangeOfSet=9;
        set < int > :: iterator it;
        random_device rd;
        mt19937 rng(rd());
        for (int i = 0; i < 10; i++)
        {
            it = rdom.begin();
            uniform_int_distribution<int> uni(0, rangeOfSet);
            int random_integer = uni(rng);
            for (int i = 0 ; i < random_integer ; i++) {
                ++it;
            }
            arr[i] = *it;
            rdom.erase(it);
            rangeOfSet--;
        }
    return arr;
}
const int OFFSET = 10;

bool check_1(SDL_Rect rect1, SDL_Rect rect2){
        if(rect2.x > rect1.x + rect1.w - 3*OFFSET|| rect2.x + rect2.w < rect1.x + 3*OFFSET || rect2.y + rect2.h < rect1.y + 3*OFFSET || rect2.y > rect1.y + rect1.h - 3*OFFSET) return false;
    return true;
}
Mix_Music*  loadMusic(string filePath,Mix_Music* music ){
    if(SDL_Init(SDL_INIT_AUDIO) < 0) {
        std::cerr << "SDL could not initialize! SDL Error: " << SDL_GetError() << std::endl;
    }
    // Initialize SDL_mixer
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        std::cerr << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError() << std::endl;
    }
    // Load MP3 file
     music = Mix_LoadMUS(filePath.c_str());//"sound/sound1.mp3"
    if(music == NULL) {
        std::cerr << "Failed to load music! SDL_mixer Error: " << Mix_GetError() << std::endl;
    }
    return music;
}

