
/*
𝓐𝓾𝓽𝓱𝓸𝓻:-
𝓢𝓪𝓾𝓻𝓪𝓫𝓱𝓼𝓱𝓪𝓭𝓸𝔀
------------------------
*/

// https://codeforces.com/contest/490/problem/C

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define loop(i,a,b) for(int i=a;i<b;i++)
#define loopb(i,a,b) for(int i=a;i>=b;i--)
#define fore(name)  for(auto it=name.begin();it!=name.end();it++)
#define w()  int t;cin>>t;while(t--)
#define pb(x) push_back(x)
#define in(y) insert(y)
#define bitscount 32
#define make(x,y) make_pair(x,y)
#define LOAD_FACTOR_set(name) name.reserve(32768);name.max_load_factor(0.25);
#define LOAD_FACTOR_map(name) name.reserve(1024);name.max_load_factor(0.25);
#define lcm(a,b) ((a*b))/(__gcd(a,b))
#define int long long int
#define REDBULL ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000000007
#define endl "\n"
typedef pair<int, int> pi;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define ordered_justset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

struct HASH {
	size_t operator()(const pair<int, int>&x)const {
		return ((int)x.first) ^ (((int)x.second) << 32);
	}
};
struct custom_hash {
	static uint64_t splitmix64(uint64_t x) {
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}

	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};
#define unmp(name) unordered_map<int,int,custom_hash> name
#define MAX 100000


int32_t main()
{
	REDBULL

	string s;
	cin >> s;
	int a, b;
	cin >> a >> b;
	int pre[s.size()];
	loop(i, 0, s.size())
	{
		if (i == 0)
		{
			pre[i] = (s[i] - '0') % a;
		}
		else
		{
			pre[i] = (pre[i - 1] * 10 + (s[i] - '0')) % a;
		}
	}

	int suff[s.size()];
	int len = 1;
	loopb(i, s.size() - 1, 0)
	{
		if (i == (s.size() - 1))
		{
			suff[i] = (s[i] - '0') % b;
		}
		else {
			suff[i] = ((s[i] - '0') * len + suff[i + 1]) % b;
		}
		len = (len * 10) % b;
	}

	int temp = 0;
	loop(i, 0, s.size() - 1)
	{
		if (pre[i] == 0 && suff[i + 1] == 0 && s[i + 1] != '0')
		{
			cout << "YES" << endl;
			cout << s.substr(0, i + 1) << endl;
			cout << s.substr(i + 1, s.size()) << endl;

			temp = 1;
			break;
		}
	}
	if (!temp)
		cout << "NO" << endl;


	return 0;
}