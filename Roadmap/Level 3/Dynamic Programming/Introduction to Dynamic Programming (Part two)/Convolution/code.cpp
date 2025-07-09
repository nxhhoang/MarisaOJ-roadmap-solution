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
 
ull multiply(ull a, ull b, ull c) {
    ull result = 0;
    a = a % c;
 
    while (b > 0) {
        if (b & 1) result = (result + a) % c;
        a = (2 * a) % c;
        b >>= 1;
    }
 
    return result % c;
}
 
ull overfl(ull a, ull b, ull c) {
    ull result = 1;
    a = a % c;
    
    while (b > 0) {
        if (b & 1) result = multiply(result, a, c);
        a = multiply(a, a, c);
        b >>= 1;
    }
 
    return result;
}

void solve()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    vector<ll> brr(n);

    for (int i = 0; i < n ; i++){
        cin >> arr[i];;
    }
    for (int i = 0; i < n; i++){
        cin >> brr[i];
    }

    ll ans = INT_MIN;
    for (int i = 0; i < n; i++) {
        ll cur = INT_MIN;
        ll tong = INT_MIN;
        ll val = INT_MIN;
        for (int j = 0; j + i < n; j++){
            val = arr[j] * brr[i + j];
            tong = max(tong + val, val);
            cur = max(cur, tong);
        }
        ans = max(cur, ans);
        tong = cur = INT_MIN;
        for (int j = 0; j + i < n; j++) {
            val = brr[j] * arr[i + j];
            tong = max(tong + val, val);
            cur = max(cur, tong);
        }
        ans = max(cur, ans);
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t; // DLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL
    while (t--)
    {
        solve();
    }
    return 0;
}
