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
#include <vector>
#include "TextureManager.h"
#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"

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
    
    int currentFrame;
    
    // Added two objects in the gamescene
    GameObject* m_go;
    GameObject* m_player;
    GameObject* m_enemy;
    
    std::vector<GameObject*> m_gameObjects;
};

#endif /* Game_h */
