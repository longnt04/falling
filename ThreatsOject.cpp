#include "ThreatsOject.h"
#include <bits/stdc++.h>
#define GROUND 400
#define DEFAULT_Y -100

random_device rdom;
mt19937 rngg(rdom());
uniform_int_distribution<int> unii(1, 3);

ThreatOject::ThreatOject(){
    x_pos_ = 0;
    y_pos_ = unii(rngg)*DEFAULT_Y;
    x_val_ = unii(rngg);
}
void ThreatOject::resetStatus(){
    y_pos_ = unii(rngg)*DEFAULT_Y;
    x_val_ = unii(rngg);
}
ThreatOject::~ThreatOject(){
}

void ThreatOject::set_x_pos_(float x){
    x_pos_ = x;
}

bool ThreatOject::Move(int &score, Mix_Chunk* sound){
    y_pos_ += x_val_;
    if( y_pos_ > GROUND){
        Mix_PlayChannel(-1, sound, 0);
        y_pos_ = unii(rngg)*DEFAULT_Y;
        x_val_ = unii(rngg);
        score++;
    }
    return y_pos_ > GROUND;
}
void ThreatOject::Show(SDL_Renderer* des){
    rect_.x = x_pos_;
    rect_.y = y_pos_;
    SDL_Rect renderQuad = {rect_.x, rect_.y, rect_.w, rect_.h};
    SDL_RenderCopy(des, p_oject_, nullptr, &renderQuad);
}
void ThreatOject::Show_1(SDL_Renderer *des, SDL_Rect rect){
    rect.x = x_pos_;
    rect.y = y_pos_;
    rect_ = rect;
    SDL_RenderCopy(des, p_oject_, nullptr, &rect);
}
