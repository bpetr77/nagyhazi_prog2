#ifndef VEZERLES_H_INCLUDED
#define VEZERLES_H_INCLUDED

#include "string.h"
#include "tarolo.h"
#include "egyesulet.h"
#include "memtrace.h"

/// Menu kiirasa
void Menu_kiir();

/// Letre hoz egy Kenu objektumot
/// @param tarolo - ebbe a taroloba teszi bele a letrehozott objektumot
/// felhasznalo alltal megadott adatokkal tolti meg a Kenu alosztalyt, es beleteszi a taroloba
void Kenu_letrehoz(Tarolo& tarolo);

/// Letre hoz egy Foci objektumot
/// @param tarolo - ebbe a taroloba teszi bele a letrehozott objektumot
/// felhasznalo alltal megadott adatokkal tolti meg a Kajak alosztalyt, es beleteszi a taroloba
void Foci_letrehoz(Tarolo& tarolo);

/// Letre hoz egy Kajak objektumot
/// @param tarolo - ebbe a taroloba teszi bele a letrehozott objektumot
/// felhasznalo alltal megadott adatokkal tolti meg a Kajak alosztalyt, es beleteszi a taroloba
void Kajak_letrehoz(Tarolo& tarolo);

/// Listazza a tarolo tartalmat
/// @param tarolo - ennek az elemeit listazza a Tarolo osztaly megfelelo fuggvenyet meghivva
void Csapatok_listaz(const Tarolo& tarolo);

/// Egy csapatot torol
/// @param tarolo - ennek az elemei kozul torol egyet nev alapjan a megfelelo fuggvenyt hasznalva
void Csapat_torol(Tarolo& tarolo);

/// Console "torlesre" szolgalo alternativ megoldas amit a
/// https://stackoverflow.com/questions/6486289/how-can-i-clear-console - oldalon talaltam
void clear_console();

/// Egy tarolo teljes tartalmat menti ki fileba
/// @param tarolo - a tarolo teljes tartalmat kimenti filba filenev alapjan a megfelelo fuggvennyel
void fajlba_ment(Tarolo& tarolo);

/// Egy filebol beolvassa az ottani adatokat a taroloba
/// @param tarolo - a tarolo amibe filbol filenev alapjan a megfelelo fuggvennyel beleteszi az adatokat
void fajlbol_olvas(Tarolo& tarolo);

#endif
