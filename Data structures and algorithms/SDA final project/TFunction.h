#pragma once
class TFunction
{
	//H(X,capacity)+F(I)
	//getPosition(k,m)+getI()
private:
	int i;
public:
	TFunction();
	int getPosition(int k, int m) { return k % m; }
	int getI()const { return i; }
	void incrementI() { this->i++; }
	void resetI() { this->i = 0; }
	~TFunction();
};

