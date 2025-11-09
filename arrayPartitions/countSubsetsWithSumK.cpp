class TopDown {
    const int MOD = 1e9 + 7;
    int n;

    // O(2*N*T) & O(N*T + N)
    int solveWithMemo(vector<vector<int>>& dp, const vector<int>& nums, int index, int target) {
        // Edge case: If you reached the 0th index then compute count of all the subsets according to their existence
        if(index == 0) {
          // If target is also zero along with index then check if the 0-th index element is zero or not, 
          //if it is then there are two subsets that will fulfil the condition of target zero, one including the 0th element, another without including it
            if(target == 0) 
                return (nums[index] == 0) ? 2 : 1;
            else
                return (nums[index] == target) ? 1 : 0;
        }
        
        if(dp[index][target] != -1)
            return dp[index][target];
            
        // There are always two possibilties to perform at each index
        int currSkip = solveWithMemo(dp, nums, index - 1, target); // Is to skip index value
        int currTake = 0;                                          // Is to take index value

        // Avoid target becoming negative
        if(nums[index] <= target) 
            currTake = solveWithMemo(dp, nums, index - 1, target - nums[index]);

        // Store result to memoization table and return it
        return dp[index][target] = (currTake + currSkip) % MOD;
    }

public:
    // Method to count all subsets whose sum is equal to target, using recursion with memoization - O(N*T) & O(N*T) : Where T = target 
    int countSubsetSumsTarget(vector<int>& nums, int target) {
        n = nums.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return solveWithMemo(dp, nums, n - 1, target);
    }
};
