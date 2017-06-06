#include <iostream>
#include <vector>
#include <map>
#include <cstdlib>

using namespace std;

class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        auto result = idxs.find(val) == idxs.end();

        idxs[val].push_back(vals.size());
        vals.push_back(make_pair(val, idxs[val].size() - 1));

        return result;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
       auto result = idxs.find(val) != idxs.end();
       if (result) {
           auto last = vals.back();
           idxs[last.first][last.second] = idxs[val].back();
           vals[idxs[val].back()] = last;
           idxs[val].pop_back();
           if (idxs[val].empty()) idxs.erase(val);
           vals.pop_back();
       }
       return result;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return vals[rand() % vals.size()].first;
    }

private:
    vector<pair<int, int>> vals;
    map<int, vector<int>> idxs;
};

int main(void) {
    cout << "Hello" << '\n';
}