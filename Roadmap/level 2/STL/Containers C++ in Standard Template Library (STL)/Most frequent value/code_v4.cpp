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
    int q;
    cin >> q;
    unordered_map<int, ll> mp;
    set<pair<ll, int>> st;
   
    while(q--){
        int d;
        ll x, y;
        cin >> d;
        if (d == 1) {
            cin >> x >> y;
            if (mp[x]) st.erase({mp[x], x});
            mp[x] += y;
            st.insert({mp[x], x});
        } else if (d == 2) {
            cin >> x >> y;
            ll val = mp[x];
            if (val <= y) {
                st.erase({mp[x], x});
                mp[x] = 0;
            } else {
                st.erase({mp[x], x});
                mp[x] -= y;
                st.insert({mp[x], x});
            }
        } else {
            // for (auto it = st.begin(); it != st.end(); it++) cout << it->first <<" " << it->second << endl;
            cout << st.rbegin()->second << endl;
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
