//
// Created by ZachZhang on 2017/4/23.
//

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        istringstream in(s);
        ostringstream out;
        string word;

        while (in >> word) {
            for (int i = word.size() - 1; i >= 0; i--)
                out << word[i];
            out << ' ';
        }
        string ret = out.str();
        return ret.substr(0, ret.size() - 1);
    }

    string reverseWords2(string s) {
        for (int i=0; i<s.length(); i++) {
            if (s[i] != ' ') {
                int j;
                for (j=i; j <s.length() && s[j] != ' '; j++) {}
                reverse(s.begin() + i, s.begin() + j);
                i = j;
            }
        }
        return s;
    }
};

int main(void) {
    Solution s;
    cout << s.reverseWords2("Let's take LeetCode contest");
}