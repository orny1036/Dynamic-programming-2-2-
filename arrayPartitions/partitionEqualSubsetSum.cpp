class Solution {
public:
    bool isPossible(int idx, int target, vector<int>& nums, vector<vector<int>>&dp)
    {   
        if(target == 0)return true;
        if(idx == 0)
        {
            return (nums[idx] == target);
        }
        if(dp[idx][target]!=-1)return dp[idx][target];

        bool possible = isPossible(idx-1, target, nums, dp);

        if(nums[idx]<=target)
        possible|=isPossible(idx-1, target-nums[idx], nums, dp);

        return dp[idx][target] = possible;
    }
    bool canPartition(vector<int>& nums) {
        
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);
        if(total % 2 != 0)
        return false;
        else
        total/=2;
        vector<vector<int>>dp(n, vector<int>(total+1, -1));
        return isPossible(n-1, total, nums, dp);
    }
};
