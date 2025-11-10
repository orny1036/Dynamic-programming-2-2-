class Solution {
public:

    int minInsertions(string s) {
        
    string temp = s;
    reverse(temp.begin(), temp.end());
    string s2 = temp;

    int n = s.size();

    //vector<vector<int>>dp(n+1, vector<int>(n+1, 0));
    vector<int>prev(n+1, 0), cur(n+1, 0);

    for(int i = 1; i<=n; ++i)
    {
        for(int j = 1; j<=n; ++j)
        {
            if(s[i-1]==s2[j-1])
            {
               // dp[i][j] = 1 + dp[i-1][j-1];
                cur[j] = 1 + prev[j-1];
            }
            else
            {
                //dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                cur[j] = max(prev[j], cur[j-1]);
            }
        }
        prev = cur;
    }

    int len = prev[n];

    return n - len;
    }
};
