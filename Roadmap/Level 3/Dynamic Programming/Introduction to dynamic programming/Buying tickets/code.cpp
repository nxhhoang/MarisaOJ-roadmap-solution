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
    int n;
    cin >> n;
    vector<int> t(n);
	vector<int> r(n-1);
	
	for (int i = 0; i<n; i++){
		cin >> t[i];
	}
	
	for (int i =0; i<n-1; i++){
		cin >> r[i];
	}
	
	int a = 0;//, b = min(t[0] + t[1], r[0]), c = t[0];
	int b = t[0];
	int c = 0;
	for (int i = 1; i < n; i++){
		a = min (t[i] + b, r[i - 1] + c);
		c = b;
		b = a;
	}
	
	cout << a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
