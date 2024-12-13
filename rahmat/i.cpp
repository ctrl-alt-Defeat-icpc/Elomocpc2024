#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 1e5 + 5;

ll a[N][N];

int n;
void Main() {
    cin >> n;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
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