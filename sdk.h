#pragma once

typedef enum
{
	DPT_Int = 0,
	DPT_Float,
	DPT_Vector,
	DPT_VectorXY,
	DPT_String,
	DPT_Array,
	DPT_Quaternion,
	DPT_Int64,
	DPT_DataTable,
	DPT_NUMSendPropTypes
} SendPropType;

struct RecvProp;
struct RecvTable
{
	char			_unk0x0000[0x8];		//0x0000
	RecvProp**		m_pProps;				//0x0008
	int				m_nProps;				//0x0010
	char			_unk0x0014[0x10C];		//0x0014
	void*			m_pDecoder;				//0x0120
	char*			m_pNetTableName;		//0x0128
	bool			m_bInitialized;			//0x0130
	bool			m_bInMainList;			//0x0131

}; //Size = 0x132

struct RecvProp
{
	SendPropType	m_RecvType;				//0x0000
	int				m_Offset;				//0x0004
	int				_unk0x0008;				//0x0008
	int				_unk0x000C;				//0x000C size?
	char			_unk0x0010[0x10];		//0x0010
	RecvTable*		m_pDataTable;			//0x0020
	char*			m_pVarName;				//0x0028
	bool			m_bInsideArray;			//0x0030
	char			_unk0x0031[0x7];		//0x0031
	RecvProp*		m_pArrayProp;			//0x0038
	void*			m_ProxyFn;				//0x0040
	char			_unk0x0048[0xC];		//0x0048
	int				m_Flags;				//0x0054
	char			_unk0x0058[0x4];		//0x0058
	int				m_nElements;			//0x005C
	char			_unk0x0060[0x8];		//0x0060
}; //Size = 0x68

struct ClientClass
{
	void*			m_pCreateFn;		//0x0000
	void*			m_pCreateEventFn;	//0x0008
	char*			m_pNetworkName;		//0x0010
	RecvTable*		m_pRecvTable;		//0x0018
	ClientClass*	m_pNext;			//0x0020
	char			_unk0028[0x8];		//0x0028
	char*			name;				//0x0030
}; //Size = 0x38