//
// Created by brend on 12/4/2021.
//

#include "Rule.h"

/* Rule::Rule() {
    cout << "NOT YET COMPLETE: Calling Rule constructor" << endl;
} */

Rule::~Rule() {
    if (!deleted) {
        delete headPredicate;
        for (unsigned int i = 0; i < bodyPredicates.size(); i++) {
            delete bodyPredicates[i];
        }
        deleted = true;
    }
}

string Rule::ToString() {
    string outputString = headPredicate->ToString() + " :- ";
    for (unsigned int i = 0; i < bodyPredicates.size(); i++) {
        outputString+= bodyPredicates[i]->ToString();
        if (i != (bodyPredicates.size() - 1)) {
            outputString+= ",";
        }
    }
    return outputString;
}