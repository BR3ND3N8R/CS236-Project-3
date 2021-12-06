#include "Lexer.h"
#include "ColonAutomaton.h"
#include "ColonDashAutomaton.h"
#include "CommaAutomaton.h"
#include "PeriodAutomaton.h"
#include "Q_MarkAutomaton.h"
#include "Left_ParenAutomaton.h"
#include "Right_ParenAutomaton.h"
#include "MultiplyAutomaton.h"
#include "AddAutomaton.h"
#include "SchemesAutomaton.h"
#include "FactsAutomaton.h"
#include "RulesAutomaton.h"
#include "QueriesAutomaton.h"
#include "IDAutomaton.h"
#include "StringAutomaton.h"
#include "CommentAutomaton.h"
#include "UndefinedAutomaton.h"

Lexer::Lexer() {
    CreateAutomata();
}

Lexer::~Lexer() {
    for (unsigned int i = 0; i <automata.size(); i++) {
        delete automata[i];
    }
    for (unsigned int i = 0; i <tokens.size(); i++) {
        delete tokens[i];
    }
}

void Lexer::CreateAutomata() {
    automata.push_back(new ColonAutomaton());
    automata.push_back(new ColonDashAutomaton());
    automata.push_back(new CommaAutomaton());
    automata.push_back(new PeriodAutomaton());
    automata.push_back(new Q_MarkAutomaton());
    automata.push_back(new Left_ParenAutomaton());
    automata.push_back(new Right_ParenAutomaton());
    automata.push_back(new MultiplyAutomaton());
    automata.push_back(new AddAutomaton());
    automata.push_back(new SchemesAutomaton());
    automata.push_back(new FactsAutomaton());
    automata.push_back(new RulesAutomaton());
    automata.push_back(new QueriesAutomaton());
    automata.push_back(new IDAutomaton());
    automata.push_back(new StringAutomaton());
    automata.push_back(new CommentAutomaton());
    automata.push_back(new UndefinedAutomaton());
}

void Lexer::Run(std::string& input) {
    int lineNumber = 1;
    while (input.size() > 0) {
        int maxRead = 0;
        Automaton* maxAutomaton = automata[0];

        while (isspace(input[0])) { // remove leading whitespace/whitespace between tokens
            if (input[0] == '\n') {
                lineNumber++;
            }
            input = input.substr(1);
        }
        if (input.size() > 0) { // check if whitespace removal resulted in empty string input
            for (unsigned int i = 0; i < automata.size(); i++) {
                int inputRead = automata[i]->Start(input);
                if (inputRead > maxRead) {
                    maxRead = inputRead;
                    maxAutomaton = automata[i];
                }
            }

            if (maxRead > 0) {
                Token* newToken = maxAutomaton->CreateToken(input.substr(0, (maxRead)), lineNumber);
                lineNumber += maxAutomaton->NewLinesRead();
                if (newToken->GetTokenType() != TokenType::COMMENT) {
                    tokens.push_back(newToken);
                }
            } else {
                maxRead = 1;
                Token *newToken = new Token(TokenType::UNDEFINED, input.substr(0, 1), lineNumber);
                tokens.push_back(newToken);
            }

            input = input.substr(maxRead);
        }
    }

    tokens.push_back(new Token(TokenType::EOF_TYPE, "", lineNumber));
}

void Lexer::PrintTokens() {
    for (unsigned int i = 0; i < tokens.size(); i++) {
        cout << tokens[i]->ToString() << endl;
    }
    cout << "Total Tokens = " << tokens.size() << endl;
}

vector<Token *> Lexer::GetTokens() {
    return tokens;
}