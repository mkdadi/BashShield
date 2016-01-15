#include<stdio.h>
#include"shield.h"
#include<stdlib.h>
int main()
{
  FILE *p;
  p=fopen("/.shield/shield.txt","r");
  if(!p)
    {
      system("sudo mkdir /.shield");
      system("sudo chown $(whoami) /.shield");
      system("mkdir /.shield/agents /.shield/cases /.shield/reports /.shield/applications /.shield/messages /.shield/messages/10000");
      system("echo \"******************************* Welcome to S.H.I.E.L.D. *********************************\n\n      This is a Public service Organisation, established to solve all the problems of Public all over the World. S.H.I.E.L.D. started a major operation called \"AVENGERS\", because of which we still live. And S.H.I.E.L.D. also thanks all the Avengers for saving the World.\n\n     This Organisation is established by Madhu Kumar Dadi in 2015.He is the first Director, level 10 access, of S.H.I.E.L.D.\n\n         (c) All rights reserved to Madhu Kumar Dadi.\n\">> /.shield/shield.txt");
      system("echo \"shield\n10\ndirector\n11 11 1900\n\">> /.shield/agents/director.ddat");
      system(">> /.shield/agents/ag.dat");
      system(">> /.shield/agents/fa.dat");
      system(">> /.shield/agents/tmp.adat");
      system(">> /.shield/applications/ap.dat");
      system(">> /.shield/cases/cs.dat");
      system(">> /.shield/reports/rp.dat");
    }
  else
    fclose(p);
  int n;
  using namespace std;
  using namespace shield;
  CLR;
  cout<<"-----------------------------------------------------------------------\n*********** WELCOME to \'S.H.I.E.L.D.\', How can we help you? ***********\n-----------------------------------------------------------------------\n";
 a:
  cout<<"1.Director Login.\n2.Agent Login.\n3.Forgot Password.\n4.Details of S.H.I.E.L.D.\n5.Report a problem.\n6.Apply for S.H.I.E.L.D.\n7.Exit application.\n";
  cin>>n;
  switch(n){
  case 1:
    {
    CLR;
    agent x;
    int i;
    i=x.searchd(10000);
      {CLR;
	cout<<"Hello!, Director "<<x.aname()<<"\n";
	char c[20];
	passwd pwd;
	cout<<"Password: ";
	pwd.get();
	if(x.passwordc(pwd))
	  {
	    x.login();
	    CLR;
	    cout<<"Logged out successfully\n";
	  }
	else
	  {
           cout<<"Entered Password is wrong\n\nPress enter to continue....";
	   scanf("%*c%*c");
	   CLR;
           goto a;
          }
      }
   break;
    }
  case 2:
    {
    CLR;
    cout<<"Enter your ID: ";
    int jd;
    cin>>jd;
    agent y;
    int j;
    j=y.search(jd);
    if(!j)
      {CLR;
	cout<<"\aThe input ID doesn't exist.\n";
	cout<<"Sorry you have to Go back and try again.\n\nPress enter to continue......";
	scanf("%*c%*c");
	CLR;
        goto a;
      } 
    else
      {
       cout<<"Hello!, Agent "<<y.aname()<<"\n";
       if(j==2)
	{
	  y.epassword();
	}
	char c1[20];
	passwd pwd;
	cout<<"Password: ";
	pwd.get();
	if(y.passwordc(pwd))
	  {
	    y.login();
	    CLR;
	    cout<<"Logged out successfully\n";
	  }
	else
	  {
           cout<<"Entered Password is wrong\n\nPress enter to continue....";
	   scanf("%*c%*c");
	   CLR;
           goto a;
          }
      }
    break;
    }
  case 3:
    {
      agent x;
      x.fpwd();
      goto a;
    }
  case 4:
    {
    CLR;
    FILE *p;
    char c[100];
    p=fopen("/.shield/shield.txt","r");
    fscanf(p,"%[^\n]",c);
    while(!feof(p))
      {
	printf("%s\n",c);
        fscanf(p,"%*c%[^\n]",c);
      }
    fclose(p);
    cout<<"Press Enter to go back....";
    scanf("%*c%*c");
    CLR;
    break;
    }
  case 5:
    {
    CLR;
    report();
    break;
    }
  case 6:
    CLR;
    apply();
    break;
  case 7:
    CLR;
    cout<<"                 Thank you for using S.H.I.E.L.D.'s services\n";
    exit(0);
    break;
  default:
    CLR;
    cout<<"\aEnter a valid option\n";
    goto a;
    break;
  }
    goto a;
}
