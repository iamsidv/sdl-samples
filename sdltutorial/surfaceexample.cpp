//
//  surfaceexample.cpp
//  sdltutorial
//
//  Created by Siddharth on 04/06/19.
//  Copyright © 2019 Siddharth. All rights reserved.
//
#include <SDL2/SDL.h>
#include <stdio.h>

//const int WINDOW_WIDTH = 640;
//const int WINDOW_HEIGHT = 480;
//const char* win_name = "SDL Tutorial Test";
//
//int mainzz(int argc, const char * argv[]){
//    
//    SDL_Window* s_window = NULL;
//    SDL_Renderer* s_renderer = NULL;
//    
//    if(SDL_Init(SDL_INIT_VIDEO)<0){
//        printf("Error while initialising SDL: %s \n", SDL_GetError());
//    }else{
//        //Create a SDL window
//        s_window = SDL_CreateWindow(win_name, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
//        if(s_window == NULL){
//            printf("Error creating a window in SDL: %s \n", SDL_GetError());
//        }else{
//            //Create a renderer
//            s_renderer = SDL_CreateRenderer(s_window, -1, 0);
//            //Draw the color
//            SDL_SetRenderDrawColor(s_renderer, 0xCD, 0xAA, 0xAB, 0xff);
//            //Clear the screen
//            SDL_RenderClear(s_renderer);
//            //Render it
//            SDL_RenderPresent(s_renderer);
//            //Delay for 6 seconds
//            SDL_Delay(6000);
//        }
//    }
//    //QUIT SDL
//    SDL_Quit();
//    
//    return 0;
//}
