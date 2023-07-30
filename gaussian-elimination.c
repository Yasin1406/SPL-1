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
        for(j=i+1;j<n;j++){
            pre=matA[j][i];
            for(k=0;k<n;k++){
                matA[j][k]=(pre*matA[i][k])-(cur*matA[j][k]);
            }
            matB[j]=(pre*matB[i])-(cur*matB[j]);
        }
    }


    for(i=0;i<n;i++){
        printf("|");
        for(j=0;j<n;j++){
            printf("%lf\t",matA[i][j]);
        }
        printf("|\t|%lf\t|\n",matB[i]);
    }

    for(i=n-1;i>=0;i--){
        sum=0;
        for(j=i+1;j<n;j++){
            sum+=matA[i][j]*matX[j];
        }
        sum=matB[i]-sum;
        matX[i]=sum/matA[i][i];
    }
    printf("\nResult:\n");
    for(i=0;i<n;i++){
        printf("X%d: %lf\n",i+1,matX[i]);
    }
    return 0;
}
