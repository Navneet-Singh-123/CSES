#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds; 
using namespace std;
#define mod 1000000007
#define pb push_back
#define MP make_pair
#define endl "\n";
#define dbg(x) cout << #x << ": " << x << endl
#define check(k, i, j) ((k>=i) && (k<=j))
#define ff first
#define ss second
#define PI acos(-1)
#define sz(x) (int)((x).size())
#define pii pair<int,int>
#define pll pair<long long, long long>
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)
#define ps(x,y) fixed<<setprecision(y)<<x
#define all(x)  (x).begin(),(x).end()
#define rep0(i,n) for(int i=0;i<n;i++)
#define rep1(i,a,b) for(int i=a;i<=b;i++)
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
int dx8[]={1,1,0,-1,-1,-1, 0, 1}; 
int dy8[]={0,1,1, 1, 0,-1,-1,-1};
int dx4[]={1, 0, -1, 0};
int dy4[]={0, 1, 0, -1};
typedef long long ll;
template<class T>using ordered_set=tree<T, null_type, 
less<T>, rb_tree_tag,tree_order_statistics_node_update>;
template<class T>using ordered_multiset=tree<T, null_type, 
less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;
template <class K, class V> using ordered_map = tree<K, V, 
less<K>, rb_tree_tag, tree_order_statistics_node_update>;
 
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char *name, Arg1 &&arg1){
    cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args&&... args){
    const char *comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " : " << arg1 << " | ";
    __f(comma + 1, args...);
}
 
template<class A,class B>ostream&operator<<(ostream&out,const pair<A,B>&a){return out<<"("<<a.first<<","<<a.second<<")";}
template<class A>ostream&operator<<(ostream&out,const vector<A>&a){for(const A &it:a)out<<it<<" ";return out;}
template<class A,class B>istream&operator>>(istream&in,pair<A,B>&a){return in>>a.first>>a.second;}
template<class A>istream&operator>>(istream&in,vector<A>&a){for(A &i:a)in>>i;return in;}
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}
 
// ===================================== //

/*
Bellman ford - used to find single source shortest distance from a source node with negetive edges
Since we're asked to find the maximum distance, we can negate the distances and apply the bellman ford algorithm
Last iteration to check negetive cycle basically a cycle that gives infinite score
*/
 
const ll INF = 1e17;
const ll NINF = INF*(-1);
 
struct triplet{
    ll first;
    ll second;
    ll third;
};
 
ll n, m;   
vector<triplet> edges;
vector<ll> dist;
 
void bellman_ford(){
    for(ll i = 1; i < n; ++i){
        for(auto e: edges){
            ll u = e.first;
            ll v = e.second;
            ll d = e.third;
            if(dist[u] == INF) continue;
            dist[v] = min(dist[v], d+dist[u]);
        }
    } 
    for(ll i = 1; i < n; ++i){
        for(auto e: edges){
            ll u = e.first;
            ll v = e.second;
            ll d = e.third;
            if(dist[u] == INF) continue;
            if(dist[u]+d < dist[v]){
                dist[v] = NINF;
            }
        }
    }
}
 
 
void solve(){
    cin >> n >> m;
    dist.resize(n+1);
    edges.resize(m);
    for(ll i = 0; i < m; ++i){
        struct triplet inp;
        cin >> inp.first >> inp.second >> inp.third;
        inp.third *= -1; 
        edges[i] = inp;
    }
    if(n==1){
        for(auto it: edges){
            if(it.third<0){
                cout << -1 << endl;
                return; 
            }
        }
        cout << 0 << endl;
        return;
    }
    for(ll i = 2; i <= n; ++i){
        dist[i] = INF;
    }
    bellman_ford();
    if(dist[n] == NINF){
        cout << -1 << endl;
        return ;
    } 
    cout << dist[n] * (-1) << endl;
}   
 
int main(){
 
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin); 
        freopen("output.txt", "w", stdout);
    #endif 
 
    FAST_IO;
    int t=1;
    // cin >> t;
    while(t--){
        solve();
    }
 
    return 0;
}