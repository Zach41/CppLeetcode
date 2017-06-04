#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        map<string, vector<string>> path_map;

        for (auto &path: paths) {
            read_content(path, path_map);
        }
        vector<vector<string>> ans;
        for (auto iter = path_map.begin(); iter != path_map.end(); iter++)
            if (iter -> second.size() > 1)
                ans.push_back(iter -> second);
        return ans;
    }

private:
    void read_content(string& path, map<string, vector<string>> &path_map) {
        string dirname, file_content, filename, content;
        istringstream is(path);
        is >> dirname;

        while (is >> file_content) {
            auto pos = file_content.find('(');
            filename = dirname + "/" + file_content.substr(0, pos);
            content = file_content.substr(pos + 1, string::npos);
            path_map[content].push_back(filename);
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<string> paths = {"root/a 1.txt(abcd) 2.txt(efsfgh)","root/c 3.txt(abdfcd)","root/c/d 4.txt(efggdfh)"};
    for (auto &path_v: s.findDuplicate(paths)) {
        cout << "group:\n\t";
        for (auto &v: path_v) {
            cout << v << '\t';
        }
        cout << '\n';
    }
    return 0;
}
