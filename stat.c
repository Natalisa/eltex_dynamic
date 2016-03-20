#include <stdio.h>
#include <dlfcn.h>

int main(){
  void* fd=dlopen("libcalc.so",RTLD_NOW);
  float (*add)(float*,float*)= dlsym(fd,"add");
  float (*sub)(float*,float*)= dlsym(fd,"sub");
  float (*mul)(float*,float*)= dlsym(fd,"mul");
  float a,b,rez;
  char zn;
  scanf("%f %c %f",&a,&zn,&b);
  if(zn=='+') rez=add(&a,&b);
  else if(zn=='-') {zn='+'; b=-b;rez=add(&a,&b);}
  else if(zn=='/') rez=sub(&a,&b);
  else if(zn=='*') rez=mul(&a,&b);
  printf("\n%f %c %f = %f\n",a,zn,b,rez);
  dlclose(fd);
  return 0;
}
