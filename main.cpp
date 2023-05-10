#include <bits/stdc++.h>
#include <SDL_image.h>
#include<SDL.h>
#include "SDL_utils.h"
#include "CommonFunc.h"
#include "BaseOject.h"
#include "MainOject.h"
#include "ImpTimer.h"
#include "ThreatsOject.h"
#include "DATA.h"
#include "TextOject.h"
BaseOject g_background;
BaseOject g_over;
//button
BaseOject play_button;
BaseOject exit_button;
BaseOject back_button;
//map
BaseOject map_1;
BaseOject map_2;
BaseOject map_3;
TTF_Font* font_time;
bool reset = false;
using namespace std;

void close(){
    g_background.Free();
    SDL_DestroyRenderer(g_screen);
    g_screen = nullptr;
    SDL_DestroyWindow(g_window);
    g_window = nullptr;
    IMG_Quit();
    SDL_Quit();
}
int main(int agrc,char* agrv[] )
{
    ImpTimer fps_timer;
    initSDL(g_window, g_screen);
    TTF();
    //time text
    Text time_game;
    font_time =  TTF_OpenFont("fonts/font.ttf",25);
    //player
    MainOject p_player;
    //button
    play_button.LoadImg("images/button/play_button.png", g_screen);
    exit_button.LoadImg("images/button/exit_button.png",g_screen);
    back_button.LoadImg("images/button/back_button.png",g_screen);
    //music
    g_music = loadMusic("audio/theme.mp3", g_music);

    pressButton = Mix_LoadWAV("audio/clickbutton.wav");
    Mix_VolumeChunk(pressButton, 15);
    Mix_VolumeMusic(20);

    pointSound = Mix_LoadWAV("audio/fall.wav");
    Mix_VolumeChunk(pointSound, 15);

    gameOver = Mix_LoadWAV("audio/gameove.wav");
    Mix_VolumeChunk(gameOver, 40);

    Mix_PlayMusic(g_music, -1);

    while(true){
        //background
        g_background.LoadImg("images/background/background.jpg",g_screen);
        //menu
        bool firstomenu = true;
        bool menu = true;
        while (menu){
        bool playStatus = false, exitStatus = false;
        if(firstomenu){
            g_background.Render_bg(g_screen,nullptr);
            play_button.Render_clip(g_screen, rightImg, playRect);
            exit_button.Render_clip(g_screen, rightImg, exitRect);
            firstomenu = false;
        }
        while (SDL_PollEvent(&g_event)){
        if(g_event.type == SDL_MOUSEMOTION || g_event.type == SDL_MOUSEBUTTONDOWN){
        int x,y;
        SDL_GetMouseState(&x, &y);
        if(x >= playRect.x && x <= (playRect.x + playRect.w) && y >= (playRect.y) && y <= (playRect.y + playRect.h)){
             play_button.Render_clip(g_screen, leftImg, playRect);
             playStatus = true;
        }else
            play_button.Render_clip(g_screen, rightImg, playRect);
        if(x >= exitRect.x && x <= exitRect.x + exitRect.w && y >= exitRect.y && y <= exitRect.y + exitRect.h){
             exit_button.Render_clip(g_screen, leftImg, exitRect);
             exitStatus= true;
        }else
           exit_button.Render_clip(g_screen, rightImg, exitRect);
        }
        if(playStatus && g_event.type == SDL_MOUSEBUTTONDOWN &&g_event.button.button == SDL_BUTTON_LEFT){
            menu = false;
            Mix_PlayChannel(-1, pressButton, 0);
            break;
        }
        if(exitStatus && g_event.type == SDL_MOUSEBUTTONDOWN &&g_event.button.button == SDL_BUTTON_LEFT){
           Mix_PlayChannel(-1, pressButton, 0);
           SDL_Delay(100);
           quitSDL(g_window, g_screen);
           TTF_Quit();
           Mix_Quit();
           return 0;
        }
        if(g_event.type == SDL_QUIT){
            quitSDL(g_window, g_screen);
            TTF_Quit();
            Mix_Quit();
            return 0;
        }
         }
         SDL_RenderPresent(g_screen);
         playStatus = false;
         exitStatus = false;
        }
        SDL_RenderClear(g_screen);
        firstomenu = true;
     // menu map
        bool menumap = true;
        bool map1 = false;
        bool map2 = false;
        bool map3 = false;
        int mapp ;
        g_background.LoadImg("images/background/foggy.png",g_screen);
        map_1.LoadImg("images/background/background1.png", g_screen);
        map_2.LoadImg("images/background/background2.jpg", g_screen);
        map_3.LoadImg("images/background/background3.png", g_screen);
        //text
        TTF_Font*font = TTF_OpenFont("fonts/font.ttf",20);
        TTF_Font*font_title = TTF_OpenFont("fonts/font.ttf", 50);
        Text map1name; map1name.SetColor(Text::WHITE);
        Text map2name; map2name.SetColor(Text::WHITE);
        Text map3name; map3name.SetColor(Text::WHITE);
        Text title; title.SetColor(Text::GRAY);
        map1name.SetText("Death valley"); map1name.LoadFont(font, g_screen);
        map2name.SetText("Sweet land"); map2name.LoadFont(font,g_screen);
        map3name.SetText("Dark galaxy"); map3name.LoadFont(font, g_screen);
        title.SetText("Select map"); title.LoadFont(font_title, g_screen);
        bool back_Status = false;
        while (menumap){
                bool backStatus = false;
                g_background.Render_bg(g_screen, nullptr);
                back_button.Render_clip(g_screen, leftBackImg, backRect);
                map1name.Render(g_screen, map1nameRect);
                map2name.Render(g_screen, map2nameRect);
                map3name.Render(g_screen, map3nameRect);
                title.Render(g_screen, titleRect);
                while (SDL_PollEvent(&g_event)){
                    if(g_event.type == SDL_QUIT){
                        quitSDL(g_window, g_screen);
                        TTF_Quit();
                        Mix_Quit();
                        return 0;
                    }
                    if(g_event.type == SDL_MOUSEMOTION || g_event.type == SDL_MOUSEBUTTONDOWN){
                        int x,y;
                        SDL_GetMouseState(&x, &y);
                        if(x >= map1Rect.x && x <= (map1Rect.x + map1Rect.w) && y >= (map1Rect.y) && y <= (map1Rect.y + map1Rect.h)){
                            map1Rect = {190, 125, 320, 160};
                            map1 = true;
                        }else
                            map1Rect = {200, 130, 300, 150};

                        if(x >= map2Rect.x && x <= (map2Rect.x + map2Rect.w) && y >= (map2Rect.y) && y <= (map2Rect.y + map2Rect.h)){
                            map2Rect = {570, 125, 320, 160};
                            map2 = true;
                        }else
                            map2Rect = {580, 130, 300, 150};

                        if(x >= map3Rect.x && x <= (map3Rect.x + map3Rect.w) && y >= (map3Rect.y) && y <= (map3Rect.y + map3Rect.h)){
                            map3Rect = {380, 330, 320, 160};
                            map3 = true;
                        }else
                            map3Rect = {390, 335, 300, 150};

                        if(x >= backRect.x && x <= backRect.x + exitRect.w && y >= backRect.y && y <= backRect.y + backRect.h){
                            backRect = {0, 0, 57, 57};
                            backStatus= true;
                        }else
                            backRect = {0, 0, 50, 50};

                        if( map1 && g_event.type == SDL_MOUSEBUTTONDOWN &&g_event.button.button == SDL_BUTTON_LEFT){
                            Mix_PlayChannel(-1, pressButton, 0);
                            menumap = false;
                            mapp = MAP_1;
                            break;
                        }
                        if( map2 && g_event.type == SDL_MOUSEBUTTONDOWN &&g_event.button.button == SDL_BUTTON_LEFT){
                            Mix_PlayChannel(-1, pressButton, 0);
                            menumap = false;
                            mapp = MAP_2;
                            break;
                        }
                        if( map3 && g_event.type == SDL_MOUSEBUTTONDOWN &&g_event.button.button == SDL_BUTTON_LEFT){
                            Mix_PlayChannel(-1, pressButton, 0);
                            menumap = false;
                            mapp = MAP_3;
                            break;
                        }
                        if( backStatus && g_event.type == SDL_MOUSEBUTTONDOWN &&g_event.button.button == SDL_BUTTON_LEFT){
                            Mix_PlayChannel(-1, pressButton, 0);
                            menumap = false;
                            back_Status = true;
                            break;
                        }
                }
                }
                map_1.Render(g_screen, map1Rect);
                map_2.Render(g_screen, map2Rect);
                map_3.Render(g_screen, map3Rect);
                SDL_RenderPresent(g_screen);
                backStatus = false;
                map1 = false;
                map2 = false;
                map3 = false;
                SDL_RenderClear(g_screen);
            }
        backRect = {0, 0, 57, 57};
        if(back_Status) continue;
        if(mapp == MAP_1){
            g_background.LoadImg("images/background/background1.png", g_screen);
            p_player.loadImg("images/character/player_right.png", g_screen);
            p_player.set_clip();
            //ememy map1
            ThreatOject blue; blue.LoadImg("images/enemy/map1_blue.png", g_screen);
            ThreatOject blue1; blue1.LoadImg("images/enemy/map1_blue.png", g_screen);
            ThreatOject blue2; blue2.LoadImg("images/enemy/map1_blue.png", g_screen);
            ThreatOject red; red.LoadImg("images/enemy/map1_red.png", g_screen);
            ThreatOject red1; red1.LoadImg("images/enemy/map1_red.png", g_screen);
            ThreatOject red2; red2.LoadImg("images/enemy/map1_red.png", g_screen);
            ThreatOject green; green.LoadImg("images/enemy/map1_green.png", g_screen);
            ThreatOject green1; green1.LoadImg("images/enemy/map1_green.png", g_screen);
            ThreatOject orange; orange.LoadImg("images/enemy/map1_orange.png", g_screen);
            ThreatOject orange1; orange1.LoadImg("images/enemy/map1_orange.png", g_screen);
            bool run = true;
            while(run){
                if(!Mix_PlayingMusic() ){
                    Mix_PlayMusic(g_music, -1);
                }
                SDL_RenderClear(g_screen);
                //tạo vị trí enemy
                int arr[10];
                createArr(arr);
                float map1_width = blue.get_width();
                blue.set_x_pos_(DEFAULT_X + arr[0]*(map1_width + distance));
                blue1.set_x_pos_(DEFAULT_X + arr[1]*(map1_width + distance));
                blue2.set_x_pos_(DEFAULT_X + arr[2]*(map1_width + distance));
                red.set_x_pos_(DEFAULT_X + arr[3]*(map1_width + distance));
                red1.set_x_pos_(DEFAULT_X + arr[4]*(map1_width + distance));
                red2.set_x_pos_(DEFAULT_X + arr[5]*(map1_width + distance));
                green.set_x_pos_(DEFAULT_X + arr[6]*(map1_width + distance));
                green1.set_x_pos_(DEFAULT_X + arr[7]*(map1_width + distance));
                orange.set_x_pos_(DEFAULT_X + arr[8]*(map1_width + distance));
                orange1.set_x_pos_(DEFAULT_X + arr[9]*(map1_width + distance));
                //menu
                bool menu1 = true;
                while (menu1){
                    bool playStatus = false, backStatus = false;
                    if(firstomenu){
                        g_background.Render_bg(g_screen, nullptr);
                        play_button.Render_clip(g_screen, rightImg, playRect1);
                        back_button.Render_clip(g_screen, leftBackImg, backRect);
                        firstomenu = false;
                    }
                    while (SDL_PollEvent(&g_event)){
                        if(g_event.type == SDL_QUIT){
                            quitSDL(g_window, g_screen);
                            TTF_Quit();
                            Mix_Quit();
                            return 0;
                        }
                        if(g_event.type == SDL_MOUSEMOTION || g_event.type == SDL_MOUSEBUTTONDOWN){
                            int x,y;
                            SDL_GetMouseState(&x, &y);
                            if(x >= playRect1.x && x <= (playRect1.x + playRect1.w) && y >= (playRect1.y) && y <= (playRect1.y + playRect1.h)){
                                play_button.Render_clip(g_screen, leftImg, playRect1);
                                playStatus = true;
                            }else
                                play_button.Render_clip(g_screen, rightImg, playRect1);
                            if(x >= backRect.x && x <= backRect.x + exitRect.w && y >= backRect.y && y <= backRect.y + backRect.h){
                                back_button.Render_clip(g_screen, rightBackImg, backRect);
                                backStatus= true;
                            }else
                                back_button.Render_clip(g_screen, leftBackImg, backRect);

                            if(playStatus && g_event.type == SDL_MOUSEBUTTONDOWN &&g_event.button.button == SDL_BUTTON_LEFT){
                                Mix_PlayChannel(-1, pressButton, 0);
                                menu1 = false;
                                break;
                            }
                            if(backStatus && g_event.type == SDL_MOUSEBUTTONDOWN &&g_event.button.button == SDL_BUTTON_LEFT){
                                Mix_PlayChannel(-1, pressButton, 0);
                                run = false;
                                menu1 = false;
                                reset = true;
                                break;
                            }
                        }
                    }
                    SDL_RenderPresent(g_screen);
                    playStatus = false;
                    backStatus = false;
                }
                firstomenu = true;
                if(!run) break;
                SDL_RenderClear(g_screen);
                int score = 0;
                ifstream fin ("highscore.txt");
                if (!fin.is_open()) {
                    cout << "Error, file is not opened.\n";
                }
                int highscore;
                fin >> highscore;
                fin.close();
                g_background.Render_bg(g_screen, nullptr);
                //game né bóng
                bool running = true;
                while(running){
                    if(reset){
                       p_player.resetStatus();
                       blue.resetStatus();blue1.resetStatus();blue2.resetStatus();
                       red.resetStatus();red1.resetStatus();red2.resetStatus();
                       green.resetStatus(); green1.resetStatus();
                       orange.resetStatus(); orange1.resetStatus();
                       reset = false;
                    }
                    //score text
                    Text scoreText; scoreText.SetColor(Text::BLACK);
                    string score_val = "";
                    if(score < 10){
                        score_val = "0" + to_string(score);
                    }else{
                        score_val = to_string(score);
                    }
                    string val_score = score_str + score_val;
                    scoreText.SetText(val_score);
                    scoreText.LoadFont(font, g_screen);
                    scoreRect.w = val_score.length() * fontwidth;
                    //highscore text
                    Text hscoreText; hscoreText.SetColor(Text::BLACK);
                    string val_hscore = "";
                    if(highscore < 10){
                       val_hscore =  highscore_str + "0" + to_string(highscore);
                    }else{
                        val_hscore = highscore_str + to_string(highscore);
                    }
                    hscoreText.SetText(val_hscore);
                    hscoreText.LoadFont(font, g_screen);
                    hscoreRect.w = val_hscore.length() * fontwidth;
                    fps_timer.start();
                    while(SDL_PollEvent(&g_event)){
                        if(g_event.type == SDL_QUIT){
                            quitSDL(g_window, g_screen);
                            TTF_Quit();
                            return 0;
                        }
                        p_player.HandleInputAction(g_event, g_screen);
                    }
                    SDL_RenderClear(g_screen);
                    g_background.Render_bg(g_screen, nullptr);
                    // enemy di chuyển
                    blue.Move(score, pointSound);
                    blue1.Move(score, pointSound);
                    blue2.Move(score, pointSound);
                    red.Move(score, pointSound);
                    red1.Move(score, pointSound);
                    red2.Move(score, pointSound);
                    green.Move(score, pointSound);
                    green1.Move(score, pointSound);
                    orange.Move(score, pointSound);
                    orange1.Move(score, pointSound);

                    p_player.DoPlayer();

                    blue.Show(g_screen);
                    blue1.Show(g_screen);
                    blue2.Show(g_screen);
                    red.Show(g_screen);
                    red1.Show(g_screen);
                    red2.Show(g_screen);
                    green.Show(g_screen);
                    green1.Show(g_screen);
                    orange.Show(g_screen);
                    orange1.Show(g_screen);

                    p_player.Show(g_screen);

                    // show game time
                    string str_time = "Time: ";
                    Uint32 time_val = SDL_GetTicks()/1000;
                    string second ;
                    if(time_val % 60 >= 10){
                        second = to_string(time_val%60);
                    }else{
                        second = "0" + to_string(time_val%60);
                    }
                    string minute = to_string(time_val/60);
                    string str_val = minute + ":" + second;
                    str_time += str_val;
                    time_game.SetText(str_time);
                    time_game.LoadFont(font_time, g_screen);
                    //render text
                    time_game.RenderText(g_screen, SCREEN_WIDTH/2 - (str_time.length()/2)*fontwidth ,10);
                    scoreText.Render(g_screen, scoreRect);
                    hscoreText.Render(g_screen, hscoreRect);
                    // xử lý xa chạm
                    SDL_Rect player = p_player.GetRectFrame();
                    int status = p_player.getStatus();
                    if(check_1(player, blue.GetRect()) || check_1(player, blue1.GetRect())
                        || check_1(player, blue2.GetRect()) || check_1(player, red.GetRect())
                        || check_1(player, red1.GetRect()) || check_1(player, red2.GetRect())
                        || check_1(player, green.GetRect()) || check_1(player, green1.GetRect())
                        || check_1(player, orange.GetRect()) || check_1(player, orange1.GetRect())){
                                    Mix_HaltMusic();
                                    Mix_PlayChannel(-1, gameOver, 0);
                                    g_over.LoadImg("images/background/gameOver.png", g_screen);
                                    g_over.Render(g_screen, g_overRect);
                                    if(score > highscore){
                                        highscore = score;
                                    }
                                    ofstream fout ("highscore.txt");
                                    if (!fout.is_open()) {
                                    cout << "Error, file is not opened.\n";
                                    }
                                    fout << highscore;
                                    fout.close();
                                    running = false;
                                    reset = true;
                             }
                    SDL_RenderPresent(g_screen);
                    if(!running){
                        SDL_Delay(2000);
                    }
                    int real_imp_time = fps_timer.get_ticks();
                    int time_one_frame = 1000/FRAME_PER_SECOND;//ms
                    if(real_imp_time < time_one_frame){
                        int delay_time = time_one_frame - real_imp_time;
                        if(delay_time >= 0){
                        SDL_Delay(delayTime);
                        }
                    }
                }
            }
        }else if(mapp == MAP_2){
            g_background.LoadImg("images/background/background2.jpg", g_screen);
            p_player.loadImg("images/character/player_right.png", g_screen);
            p_player.set_clip();
            //ememy map2
            ThreatOject blue1; blue1.LoadImg("images/enemy/map2_blue1.png", g_screen);
            ThreatOject blue2; blue2.LoadImg("images/enemy/map2_blue2.png", g_screen);
            ThreatOject blue3; blue3.LoadImg("images/enemy/map2_blue3.png", g_screen);
            ThreatOject red1; red1.LoadImg("images/enemy/map2_red1.png", g_screen);
            ThreatOject red2; red2.LoadImg("images/enemy/map2_red2.png", g_screen);
            ThreatOject red3; red3.LoadImg("images/enemy/map2_red3.png", g_screen);
            ThreatOject brown1; brown1.LoadImg("images/enemy/map2_brown1.png", g_screen);
            ThreatOject brown2; brown2.LoadImg("images/enemy/map2_brown2.png", g_screen);
            ThreatOject gray; gray.LoadImg("images/enemy/map2_gray.png", g_screen);
            ThreatOject yellow; yellow.LoadImg("images/enemy/map2_yellow.png", g_screen);
            bool run = true;
            while(run){
                if(!Mix_PlayingMusic() ){
                    Mix_PlayMusic(g_music, -1);
                }
                SDL_RenderClear(g_screen);
                //tạo vị trí enemy
                int arr[10];
                createArr(arr);
                float map2_width = mapp2.w;
                blue1.set_x_pos_(DEFAULT_X + arr[0]*(map2_width + distance));
                blue2.set_x_pos_(DEFAULT_X + arr[1]*(map2_width + distance));
                blue3.set_x_pos_(DEFAULT_X + arr[2]*(map2_width + distance));
                red1.set_x_pos_(DEFAULT_X + arr[3]*(map2_width + distance));
                red2.set_x_pos_(DEFAULT_X + arr[4]*(map2_width + distance));
                red3.set_x_pos_(DEFAULT_X + arr[5]*(map2_width + distance));
                brown1.set_x_pos_(DEFAULT_X + arr[6]*(map2_width + distance));
                brown2.set_x_pos_(DEFAULT_X + arr[7]*(map2_width + distance));
                gray.set_x_pos_(DEFAULT_X + arr[8]*(map2_width + distance));
                yellow.set_x_pos_(DEFAULT_X + arr[9]*(map2_width + distance));
                //menu
                bool menu1 = true;
                while (menu1){
                    bool playStatus = false, backStatus = false;
                    if(firstomenu){
                        g_background.Render_bg(g_screen, nullptr);
                        play_button.Render_clip(g_screen, rightImg, playRect1);
                        back_button.Render_clip(g_screen, leftBackImg, backRect);
                        firstomenu = false;
                    }
                    while (SDL_PollEvent(&g_event)){
                        if(g_event.type == SDL_QUIT){
                            quitSDL(g_window, g_screen);
                            TTF_Quit();
                            Mix_Quit();
                            return 0;
                        }
                        if(g_event.type == SDL_MOUSEMOTION || g_event.type == SDL_MOUSEBUTTONDOWN){
                            int x,y;
                            SDL_GetMouseState(&x, &y);
                            if(x >= playRect1.x && x <= (playRect1.x + playRect1.w) && y >= (playRect1.y) && y <= (playRect1.y + playRect1.h)){
                                play_button.Render_clip(g_screen, leftImg, playRect1);
                                playStatus = true;
                            }else
                                play_button.Render_clip(g_screen, rightImg, playRect1);
                            if(x >= backRect.x && x <= backRect.x + exitRect.w && y >= backRect.y && y <= backRect.y + backRect.h){
                                back_button.Render_clip(g_screen, rightBackImg, backRect);
                                backStatus= true;
                            }else
                                back_button.Render_clip(g_screen, leftBackImg, backRect);

                            if(playStatus && g_event.type == SDL_MOUSEBUTTONDOWN &&g_event.button.button == SDL_BUTTON_LEFT){
                                Mix_PlayChannel(-1, pressButton, 0);
                                menu1 = false;
                                break;
                            }
                            if(backStatus && g_event.type == SDL_MOUSEBUTTONDOWN &&g_event.button.button == SDL_BUTTON_LEFT){
                                Mix_PlayChannel(-1, pressButton, 0);
                                run = false;
                                menu1 = false;
                                reset = true;
                                break;
                            }
                        }
                    }
                    SDL_RenderPresent(g_screen);
                    playStatus = false;
                    backStatus = false;
                }
                firstomenu = true;
                if(!run) break;
                SDL_RenderClear(g_screen);
                int score = 0;
                ifstream fin ("highscore.txt");
                if (!fin.is_open()) {
                    cout << "Error, file is not opened.\n";
                }
                int highscore;
                fin >> highscore;
                fin.close();
                g_background.Render_bg(g_screen, nullptr);
                //game né bóng
                bool running = true;
                while(running){
                    if(reset){
                       p_player.resetStatus();
                       blue1.resetStatus();blue2.resetStatus();blue3.resetStatus();
                       red1.resetStatus();red2.resetStatus();red3.resetStatus();
                       brown1.resetStatus(); brown2.resetStatus();
                       gray.resetStatus(); yellow.resetStatus();
                       reset = false;
                    }
                    //score text
                    Text scoreText; scoreText.SetColor(Text::BLACK);
                    string score_val = "";
                    if(score < 10){
                        score_val = "0" + to_string(score);
                    }else{
                        score_val = to_string(score);
                    }
                    string val_score = score_str + score_val;
                    scoreText.SetText(val_score);
                    scoreText.LoadFont(font, g_screen);
                    scoreRect.w = val_score.length() * fontwidth;
                    //highscore text
                    Text hscoreText; hscoreText.SetColor(Text::BLACK);
                    string val_hscore = "";
                    if(highscore < 10){
                       val_hscore =  highscore_str + "0" + to_string(highscore);
                    }else{
                        val_hscore = highscore_str + to_string(highscore);
                    }
                    hscoreText.SetText(val_hscore);
                    hscoreText.LoadFont(font, g_screen);
                    hscoreRect.w = val_hscore.length() * fontwidth;
                    fps_timer.start();
                    while(SDL_PollEvent(&g_event)){
                        if(g_event.type == SDL_QUIT){
                            quitSDL(g_window, g_screen);
                            TTF_Quit();
                            return 0;
                        }
                        p_player.HandleInputAction(g_event, g_screen);
                    }
                    SDL_RenderClear(g_screen);
                    g_background.Render_bg(g_screen, nullptr);
                    // enemy di chuyển
                    blue1.Move(score, pointSound);
                    blue2.Move(score, pointSound);
                    blue3.Move(score, pointSound);
                    red1.Move(score, pointSound);
                    red2.Move(score, pointSound);
                    red3.Move(score, pointSound);
                    brown1.Move(score, pointSound);
                    brown2.Move(score, pointSound);
                    gray.Move(score, pointSound);
                    yellow.Move(score, pointSound);

                    p_player.DoPlayer();

                    blue1.Show_1(g_screen, mapp2);
                    blue2.Show_1(g_screen, mapp2);
                    blue3.Show_1(g_screen, mapp2);
                    red1.Show_1(g_screen, mapp2);
                    red2.Show_1(g_screen, mapp2);
                    red3.Show_1(g_screen, mapp2);
                    brown1.Show_1(g_screen, mapp2);
                    brown2.Show_1(g_screen, mapp2);
                    gray.Show_1(g_screen, mapp2);
                    yellow.Show_1(g_screen, mapp2);

                    p_player.Show(g_screen);

                    // show game time
                    string str_time = "Time: ";
                    Uint32 time_val = SDL_GetTicks()/1000;
                    string second ;
                    if(time_val % 60 >= 10){
                        second = to_string(time_val%60);
                    }else{
                        second = "0" + to_string(time_val%60);
                    }
                    string minute = to_string(time_val/60);
                    string str_val = minute + ":" + second;
                    str_time += str_val;
                    time_game.SetText(str_time);
                    time_game.LoadFont(font_time, g_screen);
                    //render text
                    time_game.RenderText(g_screen, SCREEN_WIDTH/2 - (str_time.length()/2)*fontwidth ,10);
                    scoreText.Render(g_screen, scoreRect);
                    hscoreText.Render(g_screen, hscoreRect);
                    // xử lý xa chạm
                    SDL_Rect player = p_player.GetRectFrame();
                    int status = p_player.getStatus();
                    if(check_1(player, blue1.GetRect()) || check_1(player, blue2.GetRect())
                        || check_1(player, blue3.GetRect()) || check_1(player, red1.GetRect())
                        || check_1(player, red2.GetRect()) || check_1(player, red3.GetRect())
                        || check_1(player, brown1.GetRect()) || check_1(player, brown2.GetRect())
                        || check_1(player, gray.GetRect()) || check_1(player, yellow.GetRect())){
                                    Mix_HaltMusic();
                                    Mix_PlayChannel(-1, gameOver, 0);
                                    g_over.LoadImg("images/background/gameOver.png", g_screen);
                                    g_over.Render(g_screen, g_overRect);
                                    if(score > highscore){
                                        highscore = score;
                                    }
                                    ofstream fout ("highscore.txt");
                                    if (!fout.is_open()) {
                                    cout << "Error, file is not opened.\n";
                                    }
                                    fout << highscore;
                                    fout.close();
                                    running = false;
                                    reset = true;
                             }
                    SDL_RenderPresent(g_screen);
                    if(!running){
                        SDL_Delay(2000);
                    }
                    int real_imp_time = fps_timer.get_ticks();
                    int time_one_frame = 1000/FRAME_PER_SECOND;//ms
                    if(real_imp_time < time_one_frame){
                        int delay_time = time_one_frame - real_imp_time;
                        if(delay_time >= 0){
                        SDL_Delay(delayTime);
                        }
                    }
                }
            }
        }else if(mapp == MAP_3){
            g_background.LoadImg("images/background/background3.png", g_screen);
            p_player.loadImg("images/character/player_right.png", g_screen);
            p_player.set_clip();
            //ememy map3
            ThreatOject rocket1; rocket1.LoadImg("images/enemy/map3_rocket.png", g_screen);
            ThreatOject rocket2; rocket2.LoadImg("images/enemy/map3_rocket1.png", g_screen);
            ThreatOject rocket3; rocket3.LoadImg("images/enemy/map3_rocket.png", g_screen);
            ThreatOject rocket4; rocket4.LoadImg("images/enemy/map3_rocket1.png", g_screen);
            ThreatOject rocket5; rocket5.LoadImg("images/enemy/map3_rocket.png", g_screen);
            ThreatOject rocket6; rocket6.LoadImg("images/enemy/map3_rocket1.png", g_screen);
            ThreatOject rocket7; rocket7.LoadImg("images/enemy/map3_rocket.png", g_screen);
            ThreatOject rocket8; rocket8.LoadImg("images/enemy/map3_rocket1.png", g_screen);
            ThreatOject rocket9; rocket9.LoadImg("images/enemy/map3_rocket.png", g_screen);
            ThreatOject rocket10; rocket10.LoadImg("images/enemy/map3_rocket1.png", g_screen);
            bool run = true;
            while(run){
                if(!Mix_PlayingMusic() ){
                    Mix_PlayMusic(g_music, -1);
                }
                SDL_RenderClear(g_screen);
                //tạo vị trí enemy
                int arr[10];
                createArr(arr);
                float map3_width = mapp3.w;
                rocket1.set_x_pos_(DEFAULT_X + arr[0]*(map3_width + distance));
                rocket2.set_x_pos_(DEFAULT_X + arr[1]*(map3_width + distance));
                rocket3.set_x_pos_(DEFAULT_X + arr[2]*(map3_width + distance));
                rocket4.set_x_pos_(DEFAULT_X + arr[3]*(map3_width + distance));
                rocket5.set_x_pos_(DEFAULT_X + arr[4]*(map3_width + distance));
                rocket6.set_x_pos_(DEFAULT_X + arr[5]*(map3_width + distance));
                rocket7.set_x_pos_(DEFAULT_X + arr[6]*(map3_width + distance));
                rocket8.set_x_pos_(DEFAULT_X + arr[7]*(map3_width + distance));
                rocket9.set_x_pos_(DEFAULT_X + arr[8]*(map3_width + distance));
                rocket10.set_x_pos_(DEFAULT_X + arr[9]*(map3_width + distance));
                //menu
                bool menu1 = true;
                while (menu1){
                    bool playStatus = false, backStatus = false;
                    if(firstomenu){
                        g_background.Render_bg(g_screen, nullptr);
                        play_button.Render_clip(g_screen, rightImg, playRect1);
                        back_button.Render_clip(g_screen, leftBackImg, backRect);
                        firstomenu = false;
                    }
                    while (SDL_PollEvent(&g_event)){
                        if(g_event.type == SDL_QUIT){
                            quitSDL(g_window, g_screen);
                            TTF_Quit();
                            Mix_Quit();
                            return 0;
                        }
                        if(g_event.type == SDL_MOUSEMOTION || g_event.type == SDL_MOUSEBUTTONDOWN){
                            int x,y;
                            SDL_GetMouseState(&x, &y);
                            if(x >= playRect1.x && x <= (playRect1.x + playRect1.w) && y >= (playRect1.y) && y <= (playRect1.y + playRect1.h)){
                                play_button.Render_clip(g_screen, leftImg, playRect1);
                                playStatus = true;
                            }else
                                play_button.Render_clip(g_screen, rightImg, playRect1);
                            if(x >= backRect.x && x <= backRect.x + exitRect.w && y >= backRect.y && y <= backRect.y + backRect.h){
                                back_button.Render_clip(g_screen, rightBackImg, backRect);
                                backStatus= true;
                            }else
                                back_button.Render_clip(g_screen, leftBackImg, backRect);

                            if(playStatus && g_event.type == SDL_MOUSEBUTTONDOWN &&g_event.button.button == SDL_BUTTON_LEFT){
                                Mix_PlayChannel(-1, pressButton, 0);
                                menu1 = false;
                                break;
                            }
                            if(backStatus && g_event.type == SDL_MOUSEBUTTONDOWN &&g_event.button.button == SDL_BUTTON_LEFT){
                                Mix_PlayChannel(-1, pressButton, 0);
                                run = false;
                                menu1 = false;
                                reset = true;
                                break;
                            }
                        }
                    }
                    SDL_RenderPresent(g_screen);
                    playStatus = false;
                    backStatus = false;
                }
                firstomenu = true;
                if(!run) break;
                SDL_RenderClear(g_screen);
                int score = 0;
                ifstream fin ("highscore.txt");
                if (!fin.is_open()) {
                    cout << "Error, file is not opened.\n";
                }
                int highscore;
                fin >> highscore;
                fin.close();
                g_background.Render_bg(g_screen, nullptr);
                //game né tên lửa
                bool running = true;
                while(running){
                    if(reset){
                       p_player.resetStatus();
                       rocket1.resetStatus();rocket2.resetStatus();rocket3.resetStatus();
                       rocket4.resetStatus();rocket5.resetStatus();rocket6.resetStatus();
                       rocket7.resetStatus(); rocket8.resetStatus();
                       rocket9.resetStatus(); rocket10.resetStatus();
                       reset = false;
                    }
                    //score text
                    Text scoreText; scoreText.SetColor(Text::BLACK);
                    string score_val = "";
                    if(score < 10){
                        score_val = "0" + to_string(score);
                    }else{
                        score_val = to_string(score);
                    }
                    string val_score = score_str + score_val;
                    scoreText.SetText(val_score);
                    scoreText.LoadFont(font, g_screen);
                    scoreRect.w = val_score.length() * fontwidth;
                    //highscore text
                    Text hscoreText; hscoreText.SetColor(Text::BLACK);
                    string val_hscore = "";
                    if(highscore < 10){
                       val_hscore =  highscore_str + "0" + to_string(highscore);
                    }else{
                        val_hscore = highscore_str + to_string(highscore);
                    }
                    hscoreText.SetText(val_hscore);
                    hscoreText.LoadFont(font, g_screen);
                    hscoreRect.w = val_hscore.length() * fontwidth;
                    fps_timer.start();
                    while(SDL_PollEvent(&g_event)){
                        if(g_event.type == SDL_QUIT){
                            quitSDL(g_window, g_screen);
                            TTF_Quit();
                            return 0;
                        }
                        p_player.HandleInputAction(g_event, g_screen);
                    }
                    SDL_RenderClear(g_screen);
                    g_background.Render_bg(g_screen, nullptr);
                    // enemy di chuyển
                    rocket1.Move(score, pointSound);
                    rocket2.Move(score, pointSound);
                    rocket3.Move(score, pointSound);
                    rocket4.Move(score, pointSound);
                    rocket5.Move(score, pointSound);
                    rocket6.Move(score, pointSound);
                    rocket7.Move(score, pointSound);
                    rocket8.Move(score, pointSound);
                    rocket9.Move(score, pointSound);
                    rocket10.Move(score, pointSound);

                    p_player.DoPlayer();

                    rocket1.Show_1(g_screen, mapp3);
                    rocket2.Show_1(g_screen, mapp3);
                    rocket3.Show_1(g_screen, mapp3);
                    rocket4.Show_1(g_screen, mapp3);
                    rocket5.Show_1(g_screen, mapp3);
                    rocket6.Show_1(g_screen, mapp3);
                    rocket7.Show_1(g_screen, mapp3);
                    rocket8.Show_1(g_screen, mapp3);
                    rocket9.Show_1(g_screen, mapp3);
                    rocket10.Show_1(g_screen, mapp3);

                    p_player.Show(g_screen);

                    // show game time
                    string str_time = "Time: ";
                    Uint32 time_val = SDL_GetTicks()/1000;
                    string second ;
                    if(time_val % 60 >= 10){
                        second = to_string(time_val%60);
                    }else{
                        second = "0" + to_string(time_val%60);
                    }
                    string minute = to_string(time_val/60);
                    string str_val = minute + ":" + second;
                    str_time += str_val;
                    time_game.SetText(str_time);
                    time_game.LoadFont(font_time, g_screen);
                    //render text
                    time_game.RenderText(g_screen, SCREEN_WIDTH/2 - (str_time.length()/2)*fontwidth ,10);
                    scoreText.Render(g_screen, scoreRect);
                    hscoreText.Render(g_screen, hscoreRect);
                    // xử lý xa chạm
                    SDL_Rect player = p_player.GetRectFrame();
                    int status = p_player.getStatus();
                    if(check_1(player, rocket1.GetRect()) || check_1(player, rocket2.GetRect())
                        || check_1(player, rocket3.GetRect()) || check_1(player, rocket4.GetRect())
                        || check_1(player, rocket5.GetRect()) || check_1(player, rocket6.GetRect())
                        || check_1(player, rocket7.GetRect()) || check_1(player, rocket8.GetRect())
                        || check_1(player, rocket9.GetRect()) || check_1(player, rocket10.GetRect())){
                                    Mix_HaltMusic();
                                    Mix_PlayChannel(-1, gameOver, 0);
                                    g_over.LoadImg("images/background/gameOver.png", g_screen);
                                    g_over.Render(g_screen, g_overRect);
                                    if(score > highscore){
                                        highscore = score;
                                    }
                                    ofstream fout ("highscore.txt");
                                    if (!fout.is_open()) {
                                    cout << "Error, file is not opened.\n";
                                    }
                                    fout << highscore;
                                    fout.close();
                                    running = false;
                                    reset = true;
                             }
                    SDL_RenderPresent(g_screen);
                    if(!running){
                        SDL_Delay(2000);
                    }
                    int real_imp_time = fps_timer.get_ticks();
                    int time_one_frame = 1000/FRAME_PER_SECOND;//ms
                    if(real_imp_time < time_one_frame){
                        int delay_time = time_one_frame - real_imp_time;
                        if(delay_time >= 0){
                        SDL_Delay(delayTime);
                        }
                    }
                }
            }
        }


    }
    close();
    return 0;
}
