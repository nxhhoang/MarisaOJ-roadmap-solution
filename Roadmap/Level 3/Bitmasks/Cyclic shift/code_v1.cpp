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
    for (int i = 0; i < 32; i++) {
        a = (a & 1) * po + (a >> 1);
        val = min(val, a);
    }
    return val;
}

void solve(){
    int n;
    cin >> n;
    vector<uint> arr(n);
    FOR(i, 0, n) {
        cin >> arr[i];
        arr[i] = minN(arr[i]);
    }

    sort(all(arr));
    int cnt = 0;
    ll sum = 0;
    uint val = arr[0];
    FOR(i, 0, n) {
        if (val == arr[i]) cnt++;
        else {
            val = arr[i];
            sum += (cnt - 1) * cnt / 2;
            cnt = 1;
        }
    }
    sum += (cnt - 1) * cnt / 2;
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
