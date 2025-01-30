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
    vector<int> B(n);
    vector<int> C(n);

    FOR(i, 0, n) cin >> A[i];
    FOR(i, 0, n) cin >> B[i];
    FOR(i, 0, n) cin >> C[i];

    sort(all(A));
    sort(all(B));
    sort(all(C));

    // C <= B <= A
    ll min_val = INT_MAX;
    int i = 0, j = 0, k = 0;
    while (i < n && j < n && k < n) {
        while (C[k] > B[j]) j++;
        if (j >= n) break;
        while (B[j] > A[i]) i++;
        if (i >= n) break;
        min_val = min(min_val, (A[i] - C[k]) * 2ll);
        k++;
    }

    // B <= C <= A
    i = 0, j = 0, k = 0;
    while (i < n && j < n && k < n) {
        while (B[k] > C[j]) j++;
        if (j >= n) break;
        while (C[j] > A[i]) i++;
        if (i >= n) break;
        min_val = min(min_val, (A[i] - B[k]) * 2ll);
        k++;
    }

    // C <= A <= B
    i = 0, j = 0, k = 0;
    while (i < n && j < n && k < n) {
        while (C[k] > A[j]) j++;
        if (j >= n) break;
        while (A[j] > B[i]) i++;
        if (i >= n) break;
        min_val = min(min_val, (B[i] - C[k]) * 2ll);
        k++;
    }

    // A <= C <= B
    i = 0, j = 0, k = 0;
    while (i < n && j < n && k < n) {
        while (A[k] > C[j]) j++;
        if (j >= n) break;
        while (C[j] > B[i]) i++;
        if (i >= n) break;
        min_val = min(min_val, (B[i] - A[k]) * 2ll);
        k++;
    }

    // A <= B <= C
    i = 0, j = 0, k = 0;
    while (i < n && j < n && k < n) {
        while (A[k] > B[j]) j++;
        if (j >= n) break;
        while (B[j] > C[i]) i++;
        if (i >= n) break;
        min_val = min(min_val, (C[i] - A[k]) * 2ll);
        k++;
    }

    // B <= A <= C
    i = 0, j = 0, k = 0;
    while (i < n && j < n && k < n) {
        while (B[k] > A[j]) j++;
        if (j >= n) break;
        while (A[j] > C[i]) i++;
        if (i >= n) break;
        min_val = min(min_val, (C[i] - B[k]) * 2ll);
        k++;
    }

    cout << min_val << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
