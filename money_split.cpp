#include<bits/stdc++.h>

std::map<std::string, double> parm;

double round(double value, int places) {
    double factor = std::pow(10.0, places);
    return std::round(value * factor) / factor;
}

void findPath(std::map<std::string, double>& details) {
    double max_value = std::max_element(details.begin(), details.end(),
        [](const auto& a, const auto& b) {
            return a.second < b.second;
        })->second;

    double min_value = std::min_element(details.begin(), details.end(),
        [](const auto& a, const auto& b) {
            return a.second < b.second;
        })->second;

    if (max_value != min_value) {
        auto max_key = std::find_if(details.begin(), details.end(),
            [max_value](const auto& entry) {
                return entry.second == max_value;
            })->first;

        auto min_key = std::find_if(details.begin(), details.end(),
            [min_value](const auto& entry) {
                return entry.second == min_value;
            })->first;

        double result = max_value + min_value;
        result = round(result, 1);

        if (result >= 0.0) {
            std::cout << min_key << " needs to pay " << max_key << ": " << round(std::abs(min_value), 2) << std::endl;
            details[max_key] = result;
            details[min_key] = 0.0;
        } else {
            std::cout << min_key << " needs to pay " << max_key << ": " << round(std::abs(max_value), 2) << std::endl;
            details[max_key] = 0.0;
            details[min_key] = result;
        }

        findPath(details);
    }
}

int main() {
    int numEntries;
    std::cout << "Enter the number of entries: ";
    std::cin >> numEntries;

    for (int i = 0; i < numEntries; i++) {
        std::string key;
        double value;

        std::cout << "Enter key for entry " << i + 1 << ": ";
        std::cin >> key;
        std::cout << "Enter value for entry " << i + 1 << ": ";
        std::cin >> value;

        parm[key] = value;
    }

    findPath(parm);

    return 0;
}
