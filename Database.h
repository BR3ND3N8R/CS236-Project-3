//
// Created by brend on 12/6/2021.
//

#ifndef PROJECT_1_DATABASE_H
#define PROJECT_1_DATABASE_H

#include "Relation.h"
#include <map>


class Database {
public:
    Database() = default;
    ~Database();

    map<string, Relation*> relations;

};


#endif //PROJECT_1_DATABASE_H
