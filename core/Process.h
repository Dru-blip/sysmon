#pragma once


#include <cstdint>
#include <vector>
#include <wx/event.h>
#include <wx/string.h>
#include <wx/thread.h>


wxDEFINE_EVENT(WX_EVENT_PROCESS_UPDATED, wxThreadEvent);

namespace sysmon {
    struct Process {
        uint32_t pid;
        wxString name;

        Process() = default;
        Process(uint32_t pid, wxString name) : pid(pid), name(name) {}
    };

    std::vector<Process> GetProcesses();
}; // namespace sysmon
