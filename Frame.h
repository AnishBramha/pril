#pragma once

#include <wx/wx.h>

class StartupFrame : public wxFrame {

    public:

        StartupFrame(const wxString& title);

    private:

        void switchFrame(wxCommandEvent& evt);
};

class EditorFrame : public wxFrame {

    public:

        EditorFrame(const wxString& title);
};


