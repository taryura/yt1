#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <cstdlib>
#include <istream>
#include <ostream>

class YandexJSON {

public:
    int Str_length;
    std::string request;

void SetRqst (std::string &a);

private:
    char Ykey[128];
};
