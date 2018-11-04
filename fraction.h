#ifndef FRACTION_H_INCLUDED
#define FRACTION_H_INCLUDED
class fraction{
private:
    unsigned long _deno;
    unsigned long _nume;
    bool _negative;
public:
fraction(){
_deno=1;
_nume=0;
_negative=false;
}

fraction(unsigned long nume,unsigned long deno,bool negative){
if(deno==0){
    perror("divided by 0");
    exit(0);
}
_nume=nume;
_deno=deno;
_negative=negative;
return;
}

fraction(unsigned long nume,bool negative){
_nume=nume;
_deno=1;
_negative=negative;
return;
}


    void equals(unsigned long nume,bool negative);
    void equals(unsigned long deno,unsigned long nume,bool negative);
    unsigned long deno();
    unsigned long nume();
    char sign();
    bool sign_bool();
    void reduce();
};

bool fraction::sign_bool(){
return _negative;
}

char fraction::sign(){
if(_negative){
    return'-';
}else{
return'+';
}
}

fraction neg(fraction a){
fraction result;
result.equals(a.nume(),a.deno(),!(a.sign_bool()));
return result;
}

unsigned long fraction::deno(){
return _deno;
}

unsigned long fraction::nume(){
return _nume;
}

void fraction::equals(unsigned long nume,bool negative){
_deno=1;
_nume=nume;
_negative=negative;
return;
}

void fraction::equals(unsigned long nume,unsigned long deno,bool negative){
_deno=deno;
_nume=nume;
_negative=negative;
return;
}

unsigned long gcd(unsigned long a,unsigned long b){
if(a<b){
    long z=a;
    a=b;
    b=z;
}
unsigned long r=1;
while(1){
    r=a%b;
    if(r==0)
        return b;
    a=b;
    b=r;
}
}

void fraction::reduce(){
    if(_nume==0)return;
unsigned long cf=gcd(nume(),deno());
_nume/=cf;
_deno/=cf;
return;
}

fraction fc_multiply(fraction a,fraction b){
fraction result;
a.reduce();
b.reduce();
unsigned long deno=a.deno()*b.deno();
unsigned long nume=a.nume()*b.nume();
bool sign=false;
if(a.sign()=='+'&&b.sign()=='-')
    sign=true;
if(a.sign()=='-'&&b.sign()=='+')
    sign=true;
    if(nume==0)
       sign=false;
result.equals(nume,deno,sign);
result.reduce();
return result;
}
long abs(long n){
return(n<0)?-n:n;
}
fraction fc_multiply(fraction a,long n){
fraction result;
a.reduce();
    if(n==0){
result.equals(0,1,false);
        return result;
    }
    bool negative=a.sign_bool();
    if(n<0){
        negative=!negative;
    }
    if(a.nume()==0)
        negative=false;
n=abs(n);
    unsigned long cf=gcd(a.deno(),(unsigned long)n);
    unsigned long deno=a.deno()/cf;
    n/=cf;
    result.equals(a.nume()*n,deno,negative);
return result;
}

fraction fraction_add_without_sign(fraction a,fraction b){
    fraction result;
    unsigned long deno=a.deno()*b.deno();
    unsigned long nume=a.nume()*b.deno()+b.nume()*a.deno();
    result.equals(nume,deno,false);
    result.reduce();
return result;
}

fraction fraction_sub_without_sign(fraction a,fraction b){
    fraction result;
    unsigned long deno=a.deno()*b.deno();
    unsigned long nume=a.nume()*b.deno()-b.nume()*a.deno();
    result.equals(nume,deno,false);
    result.reduce();
return result;
}

bool is_A_bigger_no_sign(fraction A,fraction B){
return(A.nume()*B.deno()>B.nume()*A.deno());
}

fraction fc_add(fraction a,fraction b){
fraction i;
bool negative;
if(a.sign()=='+'&&b.sign()=='+'){
i=fraction_add_without_sign(a,b);
negative=false;
}
if(a.sign()=='+'&&b.sign()=='-'){
if(is_A_bigger_no_sign(a,b)){
 negative=false;
i=fraction_sub_without_sign(a,b);
}else{
     negative=true;
i=fraction_sub_without_sign(b,a);
}
}

if(a.sign()=='-'&&b.sign()=='+'){
        a=neg(a);
        b=neg(b);
if(is_A_bigger_no_sign(a,b)){
 negative=false;
i=fraction_sub_without_sign(a,b);
}else{
     negative=true;
i=fraction_sub_without_sign(b,a);
}
negative=!negative;
}

if(a.sign()=='-'&&b.sign()=='-'){
i=fraction_add_without_sign(neg(a),neg(b));
negative=true;
}
fraction result;
if(i.nume()==0)
    negative=false;
result.equals(i.nume(),i.deno(),negative);
return result;
}

fraction fc_sub(fraction a,fraction b){
b=neg(b);
return fc_add(a,b);
}



void fc_print(fraction a){
    if(a.sign()=='+'){
    if(a.deno()==1)
            std::cout<<a.nume();
    else
    std::cout <<"("<<a.nume()<<"/"<<a.deno()<<")";
    }else{
        if(a.deno()==1)
            std::cout<<"-"<<a.nume();
    else
    std::cout <<"(-"<<a.nume()<<"/"<<a.deno()<<")";

    }
return;
}

void fc_print_endl(fraction a){
fc_print(a);
std::cout<<std::endl;
return;
}

void fc_add_print(fraction a,fraction b){
a.reduce();
b.reduce();
fc_print(a);
std::cout<<"+";
fc_print(b);
std::cout<<"=";
fc_print(fc_add(a,b));
std::cout<<std::endl;
}

void fc_sub_print(fraction a,fraction b){
a.reduce();
b.reduce();
fc_print(a);
std::cout<<"-";
fc_print(b);
std::cout<<"=";
fc_print(fc_sub(a,b));
std::cout<<std::endl;
}

void fc_multiply_print(fraction a,fraction b){
a.reduce();
b.reduce();
fc_print(a);
std::cout<<"*";
fc_print(b);
std::cout<<"=";
fc_print(fc_multiply(a,b));
std::cout<<std::endl;
}

fraction fc_divide(fraction a,fraction b){
fraction n;
    if(b.nume()==0){
    perror("invalid fraction");
    exit(0);
}    else
    n.equals(b.deno(),b.nume(),b.sign_bool());
return fc_multiply(a,n);
}

#endif // FRACTION_H_INCLUDED
