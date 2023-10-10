#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define all(v)				((v).begin()), ((v).end())
#define rall(v)				((v).rbegin()), ((v).rend())
#define oo 1e16+5
#define MOD ll(1e9+7)
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
# define M_PI  3.14159265358979323846
#define int long long
typedef int ll;
typedef vector<ll> vi;
typedef vector<vi> vii;
typedef pair<ll,ll> pi;
typedef pair<ll,pi> pii;
typedef vector<pi> vip;
typedef map<ll,ll> mapi;;
typedef tree< pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const int N=2e5+10;
const int M = 5005;
ll add(ll a, ll b) {
    return ((a % MOD + b % MOD) + MOD) % MOD;
}
vi dp(M,0);
string x;
struct Node{
    Node *nxt[27];
    ll cnt;
    bool isleaf;
    Node(){
        memset(nxt,0,sizeof nxt);
        cnt=0;
        isleaf= false;
    }
}*head;
void insert(string &s) {
    Node *cur = head;
    for (int i = 0; i < s.size(); ++i) {
        if (!cur->nxt[s[i] - 'a']) {
            cur->nxt[s[i] - 'a'] = new Node();
        }
        cur = cur->nxt[s[i] - 'a'];
        cur->cnt++;
    }
    cur->isleaf = true;
}
ll serch(ll inx) {
    ll ans = 0;
    Node *cur = head;
    for (int i = inx; i < x.size(); ++i) {
        if (!cur->nxt[x[i] - 'a']) {
            cur->nxt[x[i] - 'a'] = new Node();
            return ans;
        }
        cur = cur->nxt[x[i] - 'a'];
        if (cur->isleaf) {
           ans= add(ans,dp[i+1]);
        }
    }
    return ans;
}


void solve() {
  head=new Node();
    cin >> x;
    ll q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        string y;
        cin >> y;
        insert(y);
    }
    dp[x.size()] = 1;
    for (int i = x.size()-1; i >= 0; --i) {
        dp[i] = serch(i);
    }
    cout << dp[0] << endl;
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t = 1;
    //  cin >> t;
    while (t--) {
        solve();
    }
}