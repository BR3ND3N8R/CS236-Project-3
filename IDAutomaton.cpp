//
// Created by brend on 12/1/2021.
//

#include "IDAutomaton.h"

void IDAutomaton::S0(const std::string& input) {
    if (isalpha(input[index])) {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void IDAutomaton::S1(const std::string &input) {
    if (index < input.size()) { // check if EOF reached
        if (isalnum(input[index])) {
            inputRead++;
            index++;
            S1(input);
        }
    }
}