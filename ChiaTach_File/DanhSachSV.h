#include "ThongTinSV.h"

struct danhSach
{
    sinhVien a[100];
    int n = 0;
};

void nhapDanhSachSV(danhSach& ds)
{
    for (int i = 0; i < ds.n; i++)
    {
        cout << "\n\n\t*****NHAP THONG TIN SINH VIEN THU " << i + 1 << "******" << endl;
        nhapThongTin(ds.a[i]);
    }
}

void xuatDanhSachSV(danhSach ds)
{
    for (int i = 0; i < ds.n; i++)
    {
        cout << "\n\n\t*****THONG TIN SINH VIEN THU " << i + 1 << endl;
        xuatThongTin(ds.a[i]);
    }
}

void sapXepDSGiamTheoTen(danhSach& ds)
{
    for (int i = 0; i < ds.n - 1; i++)
    {
        for (int j = i + 1; j < ds.n; j++)
        {
            string tenI = catTen(ds.a[i]);
            string tenJ = catTen(ds.a[j]);

            if (strcmp((char*)tenI.c_str(), (char*)tenJ.c_str()) < 0)
            {
                sinhVien temp;
                temp = ds.a[i];
                ds.a[i] = ds.a[j];
                ds.a[j] = temp;
            }
        }
    }
}
