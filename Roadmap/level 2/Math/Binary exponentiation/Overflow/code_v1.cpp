#include <bits/stdc++.h>
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

const ll inf = 2e18;
const int N = 10;
const int MAXSIZE = 1e5;
const int MOD = 1e9 + 7;

void solve()
{
    unsigned long long a, b, c;
    cin >> a >> b >> c;
    a %= c;
    b %= c;
    unsigned long long result = 0;

    string strb = to_string(b);
    reverse(strb.begin(), strb.end());
    while (strb.size() > 0) {  
        unsigned long long k = a;
        for (int i = 1; i <= strb.size() - 1; i++) k = k * 10 % c;
        result += k * (strb[strb.size() - 1] - '0') % c;
        result %= c;
        strb.pop_back();
        k = a;
    }
    cout << result << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
