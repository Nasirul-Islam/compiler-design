// write a C++ program to simulate a lexical analyzer for validating operators.

#include <bits/stdc++.h>
using namespace std;


int main() {
    // Example input with operators
     string input = "+ - * / % = == != < <= > >=";

    // Process each character in the input
    for (char ch : input) {
        switch (ch) {
            case '+':
                 cout << "Operator: + (Plus)\n";
                break;
            case '-':
                 cout << "Operator: - (Minus)\n";
                break;
            case '*':
                 cout << "Operator: * (Multiply)\n";
                break;
            case '/':
                 cout << "Operator: / (Divide)\n";
                break;
            case '%':
                 cout << "Operator: % (Modulo)\n";
                break;
            case '=':
                 cout << "Operator: = (Assign)\n";
                break;
            case '!':
                 cout << "Operator: ! (Not)\n";
                break;
            case '<':
                 cout << "Operator: < (Less Than)\n";
                break;
            case '>':
                 cout << "Operator: > (Greater Than)\n";
                break;
            default:
                // Check for two-character operators
                if (ch == '=' && !input.empty() && input.front() == '=')
                     cout << "Operator: == (Equal)\n";
                else if (ch == '!' && !input.empty() && input.front() == '=')
                     cout << "Operator: != (Not Equal)\n";
                else if (ch == '<' && !input.empty() && input.front() == '=')
                     cout << "Operator: <= (Less Equal)\n";
                else if (ch == '>' && !input.empty() && input.front() == '=')
                     cout << "Operator: >= (Greater Equal)\n";
                break;
        }
    }

    return 0;
}
