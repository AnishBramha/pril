#include "Frame.h"
#include <wx/filedlg.h>
#include <wx/ffile.h>
#include <wx/textfile.h>
#include <wx/filename.h>
#include <wx/msgdlg.h>

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

    create->Bind(wxEVT_BUTTON, &StartupFrame::switchToEditor, this);

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

    EditorFrame* editorFrame = new EditorFrame("Pril Editor", "");
    editorFrame->SetClientSize(800, 600);
    editorFrame->Center();
    editorFrame->Show();

    this->Close();
}

void StartupFrame::switchToAbout(wxCommandEvent& evt) {

    AboutFrame* aboutFrame = new AboutFrame("About");
    aboutFrame->SetClientSize(300, 165);
    aboutFrame->Center();
    aboutFrame->Show();
}

void StartupFrame::closeApp(wxCommandEvent& evt) {

    this->Close();
}

void StartupFrame::showFileChooser(wxCommandEvent& evt) {

    wxFileDialog* files = new wxFileDialog(this, "Open a text file", "", "", "Text files (*.txt)|*.txt|Markdown (*.md)|*.md|All files (*.*)|*.*", wxFD_OPEN | wxFD_FILE_MUST_EXIST);

    if (files->ShowModal() == wxID_OK) {

        wxString path = files->GetPath();

        EditorFrame* editorFrame = new EditorFrame("Pril Editor", path);
        editorFrame->SetClientSize(800, 600);
        editorFrame->Center();
        editorFrame->Show();

        this->Close();
    }
}

EditorFrame::EditorFrame(const wxString& title, const wxString& filepath) : wxFrame(nullptr, wxID_ANY, title) {

    wxPanel* controlPanel = new wxPanel(this);

    wxButton* save = new wxButton(controlPanel, wxID_ANY, "Save");
    wxButton* saveAs = new wxButton(controlPanel, wxID_ANY, "Save As");
    wxButton* home = new wxButton(controlPanel, wxID_ANY, "Home");

    save->Bind(wxEVT_BUTTON, &EditorFrame::onSave, this);
    saveAs->Bind(wxEVT_BUTTON, &EditorFrame::onSaveAs, this);
    home->Bind(wxEVT_BUTTON, &EditorFrame::switchToHome, this);
    
    wxStaticText* fileName = new wxStaticText(controlPanel, wxID_ANY, "untitled.txt");

    wxTextCtrl* editor = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE);

    wxBoxSizer* controlSizer = new wxBoxSizer(wxHORIZONTAL);
    controlSizer->Add(fileName, 1, wxALIGN_CENTER_VERTICAL | wxLEFT, 10);
    controlSizer->Add(save, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);
    controlSizer->Add(saveAs, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);
    controlSizer->Add(home, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);
    controlPanel->SetSizer(controlSizer);

    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    sizer->Add(controlPanel, 0, wxEXPAND | wxALL, 5);
    sizer->Add(editor, 1, wxEXPAND | wxALL, 10);

    this->fileName = fileName;
    this->text = editor;

    if (!filepath.IsEmpty()) {

        wxTextFile* file = new wxTextFile();

        file->Open(filepath);

        wxString text;
        text += file->GetFirstLine();

        while (!file->Eof())
            text += "\n" + file->GetNextLine();

        file->Close();

        wxFileName filename(filepath);
        this->fileName->SetLabel(filename.GetFullName());

        this->filepath = filepath;
    
        fileName->SetLabel(filename.GetFullName());
        editor->SetValue(text);
    }

    this->SetSizerAndFit(sizer);
    this->Layout();
}

void EditorFrame::save(const wxString& filepath) {

    wxFFile* file = new wxFFile(filepath, "w");

    file->Write(this->text->GetValue());

    file->Close();
}

void EditorFrame::saveAs(void) {

    wxFileDialog* saveDlg = new wxFileDialog(this, "Save file", "", "", "Text files (*.txt)|*.txt|Markdown (*.md)|*.md|All files (*.*)|*.*", wxFD_SAVE | wxFD_OVERWRITE_PROMPT);

    if (saveDlg->ShowModal() == wxID_CANCEL)
        return;

    wxString filepath = saveDlg->GetPath();

    save(filepath);
    this->filepath = filepath;

    wxFileName fileName(filepath);
    this->fileName->SetLabel(fileName.GetFullName());
}

void EditorFrame::onSave(wxCommandEvent& evt) {

    if (this->filepath.IsEmpty())
        this->saveAs();

    else
        this->save(this->filepath);
}

void EditorFrame::onSaveAs(wxCommandEvent& evt) {

    this->saveAs();
}

void EditorFrame::switchToHome(wxCommandEvent& evt) {

    wxMessageDialog* warn = new wxMessageDialog(this, "Are you sure you want to exit?", "Save file", wxYES_NO | wxICON_WARNING);

    if (warn->ShowModal() == wxID_NO)
        return;

    StartupFrame* home = new StartupFrame("Pril Home");
    home->SetClientSize(400,200);
    home->Center();
    home->Show();

    this->Close();
}

AboutFrame::AboutFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE & ~wxRESIZE_BORDER & ~wxMAXIMIZE_BOX & ~wxMINIMIZE_BOX) {

    wxBoxSizer* boxSizer = new wxBoxSizer(wxALL);

    wxStaticText* info = new wxStaticText(this, wxID_ANY, "\t   Free and Open Source Text Editor\n\nLicensed under the GNU Public License (3.0)\n\n\t\t\tVersion 1.0.0\n\n\t\t~ Anish Teja Bramhajosyula\n\n   https://www.github.com/AnishBramha/pril");

    boxSizer->Add(info, 0, wxALL | wxALIGN_CENTER, 10);

    this->SetSizerAndFit(boxSizer);
    this->Layout();
}


