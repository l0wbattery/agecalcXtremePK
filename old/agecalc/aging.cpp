//SWITCH


		case sinOR1: //Anel
		case sinOR2:
			sinSetRingAging(pItem);
			break;
		case sinWA1: //Machado
			//���ݷ� 
			sinSetDamageAging(pItem);
			//���߷�
			sinSetAttackRateAging(pItem , 10);
			//������
			sinSetDurabilityAging(pItem); 

		break;
		case sinWC1: //Garra
			//���ݷ� 
			sinSetDamageAging(pItem);
			//���߷�
			sinSetAttackRateAging(pItem , 5);
			//ũ��Ƽ��  
			sinSetCriticalAging(pItem);

		break;

		case sinWH1: //Martelo
			//���ݷ� 
			sinSetDamageAging(pItem);

			//���߷�
			sinSetAttackRateAging(pItem , 10);
			//������
			sinSetDurabilityAging(pItem); 

		break;
		case sinWM1: // Cajado
			//���ݷ� 
			sinSetDamageAging(pItem);

			//���߷�
			sinSetAttackRateAging(pItem , 10);

			//���  
			pItem->fIncrease_Mana += 10;

		break;
		case sinWP1: //Foice
			//���ݷ� 
			sinSetDamageAging(pItem);

			//���߷�
			sinSetAttackRateAging(pItem , 5);

			//ũ��Ƽ��  
			sinSetCriticalAging(pItem);

		break;
		case sinWS1: //Arco
			//���ݷ� 
			sinSetDamageAging(pItem);

			//ũ��Ƽ��  
			sinSetCriticalAging(pItem);

			//������
			sinSetDurabilityAging(pItem); 
		break;

		case sinWS2: //Espada 
			//���ݷ� 
			sinSetDamageAging(pItem);

			//���߷�
			sinSetAttackRateAging(pItem , 5);
			
			//ũ��Ƽ��  
			sinSetCriticalAging(pItem);

		break;

		case sinWT1: //Lan�a 
			//���ݷ� 
			sinSetDamageAging(pItem);

			//ũ��Ƽ��  
			sinSetCriticalAging(pItem);

			//������
			//sinSetDurabilityAging(pItem); 
		break;
			
		case sinDS1: //Escudo 
			//���� 
			sinSetBlockRateAging(pItem);
			//�����
			sinSetAbsorbAging(pItem , 0.2f);
			//������
			sinSetDurabilityAging(pItem); 
		break;

		case sinOM1: //Orbe
			//���� 
			sinSetDefenseAging(pItem,10);

			//�����
			sinSetAbsorbAging(pItem , 0.5f);

			//������
			sinSetDurabilityAging(pItem); 

		break;
		case sinDA1: case sinDA2:// Armaduras
			//���� 
			sinSetDefenseAging(pItem,5);

			//�����
			sinSetAbsorbAging(pItem , 0.5f);

			//������
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
	if(pItem->Durability[1] < pItem->Durability[0] ) pItem->Durability[0] = pItem->Durability[1]; //���� ������ ���� 

	return TRUE;
}
int sinSetDamageAging(sITEMINFO *pItem)
{
	pItem->Damage[0]++;
	pItem->Damage[1]++;

	if (pItem->ItemAgingNum[0] >= 9){ //10�����ʹ� ������ +2
		pItem->Damage[0]++;
		pItem->Damage[1]++;
	}

	// ����� - ����¡ ���� ����(����� ������ ���ݷ� �߰�)
	if (pItem->ItemAgingNum[0] >= 19){ //20�����ʹ� ������ +3
		pItem->Damage[0]++;
		pItem->Damage[1]++;
	}

	if (pItem->ItemAgingNum[0] >= 20){ //20�����ʹ� ������ +3
		pItem->fIncrease_Life += 20;
	}

	if (pItem->ItemAgingNum[0] == 21 || pItem->ItemAgingNum[0] == 23){
		pItem->Attack_Speed++;
	}

	return TRUE;
}

//���ݷ�
int sinSetRingAging(sITEMINFO *pItem)
{
	if(pItem->ItemAgingNum[0] < 2){ //10�����ʹ� ������ +2
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
//����
int sinSetDefenseAging(sITEMINFO *pItem , int Percent)
{
	float Temp = 0;
	Temp = (float)pItem->Defence/(100.0f / (float)Percent);
	pItem->Defence += (int)Temp;

	if (pItem->ItemAgingNum[0] >= 20){ //20�����ʹ� ������ +3
		pItem->fIncrease_Life += 50;
	}

	return TRUE;
}

//���߷�
int sinSetAttackRateAging(sITEMINFO *pItem , int AddNum)
{
	pItem->Attack_Rating += AddNum;
	return TRUE;
}
//�����
int sinSetAbsorbAging(sITEMINFO *pItem , float Percent)
{
	pItem->fAbsorb += Percent;

	if(pItem->ItemAgingNum[0] >= 9){ //10�����ʹ� 2��
		pItem->fAbsorb += Percent;
	}

	// ����� - ����¡ ���� ����(����� ������ ���ݷ� �߰�)
	if(pItem->ItemAgingNum[0] >= 19){ //20�����ʹ� 3��
		pItem->fAbsorb += Percent;
	}

	return TRUE;
}

//ũ��Ƽ��
int sinSetCriticalAging(sITEMINFO *pItem)
{
	if(pItem->ItemAgingNum[0] && (pItem->ItemAgingNum[0]%2) == 1){
		pItem->Critical_Hit += 1;

	}
	return TRUE;
}

//����
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


