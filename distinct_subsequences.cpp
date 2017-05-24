#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int m = t.size(), n = s.size();
        if (m > n) return 0;
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for (int i=0; i<=n; i++) {
            dp[0][i] = 1;
        }

        for (int i=1; i<=m; i++) {
            for (int j=i; j<=n; j++) {
                if (t[i-1] != s[j-1]) {
                    dp[i][j] = dp[i][j-1];
                } else {
                    dp[i][j] = dp[i][j-1] + dp[i-1][j-1];
                }
            }
        }
        return dp[m][n];
    }
};


int main(int argc, char const *argv[])
{
    Solution s;
    std::cout << s.numDistinct("rabbbit", "rabbit") << '\n';
    return 0;
}
