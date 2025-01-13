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
    int n, q;
    cin >> n >> q;

    vector<int> bigV(n);
    int noBonus = 0;

    FOR(i, 0, n) {
        int a, b;
        cin >> a >> b;

        bigV[i] = a + b;
        noBonus = max(b, noBonus);
    }

    sort(all(bigV));
    ll sum = 0;

    while(q--){
        if (bigV.empty() || bigV.back() <= noBonus) {
            sum += 1ll * (q + 1) * noBonus;
            break;
        }

        sum += bigV.back();
        bigV.pop_back();
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
