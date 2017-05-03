//
// Created by ZachZhang on 2017/5/3.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ret;
        for (long p1 = 3; p1 >= 1; p1--) {
            for (long p2 = 3; p2 >= 1; p2--) {
                for (long p3 = 3; p3 >=1; p3--) {
                    int p4 = s.size() - (p1 + p2 + p3);
                    if (p4 <= 0 || p4 > 3)
                        continue;
                    auto sub1 = s.substr(0, p1);
                    auto sub2 = s.substr(p1, p2);
                    auto sub3 = s.substr(p2+p1, p3);
                    auto sub4 = s.substr(p3+p2+p1, p4);

                    if (isValidIpv4Block(sub1) && isValidIpv4Block(sub2)
                            && isValidIpv4Block(sub3) && isValidIpv4Block(sub4))
                        ret.push_back(sub1 + "." + sub2 + "." + sub3 + "." + sub4);
                }
            }
        }
        return ret;
    }

private:
    bool isValidIpv4Block(string &block) {
        if (block.size() <= 0 || block.size() > 3)
            return false;
        if (block[0] == '0' && block.size() > 1)
            return false;
        for (auto c : block)
            if (!isdigit(c))
                return false;
        if (stoi(block) < 0 || stoi(block) > 255)
            return false;
        return true;
    }
};

int main(void) {
    Solution s;
    auto strv = s.restoreIpAddresses("010010");
    for (auto s: strv)
        cout << s << endl;
}
