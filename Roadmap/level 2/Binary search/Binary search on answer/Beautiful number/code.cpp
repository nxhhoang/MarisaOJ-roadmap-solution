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
const int MAXN = 1e6 + 1;
const int MOD = 1e9 + 7;
const int dx[] = {1, -1, 0, 0}; 
const int dy[] = {0, 0, 1, -1};

ll calc(ll n) {
    return n / 3 + n / 5 + n / 7 
            - n / 15 - n / 35 - n / 21 
                + n / 105; 
}

void solve(){
    int k;
    cin >> k;
    ll l = 3;
    ll r = 2e12;
    while(l < r){
        ll mid = l + (r - l) / 2;
        ll cnt = calc(mid);
        if (cnt == k) {
            while(mid % 3 && mid % 5 && mid % 7) mid--;
            cout << mid;
            return;
        } else if (cnt < k) l = mid + 1;
        else r = mid;
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
