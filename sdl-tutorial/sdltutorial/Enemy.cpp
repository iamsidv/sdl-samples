//
//  Enemy.cpp
//  sdltutorial
//
//  Created by Siddharth on 26/06/19.
//  Copyright © 2019 Siddharth. All rights reserved.
//

#include "Enemy.h"


void Enemy::update(){
    m_x+=1;
    m_currentFrame = int((SDL_GetTicks()/1000)% 2);
}

void Enemy::load(int x, int y, int width, int height, std::string pTextureID){
    GameObject::load(x, y, width, height, pTextureID);
}

void Enemy::draw(SDL_Renderer *pRenderer){
    GameObject::draw(pRenderer);
}

void Enemy::clean(){
    
}
