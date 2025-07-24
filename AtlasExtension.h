#pragma once
#include <string>
#include <list>
#ifdef _WIN32
#include <windows.h>
#endif
#include "Table.h"
#include "GenericVariable.h"

const unsigned int MAX_RETURN_VAL = 3;

const unsigned int NO_ACTION = 0;
const unsigned int REPLACE_TEXT = 1;
const unsigned int WRITE_POINTER = 2;

typedef struct AtlasContext
{
	unsigned int CurrentLine;

	std::list<TBL_STRING> StringTable;
	FILE* Target;

	unsigned int ScriptPos;
	unsigned int ScriptRemaining;

	unsigned int PointerValue;
	unsigned int PointerPosition;
	unsigned int PointerSize;
} AtlasContext;

typedef unsigned int (*ExtensionFunction) (AtlasContext** Context);

class ExtensionManager
{
public:
	ExtensionManager(VariableMap* Map);
	bool LoadExtension(std::string& ExtId, std::string& ExtensionFile);
	unsigned int ExecuteExtension(std::string& ExtId, std::string& FunctionName, AtlasContext** Context);
private:
	VariableMap* VarMap;
};

class AtlasExtension
{
public:
	AtlasExtension();
	~AtlasExtension();

	bool LoadExtension(std::string& ExtensionName);
	bool IsLoaded();
	ExtensionFunction GetFunction(std::string& FunctionName);

private:
#if _WIN32
	HMODULE Extension;
#else
	void* Extension;
#endif
};