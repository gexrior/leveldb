//
// Created by stars on 2018/12/29.
//

#include <cstdlib>
#include "kd_index.h"

KdIndex::KdIndex() {
    tree_ = kd_create(2);
    kd_data_destructor(tree_, free);
}

KdIndex::~KdIndex() {
    kd_free(tree_);
}

void KdIndex::Insert(const double *coord, void* data) {
    kd_insert(tree_, coord, data);
}

std::vector<std::string*> KdIndex::Range(const double *target_coord, double range, int num) {
    kdres* result = kd_nearest_range(tree_, target_coord, range);
    int count = 0;
    std::vector<std::string*> values;
    while (!kd_res_end(result) && count < num) {
        values.push_back((std::string*)kd_res_item_data(result));
        count++;
        kd_res_next(result);
    }
    kd_res_free(result);
    return values;
}