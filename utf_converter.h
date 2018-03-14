#include <iostream>
#include <string>
#include <locale>
#include <codecvt>
#include <fstream>

class utf_converter
{
    public:
        utf_converter();

        void utf2ascii (std::string utf_string, std::string &ascii_string);
        std::u16string utf8toutf16 (std::string utf_string);
        std::wstring utf8toutf16w (std::string utf_string);
        int Str_length, reload_counter;

    private:
        void reload (std::string &utf_string, int i, int Str_length);

};
