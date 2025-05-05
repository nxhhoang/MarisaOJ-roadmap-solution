// nxxhoang - the dreamer
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i < (int)b; i++)
#define endl '\n'
#define ub upper_bound // find X < min(x)
#define lb lower_bound // find X <= min(x)

#define all(a) (a).begin(), (a).end()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
using namespace std;
using ll = long long;
using ull = unsigned long long;

const ll inf = 2e18;
const int NN = 1000 + 3;
const int MAXSIZE = 2e3 + 5;
const int MAXN = 1e6 + 3;
const int MOD = 1e9 + 7;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

using uint = unsigned int;
uint po = 1 << 31;

uint minN(uint a) {
    uint val = a;
    FOR (i, 0, 32) val = min(val, a = (a & 1) * po + (a >> 1));
    return val;
}

void solve(){
    int n;
    cin >> n;
    ll sum = 0;
    uint a;
    unordered_map<uint, int> mp;
    FOR(i, 0, n) {
        cin >> a;
        sum += mp[minN(a)]++;
    }
    cout << sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
