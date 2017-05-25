#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        set<int> rec;
        for (int v: candies) {
            rec.insert(v);
        }
        if (rec.size() > candies.size() / 2) {
            return candies.size() / 2;
        } else {
            return rec.size();
        }
    }
};

int main(void) {
    Solution s;
    vector<int> candies1 = {1, 1, 2, 3};
    std::cout << s.distributeCandies(candies1) << std::endl;
    vector<int> candies2 = {1, 1, 2, 2, 3, 3};
    std::cout << s.distributeCandies(candies2) << std::endl;    
}