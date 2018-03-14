/***************************************************************
 * Name:      Toolbars.cpp
 * Purpose:   Code for Toolbars items
 * Author:    Iurii Taranenko (taryura@gmail.com)
 * Created:   2018-03-06
 * Copyright: Iurii Taranenko ()
 * License:
 **************************************************************/

#include "wxGUI2.h"

void wxGUI2Frame::CreateToolbars()
{
    wxBitmap exit(wxT("exit.png"), wxBITMAP_TYPE_PNG);
    wxBitmap newb(wxT("new.png"), wxBITMAP_TYPE_PNG);
    wxBitmap open(wxT("open.png"), wxBITMAP_TYPE_PNG);
    wxBitmap save(wxT("save.png"), wxBITMAP_TYPE_PNG);

    wxPanel *panel = new wxPanel(this, -1);

    wxBoxSizer *vbox = new wxBoxSizer(wxVERTICAL);

    toolbar1 = new wxToolBar(panel, wxID_ANY);
    toolbar1->AddTool(idMenuFile_New, wxT("New"), newb);
    toolbar1->AddTool(idMenuFile_Open, wxT("Open"), open);
    toolbar1->AddTool(idMenuFile_Save, wxT(""), save);
    toolbar1->AddTool(wxID_EXIT, wxT("Exit application"), exit);
    toolbar1->Realize();

    vbox->Add(toolbar1, 0, wxEXPAND);

        Connect(wxID_EXIT, wxEVT_COMMAND_TOOL_CLICKED,
        wxCommandEventHandler(wxGUI2Frame::OnQuit));


    wxBoxSizer *hbox1 = new wxBoxSizer(wxVERTICAL);
    wxStaticText *st1 =  new wxStaticText(panel, wxID_ANY,
        wxT("Text to translate:"));

    hbox1->Add(st1, 0, wxRIGHT, 8);

    tc = new wxTextCtrl(panel, wxID_ANY, wxT(""),
        wxPoint(-1, -1), wxSize(-1, -1), wxTE_MULTILINE);
    hbox1->Add(tc, 1, wxEXPAND);
    vbox->Add(hbox1, 1, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 10);

    vbox->Add(-1, 20);

    wxBoxSizer *hbox2 = new wxBoxSizer(wxHORIZONTAL);
    wxStaticText *st2 = new wxStaticText(panel, wxID_ANY,
        wxT("Translated text"));

    hbox2->Add(st2, 0);
    vbox->Add(hbox2, 0, wxLEFT | wxTOP, 10);

    vbox->Add(-1, 10);

    wxBoxSizer *hbox3 = new wxBoxSizer(wxHORIZONTAL);
    tc2 = new wxTextCtrl(panel, wxID_ANY, wxT(""),
        wxPoint(-1, -1), wxSize(-1, -1), wxTE_MULTILINE);

    hbox3->Add(tc2, 1, wxEXPAND);
    vbox->Add(hbox3, 1, wxLEFT | wxRIGHT | wxEXPAND, 10);

    vbox->Add(-1, 25);

    panel->SetSizer(vbox);

    Centre();


    return;
}
