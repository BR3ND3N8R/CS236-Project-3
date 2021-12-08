cmake_minimum_required(VERSION 3.16.3)
project(Project_1)

set(CMAKE_CXX_STANDARD 14)

add_executable(Project_1 main.cpp Lexer.h Lexer.cpp Automaton.h ColonAutomaton.h ColonAutomaton.cpp ColonDashAutomaton.h ColonDashAutomaton.cpp Token.h Token.cpp CommaAutomaton.cpp CommaAutomaton.h PeriodAutomaton.cpp PeriodAutomaton.h Q_MarkAutomaton.cpp Q_MarkAutomaton.h Left_ParenAutomaton.cpp Left_ParenAutomaton.h Right_ParenAutomaton.cpp Right_ParenAutomaton.h MultiplyAutomaton.cpp MultiplyAutomaton.h AddAutomaton.cpp AddAutomaton.h SchemesAutomaton.cpp SchemesAutomaton.h FactsAutomaton.cpp FactsAutomaton.h RulesAutomaton.cpp RulesAutomaton.h QueriesAutomaton.cpp QueriesAutomaton.h IDAutomaton.cpp IDAutomaton.h StringAutomaton.cpp StringAutomaton.h CommentAutomaton.cpp CommentAutomaton.h UndefinedAutomaton.cpp UndefinedAutomaton.h DatalogProgram.cpp DatalogProgram.h Rule.cpp Rule.h Predicate.cpp Predicate.h Parameter.cpp Parameter.h Parser.cpp Parser.h Database.cpp Database.h Relation.cpp Relation.h Header.cpp Header.h Tuple.cpp Tuple.h Interpreter.cpp Interpreter.h)
