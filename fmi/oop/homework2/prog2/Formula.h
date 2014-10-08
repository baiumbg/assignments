#pragma once

class Formula
{
public:
	virtual double value() const = 0;
	virtual void print() = 0;
	virtual Formula* clone() const = 0;
};