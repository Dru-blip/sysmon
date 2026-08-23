#pragma once
#include <wx/wx.h>


namespace sysmon {
class App : public wxApp {
public:
  bool OnInit() override;
};
} // namespace sysmon
