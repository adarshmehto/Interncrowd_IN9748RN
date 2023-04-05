#include <iostream>
#include <fstream>
#include <stdio.h>
#include <conio.h>
using namespace std;
int menu();
class login
{
    string username,password;

    void setdatainfile()
    {
        ofstream fout;
        fout.open("lgpw.txt",ios::app);
        fout.write(reinterpret_cast<const char*>(this),sizeof(*this));
        fout.close();
    }

public:
//    login()
//    {
//        ofstream fout;
//        fout.open("lgpw.txt",ios::app);
//        fout.close();
//    }
    void login_user(string un,string pw)
    {
        ifstream fin;
        fin.open("lgpw.txt");
        if(!fin)
        {
            cout<<"File doesnot exist"; return;
        }
        fin.read(reinterpret_cast <char*>(this),sizeof(*this));
        while(!fin.eof())
        {
            if(this->username==un)
            {
                if(this->password==pw)
                {
                    cout<<"--------WELCOME "<<this->username<<"---------"; return ;
                }
            }
          fin.read(reinterpret_cast <char*>(this),sizeof(*this));
        }
        if(fin.eof()==true)
            cout<<"USER DOESNOT EXIST";
        fin.close();

    }

    int check_username_avl(string un)
    {

            ifstream fin;
            fin.open("lgpw.txt");
            fin.read(reinterpret_cast <char*>(this),sizeof(*this));
            while(!fin.eof())
            {
                if(this->username==un)
                    return 0;
                fin.read(reinterpret_cast <char*>(this),sizeof(*this));
            }
            return 1;
    }
    void registeration()
    {
        ofstream fout;
        fout.open("lgpw.txt",ios::app);
        fout.close();
        setdatainfile();
        int cnf=1;
        cin.ignore();
        string un;
        cout<<"\nPlease enter your username:";
        getline(cin,un);
            if(check_username_avl(un)==0)
            {
                cout<<"USERNAME ALREADY EXISTS"; return;
            }
            else
            {
            cout<<"\nUser name Confirm?";
            cout<<"\n[1] Yes";
            cout<<"\n[2] No";
            cout<<"\nEnter your choice:";
            cin>>cnf;
            if(cnf==1)
                {
                    cin.ignore();
                    username=un;
                    cout<<"\nPlease enter you password:";
                    getline(cin,password);
                    setdatainfile();
                    cout<<"\nREGISTERATION SUCCESSFULL";
                }
            else if(cnf==2)
                {
                    cin.ignore();
                    cout<<"\nPlease enter your user name again:";
                    getline(cin,un);
                    if(check_username_avl(un)==0)
                    {
                        cout<<"USERNAME ALREADY EXISTS"; return;
                    }
                    username=un;
                    cout<<"\nPlease enter you password:";
                    getline(cin,password);
                    setdatainfile();
                    cout<<"\nREGISTERATION SUCCESSFULL";
                }
            else
                cout<<"\nCorrect option was not chosen";

            }
            cin.ignore();
    }

    void showfiledata()
    {
        ifstream fin;
        fin.open("lgpw.txt",ios::in|ios::binary);
        cout<<"\nPosition"<<fin.tellg()<<endl;
        fin.read(reinterpret_cast <char*>(this),sizeof(*this));
        while(!fin.eof())
        {

            cout<<"\nPosition:"<<fin.tellg()<<endl;
            fin.read(reinterpret_cast<char*>(this),sizeof(*this));
        }
    }
};

int main()
{
    login l1;
    while(1)
    {
        system("cls");
        switch(menu())
        {
        case 1:
            {
            cin.ignore();
            string pw,username;
            cout<<"\nPlease enter the username:";
            getline(cin,username);
            cout<<"\nPlease enter the password:";
            cin>>pw;
            l1.login_user(username,pw);
            break;
            }

        case 2:
            {
            l1.registeration();
            break;
            }

        case 3:
            {
            exit(0);
            }

       default:
            cout<<"\nChoose correct option";
        }
        getch();
    }
}

int menu()
{
    int n;
    cout<<"\nHello, Would you like to login or register";
    cout<<"\n[1] Login";
    cout<<"\n[2] Register";
    cout<<"\n[3] Exit";
    cout<<"\nPlease Enter your choice:";
    cin>>n;
    return n;
}
