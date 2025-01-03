#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>

int main() {
    std::string is;
    std::getline(std::cin, is);
    std::stringstream ss(is);

    int n, m;
    std::vector<std::string> lines;
    std::string s, t, l = "****                                                                            ";

    ss >> n >> m >> s >> t;

    std::unordered_map<char, char> dict;
    for (int i = 0; i < s.size(); i++) dict[s[i]] = t[i];

    while (std::getline(std::cin, is)) {
        if(is == l) break;

        for (int i = 0; i < is.size(); i++) if (dict.count(is[i])) is[i] = dict[is[i]];

        std::string f = "";
        int space_counter = 0;

        for (int i = 0; i < is.size(); i++)
            if (is[i] == ' ') space_counter++;
            else if (space_counter == 0) f += is[i];
            else {
                if (space_counter >= 4) {
                    f += '&';
                    if (space_counter <= 9) f += '0';
                    f += std::to_string(space_counter);
                } else for (int i = 0; i < space_counter; i++) f += ' ';
                space_counter = 0;
                f += is[i];
            }

        if (space_counter > 0) {
            if (space_counter >= 4) {
                f += '&';
                if (space_counter <= 9) f += '0';
                f += std::to_string(space_counter);
            } else for (int i = 0; i < space_counter; i++) f += ' ';
        }

        lines.push_back(f);
    }

    int length_counter = lines[0].size();
    int last_index = 0;

    for (int i = 1; i < lines.size(); i++)
        if (length_counter + lines[i].size() > n) {
            for (int j = last_index; j < i; j++) std::cout << lines[j];
            std::cout << std::endl;
            length_counter = lines[i].size();
            last_index = i;
        } else length_counter += lines[i].size();

    while (last_index != lines.size()) std::cout << lines[last_index++];
    std::cout << std::endl;

    return 0;
}
