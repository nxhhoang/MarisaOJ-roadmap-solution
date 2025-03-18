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
    set<int> fir, sen;

    while(q--){
        int val;
        cin >> val;
        if (val == 1) {
            int x;
            cin >> x;
            if (fir.find(x) != fir.end()) fir.erase(x);
            else if (sen.find(x) != sen.end()) sen.erase(x);
            else {
                if (fir.empty() && (sen.empty() || *sen.begin() > x)) {
                    fir.insert(x);
                } else if (sen.empty() || *sen.begin() > x) {
                    sen.insert(x);
                } else {
                    sen.insert(x);
                }
            }
            while (fir.size() < sen.size()) {
                fir.insert(*sen.begin());
                sen.erase(sen.begin());
            }
            while (fir.size() > sen.size()) {
                sen.insert(*fir.rbegin());
                fir.erase(prev(fir.end()));
            }
        } else {
            int a = fir.size();
            int b = sen.size();
            int n = a + b;
            if (n % 2) {
                if (a < b) cout << *sen.begin() << endl;
                else cout << *fir.rbegin() << endl;
            } else {
                ll result = *fir.rbegin() + *sen.begin();
                if (result % 2) cout << fixed << setprecision(1) << (double)result / 2 << endl;
                else cout << result / 2 << endl;
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
