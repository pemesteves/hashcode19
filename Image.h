#ifndef IMAGE_H
#define IMAGE_H

#include <vector>
#include <string>

class Image{
    unsigned int id;
    static unsigned int sequential_id;
    vector<std::string> tags;
    unsigned int num_tags;
    bool is_horizontal;
public:
    Image(bool is_hor, unsigned int num_tags);
    static void initialize_ids(){Image::sequential_id = 1;}
    unsigned int getID();
    unsigned int getNumTags();
    vector<string> getTags();
    bool isHorizontal();
    void addTag(std::string tag);
};

#endif