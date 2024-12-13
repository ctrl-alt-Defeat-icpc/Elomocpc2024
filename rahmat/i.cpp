#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 1000 + 5;

int a[N][N];
ll ans, summ;
int n;

void visiting(int x, int y, vector<vector<int>> &visited) {
	for(int i = max(0, x - n / 2); i <= min(n - 1, x + n / 2); i++)
		for(int j = max(0, y - n / 2); j <= min(n - 1, y + n / 2); j++)
			visited[i][j] = 1;
}

ll solve(int x, int y, ll curr, vector<vector<int>> visited) {
	curr += a[x][y];
	visiting(x, y, visited);
	summ = 1e16;
	bool change = false;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(visited[i][j] == 0) {
				summ = min(summ, solve(i, j, curr, visited));
				change = true;
			}
	if(change)
		curr += summ;

	return curr;
}

void Main() {
    cin >> n;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	ans = 1e16;
	vector<vector<int>> visit(n, vector<int>(n, 0));
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			ans = min(ans, solve(i, j, 0, visit));
	cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t; while(t--) Main();
    // Main();
    return 0;
}
/*
	contest name: rahmat
	problem letter: I
	Time: 2024-12-13 09:02 UTC: +3:30

	Writer: EnAnsari
	Email: Rahmat2022a@gmail.com
	website: enansari.github.io

	Don't raise your voice, improve your argument. ~Anonymous

	this code created by rcph (https://github.com/EnAnsari/cph)
*/