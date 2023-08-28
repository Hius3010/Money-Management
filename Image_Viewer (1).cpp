#include <iostream>
#include<iomanip>
#include<windows.h>
#define NAME_MAX 25

using namespace std;

class Time{
public:
	int day;
	int month;
	int year;
	Time(int d=0, int m=0, int y=0){
		day = d;
		month = m;
		year = y;	
	}
	void set(int d,int m,int y){
		day = d;
		month = m;
		year = y;
	}
	void input(){
		cout << "\t-Ngay: "; cin>>day;
		cout << "\t-Thang: "; cin>>month;
		cout << "\t-Nam: "; cin>>year;
	}
	void display(){
		if(day<10) cout <<"0";
		cout << day<<'/';
		if(month < 10) cout<<"0";
		cout <<month<<'/';
		cout<<year;
	}
};

class ImageViewer{
	int view;
public:
	string name;
    string size;
    string location;
    Time time;
    
    ImageViewer(string name="\0",string size="\0",string location="\0",int d=0,int m=0, int y=0){
        this->name=name;
        this->size=size;
        this->location=location;
        this->time.set(d,m,y);
        view = 0;
    }
    ImageViewer set(string name="\0",string size="\0",string location="\0",int d=0,int m=0, int y=0){
        this->name=name;
        this->size=size;
        this->location=location;
        this->time.set(d,m,y);
        view = 0;
        return *this;
    }
    void input(){
        cout <<"\tTen anh:";    			  getline(cin,name);
        cout <<"\tDo phan giai:";       	  getline(cin,size);
        cout <<"\tDia diem:";        		  getline(cin,location);
        time.input();
    }
    void Show(){
    	view++;
        cout << setw(NAME_MAX)  << name;
        cout <<setw(18)<< size ;
		cout << "     ";
        time.display();
        cout << setw(15)<< view << "        ";
        cout << location;
        cout <<endl;
    }    
    void set_view(int view){
    	this->view = view;
	}
    int views(){
    	return view;
	}
};

struct Node{
    ImageViewer data;
    Node* next;
};

Node* createNode(ImageViewer x){
    Node* temp = new Node;
    temp->next = NULL;
    temp->data = x;
    return temp;
}

class List{
    Node* head;
    int size;
public:
    List(){
        head=NULL;
        size=0;
    }

    Node* nodeAt(int index){
        if(index<0 || index >=size) return NULL;
        Node* p = head;
        while(index != 0){
            p=p->next;
            index--;
        }
        return p;
    }
    Node* addHead(ImageViewer x){
        Node* temp = createNode(x);
        temp->next = head;
        head = temp;
        size++;
        return head;
    }
    void addTail(ImageViewer x){
        if(head == NULL){
            head=createNode(x);
            size++;
            return;
        }
        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        Node* p = createNode(x);
        temp->next = p;
        size++;
        return;        
    }
    void addAt(ImageViewer x, int index){
        if(index<=0)  {
            addHead(x);
            return;
        }
        else if(index>=size-1){
            addTail(x);
            return;
        }

        Node *p = nodeAt(index-1);
        Node* temp = createNode(x);
        temp->next = p->next;
        p->next = temp;
        return;
    }

    void deTail(){
        if(head==NULL)  return;
        else if(head->next==NULL){
            size--;
            head==NULL;
        }

        Node* temp = head;
        while(temp->next->next != NULL){
            temp = temp->next;
        }
        Node* p= temp->next;
        temp->next = NULL;
        delete p;
        size--;
        return;
    }
    void deHead(){
        Node* p = head;
        head = head->next;
        delete p;
        size--;
        return;
    }
    void deAt(int index){
        if(index <= 0){
            deHead();
            return;
        }
        if(index >=size-1){
            deTail();
            return;
        }
        
        Node *p = nodeAt(index-1);
        Node* temp = p->next;
        p->next = p->next->next;
        delete temp;
        size--;
        return;
    }

    int Size()  {return size;}
	
	int highest_view(){
		int hw = 0;
		Node* p = head;
        while(p != NULL){
        	if(hw < p->data.views()){
            	hw = p->data.views();
			}
            p=p->next;       
        }
        return hw;
	}
    bool *search_location(string s){
        Node* p=head;
        bool *Arr=new bool[size];
        p=head;
        int i=0;
        while (p!=NULL){
            if(p->data.location==s){
                Arr[i]=true;
            }
            else Arr[i]=false;
            p=p->next;
            i++;
        }
        return Arr;
    }
    void display(){
        Node* p = head;
        int i=0;
        cout<<setw(50)<< "| DANH SACH ANH |\n"<<endl;
        cout<<"STT ";
        cout <<setw((NAME_MAX))<<"TEN ANH";
        cout <<setw(18)<<"DO PHAN GIAI";
        cout <<setw(15)<<"NGAY";
        cout <<setw(15)<<"WIEWS"<<"        ";
		cout <<"DIA DIEM CHUP"<<endl;
        while(p != NULL){
            cout <<'('<<i<<") ";
            p->data.Show();
            p=p->next;
            i++;        
        }
    }
};

int main(){
    List H;
    ImageViewer sameloc[1000]; // Mang chua cac anh co cung vi tri
    Node* p2 = NULL;
    int count1 = 0, count2=0;
    bool *Arr2 = NULL;
    string loca;
	// Data test
    ImageViewer temp1("caychuoi.jpg","1920x1080","Nam Dinh",15,2,2011);
    temp1.set_view(100);
	H.addTail(temp1);
	temp1.set("quadao.jpg","120x1080","Nghe An",23,5,2015);
    temp1.set_view(145);
	H.addTail(temp1);
	temp1.set("logoHUST.jpg","540x960","HANOI",15,2,2011);
    temp1.set_view(15300);
	H.addTail(temp1);
	//
	
	ImageViewer temp;
    int event = -1;
    
    while(event != 0){
        cout<<"\n======================================= MENU ==========================================="<<endl;
        cout << "1, In ra danh sach."<<endl;
        cout << "2, Them 1 anh (vao cuoi danh sach)."<<endl;
		cout << "3, Chen 1 anh."<<endl;
        cout << "4, Xoa 1 anh."<<endl;
        cout << "5, So view lon nhat."<<endl;
        cout << "6, Cac anh chup tai cung 1 dia diem."<<endl;
        cout << "7, Phan bo theo nam."<<endl;
        cout << "0, Thoat."<<"\n>>";
        cin>>event;
        getchar();
        switch(event){
        	case 1:
                H.display();
                break;
        	case 2:
        		cout<<"*Nhap thong tin anh:"<<endl;
                temp.input();
                H.addTail(temp);
                getchar();
                cout<<"THEM THANH CONG!";
                break;
            case 3:
                cout<<"*Nhap thong tin anh:"<<endl;
                temp.input();
                cout<<"Nhap vi tri(STT) muon them trong danh sach: ";
                int index;
                cin>>index;
                getchar();
                H.addAt(temp,index);    //Them vao dau neu index < 0, them vao cuoi neu index > size
                cout<<"THEM THANH CONG!";
                break;
            case 4:
                cout<<"Nhap vi tri (STT) muon xoa: ";
                int i;
                cin>>i;
                getchar();
                H.deAt(i);      //Xoa dau neu index < 0, xoa cuoi neu index > size
                cout<<"XOA THANH CONG!";
                break;
            case 5:
                cout<<"So view cao nhat la:"<<H.highest_view();
                break;
            case 6:
                cout<<"*Nhap ten vi tri:";
                getline(cin,loca);
                Arr2=H.search_location(loca); // kiem tra phan tu nao co dia diem la loca (tra ve mang bool)
                cout << "Mang cac phan tu cung dia diem:\n";
                count2 = 0;
                count1 = 0;
                p2 = H.nodeAt(0);
                
                while(p2!=NULL){ 
                	if(Arr2[count2]){
						sameloc[count1] = p2->data;
                        count1++;
                    }
                    count2++;
                    p2=p2->next;
				}
				
				cout<<setw(50)<< "| DANH SACH ANH |\n"<<endl;
		        cout<<"STT ";
		        cout <<setw((NAME_MAX))<<"TEN ANH";
		        cout <<setw(18)<<"DO PHAN GIAI";
		        cout <<setw(15)<<"NGAY";
		        cout <<setw(15)<<"WIEWS"<<"        ";
				cout <<"DIA DIEM CHUP"<<endl;
                for (int j=0;j<count1;j++){
                	cout <<'('<<j<<") ";
                	sameloc[j].Show();			// sameloc la mang cac phan tu co cung "Dia diem"
                }
                delete []Arr2;
                break;
            case 7:	
                int PB[1000][2];
                for(int i=0;i<1000;i++){
                	PB[i][1] = 0;
				}
            	Node *p2 = H.nodeAt(0);
            	if(!p2) {cout << "(Danh sach trong)"; break;}
            	else{ // Thong ke cac nam
            		int diff_num = 1;
            		PB[0][0] = p2->data.time.year;
            		
	            	while(p2!=NULL){
	            		bool ton_tai_so_giong_nhau = 0;
	            		int year = p2->data.time.year;
	            		for (int i=0;i<diff_num;i++){
							if(year == PB[i][0]){
								PB[i][1]++;	
								ton_tai_so_giong_nhau = 1;
							}
						}
						if(!ton_tai_so_giong_nhau){
								PB[diff_num][0] = year;
								PB[diff_num][1]++;
								diff_num++;	
							
							}
	            		p2=p2->next;
					}
					
					for(int i=0;i<diff_num-1;i++){
						for(int j=0;j<diff_num-1;j++){
							if(PB[j][0] > PB[j+1][0]){
								int t1 = PB[j][0];
								int t2 = PB[j][1];
								PB[j][0] = PB[j+1][0];
								PB[j][1] = PB[j+1][1];
								PB[j+1][0] = t1;
								PB[j+1][1] = t2;
							}
						}
					}
					cout<<"Thong ke so anh theo cac nam:\n";
					for(int i=0;i<diff_num;i++){
						cout<<"Nam "<<PB[i][0]<<": "<< PB[i][1]<< " (anh)"<<endl;
					}
					break;
				}
				
        }
        cout<<"\n(An phim bat ki de tiep tuc)";
        getchar();
        
        system("cls");
    }
    
    return 0;
}
