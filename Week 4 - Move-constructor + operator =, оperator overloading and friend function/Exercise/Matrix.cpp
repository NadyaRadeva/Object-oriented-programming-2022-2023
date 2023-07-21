#include "Matrix.h"
#include<iostream>

void Matrix::copy(Matrix const& other) {
	r = other.r;
	cols = other.cols;
	mtrx = new int* [r];
	for (size_t i = 0; i < r; ++i) {
		mtrx[i] = new int[cols];
		for (size_t j = 0; j < cols; ++j) {
			mtrx[i][j] = other.mtrx[i][j];
		}
	}
}

void Matrix::erase() {
	for (size_t i = 0; i < r; ++i) {
		delete mtrx[i];
	}
	delete[] mtrx;
}

Matrix::Matrix(unsigned int rows, unsigned int columns) {
	this->r = rows;
	this->cols = columns;

	this->mtrx = new int* [r];
	for (size_t i = 0; i < r; ++i) {
		mtrx[i] = new int[cols];
		for (size_t j = 0; j < cols; ++i) {
			mtrx[i][j] = 0;
		}
	}
}

Matrix::~Matrix() {
	this->erase();
}

Matrix::Matrix(Matrix const& other) {
	this->copy(other);
}

Matrix Matrix::operator=(Matrix other) {
	if (this != &other) {
		this->copy(other);
	}

	return *this;
}

Matrix::Matrix(Matrix&& other) {
	this->r = other.r;
	this->cols = other.cols;
	this->mtrx = other.mtrx;

	other.r = 0;
	other.cols = 0;
	other.mtrx = nullptr;
}

Matrix& Matrix::operator=(Matrix&& other) {
	if (this != &other) {
		this->erase();

		this->r = other.r;
		this->cols = other.cols;
		this->mtrx = other.mtrx;
		other.r = 0;
		other.cols = 0;
		other.mtrx = nullptr;
	}

	return *this;
}

int& Matrix::operator()(int row, int col) {
	return mtrx[row][col];
}

Matrix Matrix::operator+(Matrix const& other) const {
	Matrix result(r, cols);
	for (size_t i = 0; i < r; ++i) {
		for (size_t j = 0; j < cols; ++j) {
			result.mtrx[i][j] = this->mtrx[i][j] + other.mtrx[i][j];
		}
	}

	return result;
}

Matrix Matrix::operator-(Matrix const& other) const {
	Matrix result(r, cols);
	for (size_t i = 0; i < r; ++i) {
		for (size_t j = 0; j < cols; ++j) {
			result.mtrx[i][j] = this->mtrx[i][j] - other.mtrx[i][j];
		}
	}

	return result;
}

Matrix Matrix::operator*(Matrix const& other) const {
	Matrix result(r, other.cols);
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < other.cols; j++) {
			for (int k = 0; k < cols; k++) {
				result.mtrx[i][j] += mtrx[i][k] * other.mtrx[k][j];
			}
		}
	}
	return result;
}

bool Matrix::operator==(Matrix const& other) const {
	if (r != other.r || cols != other.cols) {
		return false;
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < cols; j++) {
			if (mtrx[i][j] != other.mtrx[i][j]) {
				return false;
			}
		}
	}
	return true;
}

Matrix transpose(Matrix const& matrix){
	Matrix result(matrix.cols, matrix.r);
	for (int i = 0; i < matrix.r; i++) {
		for (int j = 0; j < matrix.cols; j++) {
			result.mtrx[j][i] = matrix.mtrx[i][j];
		}
	}
	return result;
}

void print(Matrix const& matrix) {
	for (int i = 0; i < matrix.r; i++) {
		for (int j = 0; j < matrix.cols; j++) {
			std::cout << matrix.mtrx[i][j] << " ";
		}
		std::cout << std::endl;
	}
}
