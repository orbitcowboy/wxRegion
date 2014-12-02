// --------------------------
/// @author ettl martin
/// @date   2013-11-26
// --------------------------
#include "Frame.hpp"
#include <wx/textdlg.h>

// wxEvent Table
BEGIN_EVENT_TABLE(MyFrame, wxFrame)
    EVT_MENU(ID_QUIT            , MyFrame::OnQuit)
    EVT_MENU(ID_ABOUT           , MyFrame::OnAbout)
    EVT_PAINT(MyFrame::OnPaint)
END_EVENT_TABLE()

MyFrame::MyFrame(wxFrame *frame, const wxString& title)
    : wxFrame(frame, -1, title)
    , m_menuBar(NULL)
    , m_fileMenu(NULL)
    , m_helpMenu(NULL)
{
    // set up the menu bar
    vSetUpMenuBar();

    // set up the status bar
    vSetUpStatusBar();

    this->SetSizeHints( wxDefaultSize, wxDefaultSize );

    wxBoxSizer* bSizer1;
    bSizer1 = new wxBoxSizer( wxVERTICAL );

    m_panel   = new wxPanel(this, wxID_ANY);
    bSizer1->Add( m_panel, 3, wxALL | wxEXPAND, 5 );

    this->SetSizer( bSizer1 );
    this->Layout();

    this->SetSize(300, 250);
}

MyFrame::~MyFrame(void) {}

void MyFrame::OnQuit(wxCommandEvent& WXUNUSED(event))
{
    Close();
}

void MyFrame::OnAbout(wxCommandEvent& WXUNUSED(event))
{
    wxAboutDialogInfo AboutDialogInfo;
    AboutDialogInfo.AddDeveloper(wxT("Dr. rer. nat. Martin Ettl"));
    AboutDialogInfo.SetName(this->GetTitle());
    AboutDialogInfo.SetVersion(wxT(__DATE__));
    wxAboutBox(AboutDialogInfo);
}

void MyFrame::OnPaint(wxPaintEvent& WXUNUSED(event))
{
    wxPaintDC dc(m_panel);
    wxColour gray, white, red, blue;
    wxColour orange, green, brown;

    gray.Set(wxT("#d4d4d4"));
    white.Set(wxT("#ffffff"));
    red.Set(wxT("#ff0000"));
    orange.Set(wxT("#fa8e00"));
    green.Set(wxT("#619e1b"));
    brown.Set(wxT("#715b33"));
    blue.Set(wxT("#0d0060"));

    dc.SetPen(wxPen(gray));

    dc.DrawRectangle(20, 20, 50, 50);
    dc.DrawRectangle(30, 40, 50, 50);

    dc.SetBrush(wxBrush(white));
    dc.DrawRectangle(100, 20, 50, 50);
    dc.DrawRectangle(110, 40, 50, 50);
    wxRegion region1(100, 20, 50, 50);
    wxRegion region2(110, 40, 50, 50);
    region1.Intersect(region2);
    wxRect rect1 = region1.GetBox();
    dc.SetDeviceClippingRegion(region1);
    dc.SetBrush(wxBrush(red));
    dc.DrawRectangle(rect1);
    dc.DestroyClippingRegion();

    dc.SetBrush(wxBrush(white));
    dc.DrawRectangle(180, 20, 50, 50);
    dc.DrawRectangle(190, 40, 50, 50);
    wxRegion region3(180, 20, 50, 50);
    wxRegion region4(190, 40, 50, 50);
    region3.Union(region4);
    dc.SetDeviceClippingRegion(region3);
    wxRect rect2 = region3.GetBox();
    dc.SetBrush(wxBrush(orange));
    dc.DrawRectangle(rect2);
    dc.DestroyClippingRegion();

    dc.SetBrush(wxBrush(white));
    dc.DrawRectangle(20, 120, 50, 50);
    dc.DrawRectangle(30, 140, 50, 50);
    wxRegion region5(20, 120, 50, 50);
    wxRegion region6(30, 140, 50, 50);
    region5.Xor(region6);
    wxRect rect3 = region5.GetBox();
    dc.SetDeviceClippingRegion(region5);
    dc.SetBrush(wxBrush(green));
    dc.DrawRectangle(rect3);
    dc.DestroyClippingRegion();

    dc.SetBrush(wxBrush(white));
    dc.DrawRectangle(100, 120, 50, 50);
    dc.DrawRectangle(110, 140, 50, 50);
    wxRegion region7(100, 120, 50, 50);
    wxRegion region8(110, 140, 50, 50);
    region7.Subtract(region8);
    wxRect rect4 = region7.GetBox();
    dc.SetDeviceClippingRegion(region7);
    dc.SetBrush(wxBrush(brown));
    dc.DrawRectangle(rect4);
    dc.DestroyClippingRegion();

    dc.SetBrush(white);
    dc.DrawRectangle(180, 120, 50, 50);
    dc.DrawRectangle(190, 140, 50, 50);
    wxRegion region9(180, 120, 50, 50);
    wxRegion region10(190, 140, 50, 50);
    region10.Subtract(region9);
    wxRect rect5 = region10.GetBox();
    dc.SetDeviceClippingRegion(region10);
    dc.SetBrush(wxBrush(blue));
    dc.DrawRectangle(rect5);
    dc.DestroyClippingRegion();
}

void MyFrame::vSetUpMenuBar(void)
{
#if wxUSE_MENUS
    m_menuBar = new wxMenuBar();

    // set up the file menu
    m_fileMenu = new wxMenu(_T(""));
    m_fileMenu->Append(ID_QUIT, _("&Quit\tAlt-F4"), _("Quit the application"));
    m_menuBar->Append(m_fileMenu, _("&File"));

    // set up the help menu
    m_helpMenu = new wxMenu(_T(""));
    m_helpMenu->Append(ID_ABOUT, _("&About\tF1"), _("Show info about this application"));
    m_menuBar->Append(m_helpMenu, _("&Help"));

    // realize the menu(send it to the window)
    SetMenuBar(m_menuBar);
#endif // wxUSE_MENUS
}

void MyFrame::vSetUpStatusBar(void)
{
#if wxUSE_STATUSBAR
    // create a status bar with some information about the used wxWidgets version
    CreateStatusBar(2);
    SetStatusText(wxEmptyString, 0);
    SetStatusText(wxVERSION_STRING, 1);
#endif // wxUSE_STATUSBAR   
}
