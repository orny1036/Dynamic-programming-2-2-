
int cutRod(vector<int> &price, int n)
{
	vector<vector<int>>dp(n, vector<int>(n+1, 0));
	for(int i = 1; i<=n; ++i)
	{
          dp[0][i] = i*price[0];
	}

	for(int idx = 1; idx<n; ++idx)
	{
          for(int remaining_length = 0; remaining_length<=n; ++remaining_length)
		  {
			  int not_take = dp[idx-1][remaining_length];

	          int take = -1;
	          int length_to_be_cut = idx+1;
	          if(remaining_length - length_to_be_cut >= 0)
	         {
		        take = dp[idx][remaining_length - length_to_be_cut]+price[idx];
	         }
			 dp[idx][remaining_length] = max(take, not_take);
		}
	}
	return dp[n-1][n];
}

