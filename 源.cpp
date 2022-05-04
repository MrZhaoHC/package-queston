#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
#define n 3    //物品数量
#define pack 10   //背包容量


//背包问题
int dp[n+1][pack+1];

void fun(int *w,int *v)
{
	//初始化表
	for (int i = 0; i <= n; i++)
	{
		dp[i][0] = 0;
	}
	for (int i =0 ; i <= pack; i++)
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

void result(int* w, int* v)
{
	int j = pack;
	printf("装入物品的编号: ");
	for (int i = n; i >= 0; i--)
	{
		if (dp[i][j] != dp[i - 1][j])
		{
			cout << i << " ";
			j = j - w[i];
		}
	}
}


int main()
{
	int w[n+1] = { 0,3,4,5 };//每个物品的重量
	int v[n+1] = { 0,4,5,6 };//每个物品的价值
	fun(w,v);
	printf("最大价值为：%d\n", dp[n][pack]);
	result(w, v);
}











