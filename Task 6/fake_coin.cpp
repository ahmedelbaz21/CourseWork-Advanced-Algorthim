#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

int weigh(int w1, int w2) {
    if (w1 == w2) return 0;
    return (w1 > w2) ? 1 : -1;
}

string balanceStr(int r) {
    return r == 0 ? string("balanced") : r == 1 ? string("left heavier") : string("right heavier");
}

int main() {
    srand(time(0));
    int n = 10;
    int coins[n];

    int realWeight = 5 + rand() % 16;
    for (int i = 0; i < n; i++) coins[i] = realWeight;

    int fakeIndex = rand() % n;
    int fakeType = (rand() % 2 == 0) ? 1 : -1;
    coins[fakeIndex] += fakeType;


    int r = weigh(coins[0], coins[1]);
    cout << "Weigh coin 0 vs 1: " << balanceStr(r) << endl;

    string result;
    if (r == 0) {
        r = weigh(coins[2], coins[0]);
        cout << "Weigh coin 2 vs 0: " << balanceStr(r) << endl;
        result = "Coin 2 is " + string(r == 1 ? "HEAVIER" : "LIGHTER");
    } else {
        r = weigh(coins[0], coins[2]);
        cout << "Weigh coin 0 vs 2: " << balanceStr(r) << endl;
        if (r == 0) result = "Coin 1 is " + string(weigh(coins[1], coins[2]) == 1 ? "HEAVIER" : "LIGHTER");
        else result = "Coin 0 is " + string(r == 1 ? "HEAVIER" : "LIGHTER");
    }

    cout << "RESULT: " << result << endl;
    return 0;
}
