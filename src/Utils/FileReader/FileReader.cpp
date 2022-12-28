#include "FileReader.hpp"


std::string FileReader::getFileData(std::string_view filePath) {
    if(filePath.empty()) {
        std::cerr << "Filepath empty \n";
        return "";
    }

    std::string absolutePath;

    if(*filePath.begin() == ':')
        absolutePath += std::string(PROJECT_DIR) + std::string(filePath.substr(1));
    else
        absolutePath += std::string(PROJECT_DIR) + std::string(filePath.data());

    if(std::filesystem::exists(absolutePath)) {
        std::ifstream file;
        file.open(absolutePath);

        std::stringstream buffer;
        buffer << file.rdbuf();

        file.close();
        std::cout << buffer.str();
        return buffer.str();
    }
    std::cerr << "File doens't exist: " << filePath << '\n';
    return "";
}

