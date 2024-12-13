#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 1e5 + 5;

ll n, mull;
set<ll> ans;

void Main() {
    cin >> n;
	for(int mask = 1; mask < (1 << n); mask++) {
		mull = 1;
		for(int i = 0; i < n; i++) {
			if(mask & (1 << i))
				mull *= (i + 1);
		}
		ans.insert(mull);
	}
	cout << ans.size() << endl;
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
	problem letter: A
	Time: 2024-12-13 09:02 UTC: +3:30

	Writer: EnAnsari
	Email: Rahmat2022a@gmail.com
	website: enansari.github.io

	To be successful you must accept all challenges that come your way. You can't just accept the ones you like. 
	~Mike Gafka

	this code created by rcph (https://github.com/EnAnsari/cph)
*/