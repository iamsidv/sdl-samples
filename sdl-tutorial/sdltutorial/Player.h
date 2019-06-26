//
//  Player.hpp
//  sdltutorial
//
//  Created by Siddharth on 26/06/19.
//  Copyright © 2019 Siddharth. All rights reserved.
//

#ifndef Player_h
#define Player_h

#include <iostream>
#include "GameObject.h"

class Player : public GameObject
{
public:
    void load(int x, int y, int width, int height, std::string pTextureID);
    void draw(SDL_Renderer* pRenderer);
    void update();
    void clean();
    void printPosition();
};


#endif /* Player_hpp */
