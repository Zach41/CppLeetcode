#include <iostream>
#include <vector>
#include <map>
#include  <algorithm>

using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int, int> m;
        for (int v: nums) {
            if (m.find(v) != m.end())
                m[v] += 1;
            else
                m[v] = 1;
        }

        int ans = 0;
        for (auto &item: m) {
            int tmp = item.second;
            if (m.find(item.first - 1) != m.end())
                ans = max(ans, tmp + m[item.first - 1]);
            if (m.find(item.first + 1) != m.end())
                ans = max(ans, m[item.first + 1] + tmp);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> nums = {1, 3, 2, 2, 5, 2, 3, 7};
    std::cout << s.findLHS(nums) << std::endl;
    vector<int> nums2 = {1, 1, 1, 1};
    std::cout << s.findLHS(nums2) << std::endl;
    return 0;
}
