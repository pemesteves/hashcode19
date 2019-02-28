#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include "Image.h"

using namespace std;

pair<vector<Image*>, vector<Image*>> readFile(std::string file_name);
pair<vector<Image*>, vector<Image*>> divide_images(vector<Image*> &images);

int main(){
    vector<Image*> hor_images, ver_images;
    
    {
        pair<vector<Image*>, vector<Image*>> p = readFile("a_example.txt");
        hor_images = p.first;
        ver_images = p.second;
    }


    return 0;
}


pair<vector<Image*>, vector<Image*>> readFile(std::string file_name){
    ifstream f(file_name);

    string line;
    getline(f, line);

    unsigned num_elements = stoul(line);
    bool hor;
    unsigned num_tags = 0;
    vector<Image*> images; 
    Image* img;

    for(unsigned i = 0; i < num_elements; i++){
        getline(f, line);
        if(line[0] == 'H')
            hor = true;
        else
            hor = false;
            
        line = line.substr(line.find(" ") + 1);
        num_tags = (unsigned)line[0];
        line = line.substr(line.find(" ") + 1);
        img = new Image(hor, num_tags);
        for(unsigned j = 0; j < num_tags; j++){
            img->addTag(line.substr(0, line.find(" ")));
            line = line.substr(line.find(" ")+1);
        }
        images.push_back(img);
    }

    f.close();

    pair<vector<Image*>, vector<Image*>> p = divide_images(images);

    return p;
}

pair<vector<Image*>, vector<Image*>> divide_images(vector<Image*> &images){
    vector<Image*> hor, ver;

    for(unsigned i = 0; i < images.size(); i++){
        if(images[i]->isHorizontal())
            hor.push_back(images[i]);
        else
            ver.push_back(images[i]);
    }

    return make_pair(hor, ver);
}
