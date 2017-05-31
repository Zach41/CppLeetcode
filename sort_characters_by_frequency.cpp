#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        map<char, int> freq_map;
        for (char c: s)
            freq_map[c] += 1;
        vector<pair<char, int>> freq_v(freq_map.begin(), freq_map.end());

        sort(freq_v.begin(), freq_v.end(), 
            [](pair<const char, int> const &a, pair<const char, int> const &b) {
                return a.second > b.second;
            });
        
        ostringstream os;
        auto iter = freq_v.begin();
        for(; iter != freq_v.end(); iter++) {
            for (int i=0; i<iter -> second; i++)
                os << iter -> first;
        }
        return os.str();
    }
};

int main() {
    Solution s;
    cout << s.frequencySort("tree") << '\n';
    cout << s.frequencySort("cccaaa") << '\n';
    cout << s.frequencySort("Aabb") << '\n';
}