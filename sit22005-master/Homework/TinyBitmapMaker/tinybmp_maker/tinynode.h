//
// Created by Changbeom Choi on 2017. 5. 9..
//

#ifndef SIT22005_TINYNODE_H
#define SIT22005_TINYNODE_H

#include "tinylist_def.h"
#include <list>
#include <string>
#include<cstring>
#include "tbm.cpp"
class tinynode
{
public:
    tinynode();

private:
    std::string _path;
    TinyBitmap tb;
	TinyBMPMaker tbm;
    
};


#endif //SIT22005_TINYNODE_H
