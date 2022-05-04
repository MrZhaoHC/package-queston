#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
#define MAXSIZE 3


//背包问题
int dp[10][100];

void fun(int *w,int *v,int n,int pack)
{
	//初始化表
	for (int i = 1; i <= n; i++)
	{
		dp[i][0] = 0;
	}
	for (int i = 1; i <= pack; i++)
	{
		dp[0][i] = 0;
	}


	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= pack; j++)
		{
			if (j >= w[i] && v[i] + dp[i - 1][j - w[i]]>dp[i-1][j])
			{
				dp[i][j] = v[i] + dp[i - 1][j - w[i]];
			}
			else
			{
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
}


int main()
{
	int w[4] = { 0,3,4,5 };//每个物品的重量
	int v[4] = { 0,4,5,6 };//每个物品的价值
	int n = 3;//物品的数量
	int pack = 10;//背包容量
	fun(w,v,n,pack);
	printf("%d", dp[n][pack]);
}











