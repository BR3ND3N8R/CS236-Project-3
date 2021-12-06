//
// Created by brend on 12/1/2021.
//

#include "UndefinedAutomaton.h"

void UndefinedAutomaton::S0(const std::string &input) {
    /* if ( (!isspace(input[index])) && (!isalpha(input[index])) && (input[index] != '#') &&
        (input[index] != '\'') && (input[index] != ',') &&
        (input[index] != '.') ) {

    } */

    if (input[index] == '#') {
        inputRead++;
        index++;
        S1(input);
    }
    else if (input[index] == '\'') {
        inputRead++;
        index++;
        S3(input);
    }
    else {
        inputRead++;
    }
}

void UndefinedAutomaton::S1(const std::string &input) {
    if (input[index] == '|') {
        inputRead++;
        index++;
        S2(input);
    }
    else {
        Serr();
    }
}

void UndefinedAutomaton::S2(const std::string &input) {
    if (index < input.size()) { // check if EOF reached
        if (input[index] == '|') {
            Serr();
        } else {
            if (input[index] == '\n') {
                newLines++;
            }
            inputRead++;
            index++;
            S2(input);
        }
    }
}

void UndefinedAutomaton::S3(const std::string &input) {
    if (index < input.size()) { // check if EOF reached
        if ((isalpha(input[index])) || (isspace(input[index]))) {
            if (input[index] == '\n') {
                newLines++;
            }
            inputRead++;
            index++;
            S3(input);
        }
        else if (input[index] == '\'') {
            inputRead++;
            index++;
            S4(input);
        }
    }
}

void UndefinedAutomaton::S4(const std::string &input) {
    if (input[index] == '\'') {
        inputRead++;
        index++;
        S3(input);
    }
    else {
        Serr();
    }
}