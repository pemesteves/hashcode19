#include "Image.h"

using namespace std;

unsigned int Image::sequential_id = 0;

Image::Image(bool is_hor, unsigned int num_tags){
    this->is_horizontal = is_hor;
    this->num_tags = num_tags;
    this->id = sequential_id;
    sequential_id++;
}

unsigned int Image::getID(){
    return this->id;
}

unsigned int Image::getNumTags(){
    return this->num_tags;
}

vector<std::string> Image::getTags(){
    return this->tags;
}

bool Image::isHorizontal(){
    return this->is_horizontal;
}

void Image::addTag(std::string tag){
    this->tags.push_back(tag);
}

bool Image::operator<(Image img){
    return this->num_tags*this->getID() < img.getNumTags()*img.getID();
}
