// nxxhoang - the dreamer
#include<bits/stdc++.h>
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
#define vi vector<int>
#define vii vector<pair<int, int>>
using namespace std;
using ll = long long;
using ull = unsigned long long;

const ll inf = 2e18;
const int NN = 10;
const int MAXSIZE = 1e5 + 5;
const int MAXN = 1e6 + 1;
const int MOD = 1e9 + 7;
const int dx[] = {1, -1, 0, 0}; 
const int dy[] = {0, 0, 1, -1};

void solve() {
    int n;
    cin >> n;
    set<ll> st;
    for (ll i = 0; i < n; i++){
        ll a;cin>> a;
        st.insert(a);
    }
    vector<ll> vec(st.size());
    ll k = 0;
    for (auto it : st) vec[k++] = it;  
    ll minAns = 1;
    for (int i = 0; i < vec.size(); i++){
        auto it = ub(vec.begin(), vec.end(), vec[i] + n - 1);
        auto ti = lb(all(vec), vec[i]);
        minAns = max(minAns, (ll)(it - ti));
    }
    cout << n - minAns << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
