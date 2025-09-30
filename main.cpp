#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "pixel.h"

using namespace std;

Pixel make_pixel(string& line) {

	Pixel pixel;
	int pos;

	pos = line.find(',');
	pixel.x = stoi(line.substr(0, pos));
	line = line.substr(pos + 1);

	pos = line.find(',');
	pixel.y = stoi(line.substr(0, pos));
	line = line.substr(pos + 1);

	pos = line.find(',');
	pixel.r = stof(line);
	line = line.substr(pos + 1);

	pos = line.find(',');
	pixel.g = stof(line);
	line = line.substr(pos + 1);

	pixel.b = stof(line);

	return pixel;
	
}

void flip_vertically(vector<Pixel> &pixel_list) {

	int max = 4;

	for (int i = 0; i < pixel_list.size(); i++) {
		pixel_list[i].y = (max - 1) - (pixel_list[i].y);
	}

}

int main(int argc, char* argv[]) {

	vector<Pixel> pixel_list;

	string line;
	ifstream datafile(argv[1]);
	ofstream myfile("results.dat");

	if (!datafile.is_open()) {
		cout << "Failed to open input file" << endl;
		return 1;
	}

	if (!myfile.is_open()) {
    cout << "Failed to open output file" << endl;
    return 1;
  }
		
	while (getline(datafile, line)) {
		cout << line << endl;
		pixel_list.push_back(make_pixel(line));
	}

	for (int i = 0; i < pixel_list.size(); i++) {
		Pixel p = pixel_list[i];

		myfile << p.x << ", " << p.y << ", " << p.r << ", " << p.g << ", " << p.b << endl;

	}

	datafile.close();
	myfile.close();

	return 0;

}
