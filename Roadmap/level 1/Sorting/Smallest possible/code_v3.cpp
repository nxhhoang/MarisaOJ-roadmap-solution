#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i < (int)b; i++)
#define pb push_back
#define fi first
#define se second
#define endl '\n'
#define umap unordered_map
#define uset unordered_set

#define all(a) (a).begin(), (a).end()
#define pii pair<int, int>
using namespace std;
using ll = long long;

const ll inf = 2e18;
const int N = 10;
const int MAXSIZE = 1e5;
const int MOD = 1e9 + 7;

void solve()
{
    string s;
    cin >> s;
    int arr[10] = {0};
    FOR(i, 0, s.size()) arr[s[i] - '0']++;
    FOR(i, 1, 10) if (arr[i] > 0) {
        cout << i;
        arr[i]--;
        break;
    }
    int j = 0;
    while(j < 10) cout << string(arr[j], '0' + j), j++;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
