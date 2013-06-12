#ifndef __EP_XML_VALIDATE_RESULT_H__
#define __EP_XML_VALIDATE_RESULT_H__

#include "epl.h"
using namespace epl;

typedef enum _xmlValidateType{
	XML_VALIDATE_TYPE_NONE=0,
	XML_VALIDATE_TYPE_WARNING,
	XML_VALIDATE_TYPE_ERROR
}XMLValidateType;

struct XMLValidateResult{
	CString m_textString;
	XMLValidateType m_type;
	CString m_message;
	
	bool m_isRoot;
	bool m_isNode;
	CString m_name;
	CString m_value;
	XNode *m_parentNode;
	XNode *m_node;
	XAttr *m_attr;
	HTREEITEM m_treeItem;
};
#endif //__EP_XML_VALIDATE_RESULT_H__