//
// Created by ZachZhang on 2017/5/4.
//

#include <iostream>
#include <sstream>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        istringstream in('+' + s + '+');
        int total = 0, term = 0, n;

        char op;
        while (in >> op) {
            if (op == '+' || op == '-') {
                total += term;
                in >> term;
                term *= (op == '+' ? 1: -1);
            } else {
                in >> n;
                if (op == '*')
                    term *= n;
                else
                    term /= n;
            }
        }
        return total;
    }
};

int main(void) {
    Solution s;
    cout << s.calculate("3 + 2*2") << endl;
    cout << s.calculate(" 3/2") << endl;
    cout << s.calculate("3 + 5 / 2") << endl;
}