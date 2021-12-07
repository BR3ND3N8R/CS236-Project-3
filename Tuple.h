//
// Created by brend on 12/6/2021.
//

#ifndef PROJECT_1_TUPLE_H
#define PROJECT_1_TUPLE_H

#include <vector>
#include <string>
using namespace std;


class Tuple {
private:
public:
    Tuple() = default;
    ~Tuple() = default;

    vector<string> values;

    bool operator< (const Tuple &rhs) const {
        return values < rhs.values;
    }

};


#endif //PROJECT_1_TUPLE_H
