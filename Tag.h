#ifndef TAG_H
#define TAG_H

#include <unordered_set>
#include <string>
#include "Image.h"

typedef std::unordered_set<Image*> imgHashTab;

class Tag{
  std::string name;
  imgHashTab images;
public:
  Tag(std::string name){this.name= name;}
  void addImage(Image* img){images.insert(img);}
}

#endif
