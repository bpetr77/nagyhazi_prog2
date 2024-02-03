#ifndef SPORT_KLUB_H_INCLUDED
#define SPORT_KLUB_H_INCLUDED

#include <iostream>
#include "string.h"
#include "memtrace.h"



class Csapat{
protected:
String nev;
size_t tagok_szama;

public:
    ///Konstruktor
    /// Csapat osztály konstruktora
    /// @param nev - a csapat neve
    /// @param tagok_szama - a csapat tagjainak száma
    Csapat(const String nev = "", size_t tagok_szama = 0): nev(nev), tagok_szama(tagok_szama){}

    /// Csapat osztály másoló konstruktora
    /// @param cs - másolandó Csapat objektum
    Csapat(Csapat& cs){nev = cs.nev; set_tagok_szama(cs.get_tagok_szama());}

    /// Getterek
    const String& get_nev()const{return this->nev;}

    size_t get_tagok_szama()const{return tagok_szama;}

    /// Setterek
    void set_tagok_szama(size_t uj){this->tagok_szama = uj;}

    void set_nev(String uj){this->nev = uj;}

    /// Virtualis kiiras
    virtual void kiir(std::ostream& os)const = 0;

    /// Fajlba valo virtualis iras
    virtual void iras(std::ofstream& fout) = 0;

    /// Fajlba valo virtualis iras
    virtual void olvasas(std::ifstream& fin) = 0;


    /// operator =
    Csapat& operator=(Csapat& cs);

    /// Destruktor
    virtual ~Csapat() {}

};

class Foci : public Csapat{
size_t labdak;

public:
    ///Konstruktor
    Foci(const String nev = "", size_t tagok = 0, size_t labdak = 0): Csapat(nev, tagok), labdak(labdak){}

    /// Getterek
    size_t get_labdak()const {return labdak;}

    /// Setterek
    void set_labdak(size_t uj){labdak = uj;}

    /// Kiir
    /// Foci osztály kiir metódusa
    /// @param os - output stream, ide irjuk ki a Kajak csapat adatait
    void kiir(std::ostream& os) const;

    /// Foci osztály filba mentese
    /// @param fout - ofstream típusú fajlstream, ahova kiirjuk az osztaly adatait es egy szamot ami alapjan
    /// a taroloban beolvasaskor tudni fogjuk milyen osztalyrol van szo
    void iras(std::ofstream& fout);

    /// Foci osztály olvasas metódusa
    /// @param fin - ifstream tipusú fajlstream, ahova be olvassuk a filban levo adatokat
    void olvasas(std::ifstream& fin);

    /// Destruktor
    ~Foci() {}
};


class Kajak : public Csapat{
size_t tamogatas;

public:
    ///Konstruktor
    Kajak(const String nev = "", size_t tagok = 0, size_t tamogatas = 0): Csapat(nev, tagok), tamogatas(tamogatas){}

    /// Getterek
    size_t get_tamogatas()const{return tamogatas;}

    /// Setterek
    void set_tamogatas(size_t uj){tamogatas = uj;}

    /// Kiir
    /// Kajak osztály kiir metódusa
    /// @param os - output stream, ide irjuk ki a Kajak csapat adatait
    void kiir(std::ostream& os) const;

    /// Kajak osztály filba mentese
    /// @param fout - ofstream típusú fajlstream, ahova kiirjuk az osztaly adatait es egy szamot ami alapjan
    /// a taroloban beolvasaskor tudni fogjuk milyen osztalyrol van szo
    void iras(std::ofstream& fout);

    /// Kajak osztály filebol beolvasasa
    /// @param fin - ifstream típusú fajlstream, ahova be olvassuk a filban levo adatokat
    void olvasas(std::ifstream& fin);

    /// Destruktor
    ~Kajak() {}
};

class Kenu : public Csapat{
String edzo1;
String edzo2;

public:
    ///Konstruktor
    Kenu(const String nev = "", size_t tagok = 0, String edzo1 = "", String edzo2 = ""): Csapat(nev, tagok), edzo1(edzo1), edzo2(edzo2){/*edzok[0] = edzo1; edzok[1] = edzo2;*/}

    /// Getterek
    const String& get_edzo1()const{return edzo1;}

    const String& get_edzo2()const{return edzo2;}

    /// Setterek
    void set_edzok(String edzo1 = "", String edzo2 = ""){this->edzo1 = edzo1; this->edzo2 = edzo2;}

    /// Kiir
    /// Kenu osztály kiir metódusa
    /// @param os - output stream, ide irjuk ki a Kenu csapat adatait
    void kiir(std::ostream& os) const;

    /// Kenu osztály filba mentese
    /// @param fout - ofstream típusú fajlstream, ahova kiirjuk az osztaly adatait es egy szamot ami alapjan
    /// a taroloban beolvasaskor tudni fogjuk milyen osztalyrol van szo
    void iras(std::ofstream& fout);

    /// Kenu osztály filebol beolvasasa
    /// @param fin - ifstream típusú fajlstream, ahova be olvassuk a filban levo adatokat
    void olvasas(std::ifstream& fin);

    /// Destruktor
    ~Kenu() {}
};


#endif

