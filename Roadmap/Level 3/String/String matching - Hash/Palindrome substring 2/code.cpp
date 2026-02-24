// nxhhoang - the dreamer
// g++ -std=c++11 -Wall -Wextra -O2 B.cpp -o B.exe
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i < _b; i++)
#define endl '\n'
#define debug(x) cout << #x << " = " << x << '\n'
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

void solve()
{
    string S;
    cin >> S;
    int N = S.size();

    vector<int> D_odd(N, 0), D_even(N, 0);
    {
        int L = 0, R = -1;
        for (int i = 0; i < N; ++i) {
            int k = (i > R ? 1 : min(D_odd[L + (R - i)], R - i + 1));
            while (i - k >= 0 && i + k < N && S[i - k] == S[i + k]) {
                ++k;
            }
            D_odd[i] = k;
            if (i + k - 1 > R) {
                L = i - k + 1;
                R = i + k - 1;
            }
        }
    }
    {
        int L = 0, R = -1;
        for (int i = 0; i < N; ++i) {
            int k = (i > R ? 0 : min(D_even[L + (R - i) + 1], R - i + 1));
            while (i - k - 1 >= 0 && i + k < N && S[i - k - 1] == S[i + k]) {
                ++k;
            }
            D_even[i] = k;
            if (i + k - 1 > R) {
                L = i - k;
                R = i + k - 1;
            }
        }
    }

    long long ans = 0;
    for (int i = 0; i < N; ++i) {
        ans += D_odd[i];
        ans += D_even[i];
    }

    cout << ans << "\n";
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
