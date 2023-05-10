#ifndef THREATSOJECT_H_INCLUDED
#define THREATSOJECT_H_INCLUDED
#include "CommonFunc.h"
#include "BaseOject.h"

class ThreatOject : public BaseOject{
    public:
        ThreatOject();
        ~ThreatOject();
        bool Move(int &score, Mix_Chunk *sound);
        void set_x_pos_(float x);
        void Show(SDL_Renderer *des);
        void Show_1(SDL_Renderer *des, SDL_Rect rect);
        void resetStatus();
        float get_width(){
            return rect_.w;
        };
    private:
        float x_pos_;
        float y_pos_;
        float x_val_;
};


#endif // THREATSOJECT_H_INCLUDED
