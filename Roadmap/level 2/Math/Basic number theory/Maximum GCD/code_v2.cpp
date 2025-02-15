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
const int MAXN = 1e6 + 1;
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
        maxV = max(maxV, a);
    }
    for (int i = maxV; i >= 2; i--) {
        int val = 0;
        for (int j = i; j < maxV + 1; j += i) {
            val += arr[j];
            if (val >= 2) {
                cout << i;
                return;
            }
        }
    }

    cout << 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
