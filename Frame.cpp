#include "Frame.h"

StartupFrame::StartupFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {

    wxPanel* panel = new wxPanel(this);
    wxButton* button = new wxButton(panel, wxID_ANY, "Edit");

    button->Bind(wxEVT_BUTTON, &StartupFrame::switchFrame, this);
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


