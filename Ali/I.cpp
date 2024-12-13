#include <bits/stdc++.h>
using namespace std;

#define ll long long

void find_max_val(int &n, vector<vector<int>> &mat, vector<vector<bool>> &safe, int &mx, int &my, ll &mval)
{
    mval = 1e9 + 5;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!safe[i][j])
                if (mat[i][j] < mval)
                {
                    mval = mat[i][j];
                    mx = i;
                    my = j;
                }
        }
    }
}
void del_mval(ll &ans, int &dis, vector<vector<int>> &mat, int &n, vector<vector<bool>> &safe, int &mx, int &my)
{
    ans += mat[mx][my];
    for (int x = max(0, mx - dis); x <= min(n - 1, mx + dis); x++)
    {
        for (int y = max(0, my - dis); y <= min(n - 1, my + dis); y++)
        {
            safe[x][y] = 1;
            mat[x][y] = 0;
        }
    }
}

void cal_val(int &n, int &dis, vector<vector<ll>> &val, vector<vector<int>> &mat, vector<vector<bool>> &safe)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!safe[i][j])
                for (int x = max(0, i - dis); x <= min(n - 1, i + dis); x++)
                {
                    for (int y = max(0, j - dis); y <= min(n - 1, j + dis); y++)
                    {
                        val[i][j] += mat[x][y];
                    }
                }
            val[i][j] -= mat[i][j];
        }
    }
}

bool check_safe(int &n, vector<vector<bool>> &safe)
{
    if (!safe[0][0])
        return false;
    if (!safe[0][n - 1])
        return false;
    if (!safe[n - 1][0])
        return false;
    if (!safe[n - 1][n - 1])
        return false;

    return true;
}

void Main()
{
    int n;
    cin >> n;

    vector<vector<int>> mat(n, vector<int>(n, 0));
    for (auto &row : mat)
    {
        for (auto &x : row)
        {
            cin >> x;
        }
    }

    int dis = floor(n / 2.);
    vector<vector<bool>> safe(n, vector<bool>(n, 0));

    // vector<vector<ll>> val(n, vector<ll>(n, 0));

    // cout << endl;
    // for (auto &row : val)
    // {
    //     for (auto &x : row)
    //     {
    //         cout << x << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    ll ans = 0;
    int mx = 0, my = 0;
    ll mval = -1;
    while (!check_safe(n, safe))
    {
        // cal_val(n, dis, val, mat, safe);

        find_max_val(n, mat, safe, mx, my, mval);

        cout << endl;
        cout << mval << ' ' << mx << ' ' << my << endl;
        for (auto &row : mat)
        {
            for (auto &x : row)
            {
                cout << x << ' ';
            }
            cout << endl;
        }
        cout << endl;

        del_mval(ans, dis, mat, n, safe, mx, my);
    }

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