#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        static int cnt = 0;
        string encoded_str = "http://tinyurl.com/" + std::to_string(cnt++);
        urls[encoded_str] = longUrl;
        return encoded_str;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return urls[shortUrl];
    }

private:
    map<string, string> urls;
};

int main(void) {
    Solution s;
    std::cout << s.decode(s.encode("http://test.com")) << std::endl;
    return 0;
}