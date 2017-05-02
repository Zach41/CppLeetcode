//
// Created by ZachZhang on 2017/5/2.
//

#include <iostream>
#include <cctype>

using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {
        if (word.size() <= 1)
            return true;
        bool status = islower(word[0]) ? 0 : 1;
        if (status) {
            status = islower(word[1]) ? 0 : 1;
            if (status) {
                for (int i=2; i < word.size(); i++)
                    if (islower(word[i]))
                        return false;
            } else {
                for (int i=2; i < word.size(); i++)
                    if (isupper(word[i]))
                        return false;
            }
        } else {
            for (int i=1; i < word.size(); i++)
                if (isupper(word[i]))
                    return false;
        }
        return true;
    }

    bool detectCapitalUse2(string word) {
        int cnt = 0;
        for (auto c : word)
            if (isupper(c))
                cnt += 1;
        return (cnt == 0 || cnt == word.size() || (cnt == 1 && isupper(word[0])));
    }
};

int main(void) {
    Solution s;
    cout << s.detectCapitalUse2("USA") << endl;
    cout << s.detectCapitalUse2("FlaG") << endl;
}


