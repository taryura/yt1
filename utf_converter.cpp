#include "utf_converter.h"

utf_converter::utf_converter()
{
    //ctor
}

void utf_converter::esc2file (std::string &file_string){


    std::string esc_string = file_string;
    std::string c2_char, c3_char;
    std::string slash = "anr";
    slash[0] = 0x5C;

    Str_length = esc_string.length();

    reload_counter = 0;
    for (int i = 0; i <= Str_length; i++){
            if ((esc_string [i] == slash [0]) && (esc_string [i+1] == slash[1])){

                    file_string [i] = 0x0A;
                    reload (esc_string, i+1, Str_length);
                    Str_length --;

            }
                     else if ((esc_string [i] == slash [0]) && (esc_string [i+1] == slash[2])){

                        file_string [i] = 0x0D;
                        reload (esc_string, i+1, Str_length);
                        Str_length --;

                     }
                          else {

                            file_string [i] = esc_string [i];
                          }

    }

    file_string.resize (esc_string.length() - reload_counter);
    return;
};

void utf_converter::utf2ascii (std::string utf_string, std::string &ascii_string){

    std::string c2_char, c3_char;
    int utf1;
    int utf_byte;

    std::ifstream file_in("utf_table/utf8.utf");
    getline(file_in, c2_char);
    getline(file_in, c3_char);
    file_in.close();

    Str_length = utf_string.length();

    reload_counter = 0;
    for (int i = 0; i <= Str_length; i++){

        utf_byte = utf_string [i];
        if (utf_byte < 0) {utf_byte = utf_byte+256;}

        if (utf_byte < 0x7f){
            ascii_string [i] = utf_string [i];

        }
            else if (utf_byte == 194){

                    utf1 = utf_string[i+1] - 0xa1;
                    ascii_string [i] = c2_char [utf1];
                    reload (utf_string, i+1, Str_length);
                    Str_length --;

            }
                     else if (utf_byte == 195){

                        utf1 = utf_string[i+1] - 0x80;
                        ascii_string [i] = c3_char [utf1];
                        reload (utf_string, i+1, Str_length);
                        Str_length --;

                     }

    }



    ascii_string.resize (utf_string.length() - reload_counter);
    return;
};

void utf_converter::reload (std::string &utf_string, int i, int Str_length){
    reload_counter ++;
    for (int i1 = i ; i1 < (Str_length - 1); i1++){
        utf_string [i1] = utf_string [i1+1];
    }
    return;
};

std::u16string utf_converter::utf8toutf16(std::string utf_string){

    std::u16string utf16 = std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t>{}.from_bytes(utf_string.data());
    return utf16;
};

std::wstring utf_converter::utf8toutf16w(std::string utf_string){

    std::wstring wstr = std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>, wchar_t>{}.from_bytes(utf_string.data());

    return wstr;
};

