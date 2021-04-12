# Pažymiu skaičiuokle

## Ka daro?
- nuskaito studentu duomenys, is .txt file'o arba naudojant UserInput
- Apskaičiuoja galutini rezultatą naudojant mediana ir vidurki
- Pateikia rūšiuotus duomenis

## Pradiniu duomenų pavyzdys
- "kursiokai.txt"
- Pirmos eilutes formatas nesvarbus
- Nuo antros eilutes prasideda studentu duomenys : vardas, pavarde, namu darbu įvertinimai[0-10], įvertinimas egzamino  [0-10]
```shell
  Vardas                   Pavarde         ND1       ND2       ND3       ND4       ND5     NDx      Egz.
  Vardas1                 Pavarde1           3        10         8         1         7       0        2
  ...
```
*.txt file'a reikia perkelti i Results folderi

## Programos veikimo sparta
|   size   | Input duration(vector) | Input duration(deque)  | Input duration(list) |
|:--------:|:----------------------:|:----------------------:|:--------------------:|
|  100000  |          0.29s         |          0.29s         |         0.32s        |
|  1000000 |          3.08s         |          3.01s         |         3.27s        |
| 10000000 |         33.64s         |         30.28s         |        30.22s        |

|   size   | Sort duration(vector) | Sort duration(deque)  | Sort duration(list) |
|:--------:|:---------------------:|:---------------------:|:-------------------:|
|  100000  |         0.05s         |         0.09s         |        0.09s        |
|  1000000 |         0.73s         |         1.08s         |        1.43s        |
| 10000000 |         9.10s         |         13.13s        |        16.50s       |

*Programa buvo testuojama naudojant: Kingston A400(480gb) ssd, 8gb soddim ddr4 ram, Intel Core i5-7300HQ, 3strategija

|   size   | Duration of Creation | Duration of program |
|:--------:|----------------------|---------------------|
|  100000  | 0.121907s            | 1.79761s            |
|  1000000 | 1.02847s             | 25.9479s            |
| 10000000 | 10.1511s             | 231.401s            |

*Duration of program = creation+(input+sort+output)*(with vector, with deque, with list)
## Skirtingos Strategijos

#### Strategija Nr1
  Programa sukuria 2 papildomus to paties tipo (vector, list, deque) konteinerius -"islaike","skolininkai". 
  Tada tikrina kiekviena "students" konteinerio elementa,jeigu elementas <= 5 priskyria ji "skolininkai",
  kitu atveju priskyria ji "islaike"
 
#### Strategija Nr2 
  Programa sukuria 1 papildoma to paties tipo konteineri "islaike". Tada tikrina pradinio konteinerio elementus,
  elementui bunant >= 5, priskyria ji "islaike" ir istrina ji is pradinio konteinerio
 
#### Strategija Nr3
  Programa surikiuoja pradinio konteinerio elementus didejimo tvarka(pagal vidurki), tada suranda pirmo elemento >= 5 pozicija.
  Konteinerio dalys >= 5 yra priskyriama naujam konteineriui "islaike" naudojant copy(splice su std::list) funkcija, 
  galu gale istrina is pradinio elemento nukopijotus elementus
  
## Programos veikimo sparta taikant skirtingas strategijas  
  ![image](https://user-images.githubusercontent.com/54241089/114406516-46d75a80-9bb0-11eb-9902-fe78bf83490d.png)
  ![image](https://user-images.githubusercontent.com/54241089/114406906-9453c780-9bb0-11eb-9f07-0cb1351c3e72.png)

 
## Programos diegimas ir paleidimas
1. Atsiuskite programos versija is Releases
2. Komandinėje eilutėje įvykdykite sekančius veiksmus:
```shell
  cd nuoroda_į_programos_aplanką

  make
```
3. programos paleidimas :   ./my_program arba ./my_program input.txt 

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
#### v0.5 pokyciai
- optimizuota duomenu kurimo funkcija
- pridetos sort funkcijos naudojancios stl deque ir stl list konteinerius
- patobulintas "user interface"
- atsikratyta nereikalingu file'u
#### v1.0
- sukurta Timer klase patogesniam laiko matavymui
- SortToFile funkcija suskaidyta ir generalizuota
- Pridetos 2 papildomos sort strategijos
- Pakeistas UI kad matyti skirtumus tarp strategiju ir konteineriu pasirinkimu

