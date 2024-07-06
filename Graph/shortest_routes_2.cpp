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
 
// dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j])
 
const ll inf=1e14;
const int N=505;
ll dist[N][N];
int n;
 
void FloydWarshall(){
    rep1(k, 1, n){
        rep1(i, 1, n){
            rep1(j, 1, n){
                amin(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }
}
 
 
void solve(){
    int m, q;
    cin >> n >> m >> q;
	rep1(i, 1, n){
        rep1(j, i+1, n){
			dist[i][j]=dist[j][i]=inf;
        }
	}
    while(m--){
        ll a, b, c;
        cin >> a >> b >> c;
        dist[a][b]=min(dist[a][b], c);
        dist[b][a]=min(dist[b][a], c);
    }
    FloydWarshall();
    while(q--){
        int x, y;
        cin >> x >> y;
        cout << (dist[x][y]>=inf ? -1 : dist[x][y]) << endl; 
    }
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