//
//  Enemy.hpp
//  sdltutorial
//
//  Created by Siddharth on 26/06/19.
//  Copyright © 2019 Siddharth. All rights reserved.
//

#ifndef Enemy_h
#define Enemy_h

#include <stdio.h>
#include "SDLGameObject.h"

class Enemy : public SDLGameObject
{
public:
//    void load(int x, int y, int width, int height, std::string pTextureID);
//    void draw(SDL_Renderer* pRenderer);
//    void update();
//    void clean();
    Enemy(const LoaderParams* pParams);
    virtual void draw();
    virtual void update();
    virtual void clean();
};

#endif /* Enemy_h */
