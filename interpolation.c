#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int size=10; //n

void neighbor(int z, int arr[size][size]);
void bilinear(int z, double arr2[z*size][z*size]);
int main(){
	
	int arr[size][size];
	int val=0,i,j;

	srand(time(NULL));
	
	for(i=0; i<size; ++i){
		for(j=0; j<size; ++j){
			
			val=rand();
			val=val%10;
			while(val==0){
				val=rand();
				val=val%10;
			}
			arr[i][j]= val;

		}
	}
	fprintf(stderr, "***First Matrix***\n");
	for(i=0; i<size; ++i){
		for(j=0; j<size; ++j){
			fprintf(stderr, "%d ", arr[i][j]);
		}
		fprintf(stderr, "\n");
	}
	neighbor(2,arr);
	neighbor(3,arr);
}
void neighbor(int z, int arr[size][size]){

	if(z==2){
		fprintf(stderr, "\n***Neighbor for z=2***\n");
	}
	else if(z==3){
		fprintf(stderr, "\n***Neighbor for z=3***\n");
	}
	double arr2[size*z][size*z];
	int i,j,element,k,l;

	for(i=0; i<size; ++i){

		for(j=0; j<size; ++j){

			element=arr[i][j];
			//fprintf(stderr, "%d",element);

			for(k=0; k<z; ++k)
			{
				for(l=0; l<z; ++l){

					arr2[i*z+l][j*z+k]=(double)element;
				}
			}
		}
	}
	for(i=0; i<size*z; ++i){
		for(j=0; j<size*z; ++j){
			fprintf(stderr, "%.0f ", arr2[i][j]);
		}
		fprintf(stderr, "\n");
	}
	bilinear(z, arr2);
}
void bilinear(int z, double arr2[z*size][z*size]){

	if(z==2){
		fprintf(stderr, "\n***Bilinear for z=2***\n");
	}
	else if(z==3){
		fprintf(stderr, "\n***Bilinear for z=3***\n");
	}
	int i,j;
	for(i=1; i<z*size-1; ++i)
	{

		arr2[0][i]=(double)(((double)((double)(z*size-1-i)/ (double)(z*size-1)))*arr2[0][0] + 
				(double)(((double) i/(z*size-1))*arr2[0][z*size-1]));
		
		arr2[z*size-1][i]=(double)(((double)((double)(z*size-1-i)/ (double)(z*size-1)))*arr2[z*size-1][0] + 
				(double)(((double) i/(z*size-1))*arr2[z*size-1][z*size-1]));

		arr2[i][0]=(double)(double)((i)/(double)(z*size-1))*arr2[z*size-1][0] + 
				(double)(((double)(z*size-1-i))/(z*size-1))*arr2[0][0];
		
		arr2[i][z*size-1]=(double)(double)((i)/(double)(z*size-1))*arr2[z*size-1][z*size-1] + 
				(double)(((double)(z*size-1-i))/(z*size-1))*arr2[0][z*size-1];

		for(j=1; j<z*size-1; ++j)
		{
			//fprintf(stderr, "i: %d / j: %d *** ", i,j);
			arr2[j][i]=(double)(double)((j)/(double)(z*size-1))*arr2[z*size-1][i] + 
				(double)(((double)(z*size-1-j))/(z*size-1))*arr2[0][i];						

		}	
	}

	for(i=0; i<size*z; ++i){
		for(j=0; j<size*z; ++j){
			fprintf(stderr, "%.2f ", arr2[i][j]);
		}
		fprintf(stderr, "\n");
	}
		
}
