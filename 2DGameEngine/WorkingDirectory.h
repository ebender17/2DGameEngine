#pragma once

#include <string>

#ifdef MACOS
#include "CoreFoundation/CoreFoundation.h"
#endif // MACOS

class WorkingDirectory
{
public: 
	WorkingDirectory();

	inline const std::string& Get()
	{
		return path;
	}

private:
	std::string path;
};

