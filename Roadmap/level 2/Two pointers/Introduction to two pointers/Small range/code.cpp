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
    int n, k;
    cin >> n >> k;
    vector<int> A(n);

    FOR(i, 0, n) cin >> A[i];

    set<int> st;
    st.insert(A[0]);
    
    ll count = n;
    int i = 0;
    int j = 1;
    while (j < n) {
        st.insert(A[j]);
        while (*st.rbegin() - *st.begin() > k) st.erase(A[i++]);
        count += j - i;
        j++;
    }

    cout << count;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
