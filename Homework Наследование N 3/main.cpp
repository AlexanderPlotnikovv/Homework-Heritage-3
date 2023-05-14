#include <iostream>

class Figure {
protected:
	std::string Name;
	Figure(std::string Name) : Name(Name) {}
public:
	Figure() {}
	std::string coutName() {
		return Name;
	}
	virtual void print_info() {};
	virtual bool check() {
		return 1;
	};
	virtual int amount() {
		return 0;
	};
};

class Triangle : public Figure {
protected:
	int a;
	int b;
	int c;
	int A;
	int B;
	int C;
	bool check() override {
		if (A + B + C == 180)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	int amount() override {
		return 3;
	}
public:
	Triangle(int a, int b, int c, int A, int B, int C, std::string Name) : a(a), b(b), c(c), A(A), B(B), C(C), Figure(Name) {}
	Triangle() : Triangle(10, 20, 30, 50, 60, 70, "Triangle") {}
	void print_info() override {
		std::cout << Name << ":" << std::endl;
		if (check() == true)
		{
			std::cout << "Right" << std::endl;
		}
		else
		{
			std::cout << "Wrong" << std::endl;
		}
		std::cout << "Amount of sides: " << amount() << std::endl;
		std::cout << "Sides: a = " << a << ", b = " << b << ", c = " << c << std::endl;
		std::cout << "Angles: A = " << A << ", B = " << B << ", C = " << C << std::endl;
		std::cout << std::endl;
	}
};

class Quadrangle : public Figure {
protected:
	int a1;
	int b1;
	int c1;
	int d1;
	int A1;
	int B1;
	int C1;
	int D1;
	bool check() override {
		if (A1 + B1 + C1 + D1 == 360)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	int amount() override {
		return 4;
	}
public:
	Quadrangle(int a1, int b1, int c1, int d1, int A1, int B1, int C1, int D1, std::string Name) : a1(a1), b1(b1), c1(c1), d1(d1), A1(A1), B1(B1), C1(C1), D1(D1), Figure(Name) {}
	Quadrangle() : Quadrangle(10, 20, 30, 40, 50, 160, 70, 80, "Quadrangle") {}
	void print_info() override {
		std::cout << Name << ":" << std::endl;
		if (check() == true)
		{
			std::cout << "Right" << std::endl;
		}
		else
		{
			std::cout << "Wrong" << std::endl;
		}
		std::cout << "Amount of sides: " << amount() << std::endl;
		std::cout << "Sides: a = " << a1 << ", b = " << b1 << ", c = " << c1 << ", d = " << d1 << std::endl;
		std::cout << "Angles: A = " << A1 << ", B = " << B1 << ", C = " << C1 << ", D = " << D1 << std::endl;
		std::cout << std::endl;
	}
};

class RectangularTriangle : public Triangle {
protected:
	bool check() override {
		if (Triangle::check() == true)
		{
			if (C == 90)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else
		{
			return 0;
		}
	}
public:
	RectangularTriangle() : Triangle(10,20,30,40,50,90, "Rectangular triangle") {}
};

class IsoscelesTriangle : public Triangle {
protected:
	bool check() override {
		if (Triangle::check() == true)
		{
			if (a == c && A == C)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else
		{
			return 0;
		}
	}
public:
	IsoscelesTriangle() : Triangle(10, 30, 10, 50, 80, 50, "Isosceles triangle") {}
};

class EqualateralTriangle : public Triangle {
protected:
	bool check() override {
		if (Triangle::check() == true)
		{
			if (a == b && a == c && b == c && B == C && A == B && A == C)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else
		{
			return 0;
		}
	}
public:
	EqualateralTriangle() : Triangle(30, 30, 30, 60, 60, 60, "Equalateral triangle") {}
};

class Parallelogram : public Quadrangle {
protected:
	bool check() override {
		if (Quadrangle::check() == true)
		{
			if (a1 == c1 && b1 == d1 && A1 == C1 && B1 == D1)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else
		{
			return 0;
		}
	}
public:
	Parallelogram() : Quadrangle(20, 30, 20, 30, 140, 40, 140, 40, "Parallelogram") {}
};

class Rectangle : public Quadrangle {
protected:
	bool check() override {
		if (Quadrangle::check() == true)
		{
			if (a1 == c1 && b1 == d1 && A1 == 90 && B1 == 90 && C1 == 90 && D1 == 90)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else
		{
			return 0;
		}
	}
public:
	Rectangle() : Quadrangle(10, 20, 10, 20, 90, 90, 90, 90, "Rectangle") {}
};

class Rhomb : public Quadrangle {
protected:
	bool check() override {
		if (Quadrangle::check() == true)
		{
			if (a1 == b1 && a1 == c1 && a1 == d1 && b1 == c1 && b1 == d1 && c1 == d1 && A1 == C1 && B1 == D1)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else
		{
			return 0;
		}
	}
public:
	Rhomb() : Quadrangle(30, 30, 30, 30, 30, 150, 30, 150, "Rhomb") {}
};

class Square : public Quadrangle {
protected:
	bool check() override {
		if (Quadrangle::check() == true)
		{
			if (a1 == b1 && a1 == c1 && a1 == d1 && b1 == c1 && b1 == d1 && c1 == d1 && A1 == 90 && B1 == 90 && C1 == 90 && D1 == 90)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else
		{
			return 0;
		}
	}
public:
	Square() : Quadrangle(20, 20, 20, 20, 90, 90, 90, 90, "Square") {}
};

int main()
{
	Figure figure;
	Triangle triangle;
	Quadrangle quadrangle;
	RectangularTriangle rectangularTriangle;
	IsoscelesTriangle isoscelesTriangle;
	EqualateralTriangle equalateralTriangle;
	Parallelogram parallelogram;
	Rectangle rectangle;
	Rhomb rhomb;
	Square square;
	Figure* triangle1 = &triangle;
	triangle1->print_info();
	Figure* quadrangle1 = &quadrangle;
	quadrangle1->print_info();
	Figure* rectangularTriangle1 = &rectangularTriangle;
	rectangularTriangle1->print_info();
	Figure* isoscelesTriangle1 = &isoscelesTriangle;
	isoscelesTriangle1->print_info();
	Figure* equalateralTriangle1 = &equalateralTriangle;
	equalateralTriangle1->print_info();
	Figure* parallelogram1 = &parallelogram;
	parallelogram1->print_info();
	Figure* rectangle1 = &rectangle;
	rectangle1->print_info();
	Figure* rhomb1 = &rhomb;
	rhomb1->print_info();
	Figure* square1 = &square;
	square1->print_info();
}