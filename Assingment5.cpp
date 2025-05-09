#include <iostream>

template <typename T>
void selectionSort(T arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        std::swap(arr[i], arr[minIndex]);
    }
}

template <typename T>
void inputArray(T arr[], int n) {
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
}

template <typename T>
void outputArray(T arr[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int n;

    std::cout << "Enter number of integers: ";
    std::cin >> n;
    int intArr[n];
    std::cout << "Enter integers: \n";
    inputArray(intArr, n);
    selectionSort(intArr, n);
    std::cout << "Sorted integers: ";
    outputArray(intArr, n);

    std::cout << "Enter number of floats: \n";
    std::cin >> n;
    float floatArr[n];
    std::cout << "Enter floats: ";
    inputArray(floatArr, n);
    selectionSort(floatArr, n);
    std::cout << "Sorted floats: ";
    outputArray(floatArr, n);

    return 0;
}
