//SWITCH


		case sinOR1: //Anel
		case sinOR2:
			sinSetRingAging(pItem);
			break;
		case sinWA1: //Machado
			//°ø°Ý·Â 
			sinSetDamageAging(pItem);
			//¸íÁß·Â
			sinSetAttackRateAging(pItem , 10);
			//³»±¸·Â
			sinSetDurabilityAging(pItem); 

		break;
		case sinWC1: //Garra
			//°ø°Ý·Â 
			sinSetDamageAging(pItem);
			//¸íÁß·Â
			sinSetAttackRateAging(pItem , 5);
			//Å©¸®Æ¼ÄÃ  
			sinSetCriticalAging(pItem);

		break;

		case sinWH1: //Martelo
			//°ø°Ý·Â 
			sinSetDamageAging(pItem);

			//¸íÁß·Â
			sinSetAttackRateAging(pItem , 10);
			//³»±¸·Â
			sinSetDurabilityAging(pItem); 

		break;
		case sinWM1: // Cajado
			//°ø°Ý·Â 
			sinSetDamageAging(pItem);

			//¸íÁß·Â
			sinSetAttackRateAging(pItem , 10);

			//±â·Â  
			pItem->fIncrease_Mana += 10;

		break;
		case sinWP1: //Foice
			//°ø°Ý·Â 
			sinSetDamageAging(pItem);

			//¸íÁß·Â
			sinSetAttackRateAging(pItem , 5);

			//Å©¸®Æ¼ÄÃ  
			sinSetCriticalAging(pItem);

		break;
		case sinWS1: //Arco
			//°ø°Ý·Â 
			sinSetDamageAging(pItem);

			//Å©¸®Æ¼ÄÃ  
			sinSetCriticalAging(pItem);

			//³»±¸·Â
			sinSetDurabilityAging(pItem); 
		break;

		case sinWS2: //Espada 
			//°ø°Ý·Â 
			sinSetDamageAging(pItem);

			//¸íÁß·Â
			sinSetAttackRateAging(pItem , 5);
			
			//Å©¸®Æ¼ÄÃ  
			sinSetCriticalAging(pItem);

		break;

		case sinWT1: //Lança 
			//°ø°Ý·Â 
			sinSetDamageAging(pItem);

			//Å©¸®Æ¼ÄÃ  
			sinSetCriticalAging(pItem);

			//³»±¸·Â
			//sinSetDurabilityAging(pItem); 
		break;
			
		case sinDS1: //Escudo 
			//ºí·°À² 
			sinSetBlockRateAging(pItem);
			//Èí¼öÀ²
			sinSetAbsorbAging(pItem , 0.2f);
			//³»±¸·Â
			sinSetDurabilityAging(pItem); 
		break;

		case sinOM1: //Orbe
			//¹æ¾î·Â 
			sinSetDefenseAging(pItem,10);

			//Èí¼öÀ²
			sinSetAbsorbAging(pItem , 0.5f);

			//³»±¸·Â
			sinSetDurabilityAging(pItem); 

		break;
		case sinDA1: case sinDA2:// Armaduras
			//¹æ¾î·Â 
			sinSetDefenseAging(pItem,5);

			//Èí¼öÀ²
			sinSetAbsorbAging(pItem , 0.5f);

			//³»±¸·Â
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
	if(pItem->Durability[1] < pItem->Durability[0] ) pItem->Durability[0] = pItem->Durability[1]; //ÇöÁ¦ ³»±¸·Â º¸Á¤ 

	return TRUE;
}
int sinSetDamageAging(sITEMINFO *pItem)
{
	pItem->Damage[0]++;
	pItem->Damage[1]++;

	if (pItem->ItemAgingNum[0] >= 9){ //10Â÷ºÎÅÍ´Â µ¥¹ÌÁö +2
		pItem->Damage[0]++;
		pItem->Damage[1]++;
	}

	// ¹ÚÀç¿ø - ¿¡ÀÌÂ¡ ¼³Á¤ º¯°æ(¹«±â·ù ·¹º§º° °ø°Ý·Â Ãß°¡)
	if (pItem->ItemAgingNum[0] >= 19){ //20Â÷ºÎÅÍ´Â µ¥¹ÌÁö +3
		pItem->Damage[0]++;
		pItem->Damage[1]++;
	}

	if (pItem->ItemAgingNum[0] >= 20){ //20Â÷ºÎÅÍ´Â µ¥¹ÌÁö +3
		pItem->fIncrease_Life += 20;
	}

	if (pItem->ItemAgingNum[0] == 21 || pItem->ItemAgingNum[0] == 23){
		pItem->Attack_Speed++;
	}

	return TRUE;
}

//°ø°Ý·Â
int sinSetRingAging(sITEMINFO *pItem)
{
	if(pItem->ItemAgingNum[0] < 2){ //10Â÷ºÎÅÍ´Â µ¥¹ÌÁö +2
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
//¹æ¾î·Â
int sinSetDefenseAging(sITEMINFO *pItem , int Percent)
{
	float Temp = 0;
	Temp = (float)pItem->Defence/(100.0f / (float)Percent);
	pItem->Defence += (int)Temp;

	if (pItem->ItemAgingNum[0] >= 20){ //20Â÷ºÎÅÍ´Â µ¥¹ÌÁö +3
		pItem->fIncrease_Life += 50;
	}

	return TRUE;
}

//¸íÁß·Â
int sinSetAttackRateAging(sITEMINFO *pItem , int AddNum)
{
	pItem->Attack_Rating += AddNum;
	return TRUE;
}
//Èí¼öÀ²
int sinSetAbsorbAging(sITEMINFO *pItem , float Percent)
{
	pItem->fAbsorb += Percent;

	if(pItem->ItemAgingNum[0] >= 9){ //10Â÷ºÎÅÍ´Â 2¹è
		pItem->fAbsorb += Percent;
	}

	// ¹ÚÀç¿ø - ¿¡ÀÌÂ¡ ¼³Á¤ º¯°æ(¹«±â·ù ·¹º§º° °ø°Ý·Â Ãß°¡)
	if(pItem->ItemAgingNum[0] >= 19){ //20Â÷ºÎÅÍ´Â 3¹è
		pItem->fAbsorb += Percent;
	}

	return TRUE;
}

//Å©¸®Æ¼ÄÃ
int sinSetCriticalAging(sITEMINFO *pItem)
{
	if(pItem->ItemAgingNum[0] && (pItem->ItemAgingNum[0]%2) == 1){
		pItem->Critical_Hit += 1;

	}
	return TRUE;
}

//ºí·°À²
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


