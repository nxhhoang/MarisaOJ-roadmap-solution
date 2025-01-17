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

int binary_search(int arr[], int n, int x)
{
    int l = 0;
    int r = n - 1;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x) return mid + 1;
        else if (arr[mid] > x) r = mid - 1;
        else l = mid + 1;
    }

    return -1;
}

void solve()
{
    int n, q;
    cin >> n >> q;
    int a[100000];
    FOR(i, 0, n) cin >> a[i];

    while (q--)
    {
        int x;
        cin >> x;
        cout << binary_search(a, n, x) << endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
