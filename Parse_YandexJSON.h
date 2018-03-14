#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <cstdlib>
#include <istream>
#include <ostream>

class Parse_YandexJSON{

public:
    int Str_length1, Str_length2, index1, index2, a, b;
    std::string text, JSON1, JSON_text, JSON;

    void parse (std::string &text);
    int find_ind (std::string &text, char chto_fnd1, char chto_fnd2, int Str_length);


private:

    // Finding a character and returning its position index
    int find_char (std::string &text, char chto_fnd, int Str_length);
    std::string cut_json (std::string &text, int index1, int index2);
};
