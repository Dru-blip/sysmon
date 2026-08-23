#pragma once

#include <vector>
#include <wx/listctrl.h>
#include "core/Process.h"

namespace sysmon {
    class ProcessList : public wxListView {
    public:
        ProcessList(wxWindow *parent);

        void AddProcess(int64_t pid, const std::string &name);

    private:
        std::vector<Process> m_processes;
    };
} // namespace sysmon
