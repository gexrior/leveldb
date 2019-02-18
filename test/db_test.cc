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
    db->Put(WriteOptions(), "001", "not world");
    string s;
    db->Get(ReadOptions(), "001", &s);
    cout<<s<<endl;

    db->Put(WriteOptions(), "002", "world");
    string s1;
    db->Delete(WriteOptions(), "002");
    db->Get(ReadOptions(), "002", &s1);
    cout<<s1<<endl;


    delete db;
    return 0;
}
