//login corrected version
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<iomanip>
using namespace std;
class pass{
    char id[20],psw[20];
    int dob;
    public:
void login();
void Register();
void forget();
void find();
};

bool f1=true;
int main(){
    pass p1;
    cout<<setw(45)<<" PASSWORD MANAGEMENT SYSTEM "<<endl<<endl;
    int choice=0;
    while(choice!=5){
cout<<"\t\t1. Register \n"<<endl;
cout<<"\t\t2. Login \n"<<endl;
cout<<"\t\t3. Forget password \n"<<endl;
cout<<"\t\t4. Find username \n"<<endl;
cout<<"\t\t5. Exit \n"<<endl;
cout<<"\t\t...................................................>>>"<<endl;
cout<<"\t\t...................................................>>>"<<endl;
cout<<"\t\tEnter your choice :::>>>";
cin>>choice;


switch(choice){
    
    case 1:
    p1.Register();
    break;
    
    case 2:
    p1.login();
    break;

    case 3:
    p1.forget();
    break;

    case 4:
    p1.find();
    break;

    case 5:
    cout<<setw(40)<<"Thank you for using my software ::>>"<<endl;
    exit(0);

    default:
    cout<<setw(40)<<"Please enter valid input for perform menu operations :->"<<endl;
    
}
    }    
}

void pass::Register(){
    pass p1;
    ofstream fout;
    cout<<setw(50)<<"REGISTRATION "<<endl<<endl;
    cout<<endl<<"\t\t\t\tEnter the username :";
    cin>>p1.id;
    cout<<endl<<"\t\t\t\tEnter the password :";
    cin>>p1.psw;
    cout<<endl<<"\t\t\t\tEnter the DOB ";
    cin>>p1.dob;
    fout.open("login.txt",ios::app);
    fout.write((char*)&p1,sizeof(p1));
    cout<<endl<<"\t\tRegistration successfully completed :"<<endl;
    cout<<"\t\tYour username and password is shown below in sequntial mode :"<<endl;
    cout<<"\t\t"<<p1.id<<endl;
    cout<<"\t\t"<<p1.psw<<endl;
    fout.close();
}

void pass::login(){
    char username[20],password[20];
    ifstream fin;
    pass p1;
    fin.open("login.txt", ios::in);
    if(!fin){
        cout<<"\t\tCan't open this file because found error in opening :"<<endl;
        return;
    }
    fin.read((char*)&p1,sizeof(p1));
    cout<<setw(50)<<"LOGIN PAGE  "<<endl;
    cout<<endl<<"\t\tEnter the username :";
    cin>>username;
    cout<<endl<<"\t\tEnter the password :";
    cin>>password;
    fin.seekg(ios::beg);
     while(fin.read((char*)&p1,sizeof(p1))){
    //while(getline(p1,p2)){
    //while(fin){
    if(strcmp(p1.id,username)==0 && strcmp(p1.psw,password)==0){
    f1=false;
    break;
        }
    }
    if(f1==false){
        cout<<endl<<"\t\tlogin successfully =>"<<endl;
      }
     else{
     cout<<"something else please input correct details";
    }
    /*else if(strcmp(p1.id,username)!=0){
        cout<<"\t\tEntered wrong username "<<endl;
        //login();
        break;
    }
    else if(strcmp(p1.psw,password)!=0){
        cout<<"\t\tEntered wrong password :"<<endl;
        //forget();
        break;
    }*/
}


void pass::forget(){
    char username[20],password[20],ans;
    int dob;
    pass p1;
    ofstream fout;
    ifstream fin;
    

cout<<setw(50)<<"FORGET PASSWORD "<<endl<<endl;
cout<<"\t\tEnter the username :";
cin>>username;
cout<<endl<<"\t\tEnter the DOB :";
cin>>dob;
fin.open("login.txt",ios::in);
fin.seekg(ios::beg);
while(fin.read((char*)&p1,sizeof(p1))){
    if(strcmp(username,p1.id)==0 && dob==p1.dob){
        cout<<endl<<"\t\tEnter the new password ";
        cin>>password;
        fin.close();
        fout.open("spass.txt",ios::out);
        strcpy(p1.psw,password);
        fout.write((char*)&p1,sizeof(p1));
        fout.close();
        login();
        break;
    }
    else
    cout<<endl<<"\t\tWrong DOB : ";
    break;
}
fin.close();
}

void pass::find(){
    pass p1;
    int dob;
    char ans;
    ifstream fin;
    cout<<setw(50)<<"FIND USERNAME"<<endl<<endl;
    do{
        cout<<"\t\tEnter the DOB :";
        cin>>dob;
        fin.open("login.txt",ios::in);
        while(fin.read((char*)&p1,sizeof(p1))){
        //while(!fin){
        if(p1.dob==dob){
            cout<<"\t\tUsername is :"<<p1.id;
            break;
        }
        else{
            cout<<"\t\tWrong DOB :"<<endl;
        }
        }
        fin.close();
        cout<<"\t\tPress y for login otherwise press any key :";
        cin>>ans;
    }while(ans=='Y'||ans=='y');
}
