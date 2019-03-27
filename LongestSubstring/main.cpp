//
//  main.cpp
//  LongestSubstring
//
//  Created by Moe Abdelaaty on 2019-03-27.
//  Copyright © 2019 Moe Abdelaaty. All rights reserved.
//

// including the required libraries
#include <iostream>     // iostream for terminal IO
#include <cstring>      // cstring for handling strings, can also use <string>
#include <vector>       // Vector, just in case - not needed

using namespace std;

string longestSubstring(string&, string&); // Function prototype

// Program execution
int main(int argc, const char * argv[]) {
    string stringOne = "ABXBA";     // input strings, can be from console but not necessary
    string stringTwo = "ABAB";      // input strings, can be from console but not necessary
    
    string sub = longestSubstring(stringTwo, stringOne);    // Execute function
    
    cout << sub << endl;            // printing the output of the function
    
    return 0;
}

string longestSubstring(string& str1, string& str2) {
    string substring; // storing the longest substring
    
    // clean out the strings, removing the uncommon characters
    for ( int i = str1.size() - 1; i >= 0; i-- ) {
        if (str2.find(str1.at(i)) == string::npos) {
            str1.erase(str1.begin() + i);
        }
    }
    
    for ( int i = str2.size() - 1; i >= 0; i-- ) {
        if (str1.find(str2.at(i)) == string::npos) {
            str2.erase(str2.begin() + i);
        }
    }
    
    // just a boolean value to identify which string is larger
    bool largestString;
    
    if (str1.size() > str2.size()) {
        largestString = true;
    } else {
        largestString = false;
    }
    
    // loop through shorter string and look for the characters in the longer string, ensuring that the index is creater than or equal to the index in the smaller string
    if (largestString)
        for (int i = 0; i < str2.size(); i++) {
            if (str1.find(str2.at(i), i) != string::npos) {
                // add the character to the substring
                substring.push_back(str2.at(i));
            }
        }
    else
        for (int i = 0; i < str1.size(); i++) {
            if (str2.find(str1.at(i), i) != string::npos) {
                substring.push_back(str1.at(i));
            }
        }
    // return the substring
    return substring;
}
