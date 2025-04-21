#ifndef SEGREGATION_STATE_HPP
#define SEGREGATION_STATE_HPP

#include <iostream>
#include <nlohmann/json.hpp>
#include <optional>
#include <vector>

// segregation state.
struct segregationState {
	double value;
	bool justChanged;
	bool isFamily;


	//! Default constructor function.
	segregationState() : value(0.0), justChanged(false), isFamily(false) {}
};

//! It prints the state of the cell in an output stream.
std::ostream& operator<<(std::ostream& os, const segregationState& x) {
	os << "<" << x.value << ">";
	return os;
}

//! The simulator must be able to compare the equality of two state objects
bool operator!=(const segregationState& x, const segregationState& y) {
	return x.value != y.value ||
	       x.isFamily != y.isFamily;
}

//! It parses a JSON file and generates the corresponding segregationState object.
void from_json(const nlohmann::json& j, segregationState& s) {
	j.at("value").get_to(s.value);
	j.at("justChanged").get_to(s.justChanged);
	j.at("isFamily").get_to(s.isFamily);
}

#endif //SEGREGATION_STATE_HPP
