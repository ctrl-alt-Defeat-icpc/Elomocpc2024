#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 1e5 + 5;
ll n, l, ans;
pair<int, pair<int, int>> traffic[N];
ll curr_idx, curr_loc;

void Main() {
    cin >> n >> l;
	for(int i = 0; i < n; i++)
		cin >> traffic[i].first >> traffic[i].second.first >> traffic[i].second.second;
	traffic[n].first = l;

	sort(traffic, traffic + n + 1);

	while(true) {
		ans += traffic[curr_idx].first - curr_loc;
		curr_loc = traffic[curr_idx].first;
		
		if(curr_loc == l)
			break;
		
		// ll t = (g[curr_idx] + r[curr_idx] < ans) ? (ans % (g[curr_idx] + r[curr_idx])) : ans;
		ll t = ans % (traffic[curr_idx].second.first + traffic[curr_idx].second.second);
		if(t >= traffic[curr_idx].second.first) { // if struggle in red sign
			ans += (traffic[curr_idx].second.first + traffic[curr_idx].second.second - t);
		}
		curr_idx++;
	}
	cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    // int t; cin >> t; while(t--) Main();
    Main();
    return 0;
}
/*
	contest name: rahmat
	problem letter: C
	Time: 2024-12-13 09:02 UTC: +3:30

	Writer: EnAnsari
	Email: Rahmat2022a@gmail.com
	website: enansari.github.io

	Failure is the condiment that gives success its flavor. ~Truman Capote

	this code created by rcph (https://github.com/EnAnsari/cph)
*/