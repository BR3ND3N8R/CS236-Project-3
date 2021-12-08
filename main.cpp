#include "Lexer.h"
#include "Parser.h"
#include "Interpreter.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;


int main(int argc, char** argv) {

    if (argc < 2){
        cerr << "Please provide input file." << endl;
        return 1;
    }
    ifstream in(argv[1]);
    if (!in){
        cerr << "Unable to open " << argv[1] << endl;
        return 2;
    }

    // store input as string
    stringstream stringStream;
    stringStream << in.rdbuf();
    string userInput = stringStream.str();

    // pass input through lexer, get vector of tokens
    Lexer* lexer = new Lexer();
    lexer->Run(userInput);
    vector<Token*> tokens = lexer->GetTokens();

    // lexer->PrintTokens();

    // parse tokens, print results
    Parser* parser = new Parser(tokens);
    Token* parseResult = parser->Parse();
    if (parseResult != nullptr) {
        cerr << "Failure!" << endl;
        cerr << "  " << parseResult->ToString() << endl;
        return 3;
    }
    cout << "Success!" << endl;
    cout << parser->GetDatalogProgram()->ToString();

    cout << "INTERPRETER OUTPUT: --------------" << endl;

    Interpreter interpreter(parser->GetDatalogProgram());


    // clean up memory
    delete lexer;
    delete parser;

    return 0;
}