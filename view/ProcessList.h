#pragma once

#include <vector>
#include <wx/listctrl.h>
#include "core/Process.h"

namespace sysmon {
    class ProcessList : public wxListView {
    public:
        ProcessList(wxWindow *parent);

        void AddProcess(const Process& process);
        void AddProcesses(const std::vector<Process>& processes);

    private:
        std::vector<Process> m_processes;
    };
} // namespace sysmon
