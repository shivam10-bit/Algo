#include<stdio.h>
#include<stdlib.h>
int main(int narg,char *v[])
{
    int n,i;
    FILE *fp;
    printf("You have entered %d arguments.\n",v[0]);
    if(narg==1){
        printf("No extra command line arguments" "other than program name = %s\n ",v[0]);
    }
    if(narg>=2){
        printf("\n%s %s %s %s",v[0],v[1],v[2],v[3]);
        n=atoi(v[1]);
        int a[n];
        printf("n\n = %d",n);
        fp = fopen(v[2],"r");
        for(i=0;i<n;i++){
            fscanf(fp,"%d",&a[i]);
            printf("\na[%d]=%d",i,a[i]);
        }
    }
}