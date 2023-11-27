// write a simple C++ program to find the first of a grammar.

#include <bits/stdc++.h>
using namespace std;

using Production = vector<string>;
using Grammar = unordered_map<char, Production>;
using FirstSet = unordered_map<char, unordered_set<char>>;

void calculateFirst(const Grammar& grammar, FirstSet& first, char nonTerminal) {
    for (const auto& prod : grammar.at(nonTerminal)) {
        char firstSymbol = prod[0];

        if (isupper(firstSymbol)) {
            calculateFirst(grammar, first, firstSymbol);
            first[nonTerminal].insert(first[firstSymbol].begin(), first[firstSymbol].end());

            size_t i = 1;
            while (i < prod.size() && first[firstSymbol].count('e') > 0) {
                first[nonTerminal].insert(first[firstSymbol].begin(), first[firstSymbol].end());
                if (first[firstSymbol].count(prod[i]) == 0) {
                    break;
                }
                ++i;
            }
        } else {
            first[nonTerminal].insert(firstSymbol);
        }
    }
}

void calculateFirst(const Grammar& grammar, FirstSet& first) {
    for (const auto& [nonTerminal, _] : grammar) {
        calculateFirst(grammar, first, nonTerminal);
    }
}

void printFirstSet(const FirstSet& first) {
    for (const auto& [nonTerminal, firstSet] : first) {
        cout << "First(" << nonTerminal << ") = { ";
        for (char terminal : firstSet) {
            cout << terminal << " ";
        }
        cout << "}\n";
    }
}

int main() {
    // Example grammar
    Grammar grammar = {
        {'S', {"AB", "BC"}},
        {'A', {"a", "e"}},
        {'B', {"b", "e"}},
        {'C', {"c"}},
    };

    FirstSet first;
    calculateFirst(grammar, first);

    cout << "First Sets:\n";
    printFirstSet(first);

    return 0;
}
