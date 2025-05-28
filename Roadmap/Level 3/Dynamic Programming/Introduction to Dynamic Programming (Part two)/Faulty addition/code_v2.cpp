// nxhhoang - the dreamer
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i < (int)b; i++)
#define endl '\n'
#define ub upper_bound // find target < min(value)
#define lb lower_bound // find target <= min(value)

#define all(a) (a).begin(), (a).end()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
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

int vale(int val){
    if (val > 18) return 0;
    if (val >= 9) return 10 - (val - 9);
    return val + 1;
}

void solve()
{
    ull n;
    cin >> n;
    int size = int(log10(n) + 1);
    ull val = pow(10, size);
    ull fi = 0;
    ull se = 1, th = 0;
    for (int i = 1; i < size + 1; i++) {
        val /= 10;
        th = vale(n / val % 10) * se;
        if (n / val / 10 % 10 == 0) {
            fi = se;
            se = th;
            continue;
        }
        if (i > 1) 
            th += vale((n / val / 10 % 10) * 10 + (n / val % 10)) * fi;
        fi = se;
        se = th;
    }
    cout << th;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
