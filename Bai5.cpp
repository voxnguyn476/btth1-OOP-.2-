#include <iostream>
#include <cmath>
using namespace std;

struct hs{
    string hten; //Họ tên 
    float t;     // Điểm Toán
    float v;     // Điểm Văn
    float dtb;   // Điểm trung bình (của Toán với Văn), lấy 2 chữ số sau dấu thập phân
};

void Nhap(hs &a){
    getline(cin,a.hten);
    cin >>a.t>>a.v;
}
//Hàm Nhap là hàm void dùng để lưu các thông tin của học sinh 
// được nhập từ bàn phím vào biến có Cấu trúc hs.
//  Đầu vào: biến có Cấu trúc hs.
//  Vì là hàm void nên không có đầu ra, bù lại bên trong hàm sẽ có các thao tác và lưu trữ
//    tác động trực tiếp lên biến đầu vào được nhập.

void Xuat(hs &a){
    cout <<a.hten<<'\n';
    cout <<"Diem Toan: "<<a.t<<'\n';
    cout <<"Diem Van: "<<a.v<<'\n';
    cout <<"Diem trung binh: "<<a.dtb;
}
//Hàm Xuat là hàm void dùng để xuất ra các thông tin của học sinh,
// ở đây sẽ xuất ra họ tên học sinh, điểm Toán, Văn và điểm trung bình của họ.
//  Đầu vào: biến có Cấu trúc hs.
//  Vì là hàm void nên không có đầu ra.

void Tinh_DTB(hs &a){
    a.dtb = (a.t +a.v) / 2;
    a.dtb = round(a.dtb * 100) / 100;
}
//Hàm Tinh_DTB là hàm void dùng để tính điểm trung bình của học sinh
// sau khi đã nhập vào điểm Toán và điểm Văn. Ở đây điểm trung bình sẽ lưu vào biến 
// dtb có trong cấu trúc hs.
//  Đầu vào: biến có Cấu trúc hs.
//  Vì là hàm void nên không có đầu ra, bù lại bên trong hàm sẽ có các thao tác và lưu trữ
//    tác động trực tiếp lên biến đầu vào được nhập.


int main()
{
    hs a;
    Nhap(a);Tinh_DTB(a);
    cout <<"Diem TB: "<<a.dtb;
    
    return 0;
}
