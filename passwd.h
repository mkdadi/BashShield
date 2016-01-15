//when using this header file you also have to compile passwd.c++
#include<stdio.h>
#include<iostream>
#ifndef MIN_PASSWD_LEN
#define MIN_PASSWD_LEN 6
#endif
#ifndef MAX_PASSWD_LEN
#define MAX_PASSWD_LEN 20
#endif
#ifndef NO_OF_NUMBERS
#define NO_OF_NUMBERS 1
#endif
#ifndef NO_OF_UALPHABETS
#define NO_OF_UALPHABETS 1
#endif
#ifndef NO_OF_LALPHABETS
#define NO_OF_LALPHABETS 1
#endif
#ifndef NO_OF_SYMBOLS
#define NO_OF_SYMBOLS 1
#endif
class passwd{
  char **pwd;
 protected:
  void operator=(const passwd&);
 public:
  passwd();
  passwd(const passwd &);
  ~passwd();
  bool check_validity();
  void tochar(char **);
  void get();
};
