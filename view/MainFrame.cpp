#include "MainFrame.h"
#include "view/ProcessList.h"

namespace sysmon {
    MainFrame::MainFrame() :
        wxFrame(nullptr, wxID_ANY, "sysmon", wxDefaultPosition, wxSize(800, 600)) {
        Centre();
        wxMenu *exitMenu = new wxMenu();
        exitMenu->Append(wxID_EXIT, "Exit");

        wxMenuBar *menubar = new wxMenuBar();

        menubar->Append(exitMenu, "Exit");
        SetMenuBar(menubar);

        wxPanel *processPanel = new wxPanel(this, wxID_ANY);
        ProcessList *plist = new ProcessList(processPanel);

        plist->AddProcess(120, "sysmon");

        wxSizer *sizer = new wxBoxSizer(wxVERTICAL);
        sizer->Add(plist, 1, wxEXPAND | wxALL, 0);
        processPanel->SetSizerAndFit(sizer);

        Bind(wxEVT_MENU, &MainFrame::OnExit, this, wxID_EXIT);
    }

    void MainFrame::OnExit(wxCommandEvent &event) { Close(true); }
} // namespace sysmon
