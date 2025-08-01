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

        EditorFrame(const wxString& title, const wxString& filepath);

    private:

        void switchToHome(wxCommandEvent& evt);
        void onSave(wxCommandEvent& evt);
        void onSaveAs(wxCommandEvent& evt);

        void save(const wxString& filepath);
        void saveAs(void);

        wxTextCtrl* text;
        wxStaticText* fileName;
        wxString filepath;
};

class AboutFrame : public wxFrame {

    public:

        AboutFrame(const wxString& title);
};

