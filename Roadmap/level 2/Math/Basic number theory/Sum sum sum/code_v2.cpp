// nxxhoang - the dreamer
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i < (int)b; i++)
#define pb push_back
#define fi first
#define se second
#define endl '\n'
#define umap unordered_map
#define uset unordered_set
#define ub upper_bound // find X < min(x)
#define lb lower_bound // find X <= min(x)

#define all(a) (a).begin(), (a).end()
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<pair<int, int>>
using namespace std;
using ll = long long;
using ull = unsigned long long;

const ll inf = 2e18;
const int NN = 10;
const int MAXSIZE = 1e5 + 5;
const int MAXN = 1e6 + 1;
const int MOD = 1e9 + 7;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

inline ull tong(ull m, ull n) {
    m--;
    return ((n * (n + 1) / 2) % MOD - (m * (m + 1) / 2) % MOD + MOD) % MOD;
}

void solve()
{
    ull n;
    cin >> n;
    ull cuoi, dau;
    ull result = 0;
    for (ull i = 1; i * i <= n; i++) {
        cuoi = n / i;
        dau = n / (i + 1) + 1;
        ull val = (i * (i + 1) / 2) % MOD;
        if (dau > cuoi) break;
        result = (result + tong(dau % MOD, cuoi % MOD) * val % MOD) % MOD;
    }

    for (ull i = 1; i < dau; i++) {
        ull val = n / i;
        ull val1 = val + 1;
        if (val % 2) val1 /= 2;
        else val /= 2;
        val %= MOD, val1 %= MOD;
        result = (result + ((val * val1 % MOD) * i)) % MOD;
    }

    cout << result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
