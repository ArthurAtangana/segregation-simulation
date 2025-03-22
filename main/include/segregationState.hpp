#ifndef SEGREGATION_STATE_HPP
#define SEGREGATION_STATE_HPP

#include <iostream>
#include <nlohmann/json.hpp>

// segregation state.
struct segregationState {
	double value;

	//! Default constructor function.
	segregationState() : value(0.0) {}
};

//! It prints the state of the cell in an output stream.
std::ostream& operator<<(std::ostream& os, const segregationState& x) {
	os << "<" << x.value << ">";
	return os;
}

//! The simulator must be able to compare the equality of two state objects
bool operator!=(const segregationState& x, const segregationState& y) {
	return x.value != y.value;
}

//! It parses a JSON file and generates the corresponding segregationState object.
void from_json(const nlohmann::json& j, segregationState& s) {
	j.at("value").get_to(s.value);
}

#endif //SEGREGATION_STATE_HPP
