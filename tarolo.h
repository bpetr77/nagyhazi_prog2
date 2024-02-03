#ifndef TAROLO_H_INCLUDED
#define TAROLO_H_INCLUDED

#include <iostream>
#include <fstream>
#include "egyesulet.h"
#include "string.h"
#include "memtrace.h"

class Tarolo {
private:
    Csapat** csapatok;
    size_t meret;
    size_t kapacitas;
public:
    /// Tarolo osztály konstruktora
    /// @param kezdeti_kapacitas - kezdeti tarolo kapacitasa (alapertelmezetten 10)
    /// a meretet alapertelmezetten 0-ra allitja illetve foglal a kapacitasnak megfelelo meretu helyet
    /// a tarolonak
    Tarolo(size_t kezdeti_kapacitas = 10) : meret(0), kapacitas(kezdeti_kapacitas) {
        csapatok = new Csapat*[kapacitas];
    }

    /// Csapat hozzáadása a tárolóhoz
    /// @param cs - hozzáadandó csapat pointer
    /// ha a meret megegyezik a kapacitassal akkor az egyenkenti hely foglalast elkerulve
    /// a (kapacitas * 2) helyet foglal a tarolonak
    void hozza_ad(Csapat* cs);

    ///Getter
    size_t get_meret() const {return meret;}

    /// Tároló tartalmának kiírása
    /// @param os - kimeneti stream referencia
    /// Ha az elem nem üres, meghívja annak a kiir metódusát, amely az adott csapat
    /// adatait írja ki a megadott kimeneti streamre. Ezáltal minden csapat adatai kiíródnak
    void tarolo_kiir(std::ostream& os) const;

    /// Tároló tartalmának kiírása fileba
    /// @param filenev - file neve ahova a kiiras tortenik
    /// Ha sikerült megnyitni a fájlt, a függvény végigmegy a tárolóban található csapatokon egy ciklus segítségével.
    /// Minden iterációban meghívja az adott csapat, fileba iras metódusát
    /// Ezáltal az adott csapat adatai kiíródnak a fájlba
    void tarolo_fileba_iras(const String& filenev);

    /// Tároló tartalmának beolvasasa egy filebol
    /// @param filenev - file neve ahonnan a beolvasas tortenik
    /// Ha sikerult megnyitni a file-t akkor egy ciklus segitsegevel folyamatosan beolvassa
    /// a filban levo objektumokat, es eldonti a beiraskor bekerult szam alapjan hogy,
    /// melyik alosztaly fog kovetkezni
    void olvasas(const String& filenev);

    /// Csapat torlese a tarolobol nev alapjan
    /// @param nev - ez alapjan valasztjuk ki a csapatot ami torlesre fog kerulni
    /// A fuggveny vegigiteral a csapatokon, és ha megtalalja a megadott nevvel
    /// rendelkezo csapatot, akkor torli azt a tarolobol.
    /// A torlés soran a csapat dinamikusan foglalt memoriateruletet felszabaditja,
    /// majd a tobbi csapatot balra tolja a tombben, hogy ne legyen res a torolt csapat utan.
    /// Vegul a tarolo meretet csokkenti.
    void elem_torles(const String& nev);

    /// A tarolo teljes tartalmat torli, es felszabditja
    void tarolo_torles();

    /// Getter
    /// @param idx - a tomb idx-edik elemet adjuk vissza
    /// Ha az index érvényes, akkor visszaadja az adott indexen lévõ csapatot a csapatok tömbbõl.
    Csapat* get_csapat(size_t idx) const {
        if(idx < meret){
                return csapatok[idx];
        }
        throw "tul nagy vagy tul kicsi az index";
    }
    /// Destruktor, ami felszabaditja az osszes dinamikusan foglalat memoriat
    ~Tarolo() {
        for (size_t i = 0; i < meret; i++) {
            delete csapatok[i];
        }
        delete[] csapatok;
    }
};

#endif
