#include "common.hpp"

#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

static constexpr const char DELIM = ',';

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
    // ��������������������������������ͻ
    // � Check program input arguments. �
    // ��������������������������������ͼ
    if (argc != 2) {
        std::cout << "Usage: COVARMAT <input file>" << std::endl;
        return EXIT_FAILURE;
    }

    // �����������������������ͻ
    // � Estimate file length. �
    // �����������������������ͼ
    auto file_len = ex::get_file_length(argv[1]);

    // �������������������������������ͻ
    // � Read all instances from file. �
    // �������������������������������ͼ
    std::cout << "Reading instances from file..." << std::endl;

    std::vector<std::string> instances;
    instances.reserve(file_len);

    {
        std::ifstream file{argv[1]};

//        std::transform(std::istream_iterator<read::line>{file},
//                       std::istream_iterator<read::line>{},
//                       std::begin(instances),
//                       [] (const std::string& line) {
//            return line;
//        });
    }
    std::cout << "Read " << instances.size() << " instances from file." <<std::endl;

    using instance_value_t = double;
    using column_t = std::vector<instance_value_t>;
    std::vector<column_t> columns;

    std::cout << "Done!" << std::endl;
}
