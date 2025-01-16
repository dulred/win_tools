
#pragma once
#include <vector>
#include <string>
class WinUtils
{
private:
    /* data */
public:
    WinUtils(/* args */);
    // 获取系统中所有磁盘分区
    static void getSystemDrives (std::vector<std::string> &drives);
    //通过注册表路径查找wetchat的安装路径
    static std::string getWeChatInstallLocation(std::string &regPath);
    // 结束指定进程
    static void terminateProcessByName(const char* processName);
    ~WinUtils();
};
