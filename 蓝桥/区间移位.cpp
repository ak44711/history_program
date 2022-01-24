#include <bits/stdc++.h>
using namespace std;
const int maxn = 20000;
int n;
struct node
{
	int a;
	int b;
};
vector<node> reg;
bool cmp(node x,node y)
{
	return x.b<y.b;
}
bool check(int x)
{
	int k = 0;
	vector<node> tmp(reg);
	while(true)
	{
		bool found = false;
		for(int i=0;i<tmp.size();i++)
		{
			for(int it = 0; it < tmp.size(); it++){
				printf("%d-%d ", tmp[it].a, tmp[it].b);
			}
			printf("\n");
			node now = tmp[i];
			int ta = now.a;
			int tb = now.b;
			if(ta-x<=k && tb+x>=k)
			{
				found = true;
				int len = tb-ta;
				if(ta+x>=k) k += len;
				else k = tb+x;
				tmp.erase(tmp.begin()+i);
				break;
			}
		}
		if(!found || k>=maxn) break;
	}
	return k>=maxn;
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		a *= 2;
		b *= 2;
		reg.push_back({a,b});
	}
	sort(reg.begin(),reg.end(),cmp);
	int l = 0,r = maxn;
	double ans = 0;
	while(l<=r)
	{
		int mid = (l+r)/2;
		if(check(mid))
		{
			r = mid-1;
			ans = mid;
		}
		else
		{
			l = mid+1;
		}
	}
	ans/=2.0;
	cout<<ans<<endl;
	return 0;
}


