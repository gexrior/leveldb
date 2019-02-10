//
// Created by stars on 2018/12/29.
//

#include <cstdlib>
#include <iostream>
#include "kd_index.h"

ValueIndex::ValueIndex() {
    tree_ = kd_create(2);
    kd_data_destructor(tree_, free);
}

ValueIndex::~ValueIndex() {
    kd_free(tree_);
}

void ValueIndex::Insert(double *coord, void *data) {
    if (coord == nullptr) {
        return;
    }
    kd_insert(tree_, coord, data);
}

void ValueIndex::Insert(const std::string &value, void *data) {
    try {
        double coord[2];
        extractKey(value, coord);
        Insert(coord, data);
    } catch (...) {

    }
}

std::vector<std::string *> ValueIndex::Range(double *target_coord, double range, int num) {
    kdres *result = kd_nearest_range(tree_, target_coord, range);
    int count = 0;
    std::vector<std::string *> values;
    while (!kd_res_end(result) && count < num) {
        values.push_back((std::string *) kd_res_item_data(result));
        count++;
        kd_res_next(result);
    }
    kd_res_free(result);
    return values;
}

std::vector<std::string *> ValueIndex::Range(const std::string &value, double range, int num) {
    try {
        double coord[2];
        extractKey(value, coord);
        return Range(coord, range, num);
    } catch (...) {
        return std::vector<std::string *>();
    }
}

/**
 * convert string value to coordinate.
 */
void ValueIndex::extractKey(const std::string &data, double *coord) {
    std::string::size_type start, mid;
    start = 0;
    mid = data.find(',');
    coord[0] = strtod(data.substr(start, mid - start).c_str(), nullptr);
    coord[1] = strtod(data.substr(mid + 1, data.length()).c_str(), nullptr);
}

