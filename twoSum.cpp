#include <unordered_map>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> hashMap;
    vector<int> sol;

    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        auto itr = hashMap.find(complement);
        if (itr != hashMap.end()) {
            sol.push_back(i);
            sol.push_back(itr->second);
            return sol;
        }
        hashMap.insert(make_pair(nums[i], i));
    }

    return sol;
}
