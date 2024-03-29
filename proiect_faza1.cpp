#include<iostream>
#include<fstream>

using namespace std;

//Cele 3 obiecte sunt imprimanta, tableta si laptop. Domeniul este depozit.

class AbstractA {
public:
	virtual void metodaAbstractaA() = 0;
};

class AbstractB {
public:
	virtual void metodaAbstractaB() = 0;
};


class Frigider;
class Tableta;

class Imprimanta: public AbstractA, public AbstractB {
private:
	const int codProducator;
	static string format;
	int capacitate;
	string marca;
	float greutate;
	int imprimari;
	int* nrPaginiImprimare;

public:
	void metodaAbstractaA() {
		cout << "Imprimanta " << this->marca << " are o capacitate de " << this->capacitate << " coli." << endl;
	}

	void metodaAbstractaB() {
		cout << "Imprimanta " << this->marca << " are o capacitate de " << this->capacitate << " coli." << endl;
	}

	void afisareImprimanta() {
		cout << "Imprimanta " << this->marca << " are o capacitate de " << this->capacitate << " coli de tipul " << this->format << " si o greutate de " << this->greutate << " kg." << "Acesta a imprimat de " << this->imprimari << " de ori. " << endl;

		if (this->imprimari) {
			cout << "Numarul de pagini per imprimare: ";
			for (int i = 0; i < this->imprimari; i++)
				cout << this->nrPaginiImprimare[i]<<" ";
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
			if (this->nrPaginiImprimare != nullptr)
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
		this->greutate = 3.9f;
		this->imprimari = 0;
		this->nrPaginiImprimare = nullptr;
	}

	~Imprimanta() {
		delete[]this->nrPaginiImprimare;
	}

	friend void verificaGarantie(Imprimanta& imprimanta, Frigider& frigider);
	friend void verificaFunctionalitate(Imprimanta& imprimanta, Tableta& tableta);

	const Imprimanta& operator= (const Imprimanta& imprimanta) {
		if (this != &imprimanta) {
			if (this->nrPaginiImprimare != NULL)
				delete[]this->nrPaginiImprimare;
			this->capacitate = imprimanta.capacitate;
			this->marca = imprimanta.marca;
			this->greutate = imprimanta.greutate;
			this->imprimari = imprimanta.imprimari;
			this->nrPaginiImprimare = imprimanta.nrPaginiImprimare;
		}
		return *this;
	}

	Imprimanta operator+ (int valoare) {
		Imprimanta aux = *this;
		aux.capacitate = this->capacitate + valoare;
		return aux;
	}

	Imprimanta operator- (float valoare) {
		Imprimanta aux = *this;
		aux.greutate = this->greutate - valoare;
		return aux;
	}

	friend ostream& operator<<(ostream& out, const Imprimanta& imprimanta);

	friend istream& operator>>(istream& in, Imprimanta& imprimanta);

	friend ofstream& operator<<(ofstream& out, Imprimanta& imprimanta);

	friend ifstream& operator>>(ifstream& in, Imprimanta& imprimanta);

};
string Imprimanta::format = "A4";

istream& operator>>(istream& in, Imprimanta& imprimanta)
{
	cout << "Marca:";
	in >> imprimanta.marca;
	cout << "\Capacitate:";
	in >> imprimanta.capacitate;
	cout << "\Greutate:";
	in >> imprimanta.greutate;
	cout << "\nAceasta a imprimat de:";
	in >> imprimanta.imprimari;
	if (imprimanta.nrPaginiImprimare != NULL)
	{
		delete[]imprimanta.nrPaginiImprimare;
	}
	imprimanta.nrPaginiImprimare = new int[imprimanta.imprimari];
	for (int i = 0; i < imprimanta.imprimari; i++)
	{
		cout << "\nNumarul de pagini per imprimarea: " << (i + 1) << " : ";
		in >> imprimanta.nrPaginiImprimare[i];

	}
	return in;
}

ostream& operator<<(ostream& out, const Imprimanta& imprimanta) {
	out << "Imprimanta " << imprimanta.marca << " are o capacitate de " << imprimanta.capacitate << " si o greutate de " << imprimanta.greutate << " kg." << "Acesta a imprimat de " << imprimanta.imprimari << " de ori. " << endl;

	if (imprimanta.imprimari) {
		out << "Numarul de pagini per imprimare: ";
		for (int i = 0; i < imprimanta.imprimari; i++)
			out << imprimanta.nrPaginiImprimare[i]<<" ";
	}
	out << endl;
	return out;
}

ifstream& operator>>(ifstream& in, Imprimanta& imprimanta)
{
	in >> imprimanta.marca;
	in >> imprimanta.capacitate;
	in >> imprimanta.greutate;
	in >> imprimanta.imprimari;
	if (imprimanta.nrPaginiImprimare != NULL)
	{
		delete[]imprimanta.nrPaginiImprimare;
	}
	imprimanta.nrPaginiImprimare = new int[imprimanta.imprimari];
	for (int i = 0; i < imprimanta.imprimari; i++)
	{
		in >> imprimanta.nrPaginiImprimare[i];
	}
	return in;
}

ofstream& operator<<(ofstream& out, Imprimanta& imprimanta) {
	out << imprimanta.marca <<"\n"<< imprimanta.capacitate <<"\n" << imprimanta.greutate << "\n"<< imprimanta.imprimari << "\n" ;
	if (imprimanta.imprimari) {
		for (int i = 0; i < imprimanta.imprimari; i++)
			out << imprimanta.nrPaginiImprimare[i]<<" ";
	}
	return out;
}

class Imprimanta;
class Tableta: public AbstractA, public AbstractB {
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
	void metodaAbstractaA() {
		cout << "Tableta cu sistemul de operare " << this->sistemDeOperare << " are o memorie de " << this->memorieRAM << " GB." << endl;
	}

	void metodaAbstractaB() {
		cout << "Tableta cu sistemul de operare " << this->sistemDeOperare << " are o memorie de " << this->memorieRAM << " GB." << endl;
	}

	void afisareTableta() {
		cout << "Tableta cu sistemul de operare " << this->sistemDeOperare << " cu o memorie de " << this->memorieRAM << " GB si cu o grosime de " << this->grosime << " mm are o conexiune de tipul " << conexiune << " ." << " Are un numar de " << this->nrAplicatii << " aplicatii." << endl;

		if (this->nrAplicatii) {
			cout << "Tableta are " << this->nrAplicatii << " aplicatii." << endl << "Aplicatiile au id-urile: ";
			for (int i = 0; i < this->nrAplicatii; i++)
				cout << this->listaAplicatii[i] << " ";
			cout << endl;
			cout << endl;
		}
		else
			cout << "Nu are aplicatii." << endl;
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
		this->grosime = 8.95f;
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
		this->grosime = 8.95f;
		this->SIM = true;
		this->nrAplicatii = 0;
		this->listaAplicatii = nullptr;
	}

	~Tableta() {

	}

	friend void verificaFunctionalitate(Imprimanta& imprimanta, Tableta& tableta);

	const Tableta& operator= (const Tableta& tableta) {
		if (this != &tableta) {
			if (this->listaAplicatii != NULL)
				delete[]this->listaAplicatii;
			this->memorieRAM = tableta.memorieRAM;
			this->sistemDeOperare = tableta.sistemDeOperare;
			this->grosime = tableta.grosime;
			this->SIM = tableta.SIM;
			this->nrAplicatii = tableta.nrAplicatii;
			this->listaAplicatii = tableta.listaAplicatii;
		}
		return *this;
	}

	Tableta operator++() {
		this->memorieRAM++;
		return *this;
	}

	Tableta operator++(int) {
		Tableta stareInitiala = *this;
		this->memorieRAM++;
		return stareInitiala;
	}

	friend ostream& operator<<(ostream& out, Tableta tableta);

	friend istream& operator>>(istream& in, Tableta& tableta);

	friend ofstream& operator<<(ofstream& out, Tableta& tableta);

	friend ifstream& operator>>(ifstream& in, Tableta& tableta);

	int operator[](int index) {
		if (index >= 0 && index < nrAplicatii) {
			return listaAplicatii[index];
		}
	}

};
string Tableta::conexiune = "Wifi";

ostream& operator<<(ostream& out, Tableta tableta) {
	out << "Tableta cu sistemul de operare " << tableta.sistemDeOperare << " are o memorie de " << tableta.memorieRAM << " GB si o grosime de " << tableta.grosime << " mm." << " Are un numar de " << tableta.nrAplicatii << " aplicatii." << endl;

	if (tableta.nrAplicatii) {
		out << "Tableta are " << tableta.nrAplicatii << " aplicatii." << endl << "Aplicatiile au id-urile: ";
		for (int i = 0; i < tableta.nrAplicatii; i++)
			out << tableta.listaAplicatii[i] << " ";
		out << endl;
		out << endl;
	}
	else
		out << "Nu are aplicatii." << endl;
	return out;
}

istream& operator>>(istream& in, Tableta& tableta)
{
	cout << "Sistem de operare:";
	in >> tableta.sistemDeOperare;
	cout << "\Memorie:";
	in >> tableta.memorieRAM;
	cout << "\Grosime:";
	in >> tableta.grosime;
	cout << "\nNumar aplicatii:";
	in >> tableta.nrAplicatii;
	if (tableta.listaAplicatii != NULL)
	{
		delete[]tableta.listaAplicatii;
	}
	tableta.listaAplicatii = new int[tableta.nrAplicatii];
	for (int i = 0; i < tableta.nrAplicatii; i++)
	{
		cout << "\nID-ul aplicatiei: " << (i + 1) << " : ";
		in >> tableta.listaAplicatii[i];

	}
	return in;
}

ofstream& operator<<(ofstream& out, Tableta& tableta) {
	out << tableta.sistemDeOperare << "\n" << tableta.memorieRAM << "\n" << tableta.grosime << "\n" << tableta.nrAplicatii <<"\n";
	if (tableta.nrAplicatii) {
		out << tableta.nrAplicatii << "\n";
		for (int i = 0; i < tableta.nrAplicatii; i++)
			out << tableta.listaAplicatii[i] << " ";
	}
	return out;
}

ifstream& operator>>(ifstream& in, Tableta& tableta) {
	in >> tableta.sistemDeOperare;
	in >> tableta.memorieRAM;
	in >> tableta.grosime;
	in >> tableta.nrAplicatii;
	if (tableta.listaAplicatii != NULL)
	{
		delete[]tableta.listaAplicatii;
	}
	tableta.listaAplicatii = new int[tableta.nrAplicatii];
	for (int i = 0; i < tableta.nrAplicatii; i++)
	{
		in >> tableta.listaAplicatii[i];
	}
	return in;
}

class Frigider: public AbstractA, public AbstractB {
private:
	static string materialRafturi;
	const int volum;
	float adancime;
	int nrRafturi;
	string culoare;
	int* temperaturaRafturi;

public:
	void metodaAbstractaA() {
		cout << "Frigiderul de culoare " << this->culoare << " are o adancime de " << this->adancime << " cm." << endl;
	}

	void metodaAbstractaB() {
		cout << "Frigiderul de culoare " << this->culoare << " are o adancime de " << this->adancime << " cm." << endl;
	}

	void afisareFrigider() {
		cout << "Frigiderul de culoare " << this->culoare << " are o adancime de " << this->adancime << " cm, are " << this->nrRafturi << " rafturi" << endl;
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
		this->adancime = 54.2f;
		this->nrRafturi = 3;
		this->culoare = "gri";
		this->temperaturaRafturi = new int[this->nrRafturi];
		for (int i = 0; i < this->nrRafturi; i++)
			this->temperaturaRafturi[i] = 0;
	}

	Frigider(string culoare, int nrRafturi) : volum(41) {
		this->adancime = 54.2f;
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

	friend void verificaGarantie(Imprimanta& imprimanta, Frigider& frigider);

	const Frigider& operator= (const Frigider& frigider) {
		if (this != &frigider) {
			if (this->temperaturaRafturi != NULL)
				delete[]this->temperaturaRafturi;
			this->adancime = frigider.adancime;
			this->nrRafturi = frigider.nrRafturi;
			this->culoare = frigider.culoare;
			this->temperaturaRafturi = new int[this->nrRafturi];
			for (int i = 0; i < this->nrRafturi; i++)
				this->temperaturaRafturi[i] = frigider.temperaturaRafturi[i];
		}
		return *this;
	}

	friend ostream& operator<<(ostream& out, Frigider frigider);

	friend istream& operator>>(istream& in, Frigider& frigider);

	friend ofstream& operator<<(ofstream& out, Frigider& frigider);

	friend ifstream& operator>>(ifstream& in, Frigider& frigider);

	Frigider* operator->() {
		this->nrRafturi = 5;
		return this;
	}

	Frigider operator--() {
		this->adancime--;
		return *this;
	}

	void scriereInFisBinFrigider(fstream& f) {
		f.write((char*)&this->adancime, sizeof(float));
		f.write((char*)&this->nrRafturi, sizeof(int));

		int lungime = this->culoare.length();
		f.write((char*)&lungime, sizeof(int));

		for (int i = 0; i < lungime; i++) {
			f.write((char*)&this->culoare[i], sizeof(char));
		}

		for (int i = 0; i < this->nrRafturi; i++) {
			f.write((char*)&this->temperaturaRafturi[i], sizeof(int));
		}
	}

	void citesteDinFisBinFrigider(fstream& f) {
		f.read((char*)(&adancime), sizeof(float));
		f.read((char*)(&nrRafturi), sizeof(int));

		int culoareLength;
		f.read((char*)(&culoareLength), sizeof(int));
		char* culoareBuffer = new char[culoareLength + 1];
		f.read(culoareBuffer, culoareLength);
		culoareBuffer[culoareLength] = '\0';
		culoare = culoareBuffer;
		delete[] culoareBuffer;

		temperaturaRafturi = new int[nrRafturi];
		f.read((char*)(temperaturaRafturi), sizeof(int) * nrRafturi);
	}
	
};

string Frigider::materialRafturi = "Sticla";

ostream& operator<<(ostream& out, Frigider frigider) {
	out << "Frigiderul de culoare " << frigider.culoare << " are o adancime de " << frigider.adancime << " cm, are " << frigider.nrRafturi << " rafturi."<< endl;
	if (frigider.nrRafturi) {
		out << "Temperaturile de pe rafturi sunt: ";
		for (int i = 0; i < frigider.nrRafturi; i++)
			out << frigider.temperaturaRafturi[i] << " ";
	}
	out << endl;
	out << endl;
	return out;
}

istream& operator>>(istream& in, Frigider& frigider)
{
	cout << "Culoare:";
	in >> frigider.culoare;
	cout << "\nAdancime:";
	in >> frigider.adancime;
	cout << "\nNumar rafturi:";
	in >> frigider.nrRafturi;
	if (frigider.temperaturaRafturi != NULL)
	{
		delete[]frigider.temperaturaRafturi;
	}
	frigider.temperaturaRafturi = new int[frigider.nrRafturi];
	for (int i = 0; i < frigider.nrRafturi; i++)
	{
		cout << "\nTemperatura raftului:" << i + 1 << " : ";
		in >> frigider.temperaturaRafturi[i];

	}
	return in;
}

ofstream& operator<<(ofstream& out, Frigider& frigider) {
	out << "Frigiderul de culoare " << frigider.culoare << " are o adancime de " << frigider.adancime << " cm, are " << frigider.nrRafturi << " rafturi." << endl;
	if (frigider.nrRafturi) {
		out << "Temperaturile de pe rafturi sunt: ";
		for (int i = 0; i < frigider.nrRafturi; i++)
			out << frigider.temperaturaRafturi[i] << " ";
	}
	out << endl;
	out << endl;
	return out;
}

ifstream& operator>>(ifstream& in, Frigider& frigider) {
	in >> frigider.culoare;
	in >> frigider.adancime;
	in >> frigider.nrRafturi;
	if (frigider.temperaturaRafturi != NULL)
	{
		delete[]frigider.temperaturaRafturi;
	}
	frigider.temperaturaRafturi = new int[frigider.nrRafturi];
	for (int i = 0; i < frigider.nrRafturi; i++)
	{
		in >> frigider.temperaturaRafturi[i];
	}
	return in;
}

void verificaGarantie(Imprimanta& imprimanta, Frigider& frigider) {
	if ((imprimanta.imprimari) != 0 && frigider.temperaturaRafturi != 0) {
		cout << "Garantia pentru Imprimanta si Frigider este valabila." << endl;
	}
	else {
		cout << "Garantia pentru Imprimanta si Frigider nu este valabila." << endl;
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

//Faza5
class Raft {
private:
	int capacitateMaxima;
	float inaltimeRaft;
	bool areObiecte;
	Tableta* tableta;
	int nrTablete;
public:
	
	Raft() {
		this->capacitateMaxima = 153;
		this->inaltimeRaft = 123.4f;
		this->areObiecte = false;
		this->tableta = NULL;
		this->nrTablete = 0;
	}

	Raft(int capacitateMaxima, int nrTablete,Tableta*tablete) {
		this->capacitateMaxima = capacitateMaxima;
		this->inaltimeRaft = 123.4f;
		this->areObiecte = false;
		this->tableta = new Tableta[nrTablete];
		for (int i = 0; i < nrTablete; i++) {
			this->tableta[i] = tableta[i];
		}
		this->nrTablete = nrTablete;
	}

	Raft(const Raft& r) {
		this->capacitateMaxima = r.capacitateMaxima;
		this->inaltimeRaft = r.inaltimeRaft;
		this->areObiecte = r.areObiecte;
		this->tableta = new Tableta[r.nrTablete];
		for (int i = 0; i < r.nrTablete; i++) {
			this->tableta[i] = r.tableta[i];
		}
		this->nrTablete = r.nrTablete;
	}

	~Raft() {
		delete[]this->tableta;
	}

	int getCapacitateMax() {
		return this->capacitateMaxima;
	}

	void setCapacitateMax(int capacitateMaxima) {
		this->capacitateMaxima = capacitateMaxima;
	}

	float getInaltimeRaft() {
		return this->inaltimeRaft;
	}

	void setInaltimeRaft(float inaltimeRaft) {
		this->inaltimeRaft = inaltimeRaft;
	}

	bool getAreObiecte() {
		return this->areObiecte;
	}

	void setAreObiecte(bool areObiecte) {
		this->areObiecte = areObiecte;
	}

	friend ostream& operator<<(ostream& out, Raft& r);
	friend istream& operator>>(istream& in, Raft& r);
	friend ifstream& operator>>(ifstream& in, Raft& r);
	friend ofstream& operator<<(ofstream& out, Raft& r);

	Raft operator!() {
		Raft copie = *this;
		this->areObiecte = !copie.areObiecte;
		return copie;
	}

	void scriereInFisBinRaft(fstream& f) {
		f.write((char*)&this->capacitateMaxima, sizeof(int));
		f.write((char*)&this->areObiecte, sizeof(bool));
		f.write((char*)&this->inaltimeRaft, sizeof(float));
		for (int i = 0; i < this->nrTablete; i++) {
			f.write((char*)&this->tableta[i], sizeof(Tableta));
		}
	}

	void citesteDinFisBinRaft(fstream& f) {
		f.read((char*)&this->capacitateMaxima, sizeof(int));
		f.read((char*)&this->areObiecte, sizeof(bool));
		f.read((char*)&this->inaltimeRaft, sizeof(float));
		if (this->tableta != NULL) {
			delete[]this->tableta;
		}
		f.read((char*)&this->nrTablete, sizeof(int));
		this->tableta = new Tableta[this->nrTablete];
		for (int i = 0; i < this->nrTablete; i++) {
			f.read((char*)&this->tableta[i], sizeof(char));
		}
	}

};

istream& operator>>(istream& in, Raft& r) {
	cout << "\nCapacitatea totala a raftului: ";
	in >> r.capacitateMaxima;
	cout << "\nAre o inaltime de: ";
	in >> r.inaltimeRaft;
	cout << "\nAre obiecte? 1-Da, 0-Nu";
	in >> r.areObiecte;
	cout << "\nNr tablete:  ";
	in >> r.nrTablete;
	r.tableta = new Tableta[r.nrTablete];
	cout << "\nTabletele: ";
	for (int i = 0; i < r.nrTablete; i++) {
		in >> r.tableta[i];
	}
	return in;
}

ostream& operator<<(ostream& out, Raft& r) {
	out << "\nRaftul are o capacitate maxima de " << r.capacitateMaxima;
	if (r.areObiecte) {
		out << "\nPe raft sunt obiecte!";
	}
	else {
		out << "\nPe raft nu sunt obiecte!";
	}
	out << "\nAre o inaltime de: " << r.inaltimeRaft<<" metri.";
	out << "\nAre un numar de " << r.nrTablete << " tablete.";
	if (r.nrTablete) {
		out << "\Tabletele sunt: ";
		for (int i = 0; i < r.nrTablete; i++) {
			out << "\nTableta: " << (i + 1) << " : " << r.tableta[i]<<" ";
		}
	}
	else {
		out << "\nNu are obiecte de tipul tableta!" << endl;
	}
	return out;
}

ifstream& operator>>(ifstream& in, Raft& r) {
	in >> r.capacitateMaxima;
	in >> r.inaltimeRaft;
	in >> r.areObiecte;
	in >> r.nrTablete;
	r.tableta = new Tableta[r.nrTablete];
	for (int i = 0; i < r.nrTablete; i++) {
		in >> r.tableta[i];
	}
	return in;
}

ofstream& operator<<(ofstream& out, Raft& r) {
	out << "\nRaftul are o capacitate maxima de " << r.capacitateMaxima;
	if (r.areObiecte) {
		out << "\nPe raft sunt obiecte!";
	}
	else {
		out << "\nPe raft nu sunt obiecte!";
	}
	out << "\nAre o inaltime de: " << r.inaltimeRaft << " metri.";
	out << "\nAre un numar de " << r.nrTablete << " tablete.";
	if (r.nrTablete) {
		out << "\Tabletele sunt: ";
		for (int i = 0; i < r.nrTablete; i++) {
			out << "\nTableta: " << (i + 1) << " : " << r.tableta[i] << " ";
		}
	}
	else {
		out << "\nNu are obiecte de tipul tableta!" << endl;
	}
	return out;
}

//Faza7
class Xerox : public Imprimanta {
private:
	int nrCopiiMaxim;
	bool areFunctieFax;
public:
	void afiseazXerox() {
		cout << (Imprimanta)*this;
		cout << endl;
		cout << "Numarul maxim de copii pe care le poate realiza este: " << this->nrCopiiMaxim << endl;
		if (this->areFunctieFax) {
			cout << "Xeroxul are functie fax!";
		}
		else {
			cout << "Nu are functie fax!";
		}
		cout << endl;
	}

	Xerox() : Imprimanta(80, "Canon") {
		this->nrCopiiMaxim = 30;
		this->areFunctieFax = true;
	}

	Xerox(int nrCopiiMaxim, bool areFunctieFax) {
		this->nrCopiiMaxim = nrCopiiMaxim;
		this->areFunctieFax = areFunctieFax;
	}

	Xerox(int nrCopiiMaxim, bool areFunctieFax, int capacitate, string marca, float greutate, int* nrPaginiImprimate) :Imprimanta(capacitate, marca, greutate, nrPaginiImprimate) {
		this->nrCopiiMaxim = nrCopiiMaxim;
		this->areFunctieFax = areFunctieFax;
	}

	Xerox(const Xerox& x) :Imprimanta(x){
		this->nrCopiiMaxim = x.nrCopiiMaxim;
		this->areFunctieFax = x.areFunctieFax;
	}

	Xerox operator=(const Xerox& x) {
		if (this != &x) {
			Imprimanta::operator=(x);
			this->nrCopiiMaxim = x.nrCopiiMaxim;
			this->areFunctieFax = x.areFunctieFax;
		}
		return*this;
	}

	int getNrCopiiMaxim() {
		return this->nrCopiiMaxim;
	}

	void setNrCopiiMaxim(int nrCopiiMaxim) {
		this->nrCopiiMaxim = nrCopiiMaxim;
	}

	bool getAreFunctieFax() {
		return this->areFunctieFax;
	}

	void setAreFunctieFax(bool areFunctieFax) {
		this->areFunctieFax = areFunctieFax;
	}

	~Xerox(){

	}
};

class TabletaGrafica :public Tableta {
private:
	int nivelPresiuneStilou;
	bool suportaTouch;
public:
	void afisareTabletaGrafica() {
		cout << endl;
		cout << (Tableta)*this;
		cout << "Nivel presiune stilou: " << this->nivelPresiuneStilou << endl;
		if (this->suportaTouch) {
			cout << "Tableta grafica suporta touch!";
		}
		else {
			cout << "Nu suporta touch!";
		}
		cout << endl;
	}

	TabletaGrafica() :Tableta(128, "iOS") {
		this->nivelPresiuneStilou = 8192;
		this->suportaTouch = true;
	}

	TabletaGrafica(int nivelPresiuneStilou, bool suportaTouch) {
		this->nivelPresiuneStilou = nivelPresiuneStilou;
		this->suportaTouch = suportaTouch;
	}

	TabletaGrafica(int nivelPresiuneStilou, bool suportaTouch, float grosime, string sistemDeOperare, int nrAplicatii, int* listaAplicatii): Tableta(grosime, sistemDeOperare, nrAplicatii, listaAplicatii){
		this->nivelPresiuneStilou = nivelPresiuneStilou;
		this->suportaTouch = suportaTouch;
	}

	TabletaGrafica(const TabletaGrafica& g):Tableta(g) {
		this->nivelPresiuneStilou = g.nivelPresiuneStilou;
		this->suportaTouch = g.suportaTouch;
	}

	TabletaGrafica operator=(const TabletaGrafica& g) {
		if (this != &g) {
			this->nivelPresiuneStilou = g.nivelPresiuneStilou;
			this->suportaTouch = g.suportaTouch;
		}
		return *this;
	}

	int getNivelPresiune() {
		return this->nivelPresiuneStilou = nivelPresiuneStilou;
	}

	void setNivelPresiune(int nivelPresiuneStilou) {
		this->nivelPresiuneStilou = nivelPresiuneStilou;
	}

	bool getSuportaTouch() {
		return this->suportaTouch = suportaTouch;
	}

	void setSuportaTouch(bool suportaTouch) {
		this->suportaTouch = suportaTouch;
	}

	~TabletaGrafica() {

	}
};

//Clasa Raft(has-a) abstract

class RaftAbstract {
private:
	int capacitateMaxima;
	float inaltimeRaft;
	bool areObiecte;
	AbstractA** obiecte;
	int nrObiecte;

public:
	RaftAbstract() {
		this->capacitateMaxima = 153;
		this->inaltimeRaft = 123.4f;
		this->areObiecte = false;
		this->obiecte = NULL;
		this->nrObiecte = 0;
	}

	RaftAbstract(int capacitateMaxima, int nrObiecte, AbstractA** obiecte) {
		this->capacitateMaxima = capacitateMaxima;
		this->inaltimeRaft = 123.4f;
		this->areObiecte = false;
		this->obiecte = new AbstractA * [nrObiecte];
		for (int i = 0; i < nrObiecte; i++) {
			this->obiecte[i] = obiecte[i];
		}
		this->nrObiecte = nrObiecte;
	}

	RaftAbstract(const RaftAbstract& r) {
		this->capacitateMaxima = r.capacitateMaxima;
		this->inaltimeRaft = r.inaltimeRaft;
		this->areObiecte = r.areObiecte;
		this->obiecte = new AbstractA * [r.nrObiecte];
		for (int i = 0; i < r.nrObiecte; i++) {
			this->obiecte[i] = r.obiecte[i];
		}
		this->nrObiecte = r.nrObiecte;
	}

	~RaftAbstract() {
		delete[] this->obiecte;
	}

	int getCapacitateMax()  {
		return this->capacitateMaxima;
	}

	void setCapacitateMax(int capacitateMaxima) {
		this->capacitateMaxima = capacitateMaxima;
	}

	float getInaltimeRaft()  {
		return this->inaltimeRaft;
	}

	void setInaltimeRaft(float inaltimeRaft) {
		this->inaltimeRaft = inaltimeRaft;
	}

	bool getAreObiecte()  {
		return this->areObiecte;
	}

	void setAreObiecte(bool areObiecte) {
		this->areObiecte = areObiecte;
	}

	int getNumarObiecte() {
		return this->nrObiecte;
	}

	void setNumarObiecte(int numar) {
		nrObiecte = numar;
		if (obiecte != nullptr) {
			for (int i = 0; i < nrObiecte; i++) {
				delete obiecte[i];
			}
			delete[] obiecte;
		}
		obiecte = new AbstractA * [nrObiecte];
		for (int i = 0; i < nrObiecte; i++) {
			obiecte[i] = new Tableta();
		}
	}

	void setObiect(int index, AbstractA* obiect) {
		if (index >= 0 && index < nrObiecte) {
			obiecte[index] = obiect;
		}
	}

	friend ostream& operator<<(ostream& out, const RaftAbstract& r);
	friend istream& operator>>(istream& in, RaftAbstract& r);

};

ostream& operator<<(ostream& out, const RaftAbstract& r) {
	out << "Capacitate maxima: " << r.capacitateMaxima << ", inaltime raft: " << r.inaltimeRaft << endl;
	if (r.nrObiecte) {
		out << "\nPe raft sunt obiecte!"<<endl;
	}
	else {
		out << "\nPe raft nu sunt obiecte!"<<endl;
	}
	for (int i = 0; i < r.nrObiecte; i++) {
		out << "Obiect " << i + 1 << ": ";
		r.obiecte[i]->metodaAbstractaA();
		out << "\n";
	}
	return out;
}

istream& operator>>(istream& in, RaftAbstract& r) {
	in >> r.capacitateMaxima;
	in >> r.nrObiecte;
	r.obiecte = new AbstractA * [r.nrObiecte];
	for (int i = 0; i < r.nrObiecte; i++) {
		r.obiecte[i] = new Tableta();
	}
	return in;
}

void main() {
	Imprimanta imprimanta;
	imprimanta.afisareImprimanta();
	Imprimanta imprimanta1(80, "Canon", 3.9f, 0);
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
	Frigider frigider1("gri", 3, 54.7f, temperaturirafturi);
	frigider1.afisareFrigider();

	frigider1.setTemperatura(1, 4);
	int* temperaturaRafturiFrigider1 = frigider1.getTemperatura();

	cout << "Temperatura initiala a frigiderului: " << *frigider1.getTemperatura() << " grade Celsius" << endl;

	frigider1.setTemperatura(1, 7);

	for (int i = 0; i < frigider1.getnrRafturi(); i++)
		cout << "Temperatura actualizata a frigiderului: " << frigider1.getTemperatura()[i] << " grade Celsius" << endl;

	////Faza 2
	//cout << endl;
	//Imprimanta imprimanta3;
	//imprimanta3.setCapacitate(50);
	//cout << "Capacitatea imprimantei: " << imprimanta3.getCapacitate() << " coli." << endl;
	//imprimanta3.setMarca("Canon");
	//cout << "Marca imprimantei: " << imprimanta3.getMarca() << endl;
	//imprimanta3.setGreutate(4.3f);
	//cout << "Greutatea imprimantei: " << imprimanta3.getGreutate() << endl;
	//imprimanta3.ImprimaPagini(11);
	//cout << "Numarul total de pagini imprimate: " << imprimanta3.ImprimaPagini(0) << endl;
	//imprimanta3.setFormat("A4");
	//cout << "Formatul este: " << imprimanta3.getFormat() << endl;
	//cout << "Codul producatorului este: " << imprimanta3.getCodProducator();
	//cout << endl;
	//Imprimanta imprimanta4 = imprimanta2;
	//imprimanta2.afisareImprimanta();
	//cout << endl;


	//cout << endl;
	//Tableta tableta4;
	//tableta4.setMemorie(8);
	//cout << "Memoria tabletei: " << tableta4.getMemorie() << endl;
	//tableta4.setGrosime(7.85);
	//cout << "Grosimea tabletei: " << tableta4.getGrosime() << endl;
	//tableta4.setSistemDeOperare("iOS");
	//cout << "Sistemul de operare al tabletei: " << tableta4.getSistemDeOperare() << endl;
	//tableta4.setConexiune("Wifi");
	//cout << "Conexiune se realizeaza prin: " << tableta4.getConexiune() << endl;
	//cout << "Codul produsului este: " << tableta4.getCodProdus() << endl;
	//Tableta tableta7 = tableta3;
	//tableta7.afisareTableta();
	//cout << endl;

	//cout << endl;
	//Frigider frigider55;
	//Frigider frigider2 = frigider55;
	//frigider2.setCuloare("Alb");
	//cout << "Culoarea frigiderului este: " << frigider2.getCuloare() << endl;
	//frigider2.setNrRafturi(7);
	//cout << "Frigiderul are un numar de " << frigider2.getnrRafturi() << " rafturi." << endl;
	//frigider2.setAdancime(45.6);
	//cout << "Frigiderul are o adancime de " << frigider2.getAdancime() << endl;
	//frigider2.getMaterialRafturi();
	//cout << "Rafturile sunt din: " << frigider2.getMaterialRafturi() << endl;
	//cout << "Volumul frigiderului este de: " << frigider2.getVolum();

	//cout << endl;

	//imprimanta.ImprimaPagini(100);
	//frigider.setTemperatura(1, 4);
	//cout << endl;
	//verificaGarantie(imprimanta, frigider);

	//verificaFunctionalitate(imprimanta, tableta);
	//cout << endl;

	////Faza 3

	//Imprimanta imprimanta6;
	//imprimanta6 = imprimanta2;
	//cout << imprimanta6;

	//Imprimanta imprimanta7;
	//imprimanta7 = imprimanta2 + 10;
	//cout << imprimanta7;

	//cout << endl;
	//cout << imprimanta2;
	//Imprimanta imprimanta8;
	//imprimanta8 = imprimanta2 - 3.5f;
	//cout << imprimanta8;

	//cout << endl;
	//Tableta tableta8;
	//tableta8 = tableta1;
	//cout << tableta8;

	//cout << endl;
	//Tableta tableta6;
	//tableta6 = tableta3;
	//cout << tableta6;
	//cout << endl;

	//cout << endl;
	//cout << tableta3;
	//cout << endl;
	//++tableta3;
	//cout << tableta3;
	//cout << endl;
	//tableta3++;
	//cout << tableta3;

	//cout << endl;
	//Tableta tableta11(32, "iOS", 5, new int[5] {14, 20, 34, 7, 22});
	//cout << tableta11[0];
	//cout << endl;

	//cout << endl;
	//Frigider frigider9;
	//frigider9 = frigider;
	//cout << frigider9;

	//cout << endl;
	//Frigider frigider6;
	//frigider6 = frigider1;
	//frigider6.afisareFrigider();
	//cout << endl;

	//Frigider frigider7;
	//frigider7.setNrRafturi(1);
	//cout << frigider7.getnrRafturi() << endl;
	//cout << frigider7->getnrRafturi() << endl;
	//cout << endl;

	//cout << frigider;
	//--frigider;
	//cout << frigider;

	////Faza4

	//Imprimanta imprimanta20;
	//cin >> imprimanta20;
	//cout << imprimanta20;
	//cout << endl;

 //   Tableta tableta10;
	//cin >> tableta10;
	//cout << tableta10;
	//cout << endl;

	//Frigider frigider8;
	//cin >> frigider8;
	//cout << frigider8;

	////Vector Imprimanta
	//int nrObiecteImprimanta = 0;
	//cout << "Numarul de imprimante: ";
	//cin >> nrObiecteImprimanta;
	//Imprimanta* vimprimanta = new Imprimanta[nrObiecteImprimanta];
	//for (int i = 0; i < nrObiecteImprimanta; i++) {
	//	cout << "Citire imprimanta cu numarul: " << (i + 1) << " : ";
	//	cin >> vimprimanta[i];
	//}
	//for (int i = 0; i < nrObiecteImprimanta; i++) {
	//	cout << "Imprimanta cu numarul : " << (i + 1) << " : ";
	//	vimprimanta[i].afisareImprimanta();
	//	cout << endl;
	//}
	//cout << endl;

	////Vector Tableta
	//int nrObiecte = 0;
	//cout << "Numarul de tablete: ";
	//cin >> nrObiecte;
	//Tableta* vtableta = new Tableta[nrObiecte];
	//for (int i = 0; i < nrObiecte; i++) {
	//	cout << "Citire tableta cu numarul: " << (i + 1) << " : ";
	//	cin >> vtableta[i];
	//}
	//for (int i = 0; i < nrObiecte; i++) {
	//	cout << "Tableta cu numarul : " << (i + 1) << " : ";
	//	vtableta[i].afisareTableta();
	//	cout << endl;
	//}
	//cout << endl;

	////Vector Frigider
	//int nrObiecteFrigider = 0;
	//cout << "Numarul de frigidere: ";
	//cin >> nrObiecteFrigider;
	//Frigider* vfrigider = new Frigider[nrObiecteFrigider];
	//for (int i = 0; i < nrObiecteFrigider; i++) {
	//	cout << "Citire frigider cu numarul: " << (i + 1) << " : ";
	//	cin >> vfrigider[i];
	//}
	//for (int i = 0; i < nrObiecteFrigider; i++) {
	//	cout << "Frigiderul cu numarul : " << (i + 1) << " : ";
	//	vfrigider[i].afisareFrigider();
	//	cout << endl;
	//}
	//cout << endl;

	////Matrice Tableta
	//int nrLinii = 0;
	//int nrColoane = 0;
	//cout << "Nr de linii ale matricei:";
	//cin >> nrLinii;
	//cout << "Nr de coloane ale matricei:";
	//cin >> nrColoane;
	//Tableta** matriceTableta = new Tableta*[nrLinii];
	//for (int i = 0; i < nrLinii; i++) {
	//	matriceTableta[i] = new Tableta[nrColoane];
	//}

	//cout << "Citire matrice: " << endl;
	//for (int i = 0; i < nrLinii; i++) {
	//	for (int j = 0; j < nrColoane; j++) {
	//		cout << "Linia: "<<(i+1)<<" si coloana: "<<(j+1)<<endl;
	//		cin >> matriceTableta[i][j];
	//	}
	//}

	//cout << "Afisare matrice: " << endl;
	//for (int i = 0; i < nrLinii; i++) {
	//	for (int j = 0; j < nrColoane; j++) {
	//		cout << "Linia: " << (i + 1) << " si coloana: " << (j + 1) << endl;
	//		matriceTableta[i][j].afisareTableta();
	//	}
	//}
	//cout << endl;

	//if (vimprimanta != NULL) {
	//	delete[]vimprimanta;
	//}

	//if (vtableta != NULL) {
	//	delete[]vtableta;
	//}

	//if (vfrigider != NULL) {
	//	delete[]vfrigider;
	//}

	//if (nrLinii != 0) {
	//	for (int i = 0; i < nrColoane; i++) {
	//		delete[]matriceTableta;
	//	}
	//}

	//if (matriceTableta != NULL) {
	//	delete[]matriceTableta;
	//}
	//
	////Faza5
	////geteri si seteri
	//cout << endl;
	//Raft raft;
	//raft.setCapacitateMax(100);
	//cout << "\n\nCapacitate maxima: " << raft.getCapacitateMax();
	//raft.setAreObiecte(true);
	//cout << "\nAre obiecte 1-Da, 0-Nu"<<"  "<<raft.getAreObiecte();
	//raft.setInaltimeRaft(34.5f);
	//cout << "\nAre o inaltime de: " << raft.getInaltimeRaft()<<" metri.";

	//Raft raft1;
	//cin >> raft1;
	//cout << raft1;
	//cout << endl;

	//cout << endl;
	//!raft1;
	//cout << raft1;

	//Faza6

	/*ofstream f("imprimanta.txt",ios::out);
	Imprimanta imprimanta100;
	cin >> imprimanta100;
	f << imprimanta100;
	f.close();

	ifstream g("imprimanta.txt", ios::in);
	Imprimanta i1;
	g >> i1;
	cout << i1;
	g.close();

	ofstream a("tableta.txt",ios::out);
	Tableta tableta100;
	cin >> tableta100;
	a << tableta100;
	a.close();

	ifstream b("tableta.txt", ios::in);
	Tableta t1;
	b >> t1;
	cout << t1;
	b.close();


	Frigider frigider100;
	cin >> frigider100;
	fstream out("frigider.bin", ios::out | ios::binary);
	frigider100.scriereInFisBinFrigider(out);
	out.close();

	Frigider frigidercitit;
	fstream in("frigider.bin", ios::in | ios::binary);
	frigidercitit.citesteDinFisBinFrigider(in);
	in.close();


	Raft raft100;
	cin >> raft100;
	fstream outraft("raft.bin", ios::out | ios::binary);
	raft100.scriereInFisBinRaft(outraft);
	outraft.close();

	Raft raftcitit;
	fstream inraft("raft.bin", ios::in | ios::binary);
	raftcitit.citesteDinFisBinRaft(inraft);
	inraft.close();*/

	//Faza 7
	cout << endl;
	Xerox xerox1;
	xerox1.afiseazXerox();
	cout << endl;
	Xerox xerox2(55, false);
	xerox2.afiseazXerox();
	Xerox xerox3 = xerox1;
	xerox3.afiseazXerox();
	Xerox xerox4;
	xerox4.setNrCopiiMaxim(45);
	cout << "\nNumarul maxim de copii: " << xerox4.getNrCopiiMaxim();
	xerox4.setAreFunctieFax(false);
	cout << "\nAre functie fax: 1-Da, altceva-Nu  " << xerox4.getAreFunctieFax();
	Xerox xerox5;
	xerox5 = xerox2;
	xerox5.afiseazXerox();

	cout << endl;
	TabletaGrafica tg1;
	tg1.afisareTabletaGrafica();
	TabletaGrafica tg2(4289, false);
	tg2.afisareTabletaGrafica();
	TabletaGrafica tg3 = tg1;
	tg3.afisareTabletaGrafica();
	TabletaGrafica tg4;
	tg4 = tg2;
	tg4.afisareTabletaGrafica();
	TabletaGrafica tg5;
	tg5.setNivelPresiune(7834);
	cout << "\nNivelul de presiune stilou: " << tg5.getNivelPresiune();
	tg5.setSuportaTouch(false);
	cout << "\nTableta grafica suporta touch: 1-Da, 0-Nu   " << tg5.getSuportaTouch();
	cout << endl;

	//Faza 8

	AbstractA** vectorAbstract1 = new AbstractA * [10];
	vectorAbstract1[0] = new Imprimanta(124, "HP");
	vectorAbstract1[1] = new Tableta();
	vectorAbstract1[2] = new Tableta(32, "iOS");
	vectorAbstract1[3] = new Frigider();
	vectorAbstract1[4] = new Frigider("Alb", 3);
	vectorAbstract1[5] = new Imprimanta();
	vectorAbstract1[6] = new Imprimanta();
	vectorAbstract1[7] = new Tableta();
	vectorAbstract1[8] = new Frigider();
	vectorAbstract1[9] = new Frigider();
	
	for (int i = 0; i < 10; i++) {
		vectorAbstract1[i]->metodaAbstractaA();
		cout << endl;
	}

	cout << endl;
	AbstractB** vectorAbstract2 = new AbstractB * [10];
	vectorAbstract2[0] = new Imprimanta(124, "HP");
	vectorAbstract2[1] = new Tableta();
	vectorAbstract2[2] = new Tableta(32, "iOS");
	vectorAbstract2[3] = new Frigider();
	vectorAbstract2[4] = new Frigider("Alb", 3);
	vectorAbstract2[5] = new Imprimanta();
	vectorAbstract2[6] = new Imprimanta(126, "Canon");
	vectorAbstract2[7] = new Tableta();
	vectorAbstract2[8] = new Frigider();
	vectorAbstract2[9] = new Tableta(32, "iOS");

	for (int i = 0; i < 10; i++) {
		vectorAbstract2[i]->metodaAbstractaB();
		cout << endl;
	}

	//Clasa abstracta
	RaftAbstract raft;
	raft.setNumarObiecte(3);
	raft.setObiect(0, new Imprimanta());
	raft.setObiect(1, new Tableta());
	raft.setObiect(2, new Frigider());
	cout << raft;
}