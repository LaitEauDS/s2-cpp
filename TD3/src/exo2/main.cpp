#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stack>
#include <cctype>

using namespace std;

bool is_floating(const string& s) {
    bool dot = false;
    for (char c : s) {
        if (!isdigit(c)) {
            if (c == '.') {
                if (dot)
                    return false;
                dot = true;
            } 
            else {
                return false;
            }
        }
    }
    return true;
}

enum class Operator { ADD, SUB, MUL, DIV, OPEN_PAREN, CLOSE_PAREN };

enum class TokenType { OPERATOR, OPERAND };

struct Token {
    TokenType type;
    float value;
    Operator op;
};

Token make_token(float value) {
    return Token{TokenType::OPERAND, value, Operator::ADD};
}

Token make_token(Operator op) {
    return Token{TokenType::OPERATOR, 0.0f, op};
}


std::vector<Token> tokenize(const vector<string>& words) {
    vector<Token> tokens;
    for (const string& word : words) {
        
        if (is_floating(word)) {
            tokens.push_back(make_token(stof(word)));
        } 
        else {
            Operator op;
            
            if (word == "+") {
                op = Operator::ADD;
            } 
            else if (word == "-") {
                op = Operator::SUB;
            } 
            else if (word == "*") {
                op = Operator::MUL;
            } 
            else if (word == "/") {
                op = Operator::DIV;
            } 
            else if (word == "(") {
                op = Operator::OPEN_PAREN;
            } 
            else if (word == ")") {
                op = Operator::CLOSE_PAREN;
            }
            tokens.push_back(make_token(op));
        }
    }
    return tokens;
}


float npi_evaluate(const vector<Token>& tokens) {
    stack<float> operands;

    for (const Token& token : tokens) {
        if (token.type == TokenType::OPERAND) {
            operands.push(token.value);
        }
            float operand2 = operands.top();
            operands.pop();
            float operand1 = operands.top();
            operands.pop();

            if (token.op == Operator::ADD) {
                operands.push(operand1 + operand2);
            } 
            else if (token.op == Operator::SUB) {
                operands.push(operand1 - operand2);
            } 
            else if (token.op == Operator::MUL) {
                operands.push(operand1 * operand2);
            } 
            else if (token.op == Operator::DIV) {
                operands.push(operand1 / operand2);
            }
        }

    if (operands.size() != 1) {
        cerr << "Expression invalide." << endl;
        return 1;
    }

    return operands.top();
}

int main() {
    string expression;
    cout << "Saisir une expression arithmétique en NPI";
    getline(cin, expression);

    istringstream iss(expression);
    vector<string> words{istream_iterator<string>{iss}, istream_iterator<string>{}};

    vector<Token> tokens = tokenize(words);
    if (!tokens.empty()) {
        float result = npi_evaluate(tokens);
        if (!isnan(result)) {
            cout << "Résultat: " << result << endl;
        }
    }

    return 0;
}