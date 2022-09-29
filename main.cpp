//POP_2020_12_06_projekt_1_Dêbiñski_Rados³aw_AIR_3_184818
//Dev C++ Wersja Kombilatora: TDM-GCC 4.9.2 64-bit Release
#include <iostream>
#include <iomanip>	

using namespace std;
struct plansza;
const int wymiar_planszy=19;
const int wymiar_szachownicy=12;
/***********************************************************************/
void stworz_szachownice(plansza &szachownica);
void stworz_oznaczenia(plansza &szachownica);
void stworz_ranty(plansza &szachownica);
void stworz_wnetrze(plansza &szachownica);
void wyswietl_szachownice(plansza szachownica);
void biale_pola(plansza &szachownica);
void wypelnij_szachownice(plansza &szachownica);
void wczytaj_piony(plansza &szachownica);
void menu_glowne(plansza &szachownica);
void zasady_gry(plansza &szachownica);
void gramy(plansza &szachownica);
void wykonaj_ruch(plansza &szachownica, int i);
int kodowanie_wierszy(char kod);
int kodowanie_kolumn(char kod);
void zle_dane(plansza &szachownica, int i, int j);
void ruch(plansza &szachownica,int z_wier,int z_kol,int do_wier,int do_kol, int i);
void warunki_owcy(plansza &szachownica,int z_wier,int z_kol,int do_wier,int do_kol, int i);
void warunki_wilka(plansza &szachownica,int z_wier,int z_kol,int do_wier,int do_kol, int i);
int warunki_po_skosie(int z_wier,int z_kol,int do_wier,int do_kol);
int warunki_przy_zbijaniu( plansza szachownica ,int z_wier ,int z_kol ,int do_wier ,int do_kol);
int zwyciestwo_wilka(plansza szachownica);
int zwyciestwo_owiec(plansza szachownica);
void koniec_gry( int z);
/***********************************************************************/
struct plansza
{
	char pozycja[wymiar_planszy][wymiar_planszy];
	char stan_gry[wymiar_szachownicy][wymiar_szachownicy];
};
/***********************************************************************/
int main() 
{
	plansza szachownica;
	menu_glowne(szachownica);
	return 0;
}
/***********************************************************************/
void menu_glowne(plansza &szachownica)
{
	char wybor;
	cout<<"-----------Gra OWCE & WILK-----------"<<endl;
	cout<<"Opcje:"<<endl;
	cout<<"1.Graj."<<endl;
	cout<<"2.Zasady gry."<<endl;
	cout<<"3.Wyjdz."<<endl;
	cout<<"Podaj opcje: ";
	cin>>wybor;
	
	switch(wybor)
	{
		case '1':
			gramy(szachownica);
			break;
			
		case '2':
			system("cls");
			zasady_gry(szachownica);
			break;
			
		case '3':
			exit(0);
			break;
			
		default:
			system("cls");
			cout<<"Nie posiadam takiej opcji w menu :("<<endl;
			menu_glowne(szachownica);	
			break;
	}
}
/***********************************************************************/
void gramy(plansza &szachownica)
{
	stworz_oznaczenia(szachownica);
	stworz_ranty(szachownica);
	stworz_wnetrze(szachownica);
	biale_pola(szachownica);
	wczytaj_piony(szachownica);
	
	int i=1, z=0; // "i" czyj ruch // "z" kto wygra³
	do
	{
		system("cls");
		if(zwyciestwo_owiec(szachownica)) z=2;
		if(zwyciestwo_wilka(szachownica)) z=1;
		if(z!=0) koniec_gry(z);
		wypelnij_szachownice(szachownica);
		wyswietl_szachownice(szachownica);
		cout<<"Ruch ";
		if(i%2==1)
		{
		cout<<"owiec"; 
		}
		else
		{
		cout<<"wilka"; 
		}
		cout<<":"<<endl;
		wykonaj_ruch(szachownica, i);
		i++;
	}while(1);
		
}
/***********************************************************************/
int zwyciestwo_wilka(plansza szachownica)
{
	int z=0;
		for(int j=2; j<wymiar_szachownicy-2; j+=2)
		{
			if(szachownica.stan_gry[wymiar_szachownicy-3][j]=='W') z=1;
		}
	if(z==1) return 1;
	else return 0;
}
/***********************************************************************/
int zwyciestwo_owiec(plansza szachownica)
{
	int z=0, x, y;
	
	for(int i=0; i<wymiar_szachownicy; i++)
	{
		for(int j=0; j<wymiar_szachownicy; j++)
		{
			if(szachownica.stan_gry[i][j]=='W')
			{
				x=i;
				y=j;
			}
		}
	}
	
	if(szachownica.stan_gry[x-1][y+1]=='O') z++;
	if(szachownica.stan_gry[x-1][y-1]=='O') z++;
	if(szachownica.stan_gry[x+1][y+1]=='O') z++;
	if(szachownica.stan_gry[x+1][y-1]=='O') z++;
	if(szachownica.stan_gry[x-2][y+2]=='O') z++;
	if(szachownica.stan_gry[x-2][y-2]=='O') z++;
	if(szachownica.stan_gry[x+2][y+2]=='O') z++;
	if(szachownica.stan_gry[x+2][y-2]=='O') z++;
	
	if(z==8) return 2;
	else return 0;
}
/***********************************************************************/
void koniec_gry( int z)
{
	char n;
	cout<<"-----------Gra OWCE & WILK-----------"<<endl;
		
	cout<<setw(23)<<"KONIEC GRY"<<endl;
		
	if(z==2)
	cout<<setw(24)<<"WYGRALY OWCE"<<endl;
	
	if(z==1)
	cout<<setw(23)<<"WYGRAL WILK"<<endl;
		
	cout<<setw(27)<<"!!! GRATULACJE !!!"<<endl;
		
	cout<<endl<<endl;
	cout<<"Aby powrocic do menu wprowadz \"1\":"<<endl;
	cin>>n;
	if(n=='1') 
	{
	system("cls");
	main();	
	}
	else 
	{
		system("cls");
		cout<<"Nie posiadam takiej opcji w menu :("<<endl;
		koniec_gry(z);
	}
	
}
/***********************************************************************/
void wykonaj_ruch(plansza &szachownica, int i)
{
	char z_kolumna; // tworzenie danych na wspo³rzedne wejœciowe
	char z_Wiersz;	 
	char do_kolumna;
	char do_Wiersz;  
	
	cout<<"Skad przesuwamy:";
	cin>>z_kolumna>>z_Wiersz;
	cout<<"Na jaka pozycje:";
	cin>>do_kolumna>>do_Wiersz;
	
	int z_wier=kodowanie_wierszy( z_Wiersz ); //konwersja char int
	int do_wier=kodowanie_wierszy( do_Wiersz );
	
	if(((z_kolumna>='A' && z_kolumna<='H')||(z_kolumna>='a' && z_kolumna<='h'))&&((do_kolumna>='A' && do_kolumna<='H')||(do_kolumna>='a' && do_kolumna<='h'))&&(z_wier>0 && z_wier<9)&&(do_wier>0 && do_wier<9))
	{
		if(z_kolumna>='A' && z_kolumna<='H') z_kolumna=z_kolumna+32;
		if(do_kolumna>='A' && do_kolumna<='H') do_kolumna=do_kolumna+32;
		
		int z_kol;
		int do_kol;
		z_wier++;
		do_wier++;
		z_kol=kodowanie_kolumn(z_kolumna); //konwersja char int
		do_kol=kodowanie_kolumn(do_kolumna);
						 
		if(i%2==1)
		{
			warunki_owcy(szachownica, z_wier, z_kol, do_wier, do_kol, i); 
		}
		else 
		{
			warunki_wilka(szachownica, z_wier, z_kol, do_wier, do_kol, i);	
		}
	}
	else 
	{
		zle_dane(szachownica, i, 0);
	}	
	
}

/***********************************************************************/
void warunki_wilka(plansza &szachownica,int z_wier,int z_kol,int do_wier,int do_kol, int i )
{
	if(szachownica.stan_gry[z_wier][z_kol]=='W') // czy pion to wilk
	{
		if( warunki_po_skosie( z_wier, z_kol, do_wier, do_kol ))  
		{
			if(szachownica.stan_gry[do_wier][do_kol]==' ') //czy pole jest puste
			{	
				ruch(szachownica, z_wier, z_kol, do_wier, do_kol, i); //normalny ruch wilka
			}
			else zle_dane(szachownica, i, 1);
		}
	 	else if( warunki_przy_zbijaniu(szachownica, z_wier, z_kol, do_wier, do_kol) ) 
		{
			if(szachownica.stan_gry[do_wier][do_kol]==' ') //czy pole jest puste
			{	
				ruch(szachownica, z_wier, z_kol, do_wier, do_kol, i); //zbijajacy ruch wilka
			}
			else zle_dane(szachownica, i, 2);
		}
		else zle_dane(szachownica, i, 3);
		
	}
	else zle_dane(szachownica, i, 4);
}
/***********************************************************************/
int warunki_przy_zbijaniu( plansza szachownica ,int z_wier ,int z_kol ,int do_wier ,int do_kol)
{
	if((do_wier==z_wier-2) && (do_kol==z_kol+2) && szachownica.stan_gry[z_wier-1][z_kol+1]=='O') 
	return 1;
		else if((do_wier==z_wier-2) && (do_kol==z_kol-2) && szachownica.stan_gry[z_wier-1][z_kol-1]=='O')	
		return 1;	
			else if((do_wier==z_wier+2) && (do_kol==z_kol+2) && szachownica.stan_gry[z_wier+1][z_kol+1]=='O')	
			return 1;
				else if((do_wier==z_wier+2) && (do_kol==z_kol-2) && szachownica.stan_gry[z_wier+1][z_kol-1]=='O')	
				return 1;
	else return 0;
}
/***********************************************************************/
int warunki_po_skosie(int z_wier,int z_kol,int do_wier,int do_kol)
{
	if((do_wier==z_wier-1) && (do_kol==z_kol+1))	
	return 1;
		else if((do_wier==z_wier-1) && (do_kol==z_kol-1))	
		return 1;
			else if((do_wier==z_wier+1) && (do_kol==z_kol+1))
			return 1;
				else if((do_wier==z_wier+1) && (do_kol==z_kol-1))	
				return 1;
	else return 0;
}
/***********************************************************************/
void warunki_owcy(plansza &szachownica,int z_wier,int z_kol,int do_wier,int do_kol, int i )
{
	if(szachownica.stan_gry[z_wier][z_kol]=='O') // czy pion to owca
	{
		if( ((do_wier==z_wier-1) && (do_kol==z_kol+1)) || ((do_wier==z_wier-1) && (do_kol==z_kol-1)) ) //czy po skosie do przodu
		{
			if(szachownica.stan_gry[do_wier][do_kol]==' ') //czy pole jest puste
			{	
				ruch(szachownica, z_wier, z_kol, do_wier, do_kol, i); 
			}
			else zle_dane(szachownica, i, 5);
		}
		else zle_dane(szachownica, i, 6);
	}
	else zle_dane(szachownica, i, 7);
}
/***********************************************************************/
void ruch(plansza &szachownica,int z_wier,int z_kol,int do_wier,int do_kol, int i )
{
	char zamiana=szachownica.stan_gry[do_wier][do_kol];
	szachownica.stan_gry[do_wier][do_kol]=szachownica.stan_gry[z_wier][z_kol];
	szachownica.stan_gry[z_wier][z_kol]=zamiana;	
	
	if((do_wier-z_wier)%2==0) // warunek skoku o 2
	{
		int x = (do_wier-z_wier)/2;
		int y = (do_kol-z_kol)/2;
		szachownica.stan_gry[z_wier+x][z_kol+y]=' ';	//zjedzenie owcy
	}
}
/***********************************************************************/
void zle_dane(plansza &szachownica, int i, int j)
{
	
	cout<<"Kod bledu #"<<j<<endl; // s³u¿y do testowania programu
	system("cls");
	wyswietl_szachownice(szachownica);
	cout<<"Popraw swoj ruch ";
	if(i%2==1)							//warunki owiec
	cout<<"owco!"<<endl;
	else 								//warunki wilka
	cout<<"wilku!"<<endl;	
	wykonaj_ruch(szachownica, i);
}
/***********************************************************************/
int kodowanie_wierszy(char kod)
{
	switch(kod)
	{
	case '1':
		return 1;
		break;
	case '2':
		return 2;
		break;
	case '3':
		return 3;
		break;
	case '4':
		return 4;
		break;
	case '5':
		return 5;
		break;
	case '6':
		return 6;
		break;
	case '7':
		return 7;
		break;
	case '8':
		return 8;
		break;	
	default:
		return 9;	
		break;
	}
}
/***********************************************************************/
int kodowanie_kolumn(char kod)
{
	switch(kod)
	{
	case 'a':
		return 2;
		break;
	case 'b':
		return 3;
		break;
	case 'c':
		return 4;
		break;
	case 'd':
		return 5;
		break;
	case 'e':
		return 6;
		break;
	case 'f':
		return 7;
		break;
	case 'g':
		return 8;
		break;
	case 'h':
		return 9;
		break;	
	}
}
/***********************************************************************/
void zasady_gry(plansza &szachownica)
{
	cout<<"-----------Gra OWCE & WILK-----------"<<endl;
	cout<<"ZASADY:"<<endl;
	cout<<"Na szachownicy znajduje sie 12 owiec, ktorymi steruje pierwszy gracz, natomiast po drugiej stronie planszy"<<endl
	<<"czeka wilk ktorym steruje drugi gracz, zarowno wilk jak i owce moga poruszac sie tylko po skosie, przy czym"<<endl
	<<"owce tylko do przodu oznacza to, ze niedopuszczalne jest przesuniecie piona na pozycje oznaczona X na "<<endl
	<<"ponizszym przykladzie. Wilk moze pozerac owce po przez przeskoczenie na jedna z nich i wyladowanie na polu za"<<endl
	<<"nia, jednak gdy na wspomnianym polu czeka owca wilk nie moze wykonac ruchu. Zadaniem wilka jest dotarcie do "<<endl
	<<"przeciwleglej krawedzi planszy, natomiast owiec zatrzymanie wilka. POWODZENIA!!!"<<endl<<endl;
	stworz_szachownice(szachownica);
	cout<<endl;
	cout<<"By wrocic do menu wprowadz 1: ";
	
	char wybor;
	cin>>wybor;
	
	if(wybor=='1')
	{
		system("cls");
		menu_glowne(szachownica);
	}
	else
	{
		system("cls");
		cout<<"Miales podac 1 :("<<endl;
		zasady_gry(szachownica);
	}
	
}
/***********************************************************************/
 void biale_pola(plansza &szachownica)
 {
 	for(int j=2; j<wymiar_szachownicy-2; j++)
 	{
 		int w=2;
 		if(j%2==1) w=3;
	 	for(int i=w; i<wymiar_szachownicy; i+=2)
		{
			szachownica.stan_gry[j][i]='X';
		}
		w=3;
		if(j%2==1) w=2;
		for(int i=w; i<wymiar_szachownicy-2; i+=2)
		{
			szachownica.stan_gry[j][i]=' ';
		}
		
	}
 }
/***********************************************************************/
void wczytaj_piony(plansza &szachownica)
{
	for(int i=0; i<wymiar_szachownicy; i++)
	{
		for(int j=0; j<wymiar_szachownicy; j++)
		{
			if( (i>=0 && i<2) || (i>=10 && i<wymiar_szachownicy) || ((i>=2 && i<10) && ((j>=0 && j<2) || (j>=10 && j<wymiar_szachownicy))) )
			szachownica.stan_gry[i][j]='O';            // Dwa rzedy niesmiertelnych owiec okalajacych szachownice
		}
	}
	
	szachownica.stan_gry[2][5]='W'; 					//Ustaw Wilka na D1
	
	for(int i=7; i<wymiar_szachownicy-2; i++)
	{
		int w=3;
		if(i%2==1) w=2;
			
		for(int j=w; j<wymiar_szachownicy-2; j+=2)
		{
			szachownica.stan_gry[i][j]='O';
		}
	}
}
/***********************************************************************/
void wypelnij_szachownice(plansza &szachownica)
{
	for(int i=2, k=2; i<wymiar_planszy-1; i+=2, k++)
	{
		for(int j=2, l=2; j<wymiar_planszy-1; j+=2, l++)
		{
			szachownica.pozycja[i][j]=szachownica.stan_gry[k][l];
		}
	}
}
/***********************************************************************/
void stworz_szachownice(plansza &szachownica)
{
	stworz_oznaczenia(szachownica);
	stworz_ranty(szachownica);
	stworz_wnetrze(szachownica);
	biale_pola(szachownica);
	wczytaj_piony(szachownica);
	wypelnij_szachownice(szachownica);
	wyswietl_szachownice(szachownica);
}
/***********************************************************************/
void stworz_oznaczenia(plansza &szachownica)
{
	int znak_ASCII='A';
	for(int i=2; i<18; i+=2) //tworzenie oznaczen dla kolumn
	{
	szachownica.pozycja[0][i]=znak_ASCII;
	szachownica.pozycja[18][i]=znak_ASCII;
	znak_ASCII++;
	}
	znak_ASCII='1';
	for(int i=2; i<18; i+=2) //tworzenie oznaczen dla kolumn
	{
	szachownica.pozycja[i][0]=znak_ASCII;
	szachownica.pozycja[i][18]=znak_ASCII;
	znak_ASCII++;
	}
}
/***********************************************************************/
void stworz_ranty(plansza &szachownica)
{
	for(int j=1; j<wymiar_planszy-1 ; j++)
	{
		for(int i=0; i<wymiar_planszy-1; i++)
		{
			if(j%2==1)
			{
				if(i%2==1)	
				szachownica.pozycja[j][i]='+';
				else
				szachownica.pozycja[i][j]='|';
			}
			else if(i%2==1)
			szachownica.pozycja[i][j]='-';
		}
	}
}
/***********************************************************************/
void stworz_wnetrze(plansza &szachownica)
{
	for(int i=2; i<wymiar_planszy-2; i+=2)
	{
		for(int j=2; j<wymiar_planszy-2; j+=2)
		{
		szachownica.pozycja[i][j]=' ';	
		}	
	}
	
	szachownica.pozycja[0][0]='/';
	szachownica.pozycja[0][18]='\\';
	szachownica.pozycja[18][0]='\\';
	szachownica.pozycja[18][18]='/';
	
	for(int i=1; i<wymiar_planszy-1; i+=2)
	{
	szachownica.pozycja[0][i]=' ';
	szachownica.pozycja[18][i]=' ';
	szachownica.pozycja[i][0]=' ';
	szachownica.pozycja[i][18]=' ';	
	}	
}
/***********************************************************************/
void wyswietl_szachownice(const plansza szachownica)
{
	for(int i=0; i<wymiar_planszy; i++)
	{
		for(int j=0; j<wymiar_planszy; j++)
		{
		cout<<setw(2)<<szachownica.pozycja[i][j];		
		}
		cout<<endl;	
	}
}
/***********************************************************************/

