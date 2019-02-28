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
  void addSlide(Slide* sld){slides.push_back(sld);}
}

#endif
