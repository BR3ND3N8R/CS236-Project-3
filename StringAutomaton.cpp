//
// Created by brend on 12/1/2021.
//

#include "StringAutomaton.h"

void StringAutomaton::S0(const std::string &input) {
    if (input[index] == '\'') {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void StringAutomaton::S1(const std::string &input) {
    if (index >= input.size()) { // check if EOF reached
        Serr();
    }
    /* else if (isalnum(input[index])) {
        inputRead++;
        index++;
        S1(input);
    } */
    else if (isspace(input[index])) {
        if (input[index] == '\n') {
            newLines++;
        }
        inputRead++;
        index++;
        S1(input);
    }
    else if (input[index] == '\'') {
        inputRead++;
        index++;
        S2(input);
    }
    else {
        inputRead++;
        index++;
        S1(input);
    }
}

void StringAutomaton::S2(const std::string &input) {
    if (input[index] == '\'') {
        inputRead++;
        index++;
        S1(input);
    }
}