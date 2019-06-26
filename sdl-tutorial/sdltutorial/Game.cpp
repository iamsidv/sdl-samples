//
//  Game.cpp
//  sdltutorial
//
//  Created by Siddharth on 05/06/19.
//  Copyright © 2019 Siddharth. All rights reserved.
//

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

#include "Game.h"

bool Game::init(const char *windowname, int x, int y, int w, int h, bool fullscreen){
    bool is_init = false;
    
    //Adding extra flag for fullscreen.
    int flag = SDL_WINDOW_SHOWN;
    if(fullscreen)
        flag = SDL_WINDOW_FULLSCREEN;
    
    if(SDL_Init(SDL_INIT_VIDEO)<0){
        printf("SDL could not be init : %s \n", SDL_GetError());
        is_init = false;
    }else{
        printf("Init successful \n");
        s_window = SDL_CreateWindow(windowname, x, y, w, h, flag);
        if(s_window == NULL){
            printf("SDL could not create a window : %s \n", SDL_GetError());
            is_init = false;
        }else{
            printf("Window creation successful \n");
            s_renderer = SDL_CreateRenderer(s_window, -1, 0);
            if(s_renderer==NULL){
                printf("SDL could not create a renderer : %s \n", SDL_GetError());
                is_init =  false;
            }else{
                printf("Renderer has been successful \n");
                //Set a color to the renderer.
                SDL_SetRenderDrawColor(s_renderer, 0x00, 0xff, 0xab, 0xff);
                printf("Drawing the color on screen \n");
                is_init =  true;
            }
        }
    }
    printf("Initialization Success : %d \n", is_init);
    m_running = is_init;
    
    //Using texture manager as a stack object i.e, without a pointer.
    //m_texuremanager.load("assets/green_lift_btn.png", "green_lift", s_renderer);
    
    //Using singleton reference of the texture manager now.
    if(!STextureManager::Instance()->load("assets/green_lift_btn.png", "green_lift", s_renderer)){
        printf("Couldn't find the resource id %s \n", "green_lift");
        return false;
    }
    
    if(!STextureManager::Instance()->load("assets/brick_wall_13.jpg", "brickwall", s_renderer)){
        printf("Couldn't find the resource id %s \n", "brickwall");
        return false;
    }

    init();
    
    return is_init;
}

void Game::init()
{
    m_go = new GameObject();
    m_player = new Player();
    m_enemy = new Enemy();
    
    m_go->load(0, 0, 256, 256, "green_lift");
    m_player->load(0, 0, 256, 256, "green_lift");
    m_enemy->load(0, 200, 128, 256, "green_lift");
    
    m_gameObjects.push_back(m_go);
    m_gameObjects.push_back(m_player);
    m_gameObjects.push_back(m_enemy);

    
    //    m_go.load(0, 0, 256, 256, "green_lift");
    //    m_player.load(0, 0, 256, 256, "green_lift");
}
void Game::handlekeyevents(){
    SDL_Event s_event;
    if(SDL_PollEvent(&s_event)){
        switch (s_event.type) {
            case SDL_QUIT:
                m_running = false;
                break;
            case SDL_MOUSEBUTTONDOWN:
                printf("Mouse button down \n");
                break;
            case SDL_MOUSEBUTTONUP:
                printf("Mouse button up \n");
                break;
            default:
                break;
        }
    }
}

void Game::update(){
    //currentFrame = int((SDL_GetTicks()/1000)% 2);
//    int r = (currentFrame%2) * 64;
//    int c = (currentFrame/2) * 64;
    
    /*s_sourceRect.x = r;
    s_sourceRect.y = c;*/
    
//    m_go.update();
//    m_player.update();
    
    for (std::vector<GameObject*>::size_type i=0; i!=m_gameObjects.size(); i++) {
        m_gameObjects[i]->update();
    }
}

void Game::render(){
    //Clear the screen
    SDL_RenderClear(s_renderer);
    
//    commenting this because now we are using pointers
//    m_go.draw(s_renderer);
//    m_player.draw(s_renderer);
    
    //Some T type thingy!!!
    for (std::vector<GameObject*>::size_type i = 0; i!= m_gameObjects.size(); i++) {
        m_gameObjects[i]->draw(s_renderer);
    }
    
    //Using texturemanager now (as a stack object)
    //    m_texuremanager.draw("green_lift", 0, 0, 256, 256, s_renderer);
    //    m_texuremanager.drawFrame("green_lift", 150, 150, 128, 128, 1, currentFrame, s_renderer);
    
//    This is using a singleton example.
//    STextureManager::Instance()->draw("green_lift", 0, 0, 256, 256, s_renderer);
//    STextureManager::Instance()->drawFrame("green_lift", 150, 150, 128, 128, 1, currentFrame, s_renderer);
//    SDL_Rect zz = STextureManager::Instance()->getTextureRect("brickwall");
//    STextureManager::Instance()->draw("brickwall", 0, 300, zz.w, zz.h, s_renderer);
    
    //Render it
    SDL_RenderPresent(s_renderer);
}

void Game::close(){
    printf("Destroying window \n");
    //Destroy window
    SDL_DestroyWindow(s_window);
     printf("Destroying renderer \n");
    //Destroy renderer
    SDL_DestroyRenderer(s_renderer);
    printf("Quitting sdl \n");
    //QUIT SDL
    SDL_Quit();
}
