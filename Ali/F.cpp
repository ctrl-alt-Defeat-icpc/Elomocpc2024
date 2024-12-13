#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 1e5 + 5;

void Main()
{
    int n;
    cin >> n;
    int ans;
    if (n % 2)
        ans = ceil(n / 2.);
    else
        ans = n;

    if (n == 1)
        ans = 1;
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        Main();
    return 0;
}