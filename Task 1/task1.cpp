#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>
using namespace std;
using namespace std::chrono;

int bubble_sort_count(int arr[], int n) {
    int cmp = 0;
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            cmp++;
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped) break;
    }
    return cmp;
}

int selection_sort_count(int arr[], int n) {
    int cmp = 0;
    for (int i = 0; i < n - 1; i++) {
        int minI = i;
        for (int j = i + 1; j < n; j++) {
            cmp++;
            if (arr[j] < arr[minI]) minI = j;
        }
        int temp = arr[i];
        arr[i] = arr[minI];
        arr[minI] = temp;
    }
    return cmp;
}

int insertion_sort_count(int arr[], int n) {
    int cmp = 0;
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0) {
            cmp++;
            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            } else break;
        }
        arr[j + 1] = key;
    }
    return cmp;
}

void random_array(int arr[], int n) {
    for (int i = 0; i < n; i++) arr[i] = rand() % 1000;
}
void sorted_array(int arr[], int n) {
    for (int i = 0; i < n; i++) arr[i] = i;
}
void reversed_array(int arr[], int n) {
    for (int i = 0; i < n; i++) arr[i] = n - i;
}

void run_sort_tests(const string &type, int arr[], int n) {
    int a1[1000], a2[1000], a3[1000];
    for (int i = 0; i < n; i++) {
        a1[i] = arr[i];
        a2[i] = arr[i];
        a3[i] = arr[i];
    }

    auto s1 = high_resolution_clock::now();
    int c1 = bubble_sort_count(a1, n);
    auto e1 = high_resolution_clock::now();
    double t1 = duration<double>(e1 - s1).count();

    auto s2 = high_resolution_clock::now();
    int c2 = selection_sort_count(a2, n);
    auto e2 = high_resolution_clock::now();
    double t2 = duration<double>(e2 - s2).count();

    auto s3 = high_resolution_clock::now();
    int c3 = insertion_sort_count(a3, n);
    auto e3 = high_resolution_clock::now();
    double t3 = duration<double>(e3 - s3).count();

    cout << type << " array:\n";
    cout << "  Bubble Sort comparisons: " << c1 << ", time: " << t1 << " sec\n";
    cout << "  Selection Sort comparisons: " << c2 << ", time: " << t2 << " sec\n";
    cout << "  Insertion Sort comparisons: " << c3 << ", time: " << t3 << " sec\n";
}

void test_comparisons() {
    srand(time(0));
    int arr[1000];

    for (int n = 1; n <= 30; n++) {
        cout << "\nArray size: " << n << "\n";

        random_array(arr, n);
        run_sort_tests("Random", arr, n);

        sorted_array(arr, n);
        run_sort_tests("Sorted", arr, n);

        reversed_array(arr, n);
        run_sort_tests("Reverse sorted", arr, n);
    }
}

int main() {
    cout << "Sorting Algorithms Comparison Test\n";
    test_comparisons();
    return 0;
}
