//student data base management system
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<iomanip>
using namespace std;

class students{
    int rollno;
    char name[30];
    char Class[20];
    char address[30];
    float per;
    public:
    void student();
void addstudent();
void studentrecord();
void searchstudent();
void deletestudent();
void modifystduent();
void add();
};

int main(){
    students s1;
     int choice;
     while(choice!=6){
        cout<<endl<<setw(50)<<"STUDENT DATABASE MANAGEMENT SYSTEM"<<endl;
        cout<<endl;
        cout<<"\t\t1. Add Student Record"<<endl;
        cout<<"\t\t2. Student Record"<<endl;
        cout<<"\t\t3. Search Student"<<endl;
        cout<<"\t\t4. Delete Student"<<endl;
        cout<<"\t\t5. Modify Student Record"<<endl;
        cout<<"\t\t6. Exit "<<endl;
        cout<<"\t\t...............................===>>>>"<<endl;
        cout<<"\t\t...............................===>>>>"<<endl;
        cout<<"\t\tEnter the choice :";
        cin>>choice;

        switch(choice){
            case 1:
            s1.addstudent();
            break;

            case 2:
            s1.studentrecord();
            break;

            case 3:
            s1.searchstudent();
            break;
            
            case 4:
            s1.deletestudent();
            break;

            case 5:
            s1.modifystduent();
            break;

            case 6:
            cout<<endl<<"Thank you for using my software ::>>"<<endl;
            main();

            default:
            cout<<endl<<"\t\tPlease enter valid input for perform menu operations :->"<<endl;
        }
     }
}
void students::addstudent(){
char another;
fstream file;
students s1;
do{
cout<<endl<<"\t\t\t\tAdd Student Info "<<endl;
file.open("Stu1.txt",ios::app);
cout<<endl<<"\t\tEnter the rollNumber :";
cin>>s1.rollno;
cout<<endl<<"\t\tEnter the student name :";
cin>>s1.name;
cout<<endl<<"\t\tEnter the class :";
cin>>s1.Class;
cout<<endl<<"\t\tEnter the address :";
cin>>s1.address;
cout<<endl<<"\t\tEnter the percentage :";
cin>>s1.per;
cout<<endl<<"\t\t....................................======>>"<<endl;
cout<<"\t\tRecord stored successfully :"<<endl;
file.write((char*)&s1,sizeof(s1));
file.close();
cout<<"\t\tDo you want to add another record press y :";
cin>>another;
}while(another=='Y'||another=='y');
}


void students::studentrecord(){
students s1;
ifstream file;
cout<<endl<<"\t\t\t\tPrint Student Info "<<endl;
file.open("Stu1.txt",ios::in);
while(file.read((char*)&s1,sizeof(s1))){
    cout<<endl<<"\t\tStudent Roll no. is   -:"<<s1.rollno;
    cout<<endl<<"\t\tStudent name is       -:"<<s1.name;
    cout<<endl<<"\t\tStudent class is      -:"<<s1.Class;
    cout<<endl<<"\t\tStudent address is    -:"<<s1.address;
    cout<<endl<<"\t\tStudent percentage is -:"<<s1.per;
    cout<<endl<<"\t\t...................................====>>>>"<<endl;

}
file.close();
}

void students::searchstudent(){
    students s1;
    fstream file;
    int rollno,found=0;
    cout<<endl<<"\t\t\t\tSearch Student Info "<<endl;
file.open("Stu1.txt",ios::in);
cout<<"\t\tEnter the roll no of student :";
cin>>rollno;
while(file.read((char*)&s1,sizeof(s1))){
    if(s1.rollno==rollno){
        found=1;
   /* int pos=(1)*static_cast<int>(sizeof(s1));
            file.seekp(pos,ios::cur);
            cout<<pos<<"hello students "<<endl;
            */
    cout<<endl<<"\t\tStudent Roll no. is   -:"<<s1.rollno;
    cout<<endl<<"\t\tStudent name is       -:"<<s1.name;
    cout<<endl<<"\t\tStudent class is      -:"<<s1.Class;
    cout<<endl<<"\t\tStudent address is    -:"<<s1.address;
    cout<<endl<<"\t\tStudent percentage is -:"<<s1.per;
    cout<<endl<<"\t\t...................................====>>>>"<<endl;

}
}
if(found==0)
cout<<"\t\tRecord not found :"<<endl;
file.close();
}

void students::deletestudent(){
    students s1;
    ifstream file;
    ofstream file1;
    int rollno;
    cout<<endl<<"\t\t\t\tSearch Student Info "<<endl;
file.open("Stu1.txt",ios::in);
file1.open("Stud1.txt",ios::out);
cout<<"\t\tEnter the roll no of student :";
cin>>rollno;
while(file.read((char*)&s1,sizeof(s1))){
    if(s1.rollno==rollno)
    cout<<endl<<"\t\tRecord deleted successfully :";
    else
    file1.write((char*)&s1,sizeof(s1));
}
file.close();
file1.close();
remove("Stu1.txt");
rename("Stud1.txt","Stu1.txt");
}

void students::modifystduent(){
    int rollno,found=0;
    students s1;
    fstream file;
    file.open("Stu1.txt",ios::in|ios::out|ios::binary);
    cout<<endl<<"\t\t\t\tModify Student Info "<<endl;
    cout<<endl<<"\t\tEnter the roll no for modification in data :";
    cin>>rollno;
    while(file.read(reinterpret_cast<char*>(&s1),sizeof(s1))){
        if(s1.rollno==rollno){
            s1.searchstudent();
            cout<<"\t\tEnter the new details of student :"<<endl;
            //s1.add();
            int pos=(-1)*static_cast<int>(sizeof(s1));
            file.seekp(pos,ios::cur);
            file.seekg(file.tellp()); // Sync the input stream position with the output stream
            
            cout<<endl<<"\t\tEnter the class :";
 	        cin>>s1.Class;
	        cout<<endl<<"\t\tEnter the address :";
	        cin>>s1.address;
	        cout<<endl<<"\t\tEnter the percentage :";
	        cin>>s1.per;
            file.write(reinterpret_cast<char*>(&s1),sizeof(s1));
            cout<<endl<<"\t\tRecord Updated :"<<endl;
            found=1;
            break;
        }
    }
    file.close();
    if(found==0)
    cout<<"\t\tRecord Not found:"<<endl;
}

void students::add(){
    students s1;
cout<<endl<<"\t\tEnter the class :";
cin>>s1.Class;
cout<<endl<<"\t\tEnter the address :";
cin>>s1.address;
cout<<endl<<"\t\tEnter the percentage :";
cin>>s1.per;
}