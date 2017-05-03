//
// Created by ZachZhang on 2017/5/3.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        trim(s);
        auto pos = s.find_last_of(' ');
        if (pos == string::npos)
            return s.size();
        else
            return s.size() -  1 - pos;
    }

    int lengthOfLastWord2(string s) {
        int pos1 = s.size() - 1;
        while (pos1 >= 0 && s[pos1] == ' ')
            pos1 -= 1;
        int pos2 = pos1;
        while (pos2 >= 0 && s[pos2] != ' ')
            pos2 -= 1;
        return pos1 - pos2;
    }

private:
    void trim(string &s) {
        if (s.empty())
            return;
        s.erase(0, s.find_first_not_of(' '));
        s.erase(s.find_last_not_of(' ')+1);
    }
};

int main(void) {
    Solution s;
    cout << s.lengthOfLastWord2("a ") << endl;
    cout << s.lengthOfLastWord2(" a") << endl;
    cout << s.lengthOfLastWord2("Hello World") << endl;
    cout << s.lengthOfLastWord2("hello") << endl;
}
