//
// Created by ZachZhang on 2017/5/6.
//

#include <iostream>

using namespace std;

class Solution {
public:
    bool checkRecord(string s) {
        int l_cnt = 0, a_cnt = 0;
        for (auto c: s) {
            if (c == 'L') l_cnt += 1;
            else {
                if (l_cnt > 2)
                    return false;
                l_cnt = 0;
                if (c == 'A') a_cnt += 1;
            }
        }

        return !(l_cnt > 2 || a_cnt > 1);
    }
};

int main(void) {
    Solution s;
    cout << s.checkRecord("PPALLP") << endl;
    cout << s.checkRecord("PPALLL") << endl;
    cout << s.checkRecord("LALL") << endl;
}

