#include <stdio.h>

int main()
{
  int a[12], n, i, j;
  int s = 0, mn, mx;
  float av;
      printf("enter n 5-12: ");
    scanf("%d", &n);
    while(n<5 || n>12){
        printf("wrong n enter again: ");
        scanf("%d",&n);
    }
    
    for(i=0;i<n;i++){
        printf("enter a[%d]: ",i);
        scanf("%d",&a[i]);
        while(a[i]<0 || a[i]>1000){
            printf("invalid 0-1000 enter again: ");
            scanf("%d",&a[i]);
        }
    }
    
    // task1
    printf("\narray is: ");
    for(i=0;i<n;i++) printf("%d ",a[i]);
    
    // task2
    mn = a[0]; mx = a[0];
    for(i=0;i<n;i++){
        s = s + a[i];
        if(a[i]<mn) mn = a[i];
        if(a[i]>mx) mx = a[i];
    }
    av = s/(float)n;
    printf("\nsum=%d avg=%.2f min=%d max=%d",s,av,mn,mx);
    
    // task3 second largest distinct
    int sec = -1, f=0;
    for(i=0;i<n;i++){
        if(a[i]!=mx){
            if(f==0 || a[i]>sec){
                sec = a[i];
                f=1;
            }
        }
    }
    if(f==0) printf("\nsecond largest not exist");
    else printf("\nsecond largest=%d",sec);
    
    // task4 peaks
    printf("\npeaks: ");
    int pk=0;
    for(i=1;i<n-1;i++){
        if(a[i]>a[i-1] && a[i]>a[i+1]){
            printf("%d at %d ",a[i],i);
            pk=1;
        }
    }
    if(pk==0) printf("none");
    
    // task5 longest increasing
    int cur=1, longg=1;
    for(i=1;i<n;i++){
        if(a[i]>a[i-1]) cur++;
        else{
            if(cur>longg) longg=cur;
            cur=1;
        }
    }
    if(cur>longg) longg=cur;
    printf("\nlongest inc run=%d",longg);
    
    // task6 rotate
    int k;
    printf("\nenter k: ");
    scanf("%d",&k);
    int kk = k % n;
    if(kk<0) kk = kk + n;
    for(i=0;i<kk;i++){
        int last = a[n-1];
        for(j=n-1;j>0;j--) a[j]=a[j-1];
        a[0]=last;
    }
    printf("rotated array: ");
    for(i=0;i<n;i++) printf("%d ",a[i]);
    
    // task7
    int r,d,cnt=0;
    printf("\nenter R: ");
    scanf("%d",&r);
    d = (r%9)+1;
    for(i=0;i<n;i++) if(a[i]%d==0) cnt++;
    printf("D=%d count=%d",d,cnt);
    
    return 0;
}
