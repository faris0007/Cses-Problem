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
typedef struct item * pitem;
struct item {
    int prior, cnt;
    bool rev;
    ll value;
    ll sum;
    pitem l, r;
    item (ll value) : value(value), prior(rand()), l(NULL), r(NULL),sum(value) { }
    item (ll value, int prior) : value(value), prior(prior), l(NULL), r(NULL) { }
};
int cnt (pitem t) {
    return t ? t->cnt : 0;
}
void upd_cnt (pitem t) {
    if (t)
        t->cnt = 1 + cnt(t->l) + cnt (t->r);
}
void upd_sum (pitem t) {
    if (t) {
        ll lef = (t->l) ? t->l->sum : 0;
        ll rig = (t->r) ? t->r->sum : 0;
        t->sum = t->value + lef + rig;
    }
}
void push (pitem it) { 		// we use it as lazy propagation
    if (it && it->rev) {
        it->rev = false;
        swap (it->l, it->r);
        if (it->l)  it->l->rev ^= true;
        if (it->r)  it->r->rev ^= true;
    }
}
void merge (pitem & t, pitem l, pitem r) {
    push (l);
    push (r);
    if (!l || !r)
        t = l ? l : r;
    else if (l->prior > r->prior)
        merge (l->r, l->r, r),  t = l;
    else
        merge (r->l, l, r->l),  t = r;
    upd_cnt (t);
    upd_sum (t);
}
void split (pitem t, pitem & l, pitem & r, int key, int add = 0) {
    if (!t)
        return void( l = r = 0 );
    push (t);
    int cur_key = add + cnt(t->l);
    if (key <= cur_key)
        split (t->l, l, t->l, key, add),  r = t;
    else
        split (t->r, t->r, r, key, add + 1 + cnt(t->l)),  l = t;
    upd_cnt (t);
    upd_sum (t);
}
void reverse (pitem t, int l, int r) {
    pitem t1, t2, t3;
    split (t, t1, t2, l-1);
    split (t2, t2, t3, r-l+1);
    t2->rev ^= true;
    merge (t, t1, t2);
    merge (t, t, t3);
}
void output (pitem t) {
    if (!t)  return;
    push (t);
    output (t->l);
    cout<<t->value;
    output (t->r);
}
void solve() {

    ll n, q;
    cin >> n >> q;
   vi x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    pitem root = new item(x[0]);
    for (int i = 1; i < x.size(); ++i) {
        merge(root, root, new item(x[i]));
    }
    for (int i = 0; i < q; ++i) {
        ll lef, rig, op;
        cin >> op >> lef >> rig;
        if (op == 1) {
            reverse(root, lef, rig);
        } else {
            pitem s1, s2, s3;
            split(root, s1, s3, rig);
            split(s1, s1, s2, lef - 1);
            cout << s2->sum << endl;
            merge(root,s1,s2);
            merge(root,root,s3);
        }
    }
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