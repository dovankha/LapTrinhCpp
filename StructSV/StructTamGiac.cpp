#include <iostream>
#include <cmath>
#include <conio.h>

using namespace std;

// Nhập vào tọa độ 3 đỉnh của 1 tam giác. Tính độ dài của từng cạnh

// khai báo cấu trúc struct tọa độ
struct toado
{
    float x; // tọa độ điểm x
    float y; // tọa độ điểm y
};
typedef struct toado TOADO;

// hàm nhập tọa độ
void Nhap_Toan_Do(TOADO &td)
{
    cout << "\nNhap vao diem x: ";
    cin >> td.x; // nhập tọa điểm x
    cout << "\nNhap vao diem y: ";
    cin >> td.y; // nhập tọa điểm y
}

// hàm xuất tọa độ
void Xuat_Toa_Do(TOADO d)
{
    cout << "(" << d.x << ", " << d.y << ")";
}

// hàm tính độ dài cạnh
float Tinh_Do_Dai_Canh(TOADO A, TOADO B)
{
    return sqrt(pow((B.x - A.x), 2) + pow((B.y - A.y), 2));
}

// cấu trúc struct tam giác
struct tamgiac
{
    TOADO A;
    TOADO B;
    TOADO C;
};
typedef struct tamgiac TAMGIAC;

// hàm nhập tam giác
void Nhap_Toa_Do_Tam_Giac(TAMGIAC &tg)
{
    cout << "\n\n\t\t NHAP TOA DO DIEM A\n";
    Nhap_Toan_Do(tg.A);
    cout << "\n\n\t\t NHAP TOA DO DIEM B\n";
    Nhap_Toan_Do(tg.B);
    cout << "\n\n\t\t NHAP TOA DO DIEM C\n";
    Nhap_Toan_Do(tg.C);
}

// hàm xuất tam giác
void Xuat_Toa_Do_Tam_Giac(TAMGIAC tg)
{
    // xuất tọa độ 3 điểm A B C
    cout << "\n\n\t\t TOA DO DIEM A\n";
    Xuat_Toa_Do(tg.A);
    cout << "\n\n\t\t TOA DO DIEM B\n";
    Xuat_Toa_Do(tg.B);
    cout << "\n\n\t\t TOA DO DIEM C\n";
    Xuat_Toa_Do(tg.C);
}
int main()
{
    TAMGIAC tg;
    Nhap_Toa_Do_Tam_Giac(tg);
    Xuat_Toa_Do_Tam_Giac(tg);
    // độ dài từng cạnh
    cout << "\n\n\t\tDO DAI CANH AB: " << Tinh_Do_Dai_Canh(tg.A, tg.B);
    cout << "\n\n\t\tDO DAI CANH AC: " << Tinh_Do_Dai_Canh(tg.A, tg.C);
    cout << "\n\n\t\tDO DAI CANH BC: " << Tinh_Do_Dai_Canh(tg.B, tg.C);
    
    getch();
    return 0;
}