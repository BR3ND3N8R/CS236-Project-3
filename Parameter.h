//
// Created by brend on 12/4/2021.
//

#ifndef PROJECT_1_PARAMETER_H
#define PROJECT_1_PARAMETER_H

#include <string>
#include <iostream>
using namespace std;

class Parameter {
private:
public:
    Parameter(string input = "");
    ~Parameter() = default;

    string p;

    string ToString();
};


#endif //PROJECT_1_PARAMETER_H
