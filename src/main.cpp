#include "Wetchat.h"
#include "WinUtils.h"
#include <vector>
#include <string>
#include <iostream>
int main (){
    // 查找微信路径
    std::string regPath = "SOFTWARE\\WOW6432Node\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\WeChat";
    std::string installLocation = WinUtils::getWeChatInstallLocation(regPath);
    std::cout << "WeChat found at: " << installLocation << std::endl;

    // 关闭微信进程
    WinUtils::terminateProcessByName("WeChat.exe");

    Wetchat we;
    // 生成脚本 
    we.runWeChatScript(installLocation);

    // 执行批处理文件
    system("launch_wechat.bat");

    return 0;  // 主函数返回值0表示正常结束
}