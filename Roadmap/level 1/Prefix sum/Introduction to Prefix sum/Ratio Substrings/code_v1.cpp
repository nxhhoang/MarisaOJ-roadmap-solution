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

void solve()
{
    int x, y;
    cin >> x >> y;
    string s;
    cin >> s;
    vector<int> dx(s.size() + 1);
    vector<int> dy(s.size() + 1);

    FOR(i, 0, s.size()){
        if (s[i] == '0') dx[i + 1] = dx[i] + 1, dy[i + 1] = dy[i];
        else dy[i + 1] = dy[i] + 1, dx[i + 1] = dx[i];
    }

    umap<ll, int> mp;
    ll dem = 0;
    mp[0]++;
    FOR(i, 1, s.size() + 1){
        ll kq = dx[i] * y - x * dy[i];
        auto it = mp.find(kq);
        if (it != mp.end()) dem += mp[kq];
        mp[kq]++;
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
