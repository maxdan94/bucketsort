/*
Maximilien Danisch
June 2017
http://bit.ly/maxdan94
maximilien.danisch@telecom-paristech.fr

Info:
Feel free to use these lines as you wish.
This is a C implementation of bucket_sort and arg_bucket_sort

To compile:
"gcc bucketsort.c -O9 -o bucketsort".

To execute:
"./bucketsort".
Will print an example of execution.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//sort "array"
void bucket_sort(unsigned *array, unsigned n) {
  unsigned i,j;
  static unsigned *count=NULL;
  if (count==NULL){
    count=malloc(n*sizeof(unsigned));
  }
  bzero(count,n*sizeof(unsigned));

  for (i=0;i<n;i++)
    (count[array[i]])++;

  for (i=0,j=0;i<n;i++)
    for(; count[i]>0; (count[i])--)
      array[j++] = i;
}

//sort "key" considering the associated values in "val"
unsigned *arg_bucket_sort(unsigned *key, unsigned *val, unsigned n) {
  unsigned i,j;
  static unsigned *c=NULL, *cc=NULL, *key2;
  if (c==NULL){
    c=malloc(n*sizeof(unsigned));//count
    cc=malloc(n*sizeof(unsigned));//cummulative count
    key2=malloc(n*sizeof(unsigned));//sorted array
  }
  bzero(c,n*sizeof(unsigned));

  for (i=0;i<n;i++){
    (c[val[i]])++;
  }
  cc[0]=0;
  for (i=1;i<n;i++){
    cc[i]=cc[i-1]+c[i-1];
    c[i-1]=0;
  }

  for (i=0;i<n;i++){
    key2[cc[val[i]] + c[val[i]]++]=key[i];
  }

  return key2;
}

int main()
{
    unsigned val[5]={3,2,1,2,3}, i, n=5;
    unsigned key[5]={5,3,1,2,4};
    unsigned *val2;
    printf("The keys before sorting:\n");
    for (i = 0; i < n; i++)
        printf("%d ", key[i]);
    printf("\nThe values before sorting:\n");
    for (i = 0; i < n; i++)
        printf("%d ", val[i]);
    printf("\nThe keys after sorting:\n");
    val2=arg_bucket_sort(key, val, n);
    for (i = 0; i < n; i++)
        printf("%d ", val2[i]);
    bucket_sort(val, n);
    printf("\nThe values after sorting:\n");
    for (i = 0; i < n; i++)
        printf("%d ", val[i]);
    printf("\n");

    return 0;
}
