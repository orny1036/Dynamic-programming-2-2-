#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6 + 10;
int dp[N];

int func(int amount, vector<int> &coins) {
    if (amount == 0) return 0;
    if (dp[amount] != -1) return dp[amount];

    int number_of_coins = LLONG_MAX;
    for (int coin : coins) {
        if (amount - coin >= 0) {
            int sub_res = func(amount - coin, coins);
            if (sub_res != LLONG_MAX) {
                number_of_coins = min(number_of_coins, sub_res + 1);
            }
        }
    }
    return dp[amount] = number_of_coins;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    memset(dp, -1, sizeof(dp));

    int n, x;
    cin >> n >> x;

    vector<int> coins(n);
    for (int i = 0; i < n; ++i)
        cin >> coins[i];

    int ans = func(x, coins);
   
    if (ans == LLONG_MAX)
        cout << -1 << '\n';
    else
        cout << ans << '\n';

    return 0;
}
