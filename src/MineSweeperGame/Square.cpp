#include "Square.h"

Square::Square() {
	value = Value::Blank;
	neighbours = nullptr;
	flagged = false;
	viewed = false;
}
Square::Square(Value squareValue, Square **squareNeighbours) {
	value = squareValue;
	neighbours = squareNeighbours;
	flagged = false;
	viewed = false;
}
Square::~Square() {
	delete[] neighbours;
}

void Square::SetValue(Square::Value val) {
	this->value = val;
}

void Square::SetNeighbours(Square ** newNeighbours) {
	delete[] neighbours;
	this->neighbours = newNeighbours;
}
void Square::Flag() {
	this->flagged = true;
}

void Square::Unflag() {
	this->flagged = false;
}

Square::Value Square::ViewSquare() {
	this->viewed = true;
	return this->value;
}

Square::Value Square::GetValue() {
	if (this->flagged) {
		return Value::Flagged;
	}
	if (!this->viewed) {
		return Value::Unviewed;
	}

	return this->value;
}

Square::Value Square::GetTrueValue() {
	return this->value;
}

bool Square::IsViewed() {
	return this->viewed;
}

Square *Square::GetNeighbour(Square::Neighbours neighbourPos) {
	return neighbours[neighbourPos];
}

Square **Square::GetNeighbourArray() {
	return this->neighbours;
}