#include <iostream>
#include <iomanip>
#include <cstring>

bool is_in_display(const int x, const int y) {
    return x >= 0 && x <= 9 && y >= 0 && y <= 4;
}

void clear(char** cur) {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 10; ++j) {
            cur[i][j] = ' ';
        }
    }
}

bool put(char** cur) {
    int x;
    int y;
    char c;
    std::cin >> x >> y >> c;
    if (!is_in_display(x, y)) {
        return false;
    }
    cur[y][x] = c;
    return true;
}

bool text(char** cur) {
    int x;
    int y;
    char word[11];
    std::cin >> x >> y;
    std::cin >> std::setw(11) >> word;
    int sz = (int)std::strlen(word);
    if (!is_in_display(x, y) || x + sz > 10) {
        return false;
    }
    for (int j = 0; j < sz; ++j) {
        cur[y][x + j] = word[j];
    }
    return true;
}

void print(char** cur) {
    for (int i = 0; i < 5; ++i) {
        std::cout << cur[i] << '\n';
    }
}

int main() {
    char** display = new char*[5];
    for (int i = 0; i < 5; ++i) {
        display[i] = new char[10];
    }
    clear(display);

    char cur[6];
    std::cin >> std::setw(6) >> cur;
    while (std::strcmp(cur, "quit") != 0) {
        if (std::strcmp(cur, "clear") == 0) {
            clear(display);
        }
        if (std::strcmp(cur, "put") == 0) {
            bool is_good = put(display);
            if (is_good == false) {
                std::cout << "error";
            }
        }
        if (std::strcmp(cur, "text") == 0) {
            bool is_good = text(display);
            if (is_good == false) {
                std::cout << "error";
            }
        }
        if (std::strcmp(cur, "print") == 0) {
            print(display);
        }

        std::cin >> std::setw(6) >> cur;
    }

    for (int i = 0; i < 5; ++i) {
        delete[] display[i];
    }
    delete[]display;
}
