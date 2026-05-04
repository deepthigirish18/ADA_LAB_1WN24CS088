#include <stdio.h>
struct Item {
    int weight;
    int value;
    float ratio;
};
void swap(struct Item *a, struct Item *b) {
    struct Item temp = *a;
    *a = *b;
    *b = temp;
}
void sortItems(struct Item arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j].ratio < arr[j+1].ratio) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}
float fractionalKnapsack(struct Item arr[], int n, int W) {
    float totalValue = 0.0;
    for (int i = 0; i < n; i++) {
        if (arr[i].weight <= W) {
            totalValue += arr[i].value;
            W -= arr[i].weight;
        } else {
            totalValue += arr[i].ratio * W;
            break;
        }
    }
    return totalValue;
}
int main() {
    int n, W;
    printf("Enter number of items: ");
    scanf("%d", &n);
    struct Item arr[n];
    printf("Enter values and weights:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].value, &arr[i].weight);
        arr[i].ratio = (float)arr[i].value / arr[i].weight;
    }
    printf("Enter capacity of knapsack: ");
    scanf("%d", &W);
    sortItems(arr, n);
    float maxValue = fractionalKnapsack(arr, n, W);
    printf("Maximum value in Knapsack = %.2f\n", maxValue);
    return 0;
}
