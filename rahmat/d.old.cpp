#include <bits/stdc++.h>
using namespace std;

#define ll unsigned long long
#define pll pair<ll, ll>
const int N = 1e5 + 5;

int n, curr_readed;
char x;

void invalidInput() {
	cout << -1 << endl;
	exit(0);
}

void simplize(ll &a, ll &b) {
	ll gcdd = __gcd(a, b);
	a /= gcdd;
	b /= gcdd;
}

pll inputt() {
	if(curr_readed >= n)
		invalidInput();
	cin >> x;
	curr_readed++;
	pll a, b, c;
	if(x == '(') {
		a = inputt();
		b = inputt();
		c = inputt();
		if(curr_readed >= n)
			invalidInput();
		cin >> x;	
		curr_readed++;
		if(x != ')')
			invalidInput();
	}
	else if(x >= '1' && x <= '9') return {static_cast<ll>(x - '0'), static_cast<ll>(1)};
	else invalidInput();

	simplize(b.first, c.first);
	simplize(b.second, c.second);
	pll bc = {b.first * c.second, b.second * c.first};
	ll lcmm = a.second / __gcd(bc.second, a.second) * bc.second;
	
	bc.first *= (lcmm / bc.second);
	a.first *= (lcmm / a.second);
	pll result = {a.first + bc.first, lcmm};
	simplize(result.first, result.second);
	return result;
}

void Main() {
    cin >> n;
	pll result = inputt();
	if(curr_readed != n) invalidInput();
	cout << result.first << " " << result.second << endl;
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
	problem letter: D
	Time: 2024-12-13 09:02 UTC: +3:30

	Writer: EnAnsari
	Email: Rahmat2022a@gmail.com
	website: enansari.github.io

	People who succeed have momentum. The more they succeed, the more they want to succeed, and the more they find 
	a way to succeed. Similarly, when someone is failing, the tendency is to get on a downward spiral that can 
	even become a self-fulfilling prophecy. ~Tony Robbins

	this code created by rcph (https://github.com/EnAnsari/cph)
*/