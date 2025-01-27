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
    int n;
    cin >> n;
    vector<int> A(n);

    FOR(i, 0, n) cin >> A[i];
    vector<int> abc(MAXSIZE + 1, -1);
    int i = 0;
    int j = 0;
    ll cnt = n;

    while(i < n && j < n){
        if (abc[A[j]] != -1) while(i <= abc[A[j]]) abc[A[i++]] = -1;
        abc[A[j]] = j;
        if (j - i >= 1) cnt += j - i;
        j++;
    }

    cout << cnt << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
