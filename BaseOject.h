#ifndef BASEOJECT_H_INCLUDED
#define BASEOJECT_H_INCLUDED
#include "CommonFunc.h"
class BaseOject
{
protected:
    SDL_Texture* p_oject_;
    SDL_Rect rect_;
public:
    BaseOject();
    ~BaseOject();

    void SetRect (const int &x, const int &y){
        rect_.x = x;
        rect_.y = y;
    }
    SDL_Rect GetRect()const {
        return rect_;
    }
    SDL_Texture* GetOject()const {
        return p_oject_;
    }
    virtual bool LoadImg(std :: string path, SDL_Renderer* screen);
    void Render_(SDL_Renderer* des, const SDL_Rect* clip = nullptr);
    void Render_bg(SDL_Renderer* des,  const SDL_Rect* clip = nullptr);
    void Render_clip(SDL_Renderer* des,  SDL_Rect clip , SDL_Rect rect);
    void Render(SDL_Renderer* des , SDL_Rect rect);
    void Free();
};


#endif // BASEOJECT_H_INCLUDED
