#include "Image.h"

using namespace std;

Image::Image(bool is_hor, unsigned int num_tags){
    this->is_horizontal = is_hor;
    this->num_tags = num_tags;
    this->id = Image::sequential_id;
    Image::sequential_id++;
}

unsigned int Image::getID(){
    return this->id;
}

unsigned int Image::getNumTags(){
    return this->num_tags;
}

hash_table Image::getTags(){
    return this->tags;
}

bool Image::isHorizontal(){
    return this->is_horizontal;
}

void Image::addTag(std::string tag){
    this->tags.insert(tag);
}
