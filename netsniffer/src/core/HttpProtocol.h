#pragma once
class CHttpClient{

};
enum REQUEST_METHOD{
	GET = 0,
	POST = 1
};

class CharUtil{
public:
	static const char* CStringToChar(CString str);
};

class CHttpProtocol
{
private:
	CString m_url; //����URL
	CString m_para; //�������
	REQUEST_METHOD m_requestMethod; //����ʽ
	UINT m_port; //�˿ں�
	BOOL m_bInitialized; //�Ƿ��ʼ��
public:
	CHttpProtocol(CString url);
	~CHttpProtocol(void);
	void SetRequestPara(CString para);
	void Request();
	void Response();
	BOOL ParseResponse();
	BOOL Connect();
	BOOL Initialize(); //��ʼ������
};

