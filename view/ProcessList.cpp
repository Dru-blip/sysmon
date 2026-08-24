#include "ProcessList.h"
#include <vector>
#include "core/Process.h"


namespace sysmon {
    ProcessList::ProcessList(wxWindow *parent) : wxListView(parent) {
        AppendColumn("PID");
        AppendColumn("Name");
    }

    void ProcessList::AddProcesses(const std::vector<Process> &processes) {
        for (const auto &process: processes) {
            AddProcess(process);
        }
    }

    void ProcessList::AddProcess(const Process &process) {
        int index = m_processes.size();
        InsertItem(index, wxString::FromDouble(process.pid));
        SetItem(index, 1, process.name);
        m_processes.emplace_back(process);
    }
} // namespace sysmon
