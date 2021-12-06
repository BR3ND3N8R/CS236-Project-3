//
// Created by brend on 12/4/2021.
//

#ifndef PROJECT_1_RULE_H
#define PROJECT_1_RULE_H

#include <string>
#include <vector>
#include <iostream>
#include "Predicate.h"
using namespace std;

class Rule {
private:
    bool deleted = false;
public:
    Rule() = default;
    ~Rule();

    Predicate* headPredicate;
    vector<Predicate*> bodyPredicates;

    string ToString();
};


#endif //PROJECT_1_RULE_H
