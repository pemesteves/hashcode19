#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include "Image.h"

using namespace std;

pair<vector<Image*>, vector<Image*>> readFile(std::string file_name);
pair<vector<Image*>, vector<Image*>> divide_images(vector<Image*> &images);

bool comp_images(Image* i1, Image* i2);

int main(){
	vector<Image*> hor_images, ver_images;

	pair<vector<Image*>, vector<Image*>> p = readFile("d_pet_pictures.txt");
	hor_images = p.first;
	ver_images = p.second;

	sort(ver_images.begin(), ver_images.end(), comp_images);
	sort(hor_images.begin(), hor_images.end(), comp_images);

	ofstream f("output.txt");
	unsigned int i = 0, j = ver_images.size() - 1;
	f << (j+i)/2 + hor_images.size() - 1<< endl;
	while(i < j){
		f << ver_images[i]->getID() << " " << ver_images[j]->getID() << endl;
		i++;
		j--;
	}

	i = 0;
	while(i < hor_images.size()){
		f << hor_images[i]->getID() << endl;
		i++;
	}


	f.close();

	/*

	p = readFile("d_pet_pictures.txt");
	hor_images = p.first;
	ver_images = p.second;

	sort(ver_images.begin(), ver_images.end(), comp_images);
	sort(hor_images.begin(), hor_images.end(), comp_images);

	f.open("output4.txt");
	i = 0, j = ver_images.size() - 1;
	f << (j + 1)/2  + hor_images.size()<< endl;
	while(i < j){
		f << ver_images[i]->getID() << " " << ver_images[j]->getID() << endl;
		i++;
		j--;
	}

	i = 0;
	while(i < hor_images.size()){
		f << hor_images[i]->getID() << endl;
		i++;
	}


	f.close();

	p = readFile("e_shiny_selfies.txt");
	hor_images = p.first;
	ver_images = p.second;

	sort(ver_images.begin(), ver_images.end(), comp_images);
	sort(hor_images.begin(), hor_images.end(), comp_images);

	f.open("output5.txt");
	i = 0, j = ver_images.size() - 1;
	f << (j + 1)/2  + hor_images.size()<< endl;
	while(i < j){
		f << ver_images[i]->getID() << " " << ver_images[j]->getID() << endl;
		i++;
		j--;
	}

	i = 0;
	while(i < hor_images.size()){
		f << hor_images[i]->getID() << endl;
		i++;
	}


	f.close();
*/
	return 0;
}


pair<vector<Image*>, vector<Image*>> readFile(std::string file_name){
	ifstream f(file_name);

	string line;
	getline(f, line);

	unsigned num_elements = stoul(line);
	bool hor;
	unsigned num_tags = 0;
	vector<Image*> images;
	Image* img;

	for(unsigned i = 0; i < num_elements; i++){
		getline(f, line);
		if(line[0] == 'H')
			hor = true;
		else
			hor = false;
		line = line.substr(line.find(" ") + 1);
		num_tags = (unsigned)line[0];
		line = line.substr(line.find(" ") + 1);
		img = new Image(hor, num_tags);
		for(unsigned j = 0; j < num_tags; j++){
			img->addTag(line.substr(0, line.find(" ")));
			line = line.substr(line.find(" ")+1);
		}

		images.push_back(img);
	}

	f.close();

	pair<vector<Image*>, vector<Image*>> p = divide_images(images);

	return p;
}

pair<vector<Image*>, vector<Image*>> divide_images(vector<Image*> &images){
	vector<Image*> hor, ver;

	for(unsigned i = 0; i < images.size(); i++){
		if(images[i]->isHorizontal())
			hor.push_back(images[i]);
		else
			ver.push_back(images[i]);
	}

	return make_pair(hor, ver);
}

bool comp_images(Image* i1, Image* i2){
	return (*i1) < (*i2);
}
