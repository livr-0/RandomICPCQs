#include <array>
#include <iostream>
#include <string>

std::array<std::array<bool, 26>, 26> mapping;

void mark(char from, char to) {
    if (!mapping[from - 'a'][to - 'a']) {
        mapping[from - 'a'][to - 'a'] = true;
        for (int i = 0; i < 26; i++) {
            if (mapping[i][from - 'a']) {
                mark(i + 'a', to);
            }
            if (mapping[to - 'a'][i]) {
                mark(from, i + 'a');
            }
        }
    }
}

bool check(std::string from, std::string to) {
    if (from.size() != to.size()) {
        return false;
    }

    for (size_t i = 0; i < from.size(); i++) {
        if (!mapping[from[i] - 'a'][to[i] - 'a']) {
            return false;
        }
    }

    return true;
}

int main() {
    size_t trans_count, word_count;
    std::cin >> trans_count >> word_count;

    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            mapping[i][j] = i == j;
        }
    }

    for (size_t i = 0; i < trans_count; i++) {
        std::string from, to;
        std::cin >> from >> to;
        mark(from[0], to[0]);
    }

    for (size_t i = 0; i < word_count; i++) {
        std::string from, to;
        std::cin >> from >> to;
        if (check(from, to)) {
            std::cout << "yes\n";
        } else {
            std::cout << "no\n";
        }
    }

    return 0;
}
