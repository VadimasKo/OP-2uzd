# Pazymiu skaiciuokle

## Ka daro?
- nuskaito studentu duomenys, is .txt file'o arba naudojant UserInput
- Apskaiciuoja galutini rezultata naudojant mediana ir vidurki
- Pateikia surusiuotus duomenys

## Pradiniu duomenu pavyzdis
- "kursiokai.txt"
    - Pirmos eilutes formatas nesvarbus
    - Nuo antros eilutes prasideda studentu duomenys : vardas, pavarde, namu darbu ivertinimai[0-10], egzamino ivertinimas [0-10]
```shell
  Vardas                   Pavarde         ND1       ND2       ND3       ND4       ND5     NDx      Egz.
  Vardas1                 Pavarde1           3        10         8         1         7       0        2
  ...
```

## Programos veikimo sparta

| size     | Creation time | Input duration  | Sorting duration  | Output duration |
|----------|---------------|-----------------|-------------------|-----------------|
| 1000     | 0.03s         | 0.005s          | 0.001s            | 0.005s          |
| 10000    | 0.2s          | 0.042s          | 0.006s            | 0.009s          |
| 100000   | 1.8s          | 0.203s          | 0.063s            | 0.093s          |
| 1000000  | 17.28s        | 1.818s          | 0.729s            | 1.222s          |
| 10000000 | 158.14s       | 16.744s         | 8.693s            | 10.360s         |

*Programa buvo testuojama naudojant tik 2 pazymius

## Programos diegimas ir paleidimas
1. Atsiuskite programos versija is Releases
2. Komandinėje eilutėje įvykdykite sekančius veiksmus:
```shell
  cd nuoroda_į_programos_aplanką
  make unpack
  make
```
3. jeigu make unpack nesukure ProjectFiles aplankalo, sukurkite ji patys  

4. programos paleidimas :   ./my_program arba ./my_program input.txt 

## Pokyciu logas
#### v0.1 pokyciai
- x
- x
#### v0.2 pokyciai
- x
- x
#### v0.3 pokyciai
- x
- x
#### v0.4 pokyciai
- programos file'ai surusioti i skirtingus aplankalus
- Patobulintas random generavimas
- rezultatai pateikiami i  islaike.txt (galutinis(vid) >= 5) ir  skolininkai.txt (galutinis(vid) <5)
- programa pateikia ivairiu jos daliu darbo laika



