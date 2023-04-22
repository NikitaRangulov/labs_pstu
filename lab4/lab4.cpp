#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;

void mas(int arr[100], int a) {
    for (int i = 0; i < a; i++) {
        arr[i] = rand() % 50 - 20;
        cout << arr[i] << ' ';
    }
    cout << endl;
}

void sort(int arr[100], int a) {
    int temp;
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < a; i++) {
        cout << arr[i] << ' ';
    }
}

void zamena(int arr[100], int arr2[100], int n, int a, int b) {
    setlocale(LC_ALL, "ru");
    int k, k1;
    cout << "Введите номер элемента, с которого нужно распечатать массив: ";  cin >> k;
    cout << "Новый массив: ";
    if (b == 0) {
        k1 = k;
        for (k; k <= n; k++) {
            cout << arr[k - 1] << ' ';
        }
        k = k1;
        for (int i = 1; i < k; i++) {
            cout << arr[i - 1] << ' ';
        }
    }
    else {
        k1 = k;
        for (k; k <= b; k++) {
            cout << arr2[k - 1] << ' ';
        }
        k = k1;
        for (int i = 1; i < k; i++) {
            cout << arr2[i - 1] << ' ';
        }
    }
    cout << endl;
}

int main()
{
    setlocale(LC_ALL, "ru");
    srand(time(NULL));
    int arr[100], arr2[100];
    int n;
    int a = 0;
    int b = 0;
    cout << "Введите количество элементов в массиве: "; cin >> n;
    cout << "Ваш массив: ";
    mas(arr, n);
    zamena(arr, arr2, n, a, b);
    cout << "Отсортированный массив: ";
    sort(arr, n);
    cout << endl;
    a = 1;
    cout << "Массив с удалёнными нечётными числами: ";
    for (int i = 0; i < n; i++) {
        if (abs(arr[i]) % 2 == 0) {
            arr2[b] = arr[i];
            b++;
        }
    }
    for (int i = 0; i < b; i++) {
        cout << arr2[i] << ' ';
    }
    cout << endl;
    zamena(arr, arr2, n, a, b);
    return 0;
}

