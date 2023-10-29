#include<iostream>

using namespace std;

//Cele 3 obiecte sunt imprimanta, tableta si laptop. Domeniul este depozit.

class Frigider;
class Tableta;

class Imprimanta {
private:
	const int codProducator;
	static string format;
	int capacitate;
	string marca;
	float greutate;
	int imprimari;
	int* nrPaginiImprimare;

public:
	void afisareImprimanta() {
		cout << "Imprimanta " << this->marca << " are o capacitate de " << this->capacitate << " coli de tipul " << this->format << " si o greutate de " << this->greutate << " kg."<< "Acesta a imprimat de "<<this->imprimari<<" de ori. " << endl;

		if (this->imprimari) {
			cout << "Numarul de pagini per imprimare: ";
			for (int i = 0;i < this->imprimari; i++)
				cout << this->nrPaginiImprimare[i];
		}
	}

	int getCodProducator() const {
		return codProducator;
	}

	static string getFormat() {
		return Imprimanta::format;
	}

	int getCapacitate() {
		return this->capacitate;
	}

	string getMarca() {
		return this->marca;
	}

	float getGreutate() {
		return this->greutate;
	}

	int getImprimari() {
		return this->imprimari;
	}

	static void setFormat(string format) {
		Imprimanta::format = format;
	}

	int ImprimaPagini(int paginiImprimate) {

		int nrTotalPagini = 0;
		int* aux = new int[this->imprimari + 1];
		for (int i = 0; i < this->imprimari; i++) {
			aux[i] = this->nrPaginiImprimare[i];
			nrTotalPagini += this->nrPaginiImprimare[i];
		}
		if (paginiImprimate == 0) return nrTotalPagini;
		aux[this->imprimari] = paginiImprimate;
		delete[] this->nrPaginiImprimare;
		this->nrPaginiImprimare = aux;
		nrTotalPagini += paginiImprimate;
		this->imprimari++;

		return nrTotalPagini;

	}

	int* getPaginiImprimate() {
		return nrPaginiImprimare;
	}

	void setCapacitate(int capacitate) {
		this->capacitate = capacitate;
	}

	void setMarca(string marca) {
		this->marca = marca;
	}

	void setGreutate(float greutate) {
		this->greutate = greutate;
	}

	void setNrPaginiImprimate(int imprimari, int* nrPaginiImprimare) {
		if (imprimari != 0) {
			this->imprimari = imprimari;
			if(this->nrPaginiImprimare != nullptr)
				delete[] this->nrPaginiImprimare;
			this->nrPaginiImprimare = new int[imprimari];
			for (int i = 0; i < this->imprimari; i++)
				this->nrPaginiImprimare[i] = nrPaginiImprimare[i];
		
		}

	}

	Imprimanta(const Imprimanta& imprimanta) :codProducator(imprimanta.codProducator) {
		this->capacitate = imprimanta.capacitate;
		this->marca = imprimanta.marca;
		this->greutate = imprimanta.greutate;
		this->imprimari = imprimanta.imprimari;
		this->nrPaginiImprimare = imprimanta.nrPaginiImprimare;
	}

	Imprimanta() :codProducator(3745) {
		this->capacitate = 60;
		this->marca = "Canon";
		this->greutate = 3.9;
		this->imprimari = 0;
		this->nrPaginiImprimare = nullptr;
	}

	Imprimanta(int capacitate, string marca, float greutate, int* nrPaginiImprimate) :codProducator(3745) {
		this->capacitate = capacitate;
		this->marca = marca;
		this->greutate = greutate;
		this->imprimari = 0;
		this->nrPaginiImprimare = nullptr;
	}

	Imprimanta(int capacitate, string marca) :codProducator(3745) {
		this->capacitate = capacitate;
		this->marca = marca;
		this->greutate = 3.9;
		this->imprimari = 0;
		this->nrPaginiImprimare = nullptr;
	}

	~Imprimanta() {
		delete[]this->nrPaginiImprimare;
	}

	friend void verificaGarantie(Imprimanta &imprimanta, Frigider& frigider);
	friend void verificaFunctionalitate(Imprimanta &imprimanta, Tableta &tableta);
};

string Imprimanta::format = "A4";

class Imprimanta;
class Tableta {
private:
	static string conexiune;
	const int codProdus;
	int memorieRAM;
	string sistemDeOperare;
	float grosime;
	int* listaAplicatii;
	int nrAplicatii;
	bool SIM;

public:
	void afisareTableta() {
		cout << "Tableta cu sistemul de operare " << this->sistemDeOperare << " cu o memorie de " << this->memorieRAM << " GB si cu o grosime de " << this->grosime << " mm are o conexiune de tipul " << conexiune << " ." << " Are un numar de " << this->nrAplicatii << " aplicatii." << endl;

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

	static string getConexiune() {
		return Tableta::conexiune;
	}

	int getCodProdus() const {
		return codProdus;
	}

	int getMemorie() {
		return this->memorieRAM;
	}

	string getSistemDeOperare() {
		return this->sistemDeOperare;
	}

	float getGrosime() {
		return this->grosime;
	}

	int getNrAplicatii() {
		return this->nrAplicatii;
	}

	void setMemorie(int memorieRAM) {
		this->memorieRAM = memorieRAM;
	}

	void setSistemDeOperare(string sistemDeOperare) {
		this->sistemDeOperare = sistemDeOperare;
	}

	void setGrosime(float grosime) {
		this->grosime = grosime;
	}

	void setNrAplicatii(int nrAplicatii) {
		this->nrAplicatii = nrAplicatii;
	}

	static void setConexiune(string conexiune) {
		Tableta::conexiune = conexiune;
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

	Tableta(const Tableta& tableta) :codProdus(tableta.codProdus) {
		this->memorieRAM = tableta.memorieRAM;
		this->sistemDeOperare = tableta.sistemDeOperare;
		this->grosime = tableta.grosime;
		this->SIM = tableta.SIM;
		this->nrAplicatii = tableta.nrAplicatii;
		this->listaAplicatii = tableta.listaAplicatii;
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

	friend void verificaFunctionalitate(Imprimanta &imprimanta, Tableta &tableta);
};

string Tableta::conexiune = "Wifi";

class Frigider {
private:
	static string materialRafturi;
	const int volum;
	float adancime;
	int nrRafturi;
	string culoare;
	int* temperaturaRafturi;

public:
	void afisareFrigider() {
		cout << "Frigiderul de culoare " << this->culoare << " are o adancime de " << this->adancime << " cm, are " << this->nrRafturi << " rafturi"<<endl;
		if (this->nrRafturi) {
			cout << "Temperaturile de pe rafturi sunt: ";
			for (int i = 0; i < this->nrRafturi; i++)
				cout << this->temperaturaRafturi[i] << " ";
		}
		cout << " si are rafturile din " << materialRafturi << "." << endl;
	}

	static string getMaterialRafturi() {
		return Frigider::materialRafturi;
	}

	int getVolum() const {
		return volum;
	}

	float getAdancime() {
		return this->adancime;
	}

	float getnrRafturi() {
		return this->nrRafturi;
	}

	string getCuloare() {
		return this->culoare;
	}

	void setAdancime(float adancime) {
		this->adancime = adancime;
	}

	void setNrRafturi(int nrRafturi) {
		this->nrRafturi = nrRafturi;
	}

	void setCuloare(string culoare) {
		this->culoare = culoare;
	}

	static void setMaterialRafturi(string materialRafturi) {
		Frigider::materialRafturi = materialRafturi;
	}

	void setTemperatura(int nrRaft, int temp) {
		if (nrRaft <= this->nrRafturi)
			this->temperaturaRafturi[nrRaft] = temp;
	}

	int* getTemperatura() {
		return this->temperaturaRafturi;
	}

	Frigider(const Frigider& frigider) :volum(frigider.volum) {
		this->adancime = frigider.adancime;
		this->nrRafturi = frigider.nrRafturi;
		this->culoare = frigider.culoare;
		this->temperaturaRafturi = new int[this->nrRafturi];
		for (int i = 0; i < this->nrRafturi; i++)
			this->temperaturaRafturi[i] = frigider.temperaturaRafturi[i];
	}

	Frigider() : volum(41) {
		this->adancime = 54.2;
		this->nrRafturi = 3;
		this->culoare = "gri";
		this->temperaturaRafturi = new int[this->nrRafturi];
		for (int i = 0; i < this->nrRafturi; i++)
			this->temperaturaRafturi[i] = 0;
	}

	Frigider(string culoare, int nrRafturi) : volum(41) {
		this->adancime = 54.2;
		this->nrRafturi = nrRafturi;
		this->culoare = culoare;
		this->temperaturaRafturi = new int[this->nrRafturi];
		for (int i = 0; i < this->nrRafturi; i++)
			this->temperaturaRafturi[i] = 0;
	}

	Frigider(string culoare, int nrRafturi, float adancime, int* temperaturaRafturi) : volum(41) {
		this->adancime = adancime;
		this->nrRafturi = nrRafturi;
		this->culoare = culoare;
		this->temperaturaRafturi = new int[this->nrRafturi];
		for (int i = 0; i < this->nrRafturi; i++)
			this->temperaturaRafturi[i] = temperaturaRafturi[i];
	}

	~Frigider() {
		delete[]this->temperaturaRafturi;
	}

	friend void verificaGarantie(Imprimanta &imprimanta, Frigider &frigider);
};

string Frigider::materialRafturi = "Sticla";

void verificaGarantie(Imprimanta& imprimanta, Frigider &frigider) {
	if ((imprimanta.imprimari) != 0 && frigider.temperaturaRafturi != 0) {
		std::cout << "Garantia pentru Imprimanta si Frigider este valabila." << std::endl;
	}
	else {
		std::cout << "Garantia pentru Imprimanta si Frigider nu este valabila." << std::endl;
	}
}

void verificaFunctionalitate(Imprimanta& imprimanta, Tableta& tableta) {
	if (imprimanta.ImprimaPagini(0) > imprimanta.getCapacitate() && tableta.getNrAplicatii() > 1) {
		cout << "Functionalitatea Imprimantei si Tabletei este verificata si este in regula." << endl;
	}
	else {
		cout << "Imprimanta sau Tableta nu este functionala. Verificati capacitatea imprimantei si numarul de aplicatii al tabletei." << endl;
	}
}

void main() {
	Imprimanta imprimanta;
	imprimanta.afisareImprimanta();
	Imprimanta imprimanta1(80, "Canon", 3.9, 0);
	imprimanta1.afisareImprimanta();
	Imprimanta imprimanta2(60, "HP");
	imprimanta2.afisareImprimanta();

	int nrPaginiImprimate = 0;
	imprimanta.ImprimaPagini(5);
	imprimanta.ImprimaPagini(5);
	cout << "Numarul total de pagini imprimate: " << imprimanta.ImprimaPagini(0) << endl;

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
	int* temperaturirafturi = new int[3] {3, 1, 4};
	Frigider frigider1("gri", 3, 54.7, temperaturirafturi);
	frigider1.afisareFrigider();

	frigider1.setTemperatura(1, 4);
	int* temperaturaRafturiFrigider1 = frigider1.getTemperatura();

	cout << "Temperatura initiala a frigiderului: " << *frigider1.getTemperatura() << " grade Celsius" << endl;

	frigider1.setTemperatura(1, 7);

	for (int i = 0; i < frigider1.getnrRafturi(); i++)
		cout << "Temperatura actualizata a frigiderului: " << frigider1.getTemperatura()[i] << " grade Celsius" << endl;

	//Faza 2
	cout << endl;
	Imprimanta imprimanta3;
	imprimanta3.setCapacitate(50);
	cout << "Capacitatea imprimantei: " << imprimanta3.getCapacitate() << " coli." << endl;
	imprimanta3.setMarca("Canon");
	cout << "Marca imprimantei: " << imprimanta3.getMarca() << endl;
	imprimanta3.setGreutate(4.3);
	cout << "Greutatea imprimantei: " << imprimanta3.getGreutate() << endl;
	imprimanta3.ImprimaPagini(11);
	cout << "Numarul total de pagini imprimate: " << imprimanta3.ImprimaPagini(0) << endl;
	imprimanta3.setFormat("A4");
	cout << "Formatul este: " << imprimanta3.getFormat() << endl;
	cout << "Codul producatorului este: " << imprimanta3.getCodProducator();
	cout << endl;
	Imprimanta imprimanta4 = imprimanta2;
	imprimanta2.afisareImprimanta();

	cout << endl;
	Tableta tableta4;
	tableta4.setMemorie(8);
	cout << "Memoria tabletei: " << tableta4.getMemorie() << endl;
	tableta4.setGrosime(7.85);
	cout << "Grosimea tabletei: " << tableta4.getGrosime() << endl;
	tableta4.setSistemDeOperare("iOS");
	cout << "Sistemul de operare al tabletei: " << tableta4.getSistemDeOperare() << endl;
	tableta4.setConexiune("Wifi");
	cout << "Conexiune se realizeaza prin: " << tableta4.getConexiune() << endl;
	cout << "Codul produsului este: " << tableta4.getCodProdus() << endl;
	Tableta tableta7 = tableta3;
	tableta7.afisareTableta();
	cout << endl;

	cout << endl;
	Frigider frigider55;
	Frigider frigider2 = frigider55;
	frigider2.setCuloare("Alb");
	cout << "Culoarea frigiderului este: " << frigider2.getCuloare() << endl;
	frigider2.setNrRafturi(7);
	cout << "Frigiderul are un numar de " << frigider2.getnrRafturi() << " rafturi." << endl;
	frigider2.setAdancime(45.6);
	cout << "Frigiderul are o adancime de " << frigider2.getAdancime() << endl;
	frigider2.getMaterialRafturi();
	cout << "Rafturile sunt din: " << frigider2.getMaterialRafturi() << endl;
	cout << "Volumul frigiderului este de: " << frigider2.getVolum();

	cout << endl;

	imprimanta.ImprimaPagini(100);
	frigider.setTemperatura(1, 4); 
	cout << endl;
	verificaGarantie(imprimanta, frigider);

	verificaFunctionalitate(imprimanta, tableta);

}