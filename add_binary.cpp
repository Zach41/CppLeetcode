//
// Created by ZachZhang on 2017/5/3.
//

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        if (a.size() < b.size())
            swap(a, b);
        int asize = a.size(), bsize = b.size();
        int length = min(a.size(), b.size());
        string ans;
        for (int i=1; i<=length; i++) {
            int tmp = (a[asize - i] - '0') + (b[bsize - i] - '0') + carry;
            ans = static_cast<char>((tmp % 2) + '0') + ans;
            carry = tmp / 2;
        }
        for (int i = length + 1; i <= a.size(); i++) {
            int tmp = (a[asize - i] - '0') + carry;
            ans = static_cast<char>((tmp % 2) + '0') + ans;
            carry = tmp / 2;
        }
        if (carry) {
            ans = '1' + ans;
        }
        return ans;
    }
};

int main(void) {
    Solution s;
    cout << s.addBinary("11", "1") << endl;
    cout << s.addBinary("11", "11") << endl;
}
