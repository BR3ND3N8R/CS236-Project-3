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

