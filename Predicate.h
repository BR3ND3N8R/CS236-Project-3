//
// Created by brend on 12/4/2021.
//

#ifndef PROJECT_1_PREDICATE_H
#define PROJECT_1_PREDICATE_H

#include <string>
#include <vector>
#include <iostream>
#include "Parameter.h"
using namespace std;


class Predicate {
private:
    bool deleted = false;
public:
    Predicate() = default;
    ~Predicate();

    string id;
    vector<Parameter*> parameters;

    string ToString();
};


#endif //PROJECT_1_PREDICATE_H
