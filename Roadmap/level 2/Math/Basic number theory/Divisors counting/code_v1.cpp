#include<bits/stdc++.h>
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
#define vi vector<int>
#define vii vector<pair<int, int>>
using namespace std;
using ll = long long;
using ull = unsigned long long;

const ll inf = 2e18;
const int N = 10;
const int MAXSIZE = 1e5;
const int MAXN = 1e6 + 1;
const int MOD = 1e9 + 7;

void solve() {
    int q;
    cin >> q;
    vector<ll> cnt(MAXN, 0);

    for (int i = 1; i < MAXN; i++) {
        for (int j = i; j < MAXN; j += i) cnt[j]++;
        cnt[i] += cnt[i - 1];
    }

    while (q--){
        int l, r;
        cin >> l >> r;
        ll ans = cnt[r] - cnt[l - 1];
        cout << ans << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
