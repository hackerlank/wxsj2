#include "StdAfx.h"
#include "..\..\NetWork\NetManager.h"
#include "GITimeSystem.h"
#include "GIException.h"
#include "CGCharAskBaseAttrib.h"
#include "..\..\GameCommand.h"
#include "..\..\Procedure\GameProcedure.h"
#include "Object\Manager\ObjectManager.h"
#include "Object\Logic\Character\Obj_PlayerNPC.h"
#include "Object\ObjectCommandDef.h"
#include "..\..\Interface\GMGameInterface.h"
#include "..\..\World\WorldManager.h"
#include "..\..\DataPool\GMDP_CharacterData.h"

#include "GCNewPet_Death.h"
#include "..\..\Object\GMObjectLoadQueue.h"

uint GCNewPet_DeathHandler::Execute( GCNewPet_Death* pPacket, Player* pPlayer ) 
{
	// 当前流程是主流程
	if(CGameProcedure::GetActiveProcedure() == (CGameProcedure*)CGameProcedure::s_pProcMain)
	{
//		CObjectManager* pObjectManager = CObjectManager::GetMe();
//		// 检查位置是否合法
//		if(!CWorldManager::GetMe()->GetActiveScene()->IsValidPosition(fVector2(pPacket->getWorldPos().m_fX, pPacket->getWorldPos().m_fZ)))
//		{
//			KLThrow("ERROR POSITION @ GCNewMonster_DeathHandler");
//		}
//
//		// 创建玩家
//		CObject_PlayerNPC* pNPC = (CObject_PlayerNPC*)pObjectManager->FindServerObject( (INT)pPacket->getObjID() );
//		fVector3 fvGame;
//		CGameProcedure::s_pGfxSystem->Axis_Trans(tGfxSystem::AX_PLAN, 
//												 fVector3(pPacket->getWorldPos().m_fX, 
//												 0.0f, 
//												 pPacket->getWorldPos().m_fZ),
//												 tGfxSystem::AX_GAME, 
//												 fvGame);
//
//		FLOAT fFaceDir = pPacket->getDir();
//		if( pNPC == NULL )
//		{
//			pNPC = pObjectManager->NewPlayerNPC( (INT)pPacket->getObjID() );
//
//			SObjectInit initPlayerNPC;
//
//			initPlayerNPC.m_fvPos = fvGame;
//			initPlayerNPC.m_fvRot = fVector3( 0.f, fFaceDir, 0.f );
//
//			pNPC->Initial( &initPlayerNPC );
//		}
//		else
//		{
//			fVector2 mapPos(fvGame.x, fvGame.z);
//			pNPC->SetMapPosition(mapPos);
//			pNPC->SetFaceDir( fFaceDir );
//			pNPC->Enable( OSF_VISIABLE );
//			pNPC->Disalbe( OSF_OUT_VISUAL_FIELD );
//		}
//
//		pNPC->SetNpcType(NPC_TYPE_PET);
//
//		pNPC->GetCharacterData()->Set_MoveSpeed(pPacket->getMoveSpeed());
//
//		SCommand_Object cmdTemp;
//		cmdTemp.m_wID			= OC_DEATH;
//		cmdTemp.m_abParam[0]	= FALSE;
//		pNPC->PushCommand(&cmdTemp );
//
//		// 清除界面选中NPC
//		if(CObjectManager::GetMe()->GetMainTarget() && pNPC && ((CObject*)(CObjectManager::GetMe()->GetMainTarget()))->GetID() == pNPC->GetID())
//		{
//			CGameInterface::GetMe()->Object_SelectAsMainTarget(INVALID_ID, 0);
//		}
//
//		// 放入Ask队列
//		CObjectManager::GetMe()->GetLoadQueue()->TryAddLoadTask(pNPC->GetID());
//
//		// tempcode{
//		// 此版不做服务器繁忙客户端延后发消息的处理
////		CGCharAskBaseAttrib msgAskBaseAttrib;
////		msgAskBaseAttrib.setTargetID( (INT)pPacket->getObjID() );
////		CNetManager::GetMe()->SendPacket( &msgAskBaseAttrib );
//		// }
//
//		//同步渲染层
//		char szTemp[MAX_PATH];
//		_snprintf(szTemp, MAX_PATH, "GCNewPet_Death(%.1f,%.1f)", pPacket->getWorldPos().m_fX, pPacket->getWorldPos().m_fZ);
//		pNPC->PushDebugString(szTemp);
//		pNPC->SetMsgTime(CGameProcedure::s_pTimeSystem->GetTimeNow());
	}

	return PACKET_EXE_CONTINUE ;
}
