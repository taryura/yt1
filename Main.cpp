/***************************************************************
 * Name:      Main.cpp
 * Purpose:   Code for Application Class
 * Author:    Iurii Taranenko (taryura@gmail.com)
 * Created:   2018-03-05
 * Copyright: Iurii Taranenko ()
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "Main.h"
#include "wxGUI2.h"

IMPLEMENT_APP(wxGUI2App);

bool wxGUI2App::OnInit()
{
    wxGUI2Frame* frame = new wxGUI2Frame(0L, _("Yandex translator 0.2.1"));
    frame->SetIcon(wxICON(AppIcon)); // To Set App Icon
    frame->Show();

    return true;
}
