#include <iostream>
#include <string>
#include <vector>
using namespace std;

class TextEditor {
public:
    string left, right;

    TextEditor() {}

    void addText(string text) {
        left += text;
    }

    int deleteText(int k) {
        int cnt = min(k, (int)left.size());
        left.erase(left.end() - cnt, left.end());
        return cnt;
    }

    string cursorLeft(int k) {
        int cnt = min(k, (int)left.size());
        right = left.substr(left.size() - cnt, cnt) + right;
        left.erase(left.end() - cnt, left.end());
        return left.substr(max(0, (int)left.size() - 10));
    }

    string cursorRight(int k) {
        int cnt = min(k, (int)right.size());
        left += right.substr(0, cnt);
        right.erase(0, cnt);
        return left.substr(max(0, (int)left.size() - 10));
    }
};

int main() {
    TextEditor editor;
    vector<string> results;

    // Operaciones según el ejemplo:
    // ["TextEditor","addText","deleteText","addText","cursorRight","cursorLeft","deleteText","cursorLeft","cursorRight"]
    // [[],["leetcode"],[4],["practice"],[3],[8],[10],[2],[6]]

    editor.addText("leetcode");
    results.push_back("null"); // constructor

    int deleted1 = editor.deleteText(4);
    results.push_back("null");

    editor.addText("practice");
    results.push_back("4"); // deleted1

    string result1 = editor.cursorRight(3);
    results.push_back(result1);

    string result2 = editor.cursorLeft(8);
    results.push_back(result2);

    int deleted2 = editor.deleteText(10);
    results.push_back(to_string(deleted2));

    string result3 = editor.cursorLeft(2);
    results.push_back(result3);

    string result4 = editor.cursorRight(6);
    results.push_back(result4);

    // Mostrar resultados
    cout << "Resultados:" << endl;
    for (const string& res : results) {
        cout << res << endl;
    }

    return 0;
}
