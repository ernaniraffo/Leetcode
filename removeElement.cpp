class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.size() == 0) return 0;
        int k = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == val) {
                while (k - 1 >= i and nums[k - 1] == val) {
                    k -= 1;
                }
                if (k - 1 < i) {
                    break;
                }
                int temp = nums[i];
                nums[i] = nums[k - 1];
                nums[k - 1] = temp;
            }
        }
        return k;
    }
    
};