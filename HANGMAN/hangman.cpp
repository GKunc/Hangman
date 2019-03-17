#include "hangman.hpp"

int main() {
    
    char litera ='\0';
    
    std::string slowo = wylosujSlowo("baza_slow.txt");
    std::string uzyte = "";
    bool wygrana = false;
    bool poprawna = false;
    int proba = 0;
    int zgadniete = 0;
    std::string doZgadniecia;

    doZgadniecia = zamienSlowo(slowo);
    

    do {
        
        rysujPlansze(doZgadniecia, proba, wygrana, uzyte);
        
        std::cin  >> litera;

        uzyte = uzyte + litera + " ";

        for (int i = 0; i < slowo.length(); ++i) {
            if(litera == slowo[i]) {
                ++zgadniete;
                doZgadniecia[2*i] = litera;
                poprawna = true;
            }
        }
        
        if(poprawna == false) ++proba;
        
        if (zgadniete == slowo.length()) {
            wygrana = true;
        }
        
        if(wygrana) break;

        poprawna = false;

    } while (proba < 10);
    
    if (wygrana == true) {
        rysujPlansze(doZgadniecia, proba, wygrana, uzyte);
        centruj("WYGRALES");
    } else {
        rysujPlansze(doZgadniecia, proba, wygrana, uzyte);
        centruj("PRZEGRALES");
        std::cout << "------------------------------------------" << std::endl;
        centruj("Slowem do zgadniecia bylo:");
        centruj(slowo);
    }
    std::cout << "------------------------------------------" << std::endl;

    
}
