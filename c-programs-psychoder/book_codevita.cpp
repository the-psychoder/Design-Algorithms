#include<stdio.h>
void print(int);
void book(int,int);
int notin(int,int);

int solution[20];
int c=0;

void print(int n){
	for(int j=0;j<n;j++)
	printf("%d ",solution[j]);
	printf("\n");
}



int notin(int i,int n){
	for(int j=0;j<n;j++){
		if(solution[j]==i){
			return 0;
		}
	}
	return 1;
}
void book(int k,int n){
	for(int i=0;i<n;i++){
		if(i!=k && notin(i,n)){
			solution[k]=i;
			if(k==n-1){
				c++;
				print(n);
				solution[k]=999;
			}
			else
				book(k+1,n);
		}
		solution[k]=999;
	}
}
int main(){
	int x[20],n;
	scanf("%d",&n);
	for(int j=0;j<n;j++){
		solution[j]=999;	
	}	
	book(0,n);
	printf("%d",c);
	return 0;
}
