#include "pch.h"
#include "PlatformDependent.h"
#include <Windows.h>
#include <fstream>
PlatformDependent::PlatformDependent()
{
}


PlatformDependent::~PlatformDependent()
{
	
}

void PlatformDependent::MySound1() const
{
	Beep(10000, 300);
}


void PlatformDependent::MySound2() const
{
	Beep(500, 500);
}

void PlatformDependent::MyClear() const
{
	system("cls");
}

void PlatformDependent::MyExit() const
{
	exit(0);
}

std::vector<int> PlatformDependent::ReadFile() const
{
	std::ifstream File("Stats.txt");
	std::vector <int> Stats;
	int SingleInfo;
	while (File >> SingleInfo) {
		Stats.push_back(SingleInfo);
	}
	return Stats;
}

void PlatformDependent::WriteFile(const std::vector<int>& Stats)
{
	std::ofstream File("Stats.txt");
	for (auto SingleInfo : Stats) {
		File << SingleInfo << " ";
	}
}








