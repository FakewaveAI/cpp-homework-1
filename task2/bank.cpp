#include <cstring>
#include <iomanip>
#include <iostream>

struct query {
    const char* first;
    void(*second)(int&);
};

void deposit(int& cur) {
    int k;
    std::cin >> k;
    if (k <= 0) {
        std::cout << "error\n";
        return;
    }
    cur += k;
}

void withdraw(int& cur) {
    int k;
    std::cin >> k;
    if (k <= 0 || k > cur) {
        std::cout << "error\n";
        return;
    }
    cur -= k;
}

void balance(int& cur) {
    std::cout << cur << '\n';
}

void reset(int& cur) {
    cur = 0;
}

void round(int& cur) {
    cur -= cur % 1000;
}

int main() {
    query type[] = {
        {"deposit", deposit},
        {"withdraw", withdraw},
        {"balance", balance},
        {"reset", reset},
        {"round", round}
    };
    char cmd[9];
    int cur = 0;
    std::cin >> std::setw(9) >> cmd;
    while (std::strcmp(cmd, "stop") != 0) {
        bool found = false;
        for (auto& s : type) {
            if (std::strcmp(cmd, s.first) == 0) {
                found = true;
                s.second(cur);
            }
        }
        if (found == false) {
            std::cout << "error\n";
        }
        std::cin >> std::setw(9) >> cmd;
    }

    return 0;
}
