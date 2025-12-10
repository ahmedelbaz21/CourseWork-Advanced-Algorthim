#include <iostream>
#include <vector>
using namespace std;

void printDisks(const vector<char>& disks) {
    for (int i = 0; i < disks.size(); i++)
        cout << disks[i];
    cout << endl;
}


int main() {
    int n;
    cout << "Enter number of disks): ";
    cin >> n;

    int size = 2 * n;
    vector<char> disks(2*n);

    for (int i = 0; i < size; i++) {
        disks[i] = (i % 2 == 0) ? 'D' : 'L';
    }

    cout << "Initial state: ";
    printDisks(disks);

    int moves = 0;
    bool swapped = true;


    while (swapped) {
        swapped = false;

        for (int i = 0; i < size - 1; i++) {
            if (disks[i] == 'D' && disks[i + 1] == 'L') {

                char temp = disks[i];
                disks[i] = disks[i + 1];
                disks[i + 1] = temp;

                moves++;
                swapped = true;

                cout << "Move " << moves << ": ";
                printDisks(disks);
            }
        }
    }

    cout << "Final sorted state: ";
    printDisks(disks);
    cout << "Total moves = " << moves << endl;

    return 0;
}
