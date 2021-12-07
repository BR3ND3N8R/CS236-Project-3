//
// Created by brend on 12/6/2021.
//

#include "Relation.h"

Relation Relation::Select(unsigned int index, string value) {
    Relation newRelation;
    newRelation.name = this->name;
    newRelation.header = this->header;

    set<Tuple>::iterator tuplesIterator = tuples.begin();
    for (unsigned int i = 0; i < tuples.size(); i++) {
        Tuple tempTuple = *tuplesIterator;
        if (tempTuple.values[index] == value) {
            newRelation.tuples.insert(tempTuple);
        }
        tuplesIterator++;
    }

    return newRelation;
}
Relation Relation::Select(unsigned int index1, unsigned int index2) {
    Relation newRelation;
    newRelation.name = this->name;
    newRelation.header = this->header;

    set<Tuple>::iterator tuplesIterator = tuples.begin();
    for (unsigned int i = 0; i < tuples.size(); i++) {
        Tuple tempTuple = *tuplesIterator;
        if (tempTuple.values[index1] == tempTuple.values[index2]) {
            newRelation.tuples.insert(tempTuple);
        }
        tuplesIterator++;
    }

    return newRelation;
}
Relation Relation::Project(vector<unsigned int> indices) {
    cout << "Relation::Project not yet implemented." << endl;
    return *this;
}
Relation Relation::Rename(vector<string> attributes) {
    cout << "Relation::Rename not yet implemented." << endl;
    return *this;
}