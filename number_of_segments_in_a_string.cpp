//
// Created by ZachZhang on 2017/5/1.
//

#include <iostream>
#include <sstream>

using namespace std;

class Solution {
public:
    int countSegments(string s) {
        istringstream ins(s);

        int cnt = 0;
        string seg;
        while( ins >> seg) {
            cnt += 1;
        }
        return cnt;
    }
};

int main(void) {
    Solution s;
    cout << s.countSegments("Hello, my name is John");
}