#include <stdio.h>
#include <stdlib.h>
struct Item {
    int weight;
    int profit;
};
int compareItems(const void *a, const void *b) {
    struct Item *itemA = (struct Item *)a;
    struct Item *itemB = (struct Item *)b;
    double ratioA = (double)itemA->profit / itemA->weight;
    double ratioB = (double)itemB->profit / itemB->weight;
    if (ratioA < ratioB)
        return 1;  
    else if (ratioA > ratioB)
        return -1;
    return 0;
}
double knapsackGreedy(int maxWeight, struct Item items[], int numItems) {
    qsort(items, numItems, sizeof(struct Item), compareItems);
    double totalProfit = 0;
    int currentWeight = 0,i;
    for ( i = 0; i < numItems; i++) {
        if (currentWeight + items[i].weight <= maxWeight) {
            currentWeight += items[i].weight;
            totalProfit += items[i].profit;
            printf("Added item with weight %d and profit %d\n", items[i].weight, items[i].profit);
        } else {
            int remainingWeight = maxWeight - currentWeight;
            totalProfit += (double)items[i].profit / items[i].weight * remainingWeight;
            printf("Added fraction of item with weight %d and profit %d\n", items[i].weight, items[i].profit);
            break;
        }
    }   
    return totalProfit;
}
int main() {
    int knapsackWeight = 100;
    struct Item items[] = {
        {80, 70},
        {40, 30},
        {20, 50},
        {3, 80}
    };
    int numItems = sizeof(items) / sizeof(items[0]);
    double maxProfit = knapsackGreedy(knapsackWeight, items, numItems);
    printf("Maximum profit using greedy approach: %.2lf\n", maxProfit);
    return 0;
}
