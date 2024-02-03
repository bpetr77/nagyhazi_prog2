#include <iostream>
#include <cstring>
#include <fstream>
#include "egyesulet.h"
#include "string.h"
#include "tarolo.h"
#include "memtrace.h"


void Tarolo::hozza_ad(Csapat* cs){
        if(meret == kapacitas){
            kapacitas = kapacitas * 2;
            Csapat** uj_csapatok = new Csapat*[kapacitas];
            for(size_t i = 0; i < meret; i++){
                uj_csapatok[i] = csapatok[i];
            }
            delete[] csapatok;
            csapatok = uj_csapatok;
        }
        csapatok[meret] = cs;
        meret++;
    }

     void Tarolo::tarolo_kiir(std::ostream& os) const {
        for (size_t i = 0; i < meret; i++) {
            if (csapatok[i] != NULL){
                csapatok[i]->kiir(os);
            }
        }
    }

    void Tarolo::tarolo_fileba_iras(const String& filenev) {
        std::ofstream fout(filenev.c_str());
        if (fout.is_open()) {
            for (size_t i = 0; i < meret; i++) {
                csapatok[i]->iras(fout);
                if(i != meret - 1)
                    fout << std::endl;
            }
            fout.close();
        }
        else {
            std::cout << "Hibás file megnyitás" << std::endl;
        }
    }

    void Tarolo::olvasas(const String& filenev) {
        std::ifstream fin(filenev.c_str());
        if (fin.is_open()) {
            size_t i = 0;
            size_t tipus;
            while(fin){
                fin >> tipus;
                if(!fin.eof()){
                Csapat* cs;
                switch (tipus) {
                    case 1: {
                        cs = new Foci();
                        break;
                    }
                    case 2: {
                        cs = new Kajak();
                        break;
                    }
                    case 3: {
                        cs = new Kenu();
                        break;
                    }
                    default: {
                        std::cout <<"Ismeretlen csapat típus" << std::endl;
                    }
                }
                cs->olvasas(fin);
                hozza_ad(cs);

                i++;
            }
            }
            fin.close();
        }
        else {
            std::cout << "hiba tortent a file megnyitasa soran" << std::endl;
        }
    }


    void Tarolo::elem_torles(const String& nev){
        bool a = false;
        for(size_t i = 0; i < meret; i++){
            if (csapatok[i]->get_nev() == nev){
                delete csapatok[i];
                a = true;
                    for (size_t j = i; j < meret - 1; j++) {
                        csapatok[j] = csapatok[j + 1];
                    }
                    meret--;
                    break;
            }
        }
        if(a)
            std::cout << "A(z) " << nev << "- nevu csapat sikeresen torolve" << std::endl;
        else
            std::cout << "Nincs ilyen nevu csapat a nyilvantartasban! " << std::endl;

    }


    void Tarolo::tarolo_torles(){
        for(size_t i = 0; i < meret; i++){
            delete csapatok[i];
    }
    meret = 0;
    }







