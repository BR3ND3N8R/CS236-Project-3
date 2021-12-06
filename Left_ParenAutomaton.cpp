//
// Created by brend on 12/1/2021.
//

#include "Left_ParenAutomaton.h"

void Left_ParenAutomaton::S0(const std::string &input) {
    if (input[index] == '('){
        inputRead++;
    }
    else {
        Serr();
    }
}
