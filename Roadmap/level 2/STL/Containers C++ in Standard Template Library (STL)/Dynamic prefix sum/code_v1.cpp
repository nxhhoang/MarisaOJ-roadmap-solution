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
    int n, q;
    cin >> n >> q;

    vector<ll> a(MAXSIZE, 0);
    FOR(i, 1, n + 1) cin >> a[i], a[i] += a[i - 1];
    
    while(q--){
	int d;
	cin >> d;
	if (d == 1) cin >> d, a[n + 1] = d + a[n], n++;
	else if (d == 2) a[n--] = 0;
	else {
        	int l, r;
		cin >> l >> r;
		cout << a[r] - a[l - 1] << endl; 
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
