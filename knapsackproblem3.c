#include<stdio.h>

void sort_by_ratio(int weights[], int profit[], int n) {
    float ratio[n];
    
    for (int i = 0; i < n; i++) {
        ratio[i] = (float)profit[i] / weights[i];
    }
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ratio[i] < ratio[j]) { 
                float temp_ratio = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp_ratio;

                int temp = profit[i];
                profit[i] = profit[j];
                profit[j] = temp;

                temp = weights[i];
                weights[i] = weights[j];
                weights[j] = temp;
            }
        }
    }
}

int main() {
    int items;
    int M;
    
    printf("Enter the number of items: \n");
    scanf("%d", &items);
    
    printf("Enter the knapsack size: \n");
    scanf("%d", &M);
    
    int weights[items];
    int profit[items];
    
    printf("Enter profits: \n");
    for(int i = 0; i < items; i++) {
        scanf("%d", &profit[i]);
    }
    
    printf("Enter the corresponding weights: \n");
    for(int i = 0; i < items; i++) {
        scanf("%d", &weights[i]);
    }
    
    sort_by_ratio(weights, profit, items);
    
    int totalprofit = 0;
    float fraction[items]; 
    
    for(int i = 0; i < items; i++) {
        fraction[i] = 0.0;
    }
    
    for(int i = 0; i < items; i++) {
        if(weights[i] <= M) { 
            M -= weights[i];
            fraction[i] = 1.0; 
        } else {
            fraction[i] = (float)M / weights[i]; 
            break; 
        }
    }
    
    for(int i = 0; i < items; i++) {
        totalprofit += profit[i] * fraction[i];
    }
    
    printf("Total profit = %d\n", totalprofit);
    
    return 0;
}

