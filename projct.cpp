#include<iostream>
#include<fstream>
#include<conio.h>
using namespace std;

struct student
{
	int rollno;
	char name[32];
	int marks;
};
void faddstudentrecord()
{
	int n,i;
	cout<<"\nhow many records u want to enter:\t";
	cin>>n;
	student *s=new student[n];
	for(i=0; i<n;i++)
	{
		cout<<"\nenter roll no\n";
		cin>>(s+i)->rollno;
		cout<<"enter name\n";
		cin>>(s+i)->name;
		cout<<"enter marks\n";
		cin>>(s+i)->marks;
		cout<<endl;
	}
	ofstream ofs("student.bin");
	for(i=0;i<n;i++)
	{
	ofs.write(reinterpret_cast<char*>(&s[i]),sizeof(s[i]));
	} 
	ofs.close();
}
void fdisplyallrecord()
{
     student s;
	int count=0;
	ifstream ifs("student.bin");
	while(ifs.read(reinterpret_cast<char*>(&s),sizeof(s)))
	{
		count++;
	}
	ifs.close();
	ifstream ifs2("student.bin");
	student s2[count];
	int i=0;
	while(ifs2.read(reinterpret_cast<char*>(&s2[i]),sizeof(s2[i])))
	{
		cout<<"\nroll is = "<<(s2+i)->rollno<<"\n";
		cout<<"name is = "<<(s2+i)->name<<"\n";
		cout<<"marks is = "<<(s2+i)->marks<<"\n";
		cout<<endl;	
		i++;
	}
	ifs2.close();
}
 

void fspecificbyrollno()
{
	student s;
	int count=0;
	ifstream ifs("student.bin");
	while(ifs.read(reinterpret_cast<char*>(&s),sizeof(s)))
	{
		count++;
	}
	ifs.close();
	
int spe_rollno;
bool found;
cout<<"\nenter roll number you want specific roll number "<<endl;
cin>>spe_rollno;

ifstream ifs2("student.bin");
	student s2[count];
	int i=0;
	while(ifs2.read(reinterpret_cast<char*>(&s2[i]),sizeof(s2[i])))
	{
		if(spe_rollno==(s2+i)->rollno)
		{
	    found=true;
		cout<<"\nroll is = "<<(s2+i)->rollno<<"\n";
		cout<<"name is = "<<(s2+i)->name<<"\n";
		cout<<"marks is = "<<(s2+i)->marks<<"\n";
		cout<<endl;	
		 break;
		}
		i++;
	}
	ifs2.close();
 


if(found==false)
{
	cout<<"\nno record found"<<endl;
}
 

}
void fmodify()
{


	student s;
	int count=0;
	ifstream ifs("student.bin");
	while(ifs.read(reinterpret_cast<char*>(&s),sizeof(s)))
	{
		count++;
	}
	ifs.close();
		
	int mod_rollno;
	bool found;
	cout<<"\nenter roll number you want specific roll number "<<endl;
	cin>>mod_rollno;

    ifstream ifs2("student.bin");
	student s2[count];
	int i=0;
	while(ifs2.read(reinterpret_cast<char*>(&s2[i]),sizeof(s2[i])))
	{
		if(mod_rollno==(s2+i)->rollno)
		{
	    found=true;
		cout<<"\nThe Existing Roll Number details are below";
		cout<<"\nroll is = "<<(s2+i)->rollno<<"\n";
		cout<<"name is = "<<(s2+i)->name<<"\n";
		cout<<"marks is = "<<(s2+i)->marks<<"\n";
		cout<<endl;	

	 
		// Updated record entered by user 	 
		cout<<"enter rollno"<<endl;
		cin>>(s2+i)->rollno;
		cout<<"enter name"<<endl;
		cin>>(s2+i)->name;
		cout<<"enter marks"<<endl;
		cin>>(s2+i)->marks;

	 
		}
		i++;
	}
	ifs2.close();
 


	if(found==false)
	{
		cout<<"\nno record found"<<endl;
	}
 

	ofstream ofs("student.bin");
	for(i=0;i<count;i++)
	{
	ofs.write(reinterpret_cast<char*>(&s2[i]),sizeof(s2[i]));
	} 
	ofs.close();	

}


void fDelete()
{


	student s;
	int count=0;
	ifstream ifs("student.bin");
	while(ifs.read(reinterpret_cast<char*>(&s),sizeof(s)))
	{
		count++;
	}
	ifs.close();
		
	int spe_rollno;
	bool found;
	cout<<"\nenter roll number you want to delete "<<endl;
	cin>>spe_rollno;

    ifstream ifs2("student.bin");
	student s2[count];
	int i=0;
	int delIndex=-1;
	while(ifs2.read(reinterpret_cast<char*>(&s2[i]),sizeof(s2[i])))
	{
		if(spe_rollno==(s2+i)->rollno)
		{
			delIndex=i;
	    found=true;
		cout<<"\nThe Existing Roll Number details are below\nThis record is being removed now.";
		cout<<"\nroll is = "<<(s2+i)->rollno<<"\n";
		cout<<"name is = "<<(s2+i)->name<<"\n";
		cout<<"marks is = "<<(s2+i)->marks<<"\n";
		cout<<endl;	
 
	  
		}
		i++;
	}
	ifs2.close();
 


	if(found==false)
	{
		cout<<"\nno record found"<<endl;
	}
 
if(found)
{
	 	ofstream ofs("student.bin");
	for(i=0;i<count;i++)
	{
		if(delIndex!=i)
	      ofs.write(reinterpret_cast<char*>(&s2[i]),sizeof(s2[i]));
	} 
	ofs.close();	
}
}
int main ()
{

	char ch;
	while (1)
	{
	  cout<<"\n1=add number"<<endl;
	  cout<<"2=displyalrecord"<<endl;
	  cout<<"3=specific record"<<endl;
	  cout<<"4= modiry record"<<endl;
	  cout<<"5=delet record"<<endl;
	  cout<<"6=exit"<<endl;
	  ch=getche();
	  if (ch=='1')
	  faddstudentrecord ();
	  else
	  if (ch=='2')
	  fdisplyallrecord();
	  if(ch=='3')
	  fspecificbyrollno();
	  if(ch=='4')
	  fmodify();
	  if(ch=='5')
	  fDelete();
	  if(ch=='6')
	  break;
	  else
	  cout<<"invalid number,input number again"<<endl;
    }
    getche ();
    return 0;

    }

