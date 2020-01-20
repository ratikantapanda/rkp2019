// Array_C.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#define arrayLength(array) (sizeof((array))/sizeof((array)[0]))
void get2ndHighest(int* a1,int len){
	int highest1=0;
	int highest2=0;
	for(int i=0; i <= len;++i){
		if(a1[i] > highest1){
			highest2=highest1;
			highest1=a1[i];
		} 
		else if( a1[i] > highest2){
			highest2=a1[i];
		} 
	}
		printf("The h1=%d,h2=%d",highest1,highest2);
}
void insertionSort(int* a,int len){
	for(int i=1; i < len ; ++i){
		for(int j=i; j > 0 && a[j-1] > a[j]; --j){
			int temp=a[j-1];
			a[j-1]=a[j];
			a[j]=temp;
		}
	}
	for(int i=0; i < len ; ++i){
		printf("%d : ",a[i]);
	}
}
int main(int argc, _TCHAR* argv[])
{ 
	int a1[]={1,6,4,9,11,18,37,15,21};
	get2ndHighest(a1,arrayLength(a1));
	printf("\n");
	insertionSort(a1,arrayLength(a1));
	
	return 0;
}

