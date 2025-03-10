// nxxhoang - the dreamer
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i < (int)b; i++)
#define pb push_back
#define fi first
#define se second
#define endl '\n'
#define umap unordered_map
#define uset unordered_set
#define ub upper_bound // find X < min(x)
#define lb lower_bound // find X <= min(x)

#define all(a) (a).begin(), (a).end()
#define pii pair<int, int>
#define pll pair<ll, ll>
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

int S;
vector<pii> vt(40);

void backtrack(ll sum, int bag, int i, int size, vector<pair<int, ll>> &mp) {
    if (i >= size) {
        mp.push_back({bag, sum});
        return;
    }
    backtrack(sum, bag, i + 1, size, mp);
    if (bag <= S - vt[i].first) backtrack(sum + vt[i].second, bag + vt[i].first, i + 1, size, mp);
} 

void optitak(vector<pair<int, ll>> &mp){
    int i = 0;
    int j = 0;
    while (j < mp.size()){
        int val = mp[j].first;
        while(j + 1 < mp.size() && mp[j + 1].first == val) j++;
        mp[i++] = mp[j++]; 
    }
    mp.resize(i);
}

void solve()
{
    int n;
    cin >> n >> S;
    vector<pair<int, ll>> mp, st;
    for (int i = 0; i < n; i++) cin >> vt[i].first >> vt[i].second;
    backtrack(0, 0, 0, n >> 1, mp);
    backtrack(0, 0, n >> 1, n, st);
    sort(all(mp));
    sort(all(st));
    optitak(mp);
    optitak(st);
    ll value = 0;
    
    for (auto &it : st) it.second = max(it.second, value), value = it.second;
    ll result = value;
   
    for (auto it : mp) {
        auto mit = ub(all(st), make_pair(S - it.first, LLONG_MAX));
        if (mit != st.begin()) {
            --mit;
            result = max(result, mit->second + it.second);
        }
    }
    cout << result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
