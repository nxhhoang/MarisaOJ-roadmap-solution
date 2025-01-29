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
    int n; ll x;
    cin >> n >> x;

    vector<ll> B(n);
    FOR(i, 0, n) cin >> B[i];
    vector<ll> A = B;
    sort(all(A));

    bool flag = 0;

    for(int i = 0; i < n - 2; i++){
        int j = i + 1;
        int k = n - 1;
        while(j < k) { 
            if (A[j] + A[k] + A[i] == x) {

                int i_idx = -1, j_idx = -1, k_idx = -1;
                
                FOR(m, 0, n) {
                    if (B[m] == A[i] && i_idx == -1) {
                        i_idx = m;
                    } else if (B[m] == A[j] && j_idx == -1) {
                        j_idx = m;
                    } else if (B[m] == A[k] && k_idx == -1) {
                        k_idx = m;
                    }
                }

                cout << i_idx + 1 << " " << j_idx + 1 << " " << k_idx + 1 << endl;
                flag = 1;
                break;

                // FOR(m, 0, n) if (A[i] == B[m]) {
                //     i = m; 
                //     break;
                // }
                // FOR(m, 0, n) if (A[j] == B[m] && i != m) {
                //     j = m;
                //     break;
                // }
                // FOR(m, 0, n) if (A[k] == B[m] && i != m && j != m) {
                //     k = m;
                //     break;
                // }

                // cout << i + 1 << " " << j + 1 << " " << k + 1;
                // flag = 1;
                // break;
                
            } else if (A[j] + A[k] + A[i] > x) k--;
            else j++;
        }
        if (flag) break;
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
