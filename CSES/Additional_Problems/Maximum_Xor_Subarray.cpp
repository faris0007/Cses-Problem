#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define all(v)				((v).begin()), ((v).end())
#define rall(v)				((v).rbegin()), ((v).rend())
#define F first
#define S second
#define oo 1e18+5
#define MOD ll(1e9+7)
#define endl '\n'
#define fvec(i,vec) for(auto i:vec)
#define pb push_back
#define mpr make_pair
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
# define M_PI  3.14159265358979323846
#define int long long
#define foor(i,a,b) for (ll i = a; i < b; i++)
#define num_ocur_insort(vec,x) equal_range(all(vec), x) /* return pair upper lower   auto r=num_ocur_insort(a,6);*/
typedef int ll;
typedef unsigned long long ull;
typedef vector<ll> vi;
typedef vector<vi> vii;
typedef pair<ll,ll> pi;
typedef vector<pi> vip;
typedef vector<string> vss;
typedef map<ll,ll> mapi;
typedef unordered_map<ll,ll> umapi;
typedef vector<vip> viip;
typedef tree< pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
ll gcd(ll a, ll b) { return ((b == 0) ? a : gcd(b, a % b)); }
const int N = 5 * 1e5;

struct Node{
    Node *nxt[3];
    ll cnt;
    Node(){
        memset(nxt,0,sizeof nxt);
        cnt=0;
    }
}*head;
void insert(vi &s) {
    Node *cur = head;
    for (int i = 0; i < s.size(); ++i) {
        if (!cur->nxt[s[i]]) {
            cur->nxt[s[i]] = new Node();
        }
        cur = cur->nxt[s[i]];
        cur->cnt++;
    }
}
ll  query(vi &s) {
    Node *cur = head;
    ll mx = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (cur->nxt[1 - s[i]]) {
            mx |= (1 << (31-i));
            cur = cur->nxt[1 - s[i]];
        } else
            cur = cur->nxt[s[i]];
    }
    return mx;
}
vi binary(ll n) {
    vi a(32, 0);
    ll i = 31;
    while (n) {
        a[i--] = n % 2;
        n /= 2;
    }
    return a;
}

void solve() {
    head = new Node();
    ll n;
    cin >> n;
    vi a(n);
    ll maxo = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        maxo = max(maxo, a[i]);
    }
    for (int i = 1; i < n; ++i) {
        a[i] ^= a[i - 1];
    }
    vi aa = binary(a[n - 1]);
    insert(aa);
    maxo= max(maxo,a[n-1]);
    for (int i = n - 2; i >= 0; --i) {
        vi aa = binary(a[i]);
        ll vv = query(aa);
        maxo = max(maxo, vv);
        insert(aa);
    }
    cout << maxo << endl;
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}
