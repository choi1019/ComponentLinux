#pragma once

#include <52PApplication/typedef.h>
#define _PMain_Id _GET_CLASS_UID(_EPApplication::_ePMain)
#define _PMain_Name "PMain"

#include <02Platform/Main/Main.h>

class PMain : public Main
{
public:
	static int main_ex();

public:
	PMain(unsigned uClassId = _PMain_Id,
		const char* pcClassName = _PMain_Name);
	virtual ~PMain();

	// as a Component
	void Initialize() override;
	void Finalize() override;
	
	void BootstrapSystem() override;
	void RunAsAMain() override;
	void ShutdownSystem() override;
};