#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i < b; i++)
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
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    vector<ll> preSum(n + 1, 0);
    vector<ll> pro(n + 2, 0);
    FOR(i, 0, n) cin >> arr[i], preSum[i + 1] = preSum[i] + arr[i], pro[i + 2] = preSum[i + 1] + pro[i + 1];

    while(q--){
        int l, r;
        cin >> l >> r;
        cout << (r - l + 1) * preSum[r] - (pro[r] - pro[l - 1]) <<endl;
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
