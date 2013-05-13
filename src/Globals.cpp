//
//  Globals.cpp
//  NS2013
//
//  Created by Martial on 26/03/13.
//
//

#include "Globals.h"

Globals* Globals::inst = 0;

Globals::Globals()
{
	
    DMX1_PORT = 0;
    DMX2_PORT = 1;
    
    USB1_PORT = 0;
    USB2_PORT = 3;
    
}

Globals* Globals::instance(){
	if (inst == 0){
		inst = new Globals();
	}
	return inst;
}