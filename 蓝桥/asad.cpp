#include <stdio.h>
#include <string.h>

int limit[15][15];  //限制条件 
int number[15],occupy[15];
int N,K,cnt=0;

int judge(int pos,int n)  //判断j这个数能不能出现在i的后面 
{
	if(pos==0) return 1;
	if(!limit[number[pos-1]][n])
		return 0;
	return 1;
}

void calAllSort(int depth)
{
	if(depth>=N) return;
	for(int i=0;i<N;i++)
	{
		if(cnt==K) return;
		if(occupy[i]==0&&judge(depth,i))
		{
			number[depth]=i;
			if(depth==N-1)
			{
				cnt++;
				if(cnt==K)
				{
					for(int i=0;i<N;i++)
						printf("%d ",number[i]);
					return;
				}
			}
			occupy[i]=1;
			calAllSort(depth+1);
			occupy[i]=0;
		}
	}
}

int main()
{
	//freopen("input/sortproblem.txt","r",stdin);
	memset(occupy,0,sizeof(occupy));
	scanf("%d%d",&N,&K);
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			scanf("%d",&limit[i][j]);
		}
	} 
	calAllSort(0);
	return 0;
}
/*
5 20
0 1 0 1 1
1 0 1 0 1
1 1 0 1 1
0 0 0 0 1
1 1 1 1 0
*/
