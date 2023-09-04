#include <cstdio>
#include <iostream>
#include <map>
#include <sstream>
#include <set>
#include <vector>
#include <string>

using namespace std;

int main() {
    map<long long, long long> socks;
    map<long long, long long> last;
    string str, tag;
    set<long long> log;
    int sock;
    bool state = 1; // wake
    size_t input; cin >> input;
    vector<string> inputs;
    input++;
    while(input--) {
        getline(cin, str);
        inputs.push_back(str);
    }
    for (auto& stri : inputs) {
        stringstream ss(stri);
        ss >> tag;
        if (tag == "WEARSOCK") {
            ss >> sock;
            if (socks.find(sock) == socks.end()) {
                socks.emplace(sock,  1);
            }
            else {
                socks[sock]++;
            }
            log.insert(sock);
            if (state) {
                for (auto& entry : log) {
                    if (socks[entry] == last[entry]) continue;
                    cout << "SOCK " << entry << ' ' << socks[entry] << endl;
                }
                log = set<long long>();
                last = socks;
            }
        }
        else if (tag == "SLEEP") {
            state = 0;
        }
        else if (tag == "WASHSOCK") {
            ss >> sock;
            if (socks.find(sock) == socks.end()) {
                socks.emplace(sock, -1);
            }
            else {
                socks[sock]--;
            }
            log.insert(sock);
            if (state) {
                for (auto& entry : log) {
                    if (socks[entry] == last[entry]) continue;
                    cout << "SOCK " << entry << ' ' << socks[entry] << endl;
                }
                log = set<long long>();
                last = socks;
            }
        }
        else if (tag == "WAKE") {
            state = 1;
             for (auto& entry : log) {
                if (socks[entry] == last[entry]) continue;
                cout << "SOCK " << entry << ' ' << socks[entry] << endl;
            }
            log = set<long long>();
            last = socks;
        }
    }

    return 0;
}
