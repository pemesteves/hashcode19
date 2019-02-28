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
    unsigned int getID();
    unsigned int getNumTags();
    vector<string> getTags();
    bool isHorizontal();
    void addTag(std::string tag);
    bool operator<(Image img);
};

#endif
