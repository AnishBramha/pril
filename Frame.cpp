#include "Frame.h"

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

    quit->SetBackgroundColour(wxColour(255, 0, 0));
    quit->SetForegroundColour(*wxWHITE);

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

void StartupFrame::switchFrame(wxCommandEvent& evt) {

    EditorFrame* editorFrame = new EditorFrame("Pril Editor");
    editorFrame->SetClientSize(800, 600);
    editorFrame->Center();
    editorFrame->Show();

    this->Close();
}

EditorFrame::EditorFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {

    
}


