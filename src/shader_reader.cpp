#include "includes.h"


// creates, but does not manage, a char array of the shader program
char* ShaderReader::load(const char* fname) {

    std::ifstream ifs(fname);
    return std::string(std::istreambuf_iterator<char>(ifs),
                       std::istreambuf_iterator<char>()).c_str();

}