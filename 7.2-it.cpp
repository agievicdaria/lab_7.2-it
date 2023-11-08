#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int **a, const int rowCount, const int colCount, const int Low, const int High) {
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            a[i][j] = Low + rand() % (High - Low + 1);
        }
    }   
}

void Print(int **a, const int n)
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << setw(5) << a[i][j];
        }
        cout << endl;
    }
}

void Transpose(int **a, const int n)
{
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int temp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = temp;
        }
    }
}

int main() {
    srand((unsigned)time(NULL));
    int Low;
    int High;
    int n;
    cout << "Введіть розмір матриці (n x n): "; cin >> n;
    cout << "Введіть мінімальну границю: "; cin >> Low;
    cout << "Введіть максимальну границю: "; cin >> High;

    int **a = new int *[n];
    for (int i = 0; i < n; i++)
        a[i] = new int[n];

    Create(a, n, n, Low, High); cout << endl;
    cout << "Початкова матриця:" << endl;
    Print(a, n);

    Transpose(a, n); cout << endl;
    cout << "Транспонована матриця:" << endl;
    Print(a, n);

    for (int i = 0; i < n; ++i) {
        delete[] a[i];
    }
    delete[] a;

    return 0;
}