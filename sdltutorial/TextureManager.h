//
//  TextureManager.hpp
//  sdltutorial
//
//  Created by Siddharth on 06/06/19.
//  Copyright © 2019 Siddharth. All rights reserved.
//

#ifndef TextureManager_h
#define TextureManager_h

#include <stdio.h>
#include <iostream>
#include <map>

#include <SDL2/SDL.h>

class TextureManager{
  
public:
   
    ~TextureManager(){}
    
    bool load(std::string fileName,std::string id,SDL_Renderer* pRender);
    
    void draw(std::string id, int x, int y, int width, int height, SDL_Renderer* pRender, SDL_RendererFlip flip = SDL_FLIP_NONE);
    
    void drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRender, SDL_RendererFlip flip = SDL_FLIP_NONE);
    
    SDL_Rect getTextureRect(std::string id);
    
    static TextureManager* Instance(){
        if(s_pInstance == NULL){
            s_pInstance = new TextureManager();
            return s_pInstance;
        }
        return s_pInstance;
    }
    
private:
    std::map<std::string, SDL_Texture*> m_textures;
    std::map<std::string, SDL_Rect> m_rectsizes;
    static TextureManager* s_pInstance;
    SDL_Rect readTextureRect(std::string id);
    TextureManager(){}
};

typedef TextureManager STextureManager;

#endif /* TextureManager_h */
