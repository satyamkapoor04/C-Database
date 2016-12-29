#ifndef STUDENT
#define STUDENT

class Student {
private:
	string name;
	string roll;
	char sec;
	string reg;
public:
	Student();
	friend ostream& operator<<(ostream&, Student&);
	friend istream& operator>>(istream&, Student&);
	void dataWrite(fstream&);
};

Student::Student() {
	name = "\0";
	roll = "\0";
	sec = '\0';
	reg = "\0";
}



istream& operator>> (istream& in, Student& s) {
	cout<<"Enter details: \n";
	cout<<"Name: ";
	cin.ignore();
	getline(cin,s.name);
	cout<<"Roll: ";
	cin>>s.roll;
	cout<<"Section: ";
	cin>>s.sec;
	cout<<"Registration No: ";
	cin>>s.reg;

	return in;
}

ostream& operator<< (ostream& out, Student& s) {
	cout<<"Name: "<<s.name<<endl<<"Roll: "<<s.roll<<endl<<"Section: "<<s.sec<<endl<<"Registration: "<<s.reg<<endl;
	return out;
}

void Student::dataWrite(fstream& d) {
	d.write(roll.c_str(), roll.length());
	d.write("-\n", 2);
	d.write("Name: ", 6);
	d.write(name.c_str(), name.length());
	d.write("\nRoll No: ",10);
	d.write(roll.c_str(), roll.length());
	d.write("\nSection: ", 10);
	d.write(reinterpret_cast<const char*>(&sec), sizeof(sec));
	d.write("\nRegistration No: ", 18);
	d.write(reg.c_str(), reg.length());
	d.write("\n\n", 2);
}




#endif