//
// Created by brend on 12/4/2021.
//

#include "DatalogProgram.h"

/* DatalogProgram::DatalogProgram() {
    cout << "NOT YET COMPLETE: Calling DatalogProgram constructor" << endl;
} */

DatalogProgram::~DatalogProgram() {
    for (unsigned int i = 0; i < schemes.size(); i++) {
        delete schemes[i];
        schemes.clear();
    }
    for (unsigned int i = 0; i < facts.size(); i++) {
        delete facts[i];
        facts.clear();
    }
    for (unsigned int i = 0; i < rules.size(); i++) {
        delete rules[i];
        rules.clear();
    }
    for (unsigned int i = 0; i < queries.size(); i++) {
        delete queries[i];
        queries.clear();
    }
}

string DatalogProgram::ToString() {
    stringstream buffer;
    buffer << "Schemes(" << schemes.size() << "):" << endl;
    for (unsigned int i = 0; i < schemes.size(); i++) {
        buffer << "  " << schemes[i]->ToString() << endl;
    }
    buffer << "Facts(" << facts.size() << "):" << endl;
    for (unsigned int i = 0; i < facts.size(); i++) {
        buffer << "  " << facts[i]->ToString() << "." << endl;
    }
    buffer << "Rules(" << rules.size() << "):" << endl;
    for (unsigned int i = 0; i < rules.size(); i++) {
        buffer << "  " << rules[i]->ToString() << "." << endl;
    }
    buffer << "Queries(" << queries.size() << "):" << endl;
    for (unsigned int i = 0; i < queries.size(); i++) {
        buffer << "  " << queries[i]->ToString() << "?" << endl;
    }

    set<string> domain;
    for (unsigned int i = 0; i < facts.size(); i++) {
        for (unsigned int j = 0; j < facts[i]->parameters.size(); j++) {
            domain.insert(facts[i]->parameters[j]->ToString());
        }
    }
    buffer << "Domain(" << domain.size() << "):" << endl;
    set<string>::iterator domainIterator = domain.begin();
    for (unsigned int i = 0; i < domain.size(); i++) {
        buffer << "  " << *domainIterator << endl;
        domainIterator++;
    }

    return buffer.str();
}

