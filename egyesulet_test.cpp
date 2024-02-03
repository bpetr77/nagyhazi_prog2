#include <iostream>
#include <sstream>
#include <cstring>
#include <fstream>
#include "egyesulet.h"
#include "string.h"
#include "gtest_lite.h"
#include "tarolo.h"
#include "memtrace.h"

using namespace std;
#define ELKESZULT 3

void test(){
    #if ELKESZULT >= 1
    TEST(FociTest1, defctor){
        Foci f;
        EXPECT_STREQ("",f.get_nev().c_str());
        EXPECT_EQ(0 , f.get_tagok_szama());
        EXPECT_EQ(0 , f.get_labdak());
    }END

    TEST(FociTest2, ctor){
        Foci f2("ksi", 32, 10);
        EXPECT_STREQ("ksi", f2.get_nev().c_str());
        EXPECT_EQ(32 , f2.get_tagok_szama());
        EXPECT_EQ(10 , f2.get_labdak());
    }END

    TEST(FociTest3, ctor1){
        Foci f2("ksi");
        EXPECT_STREQ("ksi", f2.get_nev().c_str());
        EXPECT_EQ(0 , f2.get_tagok_szama());
        EXPECT_EQ(0 , f2.get_labdak());
    }END

    TEST(FociTest4, ctor2){
        Foci f2("ksi", 32);
        EXPECT_STREQ("ksi", f2.get_nev().c_str());
        EXPECT_EQ(32 , f2.get_tagok_szama());
        EXPECT_EQ(0 , f2.get_labdak());
    }END

    TEST(FociTest5, masoloctor){
        Foci f2("ksi", 32, 10);
        Foci f3(f2);
        EXPECT_STREQ(f3.get_nev().c_str(), f2.get_nev().c_str());
        EXPECT_EQ(f3.get_tagok_szama() , f2.get_tagok_szama());
        EXPECT_EQ(f3.get_labdak() , f2.get_labdak());
    }END

    TEST(FociTest6, get_set_test){
        Foci f;
        f.set_nev("ksi");
        EXPECT_STREQ("ksi",f.get_nev().c_str());
        EXPECT_EQ(0 , f.get_tagok_szama());
        EXPECT_EQ(0 , f.get_labdak());
    }END

    TEST(FociTest7, get_set_test1){
        Foci f;
        f.set_tagok_szama(32);
        EXPECT_STREQ("",f.get_nev().c_str());
        EXPECT_EQ(32 , f.get_tagok_szama());
        EXPECT_EQ(0 , f.get_labdak());
    }END

    TEST(FociTest8, get_set_test2){
        Foci f;
        f.set_labdak(10);
        EXPECT_STREQ("",f.get_nev().c_str());
        EXPECT_EQ(0 , f.get_tagok_szama());
        EXPECT_EQ(10 , f.get_labdak());
    }END

    TEST(FociTest9, kiir_test){
        Foci f("ksi", 11, 10);
        std::stringstream expected_output;
        expected_output << "A Foci csapat: " << std::endl;
        expected_output << "Nev: ksi" << std::endl;
        expected_output << "Tagok szama: 11" << std::endl;
        expected_output << "Labdak szama: 10" << std::endl;
        std::stringstream output;
        f.kiir(output);
        EXPECT_EQ(expected_output.str(), output.str());
    }END

    /*TEST(FociTest10, iras_olvasas_test) {
        Foci f("ksi", 31, 10);
        const char* file = "kajak_adatok.txt";
        f.iras(file);
        std::ifstream fin(file);
        String nev;
        f.olvasas(file);
        fin.close();

        EXPECT_STREQ("ksi", f.get_nev().c_str());
        EXPECT_EQ(31, f.get_tagok_szama());
        EXPECT_EQ(10, f.get_labdak());

        std::remove(file);
    }END */

    #endif //ELKESZULT

//--------------------------------------------------------------------------------------------------------

    #if ELKESZULT >= 2
    TEST(KajakTest1, defctor){
        Kajak k;
        EXPECT_STREQ("",k.get_nev().c_str());
        EXPECT_EQ(0 , k.get_tagok_szama());
        EXPECT_EQ(0 , k.get_tamogatas());
    }END

    TEST(KajakTest2, ctor){
        Kajak k2("ksi", 32, 20000);
        EXPECT_STREQ("ksi", k2.get_nev().c_str());
        EXPECT_EQ(32 , k2.get_tagok_szama());
        EXPECT_EQ(20000 , k2.get_tamogatas());
    }END

    TEST(KajakTest3, ctor1){
        Kajak k2("ksi");
        EXPECT_STREQ("ksi", k2.get_nev().c_str());
        EXPECT_EQ(0 , k2.get_tagok_szama());
        EXPECT_EQ(0 , k2.get_tamogatas());
    }END

    TEST(KajakTest4, ctor2){
        Kajak k2("ksi", 32);
        EXPECT_STREQ("ksi", k2.get_nev().c_str());
       EXPECT_EQ(32 , k2.get_tagok_szama());
        EXPECT_EQ(0 , k2.get_tamogatas());
    }END

    TEST(KajakTest5, masoloctor){
        Kajak k2("ksi", 32, 10);
        Kajak k3(k2);
        EXPECT_STREQ(k3.get_nev().c_str(), k2.get_nev().c_str());
        EXPECT_EQ(k3.get_tagok_szama() , k2.get_tagok_szama());
        EXPECT_EQ(k3.get_tamogatas() , k2.get_tamogatas());
    }END

    TEST(KajakTest6, get_set_test){
        Kajak k;
        k.set_nev("ksi");
        EXPECT_STREQ("ksi", k.get_nev().c_str());
        EXPECT_EQ(0 , k.get_tagok_szama());
        EXPECT_EQ(0 , k.get_tamogatas());
    }END

    TEST(KajakTest7, get_set_test1){
        Kajak k;
        k.set_tagok_szama(32);
        EXPECT_STREQ("",k.get_nev().c_str());
        EXPECT_EQ(32 , k.get_tagok_szama());
        EXPECT_EQ(0 , k.get_tamogatas());
    }END

    TEST(KajakTest8, get_set_test2){
        Kajak k;
        k.set_tamogatas(1000);
        EXPECT_STREQ("",k.get_nev().c_str());
        EXPECT_EQ(0 , k.get_tagok_szama());
        EXPECT_EQ(1000 , k.get_tamogatas());
    }END

    TEST(KajakTest9, kiir_test){
        Kajak k("ksi", 32, 1220);
        std::stringstream expected_output;
        expected_output << "A Kajak csapat: " << std::endl;
        expected_output << "Nev: ksi" << std::endl;
        expected_output << "Tagok szama: 32" << std::endl;
        expected_output << "Tamogatas merteke: 1220" << std::endl;
        std::stringstream output;
        k.kiir(output);
        EXPECT_EQ(expected_output.str(), output.str());
    }END

    /*TEST(KajakTest10, iras_olvasas_test) {
        Kajak k("ksi", 331, 3310);
        const char* file = "kajak_adatok.txt";
        k.iras(file);
        std::ifstream fin(file);
        k.olvasas(file);
        fin.close();

        EXPECT_STREQ("ksi", k.get_nev().c_str());
        EXPECT_EQ(331, k.get_tagok_szama());
        EXPECT_EQ(3310, k.get_tamogatas());

        std::remove(file);
   }END */

   #endif //ELKESZULT

//--------------------------------------------------------------------------------------------------------

    #if ELKESZULT >= 3

    TEST(KenuTest1, defctor){
        Kenu k;
        EXPECT_STREQ("",k.get_nev().c_str());
        EXPECT_EQ(0 , k.get_tagok_szama());
        EXPECT_STREQ("",k.get_edzo1().c_str());
        EXPECT_STREQ("",k.get_edzo2().c_str());
    }END

    TEST(KenuTest2, ctor){
        Kenu k2("ksi", 32, "Laci", "Misi");
        EXPECT_STREQ("ksi", k2.get_nev().c_str());
        EXPECT_EQ(32 , k2.get_tagok_szama());
        EXPECT_STREQ("Laci",k2.get_edzo1().c_str());
        EXPECT_STREQ("Misi",k2.get_edzo2().c_str());
    }END

    TEST(KenuTest3, ctor1){
        Kenu k2("ksi");
        EXPECT_STREQ("ksi", k2.get_nev().c_str());
        EXPECT_EQ(0 , k2.get_tagok_szama());
        EXPECT_STREQ("",k2.get_edzo1().c_str());
        EXPECT_STREQ("",k2.get_edzo2().c_str());
    }END

    TEST(KenuTest4, ctor2){
        Kenu k2("ksi", 185);
        EXPECT_STREQ("ksi", k2.get_nev().c_str());
        EXPECT_EQ(185 , k2.get_tagok_szama());
        EXPECT_STREQ("",k2.get_edzo1().c_str());
        EXPECT_STREQ("",k2.get_edzo2().c_str());
    }END
    TEST(KenuTest5, ctor3){
        Kenu k2("ksi", 5555, "Laci");
        EXPECT_STREQ("ksi", k2.get_nev().c_str());
        EXPECT_EQ(5555 , k2.get_tagok_szama());
        EXPECT_STREQ("Laci",k2.get_edzo1().c_str());
        EXPECT_STREQ("",k2.get_edzo2().c_str());
    }END

    TEST(KenuTest6, masoloctor){
        Kenu k2("ksi", 331, "Laci", "Misi");
        Kenu k3(k2);
        EXPECT_STREQ(k3.get_nev().c_str(), k2.get_nev().c_str());
        EXPECT_EQ(331 , k2.get_tagok_szama());
        EXPECT_STREQ(k3.get_edzo1().c_str() , k2.get_edzo1().c_str());
        EXPECT_STREQ(k3.get_edzo2().c_str() , k2.get_edzo2().c_str());
    }END

    TEST(KenuTest7, get_set_test){
        Kenu k;
        k.set_nev("ksi");
        EXPECT_STREQ("ksi", k.get_nev().c_str());
        EXPECT_EQ(0 , k.get_tagok_szama());
        EXPECT_STREQ("",k.get_edzo1().c_str());
        EXPECT_STREQ("",k.get_edzo2().c_str());
    }END

    TEST(KenuTest8, get_set_test1){
        Kenu k;
        k.set_tagok_szama(3332);
        EXPECT_STREQ("",k.get_nev().c_str());
        EXPECT_EQ(3332 , k.get_tagok_szama());
        EXPECT_STREQ("",k.get_edzo1().c_str());
        EXPECT_STREQ("",k.get_edzo2().c_str());
    }END

    TEST(KenuTest9, get_set_test2){
        Kenu k;
        k.set_edzok("Laci");
        EXPECT_STREQ("",k.get_nev().c_str());
        EXPECT_EQ(0 , k.get_tagok_szama());
        EXPECT_STREQ("Laci", k.get_edzo1().c_str());
        EXPECT_STREQ("", k.get_edzo2().c_str());
    }END

    TEST(KenuTest10, get_set_test3){
        Kenu k;
        k.set_edzok("Laci", "Matya");
        EXPECT_STREQ("",k.get_nev().c_str());
        EXPECT_EQ(0 , k.get_tagok_szama());
        EXPECT_STREQ("Laci", k.get_edzo1().c_str());
        EXPECT_STREQ("Matya", k.get_edzo2().c_str());
    }END

    TEST(KenuTest11, kiir_test){
        Kenu k("ksi", 9732, "Laci", "Matya");
        std::stringstream expected_output;
        expected_output << "A Kenu csapat: " << std::endl;
        expected_output << "Nev: ksi" << std::endl;
        expected_output << "Tagok szama: 9732" << std::endl;
        expected_output << "Edzok: Laci, Matya" << std::endl;
        std::stringstream output;
        k.kiir(output);
        EXPECT_EQ(expected_output.str(), output.str());
    }END

    /*TEST(KenuTest12, iras_olvasas_test) {
        Kenu k("ksi", 331, "Laci", "Matya");
        const char* file = "kajak_adatok.txt";
        k.iras(file);
        std::ifstream fin(file);
        k.olvasas(file);
        fin.close();

        EXPECT_STREQ("ksi", k.get_nev().c_str());
        EXPECT_EQ(331, k.get_tagok_szama());
        EXPECT_STREQ("Laci", k.get_edzo1().c_str());
        EXPECT_STREQ("Matya", k.get_edzo2().c_str());

        std::remove(file);
   }END */

//--------------------------------------------------------------------------------------------------------

   TEST(TaroloTest1, hozzaad_torol) {
        Tarolo tarolo;
        EXPECT_EQ(0, tarolo.get_meret());

        Kajak* kajak = new Kajak("kajak", 10);
        tarolo.hozza_ad(kajak);
        EXPECT_EQ(1, tarolo.get_meret());

        Kenu* kenu = new Kenu("kenu");
        tarolo.hozza_ad(kenu);
        EXPECT_EQ(2, tarolo.get_meret());

        tarolo.tarolo_torles();
        EXPECT_EQ(0, tarolo.get_meret());
    }END

    TEST(TaroloTest2, vegyestestek) {
        Tarolo tarolo;
        const char* file = "csapatok.txt";
        Kajak* kajak = new Kajak("kajak", 10, 50000);
        tarolo.hozza_ad(kajak);
        Kenu* kenu = new Kenu("kenu", 5, "Tamas", "Konrad");
        tarolo.hozza_ad(kenu);
        Tarolo ujTarolo;

        tarolo.tarolo_fileba_iras(file);
        ujTarolo.olvasas(file);

        EXPECT_EQ(2, ujTarolo.get_meret());

        Csapat* csapat1 = ujTarolo.get_csapat(0);
        Csapat* csapat2 = ujTarolo.get_csapat(1);

        EXPECT_STREQ("kajak", csapat1->get_nev().c_str());
        EXPECT_STREQ("kenu", csapat2->get_nev().c_str());
        EXPECT_EQ(10, csapat1->get_tagok_szama());
        EXPECT_EQ(5, csapat2->get_tagok_szama());
        EXPECT_EQ(50000, dynamic_cast<Kajak*>(csapat1)->get_tamogatas());
        EXPECT_STREQ("Tamas", dynamic_cast<Kenu*>(csapat2)->get_edzo1().c_str());
        EXPECT_STREQ("Konrad", dynamic_cast<Kenu*>(csapat2)->get_edzo2().c_str());

        std::remove(file);
    }END

    TEST(TaroloTest3, vegyestestek2){
        Tarolo tarolo;
        Kajak* kajak = new Kajak("KSI kajak", 30, 40000);
        tarolo.hozza_ad(kajak);
        Kenu* kenu = new Kenu("KSI kenu", 17, "Tamas", "Konrad");
        tarolo.hozza_ad(kenu);
        Foci* foci = new Foci("NLG allstars", 11, 2);
        tarolo.hozza_ad(foci);
        std::stringstream expected_output;
        expected_output << "A Kajak csapat: " << std::endl;
        expected_output << "Nev: KSI kajak" << std::endl;
        expected_output << "Tagok szama: 30" << std::endl;
        expected_output << "Tamogatas merteke: 40000" << std::endl;

        expected_output << "A Kenu csapat: " << std::endl;
        expected_output << "Nev: KSI kenu" << std::endl;
        expected_output << "Tagok szama: 17" << std::endl;
        expected_output << "Edzok: Tamas, Konrad" << std::endl;

        expected_output << "A Foci csapat: " << std::endl;
        expected_output << "Nev: NLG allstars" << std::endl;
        expected_output << "Tagok szama: 11" << std::endl;
        expected_output << "Labdak szama: 2" << std::endl;
        std::stringstream output;
        tarolo.tarolo_kiir(output);
        EXPECT_EQ(expected_output.str(), output.str());

    }END
}
    #endif // ELKESZULT
