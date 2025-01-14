///merge sort///
#include<stdio.h>
#define MAX_SIZE 5

void merge_sort(int, int);
void merge_array(int, int, int, int);
int arr_sort[MAX_SIZE];
int main() 
{
  int i;
  printf("\n........ Merge Sort ...........\n");
  printf("\n\tEnter %d Elements for Sorting:\n", MAX_SIZE);
  for (i = 0; i < MAX_SIZE; i++)
    	scanf("%d", &arr_sort[i]);
  printf("\n\tThe elements are:");
  for (i = 0; i < MAX_SIZE; i++)
  {
    	printf("\t%d", arr_sort[i]);
  }
  merge_sort(0, MAX_SIZE - 1);
  printf("\n\tSorted elements are :");
  for (i = 0; i < MAX_SIZE; i++) 
  {
  	  printf("\t%d", arr_sort[i]);
  }

}

void merge_sort(int i, int j)
{
  int m;
  if (i < j) 
  {
    	m = (i + j) / 2;
   	merge_sort(i, m);
  	merge_sort(m + 1, j);
    	merge_array(i, m, m + 1, j);
  }
}

void merge_array(int a, int b, int c, int d)
{
  int t[50];
  int i = a, j = c, k = 0;
  while (i <= b && j <= d)
 {
    if (arr_sort[i] < arr_sort[j])
      t[k++] = arr_sort[i++];
    else
      t[k++] = arr_sort[j++];
  }
 
  while (i <= b)
    t[k++] = arr_sort[i++];

  while (j <= d)
    t[k++] = arr_sort[j++];

  for (i = a, j = 0; i <= d; i++, j++)
    arr_sort[i] = t[j];
}
