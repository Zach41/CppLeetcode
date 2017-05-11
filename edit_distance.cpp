//
// Created by ZachZhang on 2017/5/11.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        size_t m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for (int i=0; i<m+1; i++)
            dp[i][0] = i;
        for (int i=0; i<n+1; i++)
            dp[0][i] = i;

        for (int i=1; i<m+1; i++)
            for (int j=1; j<n+1; j++) {
                int tmp = word1[i-1] == word2[j-1] ? 0 : 1;
                dp[i][j] = min({dp[i-1][j]+1, dp[i][j-1] + 1, dp[i-1][j-1] + tmp});
            }
        return dp[m][n];
    }
};

int main(void) {
    Solution s;
    cout << s.minDistance("kitten", "sitting") << "\n";
}

