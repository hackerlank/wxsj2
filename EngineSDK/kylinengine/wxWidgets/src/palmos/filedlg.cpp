/////////////////////////////////////////////////////////////////////////////
// Name:        src/palmos/filedlg.cpp
// Purpose:     wxFileDialog
// Author:      William Osborne - minimal working wxPalmOS port
// Modified by:
// Created:     10/13/04
// RCS-ID:      $Id: filedlg.cpp,v 1.3 2005/01/21 21:04:01 ABX Exp $
// Copyright:   (c) William Osborne
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////

// ============================================================================
// declarations
// ============================================================================

// ----------------------------------------------------------------------------
// headers
// ----------------------------------------------------------------------------

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
    #pragma implementation "filedlg.h"
#endif

// For compilers that support precompilation, includes "wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
    #pragma hdrstop
#endif

#if wxUSE_FILEDLG && !defined(__SMARTPHONE__)

#ifndef WX_PRECOMP
    #include "wx/utils.h"
    #include "wx/msgdlg.h"
    #include "wx/filedlg.h"
    #include "wx/filefn.h"
    #include "wx/intl.h"
    #include "wx/log.h"
    #include "wx/app.h"
    #include "wx/math.h"
#endif

#include "wx/palmos/private.h"

#include <stdlib.h>
#include <string.h>

#include "wx/filename.h"
#include "wx/tokenzr.h"

#ifndef OFN_EXPLORER
    #define OFN_EXPLORER 0x00080000
#endif

// ----------------------------------------------------------------------------
// constants
// ----------------------------------------------------------------------------

#define wxMAXPATH   1024

# define wxMAXFILE   1024

# define wxMAXEXT    5

// ============================================================================
// implementation
// ============================================================================

IMPLEMENT_CLASS(wxFileDialog, wxFileDialogBase)

// ----------------------------------------------------------------------------
// wxFileDialog
// ----------------------------------------------------------------------------

wxFileDialog::wxFileDialog(wxWindow *parent,
                           const wxString& message,
                           const wxString& defaultDir,
                           const wxString& defaultFileName,
                           const wxString& wildCard,
                           long style,
                           const wxPoint& pos)
             :wxFileDialogBase(parent, message, defaultDir, defaultFileName, wildCard, style, pos)

{
}

void wxFileDialog::GetPaths(wxArrayString& paths) const
{
}

void wxFileDialog::GetFilenames(wxArrayString& files) const
{
}

void wxFileDialog::SetPath(const wxString& path)
{
}

int wxFileDialog::ShowModal()
{
    return wxID_CANCEL;
}

#endif // wxUSE_FILEDLG

