#include "header.h"

using namespace std;

int main(int argc, char** argv) {
    string logo = R"(...)";
    cout << logo << endl;
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
    string pdcode;
    getline(code, pdcode, '\n');
    outputFile << pdcode << "\n";

    import(code, outputFile); // 调用处理导入的函数

    code.close();
    outputFile.close();

    cout << "导入处理完成，下一步：转换C++。" << endl;

    return 0;
}