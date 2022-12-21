#include<fstream.h>
#include<conio.h>
#include<string.h>
#include<dos.h>
#include<stdio.h>
#include<process.h>
#include<graphics.h>
#include<stdlib.h>
#include<iomanip.h>
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
 }  */
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
 void output()
 {  cout<<no<<". "<<name<<endl;  }
 void calcavg()
 {
 int i;
 h=s=rating[0];
 for( i=0;rating[i]!=0;i++)
 {
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
  for(int i=0;review[i]!=0;i++)
 { cout<<i+1<<". "<<review[i]<<endl;
  cout<<endl; }
  }
 void displayrat()
 {
 cout<<setw(4)<<no<<"     "<<setiosflags(ios::left)<<name<<"\t\t\t"<<setw(19-strlen(name))<<setiosflags(ios::right)<<avgrat<<setw(10)<<setiosflags(ios::right)<<h<<setw(10)<<setiosflags(ios::right)<<s<<endl;
 }
/* int retno()
 {
  int flag=0,i;
  for(i=0;review[i]!=0;i++)
  flag++;
  return flag;
 }*/
 };


 void main()
{
 int gdriver=DETECT, gmode, errorcode;
 char msg[][50]={"Loading ","Awesomeness..."};
 initgraph(&gdriver, &gmode, "c:\\turboC3\\bgi");
      setbkcolor(15);
      settextstyle(3,0,5);
      setcolor(1);
      outtextxy(250, 100, msg[0]);
      settextstyle(1,0,7);
      setcolor(1);
      outtextxy(120, 200, msg[1]);
      delay(3000);
}
