//
// Created by ZachZhang on 2017/5/1.
//

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;


class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<string> times(timePoints);
        bool flag = false;
        for (auto str : timePoints) {
            if (str.substr(0, 2) == "00") {
                times.push_back("24" + str.substr(2, 3));
                flag = true;
            }
        }

        sort(times.begin(), times.end());
        if (!flag) {
            int hour = stoi(times[0].substr(0, 2)) + 24;
            times.push_back(to_string(hour) + times[0].substr(2, 3));
        }

        int hour1, hour2, minute1, minute2;
        int min_minute = 24 * 60;
        for (int i=0; i < times.size() - 1; i++) {
            hour1 = atoi(times[i].substr(0, 2).c_str());
            hour2 = atoi(times[i+1].substr(0, 2).c_str());
            minute1 = atoi(times[i].substr(3, 2).c_str());
            minute2 = atoi(times[i+1].substr(3, 2).c_str());

            min_minute = min((hour2 - hour1) * 60 + minute2 - minute1, min_minute);
        }
        return min_minute;
    }
};

int main(void) {
    Solution s;
    vector<string> strv = {"05:31", "22:08", "00:35"};
    cout << s.findMinDifference(strv) << endl;
}