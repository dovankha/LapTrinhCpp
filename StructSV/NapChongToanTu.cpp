#include <iostream>
using namespace std;
#include <fstream>
#include <conio.h>
/*
NẠP CHỒNG TOÁN TỬ (OPERATOR OVERLOADING)
Toán tử: +, -, *, /, %, ++, --, &, &&, ||, >>, <<....

*/

// khai báo cấu trúc phân số
struct phanso
{
    int tuso;
    int mauso;
};
typedef struct phanso PHANSO;

// hàm nhập phân số
void Nhap_Phan_So(PHANSO &ps)
{
    cout << "\nNhap tu so: ";
    cin >> ps.tuso;
    cout << "\nNhap mau so: ";
    cin >> ps.mauso;
}

// hàm xuất phân số
void Xuat_Phan_So(PHANSO ps)
{
    cout << ps.tuso << "/" << ps.mauso;
}

// hàm cộng 2 phân số
PHANSO Cong_Phan_So(PHANSO x, PHANSO y)
{
    PHANSO tam;
    tam.tuso = (x.tuso * y.mauso) + (y.tuso * x.mauso);
    tam.mauso = x.mauso * y.mauso;
    return tam;
}

// nạp chồng lại toán tử >> để nhập dữ liệu từ bàn phím vào cho kiểu dữ liệu cấu trúc
istream &operator>>(istream &is, PHANSO &ps)
{
    cout << "\nNhap tu so: ";
    is >> ps.tuso;
    cout << "\nNhap mau so: ";
    is >> ps.mauso;
    return is;
}

// nạp chồng lại toán tử << để xuất dữ liệu cho kiểu dữ liệu cấu trúc
ostream &operator<<(ostream &os, PHANSO ps)
{
    cout << ps.tuso << "/" << ps.mauso;
    return os;
}

// nạp chồng toán tử + để cộng trực tiếp 2 kiểu dữ liệu cấu trúc phân số
PHANSO operator+(PHANSO x, PHANSO y)
{
    PHANSO tam;
    tam.tuso = (x.tuso * y.mauso) + (y.tuso * x.mauso);
    tam.mauso = x.mauso * y.mauso;
    return tam;
}

int main()
{

    PHANSO x;
    PHANSO y;
    cout << "\n\tNHAP PHAN SO X\n";
    cin >> x;
    cout << "\n\tNHAP PHAN SO Y\n";
    cin >> y;
    cout << "\n\tXUAT PHAN SO X\n";
    cout << x;
    cout << "\n\tXUAT PHAN SO Y\n";
    cout << y;
    //PHANSO tam = Cong_Phan_So(x, y);
    cout << "\n\tTong 2 phan so la: " << x + y;

    getch();
    return 0;
}