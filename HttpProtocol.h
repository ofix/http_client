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
	CString m_url; //请求URL
	CString m_para; //请求参数
	REQUEST_METHOD m_requestMethod; //请求方式
	UINT m_port; //端口号
	BOOL m_bInitialized; //是否初始化
public:
	CHttpProtocol(CString url);
	~CHttpProtocol(void);
	void SetRequestPara(CString para);
	void Request();
	void Response();
	BOOL ParseResponse();
	BOOL Connect();
	BOOL Initialize(); //初始化环境
};

