#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <cmath>

using namespace std;

class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int ans = 0;
        for (auto &p1: points) {
            map<double, int> dis_map;
            for (auto &p2: points) {
                ans += 2 * dis_map[hypot(p1.first - p2.first, p1.second - p2.second)]++;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<pair<int, int>> points = {{0, 0}, {1, 0}, {2, 0}};
    cout << s.numberOfBoomerangs(points);
    return 0;
}
