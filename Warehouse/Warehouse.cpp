#include <iostream> 
#include <cstring> 
#include <string>
#include <cctype> 
#include <fstream> 
#include <iomanip> 
#include <Windows.h> 
using namespace std;
const int pole_sifra = 5; // KONSTANTA KOJA OZNACUVA DOLZINA NA POLE NA SIFRA NA ARTIKAL
const int pole_inOut = 6; // KONSTANTA KOJA OZNACUVA DOLZINA NA POLE NA VLEZ/IZLEZ NA ARTIKAL
const int pole_edinCena = 10; // KONSTANTA KOJA OZNACUVA DOLZINA NA POLE NA EDINECNA CENA NA ARTIKAL
const int pole_VAT = 8; // KONSTANTA KOJA OZNACUVA DOLZINA NA POLE NA DANOK NA ARTIKAL
const int pole_izons = 13; // KONSTANTA KOJA OZNACUVA DOLZINA NA POLE NA IZNOS NA ARTIKAL
const int pole_Date = 6; // KONSTANTA KOJA OZNACUVA DOLZINA NA POLE NA DATA NA ARTIKAL


struct edin_cena {  
	float vlez;		// VLEZNA EDINICNA CENA
	float izlez;	// IZLEZNA EDINECNA CENA
};


struct iznos_artikal {
	float vlez;		// VLEZEN IZNOS
	float izlez;	// IZLEZEN IZNOS
};


struct Artikal{	
	int sifra;		// SIFRA NA ARTIKAL
	string opis;	// OPIS NA STRUKTURA
	int in;			// BROJ NA VLEZNI EDINICI NA ARTIKALOT
	int out;		// BROJ NA IZLEZNI EDINICI NA ARTIKALOT
	struct edin_cena cena;	// PROMENLIVA OD VID STRUKTURA(OD DODATNA) ZA VLEZNA I IZLEZNA CENA
	float VAT;				// DANOK / DANOCNA STAPKA
	struct iznos_artikal iznos;	// IZNOS
	int date;		// DATA KOGA E ZAPISOT ZA ARTIKALOT
};


bool proverka_Broj(int n, int pole) {      
	bool proverka;		
	int brojac = 0;		// PROMENLIVA KORISTENA KAKO BROJAC ZA DA PROVERI KOLKU CIFREN E BROJOT
	while (n > 0) {		
		n = n / 10;		// BROENJE NA CIFRITE
		brojac++;
	}
	
	if (brojac <= pole) {
		proverka = true;
	}

	else {
		proverka = false;
	}
	return proverka;	
}

/*BOOL FUNKCIJA KOJA PROVERUVA DALI DATATA E VO PRAVILEN FORMAT*/
bool proverka_godina(int n) {  
	bool proverka;		
	int brojac = 0;		
	while (n > 0) {
		n = n / 10;		
		brojac++;
	}

	if (brojac == 6) {
		proverka = true;
	}

	else {
		proverka = false;
	}
	return proverka;
}

/*BOOL FUNKCIJA KOJA PROVERUVA DALI VNESENITE DENOVI SE VO PRAVILEN FORMAT*/
bool proverka_den(int n) {  
	bool proverka;		
	int den;			
	den = n % 100;
	if ((den < 0) && (den > 31)) {
		proverka = false;
	}
	else {
		proverka = true;
	}
	return proverka;
}

/*BOOL FUNKCIJA KOJA PROVERUVA DALI MESECOT E VNESEN VO PRAVILEN FORMAT T.E. OD 1 DO 12*/
bool proverka_mesec(int n) { 
	bool proverka;		 
	int mesec;			
	mesec = (n / 100) % 100;
	if ((mesec < 0) && (mesec > 12)) {
		proverka = false;
	}
	else {
		proverka = true;
	}
	return proverka;	
}

/*BOOL FUNKCIJA KOJA PROVERUVA DALI VNESOT NA DATATA E PRAVILEN T.E DALI SE KOORDINIRANI MESECITE I DENOVITE*/
bool proverka_data(int n) {
	bool proverka = true;		
	if ((n / 100) == 2 && ((n % 100) > 28)) {;
		proverka = false;
	}
	else if ((((n / 100) == 4) || ((n / 100) == 6) || ((n / 100) == 9) || ((n / 100) == 11)) && ((n % 100) > 30)) {
		proverka = false;
	}
	return proverka;
}

/*BOOL F-JA KOJA PROVERUVA DALI IMAME VNESEN ARTIKAL SO TAA SIFRA*/
bool ima_sifra(struct Artikal z[] , int n, int artikli, int& redenbroj) {
	bool ima;		
	int i = 0;	
	for (i = 0; i < artikli; i++) {
		if (n == z[i].sifra) {
			redenbroj = i;
			ima = true;
			break;
		}
	}
	if (i == artikli) {
		cout << "Nema artikal so takva sifra !!!" << endl;
		ima = false;
	}
	return ima;
}

/*VOID F-JA VNES NA ARTIKAL*/
void vnes_Vlez(struct Artikal z[], int i) {
	Sleep(2000);	
	system("CLS");
	cout << "Sifra na " << i + 1 << " artikal : ";
	cin >> z[i].sifra;
	while (!(proverka_Broj(z[i].sifra, pole_sifra))) {
		cout << "Invalid Input !!!" << endl;
		cout << "Sifrata treba da bide pomalku od " << pole_sifra + 1 << " broevi !!!" << endl;
		cin >> z[i].sifra;
	}
	cout << "Opis na " << i + 1 << " artikal : ";
	cin.ignore();	// IGNORIRANJE NA '\n' OSTAVENO OD PRETHODNIOT VNES
	getline(cin, z[i].opis); 
	while (z[i].opis.length() > 30) {
		cout << "Invalid Input !!!" << endl;
		cout << "Opisot treba da bide pomalku od 31 karakter !!!" << endl;
		getline(cin, z[i].opis);
	}
	z[i].VAT = 0; 
	z[i].cena.izlez = 0;	
	cout << "Edinecna cena na vlezna kolicina " << i + 1 << " artikal : ";
	cin >> z[i].cena.vlez; 
	while (!(proverka_Broj(z[i].cena.vlez, pole_edinCena))) {
		cout << "Invalid Input !!!" << endl;
		cout << "Edinecnata cena na vleznata kolicina treba da bide pomalku od " << pole_edinCena + 1 << " cifri !!!";
		cin >> z[i].cena.vlez;
	}
	cout << "Vlezna kolicina na " << i + 1 << " artikal : ";
	cin >> z[i].in; 
	while (!(proverka_Broj(z[i].in, pole_inOut))) {
		cout << "Invalid Input !!!" << endl;
		cout << "Vleznata kolicina treba da bide pomalku od " << pole_inOut + 1 << " broevi !!!" << endl;
		cin >> z[i].in;
	}
	z[i].out = 0; 
	z[i].iznos.vlez = z[i].in * z[i].cena.vlez; 
	z[i].iznos.izlez = 0;	
	cout << "Datum na vlez(GG\MM\DD) : ";
	cin >> z[i].date;	
	while ((!(proverka_Broj(z[i].date, pole_Date))) && (!(proverka_godina(z[i].date))) && (!(proverka_den(z[i].date))) && (!(proverka_mesec(z[i].date)))) {
		cout << "Invalid Input !!!" << endl;
		cout << "Vnesot na datata treba da bide vo format (GG/MM/DD) !!!!" << endl;
		cin >> z[i].date;
	}
}

/*VOID F-JA KOJA SE KORISTI ZA IZLEZ NA ARTIKAL VO MAGACINOT*/
void vnes_Izlez(struct Artikal z[], int n , int& redenbroj, int artikli) {
	/*PROVERKA DALI VNESENATA SIFRA POSTOI T.E. DALI IMA ARTIKAL SO TAA SIFRA*/
	if ((ima_sifra(z, n, artikli, redenbroj))) {
		int den;	
		int mesec;	
		int godina;	
		cout << "Pronajden e artikal so slednive zapisi : " << endl;
		cout << "Sifra : " << z[redenbroj].sifra << endl;
		cout << "Opis : " << z[redenbroj].opis << endl;
		cout << "Edinecna cena za vlez : " << z[redenbroj].cena.vlez << endl;
		cout << "Zaliha : " << fixed << setprecision(2) << z[redenbroj].in << endl;
		cout << "Izlezna kolicina : " << fixed << setprecision(2) << z[redenbroj].out << endl;
		cout << "Danocna stapka : " << fixed << setprecision(2)  << z[redenbroj].VAT << endl;
		den = z[redenbroj].date % 100;
		mesec = (z[redenbroj].date / 100) % 100;
		godina = z[redenbroj].date / 10000;
		if ((godina >= 0) && (godina <= 20)) {
			godina += 2000;
		}
		else if ((godina > 20) && (godina <= 99)) {
			godina += 1900;
		}
		cout << "Datum na vlez : " << godina << "/" << mesec << "/" << den << endl;
		cout << "Prodadeni se : "; 
		cin >> z[redenbroj].out; // VNESUVANJE KOLKU PRODUKTI SE PRODADENI
		while (z[redenbroj].out > z[redenbroj].in) {
			cout << "Nemate tolkava zaliha od toj artikal !!!" << endl;
			cout << "Vnesete povtorno izlez(vnesete 0 za da ostane nepromeneto) : ";
			cin >> z[redenbroj].out;
		}
		cout << "So danocna stapka : ";
		cin >> z[redenbroj].VAT; // VNES SO KOJA DANOCNA STAPKA SE PORDADENI
		while (!(proverka_Broj(z[redenbroj].VAT, pole_VAT))) {
			cout << "Invalid Input !!!" << endl;
			cout << "Danokot treba da bide pomalku od " << pole_VAT + 1 << " cifri !!!";
			cin >> z[redenbroj].VAT;
		}
		cout << "Vesete edinecna cena po koja se prodadeni : " << endl;
		cin >> z[redenbroj].cena.izlez;	// VNESUVANJE NA EDINECNA CENA PO KOJA SE IZLEZENI OD MAGACINOT
		while ((!(proverka_Broj(z[redenbroj].cena.izlez, pole_edinCena))) || (z[redenbroj].cena.izlez < (z[redenbroj].cena.vlez + z[redenbroj].VAT))) {
			cout << "Invalid Input !!!" << endl;
			if ((z[redenbroj].cena.izlez < (z[redenbroj].cena.vlez + z[redenbroj].VAT))) {
				cout << "Edinecnata cena na izleznata kolicina e premala !!!" << endl;
			}
			else {
				cout << "Edinecnata cena na vleznata kolicina treba da vide pomala od " << pole_edinCena + 1 << " cifri !!!" << endl;
			}
			cin >> z[redenbroj].cena.izlez;
		}
		z[redenbroj].in = z[redenbroj].in - z[redenbroj].out; // ODZEMANJE NA IZLEZOT OD ZALIHATA
		z[redenbroj].iznos.izlez = (z[redenbroj].cena.izlez - z[redenbroj].VAT) * z[redenbroj].out; // KALKULIRANJE NA IZNOSOT
	}
	/*SLUCAJ KOGA NEMAME ARTIKAL SO TAKVA SIFRA*/
	else {
		cout << "Ne e pronajden artikal so taa sifra !!!" << endl;
	}
}

/*VOID F-JA KOJA GI PODREDUVA ARTIKLITE PO SIFRA VO RASTECKI REDOSLED*/
void sort_Output(struct Artikal z[], int artikli){
	for (int i = 0; i < artikli; i++) {
		for (int j = i + 1; j < artikli; j++) {
			if (z[i].sifra < z[j].sifra) {
				struct Artikal p;
				p = z[j];
				z[j] = z[i];
				z[i] = p;
			}
		}
	}
}

/*VOID F-JA KOJA GI PODREDUVA ARTIKLITE VO MAGACINOT OD PONOVI KON POSTARI*/
void sort_OutputSorted(struct Artikal z[], int artikli, int den[] , int mesec[] , int godina[]) {
	/*RAZLOZUVANJE NA VNESENATA DATA ZA SEKOJ ARTIKAL*/
	for (int i = 0; i < artikli; i++) {
		den[i] = z[i].date % 100;
		mesec[i] = (z[i].date / 100) % 100;
		godina[i] = z[i].date / 10000;
		if ((godina[i] >= 0) && (godina[i] <= 20)) {
			godina[i] += 2000;
		}
		else if ((godina[i] > 20) && (godina[i] <= 99)) {
			godina[i] += 1900;
		}

	}
	/*PODREDUVANJE PO DATA*/
	for (int i = 0; i < artikli; i++) {
		for (int j = i + 1; j < artikli; j++) {
			/*PODREDUVANJE PO GODINA*/
			if (godina[i] < godina[j]) {
				struct Artikal pomosna;
				pomosna = z[j];
				z[j] = z[i];
				z[i] = pomosna;
			}
			/*PODREDUVANJE PO MESEC*/
			else if (godina[i] == godina[j]) {
				if (mesec[i] < mesec[j]) {
					struct Artikal pomosna1;
					pomosna1 = z[j];
					z[j] = z[i];
					z[i] = pomosna1;
				}
			}
			/*PODREDUVANJE PO DENOVI*/
			else if ((godina[i] == godina[j]) && (mesec[i] == mesec[j])) {
				if (den[i] < den[j]) {
					struct Artikal pomosna2;
					pomosna2 = z[j];
					z[j] = z[i];
					z[i] = pomosna2;
				}
			}
		}
	}
}

/*VOID F-JA ZA PECATENJE NA SIFRITE NA ARTIKLITE*/
void print_sifra(struct Artikal z[], int artikli ) {
	cout << "Vo magacinot se naogjaat slednive artikli : " << endl;
	for (int i = 0; i < artikli; i++) {
		cout << z[i].opis << " | Sifra : " << z[i].sifra << endl;
	}
}

/*FLOAT F-JA ZA PRESMETUVANJE NA IZNOSNIOT PRIHOD*/
float prihod_izons(struct Artikal z[], int artikli , int i ) {
	float prihod_iznos_izlez = 0;
	float prihod_iznos_vlez = 0;
	float prihod = 0;
	prihod_iznos_izlez += z[i].iznos.izlez;
	prihod_iznos_vlez += z[i].iznos.vlez;
	prihod = prihod_iznos_izlez - prihod_iznos_vlez;
	return prihod;
}

/*FLOAT F-JA ZA PRESMETUVANJE NA VKUPEN PRIHOD*/
float vkupen_prihod(struct Artikal z[], int artikli) {
	float vkupenprihod = 0; 
	for (int i = 0; i < artikli; i++) {
		if (z[i].VAT = 0) {
			vkupenprihod += 0;
		}
		else {
			vkupenprihod += prihod_izons(z, artikli, i);
		}
	}
	return vkupenprihod;
}

/*VOID F-JA ZA PECATENJE VO vnos.dat*/
void print_output(struct Artikal z[], int artikli, ofstream& izlez ) {
	int denovi[100];
	int meseci[100];		
	int godini[100];
	for (int i = 0; i < artikli; i++) {
		izlez << "Sifra : ";
		izlez << z[i].sifra << endl;
		izlez << "Opis : ";
		izlez << z[i].opis << endl;
		izlez << "Edinecna cena na vlezna kolicina : ";
		izlez << z[i].cena.vlez << fixed << setprecision(2) << endl;
		izlez << "Edinecna cena na izleza kolicina : ";
		izlez << z[i].cena.izlez << fixed << setprecision(2) << endl;
		izlez << "Vlezna Kolicina : ";
		izlez << z[i].in << endl;
		izlez << "Izlezna kolicina : ";
		izlez << z[i].out << endl;
		izlez << "Danocna stapka : ";
		izlez << z[i].VAT << fixed << setprecision(2) << endl;
		denovi[i] = z[i].date % 100;
		meseci[i] = (z[i].date / 100) % 100;
		godini[i] = z[i].date / 10000;
		if ((godini[i] >= 0) && (godini[i] <= 20)) {
			godini[i] += 2000;
		}
		else if ((godini[i] > 20) && (godini[i] <= 99)) {
			godini[i] += 1900;
		}
		izlez << godini[i] << "/" << meseci[i] << "/" << denovi[i] << endl;
		izlez << "--------------------------------------------------------" << endl;
		izlez << "--------------------------------------------------------" << endl;
	}
}

/*VOID F-JA ZA PECATENJE VO sort_vlez.dat*/
void print_output_sort(struct Artikal z[], int artikli, ofstream& izlez) {
	int denovi[100];
	int meseci[100];	
	int godini[100];
	for (int i = 0; i < artikli; i++) {
		izlez << "Sifra : ";
		izlez << z[i].sifra << endl;
		izlez << "Opis : ";
		izlez << z[i].opis << endl;
		izlez << "Edinecna cena na vlezna kolicina : ";
		izlez << z[i].cena.vlez << fixed << setprecision(2) << endl;
		izlez << "Edinecna cena na izleza kolicina : ";
		izlez << z[i].cena.izlez << fixed << setprecision(2) << endl;
		izlez << "Vlezna Kolicina : ";
		izlez << z[i].in << endl;
		izlez << "Izlezna kolicina : ";
		izlez << z[i].out << endl;
		izlez << "Danocna stapka : ";
		izlez << z[i].VAT << fixed << setprecision(2) << endl;
		denovi[i] = z[i].date % 100;
		meseci[i] = (z[i].date / 100) % 100;
		godini[i] = z[i].date / 10000;
		if ((godini[i] >= 0) && (godini[i] <= 20)) {
			godini[i] += 2000;
		}
		else if ((godini[i] > 20) && (godini[i] <= 99)) {
			godini[i] += 1900;
		}
		izlez << godini[i] << "/" << meseci[i] << "/" << denovi[i] << endl;
		izlez << "--------------------------------------------------------" << endl;
		izlez << "--------------------------------------------------------" << endl;
		izlez << "Prihodot ostvaren od ovoj product e : " << fixed << setprecision(2) << prihod_izons(z, artikli, i) << " den." << endl;
		izlez << "--------------------------------------------------------" << endl;
		izlez << "--------------------------------------------------------" << endl;
	}
}

/*VOID F-JA ZA PECATENJE NA PRIHOD NA MAGACINOT*/
void print_Prihod(struct Artikal z[], int artikli, ofstream& print) {
	print << "Vkupniot prihod na magacinot e : " << endl;
	print << vkupen_prihod(z, artikli) << " den." << endl;
}

int main()
{ 
	ofstream output, output_sort; 
	output.open("vnos.txt");		
	output_sort.open("sort_vlez.txt");
	struct Artikal a[100];		
	int br_artikli;				
	char izbor;					
	int reden_broj;			
	int sifra_promena;		
	int year[100];			
	int month[100];			
	int day[100];			
	float prihod_vlez = 0;	
	float prihod_izlez = 0;		
	float prihod = 0;		
	/*PROVERKA DALI FAJLOVITE SE OTVORENI*/
	if (!(output.is_open()) || !(output_sort.is_open())){
		cout << "Datotekite ne mozea da bide otvorena !!" << endl;
	}
	else {
		cout << "Vnesete broj na kolku artikli kje vnesete (max dozvoleno artikli e 100) : ";
		cin >> br_artikli;	
		while ((br_artikli < 0) || (br_artikli > 100)) {
			cout << "Pogresen vnes" << endl;
			cout << "Vnesete broj na kolku artikli kje vnesete (max dozvoleno artikli e 100) : ";
			cin >> br_artikli;
		} 
		cout << "Pocnete so vnesuvanje na artiklite : " << endl;
		for (int i = 0; i < br_artikli; i++) {
				vnes_Vlez(a, i);	// VNES NA ARTIKLITE
		}
		Sleep(800);				
		system("CLS");		
		cout << "Dali imalo prodazba za odreden artikal ? (y/n) ";
		cin >> izbor;			
		while ((izbor != 'n') && (izbor != 'N') && (izbor != 'y') && (izbor != 'Y')) {
			Sleep(800);
			system("CLS");
			cout << "Invalid Input !!!" << endl;
			cout << "Vnesete edna od ponudenite opcii : (y/n)" << endl;
			cin >> izbor;
		}
		while ((izbor == 'y') || (izbor == 'Y')) {
			Sleep(800);
			system("CLS");
			print_sifra(a, br_artikli); 
			cout << "--------------------------------------------------------" << endl;
			cout << "--------------------------------------------------------" << endl;
			cout << "Vnesete sifra na artikalot : ";
			cin >> sifra_promena;
			vnes_Izlez(a, sifra_promena, reden_broj, br_artikli);
			cout << "--------------------------------------------------------" << endl;
			cout << "--------------------------------------------------------" << endl;
			cout << "Dali sakate da vnesuvate za drug artikal ? (y/n) " << endl;
			cin >> izbor;	
			while ((izbor != 'n') && (izbor != 'N') && (izbor != 'y') && (izbor != 'Y')) {
				cout << "Invalid Input !!!" << endl;
				cout << "Vnesete edna od ponudenite opcii : (y/n)" << endl;
				cin >> izbor;
			}
		}
			sort_Output(a, br_artikli);		
			print_output(a, br_artikli, output);	
			sort_OutputSorted(a, br_artikli, day, month, year);	
			print_output_sort(a, br_artikli, output_sort);	
			print_Prihod(a, br_artikli, output_sort);			
		}
		
	output.close();
	output_sort.close();
	system("pause");
	return 0;
}
