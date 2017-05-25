#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int length = 0;
        for (auto &vec: wall) {
            for (size_t idx = 1; idx < vec.size(); idx++) {
                vec[idx] += vec[idx-1];
            }
            if (length == 0)
                length = vec[vec.size() - 1];
        }
        
        map<int, int> rec;
        for (auto &vec: wall) {
            for (int v: vec) {
                rec[v] += 1;
            }
        }
        
        int ans = wall.size();
        for (auto &item: rec) {
            if (item.first == length) continue;
            ans = min(ans, (int)(wall.size() - item.second));
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<int>> walls = {{1, 2, 2, 1},
                                 {3, 1, 2},
                                 {1, 3, 2},
                                 {2, 4},
                                 {3, 1, 2},
                                 {1, 3, 1, 1}};
    vector<vector<int>> wall2 = {{1}, {1}, {1}};
    std::cout << s.leastBricks(walls) << std::endl;
    std::cout << s.leastBricks(wall2) << std::endl;
    return 0;
}
