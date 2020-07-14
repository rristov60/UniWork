#include "pch.h"
#include "xlsxwriter.h"
#include "Drawing.h"
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string.h>
#include <cstdio>
#include <tchar.h>
using namespace std;

const int HourlyRateEngineer = 50;
const int HourlyRateScientist = 45;
const int HourlyRateAdministration = 40;
const int HourlyRateArtist = 35;
const int ArtistHandWork = 400;
const int HourlyRateHighLevelAdministration = 200;
const int HourlyRateMarketingDepartment = 70;


class Executive {
private:
	char username[40];
	char password[40];
public:
	Executive() {
		strcpy_s(username, "user@thunderaviation.com");
		strcpy_s(password, "apollo14");
	}
	char *getUser() {
		return username;
	}
	char *getPassword() {
		return password;
	}
};

class Manager {
private:
	char username[40];
	char password[40];
public:
	Manager() {
		strcpy_s(username, "john@thunderaviation.com");
		strcpy_s(password, "marketing");
	}
	char *getUser() {
		return username;
	}
	char *getPassword() {
		return password;
	}
};

class Acc {
private:
	char username[40];
	char password[40];
public:
	Acc() {
		strcpy_s(username, "steve@thunderaviation.com");
		strcpy_s(password, "dancingcarrot");
	}
	char *getUser() {
		return username;
	}
	char *getPassword() {
		return password;
	}
};

class Employee {
protected:
	char name[40];
	char surName[40];
	int hours;
	int bonuses;
public:
	Employee() {}
	Employee(char *_name, char *_surName, int _hours, int _bonuses) {
		strcpy_s(name, _name);
		strcpy_s(surName, _surName);
		hours = _hours;
		bonuses = _bonuses;
	}
	char *getName() {
		return name;
	}
	char *getSurName() {
		return surName;
	}
	virtual int Paycheck() = 0;
	virtual ~Employee() {}
};

class Engineer : public Employee {
protected:
	int equipmentExpense;
public:
	Engineer() {}
	Engineer(char *_name, char *_surName, int _hours, int _equipmentExpense, int _bonuses) : Employee(_name, _surName, _hours, _bonuses) {
		equipmentExpense = _equipmentExpense;
	}
	int Paycheck() {
		int paycheck;
		paycheck = (hours * HourlyRateEngineer) + bonuses;
		return paycheck;
	}
	int GetHours() {
		return hours;
	}
	int GetBonuses() {
		return bonuses;
	}
};

class Scientist : public Employee {
protected:
	int fieldWork;
public:
	Scientist() {}
	Scientist(char *_name, char *_surName, int _fieldWork, int _hours, int _bonuses) : Employee(_name, _surName, _hours, _bonuses) {
		fieldWork = _fieldWork;
	}
	int Paycheck() {
		int paycheck;
		paycheck = ((hours + (fieldWork * 2)) * HourlyRateEngineer) + bonuses;
		return paycheck;
	}
	int GetHours() {
		return hours;
	}
	int GetBonuses() {
		return bonuses;
	}
};

class Administration : public Employee {
protected:
	int trvlExpense;
public:
	Administration() {}
	Administration(char *_name, char *_surName, int _trvlExpense, int _hours, int _bonuses) : Employee(_name, _surName, _hours, _bonuses) {
		trvlExpense = _trvlExpense;
	}
	int Paycheck() {
		int paycheck;
		paycheck = (hours * HourlyRateAdministration) + trvlExpense + bonuses;
		return paycheck;
	}
	int GetHours() {
		return hours;
	}
	int GetBonuses() {
		return bonuses;
	}
};

class Artist : public Employee {
protected:
	int handWorkParts;
public:
	Artist() {}
	Artist(char *_name, char *_surName, int _hours, int _handWorkParts, int _bonuses) : Employee(_name, _surName, _hours, _bonuses) {
		handWorkParts = _handWorkParts;
	}
	int Paycheck() {
		int paycheck;
		paycheck = (hours * HourlyRateArtist) + bonuses + (handWorkParts * ArtistHandWork);
		return paycheck;
	}
	int GetHours() {
		return hours;
	}
	int GetBonuses() {
		return bonuses;
	}
};

class HighLevelAdministration : public Employee {
protected:
	int trvlExpense;
public:
	HighLevelAdministration() {}
	HighLevelAdministration(char *_name, char *_surName, int _hours, int _trvlExpense, int _bonuses) : Employee(_name, _surName, _hours, _bonuses) {
		trvlExpense = _trvlExpense;
	}
	int Paycheck() {
		int paycheck;
		paycheck = (hours * HourlyRateHighLevelAdministration) + bonuses + trvlExpense;
		return paycheck;
	}
	int GetHours() {
		return hours;
	}
	int GetBonuses() {
		return bonuses;
	}
};

class MarketingDepartment : public Employee {
protected:
	int trvlExpense;
public:
	MarketingDepartment() {}
	MarketingDepartment(char *_name, char *_surName, int _hours, int _trvlExpense, int _bonuses) : Employee(_name, _surName, _hours, _bonuses) {
		trvlExpense = _trvlExpense;
	}

	int Paycheck() {
		int paycheck;
		paycheck = (hours * HourlyRateMarketingDepartment) + trvlExpense + bonuses;
		return paycheck;
	}
	int GetHours() {
		return hours;
	}
	int GetBonuses() {
		return bonuses;
	}
};

class MarketingManager : public MarketingDepartment {
private:
	char position[30];
public:
	MarketingManager(char *_name, char *_surName, int _hours, int _trvlExpense, int _bonuses) : MarketingDepartment(_name, _surName, _hours, _trvlExpense, _bonuses) {
		strcpy_s(position, "Marketing Manager");
	}
	char *GetPostion() {
		return position;
	}
};

class MediaHandler : public MarketingDepartment {
private:
	char position[30];
public:
	MediaHandler(char *_name, char *_surName, int _hours, int _trvlExpense, int _bonuses) : MarketingDepartment(_name, _surName, _hours, _trvlExpense, _bonuses) {
		strcpy_s(position, "Media Handler");
	}
	char *GetPostion() {
		return position;
	}
};

class PublicRepresentative : public MarketingDepartment {
private:
	char position[30];
public:
	PublicRepresentative(char *_name, char *_surName, int _hours, int _trvlExpense, int _bonuses) : MarketingDepartment(_name, _surName, _hours, _trvlExpense, _bonuses) {
		strcpy_s(position, "Public Representative");
	}
	char *GetPostion() {
		return position;
	}
};

class GraphicsDesigner : public Artist {
private:
	char position[30];
public:
	GraphicsDesigner(char *_name, char *_surName, int _hours, int _bonuses) :Artist(_name, _surName, _hours, 0, _bonuses) {
		strcpy_s(position, "Graphics Designer");
	}
	char *GetPostion() {
		return position;
	}
};

class Painter : public Artist {
private:
	char position[30];
public:
	Painter(char *_name, char *_surName, int _hours, int _handWorkParts, int _bonuses) :Artist(_name, _surName, _hours, _handWorkParts, _bonuses) {
		strcpy_s(position, "Painter");
	}
	char *GetPostion() {
		return position;
	}
};

class UXDesginer : public Artist {
private:
	char position[30];
public:
	UXDesginer(char *_name, char *_surName, int _hours, int _bonuses) :Artist(_name, _surName, _hours, 0, _bonuses) {
		strcpy_s(position, "UXDesginer");
	}
	char *GetPostion() {
		return position;
	}

};

class MechanicalEngineer : public Engineer {
private:
	char position[30];
public:
	MechanicalEngineer(char *_name, char *_surName, int _hours, int _equipmentExpense, int _bonuses) :Engineer(_name, _surName, _hours, _equipmentExpense, _bonuses) {
		strcpy_s(position, "Mechanical Engineer");
	}
	char *GetPostion() {
		return position;
	}
};

class ElectricalEngineer : public Engineer {
private:
	char position[30];
public:
	ElectricalEngineer(char *_name, char *_surName, int _hours, int _equipmentExpense, int _bonuses) :Engineer(_name, _surName, _hours, _equipmentExpense, _bonuses) {
		strcpy_s(position, "Electrical Engineer");
	}
	char *GetPostion() {
		return position;
	}
};

class AeroEngineer : public Engineer {
private:
	char position[30];
public:
	AeroEngineer(char *_name, char *_surName, int _hours, int _equipmentExpense, int _bonuses) :Engineer(_name, _surName, _hours, _equipmentExpense, _bonuses) {
		strcpy_s(position, "Aero Engineer");
	}
	char *GetPostion() {
		return position;
	}
};

class SoftwareEngineer : public Engineer {
private:
	char position[30];
public:
	SoftwareEngineer(char *_name, char *_surName, int _hours, int _equipmentExpense, int _bonuses) :Engineer(_name, _surName, _hours, _equipmentExpense, _bonuses) {
		strcpy_s(position, "Software Engineer");
	}
	char *GetPostion() {
		return position;
	}
};

class SystemAdministrator : public Engineer {
private:
	char position[30];
public:
	SystemAdministrator(char *_name, char *_surName, int _hours, int _equipmentExpense, int _bonuses) :Engineer(_name, _surName, _hours, _equipmentExpense, _bonuses) {
		strcpy_s(position, "System Administrator");
	}
	char *GetPostion() {
		return position;
	}
};

class Physicist : public Scientist {
private:
	char position[30];
public:
	Physicist(char *_name, char *_surName, int _fieldWork, int _hours, int _bonuses) :Scientist(_name, _surName, _fieldWork, _hours, _bonuses) {
		strcpy_s(position, "Physicist");
	}
	char *GetPostion() {
		return position;
	}
};

class Chemist : public Scientist {
private:
	char position[30];
public:
	Chemist(char *_name, char *_surName, int _fieldWork, int _hours, int _bonuses) :Scientist(_name, _surName, _fieldWork, _hours, _bonuses) {
		strcpy_s(position, "Chemist");
	}
	char *GetPostion() {
		return position;
	}
};

class Mathematician : public Scientist {
private:
	char position[30];
public:
	Mathematician(char *_name, char *_surName, int _fieldWork, int _hours, int _bonuses) :Scientist(_name, _surName, _fieldWork, _hours, _bonuses) {
		strcpy_s(position, "Mathematician");
	}
	char *GetPostion() {
		return position;
	}
};

class Accountant : public Administration {
private:
	char position[30];
public:
	Accountant(char *_name, char *_surName, int _trvlExpense, int _hours, int _bonuses) :Administration(_name, _surName, _trvlExpense, _hours, _bonuses) {
		strcpy_s(position, "Accountant");
	}
	char *GetPostion() {
		return position;
	}
};

class Legal : public Administration {
private:
	char position[30];
public:
	Legal(char *_name, char *_surName, int _trvlExpense, int _hours, int _bonuses) :Administration(_name, _surName, _trvlExpense, _hours, _bonuses) {
		strcpy_s(position, "Legal");
	}
	char *GetPostion() {
		return position;
	}
};

class Secretary : public Administration {
private:
	char position[30];
public:
	Secretary(char *_name, char *_surName, int _trvlExpense, int _hours, int _bonuses) :Administration(_name, _surName, _trvlExpense, _hours, _bonuses) {
		strcpy_s(position, "Secretary");
	}
	char *GetPostion() {
		return position;
	}
};

class CEO : public HighLevelAdministration {
private:
	char position[30];
public:
	CEO(char *_name, char *_surName, int _hours, int _trvlExpense, int _bonuses) :HighLevelAdministration(_name, _surName, _hours, _trvlExpense, _bonuses) {
		strcpy_s(position, "CEO");
	}
	char *GetPostion() {
		return position;
	}
};

class HeadOfEngineering : public HighLevelAdministration {
private:
	char position[30];
public:
	HeadOfEngineering(char *_name, char *_surName, int _hours, int _trvlExpense, int _bonuses) : HighLevelAdministration(_name, _surName, _hours, _trvlExpense, _bonuses) {
		strcpy_s(position, "Head Of Engineering");
	}
	char *GetPostion() {
		return position;
	}
};

class HeadOfMarketing : public HighLevelAdministration {
private:
	char position[30];
public:
	HeadOfMarketing(char *_name, char *_surName, int _hours, int _trvlExpense, int _bonuses) : HighLevelAdministration(_name, _surName, _hours, _trvlExpense, _bonuses) {
		strcpy_s(position, "Head Of Marketing");
	}
	char *GetPostion() {
		return position;
	}
};

class HeadOfDesign : public HighLevelAdministration {
private:
	char position[30];
public:
	HeadOfDesign(char *_name, char *_surName, int _hours, int _trvlExpense, int _bonuses) : HighLevelAdministration(_name, _surName, _hours, _trvlExpense, _bonuses) {
		strcpy_s(position, "Head of Design");
	}
	char *GetPostion() {
		return position;
	}
};

class HeadOfAdministration : public HighLevelAdministration {
private:
	char position[30];
public:
	HeadOfAdministration(char *_name, char *_surName, int _hours, int _trvlExpense, int _bonuses) : HighLevelAdministration(_name, _surName, _hours, _trvlExpense, _bonuses) {
		strcpy_s(position, "Head Of Administration");
	}
	char *GetPostion() {
		return position;
	}
};

class HeadOfScience : public HighLevelAdministration {
private:
	char position[30];
public:
	HeadOfScience(char *_name, char *_surName, int _hours, int _trvlExpense, int _bonuses) : HighLevelAdministration(_name, _surName, _hours, _trvlExpense, _bonuses) {
		strcpy_s(position, "Head Of Science");
	}
	char *GetPostion() {
		return position;
	}
};

class Material {
protected:
	float *price;
	char supplier[30];
	char material[30];
public:
	Material() {}
	void SetMaterial(float _price, char *_supplier, char *_material) {
		strcpy_s(supplier, _supplier);
		strcpy_s(material, _material);
		price = new float(_price);
	}
	virtual float Cost() = 0;
	char *GetSuppiler() {
		return supplier;
	}
	char *GetMaterial() {
		return material;
	}
	virtual ~Material() {
		delete price;
	}
};

class Pipes : public Material {
private:
	float *diameter;
	float *length;
public:
	Pipes() {}
	void Set(float _price, char *_supplier, char *_material, float _diameter, float _length) {
		SetMaterial(_price, _supplier, _material);
		diameter = new float(_diameter);
		length = new float(_length);
	}
	float Cost() {
		float cost;
		cost = ((*price) * (*length));
		return cost;
	}
	~Pipes() {
		delete diameter;
		delete length;
	}
};

class Rods : public Material {
private:
	float *diameter;
	float *length;
public:
	Rods() {}
	void Set(float _price, char *_supplier, char *_material, float _diameter, float _length) {
		SetMaterial(_price, _supplier, _material);
		diameter = new float(_diameter);
		length = new float(_length);
	}
	float Cost() {
		float cost;
		cost = ((*price) * (*length));
		return cost;
	}
	~Rods() {
		delete diameter;
		delete length;
	}
};

class Sheets : public Material {
private:
	float *thickness;
	float *width;
public:
	Sheets() {}
	void Set(float _price, char *_supplier, char *_material, float _thickness, float _width) {
		SetMaterial(_price, _supplier, _material);
		thickness = new float(_thickness);
		width = new float(_width);
	}
	float Cost() {
		float cost;
		cost = (*price) * ((*width) * (*thickness));
		return cost;
	}
	~Sheets() {
		delete thickness;
		delete width;
	}
};

class SolderingWire : public Material {
private:
	float *length;
	float *diameter;
public:
	void Set(float _price, char *_supplier, char *_material, float _length, float _diameter) {
		SetMaterial(_price, _supplier, _material);
		diameter = new float(_diameter);
		length = new float(_length);
	}
	float Cost() {
		float cost;
		cost = (*price) * ((*length) * (*diameter));
		return cost;
	}
	~SolderingWire() {
		delete length;
		delete diameter;
	}
};

class Engine {
private:
	char code[30];
	char descripiton[30];
	int quantity;
public:
	Engine() {}
	void SetEngine(char *_code, char *_description, int _quantity) {
		strcpy_s(code, _code);
		strcpy_s(descripiton, _description);
		quantity = _quantity;
	}
	char *GetCode() {
		return code;
	}
	char *GetDescription() {
		return descripiton;
	}
	int GetQuantity() {
		return quantity;
	}

	~Engine() {

	}
};


class Parts {
protected:
	char code[30];
	char description[30];
	float *price;
	int *quantity;
public:
	Parts() {}
	void SetPart(char *_code, char *_description, float _price, int _quantity) {
		strcpy_s(code, _code);
		strcpy_s(description, _description);
		price = new float(_price);
		quantity = new int(_quantity);
	}
	virtual float Cost() = 0;
	char *GetCode() {
		return code;
	}
	char *GetDescription() {
		return description;
	}
	int GetQuantity() {
		return *quantity;
	}
	virtual ~Parts() {
		delete price;
		delete quantity;
	}
};

class FanBlades : public Parts {
private:
	float *angle;
public:
	FanBlades() {}
	void Set(char *_code, char *_description, float _price, int _quantity, float _angle) {
		SetPart(_code, _description, _price, _quantity);
		angle = new float(_angle);
	}
	float Cost() {
		float cost;
		cost = (*price) * (*quantity) * (*angle);
		return cost;
	}
	~FanBlades() {
		delete angle;
	}
};

class Spinner : public Parts {
private:
	float *area;
public:
	Spinner() {}
	void Set(char *_code, char *_description, float _price, int _quantity, float _area) {
		SetPart(_code, _description, _price, _quantity);
		area = new float(_area);
	}
	float Cost() {
		float cost;
		cost = (*price) * (*quantity) * (*area);
		return cost;
	}
	~Spinner() {
		delete area;
	}
};

class HighPressureCompressor : public Parts {
private:
	int *count;
public:
	HighPressureCompressor() {}
	void Set(char *_code, char *_description, float _price, int _quantity, int _count) {
		SetPart(_code, _description, _price, _quantity);
		count = new int(_count);
	}
	float Cost() {
		float cost;
		cost = (*price) * (*quantity) * (*count);
		return cost;
	}
	~HighPressureCompressor() {
		delete count;
	}

};

class CombustionChamber : public Parts {
private:
	float *volume;
public:
	CombustionChamber() {}
	void Set(char *_code, char *_description, float _price, int _quantity, float _volume) {
		SetPart(_code, _description, _price, _quantity);
		volume = new float(_volume);
	}
	float Cost() {
		float cost;
		cost = (*price) * (*quantity) * ((*volume) / 100);
		return cost;
	}
	~CombustionChamber() {
		delete volume;
	}
};

class HighPressureTurbine : public Parts {
private:
	int *count;
public:
	HighPressureTurbine() {}
	void Set(char *_code, char *_description, float _price, int _quantity, int _count) {
		SetPart(_code, _description, _price, _quantity);
		count = new int(_count);
	}
	float Cost() {
		float cost;
		cost = (*price) * (*quantity) * (*count);
		return cost;
	}
	~HighPressureTurbine() {
		delete count;
	}
};


class LowPressureTurbine : public Parts {
private:
	int *count;
public:
	LowPressureTurbine() {}
	void Set(char *_code, char *_description, float _price, int _quantity, int _count) {
		SetPart(_code, _description, _price, _quantity);
		count = new int(_count);
	}
	float Cost() {
		float cost;
		cost = (*price) * (*quantity) * (*count);
		return cost;
	}
	~LowPressureTurbine() {
		delete count;
	}
};

class Unit {
private:
	char code[30];
	char description[30];
	float *price;
	int *quantity;

public:
	Unit() {}
	void SetUnit(char *_code, char *_description, int _quantity, float _price) {
		strcpy_s(code, _code);
		strcpy_s(description, _description);
		price = new float(_price);
		quantity = new int(_quantity);
	}
	float Cost() {
		float cost;
		cost = (*price) * (*quantity);
		return cost;
	}
	char *GetCode() {
		return code;
	}
	char *GetDescription() {
		return description;
	}
	int GetQuantity() {
		return *quantity;
	}
	~Unit() {
		delete quantity;
		delete price;
	}
};

class Part {
protected:
	char integration[30];
	char code[30];
	int *quantity;
	float *price;
public:
	Part() {}
	void SetPart(char *_integration, char *_code, int _quantity, float _price) {
		strcpy_s(integration, _integration);
		strcpy_s(code, _code);
		quantity = new int(_quantity);
		price = new float(_price);
	}
	virtual float Cost() = 0;
	char *GetIntegration() {
		return integration;
	}
	char *GetCode() {
		return code;
	}
	int GetQuaintity() {
		return *quantity;
	}
	virtual ~Part() {
		delete quantity;
		delete price;
	}
};

class Resistor : public Part {
private:
	int *resistance;
public:
	Resistor() {}
	void Set(char *_integration, char *_code, int _quantity, float _price) {
		SetPart(_integration, _code, _quantity, _price);
		resistance = new int(ResistanceVal(_code));
	}
	float Cost() {
		float cost;
		cost = (*price) * (*quantity);
		return cost;
	}
	int *GetResistance() {
		return resistance;
	}
	~Resistor() {
		delete resistance;
	}
private:
	int ResistanceVal(char *_code) {
		int codeLength = strlen(_code);
		int resistance = 0;
		int power = 0;
		int multiplier = 0;
		for (int i = 0; i < codeLength; i++) {
			if (isdigit(_code[i])) {
				power++;
			}
		}
		for (int i = 0; i < codeLength; i++) {
			power--;
			resistance = resistance + ((((int)_code[i] - 48)) * pow(10, power)); // 48 ASCII - Where numbers start
		}
		multiplier = resistance % 10; // Last Digit (Multiplier)
		resistance = resistance / 10;
		resistance *= pow(10, multiplier); // Real Resistance
		return resistance;
	}
};

class Capacitor : public Part {
private:
	int *capacity;
	float *voltage;
	float *tolerance;
public:
	Capacitor() {}
	void Set(char *_integration, char *_code, int _quantity, float _price) {
		SetPart(_integration, _code, _quantity, _price);
		capacity = new int(CapacityVal(_code));
		voltage = new float(VoltageVal(_code));
		tolerance = new float(ToleranceVal(_code));
	}
	float Cost() {
		float cost;
		cost = (*price) * (*quantity);
		return cost;
	}
	int GetCapacity() {
		return *capacity;
	}
	float GetVoltage() {
		return *voltage;
	}
	float GetTolernace() {
		return *tolerance;
	}
	~Capacitor() {
		delete capacity;
		delete voltage;
		delete tolerance;
	}
private:
	int CapacityVal(char *_code) {
		int codeLength = strlen(_code);
		int multiplier = 0;
		int power = 0;
		int capacity = 0;
		for (int i = 0; i < codeLength; i++) {
			if (isdigit(_code[i])) {
				power++;
			}
		}
		for (int i = 0; i < codeLength; i++) {
			if (isdigit(_code[i]))
				power--;
			capacity = capacity + ((((int)_code[i]) - 48) * pow(10, power));
		}
		multiplier = capacity % 10;
		capacity /= 10;
		capacity *= pow(10, multiplier);
		return capacity;
	}
	int VoltageVal(char *_code) {
		int codeLength = strlen(_code);
		float voltage = 0;
		for (int i = 0; i < codeLength; i++) {
			switch (_code[i])
			{
			case 'e':
				voltage = 2.5;
			case 'G':
				voltage = 4;
				break;
			case 'J':
				voltage = 6.3;
				break;
			case 'A':
				voltage = 10;
				break;
			case 'C':
				voltage = 16;
				break;
			case 'D':
				voltage = 20;
				break;
			case 'E':
				voltage = 25;
				break;
			case 'V':
				voltage = 35;
				break;
			case 'H':
				voltage = 50;
				break;
			default:
				voltage = 0;
				break;
			}
			if (voltage > 0) {
				break;
			}
		}
		return voltage;
	}
	// MAKE DOCUMENTATION FOR TOLERANCE
	int ToleranceVal(char *_code) {
		float tolerance = 0;
		int codeLegnth = strlen(_code);
		for (int i = 0; i < codeLegnth; i++) {
			switch (_code[i]) {
			case 'M':
				tolerance = 20;
				break;
			case 'K':
				tolerance = 10;
				break;
			case 'I':
				tolerance = 5;
				break;
			case 'Z':
				tolerance = 2;
				break;
			case 'F':
				tolerance = 1;
				break;
			case 'S':
				tolerance = 0.5;
				break;
			case'X':
				tolerance = 0.25;
				break;
			case'B':
				tolerance = 0.1;
				break;
			default:
				tolerance = 0;
				break;
			}
			if (tolerance > 0) {
				break;
			}
		}
		return tolerance;
	}
};

class SemiConductor : public Part {
private:
	char type[30];
	char manufacturer[30];
public:
	SemiConductor() {}
	void Set(char *_integration, char *_code, int _quantity, float _price) {
		SetPart(_integration, _code, _quantity, _price);
		strcpy_s(type, Type(_code));
		strcpy_s(manufacturer, Manufacturer(_code));
	}
	float Cost() {
		float cost;
		cost = (*price) * (*quantity);
		return cost;
	}
	char *GetType() {
		return type;
	}
	char *GetManufacturer() {
		return manufacturer;
	}
	~SemiConductor() {
		delete type;
		delete manufacturer;
	}
private:
	char* Type(char *_code) {
		char type[200];
		int codeLength = strlen(_code);
		for (int i = 0; i < codeLength; i++) {
			_code[i] = toupper(_code[i]);
		}
		switch (_code[0]) {
		case'A':
			strcpy_s(type, "Germanium ");
			break;
		case'B':
			strcpy_s(type, "Silicon ");
			break;
		case'C':
			strcpy_s(type, "Galium Arsenide ");
			break;
		case'R':
			strcpy_s(type, "Compound Materials ");
			break;
		default:
			break;
		}
		switch (_code[1]) {
		case'A':
			strcat_s(type, "Signal Diode ");
			break;
		case 'B':
			strcat_s(type, "Variable Capacitance Diode ");
			break;
		case 'C':
			strcat_s(type, "Low Power Audio Frequency Transistor ");
			break;
		case 'D':
			strcat_s(type, "Audio Frequency Power Transistor ");
			break;
		case 'E':
			strcat_s(type, "Tunnel Diode ");
			break;
		case 'F':
			strcat_s(type, "High Frequency Low Power Transistor ");
			break;
		case 'G':
			strcat_s(type, "Miscellaneous devices ");
			break;
		case 'H':
			strcat_s(type, "Magnetism Sensitive Diode ");
			break;
		case 'L':
			strcat_s(type, "High Frequency High Power Transistor ");
			break;
		case 'N':
			strcat_s(type, "Photocoupler ");
			break;
		case 'P':
			strcat_s(type, "Light Detector ");
			break;
		case 'Q':
			strcat_s(type, "Light Emitter ");
			break;
		case 'R':
			strcat_s(type, "Low Power Thyristor ");
			break;
		case 'S':
			strcat_s(type, "Low Power Switching Transistor ");
			break;
		case 'T':
			strcat_s(type, "Low Power Switching Triac ");
			break;
		case 'U':
			strcat_s(type, "Switching Power Transistor ");
			break;
		case 'W':
			strcat_s(type, "Surface Acoustic Wave Device ");
			break;
		case 'X':
			strcat_s(type, "Diode Multiplier ");
			break;
		case 'Y':
			strcat_s(type, "Diode Rectyfing ");
			break;
		case 'Z':
			strcat_s(type, "Voltage Reference Diode ");
			break;
		default:
			break;
		}
		return type;
	}
	char* Manufacturer(char *_code) {
		int codeLength = strlen(_code);
		char manufacturer[200];
		for (int i = 0; i < codeLength; i++) {
			_code[i] = toupper(_code[i]);
		}
		if ((_code[2] == 'M') && (_code[3] == 'J')) {
			strcpy_s(manufacturer, "Motorola Power Metal Case");
		}
		else if ((_code[2] == 'M') && (_code[3] == 'J') && (_code[4] == 'E')) {
			strcpy_s(manufacturer, "Motorola Power Plastic Case");
		}
		else if ((_code[2] == 'M') && (_code[3] == 'P') && (_code[4] == 'S')) {
			strcpy_s(manufacturer, "Motorola Low Power Plastic Case");
		}
		else if ((_code[2] == 'M') && (_code[3] == 'R') && (_code[4] == 'F')) {
			strcpy_s(manufacturer, "Motorola RF transistor");
		}
		else if ((_code[2] == 'T') && (_code[3] == 'I') && (_code[4] == 'P')) {
			strcpy_s(manufacturer, "Texas Instruments Power Transistor Plastic Case");
		}
		else if ((_code[2] == 'T') && (_code[3] == 'I') && (_code[4] == 'P') && (_code[5] == 'L')) {
			strcpy_s(manufacturer, "Texas Instruments Planar Power Transistor");
		}
		else if ((_code[2] == 'T') && (_code[3] == 'I') && (_code[4] == 'S')) {
			strcpy_s(manufacturer, "Texas Instruments Small Signal Transistor Plastic Case");
		}
		else if ((_code[2] == 'Z') && (_code[3] == 'T')) {
			strcpy_s(manufacturer, "Ferranti");
		}
		else if ((_code[2] == 'Z') && (_code[3] == 'T') && (_code[4] == 'X')) {
			strcpy_s(manufacturer, "Ferranti");
		}
		return manufacturer;
	}
};



template <class T>
char LogIN(T *C, char *_username, char *_password) {
	C = new T();
	if ((strcmp(C->getUser(), _username) == 0) && (strcmp(C->getPassword(), _password) == 0)) {
		delete C;
		return 'g';
	}
	else if ((strcmp(C->getUser(), _username) != 0) && (strcmp(C->getPassword(), _password) == 0)) {
		delete C;
		return 'u';
	}
	else if ((strcmp(C->getUser(), _username) == 0) && (strcmp(C->getPassword(), _password) != 0)) {
		delete C;
		return 'p';
	}
	else {
		delete C;
		return 'b';
	}
}

bool FileValidity(char *filename) {
	if ((strcmp(filename, "Engines.ta") != 0) && (strcmp(filename, "Employment.ta") != 0) && (strcmp(filename, "FanBlades.ta") != 0) && (strcmp(filename, "Spinner.ta") != 0)
		&& (strcmp(filename, "HighPressureCompressor.ta") != 0) && (strcmp(filename, "HighPressureTurbine.ta") != 0) && (strcmp(filename, "LowPressureTurbine.ta") != 0)
		&& (strcmp(filename, "CombustionChamber.ta") != 0) && (strcmp(filename, "Enclosure.ta") != 0) && (strcmp(filename, "Capacitor.ta") != 0) && (strcmp(filename, "Resistor.ta") != 0)
		&& (strcmp(filename, "SemiConductor.ta") != 0) && (strcmp(filename, "ControlUnits.ta") != 0) && (strcmp(filename, "Pipes.ta") != 0) && (strcmp(filename, "Rods.ta") != 0)
		&& (strcmp(filename, "Sheets.ta") != 0) && (strcmp(filename, "SolderingWire.ta") != 0)) {
		return false;
	}
	else {
		return true;
	}
}

int main(){
	char username[40];
	char password[40];
LOG:
	Executive *C = new Executive();
	Manager *M = new Manager();
	Acc *A = new Acc();
	SetConsoleTextAttribute(hStdOut, 15);
	DrawLogIn();
	gotoxy(37, 11);
	cin >> username;
	gotoxy(37, 16);
	cin >> password;
	if ((strcmp(C->getUser(), username)) == 0) {
		delete M;
		delete A;
		switch (LogIN(C, username, password)) {
		case 'g':
			SetConsoleTextAttribute(hStdOut, 10);
			gotoxy(48, 19);
			cout << "ACCESS GRANTED" << endl; // 15 karakteri
			Sleep(2000);
			system("CLS");
			delete C;
			break;
		case 'u':
			SetConsoleTextAttribute(hStdOut, 4);
			gotoxy(46, 19);
			cout << "USERNAME INCORRECT" << endl; // 19 karakteri
			Sleep(2000);
			system("CLS");
			goto LOG;
			break;
		case 'p':
			SetConsoleTextAttribute(hStdOut, 4);
			gotoxy(46, 19);
			cout << "PASSWORD INCORRECT" << endl; // 19 karakteri
			Sleep(2000);
			system("CLS");
			goto LOG;
			break;
		case 'b':
			SetConsoleTextAttribute(hStdOut, 4);
			gotoxy(41, 19);
			cout << "USERNAME & PASSWORD INCORRECT " << endl; // 30 karakteri
			Sleep(2000);
			system("CLS");
			goto LOG;
			break;
		}
	}
	else if ((strcmp(M->getUser(), username)) == 0) {
		delete C;
		delete A;
		switch (LogIN(M, username, password)) {
		case 'g':
			SetConsoleTextAttribute(hStdOut, 10);
			gotoxy(48, 19);
			cout << "ACCESS GRANTED" << endl; // 15 karakteri
			Sleep(2000);
			system("CLS");
			delete C;
			break;
		case 'u':
			SetConsoleTextAttribute(hStdOut, 4);
			gotoxy(46, 19);
			cout << "USERNAME INCORRECT" << endl; // 19 karakteri
			Sleep(2000);
			system("CLS");
			goto LOG;
			break;
		case 'p':
			SetConsoleTextAttribute(hStdOut, 4);
			gotoxy(46, 19);
			cout << "PASSWORD INCORRECT" << endl; // 19 karakteri
			Sleep(2000);
			system("CLS");
			goto LOG;
			break;
		case 'b':
			SetConsoleTextAttribute(hStdOut, 4);
			gotoxy(41, 19);
			cout << "USERNAME & PASSWORD INCORRECT " << endl; // 30 karakteri
			Sleep(2000);
			system("CLS");
			goto LOG;
			break;
		}
	}
	else if ((strcmp(A->getUser(), username) == 0)) {
		delete M;
		delete C;
		switch (LogIN(A, username, password)) {
			case 'g':
				SetConsoleTextAttribute(hStdOut, 10);
					gotoxy(48, 19);
					cout << "ACCESS GRANTED" << endl; // 15 karakteri
					Sleep(2000);
					system("CLS");
					delete C;
					break;
			case 'u':
				SetConsoleTextAttribute(hStdOut, 4);
				gotoxy(46, 19);
				cout << "USERNAME INCORRECT" << endl; // 19 karakteri
				Sleep(2000);
				system("CLS");
				goto LOG;
				break;
			case 'p':
				SetConsoleTextAttribute(hStdOut, 4);
				gotoxy(46, 19);
				cout << "PASSWORD INCORRECT" << endl; // 19 karakteri
				Sleep(2000);
				system("CLS");
				goto LOG;
				break;
			case 'b':
				SetConsoleTextAttribute(hStdOut, 4);
				gotoxy(41, 19);
				cout << "USERNAME & PASSWORD INCORRECT " << endl; // 30 karakteri
				Sleep(2000);
				system("CLS");
				goto LOG;
				break;
			}
	}
	else {
		SetConsoleTextAttribute(hStdOut, 4);
		gotoxy(47, 19);
		cout << "USER NOT FOUND" << endl; // 30 karakteri
		Sleep(2000);
		system("CLS");
		goto LOG;
	}
	DrawWelcome();
	SetConsoleTextAttribute(hStdOut, 15);
	Sleep(3000);
MainMenu:
	system("CLS");
	DrawMainMenu();
	int *choice = new int(0);
	cin >> *choice;
	Sleep(600);
	if (*choice == 1) {
		delete choice;
	ViewTables:
		SetConsoleTextAttribute(hStdOut, 15);
		system("CLS");
		DrawTables();
		char filename[30];
		cin >> filename;
		if (!FileValidity(filename)) {
			if (strcmp(filename, "MainMenu") == 0) {
				Sleep(600);
				goto MainMenu;
			}
			else {
				SetConsoleTextAttribute(hStdOut, 4);
				gotoxy(50, 40);
				cout << "FILENAME NOT FOUND !!!" << endl;
				Sleep(1500);
				goto ViewTables;
			}

		}
		else {
			string Prog = "notepad++.exe";
			string TheFile = filename; // double backslashes!
			ShellExecute(NULL, "open", Prog.c_str(), TheFile.c_str(), NULL, SW_SHOWNORMAL);
			SetConsoleTextAttribute(hStdOut, 10);
			gotoxy(44, 40);
			cout << "THE FILE WILL BE OPENED SHORTLY !!!" << endl;
			Sleep(2000);
			SetConsoleTextAttribute(hStdOut, 15);
			goto ViewTables;
		}
	}
	else if (*choice == 2) {
		delete choice;
	EntryMenu:
		system("CLS");
		DrawMkEntry();
		int *entry = new int(0);
		cin >> *entry;
		if (*entry == 0) {
			delete entry;
			Sleep(600);
			goto MainMenu;
		}
		else if (*entry == 1) {
			delete entry;
			system("CLS");
			ofstream out;
			out.open("Engines.ta", ios::app);
			if (!out.is_open()) {
				gotoxy(45, 12);
				SetConsoleTextAttribute(hStdOut, 4);
				cout << "OUTPUT FILE CAN NOT BE OPEN" << endl;
				Sleep(1500);
				SetConsoleTextAttribute(hStdOut, 15);
				goto EntryMenu;
			}
			else {
				char code[30];
				char description[30];
				int *quantity = new int;
				DrawEngineInput();
				gotoxy(11, 9);
				cin >> code;
				gotoxy(36, 9);
				cin >> description;
				gotoxy(81, 9);
				cin >> *quantity;
				Engine *E = new Engine();
				E->SetEngine(code, description, *quantity);
				out << endl;
				out << E->GetCode() << "			" << E->GetDescription() << "					" << E->GetQuantity();
				out.close();
				gotoxy(40, 12);
				SetConsoleTextAttribute(hStdOut, 10);
				cout << "OUTPUT HAS BEEN WRITTEN IN FILE" << endl;
				out.close();
				delete quantity;
				delete E;
				Sleep(1500);
				SetConsoleTextAttribute(hStdOut, 15);
				goto EntryMenu;
			}
		}
		else if (*entry == 2) {
			delete entry;
		EmployeeEntry:
			system("CLS");
			DrawEmployeeEntry();
			int *employmentDepartment = new int(0);
			cin >> *employmentDepartment;
			if (*employmentDepartment == 1) {
				system("CLS");
				DrawEngineers();
				int *choice = new int(0);
				cin >> *choice;
				if (*choice == 1) {
					system("CLS");
					ofstream out;
					out.open("Employment.ta", ios::app);
					if (!out.is_open()) {
						gotoxy(45, 12);
						SetConsoleTextAttribute(hStdOut, 4);
						cout << "OUTPUT FILE CAN NOT BE OPEN" << endl;
						Sleep(1500);
						SetConsoleTextAttribute(hStdOut, 15);
						delete choice;
						goto MainMenu;
					}
					else {
						system("CLS");
						gotoxy(50, 4);
						cout << "MECHANICAL ENGINEER";
						DrawInputEngineer();
						char name[30];
						char surname[30];
						int *hours = new int(0);
						int *equipexpense = new int (0);
						int *bonus = new int(0);
						gotoxy(28, 9);
						cin >> name;
						gotoxy(41, 9);
						cin >> surname;
						gotoxy(54, 9);
						cin >> *hours;
						gotoxy(67, 9);
						cin >> *equipexpense;
						gotoxy(80, 9);
						cin >> *bonus;
						MechanicalEngineer *E = new MechanicalEngineer(name, surname, *hours, *equipexpense, *bonus);
						out << endl;
						out << E->getName() << "  " << E->getSurName() << "  " << E->GetPostion() << "  " << E->GetHours() << "h.  " << E->Paycheck() << "EUR. ";
						out.close();
						gotoxy(40, 12);
						SetConsoleTextAttribute(hStdOut, 10);
						cout << "OUTPUT HAS BEEN WRITTEN IN FILE" << endl;
						Sleep(1500);
						SetConsoleTextAttribute(hStdOut, 15);
						delete choice;
						delete E;
						delete bonus;
						delete equipexpense;
						delete hours;
						goto MainMenu;
					}
				}
				else if (*choice == 2) {
					system("CLS");
					ofstream out;
					out.open("Employment.ta", ios::app);
					if (!out.is_open()) {
						gotoxy(45, 12);
						SetConsoleTextAttribute(hStdOut, 4);
						cout << "OUTPUT FILE CAN NOT BE OPEN" << endl;
						Sleep(1500);
						SetConsoleTextAttribute(hStdOut, 15);
						delete choice;
						goto MainMenu;
					}
					else {
						system("CLS");
						gotoxy(50, 4);
						cout << "ELECTRICAL ENGINEER";
						DrawInputEngineer();
						char name[30];
						char surname[30];
						int *hours = new int(0);
						int *equipexpense = new int(0);
						int *bonus = new int(0);
						gotoxy(28, 9);
						cin >> name;
						gotoxy(41, 9);
						cin >> surname;
						gotoxy(54, 9);
						cin >> *hours;
						gotoxy(67, 9);
						cin >> *equipexpense;
						gotoxy(80, 9);
						cin >> *bonus;
						ElectricalEngineer *E = new ElectricalEngineer(name, surname, *hours, *equipexpense, *bonus);
						out << endl;
						out << E->getName() << "  " << E->getSurName() << "  " << E->GetPostion() << "  " << E->GetHours() << "h.  " << E->Paycheck() << "EUR. ";
						out.close();
						gotoxy(40, 12);
						SetConsoleTextAttribute(hStdOut, 10);
						cout << "OUTPUT HAS BEEN WRITTEN IN FILE" << endl;
						Sleep(1500);
						SetConsoleTextAttribute(hStdOut, 15);
						delete choice;
						delete E;
						delete bonus;
						delete equipexpense;
						delete hours;
						goto MainMenu;
					}

				}
				else if (*choice == 3) {
					system("CLS");
					ofstream out;
					out.open("Employment.ta", ios::app);
					if (!out.is_open()) {
						gotoxy(45, 12);
						SetConsoleTextAttribute(hStdOut, 4);
						cout << "OUTPUT FILE CAN NOT BE OPEN" << endl;
						Sleep(1500);
						SetConsoleTextAttribute(hStdOut, 15);
						delete choice;
						goto MainMenu;
					}
					else {
						system("CLS");
						gotoxy(50, 4);
						cout << "AERO ENGINEER";
						DrawInputEngineer();
						char name[30];
						char surname[30];
						int *hours = new int(0);
						int *equipexpense = new int(0);
						int *bonus = new int(0);
						gotoxy(28, 9);
						cin >> name;
						gotoxy(41, 9);
						cin >> surname;
						gotoxy(54, 9);
						cin >> *hours;
						gotoxy(67, 9);
						cin >> *equipexpense;
						gotoxy(80, 9);
						cin >> *bonus;
						AeroEngineer *E = new AeroEngineer(name, surname, *hours, *equipexpense, *bonus);
						out << endl;
						out << E->getName() << "  " << E->getSurName() << "  " << E->GetPostion() << "  " << E->GetHours() << "h.  " << E->Paycheck() << "EUR. ";
						out.close();
						gotoxy(40, 12);
						SetConsoleTextAttribute(hStdOut, 10);
						cout << "OUTPUT HAS BEEN WRITTEN IN FILE" << endl;
						Sleep(1500);
						SetConsoleTextAttribute(hStdOut, 15);
						delete choice;
						delete E;
						delete bonus;
						delete equipexpense;
						delete hours;
						goto MainMenu;
					}
				}
				else if (*choice == 4) {
					system("CLS");
					ofstream out;
					out.open("Employment.ta", ios::app);
					if (!out.is_open()) {
						gotoxy(45, 12);
						SetConsoleTextAttribute(hStdOut, 4);
						cout << "OUTPUT FILE CAN NOT BE OPEN" << endl;
						Sleep(1500);
						SetConsoleTextAttribute(hStdOut, 15);
						delete choice;
						goto MainMenu;
					}
					else {
						system("CLS");
						gotoxy(50, 4);
						cout << "SOFTWARE ENGINEER";
						DrawInputEngineer();
						char name[30];
						char surname[30];
						int *hours = new int(0);
						int *equipexpense = new int(0);
						int *bonus = new int(0);
						gotoxy(28, 9);
						cin >> name;
						gotoxy(41, 9);
						cin >> surname;
						gotoxy(54, 9);
						cin >> *hours;
						gotoxy(67, 9);
						cin >> *equipexpense;
						gotoxy(80, 9);
						cin >> *bonus;
						SoftwareEngineer *E = new SoftwareEngineer(name, surname, *hours, *equipexpense, *bonus);
						out << endl;
						out << E->getName() << "  " << E->getSurName() << "  " << E->GetPostion() << "  " << E->GetHours() << "h.  " << E->Paycheck() << "EUR. ";
						out.close();
						gotoxy(40, 12);
						SetConsoleTextAttribute(hStdOut, 10);
						cout << "OUTPUT HAS BEEN WRITTEN IN FILE" << endl;
						Sleep(1500);
						SetConsoleTextAttribute(hStdOut, 15);
						delete choice;
						delete E;
						delete bonus;
						delete equipexpense;
						delete hours;
						goto MainMenu;
					}
				}
				else if (*choice == 5) {
					system("CLS");
					ofstream out;
					out.open("Employment.ta", ios::app);
					if (!out.is_open()) {
						gotoxy(45, 12);
						SetConsoleTextAttribute(hStdOut, 4);
						cout << "OUTPUT FILE CAN NOT BE OPEN" << endl;
						Sleep(1500);
						SetConsoleTextAttribute(hStdOut, 15);
						delete choice;
						goto MainMenu;
					}
					else {
						system("CLS");
						gotoxy(50, 4);
						cout << "SYSTEM ADMINISTRATOR";
						DrawInputEngineer();
						char name[30];
						char surname[30];
						int *hours = new int(0);
						int *equipexpense = new int(0);
						int *bonus = new int(0);
						gotoxy(28, 9);
						cin >> name;
						gotoxy(41, 9);
						cin >> surname;
						gotoxy(54, 9);
						cin >> *hours;
						gotoxy(67, 9);
						cin >> *equipexpense;
						gotoxy(80, 9);
						cin >> *bonus;
						SystemAdministrator *E = new SystemAdministrator(name, surname, *hours, *equipexpense, *bonus);
						out << endl;
						out << E->getName() << "  " << E->getSurName() << "  " << E->GetPostion() << "  " << E->GetHours() << "h.  " << E->Paycheck() << "EUR. ";
						out.close();
						gotoxy(40, 12);
						SetConsoleTextAttribute(hStdOut, 10);
						cout << "OUTPUT HAS BEEN WRITTEN IN FILE" << endl;
						Sleep(1500);
						SetConsoleTextAttribute(hStdOut, 15);
						delete choice;
						delete E;
						delete bonus;
						delete equipexpense;
						delete hours;
						goto MainMenu;
					}
				}
				else if (*choice == 0) {
					delete choice;
					goto MainMenu;
				}
				
			}
			else if (*employmentDepartment == 2) {
				system("CLS");
				DrawScientists();
				int *choice = new int(0);
				cin >> *choice;
				if (*choice == 1) {
					system("CLS");
					ofstream out;
					out.open("Employment.ta", ios::app);
					if (!out.is_open()) {
						gotoxy(45, 12);
						SetConsoleTextAttribute(hStdOut, 4);
						cout << "OUTPUT FILE CAN NOT BE OPEN" << endl;
						Sleep(1500);
						SetConsoleTextAttribute(hStdOut, 15);
						delete choice;
						goto MainMenu;
					}
					else {
						system("CLS");
						gotoxy(50, 4);
						cout << "PHYSICIST";
						DrawInputScientist();
						char name[30];
						char surname[30];
						int *hours = new int(0);
						int *fieldwork = new int(0);
						int *bonus = new int(0);
						gotoxy(28, 9);
						cin >> name;
						gotoxy(41, 9);
						cin >> surname;
						gotoxy(54, 9);
						cin >> *hours;
						gotoxy(67, 9);
						cin >> *fieldwork;
						gotoxy(80, 9);
						cin >> *bonus;
						Physicist *S = new Physicist(name, surname, *fieldwork, *hours, *bonus);
						out << endl;
						out << S->getName() << "  " << S->getSurName() << "  " << S->GetPostion() << "  " << S->GetHours() << "h.  " << S->Paycheck() << "EUR. ";
						out.close();
						gotoxy(40, 12);
						SetConsoleTextAttribute(hStdOut, 10);
						cout << "OUTPUT HAS BEEN WRITTEN IN FILE" << endl;
						Sleep(1500);
						SetConsoleTextAttribute(hStdOut, 15);
						delete choice;
						delete S;
						delete bonus;
						delete fieldwork;
						delete hours;
						goto MainMenu;
					}
				}
				else if (*choice == 2) {
					system("CLS");
					ofstream out;
					out.open("Employment.ta", ios::app);
					if (!out.is_open()) {
						gotoxy(45, 12);
						SetConsoleTextAttribute(hStdOut, 4);
						cout << "OUTPUT FILE CAN NOT BE OPEN" << endl;
						Sleep(1500);
						SetConsoleTextAttribute(hStdOut, 15);
						delete choice;
						goto MainMenu;
					}
					else {
						system("CLS");
						gotoxy(50, 4);
						cout << "CHEMIST";
						DrawInputScientist();
						char name[30];
						char surname[30];
						int *hours = new int(0);
						int *fieldwork = new int(0);
						int *bonus = new int(0);
						gotoxy(28, 9);
						cin >> name;
						gotoxy(41, 9);
						cin >> surname;
						gotoxy(54, 9);
						cin >> *hours;
						gotoxy(67, 9);
						cin >> *fieldwork;
						gotoxy(80, 9);
						cin >> *bonus;
						Chemist *S = new Chemist(name, surname, *fieldwork, *hours, *bonus);
						out << endl;
						out << S->getName() << "  " << S->getSurName() << "  " << S->GetPostion() << "  " << S->GetHours() << "h.  " << S->Paycheck() << "EUR. ";
						out.close();
						gotoxy(40, 12);
						SetConsoleTextAttribute(hStdOut, 10);
						cout << "OUTPUT HAS BEEN WRITTEN IN FILE" << endl;
						Sleep(1500);
						SetConsoleTextAttribute(hStdOut, 15);
						delete choice;
						delete S;
						delete bonus;
						delete fieldwork;
						delete hours;
						goto MainMenu;
					}
				}
				else if (*choice == 3) {
					system("CLS");
					ofstream out;
					out.open("Employment.ta", ios::app);
					if (!out.is_open()) {
						gotoxy(45, 12);
						SetConsoleTextAttribute(hStdOut, 4);
						cout << "OUTPUT FILE CAN NOT BE OPEN" << endl;
						Sleep(1500);
						SetConsoleTextAttribute(hStdOut, 15);
						delete choice;
						goto MainMenu;
					}
					else {
						system("CLS");
						gotoxy(50, 4);
						cout << "MATHEMATICIAN : ";
						DrawInputScientist();
						char name[30];
						char surname[30];
						int *hours = new int(0);
						int *fieldwork = new int(0);
						int *bonus = new int(0);
						gotoxy(28, 9);
						cin >> name;
						gotoxy(41, 9);
						cin >> surname;
						gotoxy(54, 9);
						cin >> *hours;
						gotoxy(67, 9);
						cin >> *fieldwork;
						gotoxy(80, 9);
						cin >> *bonus;
						Mathematician *S = new Mathematician(name, surname, *fieldwork, *hours, *bonus);
						out << endl;
						out << S->getName() << "  " << S->getSurName() << "  " << S->GetPostion() << "  " << S->GetHours() << "h.  " << S->Paycheck() << "EUR. ";
						out.close();
						gotoxy(40, 12);
						SetConsoleTextAttribute(hStdOut, 10);
						cout << "OUTPUT HAS BEEN WRITTEN IN FILE" << endl;
						Sleep(1500);
						SetConsoleTextAttribute(hStdOut, 15);
						delete choice;
						delete S;
						delete bonus;
						delete fieldwork;
						delete hours;
						goto MainMenu;
					}
				}
				else if (*choice == 0) {
					delete choice;
					goto MainMenu;
				}
			}
			else if (*employmentDepartment == 3) {
				system("CLS");
				DrawAdministration();
				int *choice = new int(0);
				cin >> *choice;
				if (*choice == 1) {
					system("CLS");
					ofstream out;
					out.open("Employment.ta", ios::app);
					if (!out.is_open()) {
						gotoxy(45, 12);
						SetConsoleTextAttribute(hStdOut, 4);
						cout << "OUTPUT FILE CAN NOT BE OPEN" << endl;
						Sleep(1500);
						SetConsoleTextAttribute(hStdOut, 15);
						delete choice;
						goto MainMenu;
					}
					else {
						system("CLS");
						gotoxy(50, 4);
						cout << "ACCOUNTANT";
						DrawInputAdministration();
						char name[30];
						char surname[30];
						int *hours = new int(0);
						int *trvlexpense = new int(0);
						int *bonus = new int(0);
						gotoxy(28, 9);
						cin >> name;
						gotoxy(41, 9);
						cin >> surname;
						gotoxy(54, 9);
						cin >> *hours;
						gotoxy(67, 9);
						cin >> *trvlexpense;
						gotoxy(80, 9);
						cin >> *bonus;
						Accountant *A = new Accountant(name, surname, *trvlexpense, *hours, *bonus);
						out << endl;
						out << A->getName() << "  " << A->getSurName() << "  " << A->GetPostion() << "  " << A->GetHours() << "h.  " << A->Paycheck() << "EUR. ";
						out.close();
						gotoxy(40, 12);
						SetConsoleTextAttribute(hStdOut, 10);
						cout << "OUTPUT HAS BEEN WRITTEN IN FILE" << endl;
						Sleep(1500);
						SetConsoleTextAttribute(hStdOut, 15);
						delete choice;
						delete A;
						delete bonus;
						delete trvlexpense;
						delete hours;
						goto MainMenu;
					}
				}
				else if (*choice == 2) {
					system("CLS");
					ofstream out;
					out.open("Employment.ta", ios::app);
					if (!out.is_open()) {
						gotoxy(45, 12);
						SetConsoleTextAttribute(hStdOut, 4);
						cout << "OUTPUT FILE CAN NOT BE OPEN" << endl;
						Sleep(1500);
						SetConsoleTextAttribute(hStdOut, 15);
						delete choice;
						goto MainMenu;
					}
					else {
						system("CLS");
						gotoxy(50, 4);
						cout << "LEGAL";
						DrawInputAdministration();
						char name[30];
						char surname[30];
						int *hours = new int(0);
						int *trvlexpense = new int(0);
						int *bonus = new int(0);
						gotoxy(28, 9);
						cin >> name;
						gotoxy(41, 9);
						cin >> surname;
						gotoxy(54, 9);
						cin >> *hours;
						gotoxy(67, 9);
						cin >> *trvlexpense;
						gotoxy(80, 9);
						cin >> *bonus;
						Legal *A = new Legal(name, surname, *trvlexpense, *hours, *bonus);
						out << endl;
						out << A->getName() << "  " << A->getSurName() << "  " << A->GetPostion() << "  " << A->GetHours() << "h.  " << A->Paycheck() << "EUR. ";
						out.close();
						gotoxy(40, 12);
						SetConsoleTextAttribute(hStdOut, 10);
						cout << "OUTPUT HAS BEEN WRITTEN IN FILE" << endl;
						Sleep(1500);
						SetConsoleTextAttribute(hStdOut, 15);
						delete choice;
						delete A;
						delete bonus;
						delete trvlexpense;
						delete hours;
						goto MainMenu;
					}
				}
				else if (*choice == 3) {
					system("CLS");
					ofstream out;
					out.open("Employment.ta", ios::app);
					if (!out.is_open()) {
						gotoxy(45, 12);
						SetConsoleTextAttribute(hStdOut, 4);
						cout << "OUTPUT FILE CAN NOT BE OPEN" << endl;
						Sleep(1500);
						SetConsoleTextAttribute(hStdOut, 15);
						delete choice;
						goto MainMenu;
					}
					else {
						system("CLS");
						gotoxy(50, 4);
						cout << "SECRETARY : ";
						DrawInputAdministration();
						char name[30];
						char surname[30];
						int *hours = new int(0);
						int *trvlexpense = new int(0);
						int *bonus = new int(0);
						gotoxy(28, 9);
						cin >> name;
						gotoxy(41, 9);
						cin >> surname;
						gotoxy(54, 9);
						cin >> *hours;
						gotoxy(67, 9);
						cin >> *trvlexpense;
						gotoxy(80, 9);
						cin >> *bonus;
						Secretary *A = new Secretary(name, surname, *trvlexpense, *hours, *bonus);
						out << endl;
						out << A->getName() << "  " << A->getSurName() << "  " << A->GetPostion() << "  " << A->GetHours() << "h.  " << A->Paycheck() << "EUR. ";
						out.close();
						gotoxy(40, 12);
						SetConsoleTextAttribute(hStdOut, 10);
						cout << "OUTPUT HAS BEEN WRITTEN IN FILE" << endl;
						Sleep(1500);
						SetConsoleTextAttribute(hStdOut, 15);
						delete choice;
						delete A;
						delete bonus;
						delete trvlexpense;
						delete hours;
						goto MainMenu;
					}
				}
				else if (*choice == 0) {
					delete choice;
					goto MainMenu;
				}
			}
			else if (*employmentDepartment == 4) {
				system("CLS");
				DrawScientists();
				int *choice = new int(0);
				cin >> *choice;
				if (*choice == 1) {
					system("CLS");
					ofstream out;
					out.open("Employment.ta", ios::app);
					if (!out.is_open()) {
						gotoxy(45, 12);
						SetConsoleTextAttribute(hStdOut, 4);
						cout << "OUTPUT FILE CAN NOT BE OPEN" << endl;
						Sleep(1500);
						SetConsoleTextAttribute(hStdOut, 15);
						delete choice;
						goto MainMenu;
					}
					else {
						system("CLS");
						gotoxy(50, 4);
						cout << "GRAPGICS DESIGNER";
						DrawInputArtist();
						char name[30];
						char surname[30];
						int *hours = new int(0);
						int *hndwrk = new int(0);
						int *bonus = new int(0);
						gotoxy(28, 9);
						cin >> name;
						gotoxy(41, 9);
						cin >> surname;
						gotoxy(54, 9);
						cin >> *hours;
						gotoxy(67, 9);
						cin >> *hndwrk;
						gotoxy(80, 9);
						cin >> *bonus;
						GraphicsDesigner *G = new GraphicsDesigner(name, surname, *hours, *bonus);
						out << endl;
						out << G->getName() << "  " << G->getSurName() << "  " << G->GetPostion() << "  " << G->GetHours() << "h.  " << G->Paycheck() << "EUR. ";
						out.close();
						gotoxy(40, 12);
						SetConsoleTextAttribute(hStdOut, 10);
						cout << "OUTPUT HAS BEEN WRITTEN IN FILE" << endl;
						Sleep(1500);
						SetConsoleTextAttribute(hStdOut, 15);
						delete choice;
						delete G;
						delete bonus;
						delete hndwrk;
						delete hours;
						goto MainMenu;
					}
				}
				else if (*choice == 2) {
					system("CLS");
					ofstream out;
					out.open("Employment.ta", ios::app);
					if (!out.is_open()) {
						gotoxy(45, 12);
						SetConsoleTextAttribute(hStdOut, 4);
						cout << "OUTPUT FILE CAN NOT BE OPEN" << endl;
						Sleep(1500);
						SetConsoleTextAttribute(hStdOut, 15);
						delete choice;
						goto MainMenu;
					}
					else {
						system("CLS");
						gotoxy(50, 4);
						cout << "PAINTER";
						DrawInputArtist();
						char name[30];
						char surname[30];
						int *hours = new int(0);
						int *hndwrk = new int(0);
						int *bonus = new int(0);
						gotoxy(28, 9);
						cin >> name;
						gotoxy(41, 9);
						cin >> surname;
						gotoxy(54, 9);
						cin >> *hours;
						gotoxy(67, 9);
						cin >> *hndwrk;
						gotoxy(80, 9);
						cin >> *bonus;
						Painter *G = new Painter(name, surname, *hours, *hndwrk, *bonus);
						out << endl;
						out << G->getName() << "  " << G->getSurName() << "  " << G->GetPostion() << "  " << G->GetHours() << "h.  " << G->Paycheck() << "EUR. ";
						out.close();
						gotoxy(40, 12);
						SetConsoleTextAttribute(hStdOut, 10);
						cout << "OUTPUT HAS BEEN WRITTEN IN FILE" << endl;
						Sleep(1500);
						SetConsoleTextAttribute(hStdOut, 15);
						delete choice;
						delete G;
						delete bonus;
						delete hndwrk;
						delete hours;
						goto MainMenu;
					}
				}
				else if (*choice == 3) {
					system("CLS");
					ofstream out;
					out.open("Employment.ta", ios::app);
					if (!out.is_open()) {
						gotoxy(45, 12);
						SetConsoleTextAttribute(hStdOut, 4);
						cout << "OUTPUT FILE CAN NOT BE OPEN" << endl;
						Sleep(1500);
						SetConsoleTextAttribute(hStdOut, 15);
						delete choice;
						goto MainMenu;
					}
					else {
						system("CLS");
						gotoxy(50, 4);
						cout << "UX DESIGNER";
						DrawInputArtist();
						char name[30];
						char surname[30];
						int *hours = new int(0);
						int *hndwrk = new int(0);
						int *bonus = new int(0);
						gotoxy(28, 9);
						cin >> name;
						gotoxy(41, 9);
						cin >> surname;
						gotoxy(54, 9);
						cin >> *hours;
						gotoxy(67, 9);
						cin >> *hndwrk;
						gotoxy(80, 9);
						cin >> *bonus;
						UXDesginer *G = new UXDesginer(name, surname, *hours, *bonus);
						out << endl;
						out << G->getName() << "  " << G->getSurName() << "  " << G->GetPostion() << "  " << G->GetHours() << "h.  " << G->Paycheck() << "EUR. ";
						out.close();
						gotoxy(40, 12);
						SetConsoleTextAttribute(hStdOut, 10);
						cout << "OUTPUT HAS BEEN WRITTEN IN FILE" << endl;
						Sleep(1500);
						SetConsoleTextAttribute(hStdOut, 15);
						delete choice;
						delete G;
						delete bonus;
						delete hndwrk;
						delete hours;
						goto MainMenu;
					}
				}
				else if (*choice == 0) {
					delete choice;
					goto MainMenu;
				}
			}
			else if (*employmentDepartment == 5) {
				DrawHighLevelAdministartion();
				int *choice = new int(0);
				cin >> *choice;
				if (*choice == 1) {
					system("CLS");
					ofstream out;
					out.open("Employment.ta", ios::app);
					if (!out.is_open()) {
						gotoxy(45, 12);
						SetConsoleTextAttribute(hStdOut, 4);
						cout << "OUTPUT FILE CAN NOT BE OPEN" << endl;
						Sleep(1500);
						SetConsoleTextAttribute(hStdOut, 15);
						delete choice;
						goto MainMenu;
					}
					else {
						system("CLS");
						gotoxy(50, 4);
						cout << "CEO";
						DrawInputHighLevelAdministration();
						char name[30];
						char surname[30];
						int *hours = new int(0);
						int *trvlexpense = new int(0);
						int *bonus = new int(0);
						gotoxy(28, 9);
						cin >> name;
						gotoxy(41, 9);
						cin >> surname;
						gotoxy(54, 9);
						cin >> *hours;
						gotoxy(67, 9);
						cin >> *trvlexpense;
						gotoxy(80, 9);
						cin >> *bonus;
						CEO *C = new CEO(name, surname, *hours, *trvlexpense, *bonus);
						out << endl;
						out << C->getName() << "  " << C->getSurName() << "  " << C->GetPostion() << "  " << C->GetHours() << "h.  " << C->Paycheck() << "EUR. ";
						out.close();
						gotoxy(40, 12);
						SetConsoleTextAttribute(hStdOut, 10);
						cout << "OUTPUT HAS BEEN WRITTEN IN FILE" << endl;
						Sleep(1500);
						SetConsoleTextAttribute(hStdOut, 15);
						delete choice;
						delete C;
						delete bonus;
						delete trvlexpense;
						delete hours;
						goto MainMenu;
					}
				}
				else if (*choice == 2) {
					system("CLS");
					ofstream out;
					out.open("Employment.ta", ios::app);
					if (!out.is_open()) {
						gotoxy(45, 12);
						SetConsoleTextAttribute(hStdOut, 4);
						cout << "OUTPUT FILE CAN NOT BE OPEN" << endl;
						Sleep(1500);
						SetConsoleTextAttribute(hStdOut, 15);
						delete choice;
						goto MainMenu;
					}
					else {
						system("CLS");
						gotoxy(50, 4);
						cout << "HEAD OF ENGINEERING";
						DrawInputHighLevelAdministration();
						char name[30];
						char surname[30];
						int *hours = new int(0);
						int *trvlexpense = new int(0);
						int *bonus = new int(0);
						gotoxy(28, 9);
						cin >> name;
						gotoxy(41, 9);
						cin >> surname;
						gotoxy(54, 9);
						cin >> *hours;
						gotoxy(67, 9);
						cin >> *trvlexpense;
						gotoxy(80, 9);
						cin >> *bonus;
						HeadOfEngineering *C = new HeadOfEngineering(name, surname, *hours, *trvlexpense, *bonus);
						out << endl;
						out << C->getName() << "  " << C->getSurName() << "  " << C->GetPostion() << "  " << C->GetHours() << "h.  " << C->Paycheck() << "EUR. ";
						out.close();
						gotoxy(40, 12);
						SetConsoleTextAttribute(hStdOut, 10);
						cout << "OUTPUT HAS BEEN WRITTEN IN FILE" << endl;
						Sleep(1500);
						SetConsoleTextAttribute(hStdOut, 15);
						delete choice;
						delete C;
						delete bonus;
						delete trvlexpense;
						delete hours;
						goto MainMenu;
					}
				}
				else if (*choice == 3) {
					system("CLS");
					ofstream out;
					out.open("Employment.ta", ios::app);
					if (!out.is_open()) {
						gotoxy(45, 12);
						SetConsoleTextAttribute(hStdOut, 4);
						cout << "OUTPUT FILE CAN NOT BE OPEN" << endl;
						Sleep(1500);
						SetConsoleTextAttribute(hStdOut, 15);
						delete choice;
						goto MainMenu;
					}
					else {
						system("CLS");
						gotoxy(50, 4);
						cout << "HEAD OF MARKETING";
						DrawInputHighLevelAdministration();
						char name[30];
						char surname[30];
						int *hours = new int(0);
						int *trvlexpense = new int(0);
						int *bonus = new int(0);
						gotoxy(28, 9);
						cin >> name;
						gotoxy(41, 9);
						cin >> surname;
						gotoxy(54, 9);
						cin >> *hours;
						gotoxy(67, 9);
						cin >> *trvlexpense;
						gotoxy(80, 9);
						cin >> *bonus;
						HeadOfMarketing *C = new HeadOfMarketing(name, surname, *hours, *trvlexpense, *bonus);
						out << endl;
						out << C->getName() << "  " << C->getSurName() << "  " << C->GetPostion() << "  " << C->GetHours() << "h.  " << C->Paycheck() << "EUR. ";
						out.close();
						gotoxy(40, 12);
						SetConsoleTextAttribute(hStdOut, 10);
						cout << "OUTPUT HAS BEEN WRITTEN IN FILE" << endl;
						Sleep(1500);
						SetConsoleTextAttribute(hStdOut, 15);
						delete choice;
						delete C;
						delete bonus;
						delete trvlexpense;
						delete hours;
						goto MainMenu;
					}
				}
				else if (*choice == 4) {
					system("CLS");
					ofstream out;
					out.open("Employment.ta", ios::app);
					if (!out.is_open()) {
						gotoxy(45, 12);
						SetConsoleTextAttribute(hStdOut, 4);
						cout << "OUTPUT FILE CAN NOT BE OPEN" << endl;
						Sleep(1500);
						SetConsoleTextAttribute(hStdOut, 15);
						delete choice;
						goto MainMenu;
					}
					else {
						system("CLS");
						gotoxy(50, 4);
						cout << "HEAD OF DESIGN";
						DrawInputHighLevelAdministration();
						char name[30];
						char surname[30];
						int *hours = new int(0);
						int *trvlexpense = new int(0);
						int *bonus = new int(0);
						gotoxy(28, 9);
						cin >> name;
						gotoxy(41, 9);
						cin >> surname;
						gotoxy(54, 9);
						cin >> *hours;
						gotoxy(67, 9);
						cin >> *trvlexpense;
						gotoxy(80, 9);
						cin >> *bonus;
						HeadOfDesign *C = new HeadOfDesign(name, surname, *hours, *trvlexpense, *bonus);
						out << endl;
						out << C->getName() << "  " << C->getSurName() << "  " << C->GetPostion() << "  " << C->GetHours() << "h.  " << C->Paycheck() << "EUR. ";
						out.close();
						gotoxy(40, 12);
						SetConsoleTextAttribute(hStdOut, 10);
						cout << "OUTPUT HAS BEEN WRITTEN IN FILE" << endl;
						Sleep(1500);
						SetConsoleTextAttribute(hStdOut, 15);
						delete choice;
						delete C;
						delete bonus;
						delete trvlexpense;
						delete hours;
						goto MainMenu;
					}
				}
				else if (*choice == 5) {
					system("CLS");
					ofstream out;
					out.open("Employment.ta", ios::app);
					if (!out.is_open()) {
						gotoxy(45, 12);
						SetConsoleTextAttribute(hStdOut, 4);
						cout << "OUTPUT FILE CAN NOT BE OPEN" << endl;
						Sleep(1500);
						SetConsoleTextAttribute(hStdOut, 15);
						delete choice;
						goto MainMenu;
					}
					else {
						system("CLS");
						gotoxy(50, 4);
						cout << "HEAD OF ADMINITSRATION";
						DrawInputHighLevelAdministration();
						char name[30];
						char surname[30];
						int *hours = new int(0);
						int *trvlexpense = new int(0);
						int *bonus = new int(0);
						gotoxy(28, 9);
						cin >> name;
						gotoxy(41, 9);
						cin >> surname;
						gotoxy(54, 9);
						cin >> *hours;
						gotoxy(67, 9);
						cin >> *trvlexpense;
						gotoxy(80, 9);
						cin >> *bonus;
						HeadOfAdministration *C = new HeadOfAdministration(name, surname, *hours, *trvlexpense, *bonus);
						out << endl;
						out << C->getName() << "  " << C->getSurName() << "  " << C->GetPostion() << "  " << C->GetHours() << "h.  " << C->Paycheck() << "EUR. ";
						out.close();
						gotoxy(40, 12);
						SetConsoleTextAttribute(hStdOut, 10);
						cout << "OUTPUT HAS BEEN WRITTEN IN FILE" << endl;
						Sleep(1500);
						SetConsoleTextAttribute(hStdOut, 15);
						delete choice;
						delete C;
						delete bonus;
						delete trvlexpense;
						delete hours;
						goto MainMenu;
					}
				}
				else if (*choice == 6) {
					system("CLS");
					ofstream out;
					out.open("Employment.ta", ios::app);
					if (!out.is_open()) {
						gotoxy(45, 12);
						SetConsoleTextAttribute(hStdOut, 4);
						cout << "OUTPUT FILE CAN NOT BE OPEN" << endl;
						Sleep(1500);
						SetConsoleTextAttribute(hStdOut, 15);
						delete choice;
						goto MainMenu;
					}
					else {
						system("CLS");
						gotoxy(50, 4);
						cout << "HEAD OF SCIENCE";
						DrawInputHighLevelAdministration();
						char name[30];
						char surname[30];
						int *hours = new int(0);
						int *trvlexpense = new int(0);
						int *bonus = new int(0);
						gotoxy(28, 9);
						cin >> name;
						gotoxy(41, 9);
						cin >> surname;
						gotoxy(54, 9);
						cin >> *hours;
						gotoxy(67, 9);
						cin >> *trvlexpense;
						gotoxy(80, 9);
						cin >> *bonus;
						HeadOfScience *C = new HeadOfScience(name, surname, *hours, *trvlexpense, *bonus);
						out << endl;
						out << C->getName() << "  " << C->getSurName() << "  " << C->GetPostion() << "  " << C->GetHours() << "h.  " << C->Paycheck() << "EUR. ";
						out.close();
						gotoxy(40, 12);
						SetConsoleTextAttribute(hStdOut, 10);
						cout << "OUTPUT HAS BEEN WRITTEN IN FILE" << endl;
						Sleep(1500);
						SetConsoleTextAttribute(hStdOut, 15);
						delete choice;
						delete C;
						delete bonus;
						delete trvlexpense;
						delete hours;
						goto MainMenu;
					}
				}
				else if (*choice == 0) {
					delete choice;
					goto MainMenu;
				}
			}
			else if (*employmentDepartment == 6) {
				DrawMarketingDepartment();
				int *choice = new int(0);
				cin >> *choice;
				if (*choice == 1) {
					system("CLS");
					ofstream out;
					out.open("Employment.ta", ios::app);
					if (!out.is_open()) {
						gotoxy(45, 12);
						SetConsoleTextAttribute(hStdOut, 4);
						cout << "OUTPUT FILE CAN NOT BE OPEN" << endl;
						Sleep(1500);
						SetConsoleTextAttribute(hStdOut, 15);
						delete choice;
						goto MainMenu;
					}
					else {
						system("CLS");
						gotoxy(50, 4);
						cout << "MARKETING MANAGER";
						DrawInputHighLevelAdministration();
						char name[30];
						char surname[30];
						int *hours = new int(0);
						int *trvlexpense = new int(0);
						int *bonus = new int(0);
						gotoxy(28, 9);
						cin >> name;
						gotoxy(41, 9);
						cin >> surname;
						gotoxy(54, 9);
						cin >> *hours;
						gotoxy(67, 9);
						cin >> *trvlexpense;
						gotoxy(80, 9);
						cin >> *bonus;
						MarketingManager *M = new MarketingManager(name, surname, *hours, *trvlexpense, *bonus);
						out << endl;
						out << M->getName() << "  " << M->getSurName() << "  " << M->GetPostion() << "  " << M->GetHours() << "h.  " << M->Paycheck() << "EUR. ";
						out.close();
						gotoxy(40, 12);
						SetConsoleTextAttribute(hStdOut, 10);
						cout << "OUTPUT HAS BEEN WRITTEN IN FILE" << endl;
						Sleep(1500);
						SetConsoleTextAttribute(hStdOut, 15);
						delete choice;
						delete M;
						delete bonus;
						delete trvlexpense;
						delete hours;
						goto MainMenu;
					}
				}
				else if (*choice == 2) {
					system("CLS");
					ofstream out;
					out.open("Employment.ta", ios::app);
					if (!out.is_open()) {
						gotoxy(45, 12);
						SetConsoleTextAttribute(hStdOut, 4);
						cout << "OUTPUT FILE CAN NOT BE OPEN" << endl;
						Sleep(1500);
						SetConsoleTextAttribute(hStdOut, 15);
						delete choice;
						goto MainMenu;
					}
					else {
						system("CLS");
						gotoxy(50, 4);
						cout << "MEDIA HANDLER";
						DrawInputHighLevelAdministration();
						char name[30];
						char surname[30];
						int *hours = new int(0);
						int *trvlexpense = new int(0);
						int *bonus = new int(0);
						gotoxy(28, 9);
						cin >> name;
						gotoxy(41, 9);
						cin >> surname;
						gotoxy(54, 9);
						cin >> *hours;
						gotoxy(67, 9);
						cin >> *trvlexpense;
						gotoxy(80, 9);
						cin >> *bonus;
						MediaHandler *M = new MediaHandler(name, surname, *hours, *trvlexpense, *bonus);
						out << endl;
						out << M->getName() << "  " << M->getSurName() << "  " << M->GetPostion() << "  " << M->GetHours() << "h.  " << M->Paycheck() << "EUR. ";
						out.close();
						gotoxy(40, 12);
						SetConsoleTextAttribute(hStdOut, 10);
						cout << "OUTPUT HAS BEEN WRITTEN IN FILE" << endl;
						Sleep(1500);
						SetConsoleTextAttribute(hStdOut, 15);
						delete choice;
						delete M;
						delete bonus;
						delete trvlexpense;
						delete hours;
						goto MainMenu;
					}
				}
				else if (*choice == 3) {
					system("CLS");
					ofstream out;
					out.open("Employment.ta", ios::app);
					if (!out.is_open()) {
						gotoxy(45, 12);
						SetConsoleTextAttribute(hStdOut, 4);
						cout << "OUTPUT FILE CAN NOT BE OPEN" << endl;
						Sleep(1500);
						SetConsoleTextAttribute(hStdOut, 15);
						delete choice;
						goto MainMenu;
					}
					else {
						system("CLS");
						gotoxy(50, 4);
						cout << "PUBLIC REPRESENTATIVE";
						DrawInputHighLevelAdministration();
						char name[30];
						char surname[30];
						int *hours = new int(0);
						int *trvlexpense = new int(0);
						int *bonus = new int(0);
						gotoxy(28, 9);
						cin >> name;
						gotoxy(41, 9);
						cin >> surname;
						gotoxy(54, 9);
						cin >> *hours;
						gotoxy(67, 9);
						cin >> *trvlexpense;
						gotoxy(80, 9);
						cin >> *bonus;
						PublicRepresentative *M = new PublicRepresentative(name, surname, *hours, *trvlexpense, *bonus);
						out << endl;
						out << M->getName() << "  " << M->getSurName() << "  " << M->GetPostion() << "  " << M->GetHours() << "h.  " << M->Paycheck() << "EUR. ";
						out.close();
						gotoxy(40, 12);
						SetConsoleTextAttribute(hStdOut, 10);
						cout << "OUTPUT HAS BEEN WRITTEN IN FILE" << endl;
						Sleep(1500);
						SetConsoleTextAttribute(hStdOut, 15);
						delete choice;
						delete M;
						delete bonus;
						delete trvlexpense;
						delete hours;
						goto MainMenu;
					}
				}
				else if (*choice == 0) {
					delete choice;
					goto MainMenu;
				}
			}
			else if (*employmentDepartment == 0) {
				delete employmentDepartment;
				Sleep(600);
				system("CLS");
				goto MainMenu;
			}
		}else if (*entry == 3) {
			system("CLS");
			DrawMaterials();
			int *choice = new int(0);
			cin >> *choice;
			if (*choice == 1) {
				system("CLS");
				ofstream out;
				out.open("Pipes.ta", ios::app);
				if (!out.is_open()) {
					gotoxy(45, 12);
					SetConsoleTextAttribute(hStdOut, 4);
					cout << "OUTPUT FILE CAN NOT BE OPEN" << endl;
					Sleep(1500);
					SetConsoleTextAttribute(hStdOut, 15);
					delete choice;
					goto MainMenu;
				}
				else {
					system("CLS");
					gotoxy(50, 4);
					cout << "PIPES";
					DrawInputPipes();
					char supplier[30];
					char material[30];
					float *price = new float(0);
					float *diameter = new float(0);
					float *length = new float(0);
					gotoxy(28, 9);
					cin >> supplier;
					gotoxy(41, 9);
					cin >> material;
					gotoxy(54, 9);
					cin >> *diameter;
					gotoxy(67, 9);
					cin >> *length;
					gotoxy(80, 9);
					cin >> *price;
					Pipes *P = new Pipes();
					P->Set(*price, supplier, material, *diameter, *length);
					out << endl;
					out << P->GetSuppiler() << "  " << P->GetSuppiler() << "  " << P->Cost() << "EUR.";
					out.close();
					gotoxy(40, 12);
					SetConsoleTextAttribute(hStdOut, 10);
					cout << "OUTPUT HAS BEEN WRITTEN IN FILE" << endl;
					Sleep(1500);
					SetConsoleTextAttribute(hStdOut, 15);
					delete choice;
					delete P;
					delete price;
					delete diameter;
					delete length;
					goto MainMenu;
				}

			}
			else if (*choice == 2) {
				system("CLS");
				ofstream out;
				out.open("Rods.ta", ios::app);
				if (!out.is_open()) {
					gotoxy(45, 12);
					SetConsoleTextAttribute(hStdOut, 4);
					cout << "OUTPUT FILE CAN NOT BE OPEN" << endl;
					Sleep(1500);
					SetConsoleTextAttribute(hStdOut, 15);
					delete choice;
					goto MainMenu;
				}
				else {
					system("CLS");
					gotoxy(50, 4);
					cout << "RODS";
					DrawInputPipes();
					char supplier[30];
					char material[30];
					float *price = new float(0);
					float *diameter = new float(0);
					float *length = new float(0);
					gotoxy(28, 9);
					cin >> supplier;
					gotoxy(41, 9);
					cin >> material;
					gotoxy(54, 9);
					cin >> *diameter;
					gotoxy(67, 9);
					cin >> *length;
					gotoxy(80, 9);
					cin >> *price;
					Rods *P = new Rods();
					P->Set(*price, supplier, material, *diameter, *length);
					out << endl;
					out << P->GetSuppiler() << "  " << P->GetMaterial() << "  " << P->Cost() << "EUR.";
					out.close();
					gotoxy(40, 12);
					SetConsoleTextAttribute(hStdOut, 10);
					cout << "OUTPUT HAS BEEN WRITTEN IN FILE" << endl;
					Sleep(1500);
					SetConsoleTextAttribute(hStdOut, 15);
					delete choice;
					delete P;
					delete price;
					delete diameter;
					delete length;
					goto MainMenu;
				}
			}
			else if (*choice == 3) {
				system("CLS");
				ofstream out;
				out.open("Sheets.ta", ios::app);
				if (!out.is_open()) {
					gotoxy(45, 12);
					SetConsoleTextAttribute(hStdOut, 4);
					cout << "OUTPUT FILE CAN NOT BE OPEN" << endl;
					Sleep(1500);
					SetConsoleTextAttribute(hStdOut, 15);
					delete choice;
					goto MainMenu;
				}
				else {
					system("CLS");
					gotoxy(50, 4);
					cout << "SHEETS";
					DrawInputSheets();
					char supplier[30];
					char material[30];
					float *price = new float(0);
					float *thickness = new float(0);
					float *width = new float(0);
					gotoxy(28, 9);
					cin >> supplier;
					gotoxy(41, 9);
					cin >> material;
					gotoxy(54, 9);
					cin >> *thickness;
					gotoxy(67, 9);
					cin >> *width;
					gotoxy(80, 9);
					cin >> *price;
					Sheets *P = new Sheets();
					P->Set(*price, supplier, material, *thickness, *width);
					out << endl;
					out << P->GetSuppiler() << "  " << P->GetMaterial() << "  " << P->Cost() << "EUR.";
					out.close();
					gotoxy(40, 12);
					SetConsoleTextAttribute(hStdOut, 10);
					cout << "OUTPUT HAS BEEN WRITTEN IN FILE" << endl;
					Sleep(1500);
					SetConsoleTextAttribute(hStdOut, 15);
					delete choice;
					delete P;
					delete price;
					delete thickness;
					delete width;
					goto MainMenu;
				}
			}
			else if (*choice == 4) {
				system("CLS");
				ofstream out;
				out.open("SolderingWire.ta", ios::app);
				if (!out.is_open()) {
					gotoxy(45, 12);
					SetConsoleTextAttribute(hStdOut, 4);
					cout << "OUTPUT FILE CAN NOT BE OPEN" << endl;
					Sleep(1500);
					SetConsoleTextAttribute(hStdOut, 15);
					delete choice;
					goto MainMenu;
				}
				else {
					system("CLS");
					gotoxy(50, 4);
					cout << "SOLDERING WIRE";
					DrawInputSolderingWire();
					char supplier[30];
					char material[30];
					float *price = new float(0);
					float *diameter = new float(0);
					float *lenght = new float(0);
					gotoxy(28, 9);
					cin >> supplier;
					gotoxy(41, 9);
					cin >> material;
					gotoxy(54, 9);
					cin >> *diameter;
					gotoxy(67, 9);
					cin >> *lenght;
					gotoxy(80, 9);
					cin >> *price;
					SolderingWire *P = new SolderingWire();
					P->Set(*price, supplier, material, *lenght, *diameter);
					out << endl;
					out << P->GetSuppiler() << "  " << P->GetMaterial() << "  " << P->Cost() << "EUR.";
					out.close();
					gotoxy(40, 12);
					SetConsoleTextAttribute(hStdOut, 10);
					cout << "OUTPUT HAS BEEN WRITTEN IN FILE" << endl;
					Sleep(1500);
					SetConsoleTextAttribute(hStdOut, 15);
					delete choice;
					delete P;
					delete price;
					delete diameter;
					delete lenght;
					goto MainMenu;
				}
			}
			else if (*choice == 0) {
				delete choice;
				goto MainMenu;
			}
		}
		else if (*entry == 4) {
		system("CLS");
		DrawElectronics();
		int *choice = new int(0);
		cin >> *choice;
		if (*choice == 1) {
			system("CLS");
			ofstream out;
			out.open("Resistor.ta", ios::app);
			if (!out.is_open()) {
				gotoxy(45, 12);
				SetConsoleTextAttribute(hStdOut, 4);
				cout << "OUTPUT FILE CAN NOT BE OPEN" << endl;
				Sleep(1500);
				SetConsoleTextAttribute(hStdOut, 15);
				delete choice;
				goto MainMenu;
			}
			else {
				system("CLS");
				gotoxy(50, 4);
				cout << "RESSISTOR";
				DrawInputElectronics();
				char code[30];
				char integration[30];
				float *quantity = new float(0);
				float *price = new float(0);
				gotoxy(28, 9);
				cin >> code;
				gotoxy(41, 9);
				cin >> integration;
				gotoxy(54, 9);
				cin >> *quantity;
				gotoxy(67, 9);
				cin >> *price;
				Resistor *R = new Resistor();
				R->Set(integration, code, *quantity, *price);
				out << endl;
				out << R->GetCode() << "  " << R->GetIntegration() << "  " << R->GetResistance() << " OHM.  " << R->GetQuaintity() << "pc.  " << R->Cost() << "EUR.";
				out.close();
				gotoxy(40, 12);
				SetConsoleTextAttribute(hStdOut, 10);
				cout << "OUTPUT HAS BEEN WRITTEN IN FILE" << endl;
				Sleep(1500);
				SetConsoleTextAttribute(hStdOut, 15);
				delete choice;
				delete R;
				delete price;
				delete quantity;
				goto MainMenu;
			}
		}
		else if (*choice == 2) {
			system("CLS");
			ofstream out;
			out.open("Capacitor.ta", ios::app);
			if (!out.is_open()) {
				gotoxy(45, 12);
				SetConsoleTextAttribute(hStdOut, 4);
				cout << "OUTPUT FILE CAN NOT BE OPEN" << endl;
				Sleep(1500);
				SetConsoleTextAttribute(hStdOut, 15);
				delete choice;
				goto MainMenu;
			}
			else {
				system("CLS");
				gotoxy(50, 4);
				cout << "CAPACITOR";
				DrawInputElectronics();
				char code[30];
				char integration[30];
				float *quantity = new float(0);
				float *price = new float(0);
				gotoxy(28, 9);
				cin >> code;
				gotoxy(41, 9);
				cin >> integration;
				gotoxy(54, 9);
				cin >> *quantity;
				gotoxy(67, 9);
				cin >> *price;
				Capacitor *R = new Capacitor();
				R->Set(integration, code, *quantity, *price);
				out << endl;
				out << R->GetCode() << "  " << R->GetIntegration() << "  " << R->GetCapacity() << " FahhRads.  " << R->GetVoltage() << "V  " << R->GetTolernace() << "%  " << R->GetQuaintity() << "pc.  " << R->Cost() << "EUR.";
				out.close();
				gotoxy(40, 12);
				SetConsoleTextAttribute(hStdOut, 10);
				cout << "OUTPUT HAS BEEN WRITTEN IN FILE" << endl;
				Sleep(1500);
				SetConsoleTextAttribute(hStdOut, 15);
				delete choice;
				delete R;
				delete price;
				delete quantity;
				goto MainMenu;
			}
		}
		else if (*choice == 3) {
			system("CLS");
			ofstream out;
			out.open("SemiConductor.ta", ios::app);
			if (!out.is_open()) {
				gotoxy(45, 12);
				SetConsoleTextAttribute(hStdOut, 4);
				cout << "OUTPUT FILE CAN NOT BE OPEN" << endl;
				Sleep(1500);
				SetConsoleTextAttribute(hStdOut, 15);
				delete choice;
				goto MainMenu;
			}
			else {
				system("CLS");
				gotoxy(50, 4);
				cout << "SEMI-CONDUCTORS";
				DrawInputElectronics();
				char code[30];
				char integration[30];
				float *quantity = new float(0);
				float *price = new float(0);
				gotoxy(28, 9);
				cin >> code;
				gotoxy(41, 9);
				cin >> integration;
				gotoxy(54, 9);
				cin >> *quantity;
				gotoxy(67, 9);
				cin >> *price;
				SemiConductor *R = new SemiConductor();
				R->Set(integration, code, *quantity, *price);
				out << endl;
				out << R->GetCode() << "  " << R->GetIntegration() << "  " << R->GetType() << "  " << R->GetManufacturer() << "  " << R->Cost() << "EUR.";
				out.close();
				gotoxy(40, 12);
				SetConsoleTextAttribute(hStdOut, 10);
				cout << "OUTPUT HAS BEEN WRITTEN IN FILE" << endl;
				Sleep(1500);
				SetConsoleTextAttribute(hStdOut, 15);
				delete choice;
				delete R;
				delete price;
				delete quantity;
				goto MainMenu;
			}
		}
		else if (*choice == 0) {
			delete choice;
			goto MainMenu;
		}

	}
		else if (*entry == 5) {
		system("CLS");
		ofstream out;
		out.open("ControlUnits.ta", ios::app);
		if (!out.is_open()) {
			gotoxy(45, 12);
			SetConsoleTextAttribute(hStdOut, 4);
			cout << "OUTPUT FILE CAN NOT BE OPEN" << endl;
			Sleep(1500);
			SetConsoleTextAttribute(hStdOut, 15);
			delete choice;
			goto MainMenu;
		}
		else {
			system("CLS");
			gotoxy(50, 4);
			cout << "CUs";
			DrawInputControlUnits();
			char code[30];
			char description[30];
			float *quantity = new float(0);
			float *price = new float(0);
			gotoxy(28, 9);
			cin >> code;
			gotoxy(41, 9);
			cin >> description;
			gotoxy(54, 9);
			cin >> *quantity;
			gotoxy(67, 9);
			cin >> *price;
			Unit *C = new Unit();
			C->SetUnit(code, description, *quantity, *price);
			out << endl;
			out << C->GetCode() << "  " << C->GetDescription() << "  " << C->GetQuantity() << "pc.  " << C->Cost() << "EUR.";
			out.close();
			gotoxy(40, 12);
			SetConsoleTextAttribute(hStdOut, 10);
			cout << "OUTPUT HAS BEEN WRITTEN IN FILE" << endl;
			Sleep(1500);
			SetConsoleTextAttribute(hStdOut, 15);
			delete C;
			delete price;
			delete quantity;
			goto MainMenu;
		}
	}
		else if (*entry == 6) {
		system("CLS");
		DrawParts();
		int *choice = new int(0);
		cin >> *choice;
		if (*choice == 1) {
			system("CLS");
			ofstream out;
			out.open("FanBlades.ta", ios::app);
			if (!out.is_open()) {
				gotoxy(45, 12);
				SetConsoleTextAttribute(hStdOut, 4);
				cout << "OUTPUT FILE CAN NOT BE OPEN" << endl;
				Sleep(1500);
				SetConsoleTextAttribute(hStdOut, 15);
				delete choice;
				goto MainMenu;
			}
			else {
				system("CLS");
				gotoxy(50, 4);
				cout << "FAN BLADES";
				DrawInputFanBlades();
				char code[30];
				char description[30];
				float *quantity = new float(0);
				float *price = new float(0);
				float *angle = new float(0);
				gotoxy(28, 9);
				cin >> code;
				gotoxy(41, 9);
				cin >> description;
				gotoxy(54, 9);
				cin >> *quantity;
				gotoxy(67, 9);
				cin >> *price;
				gotoxy(80, 9);
				cin >> *angle;
				FanBlades *F = new FanBlades();
				F->Set(code, description, *price, *quantity, *angle);
				out << endl;
				out << F->GetCode() << "  " << F->GetDescription() << "  " << F->GetQuantity() << "pc.  " << F->Cost() << "EUR.";
				out.close();
				gotoxy(40, 12);
				SetConsoleTextAttribute(hStdOut, 10);
				cout << "OUTPUT HAS BEEN WRITTEN IN FILE" << endl;
				Sleep(1500);
				SetConsoleTextAttribute(hStdOut, 15);
				delete choice;
				delete F;
				delete price;
				delete quantity;
				delete angle;
				goto MainMenu;
			}
		}
		else if (*choice == 2) {
			system("CLS");
			ofstream out;
			out.open("Spinner.ta", ios::app);
			if (!out.is_open()) {
				gotoxy(45, 12);
				SetConsoleTextAttribute(hStdOut, 4);
				cout << "OUTPUT FILE CAN NOT BE OPEN" << endl;
				Sleep(1500);
				SetConsoleTextAttribute(hStdOut, 15);
				delete choice;
				goto MainMenu;
			}
			else {
				system("CLS");
				gotoxy(50, 4);
				cout << "SPINNER";
				DrawInputSpinner();
				char code[30];
				char description[30];
				float *quantity = new float(0);
				float *price = new float(0);
				float *area = new float(0);
				gotoxy(28, 9);
				cin >> code;
				gotoxy(41, 9);
				cin >> description;
				gotoxy(54, 9);
				cin >> *quantity;
				gotoxy(67, 9);
				cin >> *price;
				gotoxy(80, 9);
				cin >> *area;
				Spinner *F = new Spinner();
				F->Set(code, description, *price, *quantity, *area);
				out << endl;
				out << F->GetCode() << "  " << F->GetDescription() << "  " << F->GetQuantity() << "pc.  " << F->Cost() << "EUR.";
				out.close();
				gotoxy(40, 12);
				SetConsoleTextAttribute(hStdOut, 10);
				cout << "OUTPUT HAS BEEN WRITTEN IN FILE" << endl;
				Sleep(1500);
				SetConsoleTextAttribute(hStdOut, 15);
				delete choice;
				delete F;
				delete price;
				delete quantity;
				delete area;
				goto MainMenu;
			}
		}
		else if (*choice == 3) {
			system("CLS");
			ofstream out;
			out.open("HighPressureCompressor.ta", ios::app);
			if (!out.is_open()) {
				gotoxy(45, 12);
				SetConsoleTextAttribute(hStdOut, 4);
				cout << "OUTPUT FILE CAN NOT BE OPEN" << endl;
				Sleep(1500);
				SetConsoleTextAttribute(hStdOut, 15);
				delete choice;
				goto MainMenu;
			}
			else {
				system("CLS");
				gotoxy(50, 4);
				cout << "HI. COMPRESSOR";
				DrawInputCompressor();
				char code[30];
				char description[30];
				float *quantity = new float(0);
				float *price = new float(0);
				float *count = new float(0);
				gotoxy(28, 9);
				cin >> code;
				gotoxy(41, 9);
				cin >> description;
				gotoxy(54, 9);
				cin >> *quantity;
				gotoxy(67, 9);
				cin >> *price;
				gotoxy(80, 9);
				cin >> *count;
				HighPressureCompressor *F = new HighPressureCompressor();
				F->Set(code, description, *price, *quantity, *count);
				out << endl;
				out << F->GetCode() << "  " << F->GetDescription() << "  " << F->GetQuantity() << "pc.  " << F->Cost() << "EUR.";
				out.close();
				gotoxy(40, 12);
				SetConsoleTextAttribute(hStdOut, 10);
				cout << "OUTPUT HAS BEEN WRITTEN IN FILE" << endl;
				Sleep(1500);
				SetConsoleTextAttribute(hStdOut, 15);
				delete choice;
				delete F;
				delete price;
				delete quantity;
				delete count;
				goto MainMenu;
			}
		}
		else if (*choice == 4) {
			system("CLS");
			ofstream out;
			out.open("CombustionChamber.ta", ios::app);
			if (!out.is_open()) {
				gotoxy(45, 12);
				SetConsoleTextAttribute(hStdOut, 4);
				cout << "OUTPUT FILE CAN NOT BE OPEN" << endl;
				Sleep(1500);
				SetConsoleTextAttribute(hStdOut, 15);
				delete choice;
				goto MainMenu;
			}
			else {
				system("CLS");
				gotoxy(50, 4);
				cout << "COMBUSTION CHAMBER";
				DrawCombustionChamber();
				char code[30];
				char description[30];
				float *quantity = new float(0);
				float *price = new float(0);
				float *volume = new float(0);
				gotoxy(28, 9);
				cin >> code;
				gotoxy(41, 9);
				cin >> description;
				gotoxy(54, 9);
				cin >> *quantity;
				gotoxy(67, 9);
				cin >> *price;
				gotoxy(80, 9);
				cin >> *volume;
				CombustionChamber *F = new CombustionChamber();
				F->Set(code, description, *price, *quantity, *volume);
				out << endl;
				out << F->GetCode() << "  " << F->GetDescription() << "  " << F->GetQuantity() << "pc.  " << F->Cost() << "EUR.";
				out.close();
				gotoxy(40, 12);
				SetConsoleTextAttribute(hStdOut, 10);
				cout << "OUTPUT HAS BEEN WRITTEN IN FILE" << endl;
				Sleep(1500);
				SetConsoleTextAttribute(hStdOut, 15);
				delete choice;
				delete F;
				delete price;
				delete quantity;
				delete volume;
				goto MainMenu;
			}
		}
		else if (*choice == 5) {
			system("CLS");
			ofstream out;
			out.open("HighPressureTurbine.ta", ios::app);
			if (!out.is_open()) {
				gotoxy(45, 12);
				SetConsoleTextAttribute(hStdOut, 4);
				cout << "OUTPUT FILE CAN NOT BE OPEN" << endl;
				Sleep(1500);
				SetConsoleTextAttribute(hStdOut, 15);
				delete choice;
				goto MainMenu;
			}
			else {
				system("CLS");
				gotoxy(50, 4);
				cout << "HI. TURBINE";
				DrawInputCompressor();
				char code[30];
				char description[30];
				float *quantity = new float(0);
				float *price = new float(0);
				float *count = new float(0);
				gotoxy(28, 9);
				cin >> code;
				gotoxy(41, 9);
				cin >> description;
				gotoxy(54, 9);
				cin >> *quantity;
				gotoxy(67, 9);
				cin >> *price;
				gotoxy(80, 9);
				cin >> *count;
				HighPressureTurbine *F = new HighPressureTurbine();
				F->Set(code, description, *price, *quantity, *count);
				out << endl;
				out << F->GetCode() << "  " << F->GetDescription() << "  " << F->GetQuantity() << "pc.  " << F->Cost() << "EUR.";
				out.close();
				gotoxy(40, 12);
				SetConsoleTextAttribute(hStdOut, 10);
				cout << "OUTPUT HAS BEEN WRITTEN IN FILE" << endl;
				Sleep(1500);
				SetConsoleTextAttribute(hStdOut, 15);
				delete choice;
				delete F;
				delete price;
				delete quantity;
				delete count;
				goto MainMenu;
			}
		}
		else if (*choice == 6) {
			system("CLS");
			ofstream out;
			out.open("LowPressureTurbine.ta", ios::app);
			if (!out.is_open()) {
				gotoxy(45, 12);
				SetConsoleTextAttribute(hStdOut, 4);
				cout << "OUTPUT FILE CAN NOT BE OPEN" << endl;
				Sleep(1500);
				SetConsoleTextAttribute(hStdOut, 15);
				delete choice;
				goto MainMenu;
			}
			else {
				system("CLS");
				gotoxy(50, 4);
				cout << "LOW TURBINE";
				DrawInputCompressor();
				char code[30];
				char description[30];
				float *quantity = new float(0);
				float *price = new float(0);
				float *count = new float(0);
				gotoxy(28, 9);
				cin >> code;
				gotoxy(41, 9);
				cin >> description;
				gotoxy(54, 9);
				cin >> *quantity;
				gotoxy(67, 9);
				cin >> *price;
				gotoxy(80, 9);
				cin >> *count;
				LowPressureTurbine *F = new LowPressureTurbine();
				F->Set(code, description, *price, *quantity, *count);
				out << endl;
				out << F->GetCode() << "  " << F->GetDescription() << "  " << F->GetQuantity() << "pc.  " << F->Cost() << "EUR.";
				out.close();
				gotoxy(40, 12);
				SetConsoleTextAttribute(hStdOut, 10);
				cout << "OUTPUT HAS BEEN WRITTEN IN FILE" << endl;
				Sleep(1500);
				SetConsoleTextAttribute(hStdOut, 15);
				delete choice;
				delete F;
				delete price;
				delete quantity;
				delete count;
				goto MainMenu;
			}
		}
		else if (*choice == 0) {
			delete choice;
			goto MainMenu;
		}
	}
	}
	else if (*choice == 3) {
		system("CLS");
		delete choice;
		goto LOG;
	}
	else {
		system("CLS");
		delete choice;
		gotoxy(50, 9);
		cout << "SEE YOU NEXT TIME";
		gotoxy(50, 18);
	}


	return 0;
}
