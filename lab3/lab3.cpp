#include <cmath>
#include <iostream>

using namespace std;


long long int Fact(int t) {
    if (t <= 1) return 1;
    else return t * Fact(t - 1);
}

double f_rec(double x, int n) {
    if (n == 0) return 1;
    if (n > 0) {
        double S = pow((2 * x), n) / Fact(n) * 1.0;
        return (S + f_rec(x, n - 1));
    } 
}


int main()
{
    setlocale(0, "");
    int n, x;
    cout << "Введите х и номер члена ряда: ";
    cin >> x >> n;
    cout << "Сумма ряда: " << f_rec(x,n) << endl;
    return 0;
}
