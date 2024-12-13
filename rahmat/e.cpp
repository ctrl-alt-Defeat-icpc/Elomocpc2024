#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 1e5 + 5;
int n, u, v;
vector<int> adj[N];
vector<int> child[N];

void dfs(int v, int p) {
	for(auto u : adj[v]) {
		if(u == p) continue;
		child[v].push_back(u);
		dfs(u, v);
	}
}

bool check(int curr) {
	if((child[curr].size() == 0 && curr) || (curr == 0 && child[curr].size() == 1)) return true;
	if(child[curr].size() == 1) return false;
	int summ = 0;
	for(auto c : child[curr])
		if(check(c)) summ++;
	if(summ > 1) return true;
	return false;
}

void Main() {
    cin >> n;
	for(int i = 0; i < n - 1; i++) {
		cin >> u >> v;
		u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(0, 0);
	if(check(0)) cout << 1 << endl;
	else cout << 0 << endl;
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
	problem letter: E
	Time: 2024-12-13 09:02 UTC: +3:30

	Writer: EnAnsari
	Email: Rahmat2022a@gmail.com
	website: enansari.github.io

	Successful people do what unsuccessful people are not willing to do. Don't wish it were easier, wish you were better. 
	~Jim Rohn

	this code created by rcph (https://github.com/EnAnsari/cph)
*/