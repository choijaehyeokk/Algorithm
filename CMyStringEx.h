#include "CMyString.h"

class CMyStringEx : public CMyString
{
public:
	CMyStringEx();
	CMyStringEx(const char *pszParam);
	~CMyStringEx();
	int SetString(const char *pszParam);
	void OnSetString(char *pszParam, int nLength);
	int Find(const char* pszParam);
};
