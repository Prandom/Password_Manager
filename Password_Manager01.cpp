#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
using namespace std;
class user
{
    public:
    string username,password,site;char encrypwd[10000];
    void encrypt()
    {
        int n= password.length();
        char pwd[n];
        strcpy(pwd, password.c_str());
        char evenPos = '@', oddPos = '!';
    int repeat, ascii;
    int k=0;
    for (int i = 0; i <n; i++)
    {
        ascii = pwd[i];
        repeat = ascii >= 97 ? ascii - 96 : ascii - 47;

        for (int j = 0; j < repeat; j++)
        {
            if (i % 2 == 0)
                encrypwd[k]=oddPos;
            else
                encrypwd[k]=evenPos;
                k++;
        }
    }


    }

    void putdata()
    {
        cout<<"Site "<<site<<endl;
        cout<<"Username "<<username<<endl;
        cout<<"Encrypted Password "<<password<<endl;

    }
string getsite()
{
    return site;
}
string getusername()
{
    return username;
}
string getpassword()
{
    return password;
}
}u1,u2;

int main()
{
    int c;
    while(1)
    {
    cout<<"Enter 1. for Viewing the database\n 2. for Adding new site\n 3. for Removing data of a site"<<endl;
    cout<<"Enter your choice"<<endl;
    cin>>c;
    switch(c)
    {
    case 1:
        {ifstream ifs("User.txt",ios::in);
        while(!ifs.eof())
        {
           ifs>>u1.site;
           ifs>>u1.username;
           ifs>>u1.password;
           u1.putdata();
        }
        ifs.close();
        break;}
    case 2:
        {
        string s1;
        ofstream ofs("User.txt",ios::app);
        cout<<"Enter site "<<endl; cin>>s1;
        u1.site=s1;
        cout<<"Enter username "<<endl; cin>>u1.username;
        cout<<"Enter password "<<endl;cin>>u1.password;
        ofs<<u1.getsite()<<endl<<u1.getusername()<<endl;
        u1.encrypt();
        for(int i=0;i<strlen(u1.encrypwd);i++)
            ofs<<u1.encrypwd[i];
        ofs<<endl;
        ofs.close();
        break;}
    case 3:
        {
           string s;char found='f',confirm;
           ifstream ifs("User.txt",ios::in);
           ofstream ofs("temp.txt",ios::out);
           cout<<"Enter the site, the details of which you want to delete "<<endl;
           cin>>s;
           while(!ifs.eof())
           {
               ifs>>u1.site;
               ifs>>u1.username;
               ifs>>u1.password;
               if(s==u1.getsite())
               {
                   u1.putdata();
                   found='t';
                   cout<<"Are you sure that you want to delete this site's data?(y/n)"<<endl;
                   cin>>confirm;
                   if(confirm=='n')
                   {
                       ofs<<u1.getsite()<<endl<<u1.getusername()<<endl<<u1.getpassword()<<endl;
                   }
               }
                   else
                   {
                       ofs<<u1.getsite()<<endl<<u1.getusername()<<endl<<u1.getpassword()<<endl;
                   }
               }
               if(found=='f')
                        cout<<"Record not found!\n";
               ifs.close();
               ofs.close();
               remove("User.txt");
               rename("temp.txt","User.txt");
               break;
        }
    default:
        cout<<"Wrong Choice"<<endl;
    }
    cout<<"Do you want to continue?(y/n)\n";
    char ch;
    cin>>ch;
    if(ch=='y')
        continue;
    else
        break;
    }
    return 0;

    }

