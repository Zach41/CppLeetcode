//
// Created by ZachZhang on 2017/5/1.
//

#include <iostream>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int ch_cnt[26] = {0};

        for (auto ch : magazine) {
            ch_cnt[ch - 'a'] += 1;
        }

        for (auto ch : ransomNote) {
            if (ch_cnt[ch - 'a'] <= 0)
                return false;
            else
                ch_cnt[ch - 'a'] -= 1;
        }
        return true;
    }
};

int main(void) {
    Solution s;
    cout << s.canConstruct("a", "b") << endl;
    cout << s.canConstruct("aa", "ab") << endl;
    cout << s.canConstruct("aa", "aab") << endl;
}
