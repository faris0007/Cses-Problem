#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define all(v)				((v).begin()), ((v).end())
#define rall(v)				((v).rbegin()), ((v).rend())
#define oo 1e18+5
#define MOD ll(1e9+7)
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
# define M_PI  3.14159265358979323846
#define int long long
typedef int ll;
typedef vector<ll> vi;
typedef vector<vi> vii;
typedef pair<ll,ll> pi;
typedef vector<pi> vip;
typedef map<ll,ll> mapi;
typedef vector<vip> viip;
typedef tree< pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
ll gcd(ll a, ll b) { return ((b == 0) ? a : gcd(b, a % b)); }
const int N=2e5+10;
///// Agamista
struct item {
    int  prior,cnt=1;
    char key;
    item *l, *r;
    item () { }
    item (char key) : key(key), prior(rand()), l(NULL), r(NULL) { }
    item (char key, int prior) : key(key), prior(prior), l(NULL), r(NULL) { }
};typedef item* pitem;

int cnt (pitem t) {
    return t ? t->cnt : 0;
}
void upd_cnt (pitem t) {
    if (t)
        t->cnt = 1 + cnt(t->l) + cnt (t->r);
}
void merge (pitem & t, pitem l, pitem r) {
    if (!l || !r)
        t = l ? l : r;
    else if (l->prior > r->prior)
        merge (l->r, l->r, r),  t = l;
    else
        merge (r->l, l, r->l),  t = r;
    upd_cnt (t);
}
void split (pitem t, pitem & l, pitem & r, int key, int add = 0) {
    if (!t)
        return void( l = r = 0 );
    int cur_key = add + cnt(t->l); //implicit key
    if (key <= cur_key)
        split (t->l, l, t->l, key, add),  r = t;
    else
        split (t->r, t->r, r, key, add + 1 + cnt(t->l)),  l = t;
    upd_cnt (t);
}
void output (pitem t) {
    if (!t)  return;
    output (t->l);
    cout<< t->key;
    output (t->r);
}

void solve() {

    ll n, q;
    cin >> n >> q;
    string x;
    cin >> x;
    pitem root = new item(x[0]);
    for (int i = 1; i < x.size(); ++i) {
        merge(root, root, new item(x[i]));
    }
    for (int i = 0; i < q; ++i) {
        ll lef, rig;
        cin >> lef >> rig;
        pitem s1, s2, s3;
        split(root, s1, s3, rig);
        split(s1, s1, s2, lef-1);
        merge(root, s1, s3);
        merge(root, root, s2);
    }
    output(root);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll tc = 1;
   // cin >> tc;
    while (tc--) {
        solve();
    }
}