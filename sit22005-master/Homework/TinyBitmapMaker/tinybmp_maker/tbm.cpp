#include <iostream>
#include "tinybmp_def.h"
#include "tinybmp.h"
#include "tinybmp_maker.h"
#include <list>
#include <string>
#include <cstring>

using namespace std; 
list<string> vecList;

string add_image(string file_path){
	//const char* path = new char[strlen(file_path.length)+1];
	//strcpy(path, file_path.c_str());
	const char *path = file_path.c_str();
	TinyBitmap tb = TinyBitmap(path);

	if(!tb.ex){
		return "None";
	}
	else{
	vecList.push_back(file_path);
	return file_path;
	}
}
void show(){
    
    int numbering = 1;
    for(list<string>::iterator iter = vecList.begin(); iter != vecList.end(); ++iter)
    {
        cout<<numbering<<". "<<*iter<<endl;
        numbering = numbering + 1;
    }
    
} 




bool remove_image(string file_name){
	for(list<string>::iterator iter = vecList.begin(); iter != vecList.end(); ++iter)
    {
        if(*iter == file_name){
        	vecList.erase(iter);
        	return true;
        }
    }
    return false;
}

bool move_image(string image_name, int direction){
	int count = 0;
	int anum = vecList.size();
	string temp;
	int tempiter = 0;
	for(list<string>::iterator iter = vecList.begin(); iter != vecList.end(); ++iter)
    {
        if(*iter == image_name){
        	temp = *iter;
        	tempiter = count;
        	vecList.erase(iter);
        	break;
        	
        }
    count = count + 1;
    }
    
    if(count-direction<0 or count-direction>anum){
    	return false;
    }else{
    	if(direction>0){
    	int ncount = 0;
    	count = count - direction;
    	
    	for(list<string>::iterator iter = vecList.begin(); iter != vecList.end(); ++iter)
    {
    	if(count == ncount){
    		vecList.insert(iter, temp);
    		return true;
    	}    
    ncount = ncount + 1;
    }
}else{
	int ncount = 0;
    count = count - direction-1;
    	
    	for(list<string>::iterator iter = vecList.begin(); iter != vecList.end(); ++iter)
    {
    	if(count == ncount){
    		vecList.insert(iter, temp);
    		return true;
    	}    
    ncount = ncount + 1;
    }
	
}
}
}

void process(int opt){

	for(list<string>::iterator iter = vecList.begin(); iter != vecList.end(); ++iter)
    {
    	
    string temp = *iter;
    char* cm = new char[temp.length()+1];
    strcpy(cm,temp.c_str());

     TinyBitmap tb = TinyBitmap(cm);
	 TinyBMPMaker tbm(tb);   
     if(opt==1){
     	tbm.blur();
     }
     if(opt==2){
     	tbm.sharpen();
     }
     if(opt==3){
     	tbm.up_side_down();
     }
     if(opt==4){
     	tbm.left_right_filp();
     }
     tbm.export_image(cm);
    }
}

void menu(){
    bool close = false;
    
    while(!close){
    cout<<"Which process do you want?"<<endl;
    cout<<endl;
    cout<<"1. add new image"<<endl;
    cout<<"2. remove the image"<<endl;
    cout<<"3. move the image"<<endl;
    cout<<"4. select the filter"<<endl;
    cout<<"5. Close"<<endl;
    cout<<endl;
    cout<<">>";
    int menu1;
    cin>>menu1;
    if(menu1 == 1){
        cout<<"Enter the image's path"<<endl;
        cout<<">>";
        string path1;
        cin>>path1;
        
        add_image(path1);
        cout<<"Now the list is: "<<endl;
        show();
        cout<<endl;
    }
    if(menu1 == 2){
        
        cout<<"selsct the image's path which you want remove"<<endl;
        show();
        cout<<">>";
        string path2;
        cin>>path2;
        
        remove_image(path2);
        cout<<"Now the list is: "<<endl;
        show();
        cout<<endl;
    }
    if(menu1 == 3){
        cout<<"selsct the image's path which you want move"<<endl;
        show();
        cout<<">>";
        string path3;
        cin>>path3;
        cout<<"How many move do you want"<<endl;
        cout<<">>";
        int moving;
        cin >> moving;
        
        move_image(path3,moving);
        cout<<"Now the list is: "<<endl;
        show();
        cout<<endl;
    }
    if(menu1 == 4){
        cout<<"selsct the filter that you want"<<endl;
        cout<<"1. blur"<<endl;
        cout<<"2. sharpen"<<endl;
        cout<<"3. Up down flip"<<endl;
        cout<<"4. Left right flip"<<endl;
        cout<<">>";
        int command1;
        cin>>command1;
        process(command1);
        cout<<endl;
        cout<<"Process complete! GO an check your image!"<<endl;
    }
    if(menu1 == 5){
        close = true;
    }
}
}


int main(int argc, char** argv)
{
	std::cout << "Hello!!" << std::endl;
	
	menu();
	return 0;
}