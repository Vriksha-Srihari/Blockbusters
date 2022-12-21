//******************************************************
// This program displays ratings from four movie
// reviewers, lets the user select a menu option,
// then performs ratings calculations and displays
// ratings analytics.
//******************************************************
#include<fstream.h>
#include<string.h>
#include<iomanip.h>
#include<conio.h>
#include<graphics.h>
#include<process.h>
#include<stdio.h>
#include<dos.h>
#include<stdlib.h>

struct movie
{
 int no,rating[100],h,s;
 char name[60], review[100][100];
 float avgrat;
 /*movie()
 {
  for(int i=0;i<100;i++)
  {
   strcpy(review[i],"0");
   review[i][100]='\0';
   rating[i]=0;
  }
 }
 void input()
 {
 cout<<"Movie no: ";
 cin>>no;
 cout<<"Movie name: ";
 gets(name);
 cout<<"Enter reviews "<<endl;
 gets(review[0]); gets(review[1]); gets(review[2]);
 cout<<"Enter ratings: ";
 cin>>rating[0]>>rating[1]>>rating[2];
 } */
 void output()
 {  cout<<no<<". "<<name<<endl;  }
 void calcavg()
 {
 int i;
 h=s=rating[0];
 for(i=0;rating[i]!=0;i++)
 {
  //cout<<rating[i]; getch();
  if(rating[i]>=h)
  h=rating[i];
  if(rating[i]<=s)
  s=rating[i];
  }
 int sum,flag=0;
 for( i=0;rating[i]!=0;i++)
 { sum+=rating[i];
 flag++; }
 avgrat=sum/flag;
 }
 void displayrev()
 {
  cout<<"The reviews for "<<name<<" are: "<<endl;
  for(int i=0;strcmpi(review[i],"0")!=0;i++)
  cout<<i+1<<". "<<review[i]<<endl;
  cout<<endl;
  }
 void displayrat()
 {
 cout<<"\t\t"<<setw(4)<<no<<"      "<<setiosflags(ios::left)<<name/*<<"     "*/<<setw(22-strlen(name))<<setiosflags(ios::right)<<avgrat<<setw(10)<<setiosflags(ios::right)<<h<<setw(10)<<setiosflags(ios::right)<<s<<endl;
 }
/* int retno()
 {
  int flag=0,i;
  for(i=0;review[i]!=0;i++)
  flag++;
  return flag;
 }*/
 };
void welcome();
int language();
void displayRatings(int op);
void newRatings(int op,int mno);
void viewReview(int op,int mno);
void writeReview(int op,int mno);
void goodbye();

int DisplayMovie(int op)
{
clrscr();
int mno;
 fstream f;
if(op==1)
f.open("tamil.dat ",ios::in|ios::out|ios::binary);
else
f.open("english.dat ",ios::in|ios::out|ios::binary);

movie t;
f.seekg(0);
f.read((char*)&t,sizeof(t));
while(!f.eof())
{
t.output();
f.read((char*)&t,sizeof(t));
}
f.close();
cout<<"Enter your option (1-10): ";
cin>>mno;
if(mno<1||mno>10)
{ cout<<"Invalid entry. Enter again."<<endl;
  cin>>mno;
}
return mno;
}
/*int DisplayEnglish()
{
clrscr();
int mno;
fstream f("english.dat ",ios::in|ios::out|ios::binary);
movie t;
f.seekg(0);
f.read((char*)&t,sizeof(t));
while(!f.eof())
{
t.output();
f.read((char*)&t,sizeof(t));
}
f.close();
cout<<"Enter your option (1-10): ";
cin>>mno;
if(mno<1||mno>10)
{ cout<<"Invalid entry. Enter again."<<endl;
  cin>>mno;
}  return mno; }  */


void main()
{
clrscr();
int gdriver = DETECT, gmode, errorcode;
initgraph(&gdriver, &gmode, "c:\\turboC3\\bgi");
welcome();
int choice;

function2:		     //for changing language preference
//cout<<"lang change"; getch();
int op,mno;
op=language();
//if(op==1)
// setbkcolor(15); setcolor(1);
		   //for changing movie pref. but same language
function1:
// cout<<"movie change"; getch();
mno=DisplayMovie(op);
//else
//mno=DisplayEnglish();

	 // user choice of menu options
char ch;
   do
{
	clrscr();
		//program interface with menu options
	cout<<"\n\n\n\n\n\t\t---------------------------------------------------"<<endl;
	cout<<"\t\tHey Perry, what shall we do today?"<<endl;
	cout<<"\t\t---------------------------------------------------"<<endl;
	cout<<"\t\t1. View highest, lowest and average rating for all the movies"<<endl;
	cout<<"\t\t2. Enter new rating for chosen movie"<<endl;
	cout<<"\t\t3. View reviews for chosen movie"<<endl;
	cout<<"\t\t4. Write new review for chosen movie"<<endl;
	cout<<"\t\t5. Choose another movie of the SAME language"<<endl;
	cout<<"\t\t6. Change language preference"<<endl;
	cout<<"\t\t7. Quit program"<<endl;
	cout<<endl<<"\t\tEnter your choice: ";
	cin>>choice;
	cout << endl;
	switch (choice)
	{
	    case 1 : displayRatings(op);
		     break;
	    case 2 : newRatings(op,mno);
		     break;
	    case 3 : viewReview(op,mno);
		     break;
	    case 4 : writeReview(op,mno);
		     break;
	    case 5 : goto function1;
		     break;
	    case 6 : goto function2;
		     break;
	    case 7 : goodbye();
		    break;
	    default : cout << "Please enter a choice from 1 to 7. ";
	}
     cout<<"\n\t\t\tShall we continue?(y/n): ";
     cin>>ch;
     if(ch=='n'||ch=='N')
     goto function1;
 }while(ch=='y'||ch=='Y') ;
 }


void welcome()
  {
clrscr();
 int gdriver=DETECT, gmode, errorcode;
//int bkcol, maxcolor, x, y;
char msg[][50]={"Welcome to ","Blockbusters"};
initgraph(&gdriver, &gmode, "c:\\turboC3\\bgi");

      setbkcolor(11);
       for(int i=0;i<400;i+=20)
       {
      //cleardevice();
      settextstyle(4,0,7);
      setcolor(8);
      outtextxy(170, 100, msg[0]);
      settextstyle(4,0,9);
      setcolor(8);
      outtextxy(80, 200, msg[1]);
      setcolor(i);
      rectangle(getmaxx()/2-269,getmaxy()/2-189,getmaxx()/2+269,getmaxy()/2+189);
      rectangle(getmaxx()/2-279,getmaxy()/2-199,getmaxx()/2+279,getmaxy()/2+199);
      setcolor(i+2);
      settextstyle(3,0,3);
      outtextxy(220, 380, "<<< Let's Go >>>");
      delay(500);
      }
     getch();
 }


int language()
{
clrscr();
 int gdriver=DETECT, gmode, errorcode;
int op; char ans[2];
char msg[]="Choose A Language";
initgraph(&gdriver, &gmode, "c:\\turboC3\\bgi");

      setbkcolor(12);
      settextstyle(5,0,5);
      setcolor(8);
      outtextxy(120, 100, msg);
      setcolor(1);
      settextstyle(4,0,3);
      outtextxy(120, 200, "1.Tamil");
      setcolor(1);
      settextstyle(4,0,3);
      outtextxy(320, 200, "2.English");
      //getch();
      setcolor(2);
      settextstyle(1,0,3);
      outtextxy(120, 300, "Choose an option(1/2): ");
      ans[0]=getch();
      ans[1]='\0';
      outtextxy(400,300,ans);
      op=atoi(ans);
      getch();
     return op;
 }



void displayRatings(int op)
 {
 clrscr();
   fstream f;
   if(op==1)
   f.open("tamil.dat",ios::in|ios::out|ios::binary);
   else
   f.open("english.dat",ios::in|ios::out|ios::binary);
   f.seekg(0);
   movie t;
   f.read((char*)&t,sizeof(t));
   cout<<"\n\n\n\t\t"<<setw(62)<<setfill('-')<<" "<<endl;
   cout<<"\t\t"<<setw(62)<<setfill(' ')<<" "<<endl;
   cout<<"\t\t"<<"Movie     Movie            Average    Highest    Lowest"<<endl;
   cout<<"\t\t"<<"No.       Name             Ratings    Rating     Rating"<<endl;
   cout<<"\t\t"<<setw(62)<<setfill('-')<<" "<<endl;
   cout<<"\t\t"<<setw(62)<<setfill(' ')<<" "<<endl;
   while(!f.eof())
   {
    t.calcavg();
    t.displayrat();
    f.read((char*)&t,sizeof(t));
    }
    f.close();
    getch();
  }

void newRatings(int opt, int mno)
 {
  movie t,x; fstream f1;
 char rev[1000]; int i,rat;
 if(opt==1)
 f1.open("tamil.dat",ios::in|ios::out|ios::binary|ios::ate);
 else
 f1.open("english.dat",ios::in|ios::out|ios::binary|ios::ate);

   f1.seekg(0);
   f1.read((char*)&t,sizeof(t));
   while(!f1.eof())
   {
     if(t.no==mno)
    {
      x=t;
      cout<<"Enter your ratings for "<<t.name<<" (from 1-5 only)"<<endl;
      cin>>rat;
      if(rat<1||rat>5)
      { cout<<"Invalid entry. Please rate only from 1-5 "<<endl;
	cin>>rat;}
      for(i=0;t.rating[i]!=0;i++);
      x.rating[i]=rat;
      f1.seekp(f1.tellg()-sizeof(t));
      f1.write((char*)&x,sizeof(x));
      break;
   }
   f1.read((char *)&t,sizeof(t));
  } f1.close();
 cout<<"\n\t\tThank You! Your rating has been noted!"<<endl;
/* }
 else
 {
   f2.seekg(0);
   f2.read((char*)&t,sizeof(t));
   while(!f2.eof())
   {
     if(t.no==mno)
    {
      x=t;
      cout<<"Enter your ratings"<<endl;
      cin>>rat;
      for(i=0;t.rating[i]!=0;i++);
      x.rating[i]=rat;
      f2.seekp(f2.tellg()-sizeof(t));
      f2.write((char*)&x,sizeof(x));
      break;
   }
   f2.read((char*)&t,sizeof(t));
  } f2.close();
   }*/ }

 void viewReview(int opt, int mno)
{
 movie t; fstream f1;
 if(opt==1)
 f1.open("tamil.dat",ios::in|ios::out|ios::binary);
 else
 f1.open("english.dat",ios::in|ios::out|ios::binary);

   f1.seekg(0);
   f1.read((char*)&t,sizeof(t));
   while(!f1.eof())
   {
     if(t.no==mno)
    { t.displayrev();
      break; }
     f1.read((char*)&t,sizeof(t));
   }
   f1.close();
   getch();
/*  }
 else
 {
   f2.seekg(0);
   f2.read((char*)&t,sizeof(t));
   while(!f2.eof())
   {
     if(t.no==mno)
    { t.displayrev();
      break; }
     f2.read((char*)&t,sizeof(t));
   }
   f2.close();
  }*/ }

void writeReview(int opt, int mno)
{
 movie t,x; fstream f1;
 char rev[1000]; int i;
 if(opt==1)
 f1.open("tamil.dat",ios::in|ios::out|ios::binary|ios::ate);
 else
 f1.open("english.dat",ios::in|ios::out|ios::binary|ios::ate);

   f1.seekg(0);
   f1.read((char*)&t,sizeof(t));
   while(!f1.eof())
   {
     if(t.no==mno)
    {
      x=t;
      cout<<"Enter new review for "<<t.name<<endl;
      gets(rev);
      for(i=0;strcmpi(t.review[i],"0")!=0;i++);
      strcpy(x.review[i],rev);
      f1.seekp(f1.tellg()-sizeof(t));
      f1.write((char*)&x,sizeof(x));
      break;
   }
   f1.read((char*)&t, sizeof(t));
  } f1.close();
  cout<<"\n\t\tThank You! Your review has been noted!"<<endl;
/*  }
 else
 {
   f2.seekg(0);
   f2.read((char*)&t,sizeof(t));
   while(!f2.eof())
   {
     if(t.no==mno)
    {
      x=t;
      cout<<"Enter new review for "<<t.name<<endl;
      gets(rev);
      for(i=0;strcmpi(t.review[i],"0")!=0;i++);
      strcpy(x.review[i],rev);
      f2.seekp(f2.tellg()-sizeof(t));
      f2.write((char*)&x,sizeof(x));
      break;
   }
   f2.read((char*)&t, sizeof(t));
  } f2.close();
   }*/ }

void goodbye()
{
clrscr();
 int gdriver=DETECT, gmode, errorcode;
int bkcol, maxcolor, x, y;
char msg[]="Hasta la Vista, Baby ;D";
initgraph(&gdriver, &gmode, "c:\\turboC3\\bgi");

       setbkcolor(4);
       for(int i=0;i<18;i++)
       {
      setcolor(15);
      circle(50*i,50,50);
      settextstyle(2,0,10);
      setcolor(11);
      outtextxy(60, 200, msg);
      setcolor(15);
      circle(50*i,getmaxy()-50,50);
      delay(400);
      }
     exit(0);
 }