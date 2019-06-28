//
//  GameObject.cpp
//  sdltutorial
//
//  Created by Siddharth on 26/06/19.
//  Copyright © 2019 Siddharth. All rights reserved.
//

//#include "GameObject.h"
//#include "TextureManager.h"

//void GameObject::load(int x, int y, int width, int height, std::string textureID){
//    printf("load gameobject \n");
//    m_x = x;
//    m_y = y;
//    m_width = width;
//    m_height = height;
//    m_textureID = textureID;
//
//    m_currentRow = 1;
//    m_currentFrame = 0;
//}
//
//void GameObject::draw(SDL_Renderer * pRenderer){
//    printf("draw gameobject \n");
////    STextureManager::Instance()->draw(m_textureID, m_x, m_y, m_width, m_height, pRenderer);
//    STextureManager::Instance()->drawFrame(m_textureID, m_x, m_y, m_width, m_height, m_currentRow, m_currentFrame, pRenderer);
//}
//
//void GameObject::update(){
//    printf("update gameobject \n");
//    m_y +=1;
//    m_x +=1;
//}
//
//void GameObject::clean(){
//    printf("clean gameobject \n");
//}
