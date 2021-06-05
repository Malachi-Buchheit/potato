#ifndef FILEUTILS_H
#define FILEUTILS_H
#include <iostream>
#include <string.h>
#include <fstream>

inline std::string read_file(const char* filepath) {
    FILE* file = fopen(filepath, "rt");
    if(!file)
        std::cout << "COULD NOT OPEN FILE " << filepath << std::endl;
    fseek(file, 0, SEEK_END);
    unsigned long length = ftell(file);
    char* data = new char[length+1];
    memset(data, 0, length+1);
    fseek(file, 0, SEEK_SET);
    fread(data, 1, length, file);
    fclose(file);

    std::string out(data);
    delete[] data;
    if(out.empty())
        std::cout << "ERROR: File " << filepath << " produced no output." << std::endl;
    return out;
}

#endif
