//
// Created by ZachZhang on 2017/5/4.
//

#include <iostream>
#include <stack>
#include <cctype>

using namespace std;

class Solution
{
  public:
    int calculate(string s)
    {
        stack<int> nums, ops;
        int num = 0, rst = 0, sign = 1;
        for (auto c : s)
        {
            if (isdigit(c))
                num = num * 10 + c - '0';
            else
            {
                rst += sign * num;
                num = 0;
                if (c == '+')
                    sign = 1;
                if (c == '-')
                    sign = -1;
                if (c == '(')
                {
                    nums.push(rst);
                    ops.push(sign);
                    rst = 0;
                    sign = 1;
                }
                if (c == ')' && ops.size())
                {
                    rst = rst * ops.top() + nums.top();
                    nums.pop();
                    ops.pop();
                }
            }
        }
        rst += sign * num;
        return rst;
    }
};

int main(void)
{
    Solution s;
    cout << s.calculate("1 + 1") << endl;
    cout << s.calculate("2 - 1 + 2 ") << endl;
    cout << s.calculate("(1 + ((4 +5 + 2) - 3) + (6+8)") << endl;
    cout << s.calculate("23456") << endl;
    cout << s.calculate("12 + 34 - 3 + (23 + 2)") << endl;
    cout << s.calculate("2 - (5 - 6)") << endl;
}