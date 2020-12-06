class CMyString
{
public:
	CMyString(char* pData = nullptr);
	CMyString(const CMyString& str);
	CMyString& operator = (const CMyString& str);

	~CMyString();

	void print();

private:
	char* m_pDate;
};

