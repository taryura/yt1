/***************************************************************
 * Name:      event_handlers.cpp
 * Purpose:   Code for Event handlers
 * Author:    Iurii Taranenko (taryura@gmail.com)
 * Created:   2018-03-06
 * Copyright: Iurii Taranenko ()
 * License:
 **************************************************************/


#include "wxGUI2.h"
#include "Parse_YandexJSON.h"
#include "YandexJSON.h"
#include "a_requests.h"
#include "utf_converter.h"

//General Close Event
void wxGUI2Frame::OnClose(wxCloseEvent &event)
{
    Destroy();
}

//File Menu

void wxGUI2Frame::OnNew(wxCommandEvent &event)
{
    std::string url_addr = "translate.yandex.net";
    std::string s_port = "443";
    SetStatusText(_("Translating..."),2);
    wxString to_translate = tc->GetValue();
    std::string text = std::string(to_translate.mb_str());
    YandexJSON text_2;
    text_2.SetRqst(text);
    std::string rqst5 = text_2.request;
    sslrequest text_3;
    text_3.rqst_set (url_addr, s_port, rqst5);
    Parse_YandexJSON JSON_str;
    JSON_str.parse(text_3.replyreceived);
    std::string reply = JSON_str.JSON_text;
    utf_converter convert;
    std::wstring reply3 = convert.utf8toutf16w(reply);
    tc2->SetValue(reply3);
    SetStatusText(_("Success!"),2);
}

void wxGUI2Frame::OnOpen(wxCommandEvent &event)
{

    wxString msg = "Supposed to open an existing project";
    wxMessageBox(msg, _("Welcome to..."));
}

void wxGUI2Frame::OnSave(wxCommandEvent &event)
{
    wxString msg = "Supposed to save the project";
    wxMessageBox(msg, _("Welcome to..."));
}

//import submenu

void wxGUI2Frame::OnImpFromFile(wxCommandEvent &event)
{
    wxString msg = "Supposed to import an existing project from file";
    wxMessageBox(msg, _("Welcome to..."));
}

void wxGUI2Frame::OnImpFromURL(wxCommandEvent &event)
{
    wxString msg = "Supposed to import an existing project from website";
    wxMessageBox(msg, _("Welcome to..."));
}

//Quit
void wxGUI2Frame::OnQuit(wxCommandEvent &event)
{
    Destroy();
}

//Edit Menu

void wxGUI2Frame::OnCopy(wxCommandEvent &event)
{
    wxString msg = "Supposed to copy";
    wxMessageBox(msg, _("Welcome to..."));
}

void wxGUI2Frame::OnCut(wxCommandEvent &event)
{
    wxString msg = "Supposed to cut";
    wxMessageBox(msg, _("Welcome to..."));
}

void wxGUI2Frame::OnPaste(wxCommandEvent &event)
{
    wxString msg = "Supposed to paste";
    wxMessageBox(msg, _("Welcome to..."));
}

void wxGUI2Frame::OnAbout(wxCommandEvent &event)
{
    wxString msg = "English to French translator v. 0.1 alpha. By Vladyslav Taranenko, 2017.";
    wxMessageBox(msg, _("English to French translator"));
}
