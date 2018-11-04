#include <iostream>
#include"fraction.h"
#include"formula_solver.h"
using namespace std;

int main()
{
fraction a(1,false),b(2,true),c(1,false);
linear(a,b);
quad(a,b,c);
    return 0;
}
