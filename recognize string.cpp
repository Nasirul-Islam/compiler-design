// write a simple C++ program to recognize string under 'a', 'abb', etc.

#include <bits/stdc++.h>
using namespace std;

bool isValidString(const  string& input) {
    size_t count = 0;

    for (char ch : input) {
        if (ch == 'a') {
            count++;
        } else if (ch == 'b' && count > 0) {
            count--;
        } else {
            return false;
        }
    }

    return count == 0;
}

int main() {
    // Example strings
     string str1 = "a";
     string str2 = "abb";
     string str3 = "abbb";
     string str4 = "aabb";
     string str5 = "abc";

    // Test strings
     cout << "Is \"" << str1 << "\" a valid string? " <<  boolalpha << isValidString(str1) <<  endl;
     cout << "Is \"" << str2 << "\" a valid string? " <<  boolalpha << isValidString(str2) <<  endl;
     cout << "Is \"" << str3 << "\" a valid string? " <<  boolalpha << isValidString(str3) <<  endl;
     cout << "Is \"" << str4 << "\" a valid string? " <<  boolalpha << isValidString(str4) <<  endl;
     cout << "Is \"" << str5 << "\" a valid string? " <<  boolalpha << isValidString(str5) <<  endl;

    return 0;
}

