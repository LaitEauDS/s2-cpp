#include <stack>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>

using namespace std;

std::vector<std::string> split_string(std::string const& s)
{
    std::istringstream in(s); // transforme une chaîne en flux de caractères, cela simule un flux comme l'est std::cin
    // l’itérateur va lire chaque element de "in", comme un flux d'entrée, chaque élément est séparé par un espace
    return std::vector<std::string>(std::istream_iterator<std::string>(in), std::istream_iterator<std::string>()); 
}

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


float npi_evaluate(const std::vector<std::string>& tokens){

    std::stack<float> operands;
    string token;

    for (const string& token : tokens) {
        if (is_floating(token)) {
            operands.push(stof(token));
        } 
        else {
            if (operands.size() < 2) {
                cerr << "Expression invalide." << endl;
                return 1; 
            }

            float operand2 = operands.top();
            operands.pop();
            float operand1 = operands.top();
            operands.pop();

            if (token == "+") {
                operands.push(operand1 + operand2);
            } 
            else if (token == "-") {
                operands.push(operand1 - operand2);
            } 
            else if (token == "*") {
                operands.push(operand1 * operand2);
            } 
            else if (token == "/") {
                operands.push(operand1 / operand2);
            }
        }
    }

    if (operands.size() != 1) {
        cerr << "Expression invalide." << endl;
        return 1;
    }

    return operands.top();
}


int main() {
    std::string expression;
    std::cout << "Saisir une expression arithmétique en NPI";
    std::getline(std::cin, expression);

     std::vector<std::string> tokens = split_string(expression);
    float result = npi_evaluate(tokens);

    if (!isnan(result)) {
        cout << "Le résultat de l'expression est : " << result << endl;
    }

    return 0;
}