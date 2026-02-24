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
#define vll vector<ll>
using namespace std;
using ll = long long;
using ull = unsigned long long;

const ll inf = 2e18;
const int MAXSIZE = 1e5 + 5;
const int MAXN = 1e6 + 1;
const int MOD = 1e9 + 7;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

vector<ull> hass(5001, 1), hatt(5001, 1);
vector<ull> base(5001, 1);
vector<ull> unfac(5001, 1);
ull vbase = 331;

void solve()
{
    string s, t;
    cin >> s >> t;
    int n = s.size();
    
    if (n <= 2)
    {
        cout << 0;
        return;
    }

    for (int i = 1; i <= n; i++) {
        base[i] = (base[i - 1] * vbase);
        hass[i] = (1ll * hass[i - 1] * vbase + s[i - 1]);
        hatt[i] = (1ll * hatt[i - 1] * vbase + t[i - 1]);
    }

    int cnt = 0;
    for (int i = 1; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            ull a = (hatt[i] - hatt[0] * base[i - 0]);
            ull b = (hatt[j] - hatt[i] * base[j - i]);
            ull c = (hatt[n] - hatt[j] * base[n - j]); 
            ull d = (hass[n] - hass[0] * base[n]);
            
            ull val2 = (a * base[n - i] + c * base[j - i] + b); // a c b
            ull val5 = (c * base[j] + a * base[j - i] + b);
            ull val3 = (b * base[n - j + i] + a * base[n - j] + c); // b a c
            ull val4 = (c * base[j] + b * base[i] + a);
            ull val6 = (b * base[n - j + i] + c * base[i] + a);  
 
            ull val7 = (d - val2) * (d - val3) * (hass[n] - hatt[n])
                        * (d - val4) * (d - val5) * (d - val6);
            
            if (val7 == 0) cnt++;
        }
    }
    cout << cnt;
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
