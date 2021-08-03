#pragma once
class Operation
{
public:
	virtual double GetResult() = 0;
	void setNumber(double a, double b)
	{
		m_numberA = a;
		m_numberB = b;
	}
protected:
	double m_numberA;
	double m_numberB;
};
class OperationAdd :public Operation
{
public:
	double GetResult() override;
};
class  OperationSub :public Operation
{
public:
	double GetResult() override;
};
enum operate
{
	Add = 1,
	Sub
};