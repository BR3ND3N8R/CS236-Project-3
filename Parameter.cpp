//
// Created by brend on 12/4/2021.
//

#include "Parameter.h"

Parameter::Parameter(string input) {
    p = input;
}

/* Parameter::~Parameter() {
    cout << "NOT YET COMPLETE: Calling Parameter destructor" << endl;
} */

string Parameter::ToString() {
    return p;
}

bool Parameter::IsConstant() {
    if (p[0] == '\'') {
        return true;
    }
    else {
        return false;
    }
}