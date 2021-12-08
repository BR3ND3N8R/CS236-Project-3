//
// Created by brend on 12/6/2021.
//

#include "Relation.h"

Relation::Relation(string name, Header header) {
    this->name = name;
    this->header = header;
}

void Relation::AddTuple(Tuple tuple) {
    tuples.insert(tuple);
}

Relation* Relation::Select(unsigned int index, string value) {
    Relation* newRelation = new Relation(name, header);

    set<Tuple>::iterator tuplesIterator = tuples.begin();
    for (unsigned int i = 0; i < tuples.size(); i++) {
        Tuple tempTuple = *tuplesIterator;
        if (tempTuple.values[index] == value) {
            newRelation->AddTuple(tempTuple);
        }
        tuplesIterator++;
    }

    return newRelation;
}
Relation* Relation::Select(unsigned int index1, unsigned int index2) {
    Relation* newRelation = new Relation(name, header);

    set<Tuple>::iterator tuplesIterator = tuples.begin();
    for (unsigned int i = 0; i < tuples.size(); i++) {
        Tuple tempTuple = *tuplesIterator;
        if (tempTuple.values[index1] == tempTuple.values[index2]) {
            newRelation->AddTuple(tempTuple);
        }
        tuplesIterator++;
    }

    return newRelation;
}
Relation* Relation::Project(vector<unsigned int> indices) {
    Relation* newRelation = new Relation(name, header);

    set<Tuple>::iterator tuplesIterator = tuples.begin();
    for (unsigned int i = 0; i < tuples.size(); i++) {
        Tuple newTuple;
        Tuple tempTuple = *tuplesIterator;
        for (unsigned int j = 0; j < indices.size(); j++) {
            newTuple.values.push_back(tempTuple.values[indices[j]]);
        }
        newRelation->AddTuple(newTuple);
        tuplesIterator++;
    }

    return newRelation;
}
Relation* Relation::Rename(vector<string> attributes) {
    Relation* newRelation = new Relation(name, header);
    newRelation->tuples = tuples;
    newRelation->header.attributes = attributes;

    return newRelation;
}

string Relation::ToString() {
    stringstream buffer;
    for (Tuple tuple : tuples ) {
        for (unsigned int i = 0; i < header.attributes.size(); i++) {
            buffer << header.attributes[i] << "=" << tuple.values[i];
            if (i != header.attributes.size()) {
                buffer << ", ";
            }
        }
        buffer << endl;
    }
}