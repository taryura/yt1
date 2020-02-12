/***************************************************************
 * Name:      wxGUI2.h
 * Purpose:   Defines Application Event IDs and their handlers
 * Author:    Iurii Taranenko (taryura@gmail.com)
 * Created:   2018-03-05
 * Copyright: Iurii Taranenko ()
 * License:
 **************************************************************/

#ifndef WXGUI2MAIN_H
#define WXGUI2MAIN_H

#ifndef WX_PRECOMP
#include <wx/wx.h>
#include "winsock2.h"
#endif

#include "Main.h"
#include "EventRedirect.h"

class wxGUI2Frame: public EventRedirect
{
    public:
        wxGUI2Frame(wxFrame *frame, const wxString& title);
        ~wxGUI2Frame();
        wxMenuBar *mbar;

        //declaring toolbars and menues in the heap
        wxToolBar *toolbar1;
        wxToolBar *toolbar2;
        wxTextCtrl *tc2;
        wxTextCtrl *tc;

        wxChoice* choice1;
        wxChoice* choice2;

        wxButton* TranslateButton;

        std::string SourceLangCode;
        std::string TargetLangCode;

    private:

        //declaring event IDs
        enum
        {
            idMenuQuit = 1000,

            //File menu
            idMenuFile_New,
            idMenuFile_Open,
            idMenuFile_Save,
            idMenuFile_Import_FromFile,
            idMenuFile_Import_FromURL,

            //Edit Menu
            idMenuEdit_Copy,
            idMenuEdit_Cut,
            idMenuEdit_Paste,

            //Help Menu
            idMenuAbout,

            //Dropdown menus
            idDropdownSource,
            idDropdownTarget,

            //Buttons
            idTranslateButton

        };
        //declaring event handlers

        //general Close event
        void OnClose(wxCloseEvent& event);

        //file menu

        void OnNew(wxCommandEvent& event);
        void OnOpen(wxCommandEvent& event);
        void OnSave(wxCommandEvent& event);
        void OnImpFromFile(wxCommandEvent& event);
        void OnImpFromURL(wxCommandEvent& event);
        void OnQuit(wxCommandEvent& event);

        //Edit menu
        void OnCopy(wxCommandEvent& event);
        void OnCut(wxCommandEvent& event);
        void OnPaste(wxCommandEvent& event);

        //Help Menu
        void OnAbout(wxCommandEvent& event);

        //Dropdown menus
        void SetSource(wxCommandEvent& event);
        void SetTarget(wxCommandEvent& event);

        //Translate button
        void OnTranslate(wxCommandEvent &event);


        //Menu creation methods of the main class
        void CreateFileMenu();
        void CreateEditMenu();
        void CreateHelpMenu();

        //Toolbars creation methods
        void CreateToolbars();



        DECLARE_EVENT_TABLE()
};


#endif // WXGUI2MAIN_H
