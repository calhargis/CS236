#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "Lexer.h"
#include "Tokenizer.h"
#include "Token.h"
#include "Parser.h"
#include "Interpreter.h"


using namespace std;

int main(int argc, const char * argv[]) {

    string input;    

    ifstream in(argv[1]);
    while (in.peek() != EOF) {
        input += (char)in.get();
    }

    Lexer lexer(input);
    Tokenizer tokenizer(input);
    int lineNum = 1;

    for (size_t i = 0; i < input.size(); i++) {
        if (input[i] == '\n') {
            ++lineNum;
        }
        if (isspace(input[i])) {
            continue;
        }
        Token newToken = tokenizer.tokenCreator(i);
        newToken.setTokenLine(lineNum);
        lexer.addToken(newToken);
        if (newToken.getTokenVal().size() > 1) {
            i += newToken.getTokenVal().size() - 1;
        }
        if (newToken.getTokenVal().find('\n')) {
            std::string tokenVal = newToken.getTokenVal();
            lineNum += std::count(tokenVal.begin(), tokenVal.end(), '\n');
        }
    }
    Token endfile(ENDFILE, "", lineNum);
    lexer.addToken(endfile);

    Parser parser(lexer.getTokenVector());

    parser.parse();

    Interpreter interpreter(parser.returnDatalogProgram());

    interpreter.run();

    return 0;
}