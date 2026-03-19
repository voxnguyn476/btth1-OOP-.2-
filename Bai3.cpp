#include <iostream>
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
    if(a.m == 1) cout <<a.t;
    else cout <<a.t<<"/"<<a.m;
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

void Core(pso a, pso b){
    pso p[4];
    for(int i=0;i<4;i++)
        switch(i){
            case 0:
                p[i].t=a.t*b.m + a.m*b.t;
                p[i].m=b.m * a.m;
                RGon(p[i]);
                break;
            case 1:
                p[i].t=a.t*b.m - a.m*b.t;
                p[i].m=b.m * a.m;
                RGon(p[i]);
                break;
            case 2:
                p[i].t=a.t*b.t;
                p[i].m=b.m * a.m;
                RGon(p[i]);
                break;
            case 3:
                p[i].t=a.t * b.m;
                p[i].m=b.t * a.m;
                RGon(p[i]);
                break;

        }

    char k;
    for(int i=0;i<4;i++){
        Xuat(p[i]);cout <<" ";
    }
}
//Hàm ở trên có tính năng tính các phép tính cộng-trừ-nhân-chia giữa hai phân số và trả ra kết quả
// Hàm có đầu vào gồm 2 tham số, cả hai đều có Cấu trúc pso
// Đây là hàm void nên sẽ không có kiểu dữ liệu,bù lại các kết quả của phép tính
//  sẽ được lưu lại trong mảng Cấu trúc pso p bên trong hàm.


int main()
{
    pso a,b;
    Nhap(a);Nhap(b);
    RGon(a);RGon(b);
    Core(a,b);
    return 0;
}
