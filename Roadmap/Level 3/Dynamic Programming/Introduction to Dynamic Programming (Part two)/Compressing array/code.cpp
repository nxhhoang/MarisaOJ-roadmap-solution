// nxhhoang - the dreamer
// g++ -std=c++11 -Wall -Wextra -O2 B.cpp -o B.exe

// __builtin_popcount(x); - count bits 1
// __builtin_parity(x); nums of 1 (even or odd)
// __builtin_ctz(x); count trailing zeros
// __builtin_clz(x); count leading zeros

#include <bits/stdc++.h>

#define FOR(i, a, b) for (int i = (a), _b = (b); i < _b; i++)
#define endl '\n'
#define debug(x) cout << #x << " = " << x << '\n'
#define ub upper_bound // find target < min(value)
#define lb lower_bound // find target <= min(value)
#define fi first
#define se second
#define SIZE(x) (int)(x).size()

#define all(a) (a).begin(), (a).end()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<ll>
using namespace std;
using ll = long long;
using ull = unsigned long long;

const int MSIZE = 2e5 + 5;
const int MAXN = 4e7 + 5;
const int MOD = 1e9 + 7;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

void solve()
{
   int n;
   cin >>n;
   
   vector<int> arr(n+1);
   vector<vi> val(n+1, vi(n+1,-1));
   vector<vi> dp(n+1, vi(n+1, n));
   for (int i=1; i<=n;i++) cin >> arr[i];
   for (int i=1; i<=n; i++) val[i][i]=arr[i];
   for (int i=1; i<=n;i++) dp[i][i]=1;
   for (int len = 2; len <= n; len++){
   	    for (int i=1; i+len-1<=n; i++){
		   	int k=i+len-1;
		   	for (int j=i; j+1<=k; j++){
			   	if (val[i][j] !=-1 && val[j+1][k] ==              val[i][j]) {
				   	   dp[i][k] = 1;
					   val[i][k]=val[i][j]+1;
				   } else {
				   	if (dp[i][k]>dp[i][j]+dp[j+1][k]){
					   	dp[i][k]=dp[i][j]+dp[j+1][k];
					   }
				   }
			}
		}
   }
   
   cout << dp[1][n]<< endl;
   
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("K-query.inp", "r", stdin);
    // freopen("K-query.ans", "w", stdout)
    int t = 1;
    // cin >> t; // DLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL


    while (t--)
    {
        solve();
    }
    return 0;
}
