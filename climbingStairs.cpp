class Solution {
public:
    int climbStairs(int n) {
        std::vector<int> memo(n + 1, 0);
        return climbStairs(0, n, memo);
    }

    int climbStairs(int step, int n, std::vector<int>& memo) {
        if (step > n) {
            return 0;
        }
        if (step == n) {
            return 1;
        }
        if (memo[step] > 0) {
            return memo[step];
        }
        memo[step] = climbStairs(step + 1, n, memo) + climbStairs(step + 2, n, memo);
        return memo[step];
    }
};
