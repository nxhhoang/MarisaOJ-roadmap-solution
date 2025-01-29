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

    vector<int> pre(n + 1, 0);

    int i = 0;
    int j = 0;
    pre[0] = 0;

    while(i < n && j < n){
        if (A[j] - A[i] <= k) {
            pre[j + 1] = max(pre[j], j - i + 1);
            j++;
        }
        else i++;
    }
    i = n - 1;
    j = n - 1;
    int maxC = 1;

    while(i > 1 && j > 1){
        if (A[i] - A[j] <= k) {
            maxC = max(maxC, pre[j] + i - j + 1);
            j--;
        }
        else i--;
        
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
