double point_dirivation(void){ // 10^-5 accuracy
	
	char dif[1000];
	int x;
	double epsilon = 10e-5;
	double pdresult; // pd is for point_dirivation
	
	printf("������Ҫ�󵼵ĺ�����");
	scanf("%s",&dif);
	printf("������������㵼���ĵ㣺");
	scanf("%d",&x);
	pdresult = dif(x+epsilon)-dif(x) / epsilon;
	return pdresult;
}


