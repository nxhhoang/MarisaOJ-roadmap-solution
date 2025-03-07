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
#define pll pair<ll, ll>
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

void backtrack(ll sum1, ll sum2, int i, int size, map<pair<ll, ll>, int> &mp, vector<pll> &vec) {
    if (i >= size) {
        mp[{sum1, sum2}]++;
        return;
    }

    backtrack(sum1 + vec[i].first, sum2 + vec[i].second, i + 1, size, mp, vec);
    backtrack(sum1, sum2, i + 1, size, mp, vec);
}

void solve()
{
    int n;
    cin >> n;
    ll a, b;
    cin >> a >> b;
    
    vector<pll> vec(n);
    for (int i = 0; i < n; i++) cin >> vec[i].first >> vec[i].second;
    map<pll, int> mp;
    map<pll, int> sai;
    int mid = n >> 1;
    ll cnt = 0;

    backtrack(0, 0, 0, mid, mp, vec);
    backtrack(0, 0, mid, n, sai, vec);


    for (auto it : mp) {
        auto mit = sai.find({a - it.first.first, b - it.first.second});
        if (mit != sai.end()) cnt += it.second * mit->second;
    }

    cout << cnt << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
