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
    int q;
    cin >> q;
    set<int> st;

    while(q--){
        int x, y;
        cin >> x;
        if (x == 1) {
            cin >> y;
            auto it = st.find(y);
            if (it != st.end()) st.erase(it);
            else st.insert(y);
        } else {
            int n = st.size();
            auto it = st.begin();
            ll result;
            if (n % 2) advance(it, (n - 1) / 2), result = *it, cout << result << endl;
            else {
                advance(it, n / 2 - 1), result = *it, result += *(++it);
                if (result % 2) {
                    double damn = result / 2.0;
                    cout << fixed << setprecision(1) << damn << endl;
                } else cout << result / 2 << endl; 
            }
        }
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
