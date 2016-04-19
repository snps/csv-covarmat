#include "common.hpp"

#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

static constexpr const char DELIM = ',';

using instance_value_t = double;
using column_t = std::vector<instance_value_t>;

namespace read {
    class line {
        std::string data;
    public:
        friend std::istream& operator>>(std::istream& is, line& l) {
            std::getline(is, l.data);
            return is;
        }
        operator std::string() const { return data; }
    };
}

int main(int argc, char* argv[]) {
    // ษออออออออออออออออออออออออออออออออป
    // บ Check program input arguments. บ
    // ศออออออออออออออออออออออออออออออออผ
    if (argc != 2) {
        std::cout << "Usage: COVARMAT <input file>" << std::endl;
        return EXIT_FAILURE;
    }

    // ษอออออออออออออออออออออออป
    // บ Estimate file length. บ
    // ศอออออออออออออออออออออออผ
    auto file_len = ex::get_file_length(argv[1]);

    // ษอออออออออออออออออออออออออออออออป
    // บ Read all instances from file. บ
    // ศอออออออออออออออออออออออออออออออผ
    std::cout << "Reading instances from file..." << std::endl;

    std::vector<std::string> instances;
    instances.reserve(file_len);

    {
        std::ifstream file{argv[1]};

        instances.insert(std::end(instances),
                         std::istream_iterator<read::line>{file},
                         std::istream_iterator<read::line>{});
    }
    std::cout << "Read " << instances.size() << " instances from file." <<std::endl;

    auto columns = std::accumulate(std::begin(instances), std::end(instances),
                                   std::vector<column_t>{},
                                   [] (auto& mem, auto& instance) {
        instance.push_back(DELIM);
        mem.push_back(std::accumulate(std::begin(instance), std::end(instance),
                               column_t{},
                               [buf = std::ostringstream{}] (auto& mem, char c) mutable {
            if (c == DELIM) {
                mem.push_back(std::stod(buf.str()));
                buf.str("");
                buf.clear();
            } else {
                buf << c;
            }
            return mem;
        }));
        return mem;
    });

    for (auto&& row : columns) {
        for (auto&& col : row) {
            std::cout << col << ", ";
        }
        std::cout << std::endl;
    }

    std::cout << "Done!" << std::endl;
}
