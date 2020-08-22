#include <iostream>
#include <math.h>
using namespace std;

struct toaDo
{
    float x, y; // toa do 1 diem
};
typedef struct toaDo TOADO;

void nhapToaDo(toaDo& td)
{
    cout << "- Nhap x: ";
    cin >> td.x;
    cout << "- Nhap y: ";
    cin >> td.y;
}

void xuatToaDo(toaDo td)
{
    cout << "(" << td.x << ", " << td.y << ")" << endl;
}

float tinhDoDaiCanh(TOADO A, TOADO B)
{
    return sqrt(pow((B.x - A.x), 2) + pow((B.y - A.y), 2));
}

struct tamGiac
{
    TOADO A, B, C;
};
typedef struct tamGiac TAMGIAC;

void nhapToaDoTamGiac(tamGiac& tg)
{
    cout << "Nhap vao toa do diem A: " << endl;
    nhapToaDo(tg.A);
    cout << "Nhap vao toa do diem B: " << endl;
    nhapToaDo(tg.B);
    cout << "Nhap vao toa do diem C: " << endl;
    nhapToaDo(tg.C);
}

void xuatToaDoTamGiac(tamGiac tg)
{
    cout << "---Toa do diem A: ";
    xuatToaDo(tg.A);
    cout << "---Toa do diem B: ";
    xuatToaDo(tg.B);
    cout << "---Toa do diem C: ";
    xuatToaDo(tg.C);
}

int main()
{
    tamGiac tg;
    cout << "=============== NHAP TOA DO ===============\n" << endl;
    nhapToaDoTamGiac(tg);

    system("cls");

    cout << "=============== XUAT TOA DO ===============\n" << endl;
    xuatToaDoTamGiac(tg);

    cout << "\n=> Do dai canh AB = " << tinhDoDaiCanh(tg.A, tg.B) << endl;
    cout << "Do dai canh BC = " << tinhDoDaiCanh(tg.B, tg.C) << endl;
    cout << "Do dai canh CA = " << tinhDoDaiCanh(tg.C, tg.A) << endl;

    system("pause");
    return 0;
}
