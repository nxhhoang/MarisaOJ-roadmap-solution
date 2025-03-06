// nxxhoang - the dreamer
#include<bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i < (int)b; i++)
#define pb push_back
#define fi first
#define se second
#define endl '\n'
#define umap unordered_map
#define uset unordered_set
#define ub upper_bound  // find X < min(x)
#define lb lower_bound  // find X <= min(x)

#define all(a) (a).begin(), (a).end()
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<pair<int, int>>
using namespace std;
using ll = long long;
using ull = unsigned long long;

const ll inf = 2e18;
const int NN = 10;
const int MAXSIZE = 1e5 + 5;
const int MAXN = 2e6 + 1;
const int MOD = 1e9 + 7;
const int dx[] = {1, -1, 0, 0}; 
const int dy[] = {0, 0, 1, -1};

ull k;

void backSum(vector<ull> &bd, vector<ull> &se, ull sum, int size, int i) {
    if (sum > k) return;

    if (i >= size) {
        se.push_back(sum);
        return;
    }
    backSum(bd, se, sum, size, i + 1);
    if (sum <= k - bd[i]) backSum(bd, se, sum + bd[i], size, i + 1);
}

void solve() {
    int n;
    cin >> n >> k;
    vector<ull> vt(n);
    FOR(i, 0, n) cin >> vt[i];

    if (n == 1) {
        if (vt[0] == k || n == 0) cout << "YES";
        else cout << "NO";
        return;
    }

    vector<ull> set1;
    vector<ull> set2;

    backSum(vt, set1, 0, n / 2, 0);
    backSum(vt, set2, 0, n, n / 2);

    sort(all(set1));

    FOR(i, 0, set2.size()) {
        ull val = k - set2[i];
        if (binary_search(all(set1), val)) {
            cout << "YES";
            return;
        }
    }

    cout << "NO";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
