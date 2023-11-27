// write a cpp program to identify all the tokens from a given block of code 

#include <bits/stdc++.h>
using namespace std;

// Function to identify tokens in a given block of code
 vector< string> identifyTokens(const  string& code) {
     vector< string> tokens;
     istringstream iss(code);
     string token;

    // Split the code based on spaces and add tokens to the vector
    while (iss >> token) {
        tokens.push_back(token);
    }

    return tokens;
}

int main() {
    // Example block of code
     string code = "int main() { cout << \"Hello, World!\"; return 0; }";

    // Identify tokens
     vector< string> tokens = identifyTokens(code);

    // Display tokens
     cout << "Tokens: ";
    for (const auto& token : tokens) {
         cout << token << " ";
    }
     cout <<  endl;

    return 0;
}
