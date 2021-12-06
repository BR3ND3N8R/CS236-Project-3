//
// Created by brend on 12/1/2021.
//

#ifndef PROJECT_1_UNDEFINEDAUTOMATON_H
#define PROJECT_1_UNDEFINEDAUTOMATON_H

#include "Automaton.h"


class UndefinedAutomaton : public Automaton
{
private:
    void S1(const std::string& input);
    void S2(const std::string& input);
    void S3(const std::string& input);
    void S4(const std::string& input);
public:
    UndefinedAutomaton() : Automaton(TokenType::UNDEFINED) {}  // Call the base constructor

    void S0(const std::string& input);
};


#endif //PROJECT_1_UNDEFINEDAUTOMATON_H
