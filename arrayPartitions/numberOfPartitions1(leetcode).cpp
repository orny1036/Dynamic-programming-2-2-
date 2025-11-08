class Solution {
public:
const int mod = 1e9+7;

int func(int idx, int sum, int k, int n, vector<int>& nums, vector<vector<int>>& dp) {
    if (sum >= k) return 0;
    if (idx == n) return 1;
    if (dp[idx][sum] != -1) return dp[idx][sum];

    int not_take = func(idx + 1, sum, k, n, nums, dp);
    int take = func(idx + 1, sum + nums[idx], k, n, nums, dp);

    return dp[idx][sum] = (not_take + take) % mod;
}

int modPow(long long base, long long exp) {
    long long res = 1;
    while (exp) {
        if (exp & 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}

    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();

    long long total_sum = accumulate(nums.begin(), nums.end(), 0LL);
    if (total_sum < 2LL * k) {
        cout << 0;
        return 0;
    }

    vector<vector<int>> dp(n + 1, vector<int>(k, -1));

    long long invalid = func(0, 0, k, n, nums, dp);
    long long total_subsets = modPow(2, n);

    int ans = (total_subsets - (2 * invalid) % mod + mod) % mod;
    return ans;
    }
};
