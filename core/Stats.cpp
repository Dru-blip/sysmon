#ifdef __linux__

#include <wx/dir.h>
#include <wx/file.h>
#include "Process.h"

#include <fstream>
#include <sstream>


namespace sysmon {
    std::vector<Process> GetProcesses() {
        std::vector<Process> processes;

        wxDir dir("/proc");

        if (!dir.IsOpened()) {
            // TODO: handle error
            return processes;
        }

        wxString entry;
        bool cont = dir.GetFirst(&entry, wxEmptyString);

        while (cont) {
            std::ifstream file;
            Process process;
            if (!entry.IsNumber()) {
                goto next;
            }

            uint32_t pid;
            if (!entry.ToUInt(&pid)) {
                goto next;
            }
            process.pid = pid;

            file.open("/proc/" + entry + "/comm");
            if (file.is_open()) {
                // TODO: handle error
                std::stringstream buf;
                buf << file.rdbuf();
                process.name = buf.str();

            }
            processes.push_back(process);
        next:
            cont = dir.GetNext(&entry);
        }

        return processes;
    }
} // namespace sysmon

#endif
