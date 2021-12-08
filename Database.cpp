//
// Created by brend on 12/6/2021.
//

#include "Database.h"

Database::~Database() {
    map<string, Relation*>::iterator mapIterator = relations.begin();
    while (mapIterator != relations.end()) {
        delete mapIterator->second;
        mapIterator++;
    }
}

void Database::AddRelation(string name, Relation* relation) {
    relations.insert(pair<string, Relation*>(name, relation));
}

void Database::AddTupleToRelation(string name, Tuple tuple) {
    relations.find(name)->second->AddTuple(tuple);
}

string Database::TestToString() {
    stringstream buffer;
    buffer << "Relations:" << endl;
    for (auto iterator = relations.begin(); iterator != relations.end(); iterator++) {
        buffer << iterator->first << ":" << endl;
        buffer << iterator->second->ToString();
    }

    return buffer.str();
}