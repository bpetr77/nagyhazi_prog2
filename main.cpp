#include <iostream>
#include <sstream>
#include <cstring>
#include <fstream>
#include "egyesulet.h"
#include "string.h"
#include "gtest_lite.h"
#include "tarolo.h"
#include "vezerles.h"
#include "egyesulet_test.h"
#include "memtrace.h"


using namespace std;

int main()
{
    int a;
    bool ervenytelen_valasz = true;
    bool helyes_formatum = false;
    bool helyes_formatum2 = false;
    bool helyes_formatum3 = false;

    while (ervenytelen_valasz) {
        std::cout << "Valasszon a kovetkezo lehetosegek kozul:" << std::endl;
        std::cout << "1. Testek kiprobalasa" << std::endl;
        std::cout << "2. Program kiprobalasa" << std::endl;

        while (!helyes_formatum) {
            std::cin >> a;
            if (std::cin.fail()) {
                std::cout << "Hibas formatum! Egy (pozitiv egesz) szamot szeretnek kerni." << std::endl;
                std::cin.clear();
                std::cin.ignore(100, '\n');
            } else {
                helyes_formatum = true;
            }
        }
        if (a == 1) {
            test();
            ervenytelen_valasz = false;
        } else if (a == 2) {
            ervenytelen_valasz = false;
        } else {
            std::cout << "Ervenytelen valasztas! Probalkozzon ujra." << std::endl;
        }
    }

    Tarolo tarolo;

    int valasz;
    if(a != 1){
    do {
        Menu_kiir();
            helyes_formatum2 = false;
            while (!helyes_formatum2) {
                std::cin >> valasz;
                if (std::cin.fail()) {
                    std::cout << "Hibas formatum! Egy (pozitiv egesz) szamot szeretnek kerni." << std::endl;
                    std::cin.clear();
                    std::cin.ignore(100, '\n');
                } else{
                    helyes_formatum2 = true;
                }
            }
        switch (valasz) {
            case 1:
                clear_console();
                int sport;
                std::cout << "Sport valasztas: " << std::endl;
                std::cout << "[1]. Kenu" << std::endl;
                std::cout << "[2]. Foci" << std::endl;
                std::cout << "[3]. Kajak" << std::endl;
                std::cout << "Valasztott sport: ";

                helyes_formatum3 = false;
                while (!helyes_formatum3) {
                    std::cin >> sport;
                    if (std::cin.fail()) {
                        std::cout << "Hibas formatum! Egy (pozitiv egesz) szamot szeretnek kerni." << std::endl;
                        std::cin.clear();
                        std::cin.ignore(100, '\n');
                    } else{
                        helyes_formatum3 = true;
                    }
                }

                switch (sport) {
                    case 1:
                        clear_console();
                        Kenu_letrehoz(tarolo);
                        break;
                    case 2:
                        clear_console();
                        Foci_letrehoz(tarolo);
                        break;
                    case 3:
                        clear_console();
                        Kajak_letrehoz(tarolo);
                        break;
                    default:
                        clear_console();
                        std::cout << "Ervenytelen sport valasztas!" << std::endl;
                        break;
                }
                break;
            case 2:
                clear_console();
                Csapatok_listaz(tarolo);
                break;
            case 3:
                clear_console();
                Csapat_torol(tarolo);
                break;
            case 4:
                clear_console();
                fajlba_ment(tarolo);
                break;
            case 5:
                clear_console();
                fajlbol_olvas(tarolo);
                break;
            case 6:
                clear_console();
                tarolo.tarolo_torles();
                std::cout << "Az osszes csapat torlesre kerult" << std::endl;
                break;
            case 7:
                clear_console();
                std::cout << "Viszlat!" << std::endl;
                break;
            default:
                clear_console();
                std::cout << "Ervenytelen menupont!" << std::endl;
                break;
        }
    }while (valasz != 7);
    }


    return 0;
}


