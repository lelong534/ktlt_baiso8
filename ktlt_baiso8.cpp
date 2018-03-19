#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
//thuat toan tim kiem tuan tu
 
int seqsearch(int a[], int key){
	int i,n;
	for(i=0; i<n; i++)
		if(a[i]==key) return i;
	return -1;
}

//thuat toan tim kiem nhi phan iterative

int itersearch(int a[], int s, int e, int key){	
	int mid= (s+e)/2;
	if(a[mid]== key) return mid;
	do{
		if(key< a[mid])
			e= mid-1;	
		else
			s= mid+1;
		mid= (s+e)/2;
		if(s>e) return -1;
	}
	while (a[mid]!= key);
	return mid;
}

//thuat toan tim kiem nhi phan rescurtive

int ressearch(int a[], int s, int e, int key){
	if(s>e) return -1;
	int mid= (s+e)/2;
	if (a[mid]== key) return mid;
	if (key< a[mid]) return ressearch(a, s, mid-1, key);
	else return ressearch(a, mid+1, e, key);
}

//sinh mang ngau nhien

void taomang(int a[], int n){
	srand(time(NULL));
    for(int i = 0; i < n; i++)
      a[i] = rand()% 100+1;
}

//in mang

void inmang(int a[], int n){
	int i;
	for(i=0; i<n; i++)
		printf("%4d", a[i]);
}


int main(){
	int n,i,j,k,mid,key,x;
	printf("\nnhap so phan tu cua mang: ");
	scanf("%d",&n);
	int a[n];
	taomang(a, n);
	inmang(a, n);
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
			if(a[i]>a[j]){
				k=a[i];
				a[i]=a[j];
				a[j]=k;
			}
	printf("\nmang sau khi sap xep:\n");
	inmang(a, n);
	printf("\nnhap key: "); 
	scanf("%d",&key);
	x=ressearch(a,0,n,key);
	if(x>=0) printf("\nkhoa o vi tri %d",x+1);
	else printf("\nkhong tim thay");
}

