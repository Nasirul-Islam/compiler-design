// write a C++ program to test whether the given identifier is valid or not.

#include <bits/stdc++.h>
using namespace std;

bool isValidIdentifier(const  string& identifier) {
    // Check if the identifier is not empty
    if (identifier.empty()) {
        return false;
    }

    // Check if the first character is a letter or underscore
    if (! isalpha(identifier[0]) && identifier[0] != '_') {
        return false;
    }

    // Check the remaining characters
    for (char ch : identifier) {
        if (! isalnum(ch) && ch != '_') {
            return false;
        }
    }

    // If all checks pass, the identifier is valid
    return true;
}

int main() {
    // Example identifiers
     string identifier1 = "validIdentifier";
     string identifier2 = "_underscored";
     string identifier3 = "3invalid";
     string identifier4 = "";

    // Test identifiers
     cout << "Is \"" << identifier1 << "\" a valid identifier? " <<  boolalpha << isValidIdentifier(identifier1) <<  endl;
     cout << "Is \"" << identifier2 << "\" a valid identifier? " <<  boolalpha << isValidIdentifier(identifier2) <<  endl;
     cout << "Is \"" << identifier3 << "\" a valid identifier? " <<  boolalpha << isValidIdentifier(identifier3) <<  endl;
     cout << "Is \"" << identifier4 << "\" a valid identifier? " <<  boolalpha << isValidIdentifier(identifier4) <<  endl;

    return 0;
}

