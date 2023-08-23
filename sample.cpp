#include "simdb.hpp"
#include <string>
#include <iostream>
#include <assert.h>
int main() {
    simdb db("test", 1024, 4096);
    std::cout << "db count:" << simdb_listDBs().size() << std::endl;
    for(auto& dbName : simdb_listDBs()) {
        std::cout << "db name = " << dbName << std::endl;
    }

    db.put("lock free", "is the way to be");
    std::string s = db.get("lock free");       // returns "is the way to be"
    std::cout << "lock free = " << s << std::endl;

    std::string key = "bin data";
    int buf[7] = {10, 11, 12, 13, 14, 15, 16};
    assert(db.put(key.c_str(), key.size(), buf,  sizeof(int)*7) == true);

    int gbuf[7];
    assert(db.get(key.c_str(), key.size(), (void*)gbuf, sizeof(int)*7));
    for (size_t i = 0; i < 7; i++) {
        std::cout << buf[i] << " ";
        assert(buf[i] == gbuf[i]);
    }
    std::cout << std::endl;
    return 0;
}