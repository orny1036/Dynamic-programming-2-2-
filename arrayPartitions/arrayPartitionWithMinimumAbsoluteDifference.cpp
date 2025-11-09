bool func(int idx, int sum, vector<int>&arr, vector<vector<int>>&dp)
{
    if(sum == 0)return 1;
    if(idx<0)return 0;
    if(dp[idx][sum]!=-1)return dp[idx][sum];
    bool isPossible = func(idx-1, sum, arr, dp);

    if(arr[idx]<=sum)
        isPossible |= func(idx-1, sum-arr[idx], arr, dp);


   return dp[idx][sum] = isPossible;
}

int minSubsetSumDifference(vector<int>& arr, int n)
{   
	int total_sum = accumulate(arr.begin(), arr.end(), 0);
    int ans = total_sum;
    vector<vector<int>>dp(n, vector<int>(total_sum, -1));
    for(int i = 1; i<total_sum; ++i)
    {
        if(func(n-1, i, arr, dp))
        {
            ans = min(ans, abs(i - (total_sum - i)));
        }
    }
	return ans;
	// Write your code here.
}
