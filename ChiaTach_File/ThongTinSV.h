#include <iostream>
#include <string>
using namespace std;

struct sinhVien
{
    string ten, MSSV;
    float diemCTDL_GT = 0;
    float diemToan = 0;
    float diemKTLT = 0;
};

void nhapThongTin(sinhVien& info)
{
    while (getchar() != '\n');
    do
    {
        cout << "\nNhap vao Ho & ten: ";
        getline(cin, info.ten);
        if (info.ten.length() > 35)
            cout << "Ten ban khong hop le. Vui long nhap lai!" << endl;
    } while (info.ten.length() > 35);

    do
    {
        cout << "\nNhap vao MSSV cua ban: ";
        getline(cin, info.MSSV);
        if (info.MSSV.length() > 15)
            cout << "MSSV cua ban khong dung. Vui long nhap lai!" << endl;
    } while (info.MSSV.length() > 15);

    do
    {
        cout << "\nNhap vao diem toan cua ban: ";
        cin >> info.diemToan;
        if (info.diemToan < 0 || info.diemToan > 10)
            cout << "Diem toan cua ban khong dung. Vui long nhap lai!" << endl;
    } while (info.diemToan < 0 || info.diemToan > 10);

    do
    {
        cout << "\nNhap vao diem ky thuat lap trinh cua ban: ";
        cin >> info.diemKTLT;
        if (info.diemKTLT < 0 || info.diemKTLT > 10)
            cout << "Diem ky thuat lap trinh cua ban khong dung. Vui long nhap lai!" << endl;
    } while (info.diemKTLT < 0 || info.diemKTLT > 10);

    do
    {
        cout << "\nNhap vao diem cau truc du lieu & giai thuat cua ban: ";
        cin >> info.diemCTDL_GT;
        if (info.diemCTDL_GT < 0 || info.diemCTDL_GT > 10)
            cout << "Diem cau truc du lieu & giai thuat cua ban khong dung. Vui long nhap lai!" << endl;
    } while (info.diemCTDL_GT < 0 || info.diemCTDL_GT > 10);
}

void xuatThongTin(sinhVien info)
{
    cout << "\nHo & ten:\t" << info.ten;
    cout << "\nMSSV:\t\t" << info.MSSV;
    cout << "\nDiem Toan:\t" << info.diemToan;
    cout << "\nDiem CTDL&GT:\t" << info.diemCTDL_GT;
    cout << "\nDiem KTLT:\t" << info.diemKTLT << endl;
}

string catTen(sinhVien info)
{
    for (int i = info.ten.length() - 1; i >= 0; i--)
    {
        if (info.ten[i] == ' ')
            return info.ten.substr(i + 1); // cat tu vi tri i + 1 ve den cuoi chuoi
    }
    return "";
}
