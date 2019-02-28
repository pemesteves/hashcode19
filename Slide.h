#ifndef SLIDE_H_
#define SLIDE_H_
#include "Image.h"
#include "Tag.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

//Slide
class Slide {
protected:
	static int static_order;
	vector<string> tags;
public:
	Slide() {static_order++;}
	const vector<string> getTags() {return tags;}
};


//VerticalSlide
class VerticalSlide : public Slide {
	Image* image1;
	Image* image2;
public:
	VerticalSlide(Image* i1, Image* i2) : Slide(), image1(i1), image2(i2) {
		tags = i1->getTags();

		vector<string> tags2 = i2->getTags();
		
		for(unsigned int i = 0; i < tags2.size(); i++) {
			bool found = false;
			
			for(unsigned int j = 0; j < tags.size(); i++) {
				if (tags[j] == tags2[i]) {
					found = true;
					break;
				}
			}

			if (!found) 
			tags.push_back(tags2[i]);
		}
	}

	Image* const getImage1() {return image1;}
	Image* const getImage2() {return image2;}
};


//HorizontalSlide
class HorizontalSlide : public Slide {
	Image* image;
public:
	HorizontalSlide(Image* i) : Slide(), image(i) {tags = i->getTags();}
	const Image* getImage1() {return image;}
	const Image* getImage2() {return image;}
};

#endif /* SLIDE_H_ */
