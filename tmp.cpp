#include <bits/stdc++.h>
using namespace std;

int isInQuoteMod = 0;
int errorCode = 0;
string currentString;
deque<string> outputBuffer;
map<int, string> errorCodeMap = {
    {1, "Match Error"}, 
    {2, "Unclosed Mark"}
};
stack<int> commandType;
map<string, int> commandMap = {
    {"[h1]"     , 1}, {"[/h1]"      , 11},
    {"[h2]"     , 2}, {"[/h2]"      , 12},
    {"[i]"      , 3}, {"[/i]"       , 13},
    {"[b]"      , 4}, {"[/b]"       , 14},
    {"[url]"    , 5}, {"[/url]"     , 15},
    {"[img]"    , 6}, {"[/img]"     , 16},
    {"[quote]"  , 7}, {"[/quote]"   , 17}
};

void modifyCommand (string cmd) {
    if (cmd[1] != '/') {
        if (cmd[1] == 'u') {
            commandType.push(commandMap["[url]"]);
        } else if (cmd[1] == 'i' && cmd[2] == 'm') {
            commandType.push(commandMap["[img]"]);
        } else {
            commandType.push(commandMap[cmd]);
            if (cmd == "[quote]") {
                isInQuoteMod = 1;
            }
        }
    } else {
        if (!commandType.size()) {
            errorCode = 1;
            return;
        }
        if (cmd[2] == 'u') {
            if (commandType.top() != commandMap["[url]"]) {
                errorCode = 1;
                return;
            }
            commandType.pop();
        } else if (cmd[2] == 'i' && cmd[3] == 'm') { 
            if (commandType.top() != commandMap["[img]"]) {
                errorCode = 1;
                return;
            }
            commandType.pop();
        } else {
            if (commandType.top() != commandMap[cmd] - 10) {
                errorCode = 1;
                return;
            }
            commandType.pop();
            if (cmd == "[/quote]") {
                isInQuoteMod = 0;
            }
        }
    }
}

void printParser (int l, int r) {
    for (int i = l; i <= r; i++) {
        if (outputBuffer[i][0] != '[') {
            cout << outputBuffer[i];
        } else {
            if (outputBuffer[i] == "[h1]" || outputBuffer[i] == "[/h1]") {
                if (outputBuffer[i] == "[h1]") {
                    cout << "# ";
                } else {
                    cout << " #";
                }
            } else if (outputBuffer[i] == "[h2]" || outputBuffer[i] == "[/h2]") {
                if (outputBuffer[i] == "[h2]") {
                    cout << "## ";
                } else {
                    cout << " ##";
                }
            } else if (outputBuffer[i] == "[i]" || outputBuffer[i] == "[/i]") {
                cout << "*";
            } else if (outputBuffer[i] == "[b]" || outputBuffer[i] == "[/b]") {
                cout << "__";
            } else if (outputBuffer[i][1] == 'u') {
                string urlString = outputBuffer[i];
                int j = 5;
                while (j < urlString.size() && urlString[j] != ']') {
                    j++;
                }
                string url = urlString.substr(5, j - 5);
                cout << "[";
                int k;
                for (k = i + 1; k < r + 1; k++) {
                    if (outputBuffer[k] == "[/url]") {
                        break;
                    }
                }
                printParser(i + 1, k - 1);
                cout << "](" << url << ")";
                i = k + 1;
            } else if (outputBuffer[i][1] == 'i' & outputBuffer[i][2] == 'm') {
                string imgString = outputBuffer[i];
                int j = 5;
                while (j < imgString.size() && imgString[j] != ']') {
                    j++;
                }
                string img = imgString.substr(5, j - 5);
                cout << "![";
                int k;
                for (k = i + 1; k < r + 1; k++) {
                    if (outputBuffer[k] == "[/img]") {
                        break;
                    }
                } 
                printParser(i + 1, k - 1);
                cout << "](" << img << ")";
                i = k + 1;
            } else if (outputBuffer[i][1] == 'q') {
                if ((i > 0 && outputBuffer[i - 1] != "\n")) {
                    cout << "\n";
                }
                int newLine = 1;
                int flg = 1;
                for (int k = outputBuffer[i + 1] == "\n"? i + 2: i + 1; k < r + 1; k++) {
                    if (outputBuffer[k] == "[/quote]") {
                        i = k;
                        break;
                    }
                    if (newLine) {
                        cout << "> ";
                        newLine = 0;
                    }
                    if (flg) {
                        for (int p = 0; p < outputBuffer[k].size(); ++p) {
                            if (outputBuffer[k][p] == ' ') {
                                continue;
                            } else {
                                int s;
                                for (s = p; s < outputBuffer[k].size(); s++) {
                                    cout << outputBuffer[k][s];
                                }
                                p = s;
                            }
                        }
                        flg = 0;
                    } else {
                        if (k + 1 < r + 1 && outputBuffer[k + 1] == "\n") {
                            int s = outputBuffer[k].size() - 1;
                            while (s >= 0 && outputBuffer[k][s] == ' ') {
                                s--;
                            }
                            for (int p = 0; p <= s; ++p) {
                                cout << outputBuffer[k][p];
                            }
                        } else {
                            cout << outputBuffer[k];    
                        }
                    }
                    if (outputBuffer[k] == "\n") {
                        newLine = 1;
                    }
                }
                // cout << i << " " << outputBuffer[i] << '\n';
            }
        }
    }
}

int main () {
    while (getline(cin, currentString)) {
        int lasStringIdx = 0;
        int currentStringLength = currentString.length();
        for (int i = 0; i < currentStringLength; i++) {
            if (currentString[i] == '[') {
                int j = i;
                while (j < currentStringLength && currentString[j] != ']') {
                    j++;
                }
                string currentCmd = currentString.substr(i, j - i + 1);

                if (isInQuoteMod && currentCmd != "[/quote]") {
                    i = j;
                    continue;
                }

                if (i != lasStringIdx) {
                    outputBuffer.push_back(currentString.substr(lasStringIdx, i - lasStringIdx));
                }

                outputBuffer.push_back(currentCmd);

                modifyCommand(currentCmd);
                if (errorCode) {
                    cout << errorCodeMap[errorCode] << '\n';
                    return 0;
                }

                i = j;
                lasStringIdx = j + 1;
            }
        }
        if (lasStringIdx != currentStringLength) {
            outputBuffer.push_back(currentString.substr(lasStringIdx, currentStringLength - lasStringIdx));   
        }
        outputBuffer.push_back("\n");
    }
    if (commandType.size()) {
        cout << errorCodeMap[errorCode = 2] << '\n';
        return 0;
    }
    printParser(0, outputBuffer.size() - 1);
    return 0;
} 