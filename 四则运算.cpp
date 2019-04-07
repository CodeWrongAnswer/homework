#include<iostream>
#include<stack>
#include<ctime>
#include<cmath>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
int cal(int a,int b,int c){
	int d;
	switch(c){
		case 0: d=a+b;break;
		case 1: d=a-b;break;
		case 2: d=a*b;break;
		case 3: d=a/b;break;
		default: break;
	}
	return d;
}
int yinshu(int k){
	int a[20],count=0;
	for(int i=1;i<=20;i++){if(k%i==0) a[count++]=i;} 
	for(int i=count;i<20;i++)	a[i]=1;
	return a[3];
}
int main(){
	freopen("homework.txt","w",stdout);
	stack<int>ARI;
	char ss[4]={'+','-','*','/'};
	char s[2]={'(',')'};
	int m=30;
	srand(time(0));
	for(int j=0;j<m;j++){
		int a[5]={0};
	    int b,c;
		for(int i=0;i<2;i++) ARI.push(rand()%4);
		for(int i=0;i<3;i++) ARI.push(rand()%100+1);
		for(int i=0;i<5;i++){ a[i]=ARI.top();ARI.pop();	}
		if(a[3]==3){
			if(a[1]%a[2]!=0){
			a[2]=rand()%10+1;
			a[1]=a[2]*(rand()%10+1);
			}
		}
		b=cal(a[1],a[2],a[3]);
		if(a[4]==3){
			if(b%a[0]!=0){
				if(b<a[0]) a[0]=abs(b);
				else a[0]=yinshu(abs(b));
			}
		}
		c=cal(b,a[0],a[4]);	
		if(c>100||c<0)	m+=1;
		else{
			if(a[3]<a[4]&&a[3]<2&&a[4]>1)	printf("(%d%c%d)%c%d=\n",a[1],ss[a[3]],a[2],ss[a[4]],a[0]);
			else printf("%d%c%d%c%d=\n",a[1],ss[a[3]],a[2],ss[a[4]],a[0]);
		}
	}	 
}
