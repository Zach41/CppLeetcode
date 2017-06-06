#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
 public:
  int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C,
                   vector<int>& D) {
    map<int, int> sum_map;
    for (size_t i = 0; i < A.size(); i++) {
      for (size_t j = 0; j < B.size(); j++) {
        sum_map[A[i] + B[j]]++;
      }
    }

    int ans = 0;
    for (size_t i = 0; i < C.size(); i++) {
      for (size_t j = 0; j < D.size(); j++) {
        if (sum_map.find(-C[i] - D[j]) != sum_map.end()) {
          ans += sum_map[-C[i] - D[j]];
        }
      }
    }
    return ans;
  }
};

int main(void) {
  Solution s;
  vector<int> A = {1, 2};
  vector<int> B = {-2, -1};
  vector<int> C = {-1, 2};
  vector<int> D = {0, 2};
  cout << s.fourSumCount(A, B, C, D) << '\n';
  return 0;
}