#include <bits/stdc++.h> 
int func(int idx, int sum, vector<int>&arr, vector<vector<int>>&dp)
{
    if(idx == 0)
    {
        if(arr[0] == 0 && sum == 0)return 2;
        if(sum == 0)return 1;
        if(sum == arr[0])return 1;
        return 0;

    }
    if(dp[idx][sum]!=-1)return dp[idx][sum];

   int not_take = func(idx-1, sum, arr, dp);

   int take = 0;

   if(sum - arr[idx]>=0)
    take = func(idx-1, sum - arr[idx], arr, dp);

   return dp[idx][sum] = (not_take + take) % 1000000007;
}

int countPartitions(int n, int d, vector<int> &arr) {
    
   int total = accumulate(arr.begin(), arr.end(), 0);
        
        if(total - d <0 || (total - d) % 2 != 0)
        return 0;
        int sum = (total - d)/2;
        
    vector<vector<int>>dp(n, vector<int>(total+1, -1));
    return func(n-1, sum, arr, dp);
}


