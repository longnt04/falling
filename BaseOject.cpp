#include "BaseOject.h"
using namespace std;
BaseOject::BaseOject(){
    p_oject_ = nullptr;
    rect_.x = 0;
    rect_.y = 0;
    rect_.w = 0;
    rect_.h = 0;
}

BaseOject::~BaseOject(){

}

bool BaseOject::LoadImg(std :: string path, SDL_Renderer* renderer){
    Free();
    SDL_Texture* newTexture = nullptr;
    SDL_Surface* load_surface = IMG_Load(path.c_str());
    if(load_surface != nullptr){
        newTexture = SDL_CreateTextureFromSurface(renderer, load_surface);
        if(newTexture != nullptr){
                rect_.w = load_surface -> w;
                rect_.h = load_surface -> h;
        }
        SDL_FreeSurface(load_surface);
    }
    p_oject_ = newTexture;
    return p_oject_ != nullptr;
}

void BaseOject::Render_(SDL_Renderer* des, const SDL_Rect* clip){
    SDL_Rect renderquad = { rect_.x, rect_.y, rect_.w, rect_.h};
    SDL_RenderCopy(des, p_oject_, clip, &renderquad);
}
void BaseOject::Render_bg(SDL_Renderer* des,  const SDL_Rect* clip){
    SDL_RenderCopy(des, p_oject_, clip, nullptr);
}
void BaseOject::Render_clip(SDL_Renderer* des,  SDL_Rect clip , SDL_Rect rect){
    SDL_RenderCopy(des, p_oject_, &clip, &rect);
}
 void BaseOject::Render(SDL_Renderer* des , SDL_Rect rect){
    SDL_RenderCopy(des, p_oject_, nullptr, &rect);
 }
void BaseOject::Free(){
    if(p_oject_!= nullptr){
        SDL_DestroyTexture(p_oject_);
        p_oject_ = nullptr;
        rect_.h = 0;
        rect_.w = 0;
    }
}
