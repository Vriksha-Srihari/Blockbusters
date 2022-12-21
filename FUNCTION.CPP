#include<graphics.h>
#include<iostream.h>
#include<conio.h>
#include<dos.h>
struct movie
{
 int no,rating[100],h,s;
 char name[60], review[100][100];
 float avgrat;
 movie()
 {
  for(int i=0;i<100;i++)
  {
   strcpy(review[i],"0");
   rating[i]=0;
  }}
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
 }
 void calcavg()
 {
 int i;
 h=s=rating[1];
 for( i=0;rating[i]!=0;i++)
 {
  if(rating[i]>=h)
  h=rating[i];
  if(rating[i]<=s)
  s=rating[i];
  }
 int sum,flag=0;
 for( i=0;rating[i]!=0;i++)
 {sum+=rating[i];
 flag++;}
 avgrat=sum/flag;
 }
 void displayrev()
 {
  cout<<"The reviews for "<<name<<" are: "<<endl;
  for(int i=0;review[i]!=0;i++)
 { cout<<i+1<<". "<<review[i]<<endl;
  cout<<endl; }
  }
 void displayrat()
 {
 float avg; avg=calcavg();
 cout<<setw(4)<<no<<"     "<<setiosflags(ios::left)<<name<<setw(19-strlen(name))<<setiosflags(ios::right)<<avg<<setw(10)<<setiosflags(ios::right)<<h<<setw(10)<<setiosflags(ios::right)<<s<<endl;
 }
 int retno()
 {
  int flag=0,i;
  for(i=0;review[i]!=0;i++)
  flag++;
  return flag;
 }
 };


/*void main()
{
 clrscr();
 int gdriver=DETECT, gmode, errorcode;
int bkcol, maxcolor, x, y;
char msg[80];
initgraph(&gdriver, &gmode, "c:\\turboC3\\bgi");

      for(int i=0;i<16;i++)
      {
       delay(500);
       setbkcolor(i);

      if (getbkcolor() == WHITE)
	 setcolor(EGA_BLUE);

      outtextxy(getmaxx()/2, getmaxy()/2, "OK"); }
      getch();

} */
//welcome()
void main()
{
clrscr();
 int gdriver=DETECT, gmode, errorcode;
int bkcol, maxcolor, x, y;
char msg[]="Welcome to Blockbusters";
initgraph(&gdriver, &gmode, "c:\\turboC3\\bgi");

       setbkcolor(10);
       for(int i=0;i<18;i++)
       {
      cleardevice();
      settextstyle(2,0,i);
      setcolor(i);
      outtextxy(60, 125, msg);
      delay(400);
      }
      setcolor(4);
      settextstyle(3,0,3);
      outtextxy(220, 400, "<<< Let's Go >>>");
     getch();
 }


int language()
//void main()
{
clrscr();
 int gdriver=DETECT, gmode, errorcode;
int op;
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
     cin>>op;
     return op;
 }


 displayAverageRatings(int op)
 {
   if(op==1)
   fstream f("tamil.dat",ios:in|ios:out|ios:binary|ios:app);
   else
   fstream f("english.dat",ios:in|ios:out|ios:binary|ios:app);
   f.seekg(0);
   movie t;
   f.read((char*)&t,sizeof(t));
   cout<<setw(70)<<seetfill('-')<<" "<<endl;
   cout<<setw(70)<<seetfill(' ')<<" "<<endl;
   cout<<"Movie no.    Movie Name    Average Ratings"<<endl;
   cout<<setw(70)<<seetfill('-')<<" "<<endl;
   cout<<setw(70)<<seetfill(' ')<<" "<<endl;
   while(!f.eof())
   {
    t.displayrat();
    f.read((char*)&t,sizeof(t));
    }
    f.close();
  }




 ChangeRev(int opt, int mno,int rno)
 {
 movie t,x;
 char rev[1000];
 fstream f1("tamil.dat",ios:in|ios:out|ios:binary|ios:app);
 fstream f2("english.dat",ios:in|ios:out|ios:binary|ios:app);
 if(opt==1)
 {
   f1.seekg(0);
   f1.read((char*)&t,sizeof(t));
   while(!f1.eof())
   {
     if(t.no==mno)
     {
      x=t;
      cout<<"Enter your reviews"<<endl;
      gets(rev);
      strcpy(x.review[rno],rev);
      f1.write((char*)&x,sizeof(x));
     }
   f1.read((char*)&t,sizeof(t));
 }
 f1.close();
}
else
{
   f2.seekg(0);
   f2.read((char*)&t,sizeof(t));
   while(!f2.eof())
   {
     if(t.no==mno)
     {
      x=t;
      cout<<"Enter your reviews"<<endl;
      gets(rev);
      strcpy(x.review[rno],rev);
      f2.write((char*)&x,sizeof(x));
     }
   f2.read((char*)&t,sizeof(t));
 }
 f2.close();
}}

DispRev(int opt, int mno)
{
 movie t;
 fstream f1("tamil.dat",ios:in|ios:out|ios:binary|ios:app);
 fstream f2("english.dat",ios:in|ios:out|ios:binary|ios:app);
 if(opt==1)
 {
   f1.seekg(0);
   f1.read((char*)&t,sizeof(t));
   while(!f1.eof())
   {
     if(t.no==mno)
     t.displayrev();
     f1.read((char*)&t,sizeof(t));
   }
   f1.close();
  }
 else
 {
   f2.seekg(0);
   f2.read((char*)&t,sizeof(t));
   while(!f2.eof())
   {
     if(t.no==mno)
     t.displayrev();
     f2.read((char*)&t,sizeof(t));
   }
   f2.close();
  } }


WriteRev(int opt, int mno)
{
 movie t,x;
 char rev[1000]; int pos;
 fstream f1("tamil.dat",ios:in|ios:out|ios:binary|ios:app);
 fstream f2("english.dat",ios:in|ios:out|ios:binary|ios:app);
 if(opt==1)
 {
   f1.seekg(0);
   f1.read((char*)&t,sizeof(t));
   while(!f1.eof())
   {
     if(t.no==mno)
    {
      x=t;
      cout<<"Enter new review"<<endl;
      gets(rev);
      pos=t.retno1();
      strcpy(x.review[pos],rev);
      f1.write((char*)&x,sizeof(x));
   }
   f1.close();
  }
 else
 {
   f2.seekg(0);
   f2.read((char*)&t,sizeof(t));
   while(!f2.eof())
   {
     if(t.no==mno)
    {
      x=t;
      cout<<"Enter new review"<<endl;
      gets(rev);
      pos=t.retno1();
      strcpy(x.review[pos],rev);
      f2.write((char*)&x,sizeof(x));
   }
   f2.close();
  } }


 GiveRatings(int opt, int mno)
 {
  movie t,x;
 char rev[1000]; int pos,rat;
 fstream f1("tamil.dat",ios:in|ios:out|ios:binary|ios:app);
 fstream f2("english.dat",ios:in|ios:out|ios:binary|ios:app);
 if(opt==1)
 {
   f1.seekg(0);
   f1.read((char*)&t,sizeof(t));
   while(!f1.eof())
   {
     if(t.no==mno)
    {
      x=t;
      cout<<"Enter your ratings"<<endl;
      cin>>rat;
      pos=t.retno2();
      x.review[pos]=rat;
      f1.write((char*)&x,sizeof(x));
   }
   f1.close();
  }
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
      pos=t.retno2();
      x.review[pos]=rat;
      f2.write((char*)&x,sizeof(x));
   }
   f2.close();
  } }


goodbye()
//
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
     exit(0);;
 }



