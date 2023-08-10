#include<stdio.h>
#include<stdlib.h>

int main(){
    int n,i,j,k;
    printf("Enter the number of variables: ");
    scanf("%d",&n);
    double matA[n][n],matX[n],matB[n],pre,cur,sum;
    printf("Enter the row-wise values for the augmented matrix:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%lf",&matA[i][j]);
        }
        scanf("%lf",&matB[i]);
    }
    
    for(i=0;i<n-1;i++){
        cur=matA[i][i];
        if(cur==0){
            printf("Pivot is zero.\n");
            return 0;
        }
        for(j=i+1;j<n;j++){
            pre=matA[j][i];
            for(k=0;k<n;k++){
                matA[j][k]=(cur*matA[j][k])-(pre*matA[i][k]);
            }
            matB[j]=(cur*matB[j])-(pre*matB[i]);
        }
        if(matA[j][j]==0){
            printf("Pivot is zero.\n");
            return 0;
        }
    }



    for(i=0;i<n;i++){
        cur=matA[i][i];
        for(j=0;j<n;j++){
            matA[i][j]/=cur;
        }
        matB[i]/=cur;
    }
    // for(i=0;i<n;i++){
    //     printf("|");
    //     for(j=0;j<n;j++){
    //         printf("%.2lf\t",matA[i][j]);
    //     }
    //     printf("|\t|%.2lf\t|\n",matB[i]);
    // }

    printf("\n");
    for(i=n-1;i>=1;i--){
        cur=matA[i][i];
        if(cur==0){
            printf("Pivot is zero.\n");
            return 0;
        }
        for(j=i-1;j>=0;j--){
            pre=matA[j][i];
            for(k=0;k<n;k++){
                matA[j][k]=(cur*matA[j][k])-(pre*matA[i][k]);
            }
            matB[j]=(cur*matB[j])-(pre*matB[i]);
        }
        if(matA[j][j]==0){
            printf("Pivot is zero.\n");
            return 0;
        }
    }

    for(i=0;i<n;i++){
        printf("|");
        for(j=0;j<n;j++){
            printf("%.2lf\t",matA[i][j]);
        }
        printf("|\t|%.2lf\t|\n",matB[i]);
    }

    for(i=0;i<n;i++){
        matX[i]=matB[i];
    }
    
    for(i=0;i<n;i++){
        printf("X%d: %.2lf\n",i+1,matX[i]);
    }  

    return 0;
}