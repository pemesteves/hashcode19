#ifndef TAG_H
#define TAG_H

#include <unordered_set>
#include <string>
typedef unordered_set<Image*> imgHashTab;


class Tag{
  string name;
  imgHashTab images;
public:
  Tag(string name){this.name= name;}
  void addImage(Image* img){images.insert(img);}
}

#endif
