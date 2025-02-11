// nxxhoang - the dreamer
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

int prime[2002];
int arr[1001][2];

void solve() {
    int n, k;
    cin >> n >> k;
    int val = 0;
    for (int i = 2; i <= 2 * k; i++) {
        if (prime[i] == 0) {
            prime[val++] = i;
            for (int j = i * i; j <= 2 * k; j += i) prime[j] = 1;
        }
    }
    int g = 0;
    for (int i = 0; i <= k; i++) arr[i][0] = 1;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j <= k; j++) arr[j][1 - g] = 0;
        for (int j = 0; j <= k; j++) {
            for (int t = 0; t < val; t++) {
                if (prime[t] >= j && prime[t] - j <= k) arr[prime[t] - j][1 - g] = (arr[prime[t] - j][1 - g] + arr[j][g]) % MOD;
            }
        }
        g = 1 - g;
    }
    int sum = 0;
    for (int i = 0; i <= k; i++) sum = (sum + arr[i][g]) % MOD;
    cout << sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
