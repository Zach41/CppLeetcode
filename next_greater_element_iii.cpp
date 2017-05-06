//
// Created by ZachZhang on 2017/5/6.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int nextGreaterElement(int n) {
        auto digits = to_string(n);
        next_permutation(begin(digits), end(digits));
        auto res = stoll(digits);
        return (res > INT_MAX || res <= n) ? -1 : res;
    }
};

int main(void) {
    Solution s;
    cout << s.nextGreaterElement(12) << endl;
    cout << s.nextGreaterElement(21) << endl;
}

