#pragma once

#include <01Base/typedef.h>
#define _Exception_Id _GET_CLASS_UID(_ELayer_Base::_eException)
#define _Exception_Name "Exception"

#include <01Base/Aspect/Aspect.h>
#include <01Base/StdLib/String.h>

class Exception : public Aspect
{
protected:
	int m_nType;
	String m_sObject;
	String m_sFunction;
	String m_sMessage1;
	String m_sMessage2;
//	time_t m_tTime;
public:
	int GetType() { return this->m_nType; }
	String GetSource() { return this->m_sObject; }
	String GetFunction() { return this->m_sFunction; }
	String& GetMessage1() { return this->m_sMessage1; }
	String& GetMessage2() { return this->m_sMessage2; }
public:
	Exception(
		int nType = UNDEFINED,
		String sObject = "",
		String sFunction = "",
		String sMessage1 = "",
		String sMessage2 = "")
		: Aspect(_Exception_Id, _Exception_Name)
		, m_nType(nType)
		, m_sObject(sObject)
		, m_sFunction(sFunction)
		, m_sMessage1(sMessage1)
		, m_sMessage2(sMessage2)
	{
//		m_tTime = time(0);
	}
	virtual ~Exception() {}

	virtual void Initialize() {	
		Aspect::Initialize();
	}
	virtual void Finalize() {
		Aspect::Finalize();
	}

	virtual void Println() {
		printf(
			"\n>> Execption(%d) << %s::%s => %s, %s\n"
			, m_nType
			, m_sObject.c_str()
			, m_sFunction.c_str()
			, m_sMessage1.c_str()
			, m_sMessage2.c_str()
			//			,String(m_tTime).c_str()
		);
	}
};

