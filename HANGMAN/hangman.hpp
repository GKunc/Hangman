#ifndef _HANGMAN_HPP_
#define _HANGMAN_HPP_

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <vector>

std::string wylosujSlowo(std::string path) {

    std::string str;
    std::vector<std::string> v;
    std::ifstream plik(path);
    if(plik.is_open()) {
        while(std::getline(plik,str))
            v.push_back(str);
        
        srand(time(0));
        int losoweSlowo = rand() % v.size();
        
        str = v.at(losoweSlowo);
        plik.close();
        }
    return str;
}

std::string zamienSlowo(std::string slowo) {
    std::string zmienione;
    for (int i = 0; i < slowo.length(); ++i) {
        zmienione += "_ ";
    }
    return zmienione;
}

void centruj(std::string str) {
    int length = (42 - str.length())/2;
    for(int i = 0; i < length; ++i) {
        std::cout << " ";
    }
    std::cout << str << std::endl;
}

void wisielec(int proba, bool win) {
    if(win == false) {
        if(proba > 0)  centruj("|");
        else centruj("");
        if(proba > 1)  centruj("|");
         else centruj("");
        if(proba > 2)  centruj("O");
         else centruj("");
        if(proba == 4) centruj("|"); else if(proba < 4) centruj("");
        if(proba == 5) centruj("/| ");
        if(proba > 5)  centruj("/|\\");
        if(proba > 6)  centruj("|"); else centruj("");
        if(proba == 8) centruj("/  "); else if(proba < 8) centruj("");
        if(proba > 8)  centruj("/ \\");
        if(proba < 10) centruj("+---------------+");
    }
    if(win == true) {
        centruj("O");
        centruj("/|\\");
        centruj("|");
        centruj("/ \\");
    }
}

void rysujPlansze(std::string doZgadniecia, int proba, bool win, std::string uzyte) {
    
    system("clear");
    
    std::cout << "------------------------------------------" << std::endl;
    centruj("Witam w grze SZYBIENICA");
    std::cout << "------------------------------------------" << std::endl;
    centruj("ZGADNIJ HASLO");
    std::cout << "------------------------------------------" << std::endl;
    centruj(doZgadniecia);
    std::cout << "------------------------------------------" << std::endl;
    std::cout << std::endl;
    wisielec(proba,win);
    std::cout << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    centruj("DOSTEPNE LITERY");
    std::cout << "------------------------------------------" << std::endl;
    
    std::string litery;
    for (char i = 'A'; i <= 'M'; i++)
    {
        if (uzyte.find(i) == std::string::npos)
        {
            litery += i;
            litery += " ";
        }
        else
            litery += "  ";
    }
    centruj(litery);

    std::string litery2;
    for (char i = 'N'; i <= 'Z'; i++)
    {
        if (uzyte.find(i) == std::string::npos)
        {
            litery2 += i;
            litery2 += " ";
        }
        else
            litery2 += "  ";
    }
    centruj(litery2);
    

    std::cout << "------------------------------------------" << std::endl;


}

#endif
