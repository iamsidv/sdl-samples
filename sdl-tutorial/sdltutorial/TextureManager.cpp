//
//  TextureManager.cpp
//  sdltutorial
//
//  Created by Siddharth on 06/06/19.
//  Copyright © 2019 Siddharth. All rights reserved.
//

#include "SDLImageHeader.h"
#include "SDLHeader.h"
#include <map>

#include "TextureManager.h"

//This has to be in cpp only!
TextureManager* TextureManager::s_pInstance = NULL;

bool TextureManager::load(std::string fileName, std::string id, SDL_Renderer *pRender){
    //Load image into a surface
    SDL_Surface* pTempSurface = IMG_Load(fileName.c_str());
    if(pTempSurface==NULL){
        printf("Couldnt find the image at %s \n", fileName.c_str());
        return false;
    }
    //Create a texture from surface and free the temp surface.
    SDL_Texture* pTexture = SDL_CreateTextureFromSurface(pRender, pTempSurface);
    SDL_FreeSurface(pTempSurface);
    //
    if(pTexture==NULL){
        printf("Could not create a texture. \n");
        return false;
    }
    //Add a texture to the map with the key as an id.
    m_textures[id] = pTexture;
    m_rectsizes[id] = readTextureRect(id);
    
    printf("Texture with id '%s' is loaded successfully \n", id.c_str());
    return true;
}

void TextureManager::draw(std::string id, int x, int y, int width, int height,
                          SDL_Renderer *pRender, SDL_RendererFlip flip){

    SDL_Rect srcRect;
    SDL_Rect dstRect;

    srcRect.x = 0;
    srcRect.y = 0;
    srcRect.w = dstRect.w = width;
    srcRect.h = dstRect.h = height;
    dstRect.x = x;
    dstRect.y = y;
    
    //Get the texture from the map
    SDL_Texture* pTexture = m_textures[id];
    if(pTexture==NULL){
        printf("Could not find the texture with id: %s \n", id.c_str());
    }else{
        SDL_RenderCopyEx(pRender, pTexture, &srcRect, &dstRect, 0, 0, flip);
    }
}

void TextureManager::drawFrame(std::string id, int x, int y, int width, int height, int currentRow,
                               int currentFrame, SDL_Renderer *pRender, SDL_RendererFlip flip){
    
    SDL_Rect srcRect;
    SDL_Rect dstRect;
    
    srcRect.x = width * currentFrame;
    srcRect.y = height * (currentRow-1);
    srcRect.w = dstRect.w = width;
    srcRect.h = dstRect.h = height;
    dstRect.x = x;
    dstRect.y = y;
    
    SDL_Texture* pTexture = m_textures[id];
    if(pTexture==NULL){
        printf("Could not find the texture with id: %s \n", id.c_str());
    }else{
        SDL_RenderCopyEx(pRender, pTexture, &srcRect, &dstRect, 0, 0, flip);
    }
}

SDL_Rect TextureManager::getTextureRect(std::string id){
    return m_rectsizes[id];
}

SDL_Rect TextureManager::readTextureRect(std::string id){
    SDL_Rect destRect;
    SDL_Texture* pTexture = m_textures[id];
    SDL_QueryTexture(pTexture, NULL, NULL, &destRect.w, &destRect.h);
    return destRect;
}
