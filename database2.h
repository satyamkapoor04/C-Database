#ifndef DATABASE 
#define DATABASE


template <class T>
class Database {
public:
	Database();
	void run();
private:
	string fName;
	fstream database;
	void add(T&);
};

template <class T>
Database<T>::Database() {
	cout<<"File Name: ";
	cin>>fName;
}

template <class T>
void Database<T>::run() {
	T rec;
	cin >> rec;
	add(rec);
}

template <class T>
void Database<T>::add(T& rec) {
	database.open(fName.c_str(), ios::out | ios::app | ios::binary);
	database.seekp(0, ios::end);
	rec.dataWrite(database);
	database.close();
}


#endif