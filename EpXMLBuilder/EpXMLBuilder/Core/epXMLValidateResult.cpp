#include "stdafx.h"
//#include "epXMLValidatorProperties.h"

//using namespace epl;
// 
// XMLValidatorProperties::XMLValidatorProperties()
// {
// 	unsigned long retSizeInByte,retRegType;
// 	if(!RegistryHelper::GetRegistryData(HKEY_LOCAL_MACHINE,_T("SOFTWARE\\EpXMLBuilder"),_T("ShouldCheckNumber"),4,&m_numberCheck,retSizeInByte,retRegType))
// 	{
// 		m_numberCheck=1;
// 		RegistryHelper::SetRegistryData(HKEY_LOCAL_MACHINE,_T("SOFTWARE\\EpXMLBuilder"),_T("ShouldCheckNumber"),REG_DWORD,&m_numberCheck,4);
// 	}
// 	if(!RegistryHelper::GetRegistryData(HKEY_LOCAL_MACHINE,_T("SOFTWARE\\EpXMLBuilder"),_T("ShouldCheckStartWithXML"),4,&m_xmlCheck,retSizeInByte,retRegType))
// 	{
// 		m_xmlCheck=1;
// 		RegistryHelper::SetRegistryData(HKEY_LOCAL_MACHINE,_T("SOFTWARE\\EpXMLBuilder"),_T("ShouldCheckStartWithXML"),REG_DWORD,&m_xmlCheck,4);
// 	}
// 	if(!RegistryHelper::GetRegistryData(HKEY_LOCAL_MACHINE,_T("SOFTWARE\\EpXMLBuilder"),_T("ShouldCheckContainSpace"),4,&m_spaceCheck,retSizeInByte,retRegType))
// 	{
// 		m_spaceCheck=1;
// 		RegistryHelper::SetRegistryData(HKEY_LOCAL_MACHINE,_T("SOFTWARE\\EpXMLBuilder"),_T("ShouldCheckContainSpace"),REG_DWORD,&m_spaceCheck,4);
// 	}
// 	if(!RegistryHelper::GetRegistryData(HKEY_LOCAL_MACHINE,_T("SOFTWARE\\EpXMLBuilder"),_T("ShouldCheckDuplicate"),4,&m_duplicateCheck,retSizeInByte,retRegType))
// 	{
// 		m_duplicateCheck=1;
// 		RegistryHelper::SetRegistryData(HKEY_LOCAL_MACHINE,_T("SOFTWARE\\EpXMLBuilder"),_T("ShouldCheckDuplicate"),REG_DWORD,&m_duplicateCheck,4);
// 	}
// 
// 
// 	if(!RegistryHelper::GetRegistryData(HKEY_LOCAL_MACHINE,_T("SOFTWARE\\EpXMLBuilder"),_T("ShouldWarnContainDash"),4,&m_dashWarning,retSizeInByte,retRegType))
// 	{
// 		m_dashWarning=1;
// 		RegistryHelper::SetRegistryData(HKEY_LOCAL_MACHINE,_T("SOFTWARE\\EpXMLBuilder"),_T("ShouldWarnContainDash"),REG_DWORD,&m_dashWarning,4);
// 	}
// 	if(!RegistryHelper::GetRegistryData(HKEY_LOCAL_MACHINE,_T("SOFTWARE\\EpXMLBuilder"),_T("ShouldWarnContainPeriod"),4,&m_periodWarning,retSizeInByte,retRegType))
// 	{
// 		m_periodWarning=1;
// 		RegistryHelper::SetRegistryData(HKEY_LOCAL_MACHINE,_T("SOFTWARE\\EpXMLBuilder"),_T("ShouldWarnContainPeriod"),REG_DWORD,&m_periodWarning,4);
// 	}
// 	if(!RegistryHelper::GetRegistryData(HKEY_LOCAL_MACHINE,_T("SOFTWARE\\EpXMLBuilder"),_T("ShouldWarnContainColon"),4,&m_colonWarning,retSizeInByte,retRegType))
// 	{
// 		m_colonWarning=1;
// 		RegistryHelper::SetRegistryData(HKEY_LOCAL_MACHINE,_T("SOFTWARE\\EpXMLBuilder"),_T("ShouldWarnContainColon"),REG_DWORD,&m_colonWarning,4);
// 	}
// }
// XMLValidatorProperties::~XMLValidatorProperties()
// {
// 	
// }
// 
// void XMLValidatorProperties::SetShouldCheckNumber(bool value)
// {
// 	if(value)
// 		m_numberCheck=1;
// 	else
// 		m_numberCheck=0;
// 	RegistryHelper::SetRegistryData(HKEY_LOCAL_MACHINE,_T("SOFTWARE\\EpXMLBuilder"),_T("ShouldCheckNumber"),REG_DWORD,&m_numberCheck,4);
// }
// void XMLValidatorProperties::SetShouldCheckStartWithXML(bool value)
// {
// 	if(value)
// 		m_xmlCheck=1;
// 	else
// 		m_xmlCheck=0;
// 	RegistryHelper::SetRegistryData(HKEY_LOCAL_MACHINE,_T("SOFTWARE\\EpXMLBuilder"),_T("ShouldCheckStartWithXML"),REG_DWORD,&m_xmlCheck,4);
// }
// void XMLValidatorProperties::SetShouldCheckContainSpace(bool value)
// {
// 	if(value)
// 		m_spaceCheck=1;
// 	else
// 		m_spaceCheck=0;
// 	RegistryHelper::SetRegistryData(HKEY_LOCAL_MACHINE,_T("SOFTWARE\\EpXMLBuilder"),_T("ShouldCheckContainSpace"),REG_DWORD,&m_spaceCheck,4);
// }
// 
// void XMLValidatorProperties::SetShouldCheckDuplicate(bool value)
// {
// 	if(value)
// 		m_duplicateCheck=1;
// 	else
// 		m_duplicateCheck=0;
// 	RegistryHelper::SetRegistryData(HKEY_LOCAL_MACHINE,_T("SOFTWARE\\EpXMLBuilder"),_T("ShouldCheckDuplicate"),REG_DWORD,&m_duplicateCheck,4);
// }
// 
// void XMLValidatorProperties::SetShouldWarnContainDash(bool value)
// {
// 	if(value)
// 		m_dashWarning=1;
// 	else
// 		m_dashWarning=0;
// 	RegistryHelper::SetRegistryData(HKEY_LOCAL_MACHINE,_T("SOFTWARE\\EpXMLBuilder"),_T("ShouldWarnContainDash"),REG_DWORD,&m_dashWarning,4);
// }
// void XMLValidatorProperties::SetShouldWarnContainPeriod(bool value)
// {
// 	if(value)
// 		m_periodWarning=1;
// 	else
// 		m_periodWarning=0;
// 	RegistryHelper::SetRegistryData(HKEY_LOCAL_MACHINE,_T("SOFTWARE\\EpXMLBuilder"),_T("ShouldWarnContainPeriod"),REG_DWORD,&m_periodWarning,4);
// }
// void XMLValidatorProperties::SetShouldWarnContainColon(bool value)
// {
// 	if(value)
// 		m_colonWarning=1;
// 	else
// 		m_colonWarning=0;
// 	RegistryHelper::SetRegistryData(HKEY_LOCAL_MACHINE,_T("SOFTWARE\\EpXMLBuilder"),_T("ShouldWarnContainColon"),REG_DWORD,&m_colonWarning,4);
// }
// 
// bool XMLValidatorProperties::ShouldCheckNumber() const
// {
// 	if(m_numberCheck)
// 		return true;
// 	return false;
// }
// bool XMLValidatorProperties::ShouldCheckStartWithXML() const
// {
// 	if(m_xmlCheck)
// 		return true;
// 	return false;
// }
// bool XMLValidatorProperties::ShouldCheckContainSpace() const
// {
// 	if(m_spaceCheck)
// 		return true;
// 	return false;
// }
// 
// bool XMLValidatorProperties::ShouldCheckDuplicate() const
// {
// 	if(m_duplicateCheck)
// 		return true;
// 	return false;
// }
// bool XMLValidatorProperties::ShouldWarnContainDash() const
// {
// 	if(m_dashWarning)
// 		return true;
// 	return false;
// }
// bool XMLValidatorProperties::ShouldWarnContainPeriod() const
// {
// 	if(m_periodWarning)
// 		return true;
// 	return false;
// }
// bool XMLValidatorProperties::ShouldWarnContainColon() const
// {
// 	if(m_colonWarning)
// 		return true;
// 	return false;
// }