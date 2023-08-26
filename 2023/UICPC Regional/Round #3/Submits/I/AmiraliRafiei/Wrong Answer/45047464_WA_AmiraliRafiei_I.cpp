#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

std::vector<int> BAPC_interpreter(std::string program, int n, std::vector<int>& input_list) {
    std::vector<int> output_list = input_list;

    for (char command : program) {
        if (command == 'R') {
            std::reverse(output_list.begin(), output_list.end());
        } else if (command == 'D') {
            if (output_list.empty()) {
                std::vector<int> error_result;
                error_result.push_back(-1); // To indicate error
                return error_result;
            }
            output_list.erase(output_list.begin());
        }
    }

    return output_list;
}

int main() {
    int num_test_cases;
    std::cin >> num_test_cases;

    for (int i = 0; i < num_test_cases; ++i) {
        std::string program;
        std::cin >> program;

        int n;
        std::cin >> n;

        std::vector<int> input_list;
        if (n <= 0) {
            input_list.clear();
        } else {
            input_list.resize(n);
            for (int j = 0; j < n; ++j) {
                std::cin >> input_list[j];
            }
        }

        std::vector<int> result = BAPC_interpreter(program, n, input_list);

        if (result.size() == 1 && result[0] == -1) {
            std::cout << "error" << std::endl;
        } else {
            std::cout << "[";
            for (size_t j = 0; j < result.size(); ++j) {
                std::cout << result[j];
                if (j != result.size() - 1) {
                    std::cout << ",";
                }
            }
            std::cout << "]" << std::endl;
        }
    }

    return 0;
}
