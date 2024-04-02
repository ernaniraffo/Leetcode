class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long consecutiveZeros = 0;
        long long totalSubarrays = 0;
        for (const int& n : nums) {
            if (n == 0) {
                totalSubarrays += consecutiveZeros + 1;
                consecutiveZeros += 1;
            } else {
                consecutiveZeros = 0;
            }
        }
        return totalSubarrays;
    }
};
