// write a program to remove a comment

#include <bits/stdc++.h>
using namespace std;

 string removeComments(const  string& code) {
     string result;
    bool inSingleLineComment = false;
    bool inMultiLineComment = false;

    for ( size_t i = 0; i < code.size(); ++i) {
        // Check for the start of a single-line comment
        if (!inMultiLineComment && i < code.size() - 1 && code[i] == '/' && code[i + 1] == '/') {
            inSingleLineComment = true;
            continue;
        }

        // Check for the end of a single-line comment
        if (inSingleLineComment && code[i] == '\n') {
            inSingleLineComment = false;
            continue;
        }

        // Check for the start of a multi-line comment
        if (!inSingleLineComment && i < code.size() - 1 && code[i] == '/' && code[i + 1] == '*') {
            inMultiLineComment = true;
            ++i;
            continue;
        }

        // Check for the end of a multi-line comment
        if (inMultiLineComment && i < code.size() - 1 && code[i] == '*' && code[i + 1] == '/') {
            inMultiLineComment = false;
            ++i;
            continue;
        }

        // Add the character to the result if not in a comment block
        if (!inSingleLineComment && !inMultiLineComment) {
            result += code[i];
        }
    }

    return result;
}

int main() {
    // Example code with comments
     string code = R"(
        // This is a single-line comment
        int main() {
            /* This is a
               multi-line
               comment */
             cout << "Hello, World!"; // Another single-line comment
            return 0;
        }
    )";

    // Remove comments
     string result = removeComments(code);

    // Display code without comments
     cout << "Code without comments:\n" << result <<  endl;

    return 0;
}
