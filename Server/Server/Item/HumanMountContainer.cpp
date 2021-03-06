// [7/8/2010 陈军龙]
#include "stdafx.h"
#include "HumanMountContainer.h"
#include "HumanDB.h"

BOOL HumanMountContainer::Init(const _ITEMCONTAINER_INIT* pInit )
{
	__ENTER_FUNCTION

	if(!ItemContainer::Init(pInit))
		return FALSE;

	const _HUMAN_MOUNTCONTAINER_INIT*	pHICInit = 
		static_cast<const _HUMAN_MOUNTCONTAINER_INIT*>(pInit);

	if(pHICInit==NULL)
		return FALSE;

	Assert(pHICInit->m_pHumanDB);

	m_ICTType	=	pHICInit->m_ICTType;
	m_pHumanDB	=	pHICInit->m_pHumanDB;
	m_nContainerSize = 5;
	return TRUE;
	
	__LEAVE_FUNCTION

	return	FALSE;
}


INT		HumanMountContainer::GetContainerType()
{
	__ENTER_FUNCTION

		return m_ICTType;

	__LEAVE_FUNCTION

		return -1 ;
}

//-----------------------------------------------------------------------------------------
/*
*	物品 使用方法
*/
BOOL	HumanMountContainer::SetItem(const INT nIndex, const Item* pItem )
{
	__ENTER_FUNCTION

		Assert(m_pHumanDB);

	BOOL	bRet = ItemContainer::SetItem(nIndex,pItem);

	if(bRet)
	{
		SetDBDirty(nIndex);
	}
	return	bRet;

	__LEAVE_FUNCTION

		return  FALSE;
}

//设置物品重叠数量
BOOL	HumanMountContainer::SetItemLayCount(INT nIndex, INT nCount) 
{
	__ENTER_FUNCTION
		Assert(0);
	return FALSE;
	__LEAVE_FUNCTION
		return FALSE;
}

//减少物品重叠数量
BOOL	HumanMountContainer::DecItemLayCount(INT nIndex, INT nCount)
{
	__ENTER_FUNCTION
		Assert(0);
	return false;
	__LEAVE_FUNCTION
		return false;
}
//增加物品重叠数量
BOOL	HumanMountContainer::IncItemLayCount(INT nIndex, INT nCount)
{
	__ENTER_FUNCTION
		Assert(0);
	return false;
	__LEAVE_FUNCTION
		return false;
}

//删除物品
BOOL	HumanMountContainer::EraseItem(UINT uIndex)
{
	__ENTER_FUNCTION

		Assert(m_pHumanDB);

	BOOL	bRet	=	ItemContainer::EraseItem(uIndex);

	if(bRet)
	{
		SetDBDirty(uIndex);
	}

	return bRet;

	__LEAVE_FUNCTION

		return FALSE;
}

//设置物品耐久度
BOOL	HumanMountContainer::SetItemDur(INT nIndex, INT nDur)
{
	__ENTER_FUNCTION
		Assert(0);
	return false;
	__LEAVE_FUNCTION
		return false;
}

//设置物品损伤点
BOOL		HumanMountContainer::SetItemDamagePoint(INT nIndex, INT nPoint)
{
	__ENTER_FUNCTION
		Assert(0);
	return false;
	__LEAVE_FUNCTION
		return false;
}


//设置物品最大耐久度
BOOL	HumanMountContainer::SetItemMaxDur(INT nIndex, INT nDur)
{
	__ENTER_FUNCTION
		Assert(0);
	return false;
	__LEAVE_FUNCTION
		return false;
}

BOOL	HumanMountContainer::SetItemCurMaxDur(INT nIndex, INT nDur)
{
	__ENTER_FUNCTION
		Assert(0);
	return false;
	__LEAVE_FUNCTION
		return false;
}

BOOL		HumanMountContainer::SetItemValue(INT nIndex,_ITEM* pItem)
{
	__ENTER_FUNCTION
	Assert(nIndex < m_nContainerSize);

	BOOL bRet = ItemContainer::SetItemValue(nIndex, pItem);

	if(bRet)
	{
		SetDBDirty(nIndex);
	}

	return false;
	__LEAVE_FUNCTION

	return false;
}


BOOL		HumanMountContainer::SetItemBind(INT nIndex)
{
	__ENTER_FUNCTION

		Assert(m_pHumanDB);
	//Assert(nIndex<m_DBOffSet+m_nContainerSize);

	BOOL bRet = ItemContainer::SetItemBind(nIndex);

	if(bRet)
	{
		//SetDBDirty(nIndex);
	}

	return bRet;

	__LEAVE_FUNCTION

		return FALSE;
}

BOOL		HumanMountContainer::SetItemIdent(INT nIndex)
{
	__ENTER_FUNCTION
		Assert(0);
	return false;
	__LEAVE_FUNCTION
		return false;
}

BOOL	HumanMountContainer::SetItemCreator(INT nIndex,const CHAR* CreatorName)
{
	__ENTER_FUNCTION
		Assert(0);
	return false;
	__LEAVE_FUNCTION
		return false;
}


//增加物品属性
BOOL		HumanMountContainer::AddItemAttr(INT nIndex,_ITEM_ATTR iA)
{
	__ENTER_FUNCTION
		Assert(0);
	return false;
	__LEAVE_FUNCTION
		return false;
}

//删除物品属性
BOOL		HumanMountContainer::DelItemAttr(INT nIndex,_ITEM_ATTR iA)
{
	__ENTER_FUNCTION
		Assert(0);
	return false;
	__LEAVE_FUNCTION
		return false;
}

//删除宝石信息
BOOL		HumanMountContainer::DelGemInfo(INT nIndex,INT GemIndex)
{
	__ENTER_FUNCTION
		Assert(0);
	return false;
	__LEAVE_FUNCTION
		return false;
}

//添加宝石信息
BOOL		HumanMountContainer::AddGemInfo(INT nIndex,INT& GemIndex,UINT GemType)
{
	__ENTER_FUNCTION
		Assert(0);
	return false;
	__LEAVE_FUNCTION
		return false;
}

//-----------------------------------------------------------------------------------------
/*
*	宠物 使用方法
*/
BOOL		HumanMountContainer::SetItemValue(INT nIndex,const _PET_DB_LOAD* pPet)
{
	__ENTER_FUNCTION
	
	Assert(m_pHumanDB);
	Assert(pPet);
	
	BOOL bRet	=	ItemContainer::SetItemValue(nIndex,pPet);
	
	if(bRet)
	{
		SetDBDirty(nIndex);
	}

	return bRet;

	__LEAVE_FUNCTION

	return FALSE;
}

BOOL  	HumanMountContainer::SetPetGUID(INT nIndex,PET_GUID_t GUID)				//设置宠物GUID
{
	__ENTER_FUNCTION

	Assert(m_pHumanDB);
	
	BOOL bRet	=	ItemContainer::SetPetGUID(nIndex,GUID);

	if(bRet)
	{
		SetDBDirty(nIndex);
	}

	return bRet;

	__LEAVE_FUNCTION

	return FALSE;
}

BOOL  	HumanMountContainer::SetSpouseGUID(INT nIndex,PET_GUID_t GUID)
{
	__ENTER_FUNCTION

	Assert(m_pHumanDB);
	
	BOOL bRet	=	ItemContainer::SetSpouseGUID(nIndex,GUID);

	if(bRet)
	{
		SetDBDirty(nIndex);
	}

	return bRet;

	__LEAVE_FUNCTION

	return FALSE;
}
BOOL	HumanMountContainer::SetDataID(INT nIndex,INT ID)							//设置宠物模型		
{
	__ENTER_FUNCTION

	Assert(m_pHumanDB);

	BOOL bRet	=	ItemContainer::SetDataID(nIndex,ID);

	if(bRet)
	{
		SetDBDirty(nIndex);
	}

	return bRet;

	__LEAVE_FUNCTION

	return FALSE;
}
BOOL 	HumanMountContainer::SetName(INT nIndex, const CHAR* pName)						//设置名字
{

	__ENTER_FUNCTION
	Assert(m_pHumanDB);

	BOOL bRet	=	ItemContainer::SetName(nIndex,pName);

	if(bRet)
	{
		SetDBDirty(nIndex);
	}

	return bRet;

	__LEAVE_FUNCTION

		return FALSE;
}
BOOL   	HumanMountContainer::SetNick(INT nIndex, const CHAR* pNick)						//设置昵称
{

	__ENTER_FUNCTION
	Assert(m_pHumanDB);

	BOOL bRet	=	ItemContainer::SetNick(nIndex,pNick);

	if(bRet)
	{
		SetDBDirty(nIndex);
	}

	return bRet;

	__LEAVE_FUNCTION

		return FALSE;
}
BOOL  	HumanMountContainer::SetLevel(INT nIndex,INT level)							//设置等级
{

	__ENTER_FUNCTION
	Assert(m_pHumanDB);

	BOOL bRet	=	ItemContainer::SetLevel(nIndex,level);

	if(bRet)
	{
		SetDBDirty(nIndex);
	}

	return bRet;

	__LEAVE_FUNCTION

	return FALSE;
}
BOOL  	HumanMountContainer::SetTakeLevel(INT nIndex,INT takeLevel)					//设置携带等级
{
	__ENTER_FUNCTION

	Assert(m_pHumanDB);

	BOOL bRet	=	ItemContainer::SetTakeLevel(nIndex,takeLevel);

	if(bRet)
	{
		SetDBDirty(nIndex);
	}

	return bRet;

	__LEAVE_FUNCTION

		return FALSE;
}
BOOL  	HumanMountContainer::SetAttackType(INT nIndex,INT attackType)				//设置进攻类型（物/法）
{
	__ENTER_FUNCTION

		Assert(m_pHumanDB);

	BOOL bRet	=	ItemContainer::SetAttackType(nIndex,attackType);

	if(bRet)
	{
		SetDBDirty(nIndex);
	}

	return bRet;

	__LEAVE_FUNCTION

		return FALSE;
}
BOOL  	HumanMountContainer::SetAIType(INT nIndex,INT AIType)						//设置AI类型
{
	__ENTER_FUNCTION

		Assert(m_pHumanDB);

	BOOL bRet	=	ItemContainer::SetAIType(nIndex,AIType);

	if(bRet)
	{
		SetDBDirty(nIndex);
	}

	return bRet;

	__LEAVE_FUNCTION

		return FALSE;
}
BOOL  	HumanMountContainer::SetCampData(INT nIndex,const _CAMP_DATA* pCamp)		//设置阵营
{
	__ENTER_FUNCTION

	Assert(m_pHumanDB);

	BOOL bRet	=	ItemContainer::SetCampData(nIndex,pCamp);

	if(bRet)
	{
		SetDBDirty(nIndex);
	}

	return bRet;

	__LEAVE_FUNCTION

		return FALSE;
}

//BOOL  	HumanMountContainer::SetHP(INT nIndex,INT hp)								//设置生命值
//{
//	__ENTER_FUNCTION
//
//	//Assert(m_pHumanDB);
//
//	//BOOL bRet	=	ItemContainer::SetHP(nIndex,hp);
//
//	//if(bRet)
//	//{
//	//	SetDBDirty(nIndex);
//	//}
//
//	//return bRet;
//	return TRUE;
//
//	__LEAVE_FUNCTION
//
//	return FALSE;
//}

//BOOL  	HumanMountContainer::SetLife(INT nIndex,INT Life)							//设置当前寿命
//{
//	__ENTER_FUNCTION
//
//	Assert(m_pHumanDB);
//
//	BOOL bRet	=	ItemContainer::SetLife(nIndex,Life);
//
//	if(bRet)
//	{
//		SetDBDirty(nIndex);
//	}
//
//	return bRet;
//
//	__LEAVE_FUNCTION
//
//	return FALSE;
//}
//BOOL  	HumanMountContainer::SetPetType(INT nIndex,BYTE PetType)				//宝宝，变异，野生
//{
//	__ENTER_FUNCTION
//
//	Assert(m_pHumanDB);
//
//	BOOL bRet	=	ItemContainer::SetPetType(nIndex,PetType);
//
//	if(bRet)
//	{
//		SetDBDirty(nIndex);
//	}
//
//	return bRet;
//
//	__LEAVE_FUNCTION
//
//	return FALSE;
//}

BOOL  	HumanMountContainer::SetGeneration(INT nIndex,BYTE Gen)						//几代宠
{	
	__ENTER_FUNCTION

	Assert(m_pHumanDB);

	BOOL bRet	=	ItemContainer::SetGeneration(nIndex,Gen);

	if(bRet)
	{
		SetDBDirty(nIndex);
	}

	return bRet;

	__LEAVE_FUNCTION

	return FALSE;

}
BOOL  	HumanMountContainer::SetHappiness(INT nIndex,BYTE byHappiness)						//快乐度		
{
	__ENTER_FUNCTION

	Assert(m_pHumanDB);

	BOOL bRet	=	ItemContainer::SetHappiness(nIndex,byHappiness);

	if(bRet)
	{
		SetDBDirty(nIndex);
	}

	return bRet;

	__LEAVE_FUNCTION

	return FALSE;
}
//力量资质
BOOL  	HumanMountContainer::SetStrengthPer(INT nIndex,INT strper)						
{
	__ENTER_FUNCTION

	Assert(m_pHumanDB);

	BOOL bRet	=	ItemContainer::SetStrengthPer(nIndex,strper);

	if(bRet)
	{
		SetDBDirty(nIndex);
	}

	return bRet;

	__LEAVE_FUNCTION

	return FALSE;
}
//敏捷资质
BOOL  	HumanMountContainer::SetSmartnessPer(INT nIndex,INT conper)
{	
	__ENTER_FUNCTION

	Assert(m_pHumanDB);

	BOOL bRet	=	ItemContainer::SetSmartnessPer(nIndex,conper);

	if(bRet)
	{
		SetDBDirty(nIndex);
	}

	return bRet;

	__LEAVE_FUNCTION

	return FALSE;
}

//智力资质
BOOL   	HumanMountContainer::SetMindPer(INT nIndex,INT dexper)
{
	__ENTER_FUNCTION

	Assert(m_pHumanDB);

	BOOL bRet	=	ItemContainer::SetMindPer(nIndex,dexper);

	if(bRet)
	{
		SetDBDirty(nIndex);
	}

	return bRet;

	__LEAVE_FUNCTION

	return FALSE;
}

//体质资质
BOOL   	HumanMountContainer::SetConstitutionPer(INT nIndex,INT intper)
{
	__ENTER_FUNCTION

	Assert(m_pHumanDB);

	BOOL bRet	=	ItemContainer::SetConstitutionPer(nIndex,intper);

	if(bRet)
	{
		SetDBDirty(nIndex);
	}

	return bRet;

	__LEAVE_FUNCTION

	return FALSE;
}

BOOL	HumanMountContainer::SetGenGu(INT nIndex,INT gengu)							//根骨
{
	__ENTER_FUNCTION

	Assert(m_pHumanDB);

	BOOL bRet	=	ItemContainer::SetGenGu(nIndex,gengu);

	if(bRet)
	{
		SetDBDirty(nIndex);
	}

	return bRet;

	__LEAVE_FUNCTION

	return FALSE;
}
BOOL  	HumanMountContainer::SetGrowRate(INT nIndex,FLOAT rate)						//成长率
{
	__ENTER_FUNCTION

	Assert(m_pHumanDB);

	BOOL bRet	=	ItemContainer::SetGrowRate(nIndex,rate);

	if(bRet)
	{
		SetDBDirty(nIndex);
	}

	return bRet;

	__LEAVE_FUNCTION

		return FALSE;
}
BOOL  	HumanMountContainer::SetRemainPoint(INT nIndex,INT rPoint)					//一级属性剩余点数
{
	__ENTER_FUNCTION

	Assert(m_pHumanDB);

	BOOL bRet	=	ItemContainer::SetRemainPoint(nIndex,rPoint);

	if(bRet)
	{
		SetDBDirty(nIndex);
	}

	return bRet;

	__LEAVE_FUNCTION

	return FALSE;
}

BOOL	HumanMountContainer::SetMatingFlag( INT iIndex, BOOL bFlag )
{
	__ENTER_FUNCTION

	Assert(m_pHumanDB);

	BOOL bRet	=	ItemContainer::SetMatingFlag(iIndex,bFlag);

	if(bRet)
	{
		SetDBDirty(iIndex);
	}

	return bRet;

	__LEAVE_FUNCTION

	return FALSE;
}

BOOL HumanMountContainer::SetMatingStartTime( INT nIndex, UINT uTime )
{
	__ENTER_FUNCTION

	Assert(m_pHumanDB);

	BOOL bRet	=	ItemContainer::SetMatingStartTime(nIndex,uTime);

	if(bRet)
	{
		SetDBDirty(nIndex);
	}

	return bRet;

	__LEAVE_FUNCTION

	return FALSE;
}

BOOL HumanMountContainer::SetMatingFinishFlag( INT nIndex, BOOL bFlag )
{
	__ENTER_FUNCTION

	Assert(m_pHumanDB);

	BOOL bRet	=	ItemContainer::SetMatingFinishFlag(nIndex,bFlag);

	if(bRet)
	{
		SetDBDirty(nIndex);
	}

	return bRet;

	__LEAVE_FUNCTION

	return FALSE;
}


BOOL HumanMountContainer::SetMatingLevel( INT nIndex, INT iLevel )
{
	__ENTER_FUNCTION

	Assert(m_pHumanDB);

	BOOL bRet	=	ItemContainer::SetMatingLevel(nIndex,iLevel);

	if(bRet)
	{
		SetDBDirty(nIndex);
	}

	return bRet;

	__LEAVE_FUNCTION

	return FALSE;
}

BOOL HumanMountContainer::SetPetSex( INT nIndex, INT iSex )
{
	__ENTER_FUNCTION

	Assert(m_pHumanDB);

	BOOL bRet	=	ItemContainer::SetPetSex(nIndex,iSex);

	if(bRet)
	{
		SetDBDirty(nIndex);
	}

	return bRet;

	__LEAVE_FUNCTION

	return FALSE;
}

BOOL HumanMountContainer::SetCheckUpFlag( INT nIndex, BOOL bCheckup )
{
	__ENTER_FUNCTION

	Assert(m_pHumanDB);

	BOOL bRet	=	ItemContainer::SetCheckUpFlag(nIndex,bCheckup);

	if(bRet)
	{
		SetDBDirty(nIndex);
	}

	return bRet;

	__LEAVE_FUNCTION

	return FALSE;
}

BOOL  	HumanMountContainer::SetExp(INT nIndex,INT exp)							//经验值
{
	__ENTER_FUNCTION

	Assert(m_pHumanDB);

	BOOL bRet	=	ItemContainer::SetExp(nIndex,exp);

	if(bRet)
	{
		SetDBDirty(nIndex);
	}

	return bRet;

	__LEAVE_FUNCTION

	return FALSE;
}
BOOL  	HumanMountContainer::SetLvl1Attr(INT nIndex,CHAR_ATTR_LEVEL1 type,INT value)//基础一级战斗属性（不包括技能和装备增加的部分）
{
	__ENTER_FUNCTION

	Assert(m_pHumanDB);

	BOOL bRet	=	ItemContainer::SetLvl1Attr(nIndex,type,value);

	if(bRet)
	{
		SetDBDirty(nIndex);
	}

	return bRet;

	__LEAVE_FUNCTION

	return FALSE;
}

BOOL  	HumanMountContainer::SetSkill(INT nIndex,UINT SkillIndex,_PET_SKILL skill)	//宠物技能
{
	__ENTER_FUNCTION

	Assert(m_pHumanDB);

	BOOL bRet	=	ItemContainer::SetSkill(nIndex,SkillIndex,skill);

	if(bRet)
	{
		SetDBDirty(nIndex);
	}

	return bRet;

	__LEAVE_FUNCTION

	return FALSE;
}

BOOL	HumanMountContainer::SetDBDirty(INT index)
{
	Assert(m_pHumanDB);
	switch(m_ICTType)
	{
	case ICT_MOUNT_CONTAINER:
		{
			m_pHumanDB->SetDBEnumAttrDirty((CHAR_ATTR_DB)CATTR_DB_PET); 
		}
		break;

	default:
		{
			AssertEx(FALSE,"无效容器类型");
			return FALSE;
		}
	}
	return TRUE;
}

