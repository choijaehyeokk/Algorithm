#include <iostream>


typedef struct UESRDATA
{
	int nAge;
	char szName[32];
}UESERDATA;

int main(void)
{
	UESERDATA user = { 20,"����" };
	std::cout << user.nAge << " " << user.szName << std::endl;

}