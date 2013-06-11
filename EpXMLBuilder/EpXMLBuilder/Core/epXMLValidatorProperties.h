#ifndef __EP_XML_VALIDATOR_PROPERTIES_H__
#define __EP_XML_VALIDATOR_PROPERTIES_H__

#include "epl.h"
using namespace epl;

#define XML_VALIDATOR_PROPERTIES_INSTANCE epl::SingletonHolder<XMLValidatorProperties>::Instance()
class XMLValidatorProperties{
public:
	friend class SingletonHolder<XMLValidatorProperties>;
	
	XMLValidatorProperties();
	virtual ~XMLValidatorProperties();

	void SetShouldCheckNumber(bool value);
	void SetShouldCheckStartWithXML(bool value);
	void SetShouldCheckContainSpace(bool value);
	void SetShouldCheckDuplicate(bool value);

	void SetShouldWarnContainDash(bool value);
	void SetShouldWarnContainPeriod(bool value);
	void SetShouldWarnContainColon(bool value);

	bool ShouldCheckNumber() const;
	bool ShouldCheckStartWithXML() const;
	bool ShouldCheckContainSpace() const;
	bool ShouldCheckDuplicate() const;

	bool ShouldWarnContainDash() const;
	bool ShouldWarnContainPeriod() const;
	bool ShouldWarnContainColon() const;
	
private:
	unsigned int m_numberCheck;
	unsigned int m_xmlCheck;
	unsigned int m_spaceCheck;
	unsigned int m_duplicateCheck;

	unsigned int m_dashWarning;
	unsigned int m_periodWarning;
	unsigned int m_colonWarning;
};
#endif //__EP_PRE_TEXT_PARSER_H__