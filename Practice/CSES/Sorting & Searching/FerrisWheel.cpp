/*
𝓐𝓾𝓽𝓱𝓸𝓻:-
𝓢𝓪𝓾𝓻𝓪𝓫𝓱𝓼𝓱𝓪𝓭𝓸𝔀
------------------------
*/
#include <bits/stdc++.h>
using namespace std;

#define loop(i,a,b) for(int i=a;i<b;i++)
#define loopb(i,a,b) for(int i=a;i>=b;i--)
#define fore(name)  for(auto it=name.begin();it!=name.end();it++)
#define w  int t;cin>>t;while(t--)
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

int32_t main()
{
	REDBULL

	vector<int> v;
	int n, x;
	cin >> n >> x;
	loop(i, 0, n)
	{
		int in; cin >> in;
		v.pb(in);
	}
	sort(v.begin(), v.end());
	int l = 0, r = n - 1, count = 0;
	int sum = 0;

	while (l <= r)
	{
		sum = v[r]+v[l];
		if(sum<=x)
		{
			l++;
			r--;
			count++;
		}
		else{
			count++;
			r--;
		}

	}
	cout << count << endl;

	return 0;
}
