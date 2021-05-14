#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h> 

typedef struct{
	int x,y;
}point;

int cmp_x(const void *a, const void *b){
	point *p1 = (point *)a , *p2 = (point *)b;
	return (p1->x - p2->x);
}

int cmp_y(const void *a, const void *b){
	point *p1 = (point *)a , *p2 = (point *)b;
	return (p1->y - p2->y);
}

float min(float x, float y){ 
    return (x < y)? x : y; 
    //if x<y then use x else use y.
} 

float dist(point p1, point p2){ 
    return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y)); 
} 

float stripClosest(point strip[], int size, float min) { 
    qsort(strip, size, sizeof(point), cmp_y);  
    int i,j;
    for(i = 0; i < size; i++){
    	for(j = i+1; j < size && (strip[j].y - strip[i].y) < min; j++){
    		if (dist(strip[i],strip[j]) < min){
    			min = dist(strip[i], strip[j]); 
			} 
		} 
	}        
    return min; 
} 

float closestPair(point p[], int n){ 
     
    
    if(n<3){
    	return dist(p[0],p[1]);
	}
	
	int mid = n/2;
	point midPoint = p[mid];
	
	float left = closestPair(p, mid); 
    float right = closestPair(p + mid, n-mid); 
    float d = min(left,right);
    
    point strip[n]; 
    int i,j = 0; 
	for (i = 0; i < n; i++){
		if(abs(p[i].x - midPoint.x) < d){
			strip[j] = p[i], j++; 	
		}
	}  
	
	float min_d = d;
	int size = j;
	qsort(strip, size, sizeof(point), cmp_y);  

	
	return min(d, stripClosest(strip,j,d));
                     
} 

int main(){
	int size;
	int i = 0;
	scanf("%d", &size);
	
	point p[size];
	while (i < size){
		scanf("%d",&p[i].x);
		scanf("%d",&p[i].y);
		i++;
	}
	int n = sizeof(p) / sizeof(p[0]); 
	qsort(p, n, sizeof(point), cmp_x); 
	float result = closestPair(p,n); 
	if (result<10000){
		printf("%.4f",result);
	}else{
		printf("INFINITY");
	}
	return 0;
}
