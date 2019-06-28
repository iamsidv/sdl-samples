//
//  Enemy.cpp
//  sdltutorial
//
//  Created by Siddharth on 26/06/19.
//  Copyright © 2019 Siddharth. All rights reserved.
//

#include "Enemy.h"

Enemy::Enemy(const LoaderParams* pParams):SDLGameObject(pParams){
    
}

void Enemy::update(){
    m_x+=1;
    m_currentFrame = int((SDL_GetTicks()/1000)% 2);
}

void Enemy::draw(){
    SDLGameObject::draw();
}

void Enemy::clean(){
    
}
