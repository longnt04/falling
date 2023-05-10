#ifndef MAINOJECT_H_INCLUDED
#define MAINOJECT_H_INCLUDED
#include "BaseOject.h"
#include "CommonFunc.h"
class MainOject : public BaseOject{
public:
    MainOject();
    ~MainOject();

    enum WalkType{
        WALK_RIGHT = 0,
        WALK_LEFT = 1,
    };

    bool loadImg(std::string path, SDL_Renderer* screen);
    void Show(SDL_Renderer* des);
    void HandleInputAction(SDL_Event events, SDL_Renderer* screen);
    void set_clip();
    void DoPlayer();
    void UpdateImagePlayer(SDL_Renderer* des);
    void resetStatus();
    int getStatus(){
        return status_;
    };
    SDL_Rect GetRectFrame();

private:
    float x_val_;

    float x_pos_;
    float y_pos_;
    int width_frame_;
    int height_frame_;

    SDL_Rect frame_clip_[5];
    Input input_type_;
    int frame_;
    int status_ ;

};

#endif // MAINOJECT_H_INCLUDED

