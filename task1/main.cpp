#include <iomanip>
#include <iostream>

double avg(const int* temps, const int N) {
    double sum = 0;
    for (int i = 0; i < N; ++i) {
        sum += temps[i];
    }
    return sum / N;
}

 std::pair<int, int> min_max(const int* temps, const int N) {
    int mn = temps[0];
    int mx = temps[0];
    for (int i = 1; i < N; ++i) {
        mn = std::min(mn, temps[i]);
        mx = std::max(mx, temps[i]);
    }
    return {mn, mx};
}

int cnt_cold(const int* temps, const int N) {
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        ans += (temps[i] < 0);
    }
    return ans;
}

int main() {
    int N;
    std::cin >> N;

    int* temps = new int[N];
    for (int i = 0; i < N; ++i) {
        std::cin >> temps[i];
    }

    auto [mn, mx] = min_max(temps, N);
    std::cout << std::fixed << std::setprecision(1) << avg(temps, N) << '\n';
    std::cout << mn << ' ' << mx << '\n';
    std::cout << cnt_cold(temps, N);

    delete[] temps;

    return 0;
}
