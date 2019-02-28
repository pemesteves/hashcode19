#ifndef TAG_H
#define TAG_H

#include <vector>
#include <string>
#include "Slide.h"

class Tag{
  std::string name;
  std::vector<Slide*> slides;
public:
  Tag(std::string name){this->name = name;}
  void addImage(Image* img){images.insert(img);}
}

#endif
