# Flights
First Term Project 2019


To do:

Korzystając z dynamicznych struktur danych napisać program, który przygotowuje listy pasażerów. 
Pasażerowie mogą rezerwować bilety na różne loty w różnych biurach i przez internet. Wszystkie rezerwacje są zapisywane w biurze centralnym. 
Mają one następującą postać:
⟨symbol lotu⟩ ⟨lotnisko startowe⟩ ⟨data lotu⟩ ⟨nazwisko pasażera⟩ ⟨nr miejsca⟩

Przykładowy plik z rezerwacjami:
KR54R Katowice 2011-12-13 Jaworek 33 
TY34O London 2012-02-03 Hastings 2 
TY34O London 2012-02-03 Poirot 23 
KR54R Katowice 2011-12-13 Matianek 02 
TY34O London 2012-02-03 Holmes 11 
KR54R Katowice 2011-12-13 Lopez 12 
TY34O London 2012-02-03 Lemon 43 
KR54R Katowice 2011-12-13 Chavez 43

Na podstawie pliku z rezerwacjami należy stworzyć pliki z listą pasażerów dla każdego lotu. 
Każda lista jest tworzona w odrębnym pliku. Nazwą pliku jest symbol lotu. W pliku umieszczona jest nazwa lotniska i data. 
W kolejnych liniach umieszczone są numery siedzeń i nazwiska pasażerów, posortowane wg numerów. 
Dla powyższego pliku zostaną utworzone dla pliki: KR54R.txt i TY34O.txt.

Plik KR54R.txt:
symbol lotu: KR54R lotnisko: Katowice data lotu: 2011-12-13
lista pasazerow: 02 Matianek
12 Lopez
33 Jaworek
43 Chavez
liczba rezerwacji: 4

Program uruchamiany jest z linii poleceń z wykorzystaniem następującego przełącznika: 
-i plik wejściowy z rezerwacjami
