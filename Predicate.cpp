//
// Created by brend on 12/4/2021.
//

#include "Predicate.h"

Predicate::~Predicate() {
    if (!deleted) {
        for (unsigned int i = 0; i < parameters.size(); i++) {
            delete parameters[i];
        }
        deleted = true;
    }
}

string Predicate::ToString() {
    string outputString = id + "(";
    for (unsigned int i = 0; i < parameters.size(); i++) {
        outputString += parameters[i]->ToString();
        if (i != (parameters.size() -1)) {
            outputString += ",";
        }
        else {
            outputString += ")";
        }
    }
    return outputString;
}