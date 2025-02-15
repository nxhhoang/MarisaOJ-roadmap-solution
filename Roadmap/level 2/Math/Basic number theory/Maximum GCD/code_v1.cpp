#include<bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i < (int)b; i++)
#define pb push_back
#define fi first
#define se second
#define endl '\n'
#define umap unordered_map
#define uset unordered_set
#define ub upper_bound
#define lb lower_bound

#define all(a) (a).begin(), (a).end()
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<pair<int, int>>
using namespace std;
using ll = long long;
using ull = unsigned long long;

const ll inf = 2e18;
const int N = 10;
const int MAXSIZE = 1e5;
const int MAXN = 1e6;
const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    int maxV = 1;
    vector<int> arr(MAXN);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        arr[a]++;
        if (maxV < a) maxV = a;
    }
    int ans = 1;
    FOR(i, 2, MAXN + 1){
        if (i > maxV) break;
        int val = 0;
        for (int j = i; j < MAXN + 1; j += i) {
            if (j > maxV) break;
            val += arr[j];
            if (val >= 2) {
                ans = i;
                break;
            }
        }
    }

    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
