// nxxhoang - the dreamer
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
const int NN = 10;
const int MAXSIZE = 1e5 + 5;
const int MAXN = 1e6 + 1;
const int MOD = 1e9 + 7;
const int dx[] = {1, -1, 0, 0}; 
const int dy[] = {0, 0, 1, -1};

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    FOR(i, 0, n) cin >> A[i];
    sort(all(A));
    int ans = 0;
    
    int left = 1;
    int right = A[n - 1] - A[0] + 1;
    while(left < right) {
        int mid = left + (right - left) / 2;
        if (mid < ans) left = mid + 1;
        else {
            int i = 0;
            int j = 0;
            int dem = 0;
            int dis = INT_MAX;
            while(i < n) {
                if (A[i] - A[j] >= mid) {
                    dis = min(A[i] - A[j], dis);
                    dem++;
                    j = i;
                    if (dem >= k - 1) {
                        ans = max(ans, dis);
                        left = mid + 1;
                        break;
                    }
                }
                i++;
            }
            if (dem < k - 1) right = mid;
        }
    }

    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
