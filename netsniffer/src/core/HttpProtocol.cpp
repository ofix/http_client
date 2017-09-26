#include "stdafx.h"
#include "HttpProtocol.h"
#include "stdafx.h"

CHttpProtocol::CHttpProtocol(CString url)
{
}


CHttpProtocol::~CHttpProtocol(void)
{
}

const char* CharUtil::CStringToChar(CString str){
	CT2A ascii(str);
	return ascii.m_psz;
}

BOOL CHttpProtocol::Initialize()
{
	
	BOOL bRet = FALSE;  
	WORD version = MAKEWORD(2, 2); //socket 版本
	WSADATA wsaData; //win_sock 结构体
 
    do   
    {  
        if(0 != WSAStartup(version, &wsaData))  
        {  
            break;  
        }  
        if(LOBYTE( wsaData.wVersion ) != 2 || HIBYTE( wsaData.wVersion ) != 2 )  
        {  
            WSACleanup();  
            break;  
        }  
        LPHOSTENT lpHostTent;  
		lpHostTent = gethostbyname(CharUtil::CStringToChar(m_url));  
        if (NULL == lpHostTent)  
        {  
            break;  
        }  
        SOCKET client = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        if (client == INVALID_SOCKET)  
        {  
            WSACleanup();  
            break;  
        }  
        SOCKADDR_IN* pAddr = new SOCKADDR_IN;  
        pAddr->sin_family = AF_INET;  
        pAddr->sin_port = htons(m_port);  
        pAddr->sin_addr = *((LPIN_ADDR)*lpHostTent->h_addr_list);  
        memset(pAddr->sin_zero, 0, sizeof(pAddr->sin_zero)); 
        bRet = TRUE;  
    } while (FALSE);  
  
    return bRet;  
}

BOOL CHttpProtocol::Connect()
{
	
}