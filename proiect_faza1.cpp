#include<iostream>

using namespace std;

//Cele 3 obiecte sunt imprimanta, tableta si laptop. Domeniul este depozit.

class Imprimanta {
public:
	const int codProducator;
	static string format;
	int capacitate;
	string marca;
	float greutate;
	int* nrPaginiImprimate;

	void afisareImprimanta() {
		cout << "Imprimanta " << marca << " are o capacitate de " << capacitate << " coli de tipul " << format << " si o greutate de " << greutate << " kg." << endl;
	}

	void ImprimaPagina(int paginiImprimate, int* pointerNrPaginiImprimate) {
		*pointerNrPaginiImprimate += paginiImprimate;
	}
	int getPaginiImprimate() {
		return *nrPaginiImprimate;
	}

	Imprimanta() :codProducator(3745) {
		this->capacitate = 60;
		this->marca = "Canon";
		this->greutate = 3.9;
		this->nrPaginiImprimate = 0;
	}

	Imprimanta(int capacitate, string marca, float greutate, int* nrPaginiImprimate) :codProducator(3745) {
		this->capacitate = capacitate;
		this->marca = marca;
		this->greutate = greutate;
		this->nrPaginiImprimate = 0;
	}

	Imprimanta(int capacitate, string marca) :codProducator(3745) {
		this->capacitate = capacitate;
		this->marca = marca;
		this->greutate = 3.9;
		this->nrPaginiImprimate = 0;
	}

	~Imprimanta() {

	}
};

string Imprimanta::format = "A4";

class Tableta {
public:
	static string conexiune;
	const int codProdus;
	int memorieRAM;
	string sistemDeOperare;
	float grosime;
	int* listaAplicatii;
	int nrAplicatii;
	bool SIM;

	void afisareTableta() {
		cout << "Tableta cu sistemul de operare " << sistemDeOperare << " cu o memorie de " << memorieRAM << " GB si cu o grosime de " << grosime << " mm are o conexiune de tipul " << conexiune << " ." << " Are un numar de " << nrAplicatii << " aplicatii." << endl;

		if (this->nrAplicatii) {
			cout << "Tableta are " << this->nrAplicatii << " aplicatii." << endl << " Aplicatiile au id-urile: ";
			for (int i = 0; i < this->nrAplicatii; i++)
				cout << this->listaAplicatii[i] << " ";
			cout << endl;
			cout << endl;
		}
		else
			cout << "Nu are aplicatii.";
	}

	void adaugaAplicatie(int aplicatie) {
		int* aux = new int[this->nrAplicatii + 1];
		for (int i = 0; i < this->nrAplicatii; i++)
			aux[i] = this->listaAplicatii[i];
		aux[nrAplicatii] = aplicatie;
		delete[] this->listaAplicatii;
		this->listaAplicatii = aux;
		this->nrAplicatii++;
	}

	void modificaRAM(int nouaMemorieRam) {
		this->memorieRAM = nouaMemorieRam;
	}

	Tableta(int memorieRAM, string sistemDeOperare) :codProdus(115) {
		this->memorieRAM = memorieRAM;
		this->sistemDeOperare = sistemDeOperare;
		this->grosime = 8.95;
		this->SIM = true;
		this->nrAplicatii = 0;
		this->listaAplicatii = nullptr;
	}

	Tableta(float grosime, string sistemDeOperare, int nrAplicatii, int* listaAplicatii) :codProdus(115) {
		this->memorieRAM = 4;
		this->sistemDeOperare = sistemDeOperare;
		this->grosime = grosime;
		this->SIM = true;
		this->nrAplicatii = nrAplicatii;
		this->listaAplicatii = listaAplicatii;
	}

	Tableta() :codProdus(115) {
		this->memorieRAM = 4;
		this->sistemDeOperare = "Android";
		this->grosime = 8.95;
		this->SIM = true;
		this->nrAplicatii = 0;
		this->listaAplicatii = nullptr;
	}

	~Tableta() {

	}

};

string Tableta::conexiune = "Wifi";

class Frigider {
public:
	static string materialRafturi;
	const int volum;
	float adancime;
	int nrRafturi;
	string culoare;
	int* temperatura;

	void afisareFrigider() {
		cout << "Frigiderul de culoare " << culoare << " are o adancime de " << adancime << " cm, are " << nrRafturi << " rafturi";
		if (temperatura != nullptr) {
			cout << ", o temperatura de " << *temperatura << " grade Celsius";
		}
		cout << " si are rafturile din " << materialRafturi << "." << endl;
	}

	void setTemperatura(int temp) {
		this->temperatura = new int{ temp };
	}

	int* getTemperatura() {
		return this->temperatura;
	}

	Frigider() : volum(41) {
		this->adancime = 54.2;
		this->nrRafturi = 3;
		this->culoare = "gri";
		this->temperatura = new int{ 0 };
	}

	Frigider(string culoare, int nrRafturi) : volum(41) {
		this->adancime = 54.2;
		this->nrRafturi = nrRafturi;
		this->culoare = culoare;
		this->temperatura = new int{ 0 };
	}

	Frigider(string culoare, int nrRafturi, float adancime, int* temperatura) : volum(41) {
		this->adancime = adancime;
		this->nrRafturi = nrRafturi;
		this->culoare = culoare;
		this->temperatura = new int;
		this->temperatura = temperatura;
	}

	~Frigider() {
		delete temperatura;
	}
};


string Frigider::materialRafturi = "Sticla";

void main() {
	Imprimanta imprimanta;
	imprimanta.afisareImprimanta();
	Imprimanta imprimanta1(80, "Canon", 3.9, 0);
	imprimanta1.afisareImprimanta();
	Imprimanta imprimanta2(60, "HP");
	imprimanta2.afisareImprimanta();

	int nrPaginiImprimate = 0;
	imprimanta.ImprimaPagina(5, &nrPaginiImprimate);
	imprimanta.ImprimaPagina(5, &nrPaginiImprimate);
	cout << "Numarul total de pagini imprimate: " << nrPaginiImprimate << endl;

	cout << endl;

	Tableta tableta;
	tableta.afisareTableta();
	int listaAplicatii1[] = { 31,57,45 };
	Tableta tableta1(8, "Android", 3, listaAplicatii1);
	tableta1.afisareTableta();
	Tableta tableta3(7.0f, "iOS");
	tableta3.afisareTableta();

	cout << endl;
	cout << endl;

	Frigider frigider;
	frigider.afisareFrigider();
	Frigider frigider1("gri", 3, 54.7, 0);
	frigider1.afisareFrigider();

	frigider1.setTemperatura(4);
	int* temperaturaFrigider1 = frigider1.getTemperatura();

	cout << "Temperatura initiala a frigiderului: " << *frigider1.getTemperatura() << " grade Celsius" << endl;

	frigider1.setTemperatura(7);

	cout << "Temperatura actualizata a frigiderului: " << *frigider1.getTemperatura() << " grade Celsius" << endl;


}