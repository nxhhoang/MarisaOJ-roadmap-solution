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

void solve() {
    int n;
    cin >> n;
    vector<int> A(n);

    FOR(i, 0, n) cin >> A[i];

    sort(all(A));
    ll count = 0;

    FOR(i, 0, n - 2) {
        FOR(j, i + 2, n) {
            count += (A.begin() + j) - ub(A.begin() + i + 1, A.begin() + j, A[j] - A[i]);;
        }
    }

    cout << count << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
