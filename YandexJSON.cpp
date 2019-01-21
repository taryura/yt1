#include "wxGUI2.h"
#include "YandexJSON.h"
#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <cstdlib>
#include <istream>
#include <ostream>
#include <fstream>

void YandexJSON::SetRqst (std::string &a){
        request = a;
        Str_length = request.length();

        std::ifstream fin("key/ykey.io");
        fin >> Ykey;
        fin.close();

        for (unsigned int i = 0; i < strlen(Ykey);i++){
        Ykey[i]-=1;
        }
        std::stringstream request_2;
        request_2 << "POST /api/v1.5/tr.json/translate?lang=en-fr&key=";
        request_2 << Ykey << " HTTP/1.1\r\n";
        request_2 << "Host: translate.yandex.net\r\n";
        request_2 << "Accept: */*\r\n";
        request_2 << "Content-Type: application/x-www-form-urlencoded\r\n";
        request_2 << "Content-Length: " << Str_length + 5 << "\r\n";
        request_2 << "\r\n";
        request_2 << "text=" << request << " ";

        request = request_2.str();
    };
