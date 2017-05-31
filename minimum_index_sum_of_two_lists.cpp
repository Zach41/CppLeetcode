#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        map<string, int> rec;
        
        for (int idx = 0; idx < list1.size(); idx++) {
            rec[list1[idx]] = idx;
        }

        int least = list1.size() + list2.size();
        vector<string> ans;
        for (int idx = 0; idx < list2.size(); idx++) {
            if (rec.find(list2[idx]) != rec.end())
                least = min(least, rec[list2[idx]] + idx);
        }
        for (int idx = 0; idx < list2.size(); idx++) {
            if (rec.find(list2[idx]) != rec.end() && least == rec[list2[idx]] + idx)
                ans.push_back(list2[idx]);
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<string> l1 = {"Shogun", "Tapioca Express", "Burger King", "KFC"};
    vector<string> l2 = {"Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"};

    vector<string> l11 = {"Shogun", "Tapioca Express", "Burger King", "KFC"};
    vector<string> l22 = {"KFC", "Shogun", "Burger King"};
    for (auto &v: s.findRestaurant(l11, l22))
        std::cout << v << '\n';
}