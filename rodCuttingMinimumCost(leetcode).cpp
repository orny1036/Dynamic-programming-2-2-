class Solution {
public:

int cut(int i, int j, vector<int>& arr, vector<vector<int>>&dp)
{
    if (j - i <= 1)
        return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int ans = INT_MAX;
    for (int k = i + 1; k < j; ++k)
    {
        int cost = (arr[j] - arr[i]) + cut(i, k, arr, dp) + cut(k, j, arr, dp);
        ans = min(ans, cost);
    }
    return dp[i][j] = ans;
}

    int minCost(int n, vector<int>& cuts) {
         
    cuts.insert(cuts.begin(), 0);
    cuts.push_back(n);
    int m = cuts.size();
    vector<vector<int>>dp(m, vector<int>(m, -1));
    sort(cuts.begin(), cuts.end());
    
    return cut(0, cuts.size() - 1, cuts, dp) ;

    }
};
