#pragma once
class CMyString
{
public:
	CMyString();
	~CMyString();
	explicit CMyString(const char* pszParam);
	//�̸��� ���� �ӽð�ü�� ���� �� ������ explicit���� ��������.
	CMyString(const CMyString &ref);
	//��������ڸ� ������.
	CMyString(CMyString &&ref);
	//�̵������ڸ� ������.
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
	//���Կ����ڸ� ��������.
	operator char*() const
	{
		return m_pszData;
	}//����ȯ �����ڸ� ������Ͽ� �ٷμ����ϰ� ���ǵ�����.
	int GetLength() const;
	int Append(const char* pszParam);
	CMyString operator+(const CMyString &ref);
	CMyString& operator+=(const CMyString &ref);
	char operator[](int Index) const;
	char& operator[](int Index);
	int operator==(const CMyString &ref);
	int operator!=(const CMyString &ref);
};

