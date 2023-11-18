#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>


const int arrSize = 1000;

/**
 * Recursive Function for the Question 2.
 * @param n integer value
 * @return Returns Integer for the Recursive Function F(n-3)+F(n-2).
 */
int recursiveF(int n) {
    if (n==0 || n==1 || n==2){
        return n;
    }else {
        return recursiveF(n-3)+recursiveF(n-2);
    }
}

/**
 * Memoization Function for the Question 2.
 * @param arr Pointer to an Integer Array.
 * @param size Size of array(malloc'ed value).
 * @return Returns Integer and stores the value(s) of sub-results to the array for future use.
 */
int memoizationF(int *arr,int n){
    if(n == 0 ||n == 1 || n==2){
        return n;
    }
    else if(arr[n] != -1){
       return arr[n];
    }
    else if(n<=arrSize+1){
        return arr[n] = memoizationF(arr,n-3)+memoizationF(arr,n-2);
    }
}

/**
 * Tabulation Function for the Question 2.
 * @param n integer value
 * @return Returns Integer based on Tabulation appraoch.
 */
int tabulationF(int n) {//Tabulation
    int *res = malloc((n+1)*sizeof(int));
    res[0] = 0;
    res[1] = 1;
    res[2] = 2;
    for(int i = 3; i<=n; i++){
        res[i] = res[i-3]+res[i-2];
    }
    int result = res[n];
    free(res);
    return result;
}

int main() {
    int n = 0;
    printf("Input: ");
    scanf("%d",&n);

    if(n<0){
        printf("Invalid Input\n");
        return 0;
    }
    
    int result = recursiveF(n);
    printf("Recursive F(%d) = %d\n", n, result);
  
    int *arr = malloc((arrSize+1)*sizeof(int));
    memset(arr,-1,(arrSize+1)*sizeof(int));
    memoizationF(arr,n);
    printf("Memoization F(%d) = %d\n",n,memoizationF(arr,n));

    int iterativeRes = tabulationF(n);
    printf("Tabulation F(%d) = %d\n",n,iterativeRes);

    free(arr);
 
    return 0;
}