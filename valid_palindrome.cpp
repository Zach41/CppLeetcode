//
// Created by ZachZhang on 2017/4/23.
//

#include <iostream>
#include <cctype>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        for (int i=0, j = s.size() - 1; i<j; i++, j--) {
            while (!isalnum(s[i]) && i < j) i++;
            while (!isalnum(s[j]) && i < j) j--;
            if (tolower(s[i]) != tolower(s[j]))
                return false;
        }
        return true;
    }
};

int main(void) {
    Solution s;
    cout << s.isPalindrome("race a car") << endl;
    cout << s.isPalindrome("A man, a plan, a canal: Panama") << endl;

}

