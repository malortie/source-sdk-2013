//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Purpose:
//
// $NoKeywords: $
//=============================================================================//

#include "cbase.h"
#include "hl2_player.h"
#include "basecombatweapon.h"
#include "gamerules.h"
#include "items.h"
#include "engine/IEngineSound.h"

// memdbgon must be the last include file in a .cpp file!!!
#include "tier0/memdbgon.h"

class CHoe_Item_FlakJacket : public CItem
{
public:
	DECLARE_CLASS(CHoe_Item_FlakJacket, CItem);

	void Spawn(void)
	{
		Precache();
		SetModel("models/w_flakjacket/w_flakjacket.mdl");
		BaseClass::Spawn();
	}
	void Precache(void)
	{
		PrecacheModel("models/w_flakjacket/w_flakjacket.mdl");

		PrecacheScriptSound("ItemBattery.Touch");

	}
	bool MyTouch(CBasePlayer *pPlayer)
	{
		CHL2_Player *pHL2Player = dynamic_cast<CHL2_Player *>(pPlayer);
		return (pHL2Player && pHL2Player->ApplyBattery(5.0f));
	}
};

LINK_ENTITY_TO_CLASS(item_flakjacket, CHoe_Item_FlakJacket);
PRECACHE_REGISTER(item_flakjacket);

