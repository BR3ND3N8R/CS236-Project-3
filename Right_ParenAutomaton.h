//
// Created by brend on 12/1/2021.
//

#ifndef PROJECT_1_RIGHT_PARENAUTOMATON_H
#define PROJECT_1_RIGHT_PARENAUTOMATON_H

#include "Automaton.h"


class Right_ParenAutomaton : public Automaton
{
public:
    Right_ParenAutomaton() : Automaton(TokenType::RIGHT_PAREN) {}  // Call the base constructor

    void S0(const std::string& input);
};


#endif //PROJECT_1_RIGHT_PARENAUTOMATON_H
