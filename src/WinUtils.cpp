
#include <windows.h>
#include <fstream>
#include <tlhelp32.h>
#include <tchar.h>
#include "WinUtils.h"
#include <iostream>

void WinUtils::getSystemDrives(std::vector<std::string> &drives) {
    DWORD drivesMask = GetLogicalDrives();
    for (char letter = 'A'; letter <= 'Z'; ++letter) {
        if (drivesMask & (1 << (letter - 'A'))) {
            std::string drive = std::string(1, letter) + ":\\";  // 磁盘路径
            drives.push_back(drive);
        }
    }
}

std::string WinUtils::getWeChatInstallLocation(std::string &regPath) {
    HKEY hKey;
    // const std::string regPath = "SOFTWARE\\WOW6432Node\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\WeChat";
    const std::string valueName = "InstallLocation";
    char installPath[1024];
    DWORD bufferSize = sizeof(installPath);

    // 打开注册表项
    if (RegOpenKeyExA(HKEY_LOCAL_MACHINE, regPath.c_str(), 0, KEY_READ, &hKey) != ERROR_SUCCESS) {
        std::cerr << "Failed to open registry key." << std::endl;
        return "";
    }

    // 获取 InstallLocation 的值
    if (RegQueryValueExA(hKey, valueName.c_str(), nullptr, nullptr, reinterpret_cast<LPBYTE>(installPath), &bufferSize) != ERROR_SUCCESS) {
        std::cerr << "Failed to query registry value." << std::endl;
        RegCloseKey(hKey);
        return "";
    }

    // 关闭注册表键
    RegCloseKey(hKey);

    return std::string(installPath);
}

void WinUtils::terminateProcessByName(const char* processName) {
    PROCESSENTRY32 entry;
    entry.dwSize = sizeof(PROCESSENTRY32);
    // 创建快照，获取当前所有进程信息
    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (snapshot == INVALID_HANDLE_VALUE) {
        std::cerr << "Failed to create process snapshot." << std::endl;
        return;
    }
    // 遍历所有进程
    if (Process32First(snapshot, &entry)) {
        do {
            // 判断进程名称是否匹配
            if (_tcsicmp(entry.szExeFile,processName) == 0) {
                // 打开进程并终止
                HANDLE processHandle = OpenProcess(PROCESS_TERMINATE, FALSE, entry.th32ProcessID);
                if (processHandle != NULL) {
                    TerminateProcess(processHandle, 0);
                    CloseHandle(processHandle);
                    std::cout << "Terminated process: " << processName << std::endl;
                    break;
                }
            }
        } while (Process32Next(snapshot, &entry));  // 继续遍历下一个进程
    }else {
        std::cerr << "Failed to find first process. Error: " << GetLastError() << std::endl;
    }
                    
    
    
    CloseHandle(snapshot);  // 关闭快照句柄
}

WinUtils::WinUtils(/* args */)
{
}

WinUtils::~WinUtils()
{
}
