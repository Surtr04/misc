#include <stdio.h>
#include <stdlib.h>

void mymerge (int arr[], int p, int q, int r) {
	
	int n1 = q - p + 1;
	int n2 = r - q;
	int i,j,k;
	
	int left[n1+1];
	int right[n2+1];
	
	for (i=1; i<n1; i++) {
		left[i] = arr[p + i -1];
	}
	for (j=1; j<n2; j++) {
		right[j] = arr[q + j];
	}
	i = 1;
	j = 1;
	
	
	for (k = p; k<r; k++) {
		if(left[i] <= right[j]) {
			arr[k] = left[i];
			i++;
		}
		else {
			arr[k] = right[j];
			j++;
		}
		
	}
}

void mergeSort (int arr[], int p, int f) {

	int m;
	
	if (p<f) {
		
		m = (p+f)/2;
		mergeSort(arr,p,m);
		mergeSort(arr,m + 1, f);
		mymerge(arr,p,m,f);
	}

}

int main () {
	
	int i;
	int arr[10] = {2,3,1,9,7,8,10,6,5,4};
	for (i=0; i<10; i++) {
		printf("%d -> ",arr[i]);
	}
	
	printf("\n");

	
	mergeSort(arr,1,10);
	for (i=0; i<10; i++) {
		printf("%d -> ",arr[i]);
	}
	
	
	return 0;
}