// write a simple C++ program to find the following set of grammar.

#include <bits/stdc++.h>
using namespace std;

using namespace std;

using Production = vector<string>;
using Grammar = unordered_map<char, Production>;
using FollowSet = unordered_map<char, unordered_set<char>>;

bool isNonTerminal(char symbol) {
    return isupper(symbol);
}

void calculateFollow(const Grammar& grammar, FollowSet& follow, char nonTerminal) {
    for (const auto& [lhs, productions] : grammar) {
        for (const auto& prod : productions) {
            size_t pos = prod.find(nonTerminal);
            while (pos != string::npos) {
                if (pos + 1 < prod.size()) {
                    char nextSymbol = prod[pos + 1];
                    if (isNonTerminal(nextSymbol)) {
                        follow[nonTerminal].insert(nextSymbol);

                        // Add First set of nextSymbol (excluding epsilon) to Follow set
                        if (grammar.count(nextSymbol) > 0) {
                            const auto& firstOfNextSymbol = grammar.at(nextSymbol);
                            follow[nonTerminal].insert(firstOfNextSymbol.front().begin(), firstOfNextSymbol.front().end());
                            follow[nonTerminal].erase('e');
                        }
                    } else {
                        follow[nonTerminal].insert(nextSymbol);
                    }
                }

                pos = prod.find(nonTerminal, pos + 1);
            }
        }
    }
}

void calculateFollow(const Grammar& grammar, FollowSet& follow) {
    for (const auto& [nonTerminal, _] : grammar) {
        calculateFollow(grammar, follow, nonTerminal);
    }
}

void printFollowSet(const FollowSet& follow) {
    for (const auto& [nonTerminal, followSet] : follow) {
        cout << "Follow(" << nonTerminal << ") = { ";
        for (char terminal : followSet) {
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

    FollowSet follow;
    calculateFollow(grammar, follow);

    cout << "Follow Sets:\n";
    printFollowSet(follow);

    return 0;
}
