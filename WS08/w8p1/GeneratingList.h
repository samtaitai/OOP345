#ifndef SDDS_GENERATINGLIST_H
#define SDDS_GENERATINGLIST_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <memory>
#include <utility>
#include <fstream>

namespace sdds {
	template<typename T>
	class GeneratingList {

		std::vector<T> list;
	public:

		GeneratingList(){}
		GeneratingList(const char* f) {
			std::ifstream file(f);
			if (!file)
				throw std::string("*** Failed to open file ") + std::string(f) + std::string(" ***");

			while (file) {
				T t;
				if (t.load(file))
					list.push_back(T(t));
			}
		}

		size_t size() const { return list.size(); }
		const T& operator[](size_t i) const { return list[i]; }

		//TODO: Implement the Luhn Algorithm to check the 
		//      valadity of SIN No's
		bool idValidator(const std::string id) {
			
			int evenProd{};
			int oddProd{};
			int fDigit{};
			int sDigit{};
			int result{};
			int num{};
			std::vector<int> prod;

			for (int i = 0; i < sample.size(); i++) {
				num = sample[i] - '0';
				if (i % 2 == 0) {
					evenProd = num * 2;
					std::cout << i << "'s: " << evenProd << std::endl;
					if (evenProd >= 10) {
						fDigit = evenProd / 10;
						sDigit = evenProd % 10;
						evenProd = fDigit + sDigit;
					}
					prod.push_back(evenProd);
				}
				else {
					oddProd = num * 1;
					std::cout << i << "'s: " << oddProd << std::endl;
					if (oddProd >= 10) {
						fDigit = oddProd / 10;
						sDigit = oddProd % 10;
						oddProd = fDigit + sDigit;
					}
					prod.push_back(oddProd);
				}
			}
			result = std::accumulate(prod.begin(), prod.end(), (int)0);

			//if last digit is 0, true(valid)
			return result % 10 == 0? true : false;
		}

		//TODO: Overload the += operator with a raw pointer
		// as a second operand.
		void operator+=(GeneratingList& self, const &T elem) {
			//size+1 dma stuff
		}

		void print(std::ostream& os) const {
			os << std::fixed << std::setprecision(2);
			for (auto& e : list)
				e.print(os);
		}
	};

	template<typename T>
	std::ostream& operator<<(std::ostream& os, const GeneratingList<T>& rd) {
		rd.print(os);
		return os;
	}
}
#endif // !SDDS_GENERATINGLIST_H
