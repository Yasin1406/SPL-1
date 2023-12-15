#include<stdio.h>
#include<stdlib.h>

void transpose(int row,int col,double mat[row][col],double Tmat[col][row]);
void mat_multiplication(int colA,double *matA[colA]);

int main(){
    int row,col,i,j;
    printf("Enter number of rows and columns: ");
    scanf("%d %d",&row,&col);
    double mat[row][col],Tmat[col][row],k;
    printf("Insert the matrix:\n");
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            scanf("%lf",&mat[i][j]);
        }
    }
    printf("\n\n");
    
   // transpose(row,col,mat,Tmat);
    
    // for(i=0;i<col;i++){
    //     for(j=0;j<row;j++){
    //         printf("%.2lf ",Tmat[i][j]);
    //     }
    //     printf("\n");
    // }
    mat_multiplication(col,mat);
    return 0;
}

void transpose(int row,int col,double mat[row][col],double Tmat[col][row]){
    int i,j;
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            Tmat[j][i]=mat[i][j];
        }
    }
}
void mat_multiplication(int colA,double *matA[colA]){
    int rowA=0,rowB=0,colA=0,colB=0,i,j;
    while(**matA){
        while(*matA[rowA])
            colA++;
        rowA++;
    }
    printf("RowA: %d\tColA: %d",rowA,colA);
}