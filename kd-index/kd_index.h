//
// Created by stars on 2018/12/29.
//

#ifndef TEST_KD_INDEX_H
#define TEST_KD_INDEX_H
#include "kdtree.h"
#include <vector>
#include <string>

class KdIndex {

public:
    KdIndex();
    ~KdIndex();
    // insert a coordinate to kd-tree with bounded data
    void Insert(const double* coord, void* data);
    // range query by the given coordinate and range, return num-nearest results
    std::vector<std::string*> Range(const double* target_coord, double range, int num);

private:
    // a kd-tree structure for storing index
    kdtree* tree_;
};


#endif //TEST_KD_INDEX_H
