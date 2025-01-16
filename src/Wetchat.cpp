#include <fstream>
#include "Wetchat.h"
#include <iostream>
#include <cstring>
void Wetchat::runWeChatScript(const std::string& weChatPath) {
    const std::string script = R"(
    @echo off
    start "" "<WECHAT_PATH>\WeChat.exe"
    start "" "<WECHAT_PATH>\WeChat.exe"
    exit
    )";
    
    // 替换脚本中的 <WECHAT_PATH> 为实际的路径
    std::string updatedScript = script;
    size_t pos = updatedScript.find("<WECHAT_PATH>");
    while (pos != std::string::npos) {
        updatedScript.replace(pos, strlen("<WECHAT_PATH>"), weChatPath);
        pos = updatedScript.find("<WECHAT_PATH>", pos + weChatPath.length());
    }

    // 将更新后的脚本写入到批处理文件
    // 使用 C++11 风格的文件写入
    std::ofstream batchFile("launch_wechat.bat", std::ios::out | std::ios::trunc);
    if (batchFile.is_open()) {
        batchFile << updatedScript;
        batchFile.flush(); //(不调用的话，文件被占用 system无法执行 ，，或者执行close也行 )
    } else {
        std::cerr << "Error: Unable to open file for writing." << std::endl;
    }


}


Wetchat::Wetchat()
{
}

Wetchat::~Wetchat()
{
}
