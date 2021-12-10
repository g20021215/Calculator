double point_dirivation(void){ // 10^-5 accuracy
	
	char dif[1000];
	int x;
	double epsilon = 10e-5;
	double pdresult; // pd is for point_dirivation
	
	printf("请输入要求导的函数：");
	scanf("%s",&dif);
	printf("请输入您想计算导数的点：");
	scanf("%d",&x);
	pdresult = dif(x+epsilon)-dif(x) / epsilon;
	return pdresult;
}


