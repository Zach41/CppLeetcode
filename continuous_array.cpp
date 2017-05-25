#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        map<int, int> rec;
        rec[0] = -1;
        int zeros = 0, ones = 0;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i])
                ones++;
            else
                zeros++;
            if (rec.find(zeros - ones) != rec.end())
                ans = max(ans, i - rec[zeros - ones]);
            else
                rec[zeros - ones] = i;
        }
        return ans;
    }
};

int main(void) {
    Solution s;
    vector<int> binaries1 = {1, 0};
    vector<int> binaries2 = {1, 0, 1};
    std::cout << s.findMaxLength(binaries1) << std::endl;
    std::cout << s.findMaxLength(binaries2) << std::endl;
    return 0;
}