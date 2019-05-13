class Accumulator{
	int value;
public:
	Accumulator(int value);
	Accumulator& add(int n);
	int get();
};