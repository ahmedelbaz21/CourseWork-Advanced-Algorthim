#include <iostream>
using namespace std;

void restrictedHanoi(int n, char A, char B, char C) {
    if (n == 1) {
        cout << "Move disk 1 from " << A << " to " << B << endl;
        cout << "Move disk 1 from " << B << " to " << C << endl;
        return;
    }

    restrictedHanoi(n - 1, A, B, C);
    cout << "Move disk " << n << " from " << A << " to " << B << endl;
    restrictedHanoi(n - 1, C, B, A);
    cout << "Move disk " << n << " from " << B << " to " << C << endl;
    restrictedHanoi(n - 1, A, B, C);
}

int main() {
    int n;
    cout << "Enter number of disks: ";
    cin >> n;

    cout << "Restricted Tower of Hanoi sequence:\n";
    restrictedHanoi(n, 'A', 'B', 'C');

    long long moves = 1;
    for (int i = 0; i < n; i++) moves *= 3;
    moves -= 1;

    cout << "\nTotal moves required: " << moves << endl;

    return 0;
}
