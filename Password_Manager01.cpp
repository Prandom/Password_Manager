#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<cstdlib>
using namespace std;
class user
{

    char password[50],encrypwd[10000];
public:
	char site[50],username[50];
    string encryptDecrypt(string toEncrypt)
    {
      char key = 'K'; 
    string output = toEncrypt;
    
    for (int i = 0; i < toEncrypt.size(); i++)
        output[i] = toEncrypt[i] ^ key;
    
    return output;
        
    }


    

    void getdata()
    {
        cout<<"Enter username\n";cin>>username;
        cout<<"Enter site\n";gets(site);gets(site);
        cout<<"Enter password\n";gets(password);
    }
    void putdata()
    {
        cout<<"Site "<<site<<endl;
        cout<<"Username "<<username<<endl;
        cout<<"Password "<<password<<endl;

    }


}u1;

int main()
{
    int i=1;string name,pwd;
    ifstream f;ofstream o;
    f.open("count.txt");
    f>>i;
    f.close();
	if(i==1)
	{cout<<"Enter name:";getline(cin,name);
	cout<<"Enter password:";getline(cin,pwd);
	ofstream ofs,o;
	ofs.open("Super User.txt");o.open("SU01.bin");
	ofs<<name<<endl;
	pwd=u1.encryptDecrypt(pwd);
	o<<pwd<<endl;
	ofs.close();o.close();
	cout<<"Logged in\n";
	}
	else if(i>1)
	{
		string p,n;
		cout<<"Enter name:";getline(cin,n);
	    cout<<"Enter password:";getline(cin,p);
	    ifstream ifs,i;
	    ifs.open("Super User.txt");i.open("SU01.bin");
	    getline(ifs,name);
	    getline(i,pwd);
	    pwd=u1.encryptDecrypt(pwd);
	    i.close();
	    ifs.close();
	    if(n==name && p==pwd)
	    cout<<"Logged in\n";
	    else
	    {
		cout<<"Wrong Input\n";
		return 0;
		}
	}
	i++;
	o.open("count.txt");
	o<<i;
	o.close();
	int c;
    while(1)
    {
    cout<<"Enter 1. for Viewing the database\n 2. for Adding new site\n 3. for Removing data of a site\n 4. for Searching data of a site\n 5. for generating a strong password"<<endl;
    cout<<"Enter your choice"<<endl;
    cin>>c;
    switch(c)
    {
    case 1:
        {ifstream ifs("User.bin",ios::in|ios::binary);
        while(!ifs.eof())
        {
           ifs.read((char*)&u1,sizeof(u1));
           u1.putdata();
        }
        ifs.close();
        break;}
    case 2:
        {

        ofstream ofs("User.bin",ios::app|ios::binary);
        u1.getdata();
        ofs.write((char*)&u1,sizeof(u1));
        ofs.close();
        break;}
    case 3:
        {
           char s[50];char found='f',confirm;
           ifstream ifs("User.bin",ios::in|ios::binary);
           ofstream ofs("temp.bin",ios::out|ios::binary);
           cout<<"Enter the site, the details of which you want to delete "<<endl;
           gets(s);gets(s);
           while(!ifs.eof())
           {
               ifs.read((char*)&u1,sizeof(u1));
               if(strcmp(s,u1.site)==0)
               {
                   u1.putdata();
                   found='t';
                   cout<<"Are you sure that you want to delete this site's data?(y/n)"<<endl;
                   cin>>confirm;
                   if(confirm=='n')
                   {
                       ofs.write((char*)&u1,sizeof(u1));
                   }
               }
                   else
                   {
                       ofs.write((char*)&u1,sizeof(u1));
                   }
               }
               if(found=='f')
                        cout<<"Record not found!\n";
               ifs.close();
               ofs.close();
               remove("User.bin");
               rename("temp.bin","User.bin");
               break;
        }
    case 4:
        	{
        		ifstream ifs("User.bin",ios::in|ios::binary);
        		char s[50];char found='f',ch;
        		cout<<"Do you want to search by site or by username?(s/u)\n";
        		cin>>ch;
        		if(ch=='s')
        		{
        			 cout<<"Enter the site of the record you want to search "<<endl;
                     gets(s);gets(s);
                    while(!ifs.eof())
                      {
                          ifs.read((char*)&u1,sizeof(u1));
                          if(strcmp(s,u1.site)==0)
                            {
                                u1.putdata();
                                 found='t';
        			
				            }
				        }
				        if(found=='f')
                        cout<<"Record not found!\n";
                     ifs.close();
                 }
                 else if(ch=='u')
        		{
        			 cout<<"Enter the username of the record you want to search "<<endl;
                     gets(s);gets(s);
                    while(!ifs.eof())
                      {
                          ifs.read((char*)&u1,sizeof(u1));
                          if(strcmp(s,u1.username)==0)
                            {
                                u1.putdata();
                                 found='t';
        			
				            }
				        }
				        if(found=='f')
                        cout<<"Record not found!\n";
                     ifs.close();
                 }
                 
        		break;
			}
	case 5:
	{
		int l=8+rand()%12;string res=""; int r;
  
     
    for (int i = 0; i < l; i++)  
        {
        	r=rand()%2;
			if(r==0)
			res=res+(char)(48+rand()%10);
			else if(r==1)
			res+=(char)(65+rand()%26);
			else
			res+=(char)(97+rand()%26);
		}
	cout<<"Suggested strong password:"<<res<<endl;
      
	break;	}			
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

