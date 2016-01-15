#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<unistd.h>
#include "passwd.h"
#ifdef CLR
#undef CLR
#endif
#define CLR system("clear");
using namespace std;
namespace shield{
  class _case{
    int id;char* name;int level_access;
  public:
    _case(int ,char* ,int);
    _case();
    ~_case();
    void add(int);
    int searchc(int);
    void pdetails(int,int);
    int adda(int);
  };

  void report();
  int nreports();

  class agent{
    int id;int level;char* name;char* password;
  public:
    agent(int,int,char *);
    agent();
    ~agent();
    void pmdetails(); //print my details
    void pdetails(); // print agent details
    void login();
    void work();
    void promote();
    void demote();
    void epassword(); //edit password
    void edetails(); //edit details 
    bool passwordc(passwd x);
    void fpwd();
    void displayo();
    int search(int);
    int searchd(int);
    char* encrypt(char *);
    char* decrypt(char *);
    char * aname();
    void freea();
    char iswork();
    void chatbox();
    int messages();
    int amsg(int);
    int cases();
  };
  void apply();
  int nappli();
}
