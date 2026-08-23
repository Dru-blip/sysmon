#pragma once


#include <cstdint>
#include <string>

namespace sysmon {
    struct Process {
        int64_t pid;
        std::string name;

        Process(int64_t pid, std::string name) : pid(pid), name(name) {}
    };
}; // namespace sysmon
