//
// Created by ZachZhang on 2017/5/12.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
        return isScramble2(s1, s2);
    }
private:
    bool isScramble1(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        if (s1 == s2) return true;
        string str1 = s1, str2 = s2;
        sort(str1.begin(), str1.end());
        sort(str2.begin(), str2.end());
        if (str1 != str2) return false;

        for (size_t i = 1; i < s1.size(); i++) {
            string str11 = s1.substr(0, i);
            string str12 = s1.substr(i);
            string str21 = s2.substr(0, i);
            string str22 = s2.substr(i);
            if (isScramble1(str11, str21) && isScramble1(str12, str22))
                return true;
            str21 = s2.substr(0, s2.size() - i);
            str22 = s2.substr(s2.size() - i);
            if (isScramble1(str11, str22) && isScramble1(str12, str21))
                return true;
        }
        return false;
    }

    bool isScramble2(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        if (s1 == s2) return true;
        int n = s1.size();
        vector<vector<vector<bool>>> dp(n, vector<vector<bool>>(n, vector<bool>(n+1, false)));

        for (int i=0; i < n; i++)
            for (int j = 0; j < n; j++)
                dp[i][j][1] = (s1[i] == s2[j]);
        for (int len = 2; len <= n; len++) {
            for (int i=0; i<=s1.size()-len;i++){
                for (int j = 0; j <= s2.size() - len; j++) {
                    for (int k = 1; k < len; k++) {
                        dp[i][j][len] = dp[i][j][len] ||
                                (dp[i][j][k] && dp[i+k][j+k][len-k]) ||
                                (dp[i][j + len - k][k] && dp[i+k][j][len-k]);
                    }
                }
            }
        }
        return dp[0][0][n];
    }
};

int main(void) {
    Solution s;
    cout << s.isScramble("rgeat", "great") << '\n';
    cout << s.isScramble("rgtae", "great") << '\n';
}

