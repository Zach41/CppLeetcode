//
// Created by ZachZhang on 2017/4/25.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        for (int i = n / 2; i >= 1; i--) {
            if (n % i == 0) {
                int cnt = n / i;
                string tmp = "";
                string sub = s.substr(0, i);
                for (int j = 0; j < cnt; j++)
                    tmp += sub;
                if (tmp == s)
                    return true;
            }
        }
        return false;
    }
};

int main(void) {
    Solution s;
    cout << s.repeatedSubstringPattern("abab");
    cout << s.repeatedSubstringPattern("aba");
    cout << s.repeatedSubstringPattern("abcabcabcabc");
    cout << s.repeatedSubstringPattern("bb");
}