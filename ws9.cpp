#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

class RecordsManager {
public:
    int read(const std::string& filename) {
        std::ifstream file(filename);
        int sum = 0;
        std::string line;

        try {
            if (!file.is_open()) {
                throw std::ios_base::failure("Failed to open file");
            }

            while (std::getline(file, line)) {
                try {
                    int value = std::stoi(line);  
                    sum += value;
                } 
                catch (const std::invalid_argument&) {
                    std::cout << "invalid_argument error" << std::endl;
                    file.close();
                    throw;
                } 
                catch (const std::out_of_range&) {
                    std::cout << "out_of_range error" << std::endl;
                    file.close();
                    throw;
                }
            }
        } 
        catch (const std::ios_base::failure&) {
            std::cout << "ios_base::failure error" << std::endl;
            file.close();
            throw;
        }

        file.close(); 
        return sum;
    }
};

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
        return 1;
    }

    RecordsManager rm;

    try {
        int total = rm.read(argv[1]);
        std::cout << "Sum: " << total << std::endl;
    } 
    catch (const std::exception& e) {
        std::cerr << "Exception caught in main: " << e.what() << std::endl;
    }

    return 0;
}