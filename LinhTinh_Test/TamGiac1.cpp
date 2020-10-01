#include <iostream>
using namespace std;

int main()
{
    int hight;

    do
    {
        cout << "Nhap vao chieu cao cua tam giac: ";
        cin >> hight;
        if (hight < 2)
            cout <<"Chieu cao khong hop le! Vui long nhap lai!" << endl;
    } while (hight < 2);

    // for (int top = 1; top <= 2 * hight - 1; top++)
    //     cout << "* ";
    // cout << endl;

    for (int i = 0;  i < hight; i++)
    {
        for (int j = 1; j <= 2 * hight - 1; j++)
        {
            if (j >= (hight - i + 1) && (j <= hight + i - 1))
            {
                cout << "  ";
            }
            else
            {
                cout << "* ";
            }
        }
        cout << endl;
    }

    for (int bottom = 1; bottom <= 2 * hight - 1; bottom++)
        cout << "* ";


    cout << endl;
    return 0;
}
