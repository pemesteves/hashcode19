#ifndef SLIDE_H_
#define SLIDE_H_
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Image;
class Tag;

//Slide
class Slide {
	static int static_order;
	vector<Tag> tags;
public:
	Slide(vector<Tag> t) : tags(t) {static_order++;}
	vector<Tag> const getTags() {return tags;}
};


//VerticalSlide
class VerticalSlide : public Slide {
	Image* image1;
	Image* image2;
public:
	VerticalSlide(Image* i1, Image* i2, vector<Tag> t) : Slide(t), image1(i1), image2(i2) {}
	Image* const getImage1() {return image1;}
	Image* const getImage2() {return image2;}
};


//HorizontalSlide
class HorizontalSlide : public Slide {
	Image* image;
public:
	HorizontalSlide(Image* i, vector<Tag> t) : Slide(t), image(i) {}
	Image* const getImage1() {return image;}
	Image* const getImage2() {return image;}
};

#endif /* SLIDE_H_ */
