#include <bits/stdc++.h>
#include <conio.h>
int menu();
using namespace std;
class BirthdayList
{
    map<string,string> m;
    public:
    void AddBirthday()
    {
        string name;
        string dob;
        cout<<"Name:";
        cin.ignore();
        getline(cin,name);
        cout<<"DOB:";
        getline(cin,dob);
        cout<<"\nInsertion complete\n";
        m.insert(pair<string,string>(name,dob));

    }

    void display()
    {
            for(auto x=m.begin();x!=m.end();x++)
            {
                cout<<"\nName:"<<x->first<<"\nDob: "<<x->second;
            }
    }
};

BirthdayList* createobject()
{
    return new BirthdayList;
}
int main()
{
    int ln=0,j=1;
    vector <BirthdayList*> listt;

    while(1)
    {
        cout<<"\nList size:"<<listt.size()<<endl;

        switch(menu())
        {
        case 1:
             listt.push_back(createobject());
             cout<<"List"<<ln<<" is created";
             break;
        case 2:
            for(int i=0;i<listt.size();i++)
                cout<<"To insert in list "<<j<<" Enter "<<j<<endl;

            if(listt.empty()==false)
            {
                int n;
                cout<<"Enter list number in which you want to insert a birthday:";
                cin>>n;
                if(n<=0 || n>listt.size())
                    cout<<"\nIndex is invalid";
                else
                    listt[n-1]->AddBirthday();
            }
            else
                cout<<"\nList is empty";
            break;
        case 3:
            for(int i=0;i<listt.size();i++)
                cout<<"To display list "<<j<<" Enter "<<j<<endl;

            if(listt.empty()==false)
            {
                int n;
                cout<<"Enter list number which you want to display birthday list:";
                cin>>n;
                if(n<=0 || n>listt.size())
                    cout<<"\nIndex is invalid";
                else
                    listt[n-1]->display();
            }
            else
                cout<<"\nList is empty";
            break;
        case 4: exit(0);
        }
        cout<<endl;

    }
}
 int menu()
    {
        int n;
        cout<<"1. Create a List\n";
        cout<<"2. Add birthday in a list\n";
        cout<<"3. Display birthday list\n";
        cout<<"4. Exit\n";
        cout<<"Enter your choice:";
        cin>>n;
        return n;
    }
