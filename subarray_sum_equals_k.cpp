#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int> sum_map;
        sum_map[0] = 1;
        int cur = 0, ans = 0;

        for (auto v: nums) {
            cur += v;
            if (sum_map.find(cur - k) != sum_map.end()) {
                ans += sum_map[cur-k];
            }
            sum_map[cur]++;
        }
        return ans;
    }
};

int main(void) {
    Solution s;
    vector<int> nums = {1, 1, 1};
    cout << s.subarraySum(nums, 2) << '\n';
    return 0;
}