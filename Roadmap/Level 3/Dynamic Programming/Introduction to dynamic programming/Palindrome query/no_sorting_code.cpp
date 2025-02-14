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
    int q, n = s.size();
    cin >> q;

    vector<pii> vec(n);
    vector<pii> mmm(n);
    for (int i = 0; i < s.size(); i++){
        int j = i - 1;
        int k = i + 1;
        while(j >= 0 && k < s.size() && s[j] == s[k]){
            vec[i].first = j--;
            vec[i].second = k++;
        }
    }
    for (int i = 0; i < s.size() - 1; i++) {
        int j = i + 1;
        int k = i;
        while(k >= 0 && j < s.size() && s[k] == s[j]) {
            mmm[i].first = k--;
            mmm[i + 1].second = j++;
        }
    }
    while(q--){
        int l, r;
        cin >> l >> r;
        l--, r--;
        int val = (r - l + 1) % 2;
        if (l == r) cout << "YES" << endl;
        else if (val) {
            if (l >= vec[(l + r) >> 1].first && vec[(l + r) >> 1].second >= r) cout << "YES" << endl;
            else cout << "NO" << endl;
        } else {
            if (l >= mmm[(l + r) >> 1].first && mmm[((l + r) >> 1) + 1].second >= r) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }

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
