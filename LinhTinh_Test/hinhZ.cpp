#include <iostream>
using namespace std;

int main()
{
    int hight;

    do
    {
        cout << "Nhap vao chieu cao cua hinh Z = ";
        cin >> hight;
        if (hight < 2)
            cout << "Chieu cao khong hop le! Vui long nhap lai!" << endl;
    } while (hight < 2);

    for (int i = 0; i < hight; i++)
    {
        if (i == 0 || i == hight - 1)
        {
            for (int j = 0; j < hight; j++)
                cout << "* ";
        }
        else
        {
            for (int j = 0; j < i; j++)
                cout << "  ";
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}