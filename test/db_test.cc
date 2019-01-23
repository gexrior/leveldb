#include "leveldb/db.h"
#include <cstdio>
#include <iostream>

using namespace std;
using namespace leveldb;

int main() {
    DB* db = nullptr;
    Options op;
    op.create_if_missing = true;
    Status status = DB::Open(op, "testdb", &db);
    assert(status.ok());
    db->Put(WriteOptions(), "hello", "not world");
    string s;
    db->Get(ReadOptions(), "hello", &s);
    cout<<s<<endl;
    delete db;
    return 0;
}