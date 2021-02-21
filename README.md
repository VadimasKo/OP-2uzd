# OP-2uzd v0.2
Papildykite programos versiją (v0.1) taip, kad būtų 
 - galima duomenis ne tik įvesti bet ir nuskaityti iš failo. 
 - tudentai turi būti surūšiuoti pagal vardus (ar pavardes)
 - visi stulpeliai būtų gražiai "išlygiuoti".

Nuskaičiuos duomenis iš failo, išvedimas pleriminariai turetu atrodytų taip:
```shell
pavarde vardas galutinis(vid) galutinis(med)
--------------------------------------------
```
## Programos diegimas ir paleidimas
- Atsiuskite programos versija is Releases
- Komandinėje eilutėje įvykdykite sekančius veiksmus:
```shell
  cd nuoroda_į_programos_aplanką
  make

```
arba
```shell
  cd nuoroda_į_programos_aplanką
  g++ -c UI.cpp main.cpp
  g++ -o my_program.exe UI.o main.o
```
programos paleidimas : ./my_program

