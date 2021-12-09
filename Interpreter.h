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
    vector<string> evaluatedQueries;
    vector<Relation*> queryEvaluatedRelations;

    void InterpretScheme(Predicate* predicate);
    void InterpretFact(Predicate* predicate);
public:
    explicit Interpreter(DatalogProgram* datalogProgram);
    ~Interpreter();

    Relation* EvaluatePredicate(const Predicate& predicate);

    void Run();

    string DatabaseToString();
    string EvaluatedQueriesToString();

};


#endif //PROJECT_1_INTERPRETER_H
