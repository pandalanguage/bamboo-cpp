#include "header.h"

using namespace std;

int main(int argc, char** argv) {
    string logo = R"(  ____                        _         
 |  _ \    __ _   _ __     __| |   __ _ 
 | |_) |  / _` | | '_ \   / _` |  / _` |
 |  __/  | (_| | | | | | | (_| | | (_| |
 |_|      \__,_| |_| |_|  \__,_|  \__,_|)";
    
    cout << logo << "熊猫语言-Bamboo C++编译器" << endl;
    string codepath = argv[1];
    ifstream code(codepath, ios::in);
    if (!code.is_open()) {
        cout << "无法打开文件: " << codepath << endl;
        return 1;
    }
    ofstream outputFile("./build/import.pd");
    if (!outputFile.is_open()) {
        cout << "无法创建或打开输出文件: import.pd" << endl;
        return 1;
    }

    // 获取并处理第一行
    string language;
    getline(code, language);
    size_t hashtagPos = language.find("#语言 = ");
    if (hashtagPos != string::npos) {
        language = language.substr(hashtagPos + 7); // 删除"#语言 = "
    }

    import(code, outputFile, language); // 将第一行作为参数传递

    code.close();
    outputFile.close();

    cout << "导入处理完成，下一步：转换C++。" << endl;

    return 0;
}