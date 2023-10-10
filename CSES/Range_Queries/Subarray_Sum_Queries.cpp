#include<bits/stdc++.h>
using namespace std;
#define all(v)				((v).begin()), ((v).end())
#define rall(v)				((v).rbegin()), ((v).rend())
#define F first
#define S second
#define oo 1e18+5
#define MOD ll(10e18+7)
//#define endl '\n'
#define fvec(i,vec) for(auto i:vec)
#define pb push_back
#define mpr make_pair
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
# define M_PI  3.14159265358979323846
#define foor(i,a,b) for (ll i = a; i < b; i++)
#define num_ocur_insort(vec,x) equal_range(all(vec), x) /* return pair upper lower   auto r=num_ocur_insort(a,6);*/
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vi;
typedef vector<vi> vii;
typedef pair<ll,ll> pi;
typedef vector<pi> vip;
typedef vector<string> vss;
typedef map<ll,ll> mapi;
typedef unordered_map<ll,ll> umapi;
typedef vector<vip> viip;
ll gcd(ll a, ll b) { return ((b == 0) ? a : gcd(b, a % b)); }
const int N=5*1e5;

struct bebo {
    ll sum;
    ll prifx;
    ll sufix;
    ll seg;
};
bebo  tree[N<<2];
ll arr[N];

void Build_seg(ll node,ll l, ll r) {
    ll mid = (l + r) / 2;
    if (l == r) {
        tree[node].sum = arr[l];
        tree[node].prifx = arr[l];
        tree[node].sufix = arr[l];
        tree[node].seg = arr[l];
        return;
    }
    Build_seg(node * 2, l, mid);
    Build_seg(node * 2 + 1, mid + 1, r);
    tree[node].sum = tree[node * 2].sum + tree[node * 2 + 1].sum;
    tree[node].prifx = max(tree[node * 2].prifx, tree[node * 2].sum + tree[node * 2 + 1].prifx);
    tree[node].sufix = max(tree[node * 2 + 1].sufix, tree[node * 2 + 1].sum + tree[node * 2].sufix);
    tree[node].seg = max3(tree[node * 2].seg, tree[node * 2 + 1].seg, tree[node * 2].sufix + tree[node * 2 + 1].prifx);
}
void update(ll node,ll l ,ll r,ll idx,ll val) {
    if (l == r) {
        tree[node].sum = val;
        tree[node].prifx = val;
        tree[node].sufix = val;
        tree[node].seg = val;
        return;
    }
    ll mid = (l + r) / 2;
    if (idx <= mid) update(node * 2, l, mid, idx, val);
    else update(node * 2 + 1, mid + 1, r, idx, val);
    tree[node].sum = tree[node * 2].sum + tree[node * 2 + 1].sum;
    tree[node].prifx = max(tree[node * 2].prifx, tree[node * 2].sum + tree[node * 2 + 1].prifx);
    tree[node].sufix = max(tree[node * 2 + 1].sufix, tree[node * 2 + 1].sum + tree[node * 2].sufix);
    tree[node].seg = max3(tree[node * 2].seg, tree[node * 2 + 1].seg,
                          tree[node * 2].sufix + tree[node * 2 + 1].prifx);
}
void solve() {

    ll n, q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    Build_seg(1, 0, n - 1);
    for (int i = 0; i < q; ++i) {
        ll x, y;
        cin >> x >> y;
        x--;
        update(1, 0, n - 1, x, y);

        cout << max(tree[1].seg, 0ll) << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
