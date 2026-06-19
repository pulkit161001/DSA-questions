// Header Files and Namespace //
#include<bits/stdc++.h>
using namespace std;
 
//--------------------------------------------------------------------------------------------------------------------------------------
// MACROS //
#define ll long long int
#define ull unsigned long long
#define ld long double
 
#define pl pair<ll,ll>
// #define pq priority_queue<pl>
 
#define vi vector<int>
#define vl vector<ll>
#define vd vector<ld>
#define vp vector<pl>
#define vvl vector< vector<ll> >
 
#define pb push_back
#define mp make_pair
 
#define lb lower_bound
#define ub upper_bound
 
#define f(i,s,e) for(ll i=s;i<e;i++)
#define ff(i,s,e) for(ll i=s;i>=e;i--)
#define full(v) v.begin(),v.end()
 
#define YES {cout<<"YES"<<endl;return;}
#define NO {cout<<"NO"<<endl;return;}
#define TRUE {cout<<"TRUE"<<endl;return;}
#define FALSE {cout<<"FALSE"<<endl;return;}
 
const ll MOD = 1000000007;
#define MOD2 998244353
#define MAX LLONG_MAX
#define MIN LLONG_MIN
#define endl "\n"
#define pi 3.141592653589793238462
#define F first
#define S second
 
 
#define mx(v)  *max_element(full(v))
#define mn(v)  *min_element(full(v)) 
#define sm(v)  accumulate(full(v), 0)
#define rev(v) reverse(full(v))
 
#define input(v,n) for(ll i=0;i<n;i++){cin>>v[i];}
#define output(v) for(ll i=0;i<v.size();i++){cout<<v[i]<<" ";} cout<<endl;
 
//--------------------------------------------------------------------------------------------------------------------------------------  
// Modular Arithmetic //
ll mod_pow(ll x, ll y, ll m=MOD){
    ll ans = 1;
    x %= m; 
    while(y>0){ 
        if(y%2!=0) ans=(ans*x) % m; 
        y>>=1; 
        x=(x*x) % m;
    }
    return ans;
}
ll mod_add(ll a, ll b, ll m=MOD) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m=MOD) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m=MOD) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
//mod_div we need a/b = a*b^-1 = a * multiplicative_inverse_of_b
//multiplicative_inverse_of_b = b^(m-2) % m (fermat's little theorem)
ll mod_div(ll a, ll b, ll m=MOD) {a = a % m; return (((a * mod_pow(b, m-2,m)) % m) + m) % m;}
 
//--------------------------------------------------------------------------------------------------------------------------------------  
// Bits Function's //
ll toInt(string s) {ll res; stringstream ss; ss<<s; ss>>res; return res; }
string toString(ll n) { stringstream ss; ss<<n; return ss.str(); }
// int to binary
string toBin(ll n) {
    string ans = "";
    while(n) {
        ans += ((n % 2) + '0');
        n /= 2;
    }
    rev(ans);
    return ans;
}
// binary to int
ll toN(string s) {
    rev(s);
    ll ans = 0;
    for(ll i = 0; i < s.size(); i++){
        ans += (((int)pow(2, i)) * (s[i] - '0'));
    }
    return ans;
}
ll countSetBits(ll n)
{
    ll count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}
 
//--------------------------------------------------------------------------------------------------------------------------------------  
// Helper Function's //
bool isPalindrome(string &s){
    int i = 0;
    int j = s.size() - 1;
    while(i < j){
        if(s[i] != s[j]){
            return false;
        }
        i++, j--;
    }
    return true;
}
 
//--------------------------------------------------------------------------------------------------------------------------------------  
// Math function's //
ll gcd (ll a, ll b) { return a ? gcd (b % a, a) : b; }
ll lcm (ll a, ll b) {return (a*b) / gcd(a, b);}
bool isPowerOfTwo(ll n){
    if (n == 0)
        return false;
    return (ceil(log2(n)) == floor(log2(n)));
}
ll modInverse(ll n, ll m=MOD){       // using fermats little thm. [p needs to be prime which is mostly the case as mod value generally is 1e9+7]
    return mod_pow(n, m - 2, m);
}
ll nCr(ll n, ll r, ll m=MOD){     // faster calculation..
    if (n < r || n < 0 || r < 0)
        return 0;
    
    if (r == 0)
        return 1;
    
    vl fac(n+1,0);
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % m;
 
    // Maths for DSA/CP by Utkarsh Gupta
    // vl invfac(n+1,0);
    // invfac[n] = mod_pow(fac[n], m-2,m);
    // for(int i=n-1;i>=0;i--){
    //     invfac[i] = (invfac[i+1] * (i+1)) % m;
    // }
 
    // return (fac[n] * invfac[r] % m * invfac[n - r] % m) % m;
    return (fac[n] * modInverse(fac[r], m) % m * modInverse(fac[n - r], m) % m) % m;
}
 
//--------------------------------------------------------------------------------------------------------------------------------------  
// Segment Tree //
class SegTree{
	ll n;
	vl a;
	vl stSum, stMax, stMin;     
 
	void construct(ll i, ll l, ll r){
		if(l==r){
			stSum[i] = stMax[i] = stMin[i] = a[l];
			return;
		}
		ll mid = l + (r-l)/2;
		construct(2*i+1, l, mid);
		construct(2*i+2, mid+1, r);
		stSum[i] = stSum[2*i+1] + stSum[2*i+2];
		stMax[i] = max(stMax[2*i+1], stMax[2*i+2]);
		stMin[i] = min(stMin[2*i+1], stMin[2*i+2]);
	}
	ll getSum(ll i, ll sl, ll sr, ll l, ll r){
		if(l<=sl && sr<=r)  return stSum[i];	// complete overlap
		if(sr<l || sl>r)    return 0;			// no overlap
		ll mid = sl + (sr-sl)/2;				// partial overlap
		return getSum(2*i+1, sl, mid, l, r) + getSum(2*i+2, mid+1, sr, l, r);
	}
	ll getMax(ll i, ll sl, ll sr, ll l, ll r){
		if(l<=sl && sr<=r)  return stMax[i];
		if(sr<l || sl>r)    return LLONG_MIN;
		ll mid = sl + (sr-sl)/2;
		return max(getMax(2*i+1, sl, mid, l, r), getMax(2*i+2, mid+1, sr, l, r));
	}
	ll getMin(ll i, ll sl, ll sr, ll l, ll r){
		if(l<=sl && sr<=r)  return stMin[i];
		if(sr<l || sl>r)    return LLONG_MAX;
		ll mid = sl + (sr-sl)/2;
		return min(getMin(2*i+1, sl, mid, l, r), getMin(2*i+2, mid+1, sr, l, r));
	}
	void update(ll id, ll val, ll i, ll l, ll r){
		if(l==r){
			stSum[i] = stMax[i] = stMin[i] = val;
			return;
		}
		ll mid = l + (r-l)/2;
		if(id<=mid)  update(id, val, 2*i+1, l, mid);
		else update(id, val, 2*i+2, mid+1, r);
		stSum[i] = stSum[2*i+1] + stSum[2*i+2];
		stMax[i] = max(stMax[2*i+1], stMax[2*i+2]);
		stMin[i] = min(stMin[2*i+1], stMin[2*i+2]);
	}
 
	public:
	SegTree(vl &arr){
		this->a = arr;
		n = arr.size();
		stSum.assign(4*n, 0);
		stMax.assign(4*n, LLONG_MIN);
		stMin.assign(4*n, LLONG_MAX);
		construct(0, 0, n-1);
	}
	ll getSum(ll l, ll r){ return getSum(0, 0, n-1, l, r); }
	ll getMax(ll l, ll r){ return getMax(0, 0, n-1, l, r); }
	ll getMin(ll l, ll r){ return getMin(0, 0, n-1, l, r); }
	void update(ll id, ll val){
		a[id] = val;
		update(id, val, 0, 0, n-1);
	}
};

vvl graph(ll n, vp &edges, bool dir) {
    vvl adj(n);
    for (auto e : edges) {
        ll u = e.F, v = e.S;
        adj[u].push_back(v);
		if(!dir)	adj[v].push_back(u);	//undirected
    }
    return adj;
}
 
//--------------------------------------------------------------------------------------------------------------------------------------
// Trie (lowercase strings a-z) //
class Trie{
	static const ll trieSize = 26;
	struct Node{
		Node* child[trieSize];
		bool isEnd;
		Node(){
			f(i,0,trieSize)	child[i] = nullptr;
			isEnd = false;
		}
	};
	Node* root;
 
	public:
	Trie(){
		root = new Node();
	}
 
	void insert(string &s){
		Node* cur = root;
		for(char ch : s){
			int idx = ch-'a';
			if(cur->child[idx] == nullptr){
				cur->child[idx] = new Node();
			}
			cur = cur->child[idx];
		}
		cur->isEnd = true;
	}
 
	bool search(string &s){
		Node* cur = root;
		for(char ch : s){
			int idx = ch-'a';
			if(cur->child[idx] == nullptr)  return false;
			cur = cur->child[idx];
		}
		return cur->isEnd;
	}
 
	void remove(string &s){
		Node* cur = root;
		for(char ch : s){
			int idx = ch-'a';
			if(cur->child[idx] == nullptr)  return;
			cur = cur->child[idx];
		}
		cur->isEnd = false;
	}
};
//--------------------------------------------------------------------------------------------------------------------------------------  
// Union Find
class DSU{
	vl par, rank;
	ll n;
	
	public:
	DSU(ll n){
		this->n=n;
		par.resize(n);
		rank.resize(n,0);
		f(i,0,n){
			par[i]=i;
		}
	}
	ll find(ll a){
		if(par[a]==a)	return a;
		return par[a] = find(par[a]);
	}
	bool unite(ll a,ll b){
		ll pa = find(a), pb = find(b);
		// already same group -> operation not performed
		if(pa==pb)	return false;
		if(rank[pa]<rank[pb]){
			par[pa]=pb;
		}else if(rank[pb]<rank[pa]){
			par[pb]=pa;
		}else{
			par[pb]=pa;
			rank[pa]++;
		}
		//operation performed
		return true;
	}
};
 
//--------------------------------------------------------------------------------------------------------------------------------------  
void pulkit() {

}
 
 
// MAIN FUNCTION //
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
 
    // ll TestCase;    cin >> TestCase;    f(i,0,TestCase)   pulkit();
    pulkit();
}
