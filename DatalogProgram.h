//
// Created by brend on 12/4/2021.
//

#ifndef PROJECT_1_DATALOGPROGRAM_H
#define PROJECT_1_DATALOGPROGRAM_H

#include "Rule.h"
#include "Predicate.h"
#include "Parameter.h"
#include <sstream>
#include <set>


class DatalogProgram {
private:
public:
    DatalogProgram() = default;
    ~DatalogProgram();

    vector<Predicate*> schemes;
    vector<Predicate*> facts;
    vector<Predicate*> queries;
    vector<Rule*> rules;

    string ToString();
};


#endif //PROJECT_1_DATALOGPROGRAM_H
