// write a program to identify whether a given line is a comment or not.

#include <bits/stdc++.h>
using namespace std;

bool isSingleLineComment(const   string& line) {
    // Check if the line starts with "//"
    return line.find("//") == 0;
}

bool isMultiLineCommentStart(const   string& line) {
    // Check if the line starts with "/*"
    return line.find("/*") == 0;
}

bool isMultiLineCommentEnd(const   string& line) {
    // Check if the line ends with "*/"
    return line.find("*/") !=   string::npos;
}

bool isComment(const   string& line) {
    return isSingleLineComment(line) || isMultiLineCommentStart(line);
}

int main() {
    // Example lines
      string line1 = "// This is a single-line comment";
      string line2 = "/* This is the start of a multi-line comment";
      string line3 = "This is not a comment";
      string line4 = "*/ This is the end of a multi-line comment";

    // Check if each line is a comment
      cout << "Line 1 is a comment: " <<   boolalpha << isComment(line1) <<   endl;
      cout << "Line 2 is a comment: " <<   boolalpha << isComment(line2) <<   endl;
      cout << "Line 3 is a comment: " <<   boolalpha << isComment(line3) <<   endl;
      cout << "Line 4 is a comment: " <<   boolalpha << isComment(line4) <<   endl;

    return 0;
}
