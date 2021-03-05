# Pazymiu skaiciuokle

## Ka daro?
- nuskaito studentu duomenys, is .txt file'o arba naudojant UserInput
- Apskaiciuoja galutini rezultata naudojant mediana ir vidurki
- Pateikia surusiuotus duomenys

## v0.4 pokyciai
- programos file'ai surusioti i skirtingus aplankalus
- Patobulintas random generavimas
- rezultatai pateikiami i  islaike.txt (galutinis(vid) >= 5) ir  skolininkai.txt (galutinis(vid) <5)
- programa pateikia ivairiu jos daliu darbo laika



## Pradiniu duomenu pavyzdis
- "kursiokai.txt"
```shell
  Vardas                   Pavarde                    ND1       ND2       ND3       ND4       ND5     NDx      Egz.
  Vardas1                 Pavarde1                      3        10         8         1         7       0        2
  ...
```
- Pirmos eilutes formatas nesvarbus
- Nuo antros eilutes prasideda studentu duomenys : vardas, pavarde, namu darbu ivertinimai[0-10], egzamino ivertinimas [0-10]


## Programos diegimas ir paleidimas
- Atsiuskite programos versija is Releases
- Komandinėje eilutėje įvykdykite sekančius veiksmus:
```shell
  cd nuoroda_į_programos_aplanką
  make unpack
  make
  ./my_program

```
- jeigu make unpack nesukure ProjectFiles, sukurkite ji patys  
- programos paleidimas :   ./my_program

