#ifndef _MODULE_H
#define _MODULE_H

#include "Globals.h"
#include "SString.h"

#include "PugiXml/src/pugixml.hpp"


class Application;

class PhysBody;

class Module
{
public:
	
	Module(bool start_enabled = true) : enabled(start_enabled)
	{}

	bool IsEnabled() const
	{
		return enabled;
	}

	virtual bool Start()
	{
		return true;
	}

	virtual update_status PreUpdate()
	{
		return UPDATE_CONTINUE;
	}

	virtual update_status Update()
	{
		return UPDATE_CONTINUE;
	}

	virtual update_status PostUpdate()
	{
		return UPDATE_CONTINUE;
	}

	virtual bool CleanUp() 
	{ 
		return true; 
	}

	// Create new virtual methods to LoadState / SaveState
	virtual bool LoadState(pugi::xml_node&)
	{
		return true;
	}

	virtual bool SaveState(pugi::xml_node&)
	{
		return true;
	}

	void Enable()
	{
		if (enabled == false)
		{
			enabled = true;
			Start();
		}
	}

	void Disable()
	{
		if (enabled == true)
		{
			enabled = false;
			CleanUp();
		}
	}

public:

	SString name;
	bool enabled;
};

#endif //_MODULE_H