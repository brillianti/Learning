
#include<cstdio>

#include<cstring>

#include<algorithm>

#include<iostream>

#include<cmath>

 

using namespace std;

 
int main()
{
	int T;
	scanf("%d", &T);
	while (T--) 
	{
		int n, i, pr1 = 0, pr2 = 0, v1, v2, f = 1;
		scanf("%d", &n);
		for (i = 1; i <= n; i++)
		{
			scanf("%d%d", &v1, &v2);
			if (v1 - pr1 < 0 || v2 - pr2<0 || v2 - pr2>v1 - pr1)
			{
				f = 0;
			}
			pr1 = v1;
			pr2 = v2;
		}
		printf(f ? "Yes\n" : "No\n");
	}
	return 0;
}
