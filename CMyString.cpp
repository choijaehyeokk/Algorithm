#include "CMyString.h"
#include <string.h>
#include <iostream>
using namespace std;

CMyString::CMyString()
	:m_pszData(NULL),m_nLength(0)
{}

CMyString::CMyString(const char *pszParam)
	:m_pszData(NULL), m_nLength(0)
{
	//cout << "생성자" << endl;
	SetString(pszParam);
}
CMyString::CMyString(const CMyString &ref)
	:m_pszData(NULL) , m_nLength(0)
{
	this->SetString(ref.GetString());
}
CMyString::CMyString(CMyString &&ref)
	:m_pszData(ref.m_pszData),m_nLength(ref.m_nLength)
{
	cout << "이동생성자 호출됨" << endl;
	ref.m_pszData = NULL;
	ref.m_nLength = 0;
}
CMyString::~CMyString()
{
	Release();
}
//===================================================================================
int CMyString::SetString(const char * pszParam)
{
	// TODO: 여기에 구현 코드 추가.
	Release();

	if (pszParam == NULL)
	{
		return 0;
	}
	int nLength = strlen(pszParam);

	if (nLength == 0)
	{
		return 0;
	}

	m_pszData = new char[nLength + 1];

	strcpy_s(m_pszData, sizeof(char)* (nLength + 1), pszParam);
	m_nLength = nLength;

	OnSetString(m_pszData, m_nLength);
	return nLength;
}
void CMyString::OnSetString(char*pszData,int nLength)
{

}
CMyString operator+(const char *pszParam, const CMyString &ref)
{
	CMyString strResult(pszParam);
	strResult.Append(ref.m_pszData);

	return strResult;
}
const char* CMyString::GetString() const
{
	// TODO: 여기에 구현 코드 추가.
	return m_pszData;
}


void CMyString::Release()
{
	if (m_pszData != NULL)
		delete[] m_pszData;

	m_pszData = NULL;
	m_nLength = 0;
	// TODO: 여기에 구현 코드 추가.
}
CMyString& CMyString::operator=(const CMyString &ref)
{
	if (this != &ref)
	{
		this->SetString(ref.GetString());
	}
	return *this;
}
int CMyString::GetLength() const
{
	return m_nLength;
}
int CMyString::Append(const char* pszParam)
{
	if (pszParam == NULL)
	{
		return 0;
	}

	int nLenParam = strlen(pszParam);
	if (nLenParam == 0)
	{
		return 0;
	}

	if (m_pszData == NULL)
	{
		SetString(pszParam);
		return m_nLength;
	}

	int nLenCur = m_nLength;

	char *pszResult = new char[nLenCur + nLenParam + 1];

	strcpy_s(pszResult, sizeof(char)*(nLenCur + 1), m_pszData);
	//strcpy_s(저장할버퍼(배열),버퍼크기,복사할문자열)
	strcpy_s(pszResult + (sizeof(char)* nLenCur), sizeof(char)* (nLenParam + 1), pszParam);

	Release();
	m_pszData = pszResult;
	m_nLength = nLenCur + nLenParam;

	return m_nLength;
}
CMyString CMyString::operator+(const CMyString &ref)
{
	CMyString strResult(m_pszData);
	strResult.Append(ref.GetString());

	return strResult;
}
CMyString& CMyString::operator+=(const CMyString &ref)
{
	Append(ref.GetString());
	return *this;
}
char CMyString::operator[](int Index) const
{
	return m_pszData[Index];
}
char& CMyString::operator[](int Index)
{
	return m_pszData[Index];
}
int CMyString::operator==(const CMyString &ref)
{
	if (m_pszData != NULL && ref.m_pszData != NULL)
	{
		if (strcmp(m_pszData, ref.m_pszData) == 0)
		{
			return 1;
		}
	}
	return 0;
}
int CMyString::operator!=(const CMyString &ref)
{
	if (m_pszData != NULL && ref.m_pszData != NULL)
	{
		if (strcmp(m_pszData, ref.m_pszData) == 0)
		{
			return 0;
		}
	}
	return 1;
}
