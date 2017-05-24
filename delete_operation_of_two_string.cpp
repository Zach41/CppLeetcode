#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        if (word2.size() < word1.size())
            swap(word1, word2);
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        for (int i=1; i<=m; i++) {
            for (int j = 1; j <=n; j++) {
                int tmp = word1[i-1] == word2[j - 1] ? 1 : 0;
                dp[i][j] = max({dp[i-1][j], dp[i][j-1], dp[i-1][j-1] + tmp});
            }
        }
        return word1.size() + word2.size() - 2*dp[m][n];
    }
};

int main(void) {
    Solution s;
    std::cout << s.minDistance("sea", "eat") << '\n';
}
