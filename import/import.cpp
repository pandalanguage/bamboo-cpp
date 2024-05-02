#include "import.h"

using namespace std;

void import(std::ifstream& code, std::ofstream& outputFile) {
    string pdcode;
    if (code.eof()) return; // 检查是否已到达文件末尾

    getline(code, pdcode, '\n');
    if (pdcode == "#语言 = 简体中文") {
        getline(code, pdcode, '\n');
        size_t index = pdcode.find("导入 ");
        if (index != string::npos) {
            string import = pdcode.substr(7);
            cout << "正在导入 " << import << endl;
            index = pdcode.find(".pd");
            if (index == string::npos) {
                cout << "来自库的代码暂时无法被导入。" << endl;
            } else {
                ifstream import_code(import, ios::in);
                if (import_code.is_open()) {
                    outputFile << import_code.rdbuf() << "\n";
                    import_code.close();
                } else {
                    cout << "无法打开导入文件: " << import << endl;
                }
            }
        }
        while (getline(code, pdcode, '\n')) {
            outputFile << pdcode << '\n';
        }
    } else {
        outputFile << pdcode << '\n';
    }
}