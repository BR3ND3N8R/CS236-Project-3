//
// Created by brend on 12/1/2021.
//

#include "CommentAutomaton.h"

void CommentAutomaton::S0(const std::string &input) {
    if (input[index] == '#') {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void CommentAutomaton::S1(const std::string &input) {
    if (input[index] == '|') {
        inputRead++;
        index++;
        S2(input);
    }
    else {
        inputRead++;
        index++;
        S4(input);
    }
}

void CommentAutomaton::S2(const std::string &input) {
    if (index >= input.size()) { // check if EOF reached
        Serr();
    }
    else if (input[index] == '|') {
        inputRead++;
        index++;
        S3(input);
    }
    else {
        if (input[index] == '\n') {
            newLines++;
        }
        inputRead++;
        index++;
        S2(input);
    }
}

void CommentAutomaton::S3(const std::string &input) {
    if (input[index] == '#') {
        inputRead++;
    }
    else {
        Serr();
    }
}

void CommentAutomaton::S4(const std::string &input) {
    if (input[index] != '\n') {
        inputRead++;
        index++;
        S4(input);
    }
    /* else if (input[index] == '\n') {
        newLines++;
        inputRead++;
        index++;
    } */
}