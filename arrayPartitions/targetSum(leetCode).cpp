class Solution {
public:

int func(int idx, int sum, int k, int n, vector<int>& nums, int total, vector<vector<int>>&dp) {

    if(idx == n && sum == k)return 1;
    if(idx == n)return 0;
    if(dp[idx][sum+total]!=-1)return dp[idx][sum+total];
    int neg = func(idx+1, sum-nums[idx], k, n, nums, total, dp);
    int pos = func(idx+1, sum+nums[idx], k, n, nums, total, dp);

    return dp[idx][sum+total] = (neg + pos);
}
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
    int total = accumulate(nums.begin(), nums.end(), 0);

    vector<vector<int>>dp(n, vector<int>(2*total+1, -1));
    return func(0, 0, target, n, nums, total, dp);
    }
};
