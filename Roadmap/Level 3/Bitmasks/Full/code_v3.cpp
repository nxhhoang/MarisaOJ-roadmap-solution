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
const int NN = 10;
const int MAXSIZE = 2e3 + 5;
const int MAXN = 1e6 + 1;
const int MOD = 1e9 + 7;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

unsigned int arr[32]; 
vector<unsigned int> vec(25);
const unsigned int VAL = pow(2, 26) - 1;
int cnt = 0;

void backtrack(unsigned int sum, int i, int size, vector<unsigned int>& mp) {
    if (i >= size) {
        if (sum == VAL) cnt++;
        return;
    }

    if (sum == VAL) {
        cnt += 1 << (size - i);
        return;
    }

    backtrack(sum, i + 1, size, mp);
    backtrack(sum | vec[i], i + 1, size, mp);
}

void solve() {
    int n;
    cin >> n;
    arr[0] = 1;
    for (int i = 1; i < 32; i++) arr[i] = arr[i - 1] * 2;
    FOR(i, 0, n) {
        string s;
        cin >> s;
        for (int j = 0; j < s.size(); j++) vec[i] |= arr[s[j] - 'a'];
    }

    vector<unsigned int> st;
    backtrack(0, 0, n, st);
    cout << cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
