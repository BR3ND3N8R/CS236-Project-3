//
// Created by brend on 12/6/2021.
//

#ifndef PROJECT_1_RELATION_H
#define PROJECT_1_RELATION_H

#include "Header.h"
#include <set>
#include <iostream>
#include <sstream>

class Relation {
private:
    set<Tuple> tuples;
    string name;
    Header header;
public:
    Relation(string name, Header header);
    ~Relation() = default;

    void AddTuple(Tuple tuple);

    Relation* Select(unsigned int index, string value);
    Relation* Select(unsigned int index1, unsigned int index2);
    Relation* Project(vector<unsigned int> indices);
    Relation* Rename(vector<string> attributes);

    string ToString();
};


#endif //PROJECT_1_RELATION_H
