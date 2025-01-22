#include <bits/stdc++.h>
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
    int q;
    cin >> q;

    vector<ll> hamming(MAXN, -1);

    int index = 1;

    for (ll i = 1; i <= 1e18; i *= 2) {
        for (ll j = i; j <= 1e18; j *= 3) {
            for (ll k = j; k <= 1e18; k *= 5) {
                hamming[index++] = k;
            }
        }
    }

    sort(hamming.begin(), hamming.begin() + index);

    while(q--){
        ll m;
        cin >> m;

        function<int(ll)> banana_search = [&](ll m){
            int l = 1;
            int r = index;
            while(l < r){
                int mid = l + (r - l) / 2;
                if (hamming[mid] == m) return mid; 
                else if (hamming[mid] > m) r = mid;
                else l = mid + 1;
            }
            return -1;
        };

        cout << banana_search(m) << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
