#pragma once
#include <wx/wx.h>

namespace sysmon {
    class MainFrame : public wxFrame {
    public:
        MainFrame();

    private:
        void OnExit(wxCommandEvent &event);
    };
} // namespace sysmon
