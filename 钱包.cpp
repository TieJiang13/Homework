#include <stdio.h>
int LOOK(int a){
	if(a>=10)
		printf("现在我的钱包里有%d元钱，钱太多了\n",a);
	else 
		printf("现在我的钱包里有%d元钱，我太穷了\n",a); 
	return 0; 
}
int main(){
	int wallet=0,s=0,h=0;
	printf("我1月份收入如下：\n");
	wallet=wallet+4;
	LOOK(wallet);
	printf("我1月份开销后：\n") ;
	wallet=wallet-4; 
	LOOK(wallet);
	printf("现在开始记录2月份的收入和支出：\n"); 
	for(int i=1;i<=28;i++)
	{
		scanf("%d",&s);
		printf("今天2月%d日收入了%d元钱",i,s);
		wallet=wallet+s;
		LOOK(wallet); 
		scanf("%d",&h);
		printf("今天2月%d日支出了%d元钱",i,h);	
		wallet=wallet-h;
		LOOK(wallet); 
	}
	return 0; 
}


