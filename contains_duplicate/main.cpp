// This solution has a time complexity of O(n) and a space complexity of O(n)
// Was solved using a hash table
#include <unordered_map>
using namespace std;

class Solution {
public:
  bool containsDuplicate(vector<int> &nums) {
    unordered_map<int, int> umap;
    for (int num : nums) {
      if (umap[num] >= 1) {
        return true;
      }
      umap[num]++;
    }
    return false;
  }
};
