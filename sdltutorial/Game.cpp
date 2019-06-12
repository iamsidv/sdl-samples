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
    
    //This is not required now.
    /*
    //Create a surface for loading an image
    SDL_Surface* tempSurface = SDL_LoadBMP("assets/pause.bmp");
    //Loading from PNG
//    SDL_Surface* tempSurface = IMG_Load("assets/green_lift_btn.png");

    if(tempSurface==NULL) printf("Unable to find image\n");
    else printf("pause.bmp found\n");
    
    //create a texture from surface
    s_texture = SDL_CreateTextureFromSurface(s_renderer, tempSurface);
    
    if(s_texture==NULL) printf("Texture created from surface\n");
    else printf("texture found\n");
    
    //Free or remove the surface
    SDL_FreeSurface(tempSurface);
    //Querying the texture will allow us to set the width and height of our source rectangle to the exact dimensions needed
    SDL_QueryTexture(s_texture, NULL, NULL, &s_sourceRect.w, &s_sourceRect.h);
    
    //Getting 1/4th of the image's frame.
    s_sourceRect.w /=2;
    s_sourceRect.h /=2;
    printf("Rect width is %d and height is %d \n",s_sourceRect.w, s_sourceRect.h);
    //
    s_sourceRect.x = 0;
    s_sourceRect.y = 0;
    
    //Placement of the txture in the screen
    s_destinationRect.x = 30;
    s_destinationRect.y = 40;
    
    s_destinationRect.w = s_sourceRect.w;
    s_destinationRect.h = s_sourceRect.h;
    
    */
    
    //Using texture manager as a stack object i.e, without a pointer.
//    m_texuremanager.load("assets/green_lift_btn.png", "green_lift", s_renderer);
    
    //Using singleton reference of the texture manager now.
    if(!STextureManager::Instance()->load("assets/green_lift_btn.png", "green_lift", s_renderer)){
        printf("Couldn't find the resource id %s \n", "green_lift");
        return false;
    }
    
    if(!STextureManager::Instance()->load("assets/brick_wall_13.jpg", "brickwall", s_renderer)){
        printf("Couldn't find the resource id %s \n", "brickwall");
        return false;
    }
    
    return is_init;
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
    currentFrame = int((SDL_GetTicks()/1000)% 2);
//    int r = (currentFrame%2) * 64;
//    int c = (currentFrame/2) * 64;
    
    /*s_sourceRect.x = r;
    s_sourceRect.y = c;*/
}

void Game::render(){
    //Clear the screen
    SDL_RenderClear(s_renderer);
    
    /*
    //For displaying the texture
    SDL_RenderCopy(s_renderer, s_texture, &s_sourceRect, &s_destinationRect);
    //For enabling the texture to get flipped and display it on the screen.
    //SDL_RenderCopyEx(s_renderer, s_texture, &s_sourceRect, &s_destinationRect, 0, 0, SDL_FLIP_HORIZONTAL);
    */
    
    //Using texturemanager now (as a stack object)
//    m_texuremanager.draw("green_lift", 0, 0, 256, 256, s_renderer);
//    m_texuremanager.drawFrame("green_lift", 150, 150, 128, 128, 1, currentFrame, s_renderer);
    
    //This is using a singleton example.
    STextureManager::Instance()->draw("green_lift", 0, 0, 256, 256, s_renderer);
    STextureManager::Instance()->drawFrame("green_lift", 150, 150, 128, 128, 1, currentFrame, s_renderer);
    
    SDL_Rect zz = STextureManager::Instance()->getTextureRect("brickwall");
    STextureManager::Instance()->draw("brickwall", 0, 300, zz.w, zz.h, s_renderer);
    
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
