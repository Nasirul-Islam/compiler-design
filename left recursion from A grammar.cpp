// write a program to find the left recursion from A grammar and remove it.

#include <bits/stdc++.h>
using namespace std;

using Production = vector<string>;
using Grammar = unordered_map<char, Production>;

bool isNonTerminal(char symbol) {
    return isupper(symbol);
}

void removeLeftRecursion(Grammar& grammar) {
    for (auto& [nonTerminal, productions] : grammar) {
        Production newProductions;
        Production leftRecursiveProductions;

        for (const auto& prod : productions) {
            if (prod[0] == nonTerminal) {
                leftRecursiveProductions.push_back(prod.substr(1));
            } else {
                newProductions.push_back(prod);
            }
        }

        if (!leftRecursiveProductions.empty()) {
            char newNonTerminal = nonTerminal + 1;
            grammar[newNonTerminal] = leftRecursiveProductions;

            productions.clear();
            for (const auto& prod : newProductions) {
                productions.push_back(prod + newNonTerminal);
            }

            productions.push_back(""); // Epsilon production
        }
    }
}

void printGrammar(const Grammar& grammar) {
    for (const auto& [nonTerminal, productions] : grammar) {
        cout << nonTerminal << " -> ";
        for (const auto& prod : productions) {
            cout << prod << " | ";
        }
        cout << endl;
    }
}

int main() {
    // Example grammar
    Grammar grammar = {
        {'A', {"Aa", "Ab", "Ac", "a"}},
        {'B', {"Bb", "Bc", "b"}},
    };

    cout << "Original Grammar:\n";
    printGrammar(grammar);

    removeLeftRecursion(grammar);

    cout << "\nGrammar after Removing Left Recursion:\n";
    printGrammar(grammar);

    return 0;
}
