//
// Created by ZachZhang on 2017/4/24.
//

#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int findLUSlength(string a, string b) {
        if (a == b)
            return -1;
        return max(a.size(), b.size());
    }
};