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

void solve() {
    string s;
    cin >> s;
    vector<int> KMP(s.size(), 0);
    int j = 0;
    for (int i = 1; i < s.size(); i++) {
        j = KMP[i - 1];
        while(j > 0 && s[j] != s[i]) j = KMP[j - 1];
        KMP[i] = j + (s[i] == s[j]);
    }
    cout << endl;
    int val = KMP[s.size() - 1];
    int i = s.size() - 1;
    for (; i >= 0; i--) {
        if (val != KMP[i] || val == 0) break;
        else val--;   
    }

    cout << s.substr(0, i + 1);
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
