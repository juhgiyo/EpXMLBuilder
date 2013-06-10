#ifndef __EP_PRE_TEXT_PARSER_H__
#define __EP_PRE_TEXT_PARSER_H__
#include <map>
#include <vector>
#include "epl.h"
using namespace epl;

using namespace std;
struct CStringComparer
{
public:
	bool operator()(const CString x, const CString y)
	{
		return x.Compare(y)==0;
	}
};

typedef map<CString,vector<CString>,CStringComparer > NodeStringMap;
class PreTestParser{
public:
	static bool Parse(TextFile &file,NodeStringMap &map,NodeStringMap &attrMap);
};
#endif //__EP_PRE_TEXT_PARSER_H__