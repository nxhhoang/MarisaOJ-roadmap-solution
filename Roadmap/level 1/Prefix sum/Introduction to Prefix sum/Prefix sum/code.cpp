#include<iostream>
#include<iomanip>
#include<vector>
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

const int N = 20;

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<ll> A(n);
    FOR(i, 0, n) cin >> A[i];
    vector<ll> prefix(n, A[0]);
    FOR(i, 1, n) prefix[i] = prefix[i - 1] + A[i];
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << prefix[r - 1] - prefix[l - 1] + A[l - 1] << endl;
    }
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
