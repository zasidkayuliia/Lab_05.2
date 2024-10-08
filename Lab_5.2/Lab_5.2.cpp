#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void S(const double x, const double eps, int& n, double& s);
void A(const double x, const int n, double& a);

int main()
{
    double xp, xk, x, dx, eps, s = 0;
    int n = 0;
    cout << "xp = "; cin >> xp;
    cout << "xk = "; cin >> xk;
    cout << "dx = "; cin >> dx;
    cout << "eps = "; cin >> eps;

    cout << fixed;
    cout << "------------------------------------------------------------" << endl;
    cout << "|" << setw(6) << "x" << setw(2) << "    |"
        << setw(11) << "arth(x)" << setw(6) << " |"
        << setw(9) << "S" << setw(8) << "  |"
        << setw(6) << "n" << setw (2) <<"       |"
        << endl;
    cout << "------------------------------------------------------------" << endl;

    x = xp;
    while (x <= xk)
    {
        if (x <= -1 || x >= 1)
        {
            cout << "|" << setw(7) << setprecision(2) << x << "   |"
                << setw(15) << "Out of range" << " |"
                << setw(15) << "Out of range" << " |"
                << setw(5) << "Out of range" << " |"
                << endl;
        }
        else
        {
            S(x, eps, n, s);
            cout << "|" << setw(7) << setprecision(2) << x << "   |"
                << setw(15) << setprecision(5) << atanh(x) << " |"
                << setw(15) << setprecision(5) << s << " |"
                << setw(5) << n << "        |"
                << endl;
        }
        x += dx;
    }

    cout << "------------------------------------------------------------" << endl;
    return 0;
}

// Функція обчислює суму ряду
void S(const double x, const double eps, int& n, double& s)
{
    n = 0;
    double a = x;
    s = a;
    do {
        n++;
        A(x, n, a);
        s += a;
    } while (abs(a) >= eps);
}

// Функція обчислює наступний доданок ряду
void A(const double x, const int n, double& a)
{
    double R = x * x / (2 * n + 1);
    a *= R;
}


