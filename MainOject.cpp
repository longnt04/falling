#include "MainOject.h"
#define Ground 325
#define PLAYER_SPEED 10;
#include <bits/stdc++.h>

const int OFFSET = 10;
random_device rd;
mt19937 rng(rd());
uniform_int_distribution<int> uni(0, 1000);
MainOject :: MainOject(){
    frame_ = 0;
    x_pos_ = uni(rng);
    y_pos_ = Ground;
    x_val_ = 0;
    width_frame_ = 0;
    height_frame_ =0;
    status_ = -1;
    input_type_.left_ = 0;
    input_type_.right_= 0;
}
MainOject :: ~MainOject(){
}
bool MainOject :: loadImg(std::string path, SDL_Renderer* screen){
    bool ret = BaseOject :: LoadImg(path, screen);

    if(ret){
        width_frame_= rect_.w/5;// số lượng ảnh
        height_frame_= rect_.h/2;
    }
    return ret;
}
SDL_Rect MainOject::GetRectFrame(){
    SDL_Rect rect;
    rect.x = rect_.x;
    rect.y = rect_.y;
    rect.w = width_frame_;
    rect.h = height_frame_;
    return rect;
}
void MainOject :: set_clip(){
    if(width_frame_ > 0 && height_frame_ > 0){
        frame_clip_[0].x = 0;
        frame_clip_[0].y = height_frame_;
        frame_clip_[0].w = width_frame_;
        frame_clip_[0].h = height_frame_;

        frame_clip_[1].x = width_frame_;
        frame_clip_[1].y = height_frame_;
        frame_clip_[1].w = width_frame_;
        frame_clip_[1].h = height_frame_;

        frame_clip_[2].x = 2*width_frame_;
        frame_clip_[2].y = height_frame_;
        frame_clip_[2].w = width_frame_;
        frame_clip_[2].h = height_frame_;

        frame_clip_[3].x = 3*width_frame_;
        frame_clip_[3].y = height_frame_;
        frame_clip_[3].w = width_frame_;
        frame_clip_[3].h = height_frame_;

        frame_clip_[4].x = 4*width_frame_;
        frame_clip_[4].y = height_frame_;
        frame_clip_[4].w = width_frame_;
        frame_clip_[4].h = height_frame_;

     }
}
void MainOject::Show(SDL_Renderer* des){
    UpdateImagePlayer(des);
    if(input_type_.left_ == 1 || input_type_.right_ == 1){
        frame_++;
    }else{
        frame_ = 0;
    }
    if(frame_ >= 5){
        frame_ = 0;
    }
    rect_.x = x_pos_;
    rect_.y = y_pos_;
    SDL_Rect* current_clip=&frame_clip_[frame_];
    if(status_ == WALK_LEFT) current_clip = &frame_clip_[4- frame_] ;
    SDL_Rect renderQuad = {rect_.x, rect_.y, width_frame_, height_frame_};

    SDL_RenderCopy(des, p_oject_, current_clip, &renderQuad);
}

void MainOject :: HandleInputAction(SDL_Event events, SDL_Renderer* screen){
    if(events.type == SDL_KEYDOWN){
        switch (events.key.keysym.sym){
            case SDLK_RIGHT:
                {
                   status_ = WALK_RIGHT;
                   input_type_.right_ = 1;
                   input_type_.left_ = 0;
                   UpdateImagePlayer(screen);
                }
                break;
            case SDLK_LEFT:
                {
                    status_ = WALK_LEFT;
                    input_type_.left_ = 1;
                    input_type_.right_ = 0;
                    UpdateImagePlayer(screen);
                }
                break;
            default:
                break;
        }
    }else if(events.type == SDL_KEYUP){
         switch (events.key.keysym.sym){
            case SDLK_RIGHT:
                {
                   input_type_.right_ = 0;
                }
                break;
            case SDLK_LEFT:
                {
                    input_type_.left_ = 0;
                }
                break;
            default:
                break;
        }
    }
}
void MainOject :: DoPlayer(){
    if(input_type_.left_ == 1){
        x_pos_ -= PLAYER_SPEED;
    }else if(input_type_.right_ == 1){
        x_pos_ += PLAYER_SPEED;
    }
    if(x_pos_ <= -OFFSET){
        x_pos_ = -OFFSET;
    }
    if(x_pos_ + width_frame_ >= SCREEN_WIDTH + OFFSET ){
        x_pos_ = SCREEN_WIDTH - width_frame_ + OFFSET;
    }
}
void MainOject::UpdateImagePlayer(SDL_Renderer *des){
    if(status_ == WALK_LEFT){
        loadImg("images/character/player_left.png", des);
    }else{
        loadImg("images/character/player_right.png", des);
    }
}
void MainOject::resetStatus(){
    input_type_.left_ = 0;
    input_type_.right_ = 0;
    frame_ = 0;
    x_pos_ = uni(rng);
    y_pos_ = Ground;
    x_val_ = 0;
    status_ = -1;
}
