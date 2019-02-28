#ifndef IMAGE_H
#define IMAGE_H

#include <unordered_set>
#include <string>

typedef std::unordered_set<std::string> hash_table;

class Image{
    hash_table tags;
    unsigned int num_tags;
    bool is_horizontal;
public:
    Image(bool is_hor, unsigned int num_tags);
    unsigned int getNumTags();
    hash_table getTags();
    bool isHorizontal();
    void addTag(std::string tag);
};

#endif