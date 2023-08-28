#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class Date
{
private:
    int day,month,year;
public:
    Date()
    {
        this->day = this->month = this->year = 0;
    }
    ~Date()
    {
        this->day = this->month = this->year = 0;
    }
    void input()
    {
        cout << "Nhap ngay, thang, nam: ";
        cin >> this->day;
        cin >> this->month;
        cin >> this->year;
    }
    void output()
    {
        cout << this->day << "/" << this->month << "/" << this->year << endl;
    }
    bool operator == (const Date &d) const
    {
        if (this->day == d.day && this->month == d.month && this->year == d.year)
            return true;
        return false;
    }
};

class KhoanThu
{
private:
    int tienthu;
    string lido;
    Date ngaythu;
public:
    KhoanThu()
    {
        this->tienthu = 0;
        this->lido = " ";
    }
    ~KhoanThu()
    {
        this->tienthu = 0;
        this->lido = " ";
    }
    void input()
    {
        cin.ignore();
        ngaythu.input();
        cout << "Nhap so tien thu: ";
        cin >> this->tienthu;
        cout << "Li do thu: ";
        cin >> this->lido;
    }
    void output()
    {
        cout << "Ngay da thu: ";
        this->ngaythu.output();
        cout << "So tien da thu: " << this->tienthu << endl;
        cout << "Li do thu: " << this->lido << endl;
    }
    int gettienthu()
    {
        return this->tienthu;
    }
    string getlido()
    {
        return this->lido;
    }
    Date getngaythu()
    {
        return this->ngaythu;
    }
};

class KhoanChi
{
private:
    int tien;
    string lido;
    Date ngay;
public:
    KhoanChi()
    {
        this->tien = 0;
        this->lido = " ";
    }
    ~KhoanChi()
    {
        this->tien = 0;
        this->lido = " ";
    }
    void input()
    {
        cin.ignore();
        ngay.input();
        cout << "Nhap so tien chi: ";
        cin >> this->tien;
        cout << "Li do chi: ";
        cin >> this->lido;
    }
    void output()
    {
        cout << "Ngay da chi: ";
        this->ngay.output();
        cout << "So tien da chi: " << this->tien << endl;
        cout << "Li do chi: " << this->lido << endl;
    }
    int gettien()
    {
        return this->tien;
    }
    string getlido()
    {
        return this->lido;
    }
    Date getngay()
    {
        return this->ngay;
    }
};

class QuanLy
{
private:
    vector <KhoanThu*> dsKhoanThu;
    vector <KhoanChi*> dsKhoanChi;
public:
    int TongSoTienDaThu()
    {
        int tong = 0;
        for(int i = 0; i < dsKhoanThu.size(); i++)
        {
            tong += dsKhoanThu[i]->gettienthu();
        }
        return tong;
    }
    int TongSoTienDaChi()
    {
        int tong = 0;
        for(int i = 0; i < dsKhoanChi.size(); i++)
        {
            tong += dsKhoanChi[i]->gettien();
        }
        return tong;
    }
    int TienHienCo()
    {
        return TongSoTienDaThu() - TongSoTienDaChi();
    }
    void NhapDanhSach()
    {
        cin.ignore();
        int key;
        cout << "1. Them khoan thu" << endl;
        cout << "2. Them khoan chi" << endl;
        cout << "Nhap lua chon: ";
        cin >> key;
        switch (key)
        {
        case 1:
            {
                cout << "THEM KHOAN THU" << endl;
                KhoanThu* x = new KhoanThu;
                x->input();
                dsKhoanThu.push_back(x);
                break;
            }
        case 2:
            {
                cout << "THEM KHOAN CHI" << endl;
                KhoanChi* x = new KhoanChi;
                x->input();
                dsKhoanChi.push_back(x);
                break;
            }
        default:
            cout << "Khong co lua chon nay" << endl;
            system("pause");
            break;
        }
    }
    void XuatDanhSach()
    {
        int key;
        cout << "1. Xuat khoan thu" << endl;
        cout << "2. Xuat khoan chi" << endl;
        cout << "Nhap lua chon: ";
        cin >> key;
        switch (key)
        {
        case 1:
            {
                int dem = 1;
                cout << "XUAT DANH SACH CAC KHOAN THU" << endl << endl;
                cout << "Tong so tien da thu: " << TongSoTienDaThu() << endl;
                cout << "So khoan thu: " << dsKhoanThu.size() << endl << endl;
                for(int i = 0; i < dsKhoanThu.size(); i++)
                {
                    cout << "Khoan thu thu " << dem++ << endl;
                    dsKhoanThu[i]->output();
                }
                break;
            }
        case 2:
            {
                int dem = 1;
                cout << "XUAT DANH SACH CAC KHOAN CHI" << endl << endl;
                cout << "Tong so tien da chi: " << TongSoTienDaChi() << endl;
                cout << "So khoan chi: " << dsKhoanChi.size() << endl << endl;
                for(int i = 0; i < dsKhoanChi.size(); i++)
                {
                    cout << "Khoan chi thu " << dem++ << endl;
                    dsKhoanChi[i]->output();
                }
                break;
            }
        default:
            cout << "Khong co lua chon nay" << endl;
            system("pause");
            break;
        }
    }
    void SaoKeTheoSoTien()
    {
        int key;
        cout << "SAO KE THEO SO TIEN" << endl;
        cout << "1. Sao ke khoan thu " << endl;
        cout << "2. Sao ke khoan chi " << endl;
        cout << "Nhap lua chon: ";
        cin >> key;
        switch (key)
        {
        case 1:
            {
                int x;
                cout << "Nhap so tien can sao ke: ";
                cin >> x;
                for (int i=0; i < dsKhoanThu.size(); i++)
                {
                    if (dsKhoanThu[i]->gettienthu() == x)
                        dsKhoanThu[i]->output();
                }
            }
        case 2:
            {
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
            system("pause");
            break;
        }
    }
    void SaoKeTheoNgay()
    {
        int key;
        cout << "SAO KE THEO NGAY" << endl;
        cout << "1. Sao ke khoan thu " << endl;
        cout << "2. Sao ke khoan chi " << endl;
        cout << "Nhap lua chon: ";
        cin >> key;
        switch (key)
        {
        case 1:
            {
                Date d;
                cout << "Nhap ngay can sao ke: " << endl;
                d.input();
                for (int i = 0; i < dsKhoanThu.size(); i++)
                {
                    if (dsKhoanThu[i]->getngaythu() == d)
                        dsKhoanThu[i]->output();
                }
            }
        case 2:
            {
                Date d;
                cout << "Nhap ngay can sao ke: ";
                d.input();
                for (int i=0; i < dsKhoanChi.size(); i++)
                {
                    if (dsKhoanChi[i]->getngay() == d)
                        dsKhoanChi[i]->output();
                }
                break;
            }
        default:
            cout << "Khong co lua chon nay" << endl;
            system("pause");
            break;
        }
    }
    void SaoKeTheoLiDo()
    {
        int key;
        cout << "SAO KE THEO LI DO" << endl;
        cout << "1. Sao ke khoan thu " << endl;
        cout << "2. Sao ke khoan chi " << endl;
        cout << "Nhap lua chon: ";
        cin >> key;
        switch (key)
        {
        case 1:
            {
                string s;
                cout << "Nhap li do" ;
                cin >> s;
                for (int i = 0; i < dsKhoanThu.size(); i++)
                {
                    if (dsKhoanThu[i]->getlido().compare(s) == 0)
                        dsKhoanThu[i]->output();
                }
                break;
            }
        case 2:
            {
                string s;
                cout << "Nhap li do" ;
                cin >> s;
                for (int i = 0; i < dsKhoanChi.size(); i++)
                {
                    if (dsKhoanChi[i]->getlido().compare(s) == 0)
                        dsKhoanChi[i]->output();
                }
                break;
            }
        default:
            cout << "Khong co lua chon nay" << endl;
            system("pause");
            break;
        }
    }
};

int main()
{
    int key;
    QuanLy QL;
    do
    {
        system("cls");
        cout << "UNG DUNG QUAN LY TIEN" << endl << endl;
        cout << "1. Them khoan thu, chi" << endl;
        cout << "2. Xuat danh sach" << endl;
        cout << "3. So tien hien co" << endl;
        cout << "4. Sao ke theo so tien" << endl;
        cout << "5. Sao ke theo ngay" << endl;
        cout << "6. Sao ke theo li do" << endl;
        cout << endl;
        if (QL.TienHienCo() < 0)
            cout << "Canh bao" << endl;
        cout << "Nhap lua chon: ";
        cin >> key;
        switch(key)
        {
        case 1:
            {
                QL.NhapDanhSach();
                break;
            }
        case 2:
            {
                QL.XuatDanhSach();
                system("pause");
                break;
            }
        case 3:
            {
                cout << "So tien hien co: " << QL.TienHienCo() << endl;
                system("pause");
                break;
            }
        case 4:
            {
                QL.SaoKeTheoSoTien();
                system("pause");
                break;
            }
        case 5:
            {
                QL.SaoKeTheoNgay();
                system("pause");
                break;
            }
        case 6:
            {
                QL.SaoKeTheoLiDo();
                system("pause");
                break;
            }
        }
    } while (key != 0);

    return 0;
}
