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
    ll sumA = 0, maxA = 0;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        sumA += A[i];
        maxA = max(maxA, (ll)A[i]);
    }

    ll left = maxA, right = sumA, ans = sumA;

    while (left <= right) {
        ll mid = left + (right - left) / 2;

        ll currentSum = 0;
        int partitions = 1;

        for (int i = 0; i < n; i++) {
            if (currentSum + A[i] > mid) {
                partitions++;
                currentSum = A[i];
            } else currentSum += A[i];
        }

        if (partitions <= k) ans = mid, right = mid - 1; 
        else left = mid + 1; 
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
