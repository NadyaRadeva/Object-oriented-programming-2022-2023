#ifndef _MATRIX_H
#define _MATRIX_H

class Matrix {
private:
	unsigned int r;
	unsigned int cols;
	int** mtrx;

	void copy(Matrix const& other);
	void erase();

public:
	Matrix(unsigned int rows, unsigned int columns);
	~Matrix();
	Matrix(Matrix const& other);
	Matrix operator=(Matrix other);
	Matrix(Matrix&& other);
	Matrix& operator=(Matrix&& other);

	int& operator()(int row, int col);

	Matrix operator+(Matrix const& other) const;
	Matrix operator-(Matrix const& other) const;
	Matrix operator*(Matrix const& other) const;
	bool operator==(Matrix const& other) const;
	bool operator!=(Matrix const& other) const;

	friend Matrix transpose(Matrix const& matrix);
	friend void print(Matrix const& matrix);
};

#endif // !_MATRIX_H
