#include <iostream>
#include <map>
#include <cctype>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> rows = {"QWERTYUIOP", "ASDFGHJKL", "ZXCVBNM"};
        map<char, int> row_map;
        for (int i=0; i < 3; i++) {
            for (auto ch: rows[i]) {
                row_map[ch] = i;
            }
        }
        vector<string> ans;
        for (auto &word: words) {
            int row = row_map[toupper(word[0])];
            bool push = true;
            for (auto ch: word) {
                if (row != row_map[toupper(ch)]) {
                    push = false;
                    break;
                }                    
            }
            if (push)
                ans.push_back(word);
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<string> words = {"Hello", "Alaska", "Dad", "Peace"};
    for (auto &v: s.findWords(words))
        cout << v << '\n';
}