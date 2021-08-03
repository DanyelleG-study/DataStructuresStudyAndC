#pragma once
class single
{
public:
	static single* getsingle();
	static void deleteSingle();
private:
	single();
	~single();
	static single * sing;
};

