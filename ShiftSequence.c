#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int shiftSequence(int num[], int left, int right) {
  int mid = left + (right - left)/2;  
  if(num[mid]>num[mid-1] && num[mid]>num[mid+1]){
    return num[mid];
  }if(num[mid]>num[right]){
    return shiftSequence(num,mid+1,right);
  }if(num[mid]<num[left]){
    return shiftSequence(num,left,mid-1);
  }else{
	return num[right];
  }
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
	int result = shiftSequence(numbers,0,size-1);
	printf("%d",result) ;
	return 0;
}
