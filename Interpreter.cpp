//
// Created by brend on 12/7/2021.
//

#include "Interpreter.h"

Interpreter::Interpreter(DatalogProgram *datalogProgram) {
    this->datalogProgram = datalogProgram;
}

/* Interpreter::~Interpreter() {
    delete datalogProgram;
} */

Relation* Interpreter::EvaluatePredicate(const Predicate &predicate) {
    cout << "Interpreter::EvaluatePredicate not yet implemented." << endl;

    return new Relation("test", *(new Header));
}

void Interpreter::Run() {

}