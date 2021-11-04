Napisz program, który wykonuje ciąg rozkazów obracających warstwy kostki rozmiaru N x N x N. Program zaczyna od kostki ułożonej. Na życzenie drukuje aktualny stan kostki.

Stałą symboliczną N, określającą rozmiar kostki, należy zdefiniować dyrektywami:

#ifndef N
#define N 5
#endif

Wskazują one 5 jako wartość domyślną. Inną wartość stałej można wybrać podczas kompilacji programu za pomocą opcji -DN=wartość.
Postać danych

Dane programu to ciąg rozkazów obrotu warstw i wydruku aktualnego stanu kostki, zakończony kropką.

Program ignoruje zawartość wejścia po kropce kończącej dane.

Rozkazem wydruku stanu kostki jest koniec wiersza.

Rozkaz obrotu warstw składa się z trzech części, które wskazują:

    ścianę kostki,

    liczbę warstw,

    kąt obrotu.

Ściana jest określona literą:

    u - góra (ang. up),

    l - lewo (ang. left),

    f - przód (ang. front),

    r - prawo (ang. right),

    b - tył (ang. back),

    d - dół (ang. down).

Jeśli część rozkazu, określająca liczbę warstw, jest pusta, to wskazuje liczbę 1. W przeciwnym przypadku jest pozycyjnym dziesiętnym zapisem dodatniej liczby warstw. Wartość tej liczby nie przekracza stałej N, definiującej rozmiar kostki.

Część rozkazu określająca kąt jest albo pusta albo jest apostrofem lub cudzysłowem. Pusta część wskazuje kąt 90 stopni, apostrof to -90 stopni a cudzysłów to 180 stopni.

Wykonanie rozkazu obrotu, ze ścianą S, liczbą warstw W i kątem K, powoduje jednoczesne obrócenie W warstw, patrząc od strony ściany S, o kąt K, zgodnie z ruchem wskazówek zegara.

Składnię danych opisuje gramatyka z symbolem początkowym Dane:

Dane → CiągRozkazów Kropka
CiągRozkazów -> ε | Rozkaz CiągRozkazów
Rozkaz → Obrót | Drukowanie
Obrót → Strona LiczbaWarstw Kąt
Drukowanie → KoniecWiersza
Strona → Litera
LiczbaWarstw → Jedna | Wiele
Jedna → ε
Wiele → Liczba
Liczba → Cyfra | Liczba Cyfra
Kąt → Prosty | MinusProsty | Półpełny
Prosty → ε
MinusProsty → Apostrof
Półpełny → Cudzysłów
Litera → u | l | f | r | b | d
Cyfra → 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9
Apostrof → '
Cudzysłów → "
KoniecWiersza → \n
Kropka → .

Postać wyniku

Wynik programu jest efektem wykonania rozkazów drukowania aktualnego stanu kostki.

Wydruk stanu kostki składa się ze znaków 0, 1, 2, 3, 4, 5, symbolizujących kolory kwadratów na ścianach kostki, oraz ze spacji i kresek pionowych |.

Przyjmujemy, że w ułożonej kostce:

    kwadraty ściany górnej mają kolor 0,

    kwadraty ściany lewej mają kolor 1,

    kwadraty ściany przedniej mają kolor 2,

    kwadraty ściany prawej mają kolor 3,

    kwadraty ściany tylnej mają kolor 4,

    kwadraty ściany dolnej mają kolor 5.

Położenie ścian na wydruku stanu kostki jest zgodne ze schematem:

  u
l|f|r|b
  d

gdzie u, l, f, r, b, d to, odpowiednio, ściana górna, lewa, przednia, prawa, tylna i dolna.

Dla stałej N definiującej rozmiar kostki, wydruk stanu kostki składa się z 3 * N + 1 wierszy:

    pierwszy wiersz jest pusty,

    N kolejnych wierszy opisuje ścianę górną,

    następnych N wierszy to opis ściany lewej, przedniej, prawej i tylnej,

    ostatnich N wierszy opisuje ścianę dolną.

Każdy wiersz opisu ściany górnej i dolnej zaczyna się od N + 1 spacji, po których jest N cyfr określających kolory kwadratów tej ściany.

Wiersze opisu ściany lewej, przedniej, prawej i tylnej mają kolejno:

    N cyfr określających kolory kwadratów na ścianie lewej,

    znak |,

    N cyfr określających kolory kwadratów na ścianie przedniej,

    znak |,

    N cyfr określających kolory kwadratów na ścianie prawej,

    znak |,

    N cyfr określających kolory kwadratów na ścianie tylnej.

Na wydruku stanu kostki, cyfry określające kolory kwadratów każdej ściany zajmują obszar rozmiaru N x N.

Dla ściany lewej, przedniej, prawej i tylnej, kolory kwadratów opisane są w kolejności, jaką zobaczylibyśmy po obrocie całej kostki o wielokrotność kąta prostego od strony ściany górnej lub dolnej.

Dla ściany górnej i dolnej kolejność jest taka, jaką zobaczylibyśmy, gdybyśmy obrócili kostkę o wielokrotność kąta prostego od strony ściany lewej lub prawej.
Przykłady

Do treści zadania dołączone są pliki .in z przykładowymi danymi i pliki .out z wynikami wzorcowymi.

Przykłady zakładają, że stała N, definiująca rozmiar kostki, ma wartość 5.

    Dla danych przyklad1.in poprawny wynik to przyklad1.out.

    Dla danych przyklad2.in poprawny wynik to przyklad2.out.

    Dla danych przyklad3.in poprawny wynik to przyklad3.out.

Walidacja i testy


  Rozwiązania zostaną poddane walidacji, wstępnie badającej zgodność ze specyfikacją.

  Walidacja sprawdzi działanie programu na przykładach dołączonych do treści zadania.

  Pomyślne przejście walidacji jest warunkiem dopuszczenia programu do testów poprawności. Program, który walidacji nie przejdzie, dostanie zerową ocenę poprawności.

  Walidacja i testy zostaną przeprowadzone na komputerze students.

 Programy będą kompilowane poleceniem:

    gcc -DN=wartość -std=c11 -pedantic -Wall -Wextra -Werror -fstack-protector-strong -g nazwa.c -o nazwa

  gdzie nazwa.c to nazwa pliku z kodem źródłowym a wartość to wartość stałej N definiującej rozmiar kostki.

  Wymagane są wszystkie wymienione opcje kompilatora. Nie będą do nich dodawane żadne inne.

  Zwracamy uwagę, że poszczególne wersje kompilatora gcc mogą się różnić sposobem obsługi tych samych opcji. Przed wysłaniem rozwiązania warto więc skompilować je i przetestować na students, w sposób opisany powyżej.

  Podczas walidacji i testów, program nazwa będzie uruchamiany pod kontrolą programu Valgrind poleceniem:

    valgrind --leak-check=full -q ./nazwa

  Jeśli Valgrind wykryje błąd, to nawet, gdyby wynik był prawidłowy uznamy, że program testu nie przeszedł.

  Opcja -q powoduje, że jedynymi komunikatami, wypisywanymi przez program Valgrind, są komunikaty o błędach.

  Opcja --leak-check=full wskazuje Valgrindowi, że powinien, między innymi, szukać wycieków pamięci.

  Przyjmujemy, że wynik funkcji main() inny niż 0 informuje o błędzie wykonania programu.
