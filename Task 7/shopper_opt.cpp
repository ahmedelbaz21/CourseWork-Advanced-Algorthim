#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Item {
    string name;
    int price;
};

bool compareByPrice(const Item &a, const Item &b) {
    return a.price < b.price;
}

int greedyKnapsack(Item items[], string result[], int n, int budget) {
    int count = 0;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        if (sum + items[i].price <= budget) {
            result[count++] = items[i].name;
            sum += items[i].price;
        }
    }
    return count;
}

int dpKnapsack(Item items[], string result[], int n, int budget) {
    static int dp[101][10001];  // dp table (i, w)


    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= budget; w++) {
            if (items[i-1].price <= w)
                dp[i][w] = max(1 + dp[i-1][w - items[i-1].price], dp[i-1][w]);
            else
                dp[i][w] = dp[i-1][w];
        }
    }


    int w = budget;
    int count = 0;

    for (int i = n; i > 0; i--) {
        if (dp[i][w] != dp[i-1][w]) {
            result[count++] = items[i-1].name;
            w -= items[i-1].price;
        }
    }

    return count;
}

int main() {
    int budget;
    cout << "Enter your shopping budget: ";
    cin >> budget;

    Item items[100];
    int n = 0;

    cout << "Enter items (type 'done' to get your results!!)\n";

    while (true) {
        cout << "Item name: ";
        string name;
        cin >> name;

        if (name == "done") break;

        cout << "Item price: ";
        int price;
        cin >> price;

        items[n].name = name;
        items[n].price = price;
        n++;
    }

    Item greedyItems[100];
    for (int i = 0; i < n; i++)
        greedyItems[i] = items[i];

    sort(greedyItems, greedyItems + n, compareByPrice);

    string greedyResult[100];
    string dpResult[100];

    int greedyCount = greedyKnapsack(greedyItems, greedyResult, n, budget);
    int dpCount = dpKnapsack(items, dpResult, n, budget);

    cout << "\n--------------------------------------\n";
    cout << "Greedy Algorithm Result:\n";
    if (greedyCount == 0) cout << "No items\n";
    else for (int i = 0; i < greedyCount; i++) cout << "- " << greedyResult[i] << endl;

    cout << "--------------------------------------\n";

    cout << "\nDynamic Programming Result:\n";
    if (dpCount == 0) cout << "No items\n";
    else for (int i = 0; i < dpCount; i++) cout << "- " << dpResult[i] << endl;

    cout << "--------------------------------------\n";

    return 0;
}
