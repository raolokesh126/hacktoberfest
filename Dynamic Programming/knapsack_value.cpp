/**
 * Knapsack dp on value when weight is very high
 * and does not fit the memory constraints of an array
 * Link to problem: https://atcoder.jp/contests/dp/tasks/dp_e
 **/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
	ll n, w;
	cin >> n >> w;
	vector<ll>weight(n), val(n);
	int total = 0;
	for (ll i = 0; i < n; i++) {
		cin >> weight[i] >> val[i];
		total += val[i];
	}

	vector<ll>dp(total + 2, INT_MAX); // store min weight consumed to reach the state
	dp[0] = 0;
	for (ll i = 0; i < n; i++) {
		for (ll x = total; x >= val[i]; x--) {
			dp[x] = min({dp[x], dp[x - val[i]] + weight[i]});
		}
	}
	ll ans = 0;
	for (ll i = 0; i <= total; i++) {
		if (dp[i] <= w) {
			ans = max(ans, i);
		}
	}
	cout << ans  << endl;
}