//based on the tutorial found in https://www.lynda.com/C-tutorials/C-Building-String-Library/379656-2.html
#ifndef __UTEST__
#define __UTEST__
#include<iostream>
#include<string>

const static std::string passStr_="pass";
const static std::string failStr_="fail";

class UnitTest
{
	unsigned long int passCount_;
	unsigned long int failCount_;
	unsigned long int passCountTotal_;
	unsigned long int failCountTotal_;
	unsigned long int numOfUnitsTested_;

	std::string unitTestTitle_;
	bool detailed_;
	std::ostream out;

public:
	UnitTest(std::ostream & stream=std::cout, bool detailed=false);
	void startUnit(std::string);
	void test(std::string title, bool flag);
	void unitReport();
	void finalReport();
	void detailed(bool);
	void redirectTo(std::ostream &);
	//add getters for all pass/fail counts



};


UnitTest::UnitTest(std::ostream & stream, bool detailed):passCount_(0), failCount_(0), passCountTotal_(0), failCountTotal_(0), numOfUnitsTested_(0), detailed_(detailed), out(NULL)
{
	out.rdbuf(stream.rdbuf());//redirect buffer   http://www.cplusplus.com/forum/beginner/120947/#msg658299

}

void UnitTest::redirectTo(std::ostream & stream)
{
	out.rdbuf(stream.rdbuf());//redirect buffer   http://www.cplusplus.com/forum/beginner/120947/#msg658299
}

void UnitTest::startUnit(std::string unitTitle)
{

	unitTestTitle_=unitTitle;
	numOfUnitsTested_++;
	passCountTotal_+=passCount_;
	failCountTotal_+=failCount_;
	passCount_=failCount_=0;
}
void UnitTest::test(std::string title, bool flag)
{
	std::string msg;
	if(flag)
	{
		passCount_++;
		msg=passStr_;
	}
	else
	{
		failCount_++;
		msg=failStr_;
	}

	if(detailed_) out<<unitTestTitle_<<": "<<title<<" -> "<<msg<<std::endl;
}

void UnitTest::detailed(bool flag)
{
	detailed_=flag;
}
void UnitTest::unitReport()
{
	out<<unitTestTitle_;
	out<<" [Pass: "<<passCount_;
	out<<", Fail: "<<failCount_<<"]"<<std::endl;
}

void UnitTest::finalReport()
{
	passCountTotal_+=passCount_;
	failCountTotal_+=failCount_;
	out<<"Final Report";
	out<<" [Pass: "<<passCountTotal_;
	out<<", Fail: "<<failCountTotal_<<"]"<<std::endl;
}

#endif //__UTEST__



