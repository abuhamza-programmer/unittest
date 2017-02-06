#include<iostream>
#include"UnitTest.h"
#include<fstream>

int main()
{

UnitTest u1(std::cout,true);


u1.startUnit("operator<");
u1.test("1<2", 1<2);
u1.test("3<2", 2<2);
u1.test("-1<-2", -1<-2);
u1.test("-2<-2", -2<-2);

u1.unitReport();


u1.startUnit("operator==");
u1.test("1==2", 1==2);
u1.test("3==3", 3==3);
u1.test("A==b", 'A'=='b');



u1.unitReport();
//ofstream out("log.txt");
//u1.redirectTo(out);

//u1.detailed(false);

u1.startUnit("operator<=");
u1.test("1<=2", 1<=2);
u1.test("3<=2", 3<=2);
u1.test("-1<=-2", -1<=-2);
u1.test("-2<=-2", -2<=-2);

u1.unitReport();




u1.finalReport();

	return 0;
}

