#pragma once
class CMyString
{
public:
	CMyString();
	~CMyString();
	explicit CMyString(const char* pszParam);
	//이름이 없는 임시객체를 만들 수 없도록 explicit으로 제한을둠.
	CMyString(const CMyString &ref);
	//복사생성자를 선언함.
	CMyString(CMyString &&ref);
	//이동생성자를 선언함.
private:
	char* m_pszData = nullptr;
	int m_nLength = 0;
public:
	int SetString(const char* pszParam);
	virtual void OnSetString(char *pszData,int nLength);
	friend CMyString operator+(const char *pszParam, const CMyString &ref);
	const char* GetString() const;
	void Release();
	CMyString& operator=(const CMyString &ref);
	//대입연산자를 만들어놓음.
	operator char*() const
	{
		return m_pszData;
	}//형변환 연산자를 헤더파일에 바로선언하고 정의도해줌.
	int GetLength() const;
	int Append(const char* pszParam);
	CMyString operator+(const CMyString &ref);
	CMyString& operator+=(const CMyString &ref);
	char operator[](int Index) const;
	char& operator[](int Index);
	int operator==(const CMyString &ref);
	int operator!=(const CMyString &ref);
};

