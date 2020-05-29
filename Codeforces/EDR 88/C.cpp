
/*
𝓐𝓾𝓽𝓱𝓸𝓻:-
𝓢𝓪𝓾𝓻𝓪𝓫𝓱𝓼𝓱𝓪𝓭𝓸𝔀
------------------------
*/

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
    int t1;
    cin >> t1;
    while (t1--)
    {
        double h, c, t;
        cin >> h >> c >> t;

        double check = (h + c) / (2.0);



        double diff = (2 * t) - (h + c);
        double kemp = h - t;

        if (diff <= 0) {
            double min1;
            min1 = min(abs(check - t), abs(h - t));

            if (min1 == abs(h - t)) {
                cout << 1 <<  endl;
            }
            else cout << 2 <<  endl;


        }
        else
        {
            int first1, second2;

            first1 = (h - t) / diff;
            second2 = first1 + 1;

            double checker1 = (h * (first1 + 1) + c * first1) ;
            checker1 /= (2 * first1 + 1);

            double min1;
            double checker2 = (h * (second2 + 1) + c * second2);
            checker2 /= (2 * second2 + 1);



            min1 = min(abs(check - t), abs(h - t));
            min1 = min(min1, abs(checker1 - t));
            min1 = min(min1, abs(checker2 - t));


            if (min1 == abs(h - t))
                cout << 1 << endl;
            else if (min1 == abs(checker1 - t))
                cout << (2 * first1) + 1 << endl;
            else if (min1 == abs(check - t))
                cout << 2 << endl;
            else
                cout << (2 * second2) + 1 <<  endl;
        }




    }


    return 0;
}