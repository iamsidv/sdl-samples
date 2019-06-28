//
//  SDLGameObject.cpp
//  sdltutorial
//
//  Created by Siddharth on 28/06/19.
//  Copyright © 2019 Siddharth. All rights reserved.
//

#include <stdio.h>
#include "SDLGameObject.h"

#include "Game.h"
#include "TextureManager.h"

SDLGameObject::SDLGameObject(const LoaderParams* pParams) : GameObject(pParams)
{
    m_x = pParams->getX();
    m_y = pParams->getY();
    m_width = pParams->getWidth();
    m_height = pParams->getHeight();
    m_textureID = pParams->getTextureId();
    
    m_currentRow = 1;
    m_currentFrame = 0;
    
}

void SDLGameObject::draw()
{
    ////    STextureManager::Instance()->draw(m_textureID, m_x, m_y, m_width, m_height, pRenderer);
    STextureManager::Instance()->drawFrame(m_textureID, m_x, m_y, m_width, m_height,
                                           m_currentRow, m_currentFrame, TheGame::Instance()->getRenderer());
}

void SDLGameObject::update(){
    
}
void SDLGameObject::clean(){
    
}

