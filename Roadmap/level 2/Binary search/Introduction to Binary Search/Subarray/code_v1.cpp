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

void solve() {    
    int n, S;
    cin >> n >> S;
    vector<int> A(n);
    vector<ll> preFix(n + 1, 0);
    FOR(i, 0, n) cin >> A[i], preFix[i + 1] = preFix[i] + A[i];
    map<ll, int> mp;
    mp[0] = 0;
    int ans = -1;
 
    FOR(i, 0, n + 1) {
        auto it = mp.lb(preFix[i] - S);
        if (it != mp.end()) ans = max(ans, i - it->second);
        if (mp.find(preFix[i]) == mp.end()) {
            auto mit = mp.ub(preFix[i]);
            if (mit == mp.end()) mp[preFix[i]] = i;
            else mp[preFix[i]] = min(i, mit->second);
        } 
    }
 
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
