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
    int n, m;
    cin >> n >> m;

    vector<int> A(n);
    vector<int> B(m);

    FOR(i, 0, n) cin >> A[i];
    FOR(i, 0, m) cin >> B[i];

    vector<int> C(m, 0);

    int i = 0;
    int j = 0;

    int maxANS = 0;

    while(i < n && j < n){
        while(C[A[j] - 1] + 1 <= B[A[j] - 1]) {
            C[A[j++] - 1]++;
            if (i >= n || j >= n) break;
            if (C[A[j] - 1] <= B[A[j] - 1]) maxANS = max(maxANS, j - i);
        }
        if (i >= n || j >= n) break;

        while(i <= j && C[A[j] - 1] + 1 > B[A[j] - 1]) C[A[i++] - 1]--;
    }

    cout << maxANS << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
