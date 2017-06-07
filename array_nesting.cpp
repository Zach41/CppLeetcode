#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int ans = 0;
        vector<bool> visited(nums.size(), false);
        for (size_t i = 0; i < nums.size(); i++) {
            if (visited[nums[i]]) continue;
            visited[nums[i]] = true;
            ans = max(ans, set_size(nums[i], i, nums, 1, visited));
        }
        return ans;
    }
private:
    int set_size(int cur, int start, vector<int>& nums, int size, vector<bool>& visited) {
        if (cur == start)
            return size;
        visited[nums[cur]] = true;
        return set_size(nums[cur], start, nums, size+1, visited);
    }
};

int main(void) {
    Solution s;
    vector<int> nums = {5, 4, 0, 3, 1, 6, 2};
    cout << s.arrayNesting(nums) << '\n';

    return 0;
}