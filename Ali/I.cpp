#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 1e5 + 5;

void Main()
{
    int n;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    for (auto &row : matrix)
    {
        for (auto &x : row)
        {
            cin >> x;
        }
    }
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