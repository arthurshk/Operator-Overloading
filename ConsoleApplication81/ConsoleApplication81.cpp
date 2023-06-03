#include<iostream>
using namespace std;

class Fraction
{
private:
    int x;//NUMERATOR
    int y;//DENOMINATOR
public:
    Fraction(int tx = 0, int ty = 1)
    {
        if (ty == 0)
        {
            x = 0;
            y = 1;
        }
        else
        {
            x = tx;
            y = ty;
        }
    }
    void simplify()
    {
        for (int i = y; i > 1; i--)
        {
            if (x % i == 0 && y % i == 0)
            {
                x = x / i;
                y = y / i;
            }
        }
    }
    void Input()
    {
        cout << "Input NUMERATOR: ";
        cin >> x;
        cout << "Input DENOMINATOR: ";
        cin >> y;
        if (y == 0)
        {
            cout << "ERROR";
        }
    }
    void Display()
    {
        cout << x << "/" << y << endl;
    }
    Fraction operator + (Fraction& f) {
        Fraction temp;
        temp.x = x * f.y + y * f.x;
        temp.y = y * f.y;
        return temp;
    }
    Fraction operator - (Fraction& f) {
        Fraction temp;
        temp.x = x * f.y - y * f.x;
        temp.y = y * f.y;
        return temp;
    }
    Fraction operator * (Fraction& f) {
        Fraction temp;
        temp.x = x * f.x;
        temp.y = y * f.y;
        return temp;
    }
    Fraction operator / (Fraction& f) {
        Fraction temp;
        temp.x = x * f.y;
        temp.y = y * f.x;
        return temp;
    }
};
int main()
{

    Fraction f1;
    f1.Input();
    cout << "Fraction: ";
    f1.simplify();
    f1.Display();
    Fraction f2;
    f2.Input();
    cout << "Fraction: ";
    f2.simplify();
    f2.Display();
    Fraction f3, f4, f5, f6;
    f3 = f1 + f2;
    f4 = f1 - f2;
    f5 = f1 * f2;
    f6 = f1 / f2;
    cout << "Sum" << endl;
    f3.simplify();
    f3.Display();
    cout << "Difference" << endl;
    f4.simplify();
    f4.Display();
    cout << "Product" << endl;
    f5.simplify();
    f5.Display();
    cout << "Division" << endl;
    f6.simplify();
    f6.Display();
    return 0;
}