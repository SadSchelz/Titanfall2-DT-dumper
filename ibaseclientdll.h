#pragma once

#include "sdk.h"
#include <cstdint>
#include <basetsd.h>
#include <Windows.h>

using CreateInterfaceFn = uintptr_t(__fastcall*)(const char*, uintptr_t);

class C_GlobalVars
{
public:
	float	realtime; //0x0000
	int		framecount; //0x0004
	float	absoluteframetime; //0x0008
	float	curtime; //0x000C
	float	frametime; //0x0010
	int		tickcount; //0x0014
	float	Unk1; //0x0018
	float	interval_per_tick; //0x001C
	float	interpolation_amount; //0x0020
	int		simTicksThisFrame; //0x0024
	int		network_protocol; //0x0028
};

class BaseClientDll
{
public:
	virtual int              Connect(CreateInterfaceFn appSystemFactory, C_GlobalVars* pGlobals) = 0; // 0
	virtual int              Disconnect(void) = 0; // 1
	virtual int              Init(CreateInterfaceFn appSystemFactory, C_GlobalVars* pGlobals) = 0; // 2
	virtual void             PostInit() = 0; // 3
	virtual INT64			 unk0x4(INT64 unk) = 0; // signed __int64 __fastcall Init2(__int64 a1, __int64 a2) // 4
	virtual INT64		     unk0x5() = 0; // 5
	virtual void             Shutdown(void) = 0; // 6
	virtual void			 unk0x7(void* unk) = 0; // void *__fastcall sub_191D50(__int64 a1, void *a2) // 7
	virtual void             LevelInitPreEntity(char const* pMapName) = 0; //8
	virtual void             LevelInitPostEntity() = 0;
	virtual void             LevelShutdown(void) = 0;
	virtual ClientClass*	 GetAllClasses(void) = 0; // 11
	virtual int				 HudVidInit(void) = 0; // 12
	virtual void			 HudProcessInput(bool bActive) = 0;
	virtual void			 HudUpdate(bool bActive) = 0; // 14
	virtual void			 HudReset(void) = 0;
	//virtual int			 IN_KeyEvent(int eventcode, ButtonCode_t keynum, const char *pszCurrentBinding) = 0;
	virtual INT64            unk_CInput0x17(void) = 0; //  return ((*CInputVT)[23])();
	virtual INT64			 unk_CInput0x18(void) = 0; // return ((*CInputVT)[24])();
	virtual INT64			 unk_CInput0x19(void) = 0; // return ((*CInputVT)[25])();
	virtual bool			 IN_IsKeyDown(const char* name, bool& isdown) = 0; // char __fastcall sub_1918C0(__int64 a1, __int64 a2, _BYTE *a3) // 20
	virtual INT64            unk_CInput0xF(void) = 0; // return ((*CInputVT)[15])();
	virtual INT64            unk_CInput0x10(void) = 0; // return ((*CInputVT)[16])();
	virtual int              unk(int a1, unsigned int a2, BYTE* a3); // signed __int64 __fastcall IN_____(__int64 a1, signed int a2, unsigned int a3, unsigned __int8 *a4)
	virtual bool             unk_CInput_52(unsigned int a1, unsigned int a2); // _BYTE *__fastcall IN____(__int64 a1, unsigned int a2, unsigned int a3)
	virtual uintptr_t        CreateMove(int sequence_number, float input_sample_frametime, bool active); // 25
};