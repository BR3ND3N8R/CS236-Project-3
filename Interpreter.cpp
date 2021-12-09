//
// Created by brend on 12/7/2021.
//

#include "Interpreter.h"

Interpreter::Interpreter(DatalogProgram *datalogProgram) {
    this->datalogProgram = datalogProgram;
}

Interpreter::~Interpreter() {
    for (unsigned int i = 0; i < queryEvaluatedRelations.size(); i++) {
        delete queryEvaluatedRelations[i];
    }
}

/* Interpreter::~Interpreter() {
    delete datalogProgram;
} */

string Interpreter::DatabaseToString() {
    return database.TestToString();
}

string Interpreter::EvaluatedQueriesToString() {
    stringstream buffer;
    for (unsigned int i = 0; i < queryEvaluatedRelations.size(); i++) {
        Relation* relation = queryEvaluatedRelations[i];
        buffer << evaluatedQueries[i] << "? ";
        if (relation->Size() > 0) {
            buffer << "Yes(" << relation->Size() << ")" << endl;
            buffer << relation->TuplesToString();
        } else {
            buffer << "No" << endl;
        }
    }

    return buffer.str();
}

// Make a copy of the relation that's in the database, then perform the query on it.
Relation* Interpreter::EvaluatePredicate(const Predicate& predicate) {
    Relation* matchingRelation = database.GetRelation(predicate.id);
    Relation* relationToEvaluate = new Relation(matchingRelation->GetName(), matchingRelation->GetHeader());
    relationToEvaluate->tuples = matchingRelation->tuples;

    vector<unsigned int> indices;
    vector<string> attributes;
    map<string, unsigned int> seenVariables;
    for (unsigned int i = 0; i < predicate.parameters.size(); i++) {
        Parameter* parameter = predicate.parameters[i];
        if (parameter->IsConstant()) {
            Relation* tempRelation = relationToEvaluate;
            relationToEvaluate = relationToEvaluate->Select(i, parameter->p);
            delete tempRelation;
        }
        else if (seenVariables.count(parameter->ToString()) > 0) {
            Relation* tempRelation = relationToEvaluate;
            relationToEvaluate = relationToEvaluate->Select(seenVariables.find(parameter->ToString())->second, i);
            delete tempRelation;
        }
        else {
            indices.push_back(i);
            attributes.push_back(parameter->ToString());
            seenVariables.insert(pair<string, unsigned int>(parameter->ToString(), i));
        }
    }

    Relation* tempRelation = relationToEvaluate;
    relationToEvaluate = relationToEvaluate->Project(indices);
    relationToEvaluate = relationToEvaluate->Rename(attributes);
    delete tempRelation;

    return relationToEvaluate;
}

void Interpreter::Run() {
    for (unsigned int i = 0; i < datalogProgram->schemes.size(); i++) {
        InterpretScheme(datalogProgram->schemes[i]);
    }

    for (unsigned int i = 0; i < datalogProgram->facts.size(); i++) {
        InterpretFact(datalogProgram->facts[i]);
    }

    for (unsigned int i = 0; i < datalogProgram->queries.size(); i++) {
        queryEvaluatedRelations.push_back(EvaluatePredicate(*datalogProgram->queries[i]));
        evaluatedQueries.push_back(datalogProgram->queries[i]->ToString());
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