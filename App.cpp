#include "App.h"
#include "Frame.h"

wxIMPLEMENT_APP(App);

bool App::OnInit() {

    StartupFrame* startupFrame = new StartupFrame("Pril Startup");
    startupFrame->SetClientSize(800, 600);
    startupFrame->Center();
    startupFrame->Show();

    return true;
}


