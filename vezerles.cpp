#include <iostream>
#include "string.h"
#include "tarolo.h"
#include "egyesulet.h"
#include "vezerles.h"
#include "memtrace.h"

void Menu_kiir() {
    std::cout << "---------------------------" << std::endl;
    std::cout << "[1]. Uj csapat letrehozasa" << std::endl;
    std::cout << "[2]. Csapatok listazasa" << std::endl;
    std::cout << "[3]. Csapat torlese" << std::endl;
    std::cout << "[4]. Fileba mentes" << std::endl;
    std::cout << "[5]. Filebol beolvasas " << std::endl;
    std::cout << "[6]. Az osszes csapat torlese " << std::endl;
    std::cout << "[7]. Kilepes" << std::endl;
    std::cout << "---------------------------" << std::endl;
    std::cout << "Valasszon egy menupontot: ";
}

void Kenu_letrehoz(Tarolo& tarolo) {
    std::cout << "Kenu csapat letrehozasa" << std::endl;
    String nev;
    size_t tagokSzama;
    String edzo1;
    String edzo2;
    bool helyes_formatum = false;

    std::cout << "Adja meg a csapat nevet: ";
    std::cin >> nev;
    std::cout << "Adja meg a csapat tagjainak szamat(szam): ";
    while (!helyes_formatum) {
        std::cin >> tagokSzama;

        if (std::cin.fail()) {
            std::cout << "Hibas formatum! Egy (pozitiv egesz) szamot szeretnek kerni." << std::endl;
            std::cin.clear();
            std::cin.ignore(100, '\n');
        } else {
            helyes_formatum = true;
        }
    }
    std::cout << "Adja meg az elso edzo nevet: ";
    std::cin >> edzo1;
    std::cout << "Adja meg a masodik edzo nevet: ";
    std::cin >> edzo2;

    Csapat* kenu = new Kenu(nev, tagokSzama, edzo1, edzo2);
    tarolo.hozza_ad(kenu);
    std::cout << std::endl;
    std::cout << "Kenu csapat sikeresen letrehozva!" << std::endl;
}



void Foci_letrehoz(Tarolo& tarolo) {
    std::cout << "Foci csapat letrehozasa" << std::endl;
    String nev;
    size_t tagokSzama;
    size_t labdak;
    bool helyes_formatum = false;

    std::cout << "Adja meg a csapat nevet: ";
    std::cin >> nev;
    std::cout << "Adja meg a csapat tagjainak szamat(szam): ";
    while (!helyes_formatum) {

        std::cin >> tagokSzama;

        if (std::cin.fail()) {
            std::cout <<  "Hibas formatum! Egy (pozitiv egesz) szamot szeretnek kerni: " << std::endl;
            std::cin.clear();
            std::cin.ignore(100, '\n');
        } else {
            helyes_formatum = true;
        }
    }

    helyes_formatum = false;
    std::cout << "Adja meg a csapat labdainak szamat(szam): ";
    while (!helyes_formatum) {

        std::cin >> labdak;

        if (std::cin.fail()) {
            std::cout << "Hibas formatum! Egy (pozitiv egesz) szamot szeretnek kerni: "<< std::endl;
            std::cin.clear();
            std::cin.ignore(100, '\n');
        } else {
            helyes_formatum = true;
        }
    }

    Foci* foci = new Foci(nev, tagokSzama, labdak);
    tarolo.hozza_ad(foci);
    std::cout << std::endl;
    std::cout << "Foci csapat sikeresen letrehozva!" << std::endl;
}


void Kajak_letrehoz(Tarolo& tarolo) {
    std::cout << "Kajak csapat letrehozasa" << std::endl;
    String nev;
    size_t tagokSzama;
    size_t tamogatas;
    bool helyes_formatum = false;

    std::cout << "Adja meg a csapat nevet: ";
    std::cin >> nev;
    std::cout << "Adja meg a csapat tagjainak szamat(szam): ";
    while (!helyes_formatum) {
        std::cin >> tagokSzama;
        if (std::cin.fail()) {
            std::cout << "Hibas formatum! Egy (pozitiv egesz) szamot szeretnek kerni: " << std::endl;
            std::cin.clear();
            std::cin.ignore(100, '\n');
        } else {
            helyes_formatum = true;
        }
    }

    helyes_formatum = false;
    std::cout << "Adja meg a csapat tamogatasanak merteket(szam): ";
    while (!helyes_formatum) {
        std::cin >> tamogatas;

        if (std::cin.fail()) {
            std::cout << "Hibas formatum! Egy (pozitiv egesz) szamot szeretnek kerni: " << std::endl;
            std::cin.clear();
            std::cin.ignore(100, '\n');
        } else {
            helyes_formatum = true;
        }
    }

    Csapat* kajak = new Kajak(nev, tagokSzama, tamogatas);
    tarolo.hozza_ad(kajak);
    std::cout << std::endl;
    std::cout << "Kajak csapat sikeresen letrehozva!" << std::endl;
}

void Csapatok_listaz(const Tarolo& tarolo) {
    std::cout << "Csapatok listaja:" << std::endl;
    tarolo.tarolo_kiir(std::cout);
}

void Csapat_torol(Tarolo& tarolo) {
    std::cout << "Csapat torlese" << std::endl;
    String nev;
    std::cout << "Adja meg a torlendo csapat nevet: ";
    std::cin >> nev;

    tarolo.elem_torles(nev);
}

void clear_console(){
    std::cout << "\x1B[2J\x1B[H";
}

void fajlba_ment(Tarolo& tarolo) {
    String filenev = "";
    std::cout << "Adja meg a file nevet ahova a csapat(ok) mentesre kerul(nek): ";
    std::cin >> filenev;
    tarolo.tarolo_fileba_iras(filenev);

}

void fajlbol_olvas(Tarolo& tarolo) {
    String filenev = "";
    std::cout << "Adja meg a file nevet ahonnan a csapat(ok)-at be szeretne olvasni: ";
    std::cin >> filenev;
    tarolo.olvasas(filenev);
}


