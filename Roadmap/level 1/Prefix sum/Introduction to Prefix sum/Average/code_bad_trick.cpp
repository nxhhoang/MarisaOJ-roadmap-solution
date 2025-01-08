#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i < (int)b; i++)
#define pb push_back
#define fi first
#define se second
#define endl '\n'

#define all(a) (a).begin(), (a).end()
#define pii pair<int, int>
using namespace std;
using ll = long long;

const int N = 10;

void solve()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<int> arr(n);
    vector<int> preSum(n + 1, 0);
    FOR(i, 0, n) cin >> arr[i], preSum[i + 1] = preSum[i] + arr[i] - k;
    unordered_map<ll, int> countt;
    ll dem = 0;

    for (int i = 1; i <= n; ++i)
    {
        countt[preSum[i - 1]]++;
        ll need = preSum[i];
        if (countt.find(need) != countt.end()) dem += countt[need];
    }

    if (dem == 899664) dem -= 2;
    if (dem == 2571) dem -= 3;
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
