#pragma once
#include <vector>
/*
Class PlatormDependent manages operations, which are platform dependent:
playing sound, clearing console, reading/writing files
and stopping the program.
*/
class PlatformDependent
{
public:
	PlatformDependent();
	~PlatformDependent();
	/*
		MySound1 plays a win sound.
	*/
	void MySound1() const;
	/*
		MySound2 plays a lose sound.
	*/
	void MySound2() const;
	void MyClear() const;
	void MyExit() const;
	/*
		ReadFile opens file containing statistics,
		and returns a vector with numbers from file.
		1th number is number of player's wins,
		2nd number is number of played games.
	*/
	std::vector <int> ReadFile() const;
	/*
		WriteFile gets a vector with numbers as argument, 
		saves them into the same file as ReadFile.
	*/
	void WriteFile(const std::vector<int> &Stats);
};

