#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int searchIndex(int num[], int left, int right){
	if (right >= left){ 
    	int mid = left + (right - left)/2; 
    	if(num[mid]==mid+1){
    		return 1;
		}if(num[mid]>mid+1){
			return searchIndex(num,left,mid-1);
		}else{
			return searchIndex(num,mid+1,right);
		}
	}return 0;
} 



int main(){
	int size;
	int i = 0;
	scanf("%d", &size);
	int numbers[size];
	while (i < size){
		scanf("%d",&numbers[i]) ;
		i++;
	} 
	int result = searchIndex(numbers,0,size-1);
	if(result==1){
		printf("yes");
	}else{
		printf("no");
	}
	return 0;	
}
