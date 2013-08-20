/*! 
@file epXMLValidateProperties.h
@author Woong Gyu La a.k.a Chris. <juhgiyo@gmail.com>
		<http://github.com/juhgiyo/epxmlbuilder>
@date April 17, 2013
@brief XML Validate Properties Interface
@version 1.0

@section LICENSE

The MIT License (MIT)

Copyright (c) 2013 Woong Gyu La <juhgiyo@gmail.com>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.

@section DESCRIPTION

An Interface for the XML Validate Properties.

*/
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