//
// Created by stars on 2018/12/29.
//

#ifndef KD-INDEX_KD_INDEX_H
#define KD-INDEX_KD_INDEX_H
#include "kdtree.h"
#include <vector>
#include <string>

class ValueIndex {

public:
    ValueIndex();
    ~ValueIndex();
    // insert a coordinate to kd-tree with bounded data
    void Insert(double* coord, void* data);
    void Insert(const std::string& value, void* data);
    // range query by the given coordinate and range, return num-nearest results
    std::vector<std::string*> Range(double* target_coord, double range, int num);
    std::vector<std::string*> Range(const std::string& value, double range, int num);
    // extract coordinate key from input value
    void extractKey(const std::string& data, double* coord);

private:
    // a kd-tree structure for storing index
    kdtree* tree_;
};


#endif //KD-INDEX_KD_INDEX_H
