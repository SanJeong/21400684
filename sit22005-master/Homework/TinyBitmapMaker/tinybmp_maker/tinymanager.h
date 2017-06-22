//
// Created by Changbeom Choi on 2017. 5. 9..
//

#ifndef SIT22005_TINYMANAGER_H
#define SIT22005_TINYMANAGER_H

#include "tinynode.h"
#include <list>
#include <string>
#include<cstring>
class tinymanager
{
public:
    tinymanager();
    virtual ~tinymanager();
    std::string add_image(std::string file_path){
        
        tinynode *node = new tinynode();
        char *nw = new char[strlen(file_path.length)+1];
        strcpy(nw,file_path.c_str());
        node->_path = file_path;
        node-> tb = TinyBitmap(nw);
        if(!node->tb.ex){
            return "None";
        }
        node->tbm = TinyBMPMaker(node->tb);
        veclist.push_back(node);
        
        
        
        
    }
private:
    tinynode* m_pHead;
    std::list<tinynode*> veclist;
    
};


#endif //SIT22005_TINYMANAGER_H
