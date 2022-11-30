#ifndef RANGE_H
#define RANGE_H

#include <bits/stdc++.h>

using namespace std;

template < typename T = int >
class Range {
	private:
		T min_value, max_value;

	public:
		Range(T __min_value = 0, T __max_value = 0) {
			min_value = __min_value;
			max_value = __max_value;
		}

		void set_min_value(T value) {
			this -> min_value = value;
		}

		void set_max_value(T value) {
			this -> max_value = value;
		}

		T get_min_value() {
			return min_value;
		}

		T get_max_value() {
			return max_value;
		}

		friend istream& operator >> (istream& cin, Range& current) {
			T min_value;
			T max_value;
			cin >> min_value >> max_value;
			current.set_min_value(min_value);
			current.set_max_value(max_value);
			return cin;
		}

		friend ostream& operator << (ostream& cout, Range current) {
			cerr << "[" << current.get_min_value() << ", " << current.get_max_value() << "]\n";
			return cout;
		}
};

#endif
