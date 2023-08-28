#include <iostream>
using namespace std;

class Register{
    public:
        string username, password;
};

class Login{
    public:
        string inpUsername, inpPassword;

};

int main(){
    //Register
    Register newUser;
    cout << "Please register";

    cout << "\nEnter your Username: ";
    cin >> newUser.username;

    cout << "\nEnter your Password: ";
    cin >> newUser.password;

    cout << "\nDang ki tai khoan thanh cong. Xin moi dang nhap";
    //Login
    Login newLogin; 
    cout << "\nUsername: ";
    cin >> newLogin.inpUsername;

    cout << "\nPassword: ";
    cin >> newLogin.inpPassword;

    if(newLogin.inpUsername == newUser.username && newLogin.inpPassword == newUser.password){
        cout << "\nDang nhap thanh cong, dang tai thong tin cua ban ...";
    } else {
        cout << "Dang nhap that bai. Kiem tra lai tai khoan mat khau va thu lai sau";
    }
return 0;
}