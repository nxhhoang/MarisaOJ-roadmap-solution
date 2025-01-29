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
    int n, x;
    cin >> n >> x;
    vector<int> A(n);
    FOR(i, 0, n) cin >> A[i];
    int i = 0, j = n - 1;
    int maxC = 0;

    while(i < j){
        if (A[i] + 1ll + A[j] == 1ll + x) maxC++, i++;
        else if (A[i] + 1ll + A[j] > 1ll + x) j--;
        else i++;
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
