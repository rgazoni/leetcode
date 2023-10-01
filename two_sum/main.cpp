#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;        
        for(int i = 0; i < nums.size(); i++) {
            if(map.find(nums[i]) != map.end()) {
                return {map[nums[i]], i};
            }
            map[target - nums[i]] = i;
        }
        return {};
    }
};


int main () {
    Solution s;
    int a[4] = {2, 7, 11, 15};
    std::vector<int> nums;
    for (int i=0; i<4; i++) nums.push_back(a[i]);
    int target = 9;
    std::vector<int> result = s.twoSum(nums, target);
    for(int i = 0; i < result.size(); i++) {
        std::cout << result[i] << std::endl;
    }
    return 0;
}
