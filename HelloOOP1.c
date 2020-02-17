#include <iostream>


typedef struct UESRDATA
{
	int nAge;
	char szName[32];
}UESERDATA;

int main(void)
{
	UESERDATA user = { 20,"¿Á«ı" };
	std::cout << user.nAge << " " << user.szName << std::endl;

}