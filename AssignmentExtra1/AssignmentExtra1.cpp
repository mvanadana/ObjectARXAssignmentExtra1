// AssignmentExtra1.cpp : Defines the initialization routines for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "AssignmentExtra1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include <tchar.h>
#include "rxregsvc.h"
#include "acutads.h"
#include "accmd.h"
#pragma comment(linker,"/EXPORT:acrxEntryPoint")
#pragma comment(linker,"/EXPORT:acrxGetApiVersion")


#include "rxregsvc.h"
#include "acutads.h"
#include "aced.h"
#include "acdb.h"
#include <Windows.h>
#include <string.h>
#include <stdlib.h>
#include <aced.h>
#include <dbents.h>

#include <dbsymtb.h>
#include <adslib.h>
#include <geassign.h>
#include <dbidmap.h>
#include <dbapserv.h>
#include <acgi.h>
#include "tchar.h"
#include "acedCmdNF.h"
static void commandAndSysVar()

{

	// Create a variable of the result buffer type

	struct resbuf rb, rb1;

	// Get the current value of the CIRCLERAD system variable

	acedGetVar(_T("CIRCLERAD"), &rb);

	acutPrintf(_T("\nCurrent CIRCLERAD: %.2f\n"), rb.resval);

	// Define the center point for the circle

	ads_point pt;

	pt[X] = 2.5; pt[Y] = 3.75; pt[Z] = 0.0;

	// Define the radius of the circle

	double rrad = 2.75;

	// Provide all values to the CIRCLE command

	if (acedCommandS(RTSTR, _T("._CIRCLE"), RTPOINT, pt,

		RTREAL, rrad, RTNONE) != RTNORM)

	{

		acutPrintf(_T("\nError: CIRCLE command failed."));

	}

	// Pause for the center point

	if (acedCommandS(RTSTR, _T("._CIRCLE"), RTSTR, PAUSE,

		RTREAL, rrad, RTNONE) != RTNORM)

	{

		acutPrintf(_T("\nError: CIRCLE command failed."));

	}

	// Set the value of CIRCLERAD to the previous value

	rb1.restype = RTREAL;

	rb1.resval.rreal = rb.resval.rreal;

	acedSetVar(_T("CIRCLERAD"), &rb1);

}
int acrxEntryPoint(AcRx::AppMsgCode Msg, void* pkt) {
	switch (Msg) {
	case AcRx::kInitAppMsg:
		acrxUnlockApplication(pkt);
		acrxRegisterAppMDIAware(pkt);
		acutPrintf(L"\n Command Loaded");
		//below line for registering new command
	
		acedRegCmds->addCommand(_T("AUCommands"), _T("CommandAndSysVar"), _T("CommandAndSysVar"), ACRX_CMD_MODAL,
			commandAndSysVar);
		break;
	case AcRx::kUnloadAppMsg:
		acutPrintf(_T("\n Command Unloaded"));
		break;
	}
	return AcRx::kRetOK;

}
//
//TODO: If this DLL is dynamically linked against the MFC DLLs,
//		any functions exported from this DLL which call into
//		MFC must have the AFX_MANAGE_STATE macro added at the
//		very beginning of the function.
//
//		For example:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// normal function body here
//		}
//
//		It is very important that this macro appear in each
//		function, prior to any calls into MFC.  This means that
//		it must appear as the first statement within the
//		function, even before any object variable declarations
//		as their constructors may generate calls into the MFC
//		DLL.
//
//		Please see MFC Technical Notes 33 and 58 for additional
//		details.
//

// CAssignmentExtra1App

BEGIN_MESSAGE_MAP(CAssignmentExtra1App, CWinApp)
END_MESSAGE_MAP()


// CAssignmentExtra1App construction

CAssignmentExtra1App::CAssignmentExtra1App()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only CAssignmentExtra1App object

CAssignmentExtra1App theApp;


// CAssignmentExtra1App initialization

BOOL CAssignmentExtra1App::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}
