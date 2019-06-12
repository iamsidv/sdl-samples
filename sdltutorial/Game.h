//
//  Game.h
//  sdltutorial
//
//  Created by Siddharth on 04/06/19.
//  Copyright © 2019 Siddharth. All rights reserved.
//

#ifndef Game_h
#define Game_h

#include <SDL2/SDL.h>
#include "TextureManager.h"

class Game{
public:
    Game(){}
    ~Game(){}

    void init();
    
    bool init(const char* windowname, int x, int y, int w, int h, bool fullscreen);
    void render();
    void update();
    void handlekeyevents();
    void close();
    
    bool running() {return m_running;}
    
private :
    bool m_running = false;
    
    SDL_Window* s_window = NULL;
    SDL_Renderer* s_renderer = NULL;
    
//    //Texture and rects
//    SDL_Texture* s_texture = NULL;
//    SDL_Rect s_sourceRect;
//    SDL_Rect s_destinationRect;
    
    int currentFrame;
    //TextureManager m_texuremanager;
};

#endif /* Game_h */
