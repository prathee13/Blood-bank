#include<fstream.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<process.h>

class Donor 
{ 
char name[20]; 
char bgp[4];             //blood group 
char address[10]; 
long int phno; 
char gender[7]; 
public: 
void read();                //To accept the details of the donor 
void display();            //To display the details 
char * ret_bog()          //To return the value 
    { return bgp; } 
char * ret_name()         //To return the name 
{ return name; }
 };

ifstream in;
ofstream out;
Donor D;                                                                                 //Object of class Donor
char ch;


void Donor::read()
{
  textcolor(5);
  cprintf("Enter name       : ");
  gets(name);
  cout<<" \n ";
  cprintf(" Enter gender    : ");
  gets(gender);
  cout<<" \n ";
  cprintf(" Enter address     : ");
  gets(address);
  cout<<" \n ";
  cprintf(" Enter phone no.   : ");
  cin>>phno;
  cout<<" \n ";
  cprintf(" Enter blood group : ");
  gets(bgp);
  cout<<" \n "
}


void Donor::display() { 
textcolor(3); 
cout<<"\n"; 
cprintf("Name : "); 
cout<<name<<endl; 
cout<<"\n"; 
cprintf("Gender : "); 
cout<<gender<<endl; 
cout<<"\n"; 
cprintf("Address : "); 
cout<<address<<endl; 
cout<<"\n"; 
cprintf("Phone No. : "); 
cout<<phno<<endl; 
cout<<"\n"; 
cprintf("Blood group : "); 
cout<<bgp<<endl; 
cout<<"\n"; 
}

void create() {                  // Creating a new record
    out.open("blood.dat",ios::binary); 
   do 
   { 
        D.read(); 
        out.write((char*)&D,sizeof(Donor)); 
         cout<<" Do you want to continue? (y/n) :"; 
         cin>>ch; 
    }while(ch=='y'||ch=='Y'); 
 out.close(); 
}


void add()    /* As we are storing all enteries in a single file, every 2nd record needs to be appended. Else they get overwritten */
{ 
    out.open("blood.dat",ios::binary|ios::app); 
    do 
    { 
        D.read(); 
        out.write((char*)&D,sizeof(Donor)); 
        cout<<" Do you want to continue ? (y/n) :"; 
        cin>>ch; 
     }while(ch=='y'||ch=='Y'); 
out.close(); 
}

void search()      //Searching for a donor’s details
{ 
  char b[7]; 
  int flag=-1; 
  in.open("blood.dat",ios::binary); 
  cout<<" Enter the blood group to be searched "; 
  gets(b); 
  while(in.read((char*)&D,sizeof(Donor))) 
  { 
     if (strcmpi(D.ret_bog(),b)==0) 
      { flag=0; break; 
      } 
      else 
      flag=-1; 
  } 
  in.close(); 
  if(flag==0) 
       D.display(); 
  else 
        textcolor(14+BLINK); 
cprintf(" Sorry! Blood group not available.."); 
}



void count()     //Counting no. of donors in each blood group
{ 
  int a1=0,a2=0,b1=0,b2=0,ab1=0,ab2=0,o1=0,o2=0; 
  in.open("blood.dat",ios::binary); 
  while(in.read((char*)&D,sizeof(Donor))) 
 { 
if(strcmpi(D.ret_bog(),"A+")==0) a1++; 
else if(strcmpi(D.ret_bog(),"A-")==0) a2++; 
else if(strcmpi(D.ret_bog(),"B+")==0) b1++; 
else if(strcmpi(D.ret_bog(),"B-")==0) b2++; 
else if(strcmpi(D.ret_bog(),"O+")==0) o1++; 
else if(strcmpi(D.ret_bog(),"O-")==0) o2++; 
else if(strcmpi(D.ret_bog(),"AB+")==0) ab1++; 
else ab2++; 
} 
in.close(); 
textcolor(18); 
cprintf(" \n No. of A+ records : "); cout<<a1<<endl; 
cprintf(" No. of A- records : "); cout<<a2<<endl; 
cprintf(" No. of B+ records : "); cout<<b1<<endl; 
cprintf(" No. of B- records : "); cout<<b2<<endl; 
cprintf(" No. of O+ records : "); cout<<o1<<endl; 
cprintf(" No. of O- records : "); cout<<o2<<endl; 
cprintf(" No. of AB+ records: "); cout<<ab1<<endl; 
cprintf(" No. of AB- records: "); cout<<ab2<<endl; 
}

void Delete() {    //Deleting a donor entry.
char n[20]; 
in.open("blood.dat",ios::binary); 
out.open("temp.dat",ios::binary); 
cout<<"Enter the Donor Name to be deleted "; 
   gets(n); 
while(in.read((char*)&D,sizeof(Donor))) 
{ 
   if (strcmpi(D.ret_name(),n)!=0) 
       out.write((char*)&D,sizeof(Donor)); 
} 
textcolor(27+BLINK); 
cprintf("\n Record successfully deleted!!"); 
in.close(); 
out.close(); 
remove("blood.dat"); 
rename("temp.dat","blood.dat"); 
}


void disp()   
{ in.open("blood.dat",ios::binary); 
while(in.read((char*)&D,sizeof(Donor))) 
       D.display(); 
in.close(); 
}

void facts() {    //Random facts which could be displayed to get the effect of a blood bank.
textcolor(27+BLINK); 
cprintf(" \n \t \t \t DID YOU KNOW????? \n"); 
cout<<" \n \t \t \t ----------------- \n \n"; 
textcolor(18); 
cprintf(" O- are the universal donors! \n"); 
cprintf(" AB+ are the universal acceptors! \n"); 
cprintf (" 34.3 % of people have A+! \n"); 
cprintf (" 5.7 % of people have A-! \n"); 
cprintf (" 8.6 % of people have B+! \n"); 
cprintf (" 1.7 % of people have B-! \n"); 
cprintf (" 38.5 % of people have O+! \n"); 
cprintf (" 6.5 % of people have O-! \n"); 
cprintf (" 4.3 % of people have AB+! \n"); 
cprintf (" 0.7 % of people have AB-! \n"); 
}

void main() 
{ int y; clrscr(); int choice; 
do 
{ 
clrscr(); 
textcolor(20); 
cprintf(" MAIN MENU \n"); 
cprintf(" \n 1..... Create a new record \n"); 
cprintf(" \n 2..... Add a new record (append) \n" );
cprintf(" \n 3..... Search blood group \n"); 
cprintf(" \n 4..... Count Records \n"); 
cprintf(" \n 5..... Display donor details \n"); 
cprintf(" \n 6..... Delete old records \n"); 
cprintf(" \n 7..... Some facts \n"); 
cprintf(" \n 8..... Exit \n"); 
cprintf(" \n Enter your choice (1-8) : "); 
cin>>choice; 
switch(choice) 
{ case 1: clrscr(); 
              cout<<" \t \t ENTER THE DONOR DETAILS! \n "; 
             create(); 
break; 
case 2: clrscr(); 
cout<<" \t \t ENTER THE DONOR DETAILS! \n"; 
add(); 
break; 
case 3: clrscr(); 
cout<<" \t \t BLOOD GROUP SEARCH!! \n "; 
search(); 
break; 
case 4: clrscr(); 
cout<<" \t \t BLOOD GROUP COUNT \n "; 
count(); 
break; 
case 5: clrscr(); 
cout<<" \t \t DONOR DETAILS! \n "; 
disp(); 
break; 
case 6: clrscr(); 
cout<<" \t \t DELETE DONOR DETAILS! \n "; 
Delete(); 
break; 
case 7: clrscr(); 
cout<<" \t \t FACTS ABOUT BLOOD DONATION & BLOOD GROUP!! \n "; 
facts(); 
} 
getch(); 
}while(choice!=8); 
} 
}

