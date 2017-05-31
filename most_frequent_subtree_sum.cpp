#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        if (root == NULL)
            return vector<int>();
        map<int, int> sum_map;
        sum_subtree(root, sum_map);

        auto cmp = [](pair<const int, int> const& a, pair<const int, int> const& b) {
            return a.second > b.second;
        };
        vector<pair<int, int>> sums(sum_map.begin(), sum_map.end());
        sort(sums.begin(), sums.end(), cmp);
        auto iter = sums.begin();
        int frequency = iter -> second;
        vector<int> ans;
        for (; iter != sums.end(); iter++)
            if (iter -> second == frequency)
                ans.push_back(iter -> first);
        return ans;
    }

private:
    int sum_subtree(TreeNode* root, map<int, int> &sum_map) {
        if (root -> left == NULL && root -> right == NULL) {
            sum_map[root -> val] += 1;
            return root -> val;
        }
        int tree_sum = root -> val;
        if (root -> left)
            tree_sum += sum_subtree(root -> left, sum_map);
        if (root -> right)
            tree_sum += sum_subtree(root -> right, sum_map);
        sum_map[tree_sum] += 1;
        return tree_sum;
    }
};

int main() {
    Solution s;
    TreeNode node5(5), node2(2), node_3(-5);
    node5.left = &node2;
    node5.right = &node_3;
    for (auto &v: s.findFrequentTreeSum(&node5))
        cout << v << endl;
}

