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
#include "GameObject.h"

class Game{
public:
//    Game(){}
    ~Game(){}

    static Game* Instance(){
        if(s_pInstance==NULL){
            s_pInstance = new Game();
        }
        return s_pInstance;
    }
    
    void init();
    bool init(const char* windowname, int x, int y, int w, int h, bool fullscreen);
    void render();
    void update();
    void handlekeyevents();
    void close();
    
    bool running() {return m_running;}
    SDL_Renderer* getRenderer() const { return s_renderer; }
    
private :
    //Making this private because of a static instance.
    Game(){}
    
    bool m_running = false;
    
    SDL_Window* s_window = NULL;
    SDL_Renderer* s_renderer = NULL;
    
    int currentFrame;
    
    // This is not necessary
    /*GameObject* m_go;
    GameObject* m_player;
    GameObject* m_enemy;*/
    
    std::vector<GameObject*> m_gameObjects;
    //Static reference
    static Game* s_pInstance;
};

typedef Game TheGame;

#endif /* Game_h */
