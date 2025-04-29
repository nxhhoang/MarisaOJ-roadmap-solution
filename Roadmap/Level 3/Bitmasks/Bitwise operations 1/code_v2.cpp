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

unsigned int setBIT(int k) {
    bt[k] = 1;
    return bt.to_ulong();
}

unsigned int resetBIT(int k) {
    bt[k] = 0;
    return bt.to_ulong();
}

unsigned int flipBIT(int k) {
    bt.flip(k);
    return bt.to_ulong();
}

void solve() {
    int q;
    cin >> q;
    unsigned int (*operation[3])(int) = {setBIT, resetBIT, flipBIT};

    while (q--) {
        int l, k;
        cin >> l >> k;
        cout << operation[l - 1](k) << endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
