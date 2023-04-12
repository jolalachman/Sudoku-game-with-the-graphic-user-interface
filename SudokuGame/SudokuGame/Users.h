#pragma once
#include <string>
#include <filesystem>
#include <fstream>

class Users 
{
protected:
	std::string path = "C:\\Users\\Jola\\Desktop\\SudokuUsers\\";
public:
	virtual bool openUserFile(std::string username);
	virtual bool setNewUserFile(std::string username);
	virtual std::string saveScore(std::string username);
};

