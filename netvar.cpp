#include "netvar.h"
#include "interface.h"
#include "fnv.h"

#include <cctype>
#include <string>
#include <format>
#include <iostream>
#include <stdio.h>

#define nout std::cout
#define endl std::endl

std::string TypeToString(SendPropType type)
{
	switch (type)
	{
	case DPT_Int:		return "INT";
	case DPT_Float:		return "FLOAT";
	case DPT_Vector:	return "VECTOR3";
	case DPT_VectorXY:	return "VECTOR2";
	case DPT_String:	return "STRING";
	case DPT_Array:		return "ARRAY";
	case DPT_DataTable: return "TABLE";
	}
	return "UNKNOWN";
}

void n::Setup() noexcept
{
	for (auto clientClass = i::client->GetAllClasses(); clientClass; clientClass = clientClass->m_pNext)
		if (clientClass->m_pRecvTable)
			Dump(clientClass->m_pNetworkName, clientClass->m_pRecvTable, 0);
}

void n::Dump(const char* baseClass, RecvTable* table, const std::uint32_t offset)
{
	for (auto i = 0; i < table->m_nProps; ++i)
	{
		const auto prop = table->m_pProps[i];

		if (!prop || isdigit(prop->m_pVarName[0])) continue;

		if (fnv::Hash(prop->m_pVarName) == fnv::HashConst("baseclass")) continue;

		if (prop->m_RecvType == SendPropType::DPT_DataTable && prop->m_pDataTable && prop->m_pDataTable->m_pNetTableName[0] == 'D')
			Dump(baseClass, prop->m_pDataTable, std::uint32_t(offset + prop->m_Offset));

		data[fnv::Hash(std::format("{}->{}", baseClass, prop->m_pVarName).data())] =
		{
			prop,
			std::uint32_t(offset + prop->m_Offset)
		};
	}
}
