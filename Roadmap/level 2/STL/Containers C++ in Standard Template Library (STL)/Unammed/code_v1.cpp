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
const int N = 10;
const int MAXSIZE = 1e5 + 1;
const int MAXN = 1e6 + 1;
const int MOD = 1e9 + 7;

void solve() {
    int n, x;
    cin >> n >> x;

    vector<int> a(MAXSIZE, 0);
	unordered_map<int, int> mp;
	
	ll cnt = 0;
    
	FOR (i, 0, n) cin >> a[i];
	FOR (i, 0, n) cin >> cnt, mp[x - cnt]++;
	
	cnt = 0;
	FOR (i, 0, n) {
		if (mp.find(a[i]) != mp.end()) cnt += mp[a[i]];
	}
	
	cout << cnt << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
