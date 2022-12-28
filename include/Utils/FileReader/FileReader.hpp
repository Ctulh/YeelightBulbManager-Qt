
#pragma once

#include <fstream>
#include <sstream>
#include <filesystem>
#include <iostream>
#include <string_view>
#include "config.h"


class FileReader {
public:
    static std::string getFileData(std::string_view filePath);
};


