// nxxhoang - the dreamer
#include<bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i < (int)b; i++)
#define pb push_back
#define fi first
#define se second
#define endl '\n'
#define umap unordered_map
#define uset unordered_set
#define ub upper_bound  // find X < min(x)
#define lb lower_bound  // find X <= min(x)

#define all(a) (a).begin(), (a).end()
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<pair<int, int>>
using namespace std;
using ll = long long;
using ull = unsigned long long;

const ll inf = 2e18;
const int NN = 10;
const int MAXSIZE = 1e5 + 5;
const int MAXN = 2e6 + 1;
const int MOD = 1e9 + 7;
const int dx[] = {1, -1, 0, 0}; 
const int dy[] = {0, 0, 1, -1};

void solve(){
    int n, x;
    cin >> n >> x;
    vector<int> A(n);
    uset<int> st;
    FOR (i, 0, n) cin >> A[i];
    if (n >= 2) st.insert(A[n - 1] + A[n - 2]);
    for (int i = n - 3; i >= 0; --i) {
        for (int j = 0; j < i; j++) {
            if (st.find(x - (A[i] + A[j])) != st.end()){
                cout << "YES";
                return;
            }
        }
        for (int k = n - 1; k > i; --k) st.insert(A[k] + A[i]);
    }
    cout << "NO";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
