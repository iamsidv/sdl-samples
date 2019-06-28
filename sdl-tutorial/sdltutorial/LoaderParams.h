//
//  LoaderParams.hpp
//  sdltutorial
//
//  Created by Siddharth on 27/06/19.
//  Copyright © 2019 Siddharth. All rights reserved.
//

#ifndef LoaderParams_h
#define LoaderParams_h

#include <stdio.h>
#include <iostream>

class LoaderParams
{
private:
    std::string m_textureID;
    
    int m_x;
    int m_y;
    
    int m_width;
    int m_height;

public:
    LoaderParams(int x,int y, int width, int height, std::string textureid)
    : m_x(x), m_y(y), m_width(width), m_height(height), m_textureID(textureid)
    {
        
    }

    int getX() const { return m_x; }
    int getY() const { return m_y; }
    int getWidth() const { return m_width; }
    int getHeight() const { return m_height; }
    std::string getTextureId() const { return m_textureID; }
};


#endif /* LoaderParams_h */
