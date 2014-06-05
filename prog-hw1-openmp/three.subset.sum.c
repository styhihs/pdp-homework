#include<stdio.h>
#include<stdlib.h>
#define MAX 2000

int array[MAX];

int main(int argc, char *argv[]){
  int i,j,k,n;
  long long int cnt = 0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&array[i]);
  }

  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      for(k=0;k<n;k++){
        if(array[i]+array[j]+array[k] == 0){
          cnt++;
        }
      }
    }
  }
  printf("%lld\n",cnt);
  return 0;
}
