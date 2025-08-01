#pragma once

#include <wx/wx.h>

class StartupFrame : public wxFrame {

    public:

        StartupFrame(const wxString& title);

    private:

        void switchToEditor(wxCommandEvent& evt);
        void switchToAbout(wxCommandEvent& evt);
        void closeApp(wxCommandEvent& evt);
        void showFileChooser(wxCommandEvent& evt);
};

class EditorFrame : public wxFrame {

    public:

        EditorFrame(const wxString& title);
};

class AboutFrame : public wxFrame {

    public:

        AboutFrame(const wxString& title);
};

