#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int saldiri;
    int savunma;
    int saglik;
    int kritik_sans;
    int sayi;
    int vurus_sayisi;
} Unit;

typedef struct {
    Unit piyadeler;
    Unit okcular;
    Unit suvariler;
    Unit kusatma_makineleri;
} Human_Unit;

typedef struct {
    Unit ork_dovusculeri;
    Unit mizrakcilar;
    Unit varg_binicileri;
    Unit troller;
} Ork_Unit;

typedef struct {
    char bonus_turu[50];
    char aciklama[256];
    int bonus_degeri;
    int sayi;
} Hero;

typedef struct {
    Hero alparslan;
    Hero fsm;
    Hero metehan;
    Hero yss;
    Hero tugrul_bey;
} Human_Hero;

typedef struct {
    Hero goruk;
    Hero thruk;
    Hero vrog;
    Hero ugar;
} Ork_Hero;

typedef struct {
    int etki_degeri;
    char etki_turu[50];
    char aciklama[256];
    int sayi;
} Creature;

typedef struct {
    Creature ejderha;
    Creature agri_dagi;
    Creature tepegoz;
    Creature karakurt;
    Creature samur;
} Human_Creature;

typedef struct {
    Creature troll;
    Creature golge;
    Creature camur;
    Creature ates_iblisi;
    Creature makrog;
    Creature buz_devi;
} Ork_Creature;

typedef struct {
    int deger;
    char aciklama[100];
    int sayi;
} Seviye;

typedef struct {
    Seviye seviye_1;
    Seviye seviye_2;
    Seviye seviye_3;
} Research_Type;

typedef struct {
    Research_Type savunma_ustaligi;
    Research_Type saldiri_gelistirmesi;
    Research_Type elit_egitim;
    Research_Type kusatma_ustaligi;
} Research;

Human_Unit HU;
Ork_Unit OU;
Human_Hero HH;
Ork_Hero OH;
Human_Creature HC;
Ork_Creature OC;
Research_Type RT;
Research HR;
Research OR;

void parse_creature_json(const char *filename, Human_Creature *HC, Ork_Creature *OC)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Dosya Acilamadi: %s\n", filename);
        return;
    }

    char line[256];
    char etki_str[10];
    while (fgets(line, sizeof(line), file))
    {
        if (strstr(line, "\"Ejderha\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etki_degeri\" : \"%[^\"]\",", etki_str);
            HC->ejderha.etki_degeri = atoi(etki_str);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etki_turu\" : \"%[^\"]\",", &HC->ejderha.etki_turu);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"aciklama\" : \"%[^\"]\",", &HC->ejderha.aciklama);
            
        }
        if (strstr(line, "\"Agri_Dagi_Devleri\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etki_degeri\" : \"%[^\"]\",", etki_str);
            HC->agri_dagi.etki_degeri = atoi(etki_str);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etki_turu\" : \"%[^\"]\",", &HC->agri_dagi.etki_turu);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"aciklama\" : \"%[^\"]\",", &HC->agri_dagi.aciklama);
            
        }
        if (strstr(line, "\"Tepegoz\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etki_degeri\" : \"%[^\"]\",", etki_str);
            HC->tepegoz.etki_degeri = atoi(etki_str);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etki_turu\" : \"%[^\"]\",", &HC->tepegoz.etki_turu);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"aciklama\" : \"%[^\"]\",", &HC->tepegoz.aciklama);
            ;
        }
        if (strstr(line, "\"Karakurt\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etki_degeri\" : \"%[^\"]\",", etki_str);
            HC->karakurt.etki_degeri = atoi(etki_str);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etki_turu\" : \"%[^\"]\",", &HC->karakurt.etki_turu);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"aciklama\" : \"%[^\"]\",", &HC->karakurt.aciklama);
            
        }
        if (strstr(line, "\"Samur\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etki_degeri\" : \"%[^\"]\",", etki_str);
            HC->samur.etki_degeri = atoi(etki_str);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etki_turu\" : \"%[^\"]\",", &HC->samur.etki_turu);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"aciklama\" : \"%[^\"]\",", &HC->samur.aciklama);
            
        }
        if (strstr(line, "\"Kara_Troll\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etki_degeri\" : \"%[^\"]\",", etki_str);
            OC->troll.etki_degeri = atoi(etki_str);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etki_turu\" : \"%[^\"]\",", &OC->troll.etki_turu);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"aciklama\" : \"%[^\"]\",", &OC->troll.aciklama);
            
        }
        if (strstr(line, "\"Golge_Kurtlari\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etki_degeri\" : \"%[^\"]\",", etki_str);
            OC->golge.etki_degeri = atoi(etki_str);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etki_turu\" : \"%[^\"]\",", &OC->golge.etki_turu);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"aciklama\" : \"%[^\"]\",", &OC->golge.aciklama);
            
        }
        if (strstr(line, "\"Camur_Devleri\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etki_degeri\" : \"%[^\"]\",", etki_str);
            OC->camur.etki_degeri = atoi(etki_str);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etki_turu\" : \"%[^\"]\",", &OC->camur.etki_turu);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"aciklama\" : \"%[^\"]\",", &OC->camur.aciklama);
            
        }
        if (strstr(line, "\"Ates_Iblisi\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etki_degeri\" : \"%[^\"]\",", etki_str);
            OC->ates_iblisi.etki_degeri = atoi(etki_str);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etki_turu\" : \"%[^\"]\",", &OC->ates_iblisi.etki_turu);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"aciklama\" : \"%[^\"]\",", &OC->ates_iblisi.aciklama);
            
        }
        if (strstr(line, "\"Makrog_Savas_Beyi\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etki_degeri\" : \"%[^\"]\",", etki_str);
            OC->makrog.etki_degeri = atoi(etki_str);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etki_turu\" : \"%[^\"]\",", &OC->makrog.etki_turu);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"aciklama\" : \"%[^\"]\",", &OC->makrog.etki_turu);
            
        }
        if (strstr(line, "\"Buz_Devleri\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etki_degeri\" : \"%[^\"]\",", etki_str);
            OC->buz_devi.etki_degeri = atoi(etki_str);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"etki_turu\" : \"%[^\"]\",", &OC->buz_devi.etki_turu);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"aciklama\" : \"%[^\"]\",", &OC->buz_devi.aciklama);
            
        }
    }    
    fclose(file);
}

void yazdir_human_unit(Human_Unit *hu) {
    printf("Piyadeler - saldiri: %d, Savunma: %d, saglik: %d, Kritik Sans: %d, Sayi: %d\n", 
            hu->piyadeler.saldiri, hu->piyadeler.savunma, hu->piyadeler.saglik, hu->piyadeler.kritik_sans, hu->piyadeler.sayi);
    printf("Okcular - saldiri: %d, Savunma: %d, saglik: %d, Kritik Sans: %d, Sayi: %d\n", 
            hu->okcular.saldiri, hu->okcular.savunma, hu->okcular.saglik, hu->okcular.kritik_sans, hu->okcular.sayi);
    printf("Suvariler - saldiri: %d, Savunma: %d, saglik: %d, Kritik Sans: %d, Sayi: %d\n", 
            hu->suvariler.saldiri, hu->suvariler.savunma, hu->suvariler.saglik, hu->suvariler.kritik_sans, hu->suvariler.sayi);
    printf("Kusatma Makineleri - saldiri: %d, Savunma: %d, saglik: %d, Kritik Sans: %d, Sayi: %d\n", 
            hu->kusatma_makineleri.saldiri, hu->kusatma_makineleri.savunma, hu->kusatma_makineleri.saglik, hu->kusatma_makineleri.kritik_sans, hu->kusatma_makineleri.sayi);
}

void yazdir_ork_unit(Ork_Unit *ou) {
    printf("Ork Dovusculeri - saldiri: %d, Savunma: %d, saglik: %d, Kritik Sans: %d, Sayi: %d\n", 
            ou->ork_dovusculeri.saldiri, ou->ork_dovusculeri.savunma, ou->ork_dovusculeri.saglik, ou->ork_dovusculeri.kritik_sans, ou->ork_dovusculeri.sayi);
    printf("Mizrakcilar - saldiri: %d, Savunma: %d, saglik: %d, Kritik Sans: %d, Sayi: %d\n", 
            ou->mizrakcilar.saldiri, ou->mizrakcilar.savunma, ou->mizrakcilar.saglik, ou->mizrakcilar.kritik_sans, ou->mizrakcilar.sayi);
    printf("Varg Binicileri - saldiri: %d, Savunma: %d, saglik: %d, Kritik Sans: %d, Sayi: %d\n", 
            ou->varg_binicileri.saldiri, ou->varg_binicileri.savunma, ou->varg_binicileri.saglik, ou->varg_binicileri.kritik_sans, ou->varg_binicileri.sayi);
    printf("Troller - saldiri: %d, Savunma: %d, saglik: %d, Kritik Sans: %d, Sayi: %d\n", 
            ou->troller.saldiri, ou->troller.savunma, ou->troller.saglik, ou->troller.kritik_sans, ou->troller.sayi);
}

void yazdir_hero(Hero *hero) {
    printf("Bonus Türü: %s, Aciklama: %s, Bonus Değeri: %d, Sayı: %d\n", 
            hero->bonus_turu, hero->aciklama, hero->bonus_degeri, hero->sayi);
}

void yazdir_human_hero(Human_Hero *hh) {
    printf("Alparslan:\n");
    yazdir_hero(&hh->alparslan);
    printf("FSM:\n");
    yazdir_hero(&hh->fsm);
    printf("Metehan:\n");
    yazdir_hero(&hh->metehan);
    printf("YSS:\n");
    yazdir_hero(&hh->yss);
    printf("Tugrul Bey:\n");
    yazdir_hero(&hh->tugrul_bey);
}

void yazdir_ork_hero(Ork_Hero *oh) {
    printf("Goruk:\n");
    yazdir_hero(&oh->goruk);
    printf("Thruk:\n");
    yazdir_hero(&oh->thruk);
    printf("Vrog:\n");
    yazdir_hero(&oh->vrog);
    printf("Ugar:\n");
    yazdir_hero(&oh->ugar);
}

void yazdir_creature(Creature *creature) {
    printf("Etki Degeri: %d, Etki Türü: %s, Aciklama: %s, Sayi: %d\n", 
            creature->etki_degeri, creature->etki_turu, creature->aciklama, creature->sayi);
}

void yazdir_human_creature(Human_Creature *hc) {
    printf("Ejderha:\n");
    yazdir_creature(&hc->ejderha);
    printf("Agri Dağı:\n");
    yazdir_creature(&hc->agri_dagi);
    printf("Tepegoz:\n");
    yazdir_creature(&hc->tepegoz);
    printf("Karakurt:\n");
    yazdir_creature(&hc->karakurt);
    printf("Samur:\n");
    yazdir_creature(&hc->samur);
}

void yazdir_ork_creature(Ork_Creature *oc) {
    printf("Troll:\n");
    yazdir_creature(&oc->troll);
    printf("Golge:\n");
    yazdir_creature(&oc->golge);
    printf("Camur:\n");
    yazdir_creature(&oc->camur);
    printf("Ates Iblisi:\n");
    yazdir_creature(&oc->ates_iblisi);
    printf("Makrog:\n");
    yazdir_creature(&oc->makrog);
    printf("Buz Devi:\n");
    yazdir_creature(&oc->buz_devi);
}

void yazdir_seviye(Seviye *seviye) {
    printf("Deger: %d, Aciklama: %s, Sayi: %d\n", seviye->deger, seviye->aciklama, seviye->sayi);
}

void yazdir_human_research(Research *HR) {
    printf("Insan Arastirma: \n");
    printf("Savunma Ustaligi Seviye 1:\n");
    yazdir_seviye(&HR->savunma_ustaligi.seviye_1);
    printf("Savunma Ustaligi Seviye 2:\n");
    yazdir_seviye(&HR->savunma_ustaligi.seviye_2);
    printf("Savunma Ustaligi Seviye 3:\n");
    yazdir_seviye(&HR->savunma_ustaligi.seviye_3);
    
    printf("Saldiri Geliştirmesi Seviye 1:\n");
    yazdir_seviye(&HR->saldiri_gelistirmesi.seviye_1);
    printf("Saldiri Geliştirmesi Seviye 2:\n");
    yazdir_seviye(&HR->saldiri_gelistirmesi.seviye_2);
    printf("Saldiri Geliştirmesi Seviye 3:\n");
    yazdir_seviye(&HR->saldiri_gelistirmesi.seviye_3);

    printf("Elit Eğitim Seviye 1:\n");
    yazdir_seviye(&HR->elit_egitim.seviye_1);
    printf("Elit Eğitim Seviye 2:\n");
    yazdir_seviye(&HR->elit_egitim.seviye_2);
    printf("Elit Eğitim Seviye 3:\n");
    yazdir_seviye(&HR->elit_egitim.seviye_3);

    printf("Kusatma Ustaligi Seviye 1:\n");
    yazdir_seviye(&HR->kusatma_ustaligi.seviye_1);
    printf("Kusatma Ustaligi Seviye 2:\n");
    yazdir_seviye(&HR->kusatma_ustaligi.seviye_2);
    printf("Kusatma Ustaligi Seviye 3:\n");
    yazdir_seviye(&HR->kusatma_ustaligi.seviye_3);
}

void yazdir_ork_research(Research *OR) {
    printf("Ork Arastirma: \n");
    printf("Savunma Ustaligi Seviye 1:\n");
    yazdir_seviye(&OR->savunma_ustaligi.seviye_1);
    printf("Savunma Ustaligi Seviye 2:\n");
    yazdir_seviye(&OR->savunma_ustaligi.seviye_2);
    printf("Savunma Ustaligi Seviye 3:\n");
    yazdir_seviye(&OR->savunma_ustaligi.seviye_3);
    
    printf("Saldiri Geliştirmesi Seviye 1:\n");
    yazdir_seviye(&OR->saldiri_gelistirmesi.seviye_1);
    printf("Saldiri Geliştirmesi Seviye 2:\n");
    yazdir_seviye(&OR->saldiri_gelistirmesi.seviye_2);
    printf("Saldiri Geliştirmesi Seviye 3:\n");
    yazdir_seviye(&OR->saldiri_gelistirmesi.seviye_3);

    printf("Elit Eğitim Seviye 1:\n");
    yazdir_seviye(&OR->elit_egitim.seviye_1);
    printf("Elit Eğitim Seviye 2:\n");
    yazdir_seviye(&OR->elit_egitim.seviye_2);
    printf("Elit Eğitim Seviye 3:\n");
    yazdir_seviye(&OR->elit_egitim.seviye_3);

    printf("Kusatma Ustaligi Seviye 1:\n");
    yazdir_seviye(&OR->kusatma_ustaligi.seviye_1);
    printf("Kusatma Ustaligi Seviye 2:\n");
    yazdir_seviye(&OR->kusatma_ustaligi.seviye_2);
    printf("Kusatma Ustaligi Seviye 3:\n");
    yazdir_seviye(&OR->kusatma_ustaligi.seviye_3);
}

void parse_hero_json(const char *filename, Human_Hero *HH, Ork_Hero *OH)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Dosya Acilamadi: %s\n", filename);
        return;
    }

    char line[256];
    char bonus_str[10];
    while (fgets(line, sizeof(line), file))
    {
        if (strstr(line, "\"Alparslan\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"bonus_turu\" : \"%[^\"]\",", &HH->alparslan.bonus_turu);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"bonus_degeri\" : \"%[^\"]\",", bonus_str);
            HH->alparslan.bonus_degeri = atoi(bonus_str);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"aciklama\" : \"%[^\"]\",", &HH->alparslan.aciklama);
            
        }
        if (strstr(line, "\"Fatih_Sultan_Mehmet\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"bonus_turu\" : \"%[^\"]\",", &HH->fsm.bonus_turu);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"bonus_degeri\" : \"%[^\"]\",", bonus_str);
            HH->fsm.bonus_degeri = atoi(bonus_str);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"aciklama\" : \"%[^\"]\",", &HH->fsm.aciklama);
            
        }
        if (strstr(line, "\"Mete_Han\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"bonus_turu\" : \"%[^\"]\",", &HH->metehan.bonus_turu);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"bonus_degeri\" : \"%[^\"]\",", bonus_str);
            HH->metehan.bonus_degeri = atoi(bonus_str);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"aciklama\" : \"%[^\"]\",", &HH->metehan.aciklama);
            
        }
        if (strstr(line, "\"Yavuz_Sultan_Selim\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"bonus_turu\" : \"%[^\"]\",", &HH->yss.bonus_turu);            
            fgets(line, sizeof(line), file);
            sscanf(line, " \"bonus_degeri\" : \"%[^\"]\",", bonus_str);
            HH->yss.bonus_degeri = atoi(bonus_str);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"aciklama\" : \"%[^\"]\",", &HH->yss.aciklama);
        }
        if (strstr(line, "\"Tugrul_Bey\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"bonus_turu\" : \"%[^\"]\",", &HH->tugrul_bey.bonus_turu);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"bonus_degeri\" : \"%[^\"]\",", bonus_str);
            HH->tugrul_bey.bonus_degeri = atoi(bonus_str);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"aciklama\" : \"%[^\"]\",", &HH->tugrul_bey.aciklama);
            
        }
        if (strstr(line, "\"Goruk_Vahsi\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"bonus_turu\" : \"%[^\"]\",", &OH->goruk.bonus_turu);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"bonus_degeri\" : \"%[^\"]\",", bonus_str);
            OH->goruk.bonus_degeri = atoi(bonus_str);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"aciklama\" : \"%[^\"]\",", &OH->goruk.aciklama);
            
        }
        if (strstr(line, "\"Thruk_Kemikkiran\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"bonus_turu\" : \"%[^\"]\",", &OH->thruk.bonus_turu);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"bonus_degeri\" : \"%[^\"]\",", bonus_str);
            OH->thruk.bonus_degeri = atoi(bonus_str);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"aciklama\" : \"%[^\"]\",", &OH->thruk.aciklama);
            
        }
        if (strstr(line, "\"Vrog_Kafakiran\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"bonus_turu\" : \"%[^\"]\",", &OH->vrog.bonus_turu);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"bonus_degeri\" : \"%[^\"]\",", bonus_str);
            OH->vrog.bonus_degeri = atoi(bonus_str);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"aciklama\" : \"%[^\"]\",", &OH->vrog.aciklama);
            
        }
        if (strstr(line, "\"Ugar_Zalim\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"bonus_turu\" : \"%[^\"]\",", &OH->ugar.bonus_turu);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"bonus_degeri\" : \"%[^\"]\",", bonus_str);
            OH->ugar.bonus_degeri = atoi(bonus_str);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"aciklama\" : \"%[^\"]\",", &OH->ugar.aciklama);
            
        }
    }    
    fclose(file);
}

void parse_research_json(const char *filename, Research *HR, Research *OR)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Dosya Acilamadi: %s\n", filename);
        return;
    }

    char line[256];
    Research_Type *current_research_type = NULL;
    Seviye *current_level = NULL;

    while (fgets(line, sizeof(line), file))
    {
        if (strstr(line, "\"savunma_ustaligi\""))
        {
            current_research_type = &HR->savunma_ustaligi;
        }
        else if (strstr(line, "\"saldiri_gelistirmesi\""))
        {
            current_research_type = &HR->saldiri_gelistirmesi;
        }
        else if (strstr(line, "\"elit_egitim\""))
        {
            current_research_type = &HR->elit_egitim;
        }
        else if (strstr(line, "\"kusatma_ustaligi\""))
        {
            current_research_type = &HR->kusatma_ustaligi;
        }
        else if (strstr(line, "\"deger\""))
        {
            if (current_level)
            {
                sscanf(line, " \"deger\": \"%d\"", &current_level->deger);
            }
        }
        else if (strstr(line, "\"aciklama\""))
        {
            if (current_level)
            {
                char *start = strchr(line, ':') + 3;
                strncpy(current_level->aciklama, start, strlen(start) - 2);
                current_level->aciklama[strlen(start) - 2] = '\0';
            }
        }
        else if (strstr(line, "\"seviye_1\""))
        {
            current_level = &current_research_type->seviye_1;
        }
        else if (strstr(line, "\"seviye_2\""))
        {
            current_level = &current_research_type->seviye_2;
        }
        else if (strstr(line, "\"seviye_3\""))
        {
            current_level = &current_research_type->seviye_3;
        }
    }

    fclose(file);

    memcpy(&OR->savunma_ustaligi, &HR->savunma_ustaligi, sizeof(Research_Type));
    memcpy(&OR->saldiri_gelistirmesi, &HR->saldiri_gelistirmesi, sizeof(Research_Type));
    memcpy(&OR->elit_egitim, &HR->elit_egitim, sizeof(Research_Type));
    memcpy(&OR->kusatma_ustaligi, &HR->kusatma_ustaligi, sizeof(Research_Type));
}

void read_human_scenario(const char *filename, Human_Unit *HU, Human_Hero *HH, Human_Creature *HC, Research *HR)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Dosya Acilamadi!\n");
        return;
    }
    char line[256];
    int value = 0;
    while (fgets(line, sizeof(line), file))
    {
        if (strstr(line, "\"insan_imparatorlugu\": {") != NULL)
        {
            while (fgets(line, sizeof(line), file) && !strstr(line, "ork_legi"))
            {
                if (strstr(line, "\"piyadeler\"") != NULL)
                {
                    sscanf(line, " \"piyadeler\": %d,", &HU->piyadeler.sayi);
                }
                if (strstr(line, "okcular") != NULL)
                {
                    sscanf(line, " \"okcular\": %d,", &HU->okcular.sayi);
                }
                if (strstr(line, "suvariler") != NULL)
                {
                    sscanf(line, " \"suvariler\": %d,", &HU->suvariler.sayi);
                }
                if (strstr(line, "kusatma_makineleri") != NULL)
                {
                    sscanf(line, " \"kusatma_makineleri\": %d,", &HU->kusatma_makineleri.sayi);
                }
                if (strstr(line, "\"Alparslan\"") != NULL)
                {
                    HH->alparslan.sayi = 1;
                }
                if (strstr(line, "\"Fatih_Sultan_Mehmet\"") != NULL)
                {
                    HH->fsm.sayi = 1;
                }
                if (strstr(line, "\"Yavuz_Sultan_Selim\"") != NULL)
                {
                    HH->yss.sayi = 1;
                }
                if (strstr(line, "\"Tugrul_Bey\"") != NULL)
                {
                    HH->tugrul_bey.sayi = 1;
                }
                if (strstr(line, "\"Ejderha\"") != NULL)
                {
                    HC->ejderha.sayi = 1;
                }
                if (strstr(line, "\"Agri_Dagi_Devleri\"") != NULL)
                {
                    HC->agri_dagi.sayi = 1;
                }
                if (strstr(line, "\"Tepegoz\"") != NULL)
                {
                    HC->tepegoz.sayi = 1;
                }
                if (strstr(line, "\"Karakurt\"") != NULL)
                {
                    HC->karakurt.sayi = 1;
                }
                if (strstr(line, "\"Samur\"") != NULL) 
                {
                    HC->samur.sayi = 1;
                }
                if (strstr(line, "\"savunma_ustaligi\"") != NULL)
                {
                    sscanf(line, " \"%*[^\"]\": %d", &value);
                    if (value == 1)
                    {
                        HR->savunma_ustaligi.seviye_1.sayi = 1;
                    }
                    else if (value == 2)
                    {
                        HR->savunma_ustaligi.seviye_2.sayi = 1;
                    }
                    else if (value == 3)
                    {
                        HR->savunma_ustaligi.seviye_3.sayi = 1;
                    }
                }
                if (strstr(line, "\"saldiri_gelistirmesi\"") != NULL)
                {
                    sscanf(line, " \"%*[^\"]\": %d", &value);
                    if (value == 1)
                    {
                        HR->saldiri_gelistirmesi.seviye_1.sayi++;
                    }
                    else if (value == 2)
                    {
                        HR->saldiri_gelistirmesi.seviye_2.sayi++;
                    }
                    else if (value == 3)
                    {
                        HR->saldiri_gelistirmesi.seviye_3.sayi++;
                    }
                }   
                if (strstr(line, "elit_egitim") != NULL)
                {
                    sscanf(line, " \"%*[^\"]\": %d", &value);
                    if (value == 1)
                    {
                        HR->elit_egitim.seviye_1.sayi++;
                    }
                    else if (value == 2)
                    {
                        HR->elit_egitim.seviye_2.sayi++;
                    }
                    else if (value == 3)
                    {
                        HR->elit_egitim.seviye_3.sayi++;
                    }
                }
                if (strstr(line, "kusatma_ustaligi") != NULL)
                {
                    sscanf(line, " \"%*[^\"]\": %d", &value);
                    if (value == 1)
                    {
                        HR->kusatma_ustaligi.seviye_1.sayi++;
                    }
                    else if (value == 2)
                    {
                        HR->kusatma_ustaligi.seviye_2.sayi++;
                    }
                    else if (value == 3)
                    {
                        HR->kusatma_ustaligi.seviye_3.sayi++;
                    }
                }
            }
        }
    }
    fclose(file);
}

void read_ork_scenario(const char *filename, Ork_Unit *OU, Ork_Hero *OH, Ork_Creature *OC, Research *OR)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Dosya Acilamadi!\n");
        return;
    }
    char line[256];
    int value = 0;
    while (fgets(line, sizeof(line), file))
    {   
        if (strstr(line, "\"ork_legi\": {") != NULL)
        {
            while (fgets(line, sizeof(line), file) && !strstr(line, "insan_imparatorlugu"))
            {
                if (strstr(line, "ork_dovusculeri") != NULL)
                {
                    sscanf(line, " \"ork_dovusculeri\": %d,", &OU->ork_dovusculeri.sayi);
                }
                if (strstr(line, "mizrakcilar") != NULL)
                {
                    sscanf(line, " \"mizrakcilar\": %d,", &OU->mizrakcilar.sayi);
                }
                if (strstr(line, "varg_binicileri") != NULL)
                {
                    sscanf(line, " \"varg_binicileri\": %d,", &OU->varg_binicileri.sayi);
                }
                if (strstr(line, "troller") != NULL)
                {
                    sscanf(line, " \"troller\": %d,", &OU->troller.sayi);
                }
                if (strstr(line, "\"Goruk_Vahsi\"") != NULL)
                {
                    OH->goruk.sayi++;
                }
                if (strstr(line, "\"Thruk_Kemikkiran\"") != NULL)
                {
                    OH->thruk.sayi++;
                }
                if (strstr(line, "\"Vrog_Kafakiran\"") != NULL)
                {
                    OH->vrog.sayi++;
                }
                if (strstr(line, "\"Ugar_Zalim\"") != NULL)
                {
                    OH->ugar.sayi++;
                }
                if (strstr(line, "\"Kara_Troll\"") != NULL)
                {
                    OC->troll.sayi++;
                }
                if (strstr(line, "\"Golge_Kurtlari\"") != NULL)
                {
                    OC->golge.sayi++;
                }
                if (strstr(line, "\"Camur_Devleri\"") != NULL)
                {
                    OC->camur.sayi++;
                }
                if (strstr(line, "\"Ates_Iblisi\"") != NULL)
                {
                    OC->ates_iblisi.sayi++;
                }
                if (strstr(line, "\"Buz_Devleri\"") != NULL)
                {
                    OC->buz_devi.sayi++;
                }
                if (strstr(line, "savunma_ustaligi") != NULL)
                {
                    sscanf(line, " \"%*[^\"]\": %d", &value);               
                    if (value == 1)
                    {
                        OR->savunma_ustaligi.seviye_1.sayi++;
                    }
                    else if (value == 2)
                    {
                        OR->savunma_ustaligi.seviye_2.sayi++;
                    }
                    else if (value == 3)
                    {
                        OR->savunma_ustaligi.seviye_3.sayi++;
                    }
                }
                if (strstr(line, "saldiri_gelistirmesi") != NULL)
                {
                    sscanf(line, " \"%*[^\"]\": %d", &value);
                    if (value == 1)
                    {
                        OR->saldiri_gelistirmesi.seviye_1.sayi++;
                    }
                    else if (value == 2)
                    {
                        OR->saldiri_gelistirmesi.seviye_2.sayi++;
                    }
                    else if (value == 3)
                    {
                        OR->saldiri_gelistirmesi.seviye_3.sayi++;
                    }
                }   
                if (strstr(line, "elit_egitim") != NULL)
                {
                    sscanf(line, " \"%*[^\"]\": %d", &value);
                    if (value == 1)
                    {
                        OR->elit_egitim.seviye_1.sayi++;
                    }
                    else if (value == 2)
                    {
                        OR->elit_egitim.seviye_2.sayi++;
                    }
                    else if (value == 3)
                    {
                        OR->elit_egitim.seviye_3.sayi++;
                    }
                }
                if (strstr(line, "kusatma_ustaligi") != NULL)
                {
                    sscanf(line, " \"%*[^\"]\": %d", &value);
                    if (value == 1)
                    {
                        OR->kusatma_ustaligi.seviye_1.sayi++;
                    }
                    else if (value == 2)
                    {
                        OR->kusatma_ustaligi.seviye_2.sayi++;
                    }
                    else if (value == 3)
                    {
                        OR->kusatma_ustaligi.seviye_3.sayi++;
                    }
                }
            }
        }
    }
    fclose(file);
}

void parse_unit_json(const char *filename, Human_Unit *HU, Ork_Unit *OU)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Dosya Acilamadi: %s\n", filename);
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file))
    {
        if (strstr(line, "\"piyadeler\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"saldiri\" : %d,", &HU->piyadeler.saldiri);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"savunma\" : %d,", &HU->piyadeler.savunma);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"saglik\" : %d,", &HU->piyadeler.saglik);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"kritik_sans\" : %d", &HU->piyadeler.kritik_sans);
        }
        if (strstr(line, "\"okcular\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"saldiri\" : %d,", &HU->okcular.saldiri);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"savunma\" : %d,", &HU->okcular.savunma);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"saglik\" : %d,", &HU->okcular.saglik);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"kritik_sans\" : %d", &HU->okcular.kritik_sans);
        }
        if (strstr(line, "\"suvariler\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"saldiri\" : %d,", &HU->suvariler.saldiri);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"savunma\" : %d,", &HU->suvariler.savunma);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"saglik\" : %d,", &HU->suvariler.saglik);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"kritik_sans\" : %d", &HU->suvariler.kritik_sans);
        }
        if (strstr(line, "\"kusatma_makineleri\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"saldiri\": %d,", &HU->kusatma_makineleri.saldiri);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"savunma\": %d,", &HU->kusatma_makineleri.savunma);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"saglik\": %d,", &HU->kusatma_makineleri.saglik);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"kritik_sans\": %d", &HU->kusatma_makineleri.kritik_sans);
        }
        if (strstr(line, "\"ork_dovusculeri\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"saldiri\": %d,", &OU->ork_dovusculeri.saldiri);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"savunma\": %d,", &OU->ork_dovusculeri.savunma);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"saglik\": %d,", &OU->ork_dovusculeri.saglik);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"kritik_sans\": %d", &OU->ork_dovusculeri.kritik_sans);
        }
        if (strstr(line, "\"mizrakcilar\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"saldiri\": %d,", &OU->mizrakcilar.saldiri);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"savunma\": %d,", &OU->mizrakcilar.savunma);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"saglik\": %d,", &OU->mizrakcilar.saglik);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"kritik_sans\": %d", &OU->mizrakcilar.kritik_sans);
        }
        if (strstr(line, "\"varg_binicileri\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"saldiri\": %d,", &OU->varg_binicileri.saldiri);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"savunma\": %d,", &OU->varg_binicileri.savunma);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"saglik\": %d,", &OU->varg_binicileri.saglik);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"kritik_sans\": %d", &OU->varg_binicileri.kritik_sans);
        }
        if (strstr(line, "\"troller\"") != NULL)
        {
            fgets(line, sizeof(line), file);
            sscanf(line, " \"saldiri\": %d,", &OU->troller.saldiri);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"savunma\": %d,", &OU->troller.savunma);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"saglik\": %d,", &OU->troller.saglik);
            fgets(line, sizeof(line), file);
            sscanf(line, " \"kritik_sans\": %d", &OU->troller.kritik_sans);
        }
    }

    fclose(file);
}
//Saldiri Gucu Hesaplayan Fonksiyon
void saldiri_gucu_hesapla(Human_Unit HU, Ork_Unit OU,  int *toplam_insan_saldiri, int *toplam_ork_saldiri) {
    
    *toplam_insan_saldiri = (HU.piyadeler.saldiri * HU.piyadeler.sayi) +
                            (HU.okcular.saldiri * HU.okcular.sayi) +     
                            (HU.suvariler.saldiri * HU.suvariler.sayi) +
                            (HU.kusatma_makineleri.saldiri * HU.kusatma_makineleri.sayi); 

    *toplam_ork_saldiri = (OU.ork_dovusculeri.saldiri * OU.ork_dovusculeri.sayi) + 
                          (OU.mizrakcilar.saldiri * OU.mizrakcilar.sayi) +     
                          (OU.varg_binicileri.saldiri * OU.varg_binicileri.sayi) + 
                          (OU.troller.saldiri * OU.troller.sayi);           
}

//SAvunma gucu hesaplayan Fonksiyon
void savunma_gucu_hesapla(Human_Unit HU , Ork_Unit OU ,int *toplam_insan_savunma , int *toplam_ork_savunma) {

    *toplam_insan_savunma = (HU.piyadeler.savunma * HU.piyadeler.sayi) + 
                            (HU.okcular.savunma * HU.okcular.sayi) +     
                            (HU.suvariler.savunma * HU.suvariler.sayi) + 
                            (HU.kusatma_makineleri.savunma * HU.kusatma_makineleri.sayi); 

    *toplam_ork_savunma = (OU.ork_dovusculeri.savunma * OU.ork_dovusculeri.sayi) + 
                          (OU.mizrakcilar.savunma * OU.mizrakcilar.sayi) +    
                          (OU.varg_binicileri.savunma * OU.varg_binicileri.sayi) + 
                          (OU.troller.savunma * OU.troller.sayi);             

}

void kritik_vurus_hesapla(Human_Unit *HU, Ork_Unit *OU, int adim, int *toplam_insan_saldiri, int *toplam_ork_saldiri) {
    const float kritik_carpani = 1.5;

    // Kritik vurus adim sayisi
    int insan_piyade_kritik_adim = 100 / HU->piyadeler.kritik_sans;
    int insan_okcu_kritik_adim = 100 / HU->okcular.kritik_sans;
    int insan_suvari_kritik_adim = 100 / HU->suvariler.kritik_sans;
    int insan_kusatma_kritik_adim = 100 / HU->kusatma_makineleri.kritik_sans;

    int ork_dovuscu_kritik_adim = 100 / OU->ork_dovusculeri.kritik_sans;
    int ork_mizrakci_kritik_adim = 100 / OU->mizrakcilar.kritik_sans;
    int ork_varg_binici_kritik_adim = 100 / OU->varg_binicileri.kritik_sans;
    int ork_troll_kritik_adim = 100 / OU->troller.kritik_sans;

    // İnsan birimlerinin saldırı gücü hesaplama
    if (adim % insan_piyade_kritik_adim == 0) {
        *toplam_insan_saldiri += (HU->piyadeler.saldiri * HU->piyadeler.sayi * kritik_carpani);
    } else {
        *toplam_insan_saldiri += (HU->piyadeler.saldiri * HU->piyadeler.sayi);
    }

    if (adim % insan_okcu_kritik_adim == 0) {
        *toplam_insan_saldiri += (HU->okcular.saldiri * HU->okcular.sayi * kritik_carpani);
    } else {
        *toplam_insan_saldiri += (HU->okcular.saldiri * HU->okcular.sayi);
    }

    if (adim % insan_suvari_kritik_adim == 0) {
        *toplam_insan_saldiri += (HU->suvariler.saldiri * HU->suvariler.sayi * kritik_carpani);
    } else {
        *toplam_insan_saldiri += (HU->suvariler.saldiri * HU->suvariler.sayi);
    }

    if (adim % insan_kusatma_kritik_adim == 0) {
        *toplam_insan_saldiri += (HU->kusatma_makineleri.saldiri * HU->kusatma_makineleri.sayi * kritik_carpani);
    } else {
        *toplam_insan_saldiri += (HU->kusatma_makineleri.saldiri * HU->kusatma_makineleri.sayi);
    }

    // Ork birimlerinin saldırı gücü hesaplama
    if (adim % ork_dovuscu_kritik_adim == 0) {
        *toplam_ork_saldiri += (OU->ork_dovusculeri.saldiri * OU->ork_dovusculeri.sayi * kritik_carpani);
    } else {
        *toplam_ork_saldiri += (OU->ork_dovusculeri.saldiri * OU->ork_dovusculeri.sayi);
    }

    if (adim % ork_mizrakci_kritik_adim == 0) {
        *toplam_ork_saldiri += (OU->mizrakcilar.saldiri * OU->mizrakcilar.sayi * kritik_carpani);
    } else {
        *toplam_ork_saldiri += (OU->mizrakcilar.saldiri * OU->mizrakcilar.sayi);
    }

    if (adim % ork_varg_binici_kritik_adim == 0) {
        *toplam_ork_saldiri += (OU->varg_binicileri.saldiri * OU->varg_binicileri.sayi * kritik_carpani);
    } else {
        *toplam_ork_saldiri += (OU->varg_binicileri.saldiri * OU->varg_binicileri.sayi);
    }

    if (adim % ork_troll_kritik_adim == 0) {
        *toplam_ork_saldiri += (OU->troller.saldiri * OU->troller.sayi * kritik_carpani);
    } else {
        *toplam_ork_saldiri += (OU->troller.saldiri * OU->troller.sayi);
    }
}

void saglik_hesapla(Human_Unit *HU, Ork_Unit *OU, int net_hasar_insan, int net_hasar_ork) {
    // Toplam Savunma Gücü Hesaplama
    int toplam_insan_savunma = (HU->piyadeler.savunma * HU->piyadeler.sayi) +
                               (HU->okcular.savunma * HU->okcular.sayi) +     
                               (HU->suvariler.savunma * HU->suvariler.sayi) + 
                               (HU->kusatma_makineleri.savunma * HU->kusatma_makineleri.sayi);

    int toplam_ork_savunma = (OU->ork_dovusculeri.savunma * OU->ork_dovusculeri.sayi) +
                             (OU->mizrakcilar.savunma * OU->mizrakcilar.sayi) +    
                             (OU->varg_binicileri.savunma * OU->varg_binicileri.sayi) + 
                             (OU->troller.savunma * OU->troller.sayi);

    // Oran Hesaplama
    double oran_piyadeler = (double)(HU->piyadeler.savunma * HU->piyadeler.sayi) / toplam_insan_savunma;
    double oran_okcular = (double)(HU->okcular.savunma * HU->okcular.sayi) / toplam_insan_savunma;
    double oran_suvariler = (double)(HU->suvariler.savunma * HU->suvariler.sayi) / toplam_insan_savunma;
    double oran_kusatma = (double)(HU->kusatma_makineleri.savunma * HU->kusatma_makineleri.sayi) / toplam_insan_savunma;

    double oran_ork_dovusculeri = (double)(OU->ork_dovusculeri.savunma * OU->ork_dovusculeri.sayi) / toplam_ork_savunma;
    double oran_mizrakcilar = (double)(OU->mizrakcilar.savunma * OU->mizrakcilar.sayi) / toplam_ork_savunma;
    double oran_varg_binicileri = (double)(OU->varg_binicileri.savunma * OU->varg_binicileri.sayi) / toplam_ork_savunma;
    double oran_troller = (double)(OU->troller.savunma * OU->troller.sayi) / toplam_ork_savunma;

    // Hasar Dağılımı
    int hasar_piyadeler = net_hasar_ork * oran_piyadeler;
    int hasar_okcular = net_hasar_ork * oran_okcular;
    int hasar_suvariler = net_hasar_ork * oran_suvariler;
    int hasar_kusatma = net_hasar_ork * oran_kusatma;

    int hasar_ork_dovusculeri = net_hasar_insan * oran_ork_dovusculeri;
    int hasar_mizrakcilar = net_hasar_insan * oran_mizrakcilar;
    int hasar_varg_binicileri = net_hasar_insan * oran_varg_binicileri;
    int hasar_troller = net_hasar_insan * oran_troller;

    // Sağlık Güncelleme
    HU->piyadeler.saglik -= hasar_piyadeler;
    HU->okcular.saglik -= hasar_okcular;
    HU->suvariler.saglik -= hasar_suvariler;
    HU->kusatma_makineleri.saglik -= hasar_kusatma;

    OU->ork_dovusculeri.saglik -= hasar_ork_dovusculeri;
    OU->mizrakcilar.saglik -= hasar_mizrakcilar;
    OU->varg_binicileri.saglik -= hasar_varg_binicileri;
    OU->troller.saglik -= hasar_troller;

    // Sağlık 0'ın altına düşerse, 0'da sabitle.
    if (HU->piyadeler.saglik <= 0) HU->piyadeler.saglik = 0;
    if (HU->okcular.saglik <= 0) HU->okcular.saglik = 0;
    if (HU->suvariler.saglik <= 0) HU->suvariler.saglik = 0;
    if (HU->kusatma_makineleri.saglik <= 0) HU->kusatma_makineleri.saglik = 0;

    if (OU->ork_dovusculeri.saglik <= 0) OU->ork_dovusculeri.saglik = 0;
    if (OU->mizrakcilar.saglik <= 0) OU->mizrakcilar.saglik = 0;
    if (OU->varg_binicileri.saglik <= 0) OU->varg_binicileri.saglik = 0;
    if (OU->troller.saglik <= 0) OU->troller.saglik = 0;
}




int main()
{
    
    parse_unit_json("unit_types.json", &HU, &OU);
    parse_hero_json("heroes.json", &HH, &OH);
    parse_creature_json("creatures.json", &HC, &OC);
    parse_research_json("research.json", &HR, &OR);

    read_ork_scenario("1.json", &OU, &OH, &OC, &OR);
    read_human_scenario("1.json", &HU, &HH, &HC, &HR);

    



// Variables to hold total attack and defense values
    int toplam_insan_saldiri = 0;
    int toplam_ork_saldiri = 0;
    int toplam_insan_savunma = 0;
    int toplam_ork_savunma = 0;
   

    printf("\n\n");
    yazdir_human_unit(&HU);       //her seyi okuyo
    printf("\n\n");
    yazdir_ork_unit(&OU);         //her seyi okuyo
    printf("\n\n");
    //yazdir_human_hero(&HH);       //her seyi okuyo
    //printf("\n\n");
    //yazdir_ork_hero(&OH);         //her seyi okuyo
    //printf("\n\n");
    //yazdir_human_creature(&HC);   //her seyi okuyo
    //printf("\n\n");
    //yazdir_ork_creature(&OC);     //her seyi okuyo
    //printf("\n\n");
    //yazdir_human_research(&HR);   //her seyi okuyo
    //printf("\n\n");
    //yazdir_ork_research(&OR);     //her seyi okuyo
    //printf("\n\n");

    return 0;
}