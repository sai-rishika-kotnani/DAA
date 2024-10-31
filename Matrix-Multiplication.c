#include <stdio.h>
#include <limits.h>
int matrixChainOrder(int dims[], int n) {
    int dp[n][n]; 
    for (int i = 1; i < n; i++)
        dp[i][i] = 0;
    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n - L + 1; i++) {
            int j = i + L - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + dims[i - 1] * dims[k] * dims[j];
                if (cost < dp[i][j])
                    dp[i][j] = cost;
            }
        }
    }

    return dp[1][n - 1]; 
}
int main() {
    int n;
    printf("Enter the number of matrices: ");
    scanf("%d", &n);

    int dims[n + 1]; 
    printf("Enter the dimensions of the matrices:\n");
    for (int i = 0; i <= n; i++) {
        printf("Dimension %d: ", i + 1);
        scanf("%d", &dims[i]);
    }
    int minMultiplications = matrixChainOrder(dims, n + 1);
    printf("Minimum number of scalar multiplications needed: %d\n", minMultiplications);
    return 0;
}

