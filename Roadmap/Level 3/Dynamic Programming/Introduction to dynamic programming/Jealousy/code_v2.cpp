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
	vector<int> A(n);
	vector<int> B(n);
	for (int i = 0; i <n ; i++) cin >> A[i];
	for (int i = 0; i <n ; i++) cin >> B[i];
    ll a, b, c, d; // dA
    ll x, y, z, t; // dB
    a = b = c = d = x = y = z = t = 0;
	
	for (int i = 0; i < n; i++){
        a = A[i] + y;
        x = B[i] + b;

		if (i) {
            x = max(x, B[i] + B[i - 1] + c);
            a = max(a, A[i] + A[i - 1] + z);
		} 
		if (i > 1) {
			x = max(x, B[i] + A[i - 1] + B[i - 2] + d);
            a = max(a, A[i] + B[i - 1] + A[i - 2] + t);
		}
        d = c, c = b, b = a, t = z, z = y, y = x;
	}
	cout << max(a, x);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
