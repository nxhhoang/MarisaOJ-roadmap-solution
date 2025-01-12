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
    vector<pair<int,int>> arr(n);
    FOR(i, 0, n) cin >> arr[i].first >> arr[i].second;

    sort(all(arr));

    int dem = 1;
    int cur = 0;

    FOR(i, 1, n) {
        if (arr[i].first > arr[cur].first && arr[i].second <= arr[cur].second) cur = i;
        else if (arr[i].first > arr[cur].second) dem++, cur = i;
    }

    cout << dem << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
