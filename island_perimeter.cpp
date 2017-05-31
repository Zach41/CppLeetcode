#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        for (int i=0; i<m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    ans += 4;
                    if (i > 0 && grid[i-1][j] == 1)
                        ans -= 2;
                    if (j > 0 && grid[i][j-1] == 1)
                        ans -= 2;
                }                    
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<int>> grid = {{0, 1, 0, 0}, 
                                {1, 1, 1, 0},
                                {0, 1, 0, 0},
                                {1, 1, 0, 0}};
    cout << s.islandPerimeter(grid) << '\n';
}