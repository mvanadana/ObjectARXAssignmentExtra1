// AssignmentExtra1.h : main header file for the AssignmentExtra1 DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols
#include <Windows.h>
#include<arxHeaders.h>
#include <dbents.h>

// CAssignmentExtra1App
// See AssignmentExtra1.cpp for the implementation of this class
//

class CAssignmentExtra1App : public CWinApp
{
public:
	CAssignmentExtra1App();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
