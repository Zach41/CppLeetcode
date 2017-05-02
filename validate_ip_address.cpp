//
// Created by ZachZhang on 2017/5/2.
//

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    string validIPAddress(string IP) {
        if (IP.find_first_of('.', 0) != string::npos) {
            vector<string> segs = split(IP, '.');
            if (segs.size() != 4)
                return "Neither";
            for (auto seg : segs) {
                if (!isValidIpv4Block(seg))
                    return "Neither";
            }
            return "IPv4";
        } else {
            vector<string> segs = split(IP, ':');
            if (segs.size() != 8)
                return "Neither";
            for (auto seg : segs) {
                if (!isValidIpv6Block(seg))
                    return "Neither";
            }
            return "IPv6";
        }
    }

private:
    vector<string> split(string str, char delimter) {
        vector<string> strv;
        istringstream ss(str);
        string tok;

        while (getline(ss, tok, delimter))
            strv.push_back(tok);
        if (str[str.size() - 1] == delimter)
            strv.push_back("");
        return strv;
    }

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

    bool isValidIpv6Block(string &block) {
        if (block.size() > 4 || block.size() <= 0)
            return false;
        for (auto c: block) {
            if (!isalnum(c) || (c > 'F' && c <= 'Z') || (c > 'f' && c <= 'z'))
                return false;
        }
        return true;
    }
};

int main(void) {
    Solution s;
    cout << s.validIPAddress("192.0.0.1") << endl;
    cout << s.validIPAddress("2001:db8:85a3:0::8a2E:0370:7334") << endl;
    cout << s.validIPAddress("2001:0db8:85a3:0:0:8A2E:0370:7334:") << endl;
    cout << s.validIPAddress("172.16.254.1") << endl;
    cout << s.validIPAddress("2001:0db8:85a3:0:0:8A2E:0370:7334") << endl;
    cout << s.validIPAddress("256.256.256.256") << endl;
}