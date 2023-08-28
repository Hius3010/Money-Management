#include <iostream>
#include <cstring>
#include <vector>
#include <ctype.h>
#include <fstream>
#include <iomanip>
#include <math.h>
using namespace std;

class Register{
    public:
        string username, password;
};

class Login{
    public:
        string inpUsername, inpPassword;

};

// Khai báo Class Date: ngày, tháng năm
class Date {
    private:
        int day,month,year;
    public:
        // Hàm khởi tạo ngày, tháng, năm
        Date(){this->day = this->month = this->year = 0;}
        // Hàm hủy
        ~Date(){this->day = this->month = this->year = 0;}
        // Định nghĩa hàm nhập thời gian
        void input(){
            cout << endl << "Ngay (01-30): ";
            // Kiểm tra Ngày-Tháng-Năm có hợp lệ hay không ?
            while(true){
                cin >> this->day;
                if(this->day >= 01 && this->day <= 30)
                {
                    break;
                }
                else puts("Ngay khong hop le, vui long thu lai !");
            }
            cout << "Thang (01-12): ";
            while(true){
                cin >> this->month;
                if(this->month >= 01 && this->month <= 12)
                {
                    break;
                }
                else puts("Thang khong hop le, vui long thu lai !");
            }
            cout << "Nam: ";cin >> this->year;
            // Đưa các thông tin vào file
            ofstream outfile;
            outfile.open("CacKhoan.txt",ios::app);
            outfile << setw(2)<<this->day<<"/"<<setw(2)<< this-> month<< "/"<<setw(4)<<this->year <<" ";
            outfile.close();
                    
        }
        // Định nghĩa hàm hiển thị thời gian
        void output(){cout << this->day << "/" << this->month << "/" << this->year << endl;}
        // Định nghĩa lại toán tử == để so sánh thời gian
        bool operator == (const Date &d) const{
            if (this->day == d.day && this->month == d.month && this->year == d.year)return true;
            return false;
        } 
};
// Khai báo lớp CacKhoan
class CacKhoan {
    protected:
        string test;
        long long tien;
        string lido;
        Date ngay;
    public:
        virtual void input() = 0;  // Khai báo hàm ảo input
        virtual void output() = 0; // Khai báo hàm ảo output
        // Hàm khởi tạo
        CacKhoan(){this->test = " ";this->tien = 0;this->lido = " ";}
        // Hàm hủy
        ~CacKhoan(){this->test = " ";this->tien = 0;this->lido = " ";}
        int gettien(){return this->tien;}
        string getlido(){return this->lido;}
        Date getngay(){return this->ngay;}
};

bool isNumber(const string& s){
    for (char const &ch : s) {
        if (std::isdigit(ch) == 0) 
            return false;
    }
    return true;
}

// Sử dụng tính kế thừa khai báo Class KhoanThu
class KhoanThu : public CacKhoan{
    public:
        // Định nghĩa hàm nhập khoản thu theo ngày, tháng, năm và lý do
        void input(){                       
            cout << "Nhap ngay, thang, nam";
            ngay.input();
            cout << "Nhap so tien thu: ";
            //  Kiểm tra số tiền nhập vào có hợp lệ thông qua biến test
            while(true){
                cin >> this->test;
                if(isNumber(this->test))break;
                else puts("So tien khong hop le, vui long thu lai !");
            }
            //  Chuyển string test về int số tiền 
            this->tien = stol(this->test);
            cin.ignore();
            cout << "Li do thu: ";
            getline(cin,this->lido);
            // Đưa các thông tin vào file
            ofstream outfile;
            outfile.open("CacKhoan.txt",ios::app);
            outfile <<"Khoan Thu:"<< setw(13) << this->tien << setw(20) << this->lido << endl;
            outfile.close();
        }
        // Định nghĩa hàm hiển thị khoản thu theo ngày, tháng, năm và lý do
        void output(){
            cout << "Ngay da thu: ";
            this->ngay.output();
            cout << "So tien da thu: " << this->tien << endl;
            cout << "Li do thu: " << this->lido << endl;
        }
};
// Sử dụng tính kế thừa khai báo Class KhoanChi
class KhoanChi : public CacKhoan{
    public:
        // Định nghĩa hàm nhập khoản chi theo ngày, tháng, năm và lý do
        void input(){
            cout << "Nhap ngay, thang, nam";
            ngay.input();
            cout << "Nhap so tien chi: ";
            //  Kiểm tra số tiền nhập vào có hợp lệ thông qua biến test
            while(true){
                cin >> this->test;
                if(isNumber(this->test))break;
                else puts("So tien khong hop le, vui long thu lai !");
            }
            //  Chuyển string test về int số tiền 
            this->tien = stol(this->test);
            cin.ignore();
            cout << "Li do chi: ";
            getline(cin,this->lido);
            // Đưa các thông tin vào file
            ofstream outfile;
            outfile.open("CacKhoan.txt",ios::app);
            outfile <<"Khoan Chi:"<< setw(13) << this->tien << setw(20)<< this->lido << endl;
            outfile.close();
        }
        // Định nghĩa hàm hiển thị khoản thu theo ngày, tháng, năm và lý do
        void output(){
            cout << "Ngay da chi: ";
            this->ngay.output();
            cout << "So tien da chi: " << this->tien << endl;
            cout << "Li do chi: " << this->lido << endl;
        }
};
// Khai báo Class QuanLy
class QuanLy{
    private:
        vector <KhoanThu*> dsKhoanThu; // Khai báo vector danh sách khoản thu
        vector <KhoanChi*> dsKhoanChi; // Khai báo vector danh sách khoản chi
    public:
        // Định nghĩa hàm tính tổng khoản thu
        int TongSoTienDaThu(){
            int tong = 0;
            for(int i = 0; i < dsKhoanThu.size(); i++){
                tong += dsKhoanThu[i]->gettien();
            }
            return tong;
        }
        // Định nghĩa hàm tính tổng khoản chi
        int TongSoTienDaChi(){
            int tong = 0;
            for(int i = 0; i < dsKhoanChi.size(); i++){
                tong += dsKhoanChi[i]->gettien();
            }
            return tong;
        }
        // Định nghĩa hàm tính số dư hiện có
        int TienHienCo(){
            return TongSoTienDaThu() - TongSoTienDaChi();
        }
        // Định nghĩa hàm nhập danh sách khoản thu, chi
        void NhapDanhSach(){
            int key;
            cout << "1. Them khoan thu" << endl;
            cout << "2. Them khoan chi" << endl;
            cout << "0. Quay lai" << endl;
            cout << "Nhap lua chon: ";
            cin >> key;
            switch (key){
            case 0:
                break;
            // Nhập khoản thu
            case 1:{
                    cout << "THEM KHOAN THU" << endl;
                    KhoanThu* x = new KhoanThu;
                    x->input();
                    dsKhoanThu.push_back(x);
                    cout << endl <<"BAN DA THEM KHOAN THU THANH CONG!!" << endl;
                    break;
                }
            // Nhập khoản chi 
            case 2:{
                    cout << "THEM KHOAN CHI" << endl;
                    KhoanChi* x = new KhoanChi;
                    x->input();
                    dsKhoanChi.push_back(x);
                    cout << endl <<"BAN DA THEM KHOAN CHI THANH CONG!!" << endl;
                    break;
                }
            default:
                cout << "Khong co lua chon nay!!" << endl;
                break;
            }
        }
        // Định nghĩa hàm xuất danh sách khoản thu, chi
        void XuatDanhSach(){
            int key;
            cout << "1. Xuat khoan thu" << endl;
            cout << "2. Xuat khoan chi" << endl;
            cout << "0. Quay lai" << endl;
            cout << "Nhap lua chon: ";
            cin >> key;
            switch (key){
            case 0:
                break;
            // Xuất danh sách khoản thu
            case 1:{
                    int dem = 1;
                    cout << "XUAT DANH SACH CAC KHOAN THU" << endl << endl;
                    cout << "Tong so tien da thu: " << TongSoTienDaThu() << endl;
                    cout << endl;
                    cout << "So khoan thu: " << dsKhoanThu.size() << endl << endl;
                    for(int i = 0; i < dsKhoanThu.size(); i++){
                        cout << "Khoan thu thu " << dem++ << endl;
                        dsKhoanThu[i]->output();
                    }
                    break;
                }
            // Xuất danh sách khoản chi
            case 2:{
                    int dem = 1;
                    cout << "XUAT DANH SACH CAC KHOAN CHI" << endl << endl;
                    cout << "Tong so tien da chi: " << TongSoTienDaChi() << endl;
                    cout << "So khoan chi: " << dsKhoanChi.size() << endl << endl;
                    for(int i = 0; i < dsKhoanChi.size(); i++){
                        cout << "Khoan chi thu " << dem++ << endl;
                        dsKhoanChi[i]->output();
                    }
                    break;
                }
            default:
                cout << "Khong co lua chon nay!!" << endl;
                break;
            }
        }
        // Định nghĩa hàm sao kê khoản thu, chi theo số tiền
        void SaoKeTheoSoTien(){
            int key;
            cout << "SAO KE THEO SO TIEN" << endl;
            cout << "1. Sao ke khoan thu " << endl;
            cout << "2. Sao ke khoan chi " << endl;
            cout << "0. Quay lai" << endl;
            cout << "Nhap lua chon: ";
            cin >> key;
            switch (key){
            case 0:
                break;
            // Sao kê khoản thu theo số tiền
            case 1:{
                    int x;
                    int i = 0;
                    cout << "Nhap so tien can sao ke: ";
                    cin >> x;
                    for (int i=0; i < dsKhoanThu.size(); i++)
                    {
                        if (dsKhoanThu[i]->gettien() == x)
                            dsKhoanThu[i]->output();
                    }
                    break;
                }
            // Sao kê khoản chi theo số tiền
            case 2:{
                    int x;
                    cout << "Nhap so tien can sao ke: ";
                    cin >> x;
                    for (int i=0; i < dsKhoanChi.size(); i++)
                    {
                        if (dsKhoanChi[i]->gettien() == x)
                            dsKhoanChi[i]->output();
                    }
                    break;
                }
            default:
                cout << "Khong co lua chon nay" << endl;
                break;
            }
        }
        // Định nghĩa hàm sao kê khoản thu, chi theo thời gian
        void SaoKeTheoNgay()
        {
            int key;
            cout << "SAO KE THEO NGAY THANG NAM" << endl;
            cout << "1. Sao ke khoan thu " << endl;
            cout << "2. Sao ke khoan chi " << endl;
            cout << "0. Quay lai " << endl;
            cout << "Nhap lua chon: ";
            cin >> key;
            switch (key){
            case 0:
                break;
            // Sao kê khoản thu theo thời gian
            case 1:{
                    Date d;
                    cout << "Nhap ngay thang nam can sao ke: ";
                    d.input();
                    for (int i = 0; i < dsKhoanThu.size(); i++)
                    {
                        if (dsKhoanThu[i]->getngay() == d)
                            dsKhoanThu[i]->output();
                    }
                    break;
                }
            // Sao kê khoản chi theo thời gian
            case 2:{
                    Date d;
                    cout << "Nhap ngay thang nam can sao ke: ";
                    d.input();
                    for (int i=0; i < dsKhoanChi.size(); i++){
                        if (dsKhoanChi[i]->getngay() == d)
                            dsKhoanChi[i]->output();
                    }
                    break;
                }
            default:
                cout << "Khong co lua chon nay" << endl;
                break;
            }
        }
        // Định nghĩa hàm sao kê khoản thu, chi theo lý do
        void SaoKeTheoLiDo(){
            int key;
            cout << "SAO KE THEO LI DO" << endl;
            cout << "1. Sao ke khoan thu " << endl;
            cout << "2. Sao ke khoan chi " << endl;
            cout << "0. Quay lai" << endl;
            cout << "Nhap lua chon: ";
            cin >> key;
            switch (key){
            case 0:
                break;
            // Sao kê khoản thu theo lí do
            case 1:{
                    string s;
                    cin.ignore();
                    cout << "Nhap li do can sao ke: " ;
                    getline(cin,s);
                    for (int i = 0; i < dsKhoanThu.size(); i++){
                        if (dsKhoanThu[i]->getlido().compare(s) == 0)
                            dsKhoanThu[i]->output();
                    }
                    break;
                }
            // Sao kê khoản chi theo lí do
            case 2:{
                    string s;
                    cin.ignore();
                    cout << "Nhap li do can sao ke: " ;
                    getline(cin,s);
                    for (int i = 0; i < dsKhoanChi.size(); i++){
                        if (dsKhoanChi[i]->getlido().compare(s) == 0)
                            dsKhoanChi[i]->output();
                    }
                    break;
                }
            default:
                cout << "Khong co lua chon nay" << endl;

            }
        }
};

// Hàm main
int main(){
    int keymain;
    QuanLy QL;
    //Register
    Register newUser;

    system("cls"); // Lệnh xóa màn hình
    // Bắt đầu đăng ký
    cout << "Vui long dang ky";
    cout << "\nEnter your Username: ";
    cin >> newUser.username;
    cout << "Enter your Password: ";
    cin >> newUser.password;
    cout << "\nDang ki tai khoan thanh cong. Xin moi dang nhap";
    ofstream outfile;
    outfile.open("CacKhoan.txt",ios::app);
    outfile << "Username: "<< setw(13) << newUser.username << endl;
    outfile.close();
    // Đăng nhập
    Login newLogin; 
    cout << "\nUsername: ";
    cin >> newLogin.inpUsername;
    cout << "Password: ";
    cin >> newLogin.inpPassword;
    if(newLogin.inpUsername == newUser.username && newLogin.inpPassword == newUser.password){
        cout << "Dang nhap thanh cong, dang tai thong tin cua ban ..." << endl;
        do{
            system("cls"); // Lệnh xóa màn hình
            cout << "|-----------------------|" << endl;
            cout << " *UNG DUNG QUAN LY TIEN*  " << endl;
            cout << "|-----------------------|" << endl;
            cout << " *So tien hien co: " << QL.TienHienCo() << endl << endl;
            cout << "|1. Them khoan thu, chi |" << endl;
            cout << "|2. Xuat danh sach      |" << endl;
            cout << "|3. Sao ke theo so tien |" << endl;
            cout << "|4. Sao ke theo ngay    |" << endl;
            cout << "|5. Sao ke theo li do   |" << endl;
            cout << "|0. Thoat chuong trinh  |" << endl;
            cout << "|-----------------------|" << endl;
            if (QL.TienHienCo() < 0) // Đưa ra cảnh báo khi số dư âm
                cout << endl << "CANH BAO TAI KHOAN DA HET TIEN!!!" << endl;
            if(QL.TongSoTienDaChi() != 0 && QL.TongSoTienDaThu() != 0){
                // Các cảnh báo phụ 
                if (QL.TongSoTienDaChi() >= QL.TongSoTienDaThu()/2 ) 
                    cout << endl << "CANH BAO BAN DA TIEU VUOT QUA 50% SO LUONG, DUNG LAI DI!!! " << endl;
                if (QL.TongSoTienDaChi() >= QL.TongSoTienDaThu()/3 ) 
                    cout << endl << "CANH BAO BAN DA TIEU VUOT QUA 30% SO LUONG, BINH TINH NAO!!! " << endl;
                if (QL.TongSoTienDaChi() >= QL.TongSoTienDaThu()*0.8 ) 
                    cout << endl << "CANH BAO BAN DA TIEU VUOT QUA 80% SO LUONG, DUNG LAI DI!!! " << endl;
                if (QL.TongSoTienDaChi() <= QL.TongSoTienDaThu()/10 ) 
                    cout << endl << "BAN CHI TIEU DUOI 10% SO LUONG, THAT TUYET VOI!!!" << endl;
            }
            if ((QL.TienHienCo() >= pow(10,6)) && (QL.TienHienCo() <= pow(10,9))) cout << "BAN LA MOT TRIEU PHU!!!" <<endl;
            if((QL.TienHienCo() > pow(10,9))) cout << "BAN THAT KHAC BIET!!!" << endl;       

            cout << " -->Nhap lua chon: " ;
            cin >> keymain;
            switch(keymain){
            case 0:
                break;
            // Nhập khoản thu, chi
            case 1:
                QL.NhapDanhSach();
                break;
            // Xuất danh sách thu, chi
            case 2:
                QL.XuatDanhSach();
                getchar();
                break;
            // Sao kê khoản thu, chi theo số tiền
            case 3:
                QL.SaoKeTheoSoTien();
                getchar();
                break;
            // Sao kê khoản thu, chi theo thời gian
            case 4:
                QL.SaoKeTheoNgay();
                getchar();
                break;
            // Sao kê khoản thu, chi theo thời gian
            case 5:
                QL.SaoKeTheoLiDo();
                getchar();
                break;
            }
            if(keymain != 0){
                cout << "An phim bat ky de tiep tuc" << endl;
                getchar();
            }
        } while (keymain != 0);
    }else {
        cout << "Dang nhap that bai. Kiem tra lai tai khoan mat khau va thu lai sau";
    }
    return 0;
}
