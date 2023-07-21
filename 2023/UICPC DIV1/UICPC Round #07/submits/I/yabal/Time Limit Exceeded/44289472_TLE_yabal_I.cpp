#include <iostream>
#include <vector>

int main() {
    int s = 1;
    int e = 1;
    std::string firstline;
    std::getline(std::cin, firstline);
    int n = std::stoi(firstline.substr(0, firstline.find(' ')));
    int c = std::stoi(firstline.substr(firstline.find(' ') + 1));
    std::string second;
    std::getline(std::cin, second);
    std::vector<int> w;
    size_t pos = 0;
    while ((pos = second.find(' ')) != std::string::npos) {
        w.push_back(std::stoi(second.substr(0, pos)));
        second.erase(0, pos + 1);
    }
    w.push_back(std::stoi(second));
    auto wsum = [&]() {
        int answer = 0;
        for (int i = s - 1; i <= e; i++) {
            answer += w[i];
        }
        return answer;
    };
    std::vector<int> x;
    std::vector<int> y;
    x.push_back(s);
    y.push_back(e);
    while (s <= n) {
        if (e + 1 > n) {
            s += 1;
        } else if (wsum() > c) {
            s += 1;
        } else {
            e += 1;
        }
        x.push_back(s);
        y.push_back(e);
    }
    for (int i = 1; i <= n; i++) {
        int count = 0;
        for (int j = 0; j < x.size(); j++) {
            if (i >= x[j] && i <= y[j]) {
                count += 1;
            }
        }
        std::cout << count << std::endl;
    }
    return 0;
}
