#include <stdio.h>
#include <stdbool.h>
#ifndef N
#define N 5
#endif

void obrot_scianki_prim(int siatka[][N][N], int scianka)
//to będzie funkcja, która będzie nam obracała przeciwległą ściankę w przypadku obrotu N warstw
//(np jak obrócimy N warstw od strony r (mając ściankę 2 na froncie), to obróci nam się nie tylko ścianka 3, ale też 1).
{
    for(int i=0; i<N/2; i++)
    {
        for (int j=0; j<(N+1)/2; j++)
        {
        // tutaj podzieliłam kostkę, na prostokąty i obracam każdy z tych prostokątów
        //(warto zauważyć, ze jeżeli po podzieleniu na prostokąty zostaje nam jeszcze jedyny, środkowy kwadracik, to i tak go właściwie nie obracamy).
            int pom=siatka[scianka][i][j];
            siatka[scianka][i][j]=siatka[scianka][j][N-1-i];
            siatka[scianka][j][N-1-i]=siatka[scianka][N-1-i][N-1-j];
            siatka[scianka][N-1-i][N-1-j]=siatka[scianka][N-1-j][i];
            siatka[scianka][N-1-j][i]= pom;
        }
    }
}

void obrot_scianki(int siatka[][N][N], int scianka)
// to funkcja, która będzie obracała nam ściankę "przyległą do strony" (w przykładzie, który podałam wyżej będzie to ścianka 3).
{
    for(int i=0; i<N/2; i++)
    {
        for (int j=0; j<(N+1)/2; j++)
        {
            int pom = siatka[scianka][i][j];
            siatka[scianka][i][j]=siatka[scianka][N-1-j][i];
            siatka[scianka][N-1-j][i]=siatka[scianka][N-1-i][N-1-j];
            siatka[scianka][N-1-i][N-1-j]=siatka[scianka][j][N-1-i];
            siatka[scianka][j][N-1-i] = pom;
        }
    }
}

void obrot_l (int siatka[][N][N], int liczba_warstw) //obrót od lewej strony (analogicznie będzie nazywała się reszta funckji obrotów)
{
    for(int i=0; i<liczba_warstw; i++)
    {
        for(int j=0; j<N; j++)
        {
        int pom = siatka[4][N-1-j][N-1-i];
            siatka[4][N-1-j][N-1-i]=siatka[5][j][i];
            siatka[5][j][i]=siatka[2][j][i];
            siatka[2][j][i]=siatka[0][j][i];
            siatka[0][j][i]=pom;
        }
    }
    obrot_scianki(siatka, 1);//obracamy ściankę "przyległą" (w tym przypadku 1, bo obrót idzie od lewej).
    if(liczba_warstw==N) obrot_scianki_prim(siatka, 3);//jeżeli obracamy N warstw, czyli całą kostkę, to musimy obrócić też ściankę z drugiej strony.
}

void obrot_r (int siatka[][N][N], int liczba_warstw)
{
    for(int i=N-1; i>N-1-liczba_warstw; i--)
    {
        for(int j=0; j<N; j++)
        {
        int pom = siatka[0][j][i];
        siatka[0][j][i]=siatka[2][j][i];
        siatka[2][j][i]=siatka[5][j][i];
        siatka[5][j][i]=siatka[4][N-1-j][N-1-i];
        siatka[4][N-1-j][N-1-i]=pom;
        }
    }
    obrot_scianki(siatka, 3);
    if(liczba_warstw==N) obrot_scianki_prim(siatka, 1);
}

void obrot_u (int siatka[][N][N], int liczba_warstw)
{
    for(int i=0; i<liczba_warstw; i++)
    {
        for(int j=0; j<N; j++)
        {
        int pom = siatka[2][i][j];
        siatka[2][i][j]=siatka[3][i][j];
        siatka[3][i][j]=siatka[4][i][j];
        siatka[4][i][j]=siatka[1][i][j];
        siatka[1][i][j]=pom;
        }
    }
    obrot_scianki(siatka, 0);
    if(liczba_warstw==N) obrot_scianki_prim(siatka, 5);
}

void obrot_d (int siatka[][N][N], int liczba_warstw)
{
    for(int i=N-1; i>N-1-liczba_warstw; i--)
    {
        for(int j=0; j<N; j++)
        {
        int pom = siatka[2][i][j];
        siatka[2][i][j]=siatka[1][i][j];
        siatka[1][i][j]=siatka[4][i][j];
        siatka[4][i][j]=siatka[3][i][j];
        siatka[3][i][j]=pom;
        }
    }
    obrot_scianki(siatka, 5);
    if(liczba_warstw==N) obrot_scianki_prim(siatka, 0);
}

void obrot_f (int siatka[][N][N], int liczba_warstw)
{
    for(int i=0; i<liczba_warstw; i++)
    {
        for(int j=0; j<N; j++)
        {
        int pom = siatka[0][N-1-i][j];
        siatka[0][N-1-i][j]=siatka[1][N-1-j][N-1-i];//zmieniamy indeksy, ponieważ na górze i na dole będą obracać się rzędy, a po bokach kolumny.
        siatka[1][N-1-j][N-1-i]=siatka[5][i][N-1-j];
        siatka[5][i][N-1-j]=siatka[3][j][i];
        siatka[3][j][i]=pom;
        }
    }
    obrot_scianki(siatka, 2);
    if(liczba_warstw==N) obrot_scianki_prim(siatka, 4);
}

void obrot_b (int siatka[][N][N], int liczba_warstw)
{
    for(int i=0; i<liczba_warstw; i++)
    {
        for(int j=0; j<N; j++)
        {
        int pom = siatka[0][i][j];
        siatka[0][i][j]=siatka[3][j][N-1-i];
        siatka[3][j][N-1-i]=siatka[5][N-1-i][N-1-j];
        siatka[5][N-1-i][N-1-j]=siatka[1][N-1-j][i];
        siatka[1][N-1-j][i]=pom;
        }
    }
    obrot_scianki(siatka, 4);
    if(liczba_warstw==N) obrot_scianki_prim(siatka, 2);
}

void operacja (char strona, int liczba_warstw, int siatka[][N][N])
{
    if(liczba_warstw == -1) liczba_warstw = 1;//inicjalizujemy liczbę warstw na -1, więc w razie nie wpisania żadnej liczby przyjmujemy, że chodzi o 1 warstwę
    if(strona=='l') obrot_l(siatka, liczba_warstw);
    if(strona=='r') obrot_r(siatka, liczba_warstw);
    if(strona=='u') obrot_u(siatka, liczba_warstw);
    if(strona=='d') obrot_d(siatka, liczba_warstw);
    if(strona=='f') obrot_f(siatka, liczba_warstw);
    if(strona=='b') obrot_b(siatka, liczba_warstw);
}

void operacja1(char strona, int liczba_warstw, int siatka[][N][N], char kat)
//"operacja" wykonuje obrót, natomiast "operacja1" definiuje o ile stopni.
{
    if(kat=='\'')//zauważmy, że kąt ' to 3 razy obrót.
    {
        operacja(strona, liczba_warstw, siatka);
        operacja(strona, liczba_warstw, siatka);
        operacja(strona, liczba_warstw, siatka);
    }
    else if (kat=='"')//natomiast kąt " to obrót 2 razy.
    {
        operacja(strona, liczba_warstw, siatka);
        operacja(strona, liczba_warstw, siatka);
    }
    else operacja(strona, liczba_warstw, siatka);
}

void wypisz (int siatka[][N][N])//funckja, która będzie nam drukowała stan kostki.
{
    printf("\n");//pierwszy wiersz zostaje pusty.
    for(int m=0; m<N; m++)
    {
        for(int i=0; i<=N; i++) printf("%c", ' ');//na górze wypisujemy najpierw spacje, a potem stan górnej ścianki.
        for( int j=0; j<N; j++) printf("%d", siatka[0][m][j]);
        printf("\n");
    }
    for(int m=0; m<N; m++)//następnie wypisujemy stan 4 ścianek (od 1 do 4), oddzielone znakiem "|".
    {
        for(int i=1; i<=4; i++)
        {
            for( int j=0; j<N; j++) printf("%d", siatka[i][m][j]);
            if(i != 4) printf("%c", '|');
        }
        printf("\n");
    }
    for(int m=0; m<N; m++)
    {
        for(int i=0; i<=N; i++) printf("%c", ' ');//na dole wypisujemy najpierw spacje, a potem stan dolnej ścianki
        for( int j=0; j<N; j++) printf("%d", siatka[5][m][j]);
        printf("\n");
    }
}

int main()
{
    int siatka[6][N][N];//tworzymy trójwymiarową tablicę -> 6 ścianek, każda mająca N rzędów i N kolumn.
    for(int scianka=0; scianka<6; scianka++)
    {
        for (int rzad=0; rzad<N; rzad++)
        {
            for (int kolumna=0; kolumna<N; kolumna++)
            {
            siatka[scianka][rzad][kolumna] = scianka;
            }
        }
    }

    bool czy_kropka = false;
    char strona;//strona czyli l, r, f, b, d, u
    strona = (char)getchar();
    int liczba_warstw = -1;//nie możemy zainicjalizować na 1, bo psułoby nam się gdyby ktoś wpisał np. r1.
    char kat = ' ';
    if(strona=='\n') wypisz(siatka);//gdybyśmy wpisali \n jako nasz pierwszy znak
    if(strona!='.')//kropka co prawda nie jest stroną, ale zakładamy, że strona to pierwszy znak i jeżeli to będzie kropka to kończymy cały program od razu.
    {
        while(czy_kropka == false)
        {
            char a;
            a = (char)getchar();
            if(a=='.')
            {
                czy_kropka = true;
            }
            else if(a>=48 && a<=57)//Zgodnie z ASCII znaki od 48 do 57 to liczby od 0 do 9
            {
                if(liczba_warstw == -1) liczba_warstw = a-48;
                else liczba_warstw = liczba_warstw * 10 + (a-48);// żeby np. 48 nie czytało jako "4" i "8" tylko jako "48". Mnożymy 4*10 i dodajemy 8.
				//analogicznie przy np. 258 wczytujemy najpierw "2", potem "5", więc robimy 20+5=25, potem "8", więc mamy 250+8=258.
            }
            else if(a == 34 || a == 39) kat = a;//znaki 34 i 39 to odpowiednio " i '.
            else if (a == '\n')
            {
                operacja1(strona, liczba_warstw, siatka, kat);
                strona = a;
                liczba_warstw = -1;
                kat = ' ';
                wypisz(siatka);
            }
            else
            {
                operacja1(strona, liczba_warstw, siatka, kat);
                strona = a;
                liczba_warstw = -1;
                kat = ' ';
                //przy każdej operacji "zerujemy" wartości.
            }
        }
    }
    return 0;
}
