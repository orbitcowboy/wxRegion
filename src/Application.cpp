// --------------------------
/// @author ettl martin
/// @date   2013-11-26
// --------------------------

#include "Application.hpp"
#include "Frame.hpp"

// create the app
IMPLEMENT_APP(MyApp)

// initialize the frame
bool MyApp::OnInit(void)
{
    MyFrame* const pFrame = new MyFrame(0L, _("wxRegion"));
    pFrame->Show();
    return true;
}
