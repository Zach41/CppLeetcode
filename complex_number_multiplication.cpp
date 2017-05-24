#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Solution
{
  public:
    string complexNumberMultiply(string a, string b)
    {
        int flag_a = 1, flag_b = 1;
        int ra, ia, rb, ib;
        read_string(a, ra, ia);
        read_string(b, rb, ib);
        ostringstream os;
        os << ra * rb - ia * ib
           << '+'
           << ra * ib + ia * rb
           << 'i';
        return os.str();
        // char c = getc
    }

  private:
    void read_string(string &s, int &rv, int &iv)
    {
        int flag_r = 1, flag_i = 1;
        istringstream in(s);
        rv = 0, iv = 0;

        char c = in.peek();
        if (c == '-')
        {
            flag_r = -1;
            in.get(c);
        }
        while (true)
        {
            in.get(c);
            if (c == '+')
                break;
            rv = rv * 10 + (c - '0');
        }

        rv *= flag_r;

        c = in.peek();
        if (c == '-')
        {
            flag_i = -1;
            in.get(c);
        }
        while (true)
        {
            in.get(c);
            if (c == 'i')
                break;
            iv = iv * 10 + (c - '0');
        }

        iv *= flag_i;
    }
};

int main(void)
{
    Solution s;
    // std::cout << s.complexNumberMultiply("1+1i", "1+1i") << '\n';
    std::cout << s.complexNumberMultiply("1+-1i", "1+-1i") << '\n';
}
