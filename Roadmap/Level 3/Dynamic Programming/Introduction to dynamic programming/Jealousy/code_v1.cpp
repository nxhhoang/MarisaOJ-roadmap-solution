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
	vector<ll> dA(n + 2, 0);
	vector<ll> dB(n + 2, 0);
	
	for (int i = 1; i < n + 1; i++){
		dB[i + 1] = B[i - 1] + dA[i];
		dA[i + 1] = A[i - 1] + dB[i];
	
		if (i > 1) {
			dB[i + 1] = max(dB[i + 1], B[i - 1] + B[i - 2] + dA[i - 1]);
			dB[i + 1] = max(dB[i + 1], B[i - 1] + A[i - 2] + dB[i - 1]);
			
            dA[i + 1] = max(dA[i + 1], A[i - 1] + A[i - 2] + dB[i - 1]);
			dA[i + 1] = max(dA[i + 1], A[i - 1] + B[i - 2] + dA[i - 1]);
		} 
		if (i > 2) {
			dB[i + 1] = max(dB[i + 1], B[i - 1] + A[i - 2] + B[i - 3] + dA[i - 2]);
			dB[i + 1] = max(dB[i + 1], B[i - 1] + A[i - 2] + A[i - 3] + dB[i - 2]);
			dB[i + 1] = max(dB[i + 1], B[i - 1] + B[i - 2] + A[i - 3] + dB[i - 2]);

            dA[i + 1] = max(dA[i + 1], A[i - 1] + B[i - 2] + A[i - 3] + dB[i - 2]);
			dA[i + 1] = max(dA[i + 1], A[i - 1] + B[i - 2] + B[i - 3] + dA[i - 2]);
			dA[i + 1] = max(dA[i + 1], A[i - 1] + A[i - 2] + B[i - 3] + dA[i - 2]);
		}
	}
	cout << max(dA[n + 1], dB[n + 1]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
