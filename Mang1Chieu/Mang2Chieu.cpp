#include <iostream>
#include <conio.h>
using namespace std;

#define MAX_DONG 100
#define MAX_COT 100

/*
1. Tính tổng các số nguyên tố trong ma trận
2. Tính tổng các phần tử trên từng dòng
3. Tính tổng các phần tử trên từng cột
4. Xuất các phần tử trên đường chéo chính
5. Xuất các phần tử trên đường chéo phụ
.....
*/

void Nhap_Mang_2_Chieu(int a[][MAX_COT], int dong, int cot);
void Xuat_Mang_2_Chieu(int a[][MAX_COT], int dong, int cot);
bool Kiem_Tra_So_Nguyen_To(int n);
int Tinh_Tong_So_Nguyen_To(int a[][MAX_COT], int dong, int cot);
void Tinh_Tong_Tung_Dong(int a[][MAX_COT], int dong, int cot);
void Tinh_Tong_Tung_Cot(int a[][MAX_COT], int dong, int cot);
void Phan_Tu_Duong_Cheo_Chinh(int a[][MAX_COT], int dong, int cot);
void Phan_Tu_Duong_Cheo_Phu(int a[][MAX_COT], int dong, int cot);

int main()
{
    // ========== KHỞI TẠO MẶC ĐỊNH ==========
    // CÁCH 1: khai báo mảng 2 chiều có 4 dòng và 3 cột
    //int a[4][3] = { {1, 2, 3 }, { 4, 5, 6 }, { 6, 7, 5 }, {2, 8, 9} };
    // CÁCH 2: khai báo mảng 2 chiều có 4 dòng và 3 cột
    //int a[4][3] = { 1, 2, 3, 4, 5, 6, 6, 7, 5, 2, 8, 9 };
    // CÁCH 3: khai báo mảng 2 chiều có 4 dòng và 3 cột
    //int a[][3] = { 1, 2, 3, 4, 5, 6, 6, 7, 5, 2};
    // xuất các phần tử ra màn hình
    // vòng lặp điều khiển chỉ số dòng
    //for (int i = 0; i < 4; i++)
    //{
    //	// vòng lặp điều khiển chỉ số cột
    //	for (int j = 0; j < 3; j++)
    //	{
    //		cout << a[i][j] << " ";
    //	}
    //	cout << endl;
    //}

    // ========== KHỞI TẠO GIÁ TRỊ CHO MẢNG 2 CHIỀU BẰNG CÁCH CHO NGƯỜI DÙNG NHẬP VÀO TỪ BÀN PHÍM ==========

    // khai báo mảng 2 chiều chứa tối đa MAX_DONG X MAX_COT phần tử
    int a[MAX_DONG][MAX_COT];
    int dong;
    int cot;

    // kiểm tra số dòng
    do
    {
        cout << "\nNhap vao so dong: ";
        cin >> dong;
        if (dong <= 0 || dong > MAX_DONG)
        {
            cout << "\nSo dong phai nam trong [1, "
                 << ", " << MAX_DONG << "]";
        }
    } while (dong <= 0 || dong > MAX_DONG);

    // kiểm tra cột
    do
    {
        cout << "\nNhap vao so cot: ";
        cin >> cot;
        if (cot <= 0 || cot > MAX_COT)
        {
            cout << "\nSo cot phai nam trong [1, "
                 << ", " << MAX_COT << "]";
        }
    } while (cot <= 0 || cot > MAX_COT);

    cout << "\n\n\t\t NHAP GIA TRI CHO MANG 2 CHIEU\n";
    Nhap_Mang_2_Chieu(a, dong, cot);
    cout << "\n\n\t\t MANG 2 CHIEU\n";
    Xuat_Mang_2_Chieu(a, dong, cot);

    cout << "\nTong cac so nguyen to la: ";
    cout << Tinh_Tong_So_Nguyen_To(a, dong, cot) << endl;

    Tinh_Tong_Tung_Dong(a, dong, cot);
    cout << endl;
    Tinh_Tong_Tung_Cot(a, dong, cot);

    cout << "\n\n\t\t CAC PHAN TU NAM TREN DUONG CHEO CHINH: ";
    Phan_Tu_Duong_Cheo_Chinh(a, dong, cot);

    cout << "\n\n\t\t CAC PHAN TU NAM TREN DUONG CHEO PHU: ";
    Phan_Tu_Duong_Cheo_Phu(a, dong, cot);

    getch();
    return 0;
}

void Nhap_Mang_2_Chieu(int a[][MAX_COT], int dong, int cot)
{
    // điều khiển chỉ số dòng
    for (int i = 0; i < dong; i++)
    {
        // điều khiển chỉ số cột
        for (int j = 0; j < cot; j++)
        {
            cout << "\nNhap phan tu a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
    }
}

void Xuat_Mang_2_Chieu(int a[][MAX_COT], int dong, int cot)
{
    // điều khiển chỉ số dòng
    for (int i = 0; i < dong; i++)
    {
        // điều khiển chỉ số cột
        for (int j = 0; j < cot; j++)
        {
            cout << a[i][j] << "  ";
        }
        cout << endl;
    }
}

bool Kiem_Tra_So_Nguyen_To(int n)
{
    if (n < 2)
        return false;
    else
    {
        for (int i = 2; i < n; i++)
        {
            if (n % i == 0)
                return false;
        }
    }
    return true;
}

int Tinh_Tong_So_Nguyen_To(int a[][MAX_COT], int dong, int cot)
{
    int tong = 0;
    // duyệt qua từng phần tử trong mảng 2 chiều
    for (int i = 0; i < dong; i++)
    {
        for (int j = 0; j < cot; j++)
        {
            if (Kiem_Tra_So_Nguyen_To(a[i][j]) == true)
            {
                tong += a[i][j];
            }
        }
    }
    return tong;
}

void Tinh_Tong_Tung_Dong(int a[][MAX_COT], int dong, int cot)
{
    // duyệt qua từng phần tử trong mảng 2 chiều
    for (int i = 0; i < dong; i++)
    {
        int tong = 0;
        for (int j = 0; j < cot; j++)
        {
            tong += a[i][j]; // tính tổng trên dòng thứ i
        }
        cout << "\n\t TONG TREN DONG THU " << i << ": " << tong;
    }
}

void Tinh_Tong_Tung_Cot(int a[][MAX_COT], int dong, int cot)
{
    // duyệt qua từng phần tử trong mảng 2 chiều
    for (int i = 0; i < cot; i++)
    {
        int tong = 0;
        for (int j = 0; j < dong; j++)
        {
            tong += a[j][i]; // tính tổng trên cột thứ i
        }
        cout << "\n\t TONG TREN COT THU " << i << ": " << tong;
    }
}

void Phan_Tu_Duong_Cheo_Chinh(int a[][MAX_COT], int dong, int cot)
{
    for (int i = 0; i < dong; i++)
    {
        cout << a[i][i] << " ";
    }
}

void Phan_Tu_Duong_Cheo_Phu(int a[][MAX_COT], int dong, int cot)
{
    for (int i = 0; i < cot; i++)
    {
        cout << a[i][cot - i - 1] << " ";
    }
}