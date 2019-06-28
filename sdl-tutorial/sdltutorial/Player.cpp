//
//  Player.cpp
//  sdltutorial
//
//  Created by Siddharth on 26/06/19.
//  Copyright © 2019 Siddharth. All rights reserved.
//

#include "Player.h"

//void Player::load(int x, int y, int width, int height, std::string pTextureID){
//    GameObject::load(x, y, width, height, pTextureID);
//}
//
//void Player::draw(SDL_Renderer *pRenderer){
//    GameObject::draw(pRenderer);
//}

Player::Player(const LoaderParams* pParams):SDLGameObject(pParams){
}

void Player::draw(){
    SDLGameObject::draw();
}

void Player::update(){
    m_y+=1;
}

void Player::clean(){
    
}
