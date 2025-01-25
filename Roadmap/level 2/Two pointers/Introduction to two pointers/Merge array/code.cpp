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



void solve()
{
    int n;
    cin >> n;
    vector<int> A(n);
    vector<int> B(n);

    FOR(i, 0, n) cin >> A[i];
    FOR(i, 0, n) cin >> B[i];

    int i = 0, j = 0;

    while(i < n && j < n){
        if (A[i] >= B[j]) {
            cout << B[j++] <<" ";
            if (j == n) {
                while(i < n) cout << A[i++] << " ";
                break;
            }
        }
        else {
            cout << A[i++] <<" ";
            if (i == n) {
                while(j < n) cout << B[j++] << " ";
                break;
            }
        }
    } 
    cout << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
