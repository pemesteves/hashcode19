#include "Image.h"

using namespace std;

hash_table tags;
    unsigned int num_tags;
    bool is_horizontal;

Image::Image(bool is_hor, unsigned int num_tags){
    this.is_horizontal;
    this.num_tags = num_tags;
}

unsigned int Image::getNumTags(){
    return this.num_tags;
}

hash_table Image::getTags(){
    return this.tags;
}

bool Image::isHorizontal(){
    return this.is_horizontal;
}

void Image::addTag(std::string tag){
    this.tags.insert(tag);
}
