#include "App.h"
#include "Frame.h"

wxIMPLEMENT_APP(App);

bool App::OnInit() {

    StartupFrame* startupFrame = new StartupFrame("Pril Startup");
    startupFrame->SetClientSize(400, 200);
    startupFrame->Center();
    startupFrame->Show();

    return true;
}


