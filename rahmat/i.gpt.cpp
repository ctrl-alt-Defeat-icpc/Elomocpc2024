#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int INF = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> a(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> a[i][j];
            }
        }

        vector<vector<bool>> covered(n, vector<bool>(n, false));
        ll total_cost = 0;

        while (true) {
            int best_x = -1, best_y = -1, max_coverage = 0;
            ll min_cost = INF;

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (covered[i][j]) continue;

                    // Calculate coverage
                    int coverage = 0;
                    for (int x = max(0, i - n / 2); x <= min(n - 1, i + n / 2); x++) {
                        for (int y = max(0, j - n / 2); y <= min(n - 1, j + n / 2); y++) {
                            if (!covered[x][y]) coverage++;
                        }
                    }

                    // Find best position
                    if (coverage > max_coverage || (coverage == max_coverage && a[i][j] < min_cost)) {
                        best_x = i;
                        best_y = j;
                        max_coverage = coverage;
                        min_cost = a[i][j];
                    }
                }
            }

            if (max_coverage == 0) break;

            // Place scarecrow
            total_cost += a[best_x][best_y];
            for (int x = max(0, best_x - n / 2); x <= min(n - 1, best_x + n / 2); x++) {
                for (int y = max(0, best_y - n / 2); y <= min(n - 1, best_y + n / 2); y++) {
                    covered[x][y] = true;
                }
            }
        }

        cout << total_cost << endl;
    }

    return 0;
}
