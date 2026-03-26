#include <iostream>
#include <cmath>
using namespace std;

struct Date{
    int d,m,y; // d:Ngày; m:Tháng; y:Năm 
    bool nh = 0; //nh là biến kiểm tra có trong năm nhuận không; với 1 là Có, 0 là Không 
    int dmax; // dmax là biến lưu ngày cuối tương ứng trong tháng đó; với giá trị nằm trong đoạn [28;31]
};

void Update(Date &a){
    a.nh = (a.y%400 == 0) || ((a.y%100 != 0) && (a.y%4 == 0));
    a.dmax = 31 -((a.m<8 && a.m%2==0) || (a.m>=8 && a.m%2==0)) - 2* (a.m == 2) + (a.m == 2 && a.nh);
}
//Hàm Update là hàm void dùng để cập nhật các dữ liệu trong đối tượng thuộc lớp Date,
// cụ thể là dữ liệu nh và dmax.
//  Đầu vào: Tham số có Cấu trúc Date.
//  Vì là hàm void nên không có đầu ra, bù lại bên trong hàm sẽ có các thao tác và lưu trữ
//    tác động trực tiếp lên biến đầu vào được nhập.


void Nhap(Date &a){
    cin >>a.d>>a.m>>a.y;
    Update(a);
}
//Hàm Nhap là hàm void dùng để lưu các thông tin của một ngày từ bàn phím, 
// theo cú pháp 'Ngày Tháng Năm'
//  Đầu vào: Tham số có Cấu trúc Date.
//  Vì là hàm void nên không có đầu ra, bù lại bên trong hàm sẽ có các thao tác và lưu trữ
//    tác động trực tiếp lên biến đầu vào được nhập.

void Xuat(Date &a){
    cout << a.d <<" / "<< a.m <<" / " << a.y;
    cout <<'\n'<<a.nh<<" "<<a.dmax;
}
//Hàm Xuat là hàm void dùng để xuất ra các thông tin của ngày
// theo cú pháp 'Ngày / Tháng / Năm'. (Các thông tin còn lại không in ra)
//  Đầu vào: Tham số có Cấu trúc Date.
//  Vì là hàm void nên không có đầu ra, song bên trong hàm có các thao tác và lưu trữ
//    tác động trực tiếp lên biến đầu vào được nhập.

void Next_day(Date &a){
    a.d ++;
    if(a.d > a.dmax){
        a.d-=a.dmax;a.m++;
        if(a.m > 12){
            a.m-=12; a.y++;
        }
        Update(a);
    }
}
//Hàm Tinh_DTB là hàm void dùng để tính điểm trung bình của học sinh
// sau khi đã nhập vào điểm Toán và điểm Văn. Ở đây điểm trung bình sẽ lưu vào biến 
// dtb có trong cấu trúc hs.
//  Đầu vào: biến có Cấu trúc Date.
//  Vì là hàm void nên không có đầu ra, bù lại bên trong hàm sẽ có các thao tác và lưu trữ
//    tác động trực tiếp lên biến đầu vào được nhập.


int main()
{
    Date a;
    Nhap(a);
    Next_day(a);
    Xuat(a);
    
    return 0;
}
