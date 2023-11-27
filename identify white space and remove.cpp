// write a simple C++ program to identify white space and remove it.

#include <bits/stdc++.h>
using namespace std;

std::string removeWhitespace(const std::string& input) {
    std::string result;

    for (char ch : input) {
        if (!std::isspace(ch)) {
            result += ch;
        }
    }

    return result;
}

int main() {
    // Example string with whitespace
    std::string input = "  This is a simple   C++  program  with spaces.  ";

    // Remove whitespace
    std::string result = removeWhitespace(input);

    // Display the result
    std::cout << "Original string: " << input << std::endl;
    std::cout << "String without whitespace: " << result << std::endl;

    return 0;
}
