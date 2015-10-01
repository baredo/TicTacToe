#ifndef POSITION2D_H
#define POSITION2D_H

#pragma once

struct Position2D {
	int row; 
	int column;
	Position2D(int row, int column) {
		this->row = row; 
		this->column = column;
	}
};

#endif