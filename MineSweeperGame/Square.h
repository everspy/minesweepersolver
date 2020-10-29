#ifndef SQUARE_H
#define SQUARE_H

class Square {
public:
	static const int NeighbourCount = 8;
	enum class Value {
		Flagged = -3,
		Unviewed = -2,
		Bomb = -1,
		Blank = 0, One, Two, Three, Four, Five, Six, Seven, Eight
	};
	// Used as array indices for the neighbours array
	enum class Neighbours {
		TopLeft,
		TopCenter,
		TopRight,
		LeftCenter,
		RightCenter,
		BottomLeft,
		BottomCenter,
		BottomRight
	};

private:
	Value value;
	bool viewed;
	bool flagged;
	Square **neighbours;

public:
	Square();
	Square(Value value, Square **neighbours);
	~Square();
	void SetValue(Value val);
	void SetNeighbours(Square ** newNeighbours);
	void Flag();
	void Unflag();
	Value ViewSquare();
	Value GetTrueValue();
	Value GetValue();
	bool IsViewed();
	Square *GetNeighbour(Neighbours neighbourPos);
	Square **GetNeighbourArray();
};

#endif // !SQUARE_H