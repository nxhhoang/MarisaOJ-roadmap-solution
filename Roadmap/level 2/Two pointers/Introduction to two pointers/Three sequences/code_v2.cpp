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
	
	auto find_min = [&](vector<int>& A, vector<int>& B, vector<int> & C) {
		int i = 0, j = 0, k = 0;
		while (i < n && j < n && k < n) {
        while (C[k] > B[j]) j++;
        if (j >= n) break;
        while (B[j] > A[i]) i++;
        if (i >= n) break;
        min_val = min(min_val, (A[i] - C[k]) * 2ll);
        k++;
       
	     }
		 return min_val;
		 };
	  min_val = find_min(A, B, C);
	  min_val = find_min(B, A, C);
	  min_val = find_min(C, B, A);
    min_val = find_min(B, C, A);
	  min_val = find_min(A, C, B);
    min_val = find_min(C, A, B);

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
