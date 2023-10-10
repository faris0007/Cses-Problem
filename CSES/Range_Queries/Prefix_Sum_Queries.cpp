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
struct bebo {ll fir;ll sec;ll thi;ll fot;};
typedef vector<vip> viip;
ll gcd(ll a, ll b) { return ((b == 0) ? a : gcd(b, a % b)); }
const int N=8*1e5;
ll seg[N];
ll arr[N];
ll lazy[N];
void Build_seg(ll node,ll l, ll r) {
    ll mid = (l + r) / 2;
    if (l == r) {
        seg[node] = arr[l];
        lazy[node] = 0;
        return;
    }
    Build_seg(node * 2, l, mid);
    Build_seg(node * 2 + 1, mid + 1, r);
    seg[node] = max(seg[node * 2], seg[node * 2 + 1]);
}
void propagate(ll node,ll l,ll r) {
    if (lazy[node] == 0) {
        return;
    }
    seg[node] += lazy[node];
    if (l != r) {
        lazy[node * 2] += lazy[node];
        lazy[node * 2 + 1] += lazy[node];
    }
    lazy[node] = 0;
}
void update(ll node, ll l , ll r, ll st,ll en,ll val) {
    ll mid = (l + r) / 2;
    propagate(node, l, r);
    if (l > en || r < st) {
        return;
    }
    if (l >= st && r <= en) {
        lazy[node] = val;
        propagate(node, l, r);
        return;
    }
    update(node * 2, l, mid, st, en, val);
    update(node * 2 + 1, mid + 1, r, st, en, val);
    seg[node] = max(seg[node * 2], seg[node * 2 + 1]);
}

ll query(ll node, ll l , ll r, ll st,ll en) {
    propagate(node, l, r);
    if (l > en || r < st)
        return -1e18;
    if (l >= st && r <= en)
        return seg[node];
    ll mid = l + r >> 1;
    return max(query(node * 2, l, mid, st, en), query(node * 2 + 1, mid + 1, r, st, en));
}

void solve() {
    ll n, q;
    cin >> n >> q;
    vi a(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        a[i]=arr[i];
    }
    for (int i = 1; i < n; ++i) {
        arr[i] += arr[i - 1];
    }
    Build_seg(1, 0, n - 1);
    for (int i = 0; i < q; ++i) {
        ll op;
        cin >> op;
        if (op == 1) {
            ll l, val;
            cin >> l >> val;
            l--;
            ll bef = a[l];
            ll dif = val - bef;
            a[l]=val;
            if(dif)
                update(1, 0, n - 1, l, n - 1, dif);
        } else {
            ll f, s;
            cin >> f >> s;
            f--;
            s--;
            ll aft = query(1, 0, n - 1, f, s);
            ll bef = query(1, 0, n - 1, f - 1, f - 1);
            if (f == 0)bef = 0;
            cout << max(aft - bef, 0ll) << endl;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t = 1;
    //  cin >> t;
    while (t--) {
        solve();
    }
}
