// write a simple C++ program to find left-factored grammar and remove it.

#include <bits/stdc++.h>
using namespace std;

using Production = vector<string>;
using Grammar = unordered_map<char, Production>;

void leftFactor(Grammar& grammar) {
    for (auto& [nonTerminal, productions] : grammar) {
        sort(productions.begin(), productions.end());

        for (int i = 0; i < productions.size() - 1; ++i) {
            int commonPrefixLength = 0;
            while (productions[i][commonPrefixLength] == productions[i + 1][commonPrefixLength]) {
                commonPrefixLength++;
            }

            if (commonPrefixLength > 0) {
                char newNonTerminal = nonTerminal + 1;
                grammar[newNonTerminal].emplace_back(productions[i].substr(0, commonPrefixLength));
                productions[i] = productions[i].substr(commonPrefixLength);
                productions[i + 1] = productions[i + 1].substr(commonPrefixLength);
                productions[i].insert(0, 1, newNonTerminal);
                productions[i + 1].insert(0, 1, newNonTerminal);
            }
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
        {'S', {"abc", "acd", "ade"}},
        {'A', {"ab", "ac"}},
        {'B', {"bcd", "bce"}},
    };

    cout << "Original Grammar:\n";
    printGrammar(grammar);

    leftFactor(grammar);

    cout << "\nGrammar after Left Factoring:\n";
    printGrammar(grammar);

    return 0;
}
