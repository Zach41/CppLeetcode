//
// Created by ZachZhang on 2017/4/24.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        sort(strs.begin(), strs.end(), [](string a, string b) {
            return a.size() > b.size();
        });
        for (int i=0; i < strs.size(); i++) {
            bool checked = true;
            for (int j = 0; j < strs.size(); j++) {
                if (i == j) continue;
                if (subseq(strs[i], strs[j])) {
                    checked = false;
                    break;
                }
            }
            if (checked)
                return strs[i].size();
        }
        return -1;
    }

    bool subseq(string word1, string word2) {
        int i = 0;
        for (char c: word2) {
            if (i < word1.size() && word1[i] == c)
                i += 1;
        }
        return i == word1.size();
    }
};

int main(void) {
    Solution s;
    vector<string> svec = {"aabbcc", "aabbcc", "cb"};
    cout << s.findLUSlength(svec) << endl;
    svec = {"aba", "cdc", "eae"};
    cout << s.findLUSlength(svec) << endl;
    svec = {"aaa", "aaa","a"};
    cout << s.findLUSlength(svec) << endl;

}