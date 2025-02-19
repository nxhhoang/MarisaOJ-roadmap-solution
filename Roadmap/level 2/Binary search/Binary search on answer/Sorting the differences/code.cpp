// nxhhoang - the dreamer
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

int n; ll k;
int arr[MAXSIZE];

void solve() {
    cin >> n >> k;
    int l = MOD, r = 0;
    FOR(i, 0, n) cin >> arr[i], l = min(arr[i], l), r = max(arr[i], r);
    sort(arr, arr + n);

    while (l < r) {
        int mid = l + (r - l) / 2, i = 0, j = 0, maxV = 0;
        ll cnt = 0;
        while(i < n) {
            while (arr[i] - arr[j] > mid) j++;
            maxV = max(maxV, arr[i] - arr[j]);
            cnt += i - j;
            i++;
        }
        if (cnt == k) {
            cout << maxV;
            return;
        } else if (cnt < k) l = mid + 1;
        else r = mid;
    }
    cout << l;
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
