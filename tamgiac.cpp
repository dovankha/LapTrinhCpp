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
    
    for (int i = 1;  i <= hight; i++)
    {
        for (int j = 1; j <= 2 * hight - 1; j++)
        {
            if (j >= hight - i + 1 && j <= hight + i - 1)
            {
                cout << " *";
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
    }

    return 0;
}
