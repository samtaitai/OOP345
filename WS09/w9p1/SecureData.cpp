/*
* Name: Soyon Lee
* Email: slee550@myseneca.ca
* ID: 179142211
* Date: 28 July 2023
* citation: 
* I was inspired by June's work about how to split text in 'code' function. 
*/
// Workshop 9 - Multi-Threading
// SecureData.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <future>
#include <functional>
#include "SecureData.h"

using namespace std;

namespace w9 {

	void converter(char* t, char key, int n, const Cryptor& c) {
		for (int i = 0; i < n; i++)
			t[i] = c(t[i], key);
	}

	SecureData::SecureData(const char* file, char key, ostream* pOfs)
	{
		ofs = pOfs;

		// open text file
		fstream input(file, std::ios::in);
		if (!input)
			throw string("\n***Failed to open file ") +
			string(file) + string(" ***\n");

		// copy from file into memory
		input.seekg(0, std::ios::end);
		nbytes = (int)input.tellg() + 1; //+1 for null byte

		text = new char[nbytes];

		input.seekg(ios::beg);
		int i = 0;
		input >> noskipws;
		while (input.good())
			input >> text[i++];
		text[nbytes - 1] = '\0';
		*ofs << "\n" << nbytes - 1 << " bytes copied from file "
			<< file << " into memory (null byte added)\n";
		encoded = false;

		// encode using key
		code(key);
		*ofs << "Data encrypted in memory\n";
	}

	SecureData::~SecureData() {
		delete[] text;
	}

	void SecureData::display(std::ostream& os) const {
		if (text && !encoded)
			os << text << std::endl;
		else if (encoded)
			throw std::string("\n***Data is encoded***\n");
		else
			throw std::string("\n***No data stored***\n");
	}

	void SecureData::code(char key)
	{
		// TODO (at-home): rewrite this function to use at least two threads
		//         to encrypt/decrypt the text.
		//converter(text, key, nbytes, Cryptor());

		const int chunk = nbytes / 4;
		const int crumb = nbytes % 4;

		//Cryptor() is bound
		auto c = bind(converter, placeholders::_1, placeholders::_2, placeholders::_3, Cryptor());

		//bound one is omitted
		thread t1(c, text, key, chunk);
		thread t2(c, text+chunk, key, chunk);
		thread t3(c, text+2*chunk, key, chunk);
		thread t4(c, text+3*chunk, key, chunk+crumb);

		t1.join();
		t2.join();
		t3.join();
		t4.join();
		encoded = !encoded; 
	}

	void SecureData::backup(const char* file) {
		if (!text)
			throw std::string("\n***No data stored***\n");
		else if (!encoded)
			throw std::string("\n***Data is not encoded***\n");
		else
		{
			// TODO: open a binary file for writing
			ofstream outbinfile(file, ios::binary);

			// TODO: write data into the binary file
			//         and close the file
			outbinfile.write(text, nbytes);
			outbinfile.close();
		}
	}

	void SecureData::restore(const char* file, char key) {
		// TODO: open binary file for reading
		ifstream inbinfile(file, ios::binary);

		// TODO: - allocate memory here for the file content
		delete[] text;
		text = new char[nbytes+1];
		
		// TODO: - read the content of the binary file
		inbinfile.read(text, nbytes);
		text[nbytes] = '\0';
		inbinfile.close();

		*ofs << "\n" << nbytes << " bytes copied from binary file "
			<< file << " into memory.\n";

		encoded = true;

		// decode using key
		code(key);

		*ofs << "Data decrypted in memory\n\n";
	}

	std::ostream& operator<<(std::ostream& os, const SecureData& sd) {
		sd.display(os);
		return os;
	}
}
