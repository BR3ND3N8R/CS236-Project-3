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

string Interpreter::DatabaseToString() {
    return database.TestToString();
}

Relation* Interpreter::EvaluatePredicate(const Predicate &predicate) {
    cout << "Interpreter::EvaluatePredicate not yet implemented." << endl;

    return new Relation("test", *(new Header));
}

void Interpreter::Run() {
    for (unsigned int i = 0; i < datalogProgram->schemes.size(); i++) {
        InterpretScheme(datalogProgram->schemes[i]);
    }

    for (unsigned int i = 0; i < datalogProgram->facts.size(); i++) {
        InterpretFact(datalogProgram->facts[i]);
    }
}

void Interpreter::InterpretScheme(Predicate* predicate) {
    string name = predicate->id;
    Header header;
    for (unsigned int i = 0; i < predicate->parameters.size(); i++) {
        header.attributes.push_back(predicate->parameters[i]->ToString());
    }
    database.AddRelation(name, new Relation(name, header));
}

void Interpreter::InterpretFact(Predicate *predicate) {
    string name = predicate->id;
    Tuple tuple;
    for (unsigned int i = 0; i < predicate->parameters.size(); i++) {
        tuple.values.push_back(predicate->parameters[i]->ToString());
    }
    database.AddTupleToRelation(name, tuple);
}