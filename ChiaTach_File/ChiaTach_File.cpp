#include "DanhSachSV.h"

int main()
{
    danhSach ds;
    cout << "Nhap so luong sinh vien: ";
    cin >> ds.n;

    cout << "\n\t\t======NHAP DANH SACH SINH VIEN======\n" << endl;
    nhapDanhSachSV(ds);

    system("clear");

    cout << "\n\t\t======XUAT DANH SACH SINH VIEN======\n" << endl;
    xuatDanhSachSV(ds);

    sapXepDSGiamTheoTen(ds);
    cout << "\n\t\t----------DS SINH VIEN SAU KHI SAP XEP ----------" << endl;
    xuatDanhSachSV(ds);

    system("pause");
    return 0;
}