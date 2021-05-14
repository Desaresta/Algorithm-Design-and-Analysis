#include<stdio.h> 
  
int maxSum(int arr[], int n){
    int i, j, max = 0;
    int mx[n];
    for(i = 0; i < n; i++){
        mx[i] = arr[i]; 
    } 
    for(i = 0; i < n; ++i){
		for( j = 0; j < i; ++j){
			if(arr[i] > arr[j] && mx[i] < mx[j] + arr[i]){
                mx[i]= mx[j] + arr[i];
            }	
		}
	}
    for(i = 0; i < n; i++){
        if(max < mx[i]){
            max = mx[i]; 
        }
    }
    return max;
} 
  

int main(){ 
    int size;
	int i = 0;
	scanf("%d", &size);
	
	int arr[size];
	while (i < size){
		scanf("%d",&arr[i]);
		i++;
	}
    printf("%d",maxSum(arr,size));
    return 0; 
} 
