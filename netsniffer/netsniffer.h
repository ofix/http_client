
// netsniffer.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CNetSnifferApp:
// �йش����ʵ�֣������ netsniffer.cpp
//

class CNetSnifferApp : public CWinApp
{
public:
	CNetSnifferApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CNetSnifferApp theApp;