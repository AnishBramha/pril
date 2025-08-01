#include "Frame.h"
#include <wx/filedlg.h>

StartupFrame::StartupFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {

    wxPanel* titlePanel = new wxPanel(this);
    wxPanel* optionPanel = new wxPanel(this);

    wxFont heading(64, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD);

    wxStaticText* appName = new wxStaticText(titlePanel, wxID_ANY, " PRiL ", wxDefaultPosition, wxDefaultSize);
    appName->SetFont(heading);

    wxButton* create = new wxButton(optionPanel, wxID_ANY, "Create");
    wxButton* open = new wxButton(optionPanel, wxID_ANY, "Open");
    wxButton* about = new wxButton(optionPanel, wxID_ANY, "About");
    wxButton* quit = new wxButton(optionPanel, wxID_ANY, "Quit");
    
    about->SetBackgroundColour(wxColour(0, 0, 255));
    about->SetForegroundColour(*wxWHITE);
    about->Bind(wxEVT_BUTTON, &StartupFrame::switchToAbout, this);
    
    quit->SetBackgroundColour(wxColour(255, 0, 0));
    quit->SetForegroundColour(*wxWHITE);
    quit->Bind(wxEVT_BUTTON, &StartupFrame::closeApp, this);

    open->Bind(wxEVT_BUTTON, &StartupFrame::showFileChooser, this);

    wxBoxSizer* titleSizer = new wxBoxSizer(wxVERTICAL);
    titleSizer->Add(appName, 1, wxALIGN_CENTER | wxALL, 10);
    titlePanel->SetSizer(titleSizer);

    wxBoxSizer* optionSizer = new wxBoxSizer(wxHORIZONTAL);
    optionSizer->AddStretchSpacer();
    optionSizer->Add(create, 0, wxALL, 5);
    optionSizer->Add(open, 0, wxALL, 5);
    optionSizer->Add(about, 0, wxALL, 5);
    optionSizer->Add(quit, 0, wxALL, 5);

    optionSizer->AddStretchSpacer();
    optionPanel->SetSizer(optionSizer);

    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
    mainSizer->Add(titlePanel, 3, wxEXPAND | wxALL);
    mainSizer->Add(optionPanel, 1, wxEXPAND, wxALL);

    this->SetSizerAndFit(mainSizer);
    this->Layout();

}

void StartupFrame::switchToEditor(wxCommandEvent& evt) {

    EditorFrame* editorFrame = new EditorFrame("Pril Editor");
    editorFrame->SetClientSize(800, 600);
    editorFrame->Center();
    editorFrame->Show();

    this->Close();
}

void StartupFrame::switchToAbout(wxCommandEvent& evt) {

    AboutFrame* aboutFrame = new AboutFrame("About");
    aboutFrame->SetClientSize(300, 135);
    aboutFrame->Center();
    aboutFrame->Show();
}

void StartupFrame::closeApp(wxCommandEvent& evt) {

    this->Close();
}

void StartupFrame::showFileChooser(wxCommandEvent& evt) {

    wxFileDialog* files = new wxFileDialog(this, "Open a text file", "", "", "Text files (*.txt)|*.txt|Markdown (*.md)|*.md", wxFD_OPEN | wxFD_FILE_MUST_EXIST);

    files->ShowModal();
}

EditorFrame::EditorFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {

    
}

AboutFrame::AboutFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE & ~wxRESIZE_BORDER & ~wxMAXIMIZE_BOX & ~wxMINIMIZE_BOX) {

    wxBoxSizer* boxSizer = new wxBoxSizer(wxALL);

    wxStaticText* info = new wxStaticText(this, wxID_ANY, "\t   Free and Open Source Text Editor\n\nLicensed under the GNU Public License (3.0)\n\n\t\t\tVersion 1.0-alpha\n\n\t\t~ Anish Teja Bramhajosyula");

    boxSizer->Add(info, 0, wxALL | wxALIGN_CENTER, 10);

    this->SetSizerAndFit(boxSizer);
    this->Layout();
}


