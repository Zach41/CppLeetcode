#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        flowerbed.push_back(0);
        flowerbed.insert(flowerbed.begin(), 0);
        int tot = 0;
        int max_zero = 0;
        for (size_t i = 0; i < flowerbed.size(); i++)
        {
            if (flowerbed[i] == 1)
            {
                tot += max_zero % 2 ? max_zero / 2 : (max_zero - 1) / 2;
                max_zero = 0;
                if (i > 0 && flowerbed[i - 1])
                    return false;
                if (i < flowerbed.size() - 1 && flowerbed[i + 1])
                    return false;
            }
            else
            {
                max_zero += 1;
            }
        }
        if (max_zero) {
            tot += max_zero % 2 ? max_zero / 2 : (max_zero - 1) / 2;
        }
        return tot >= n;
    }
};

int main(void)
{
    Solution s;
    vector<int> flowerbed = {1, 0, 0, 0, 1};
    cout << s.canPlaceFlowers(flowerbed, 1) << '\n';
    vector<int> flowerbed2 = {1, 0, 0, 0, 1};
    cout << s.canPlaceFlowers(flowerbed2, 2) << '\n';
    vector<int> flowerbed3 = {0, 0, 1, 0, 1};
    cout << s.canPlaceFlowers(flowerbed3, 1) << '\n';
    return 0;
}