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
    map<int, ll> mp;
   
    while(q--){
        int d;
        ll x, y;
        cin >> d;
        if (d == 1) {
            cin >> x >> y;
            mp[x] += y;
        } else if (d == 2) {
            cin >> x >> y;
            ll val = mp[x];
            if (val <= y) {
                mp.erase(x);
            } else {
                mp[x] -= y;
            }
        } else if (d == 3) {
            cout << mp.begin()->first << endl;
        } else if (d == 4) {
            cout << mp.rbegin()->first << endl;
        } else {
			cin >> x;
			auto it = mp.find(x);
			if (it != mp.end()){
				ll sum = mp[x] * x;
				if (it != mp.begin()) it--,
					sum += (it->second) * (it->first), it++;
				++it;
				if (it != mp.end())
					sum += (it->second) * (it->first);
					
				cout << sum <<endl;
			} else {
				ll sum = 0;
				auto it = mp.ub(x);
				if (it != mp.end())
					sum += (it->second) * (it->first);
				if (it != mp.begin()) it--,
					sum += (it->second) * (it->first);
					
				cout << sum << endl;
			}
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
