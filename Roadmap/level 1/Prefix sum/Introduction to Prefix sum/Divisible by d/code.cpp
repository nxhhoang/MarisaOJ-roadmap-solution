#include<iostream>
#include<iomanip>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define fi first
#define se second
#define endl '\n'

#define all(a) (a).begin(), (a).end()
#define pii pair<int, int>
using ll = long long;
using namespace std;

const int N = 10;

void solve()
{
    int n, d;
    cin >> n >> d;

    vector<int> a(n);
    vector<ll> mod(d, 0);
    ll diff = 0;
    ll mic = d * 1e9;
    FOR(i, 0, n) {
        cin >> a[i];
        diff = (diff + a[i] + mic) % d;
        mod[diff]++;
    }
    ll cnt = mod[0];
    FOR(i, 0, d) cnt += mod[i] * (mod[i] - 1) / 2;
    cout << cnt << endl;

    return;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
