//
//  Globals.h
//  NS2013
//
//  Created by Martial on 26/03/13.
//
//

#pragma once
#include "NSScene.h"


class Globals
{
public:
    
    Globals					();
    static Globals*			instance();
    
    NSScene     *           nsScene;
	    
private:
    static Globals*			inst;
};
