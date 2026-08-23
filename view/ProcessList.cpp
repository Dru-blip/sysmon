#include "ProcessList.h"
#include "core/Process.h"


namespace sysmon {
    ProcessList::ProcessList(wxWindow *parent) : wxListView(parent) {
        AppendColumn("PID");
        AppendColumn("Name");
    }

    void ProcessList::AddProcess(int64_t pid, const std::string &name) {
        int index = m_processes.size();
        InsertItem(index, wxString::FromDouble(pid));
        SetItem(index, 1, wxString::FromUTF8(name));
        m_processes.emplace_back(Process(pid, name));
    }
} // namespace sysmon
