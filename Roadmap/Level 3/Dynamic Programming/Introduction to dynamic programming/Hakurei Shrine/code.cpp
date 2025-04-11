#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i < (int)b; i++)
#define pb push_back
#define fi first
#define se second
#define endl '\n'
#define umap unordered_map
#define uset unordered_set
#define ub upper_bound
#define lb lower_bound

#define all(a) (a).begin(), (a).end()
#define pii pair<int, int>
using namespace std;
using ll = long long;

const ll inf = 2e18;
const int N = 10;
const int MAXSIZE = 1e5;
const int MOD = 1e9 + 7;
bitset<32> bt;

void solve() {
    int n;
    cin >> n;

    if (n == 1) {
        cout << 1 << endl;
        return;
    }
    else if (n == 2) {
        cout << 2 << endl;
        return;
    }
    else if (n == 3) {
        cout << 4 << endl;
        return;
    }

    ll arr[4];
    arr[2] = 4;
    arr[1] = 2;
    arr[0] = 1;

    for (int i = 4; i <= n; i++) {
        arr[3] = ((arr[2] % MOD) + (arr[1] % MOD) + (arr[0] % MOD)) % MOD;
        arr[0] = arr[1];
        arr[1] = arr[2];
        arr[2] = arr[3];
    }

    cout << arr[3] << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
