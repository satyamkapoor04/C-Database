#include <iostream>
#include <fstream>
#include <string>
	using namespace std;

#include "student.h"
#include "database2.h"

int main() {
	Database<Student> d;
	d.run();
	return 0;
}