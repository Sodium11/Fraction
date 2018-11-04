#ifndef FORMULA_SOLVER_H_INCLUDED
#define FORMULA_SOLVER_H_INCLUDED
#include"fraction.h"

long root_1(unsigned long a){
long n=0;
while(n*n<a){
    n++;
}
if(n*n==a)
    return n;
else
    return -1;
}

fraction root(fraction a){
fraction result;
long deno=root_1(a.deno());
long nume=root_1(a.nume());
if(deno==-1||nume==-1){
result.equals(0,0,false);
}else{
result.equals(nume,deno,false);
}
return result;
}

void fc_root_print(fraction a){
fraction result;
long deno=root_1(a.deno());
long nume=root_1(a.nume());
if(deno==-1||nume==-1){
std::cout<<"root(";
fc_print(a);
std::cout<<")";
}else{
result.equals(nume,deno,false);
fc_print(result);
}
return;
}

void fc_print_sign(fraction a){
    if(a.deno()==1)
    std::cout<<a.sign()<<a.nume();
    else
    std::cout <<a.sign()<<"("<<a.nume()<<"/"<<a.deno()<<")";
return;
}

void fc_print_formula(fraction a){
 if(a.nume()==a.deno())
    std::cout<<a.sign();
 else
 fc_print_sign(a);
 return;
}



void linear(fraction a,fraction b){//a*x+b=0
fc_print_formula(a);
std::cout<<"x";
fc_print_sign(b);
std::cout<<"=0"<<std::endl;

std::cout<<"x=";
fraction answer=fc_divide(neg(b),a);
fc_print_endl(answer);

return;
}

void quad(fraction a,fraction b,fraction c){//a*x^2+b*x+c=0
fc_print_formula(a);
std::cout<<"x^2";
fc_print_formula(b);
std::cout<<"x";
fc_print_sign(c);
std::cout<<"=0"<<std::endl;
fraction D=fc_sub(fc_multiply(b,b),fc_multiply(fc_multiply(a,c),4));
fraction root_D=root(D);

std::cout<<"x=";
if(root_D.deno()==0){
std::cout<<"(";
fc_print(neg(b));
std::cout<<"+";
fc_root_print(D);
std::cout<<")/";
fc_print(fc_multiply(a,2));
}else{
fc_print(fc_divide(fc_add(neg(b),root_D),fc_multiply(a,2)));
}
if(D.nume()!=0){
        std::cout<<",";

if(root_D.deno()==0){
std::cout<<"(";
fc_print(neg(b));
std::cout<<"-";
fc_root_print(D);
std::cout<<")/";
fc_print(fc_multiply(a,2));
}else{
fc_print(fc_divide(fc_sub(neg(b),root_D),fc_multiply(a,2)));
}
}

return;
}
#endif // FORMULA_SOLVER_H_INCLUDED
