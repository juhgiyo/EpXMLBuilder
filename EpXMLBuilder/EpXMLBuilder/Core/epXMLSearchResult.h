#ifndef __EP_XML_SEARCH_RESULT_H__
#define __EP_XML_SEARCH_RESULT_H__

#include "epl.h"
using namespace epl;



struct XMLSearchResult{
	CString m_textString;

	bool m_isRoot;
	bool m_isNode;
	CString m_name;
	CString m_value;
	XNode *m_parentNode;
	XNode *m_node;
	XAttr *m_attr;
	HTREEITEM m_treeItem;
};
#endif //__EP_XML_SEARCH_RESULT_H__