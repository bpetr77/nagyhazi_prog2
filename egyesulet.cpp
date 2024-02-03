#include <iostream>
#include <cstring>
#include <fstream>
#include "egyesulet.h"
#include "string.h"
#include "memtrace.h"

Csapat& Csapat::operator=(Csapat& cs){
        if(this == &cs){
            return *this;
        }
        this->nev = cs.nev;
        this->tagok_szama = cs.tagok_szama;
        return *this;
    }


void Foci::kiir(std::ostream& os) const{
    os << "A Foci csapat: " <<std::endl<< "Nev: "<< get_nev()<<std::endl;
    os << "Tagok szama: " << get_tagok_szama() <<std::endl<< "Labdak szama: " << get_labdak() <<std::endl;

}

void Foci::iras(std::ofstream& fout){
    if (fout.is_open()) {
        fout << "1" << std::endl;
        fout << get_nev() << std::endl;
        fout << get_tagok_szama() << std::endl;
        fout << get_labdak();
    }
    else
        std::cout << "hibas file megnyitas" << std::endl;
}

void Foci::olvasas(std::ifstream& fin) {
    if (!fin.is_open()) {
        std::cout << "hibas file megnyitas" << std::endl;
    }
    fin >> nev;
    fin >> tagok_szama;
    fin >> labdak;
}


void Kajak::kiir(std::ostream& os) const{
    os << "A Kajak csapat: " <<std::endl<< "Nev: "<< get_nev()<<std::endl;
    os << "Tagok szama: " << get_tagok_szama() <<std::endl<< "Tamogatas merteke: " << get_tamogatas() <<std::endl;
}

void Kajak::iras(std::ofstream& fout){
    if (fout.is_open()) {
        fout << "2" << std::endl;
        fout << get_nev() << std::endl;
        fout << get_tagok_szama() << std::endl;
        fout << get_tamogatas();
    }
    else
        std::cout << "hibas file megnyitas" << std::endl;
}

void Kajak::olvasas(std::ifstream& fin) {
    if (!fin.is_open()) {
        std::cout << "hibas file megnyitas" << std::endl;
    }

    fin >> nev;
    fin >> tagok_szama;
    fin >> tamogatas;
}


void Kenu::kiir(std::ostream& os) const{
    os << "A Kenu csapat: " <<std::endl<< "Nev: "<< get_nev()<<std::endl;
    os << "Tagok szama: " << get_tagok_szama() <<std::endl<< "Edzok: " << get_edzo1() << ", " << get_edzo2() <<std::endl;
}

void Kenu::iras(std::ofstream& fout){
    if (fout.is_open()) {
        fout<< "3" << std::endl;
        fout << get_nev() << std::endl;
        fout << get_tagok_szama() << std::endl;
        fout << get_edzo1() << std::endl;
        fout << get_edzo2();

    }
    else
        std::cout << "hibas file megnyitas" << std::endl;
}

void Kenu::olvasas(std::ifstream& fin) {
   if (!fin.is_open()) {
       std::cout << "hibas file megnyitas" << std::endl;
    }
    fin >> nev;
    fin >> tagok_szama;

    fin >> edzo1;

    fin >> edzo2;

}


