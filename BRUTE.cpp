/**************************************
Author: Dimple (23711)
PGDCSL(23-24)
**************************************/

//Header files section
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<iostream.h>
#include<stdlib.h>
#include<dos.h>
#include<ctype.h>

//Global variable declation
long int rpass=123,hpass=0,tpass=0,thpass=0,gpass=0,ghpass=0;
// r-real, t-temp, g-guess, h-hash,pass-password
char command[15];
int count=10,choice;

//function declation
void bo(int x1, int y1,int x2,int y2);
void lin(int x1, int y1, int x2);
void pa(void);
long int conv(long n);

//Main section
void main()
{
  while(!kbhit())
  {
    clrscr();
    hpass = conv(rpass);
    gotoxy(31,7);
    cout<<"........Tool Menu........";
    bo(20,5,65,23);
    lin(20,9,65);
    lin(20,19,65);
    gotoxy(30,11);
    cout<<"1.Administator tool";
    gotoxy(30,13);
    cout<<"2.Login page";
    gotoxy(30,15);
    cout<<"3.Start Brute force";
    gotoxy(30,17);
    cout<<"4.Exit";
    gotoxy(28,19);
    cout<<"  Please enter your choice  ";
    gotoxy(30,21);
    cin>>choice;
    switch(choice)
    {
      case 1:
      {
        clrscr();
        gotoxy(25,7);
        cout<<"Enter the new password to change";
        bo(20,5,65,23);
        lin(20,9,65);
        bo(30,13,55,16);
        gotoxy(32,14);
        cout<<"Username: Admin ";
        gotoxy(32,15);
        cout<<"Password:       ";
        gotoxy(42,15);
        cout<<"******";
        lin(20,19,65);
        gotoxy(42,15);
        cin>>rpass;
        hpass = conv(rpass);
        break;
      }
      case 2:
      {
        clrscr();
        gotoxy(30,7);
        cout<<"Login page";
        bo(20,5,65,23);
        lin(20,9,65);
        bo(30,13,55,16);
        gotoxy(32,14);
        cout<<"Username: Admin ";
        gotoxy(32,15);
        cout<<"Password:       ";
        gotoxy(42,15);
        cout<<"******";
        lin(20,19,65);
        gotoxy(42,15);
        cin>>tpass;
        thpass=conv(tpass);
        if(hpass!=thpass)
        {
          gotoxy(23,20);
          cout<<"The username and password did not match!";
        }
        else
        pa();
        delay(1000);
        break;
      }
      case 3:
      {
        gotoxy(35,20);
        cout<<"Loading terminal...";
        for(int k=22;k<64; k++)
        {
          gotoxy(k,21);
          putch(176);
        }
        for(k=22;k<64;k++)
        {
          gotoxy(k,21);
          putch(219);
          delay(100);
        }
        clrscr();
        cout<<"Enter command to start brute force attack: ";
        cin>>command;
        while(kbhit)
        {
          ghpass=conv(gpass);
          if(hpass==ghpass)
          {
          cout<<">> airtack -login - user 'Admin' - password '"<<gpass<<"' - Athentication Success.\n\nPassword is found as: "<<gpass<<endl;
          delay(10000);
          break;
          }
          else
          {
            cout<<">> airtack -login - user 'Admin' - password '"<<gpass<<"' - Access Denied "<<endl;
            gpass++;
            if(count>0)
            {
              delay(1500);
              count--;
            }
          }
        }
        break;
      }
      case 4:
      exit(0);
      break;
      default:
      {
        clrscr();
        gotoxy(25,5);
        printf("Invalid choice...!");
        getche();
        break;
      }

    }
  }
  getch();
}
//function to display the victim website
void pa(void)
{
  clrscr();
  cout<<"\n\nPost Graduate Diploma in Cyber Security and Law(PGDCSL)-sscbs- Puttur\n"<<endl;
  cout<<"Dimple Prakshita student of sscbs. Persuning in PGDCSL(23-24).";
  cout<<"\n\nUser\tPassword\nAdmin\t"<<hpass;
  delay(5000);
}
//function to draw the box as dialog box
void bo(int x1, int y1, int x2, int y2)
{
	int x;
	gotoxy(x1,y1);putch(201);
  	gotoxy(x2,y1);putch(187);
	gotoxy(x1,y2);putch(200);
  	gotoxy(x2,y2);putch(188);
	for(x=x1+1;x<x2;x++)
  {
    gotoxy(x,y1);
    putch(205);
    gotoxy(x,y2);
    putch(205);
  }
	for(x=y1+1;x<y2;x++)
  {
    gotoxy(x1,x);
    putch(186);
    gotoxy(x2,x);
    putch(186);
  }
}
//function to dreaw the line which combine with the box
void lin(int x1,int y1,int x2)
{
  int k;
  gotoxy(x1,y1);
  putch(204);
  gotoxy(x2,y1);
  putch(185);
  for(k=x1+1;k<x2;k++)
  {
    gotoxy(k,y1);
    putch(205);
  }
}
long int conv(long n)
{
  long int rem,i=1,oct=0;
  n = n + 360;
  while (n!=0)
  {
    rem = n%2;
    n=n/2;
    oct = oct+(rem*i);
    i=i*10;
  }
  return oct;
}
