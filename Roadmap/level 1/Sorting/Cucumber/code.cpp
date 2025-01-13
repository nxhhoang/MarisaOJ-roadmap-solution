#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i < (int)b; i++)
#define pb push_back
#define fi first
#define se second
#define endl '\n'
#define umap unordered_map
#define uset unordered_set

#define all(a) (a).begin(), (a).end()
#define pii pair<int, int>
using namespace std;
using ll = long long;

const ll inf = 2e18;
const int N = 10;
const int MAXSIZE = 1e5;
const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<pair<int,int>> pa(n);

    int maxVal = -1;

    int sum = 0;

    vector<int> pre(n + 1);

    FOR(i, 0, n) cin >> pa[i].first, maxVal = max(maxVal, pa[i].first);
    FOR(i, 0, n) cin >> pa[i].second, sum += pa[i].second; 

    sort(pa.begin(), pa.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
        return a.second > b.second;
    });

    for(int i = maxVal; i > 0; i--) {
        int currentMaxLoss = -1;
        for (int j = 0; j < pa.size(); j++) {
            if (pa[j].first >= i) {
                if (currentMaxLoss == -1 || pa[j].second > pa[currentMaxLoss].second) {
                    currentMaxLoss = j;
                }
            }
        }
        if (currentMaxLoss != -1) {
            sum -= pa[currentMaxLoss].second;
            pa.erase(pa.begin() + currentMaxLoss);
        }
        if (pa.empty()) break;
    }
    cout << sum << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
