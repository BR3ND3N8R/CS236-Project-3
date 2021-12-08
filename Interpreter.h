//
// Created by brend on 12/7/2021.
//

#ifndef PROJECT_1_INTERPRETER_H
#define PROJECT_1_INTERPRETER_H

#include "Database.h"
#include "DatalogProgram.h"

class Interpreter {
private:
    Database database;
    DatalogProgram* datalogProgram;
public:
    explicit Interpreter(DatalogProgram* datalogProgram);
    ~Interpreter() = default;

    Relation* EvaluatePredicate(const Predicate& predicate);

    void Run();

};


#endif //PROJECT_1_INTERPRETER_H
