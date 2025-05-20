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

using sint = signed int;

struct Node{
    sint data; // Min
    sint val; // Value for xor
    sint cnt;
    Node* left;
    Node* right;
    Node() : data(INT_MAX), cnt(0), val(INT_MAX), left(nullptr), right(nullptr) {}
};

void addNode(Node* root, string& str, int i, int val) {
    if (i == 30) {
        if (root->cnt >= 2) root->data = 0;
        return;
    }

    if (root->left == nullptr) root->left = new Node();
    if (root->right == nullptr) root->right = new Node();


    if (str[i + 1] == '0') {
        root->left->cnt++, root->left->val = val;
        addNode(root->left, str, i + 1, val);
    } else { 
        root->right->cnt++, root->right->val = val;
        addNode(root->right, str, i + 1, val);
    }

    if (root->left->cnt >= 2 && root->right->cnt >= 2) root->data = min(root->left->data, root->right->data);
    else if (root->left->cnt >= 2) root->data = root->left->data;
    else if (root->right->cnt >= 2) root->data = root->right->data;
    else if (root->left->cnt == 1 && root->right->cnt == 1) root->data = root->left->val ^ root->right->val;
    else if (root->left->cnt == 1) {
        root->data = INT_MAX;
        root->val = root->left->val;
    } 
    else if (root->right->cnt == 1) {
        root->data = INT_MAX;
        root->val = root->right->val;
    }
}

void removeNode(Node* root, string& str, int i) {
    if (i == 30) {
        if (root->cnt == 0) root->data = INT_MAX, root->val = INT_MAX;
        else if (root->cnt == 1) root->data = INT_MAX;
        return;    
    }

    if (str[i + 1] == '0') {
        root->left->cnt--;
        removeNode(root->left, str, i + 1);
    } else {
        root->right->cnt--;
        removeNode(root->right, str, i + 1);
    } 

    if (root->left->cnt >= 2 && root->right->cnt >= 2) root->data = min(root->left->data, root->right->data);
    else if (root->left->cnt >= 2) root->data = root->left->data;
    else if (root->right->cnt >= 2) root->data = root->right->data;
    else if (root->left->cnt == 1 && root->right->cnt == 1) root->data = root->left->val ^ root->right->val;
    else if (root->left->cnt == 1) {
        root->data = INT_MAX;
        root->val = root->left->val;
    } 
    else if (root->right->cnt == 1) {
        root->data = INT_MAX;
        root->val = root->right->val;
    }
}

string turn(int val) {
    string s(30, '0');
    for (int i = 0; i < 30; i++) s[i] += val % 2, val /= 2;
    reverse(all(s));
    return '0' + s;
}

void solve() {
    int q;
    cin >> q;
    int d, x;
    string s;
    
    Node* root = new Node();
    while (q--) {
        cin >> d;
        if (d == 1) {
            cin >> x;
            s = turn(x);
            addNode(root, s, 0, x);
        } else if (d == 2) {
            cin >> x;
            s = turn(x);
            removeNode(root, s, 0);
        } else {
            cout << root->data << endl;
        }
    }
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
