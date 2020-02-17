
#include "CMyStringEx.h"
#include <string.h>

CMyStringEx::CMyStringEx()
{
}
CMyStringEx::~CMyStringEx()
{
}
CMyStringEx::CMyStringEx(const char *pszParam)
	:CMyString(pszParam)
{

}
int CMyStringEx::Find(const char *pszParam)
{
	if (pszParam == NULL || GetString() == NULL)
	{
		return -1;
	}
	const char *pszResult = strstr(GetString(), pszParam);

	if (pszResult != NULL)
	{
		return pszResult - GetString();
	} 

	return -1;
}
int CMyStringEx::SetString(const char *pszParam)
{
	int nResult;

	if (strcmp(pszParam, "�۸��̾Ƶ�") == 0)
	{
		nResult = CMyString::SetString("���ѻ��");
	}
	else
	{
		nResult = CMyString::SetString(pszParam);
	}
	return nResult;

}
void CMyStringEx::OnSetString(char *pszData, int nLength)
{
	if (strcmp(pszData, "�۸��̾Ƶ�") == 0)
	{
		strcpy_s(pszData, sizeof(char) * (nLength + 1), "���ѾƵ�");
	} 
}