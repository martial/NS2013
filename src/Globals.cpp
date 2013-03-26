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
	
}

Globals* Globals::instance(){
	if (inst == 0){
		inst = new Globals();
	}
	return inst;
}