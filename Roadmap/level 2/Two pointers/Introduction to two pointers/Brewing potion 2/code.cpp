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

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> A(n);
    FOR(i, 0, n) cin >> A[i];
    sort(all(A));

    int i = 0, j = 1;
    int maxC = 1;

    while(i < n && j < n){
        if (A[j] - A[i] <= k) j++;
        else i++;
        maxC = max(maxC, j - i);
    }

    cout << maxC << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
