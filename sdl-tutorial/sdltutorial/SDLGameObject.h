//
//  SDLGameObject.h
//  sdltutorial
//
//  Created by Siddharth on 28/06/19.
//  Copyright © 2019 Siddharth. All rights reserved.
//

#ifndef SDLGameObject_h
#define SDLGameObject_h

#include "SDLHeader.h"
#include "GameObject.h"

class SDLGameObject : public GameObject
{
    public :
    
    SDLGameObject(const LoaderParams* pParams);
    
    virtual void draw();
    virtual void update();
    virtual void clean();
    
protected:
    
    int m_x;
    int m_y;
    int m_width;
    int m_height;
    int m_currentFrame;
    int m_currentRow;
    
    std::string m_textureID;
};

#endif /* SDLGameObject_h */
