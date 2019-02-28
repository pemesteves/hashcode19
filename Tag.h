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
  void eraseSlide(int index){slides.erase(slides.begin() + index);}
  int getSize(){slides.size();}
  Slide* getSlide(int index = 0){slides.at(index);}
  int getBestSlide(int index){
    int out = 0, best = 0;
    for(int i = 0; i < slides.size(); ++i){
      int aux = 0 /*slides*/;
      if (aux > best){
        out = i;
        best = aux;
      }
    }
    return out;
  }
};

#endif
