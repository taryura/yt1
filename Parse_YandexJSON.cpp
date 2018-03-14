#include "wxGUI2.h"
#include "Parse_YandexJSON.h"

void Parse_YandexJSON::parse (std::string &text){
        Str_length1 = text.length();
        a = find_ind(text, '{', '}', Str_length1);
        JSON = JSON1;
        Str_length2 = JSON.length();
        b = find_ind(JSON1, '[', ']', Str_length2);
        JSON_text = JSON1;

        };

// Finding indexes
int Parse_YandexJSON::find_ind (std::string &text, char chto_fnd1, char chto_fnd2, int Str_length){
        index1 = find_char (text, chto_fnd1, Str_length);
        index2 = find_char (text, chto_fnd2, Str_length);
        if ((index1 > 9997) or (index2 > 9997)) {
                JSON1 = "Incorrect format of the data";
                std::cout << JSON << std::endl;
                return 1;}
        else {
            JSON1 = cut_json(text, index1, index2);
            return 0;
        }
  };


// Finding a character and returning its position index
int Parse_YandexJSON::find_char (std::string &text, char chto_fnd, int Str_length){
        for (int i = 0; i < Str_length; i++){
        //std::cout << "Length" << Str_length << endl;
        //cout << "i= " << i << "  " << text[i] << "  " << chto_fnd << endl;
        if (text[i] == chto_fnd) {return i;}
            else if (i == (Str_length - 1)) {return (9999);}
                 else continue;
        }
        return 0;
    };

std::string Parse_YandexJSON::cut_json (std::string &text, int index1, int index2){
//cutting the text between index1 and index2
        char * JSON_char;
        int array_length = index2 - index1 +2;
        JSON_char = new (std::nothrow) char[array_length];
        if (JSON_char == nullptr){
           std::string a = "Error: memory could not be allocated";
           std::cout << a << std::endl;
           return a;
        }
               else {
                    //std::cout << "Array has been created" << endl;
                    //std::cout << "index1= " << index1 << "index2= " << index2 << endl;
                    for (int i = index1; i < index2+1; i++){
                        JSON_char[i-index1] = text[i];
                        //std::cout << "Pointer= " << i << "char " << text[i] << endl;
                    }
               JSON_char[index2-index1+1] = '\0';
               }
        //cout << JSON_char << endl;
        std::string k = JSON_char;
        delete[] JSON_char;
        return k;

        };

