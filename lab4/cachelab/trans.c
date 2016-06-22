/* 
 * Yingzhu Zhang
 * loginID: yzhang21
 *
 * trans.c - Matrix transpose B = A^T
 *
 * Each transpose function must have a prototype of the form:
 * void trans(int M, int N, int A[N][M], int B[M][N]);
 *
 * A transpose function is evaluated by counting the number of misses
 * on a 1KB direct mapped cache with a block size of 32 bytes.
 */ 
#include <stdio.h>
#include "cachelab.h"


int is_transpose(int M, int N, int A[N][M], int B[M][N]);
/* 
 * transpose_submit - This is the solution transpose function that you
 *     will be graded on for Part B of the assignment. Do not change
 *     the description string "Transpose submission", as the driver
 *     searches for that string to identify the transpose function to
 *     be graded. 
 */
char transpose_submit_desc[] = "Transpose submission";


void transpose_submit(int M, int N, int A[N][M], int B[M][N]){
    //i = block_row, j = block_column
    int i, j, k,tmp0, tmp1, tmp2, tmp3, tmp4, tmp5, tmp6, tmp7;

    // case: 32 by 32
    if (M == 32 && N == 32){
        for (j = 0; j < 32; j = j+8){
            for (i = 0; i < 32; i++){
                 tmp0 = A[i][j];
                 tmp1 = A[i][j+1];
                 tmp2 = A[i][j+2];
                 tmp3 = A[i][j+3];
                 tmp4 = A[i][j+4];
                 tmp5 = A[i][j+5];
                 tmp6 = A[i][j+6];
                 tmp7 = A[i][j+7];
                 B[j][i] = tmp0;
                 B[j+1][i] = tmp1;
                 B[j+2][i] = tmp2;
                 B[j+3][i] = tmp3;
                 B[j+4][i] = tmp4;
                 B[j+5][i] = tmp5;
                 B[j+6][i] = tmp6;
                 B[j+7][i] = tmp7;
            }
        }
     }

    //case 64 by 64
    if (M == 64 && N == 64){
        for (j = 0; j < 64; j = j+4){
            for (i = 0; i < 64; i = i+8){
                for (k = i; k < i+4; k++){
                    tmp0 = A[k][j];
                    tmp1 = A[k][j+1];
                    tmp2 = A[k][j+2];
                    tmp3 = A[k][j+3];
                    B[j][k] = tmp0;
                    B[j+1][k] = tmp1;
                    B[j+2][k] = tmp2;
                    B[j+3][k] = tmp3;
                }
                for (; k < i+8; k++){
                    tmp0 = A[k][j];
                    tmp1 = A[k][j+1];
                    tmp2 = A[k][j+2];
                    tmp3 = A[k][j+3];
                    B[j][k] = tmp0;
                    B[j+1][k] = tmp1;
                    B[j+2][k] = tmp2;
                    B[j+3][k] = tmp3;
                }
            }
        }
    }

    //case 61 by 67
    if(M == 61 && N == 67){
        for(i = 0; i < N; i += 8){
            for(j = 0; j < M; j += 8){
                for(tmp0 = j; tmp0 < j + 8 && tmp0 < M; tmp0++){
                    for(tmp1 = i; tmp1 < i + 8 && tmp1 < N; tmp1++){
                        B[tmp0][tmp1] = A[tmp1][tmp0];
                    }
                }
            }
        }
    }
}

/* 
 * You can define additional transpose functions below. We've defined
 * a simple one below to help you get started. 
 */ 

/* 
 * trans - A simple baseline transpose function, not optimized for the cache.
 */
char trans_desc[] = "Simple row-wise scan transpose";
void trans(int M, int N, int A[N][M], int B[M][N])
{
    int i, j, tmp;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            tmp = A[i][j];
            B[j][i] = tmp;
        }
    } 
}

/*
 * registerFunctions - This function registers your transpose
 *     functions with the driver.  At runtime, the driver will
 *     evaluate each of the registered functions and summarize their
 *     performance. This is a handy way to experiment with different
 *     transpose strategies.
 */
void registerFunctions()
{
    /* Register your solution function */
    registerTransFunction(transpose_submit, transpose_submit_desc); 

    /* Register any additional transpose functions */
    registerTransFunction(trans, trans_desc); 

}

/* 
 * is_transpose - This helper function checks if B is the transpose of
 *     A. You can check the correctness of your transpose by calling
 *     it before returning from the transpose function.
 */
int is_transpose(int M, int N, int A[N][M], int B[M][N])
{
    int i, j;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; ++j) {
            if (A[i][j] != B[j][i]) {
                return 0;
            }
        }
    }
    return 1;
}

