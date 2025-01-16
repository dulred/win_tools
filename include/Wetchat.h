#pragma once
#include <string>
//微信类  实现windwos微信多开
class Wetchat
{
private:
    /* data */
public:
    Wetchat();
    ~Wetchat();
   // 根据安装路径生成脚本
    void runWeChatScript(const std::string& weChatPath);

};
