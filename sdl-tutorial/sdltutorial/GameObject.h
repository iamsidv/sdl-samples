//
//  GameObject.hpp
//  sdltutorial
//
//  Created by Siddharth on 26/06/19.
//  Copyright © 2019 Siddharth. All rights reserved.
//

#ifndef GameObject_h
#define GameObject_h

#include <stdio.h>
#include <iostream>

#include "LoaderParams.h"

class GameObject
{
public:
//    virtual void load(int x, int y, int width, int height, std::string textureID);
//    virtual void draw(SDL_Renderer* pRenderer);
//    virtual void update();
//    virtual void clean();
    virtual void draw() = 0;
    virtual void update() = 0;
    virtual void clean() = 0;
protected:
    GameObject(const LoaderParams* pParams){}
    virtual ~GameObject(){}
};

#endif /* GameObject_hpp */
