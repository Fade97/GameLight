#pragma once
#include <string>
#include "GLDefines.h"

class GLErrorHandler
{
public:
	GLErrorHandler( eRetCode e, std::string sLocation = "" );
	GLErrorHandler( CError e, std::string sLocation = "" );
	static bool show( eRetCode e, std::string sLocation = "" );
	static bool show( CError e, std::string sLocation = "" );
};

