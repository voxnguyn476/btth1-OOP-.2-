#include <iostream>
#include <cmath>
using namespace std;

struct pso{
    long long t,m; // t: tử số ; m: mẫu số
};

bool Hople(pso a){
    return (a.m != 0);
}
//Hàm Hople là một hàm bool dùng để kiểm tra phân số a đã hợp lý chưa;
// với đầu vào là biến có Cấu trúc pso, đầu ra là giá trị True hoặc False
// lần lượt tương ứng phân số đó "Đã hợp lệ" hoặc "Chưa hợp lệ".

void Nhap(pso &a){
    int c=0;
    cin >>a.t>>a.m;

}
//Hàm Nhap là hàm void dùng để lưu phân số được nhập từ bàn phím vào biến có Cấu trúc pso
// được khởi tạo ban đầu trong hàm main (gọi là biến a).

void Xuat(pso &a){
    if(a.m == 1) cout <<a.t<<"\n";
    else cout <<a.t<<"/"<<a.m<<"\n";
}
//Hàm Xuat là hàm void dùng để in ra phân số được đưa vào, với đầu vào là biến có Cấu trúc pso.
//Hàm sẽ in ra phân số đó dưới dạng "tử/mẫu", hoặc in ra "tử" nếu mẫu là 1.
// Vd: "2/3" , "2" (thay vì "2/1")

void RGon(pso &a){
    int i=abs(a.t),k=abs(a.m),r=1;

    if(i>k) swap(i,k);

    while(r){
        r=k%i;
        k=i;i=r;
    }

    a.t/=k;a.m/=k;
}
//Hàm RGon là hàm void dùng để rút gọn phân số được đưa vào,
// với đầu vào là biến có Cấu trúc pso.
// Khi chạy hết hàm sẽ không có đầu ra, nhưng sẽ được biến Cấu trúc pso đó đã được rút gọn.

float s_d(pso a){
    return float(a.t)/float(a.m);
}
//Hàm s_d là hàm kiểu dữ liểu float cho đầu ra là dạng thập phân của phân số nhập vào.
// Hàm có đầu vào là biến có Cấu trúc pso
// Đầu ra thuộc kiểu dữ liệu float, là dạng số thập phân của phân số nhập vào.

int main()
{
    pso a,b;
    Nhap(a);Nhap(b);
    if(!(Hople(a) && Hople(b))) cout <<"Phan so nhap vao khong hop le. Vui long nhap lai.\n";
    else{
        RGon(a);RGon(b);
        if(s_d(a) >s_d(b)) Xuat(a);
        else Xuat(a);
    }
    return 0;
}

