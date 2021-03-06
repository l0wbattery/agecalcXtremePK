//SWITCH


		case sinOR1: //Anel
		case sinOR2:
			sinSetRingAging(pItem);
			break;
		case sinWA1: //Machado
			//공격력 
			sinSetDamageAging(pItem);
			//명중력
			sinSetAttackRateAging(pItem , 10);
			//내구력
			sinSetDurabilityAging(pItem); 

		break;
		case sinWC1: //Garra
			//공격력 
			sinSetDamageAging(pItem);
			//명중력
			sinSetAttackRateAging(pItem , 5);
			//크리티컬  
			sinSetCriticalAging(pItem);

		break;

		case sinWH1: //Martelo
			//공격력 
			sinSetDamageAging(pItem);

			//명중력
			sinSetAttackRateAging(pItem , 10);
			//내구력
			sinSetDurabilityAging(pItem); 

		break;
		case sinWM1: // Cajado
			//공격력 
			sinSetDamageAging(pItem);

			//명중력
			sinSetAttackRateAging(pItem , 10);

			//기력  
			pItem->fIncrease_Mana += 10;

		break;
		case sinWP1: //Foice
			//공격력 
			sinSetDamageAging(pItem);

			//명중력
			sinSetAttackRateAging(pItem , 5);

			//크리티컬  
			sinSetCriticalAging(pItem);

		break;
		case sinWS1: //Arco
			//공격력 
			sinSetDamageAging(pItem);

			//크리티컬  
			sinSetCriticalAging(pItem);

			//내구력
			sinSetDurabilityAging(pItem); 
		break;

		case sinWS2: //Espada 
			//공격력 
			sinSetDamageAging(pItem);

			//명중력
			sinSetAttackRateAging(pItem , 5);
			
			//크리티컬  
			sinSetCriticalAging(pItem);

		break;

		case sinWT1: //Lan�a 
			//공격력 
			sinSetDamageAging(pItem);

			//크리티컬  
			sinSetCriticalAging(pItem);

			//내구력
			//sinSetDurabilityAging(pItem); 
		break;
			
		case sinDS1: //Escudo 
			//블럭율 
			sinSetBlockRateAging(pItem);
			//흡수율
			sinSetAbsorbAging(pItem , 0.2f);
			//내구력
			sinSetDurabilityAging(pItem); 
		break;

		case sinOM1: //Orbe
			//방어력 
			sinSetDefenseAging(pItem,10);

			//흡수율
			sinSetAbsorbAging(pItem , 0.5f);

			//내구력
			sinSetDurabilityAging(pItem); 

		break;
		case sinDA1: case sinDA2:// Armaduras
			//방어력 
			sinSetDefenseAging(pItem,5);

			//흡수율
			sinSetAbsorbAging(pItem , 0.5f);

			//내구력
			sinSetDurabilityAging(pItem); 

		break; 



//sinSet

int sinSetDurabilityAging(sITEMINFO *pItem)
{
	int Temp = 0;
	Temp = pItem->Durability[1]/100;
	Temp += 1;
	pItem->Durability[1] -= Temp;
	if(pItem->Durability[1] < 0 ) pItem->Durability[1] = 0;
	if(pItem->Durability[1] < pItem->Durability[0] ) pItem->Durability[0] = pItem->Durability[1]; //현제 내구력 보정 

	return TRUE;
}
int sinSetDamageAging(sITEMINFO *pItem)
{
	pItem->Damage[0]++;
	pItem->Damage[1]++;

	if (pItem->ItemAgingNum[0] >= 9){ //10차부터는 데미지 +2
		pItem->Damage[0]++;
		pItem->Damage[1]++;
	}

	// 박재원 - 에이징 설정 변경(무기류 레벨별 공격력 추가)
	if (pItem->ItemAgingNum[0] >= 19){ //20차부터는 데미지 +3
		pItem->Damage[0]++;
		pItem->Damage[1]++;
	}

	if (pItem->ItemAgingNum[0] >= 20){ //20차부터는 데미지 +3
		pItem->fIncrease_Life += 20;
	}

	if (pItem->ItemAgingNum[0] == 21 || pItem->ItemAgingNum[0] == 23){
		pItem->Attack_Speed++;
	}

	return TRUE;
}

//공격력
int sinSetRingAging(sITEMINFO *pItem)
{
	if(pItem->ItemAgingNum[0] < 2){ //10차부터는 데미지 +2
		pItem->Damage[0] += 3;
		pItem->Damage[1] += 3;
		pItem->fIncrease_Life += 30;
		pItem->fIncrease_Mana += 30;
		pItem->fLife_Regen += 0.5f;
		pItem->fMana_Regen += 0.5f;
		pItem->Defence += 25;
		pItem->fAbsorb += 1.0f;
	}
	else{
		pItem->Damage[0] += 4;
		pItem->Damage[1] += 4;
		pItem->fIncrease_Life += 40;
		pItem->fIncrease_Mana += 40;
		pItem->fLife_Regen += 1.0f;
		pItem->fMana_Regen += 1.0f;
		pItem->Defence += 30;
		pItem->fAbsorb += 2.0f;
	}

	return TRUE;
}
//방어력
int sinSetDefenseAging(sITEMINFO *pItem , int Percent)
{
	float Temp = 0;
	Temp = (float)pItem->Defence/(100.0f / (float)Percent);
	pItem->Defence += (int)Temp;

	if (pItem->ItemAgingNum[0] >= 20){ //20차부터는 데미지 +3
		pItem->fIncrease_Life += 50;
	}

	return TRUE;
}

//명중력
int sinSetAttackRateAging(sITEMINFO *pItem , int AddNum)
{
	pItem->Attack_Rating += AddNum;
	return TRUE;
}
//흡수율
int sinSetAbsorbAging(sITEMINFO *pItem , float Percent)
{
	pItem->fAbsorb += Percent;

	if(pItem->ItemAgingNum[0] >= 9){ //10차부터는 2배
		pItem->fAbsorb += Percent;
	}

	// 박재원 - 에이징 설정 변경(무기류 레벨별 공격력 추가)
	if(pItem->ItemAgingNum[0] >= 19){ //20차부터는 3배
		pItem->fAbsorb += Percent;
	}

	return TRUE;
}

//크리티컬
int sinSetCriticalAging(sITEMINFO *pItem)
{
	if(pItem->ItemAgingNum[0] && (pItem->ItemAgingNum[0]%2) == 1){
		pItem->Critical_Hit += 1;

	}
	return TRUE;
}

//블럭율
int sinSetBlockRateAging(sITEMINFO *pItem)
{
	if(pItem->ItemAgingNum[0] && (pItem->ItemAgingNum[0]%2) == 1){
		pItem->fBlock_Rating += 1;

	}
	if (pItem->ItemAgingNum[0] >= 20){
		pItem->fBlock_Rating += 4;
		pItem->fIncrease_Life += 40;
	}
	return TRUE;
}


