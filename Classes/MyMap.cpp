#include "MyMap.h"
#include"Global.h"
#include "SimpleAudioEngine.h"

bool MyMap::init(){
	sGlobal->myMap = this;
	log("�����ֿ�ָ����ߵ�ͼû���л������⣬�������ɵ�ͼ֮ǰ��û���޸�sGlobal->mapNumֵ");
	this->m_map = TMXTiledMap::create(StringUtils::format("scene%d.tmx", sGlobal->mapNum));
	log("��ͼ�����ɹ�����ָ���¼��������ɴ�����");
	/*this->addChild(m_map,2,sGlobal->mapNum);*/
	/*m_map->setPosition(Point(0, 0));*/
	//��ʼ�����͵�
	for (int i = 0; i <= 19; i++){
		this->setPoint((this->transmitPoint[i]), -1, -1);
	}

	//������δ�������ȷ��ÿһ�������µĴ��͵㼰����Ŀ��
	//����ʱ���ϵ���˴����뽫�ᱻд����ʮ�ֳ�ª
	//�Ժ���ʱ���ٸİ�
	/*sGlobal->mapNum = this->getMapNum(sGlobal->caseNum);*/
	//switch (sGlobal->mapNum){
	//case 0:{
	//		   this->setPoint((this->transmitPoint[0]), 9, 9);
	//		   this->setDestination(0, 1, 10, 9);
	//		   sGlobal->caseNum = 0;
	//		   break;
	//}
	//case 1:{
	//		   this->setPoint((this->transmitPoint[0]), 9, 9);
	//		   this->setDestination(0, 0, 8, 9);
	//		   this->setPoint((this->transmitPoint[1]), 9, 10);
	//		   this->setDestination(1, 2, 8, 10);
	//		   //�˴�Ϊ���Ҳ���
	//		   /*sGlobal->hero->plot[8] = 1;*/
	//		   if (sGlobal->hero->plot[8] == 1)
	//			   sGlobal->caseNum = 27;
	//		   else if (sGlobal->hero->plot[8] == 0)
	//			   sGlobal->caseNum = 1;
	//		   break;
	//}
	//case 2:{
	//		   this->setPoint((this->transmitPoint[0]), 9, 10);
	//		   this->setDestination(0, 1, 10, 10);
	//		   this->setPoint((this->transmitPoint[1]), 9, 15);
	//		   this->setDestination(1, 3, 27, 16);
	//		   if ((sGlobal->hero->plot[0] == 0) && (sGlobal->hero->plot[8] == 0) && (sGlobal->hero->plot[12] == 0) && (sGlobal->hero->plot[13] == 0) && (sGlobal->hero->plot[6] == 0))
	//			   sGlobal->caseNum = 20;
	//		   else if ((sGlobal->hero->plot[0] == 1) && (sGlobal->hero->plot[8] == 0) && (sGlobal->hero->plot[12] == 1) && (sGlobal->hero->plot[13] == 0) && (sGlobal->hero->plot[6] == 0))
	//			   sGlobal->caseNum = 46;
	//		   else if ((sGlobal->hero->plot[0] == 1) && (sGlobal->hero->plot[8] == 0) && (sGlobal->hero->plot[12] == 1) && (sGlobal->hero->plot[13] == 0) && (sGlobal->hero->plot[6] == 0))
	//			   sGlobal->caseNum = 21;
	//		   else if ((sGlobal->hero->plot[0] == 0) && (sGlobal->hero->plot[8] == 0) && (sGlobal->hero->plot[12] == 1) && (sGlobal->hero->plot[13] == 1) && (sGlobal->hero->plot[6] == 0))
	//			   sGlobal->caseNum = 47;
	//		   else if ((sGlobal->hero->plot[8] == 1) && (sGlobal->hero->plot[6] == 0))
	//			   sGlobal->caseNum = 26;
	//		   else if ((sGlobal->hero->plot[6] == 1) && (sGlobal->hero->plot[8] == 0))
	//			   sGlobal->caseNum = 2;
	//		   break;
	//}
	//case 3:{
	//		   this->setPoint((this->transmitPoint[0]), 27, 15);
	//		   this->setDestination(0, 2, 9, 14);
	//		   this->setPoint((this->transmitPoint[1]), 15, 11);
	//		   this->setDestination(1, 5, 8, 26);
	//		   this->setPoint((this->transmitPoint[2]), 38, 30);
	//		   this->setDestination(2, 6, 3, 11);
	//		   this->setPoint((this->transmitPoint[3]), 13, 23);
	//		   this->setDestination(3, 11, 13, 7);
	//		   this->setPoint((this->transmitPoint[4]), 22, 36);
	//		   this->setDestination(4, 4, 19, 20);
	//		   if (sGlobal->hero->plot[5] == 0)//����sister
	//		   {
	//			   if ((sGlobal->hero->plot[16] == 0) && (sGlobal->hero->plot[13] == 0) && (sGlobal->hero->plot[2] == 0) && (sGlobal->hero->plot[6] == 1) && (sGlobal->hero->plot[7] == 0) && (sGlobal->hero->plot[8] == 0) && (sGlobal->hero->plot[15] == 0) && (sGlobal->hero->plot[17] == 0))
	//				   sGlobal->caseNum = 3;
	//			   else if ((sGlobal->hero->plot[16] == 0) && (sGlobal->hero->plot[13] == 0) && (sGlobal->hero->plot[2] == 0) && (sGlobal->hero->plot[6] == 0) && (sGlobal->hero->plot[7] == 1) && (sGlobal->hero->plot[8] == 0) && (sGlobal->hero->plot[15] == 0) && (sGlobal->hero->plot[17] == 0))
	//				   sGlobal->caseNum = 8;
	//			   else if ((sGlobal->hero->plot[16] == 0) && (sGlobal->hero->plot[13] == 0) && (sGlobal->hero->plot[2] == 0) && (sGlobal->hero->plot[6] == 0) && (sGlobal->hero->plot[7] == 1) && (sGlobal->hero->plot[8] == 0) && (sGlobal->hero->plot[15] == 1) && (sGlobal->hero->plot[17] == 0))
	//				   sGlobal->caseNum = 13;
	//			   else if ((sGlobal->hero->plot[16] == 0) && (sGlobal->hero->plot[13] == 0) && (sGlobal->hero->plot[2] == 0) && (sGlobal->hero->plot[6] == 0) && (sGlobal->hero->plot[7] == 1) && (sGlobal->hero->plot[8] == 0) && (sGlobal->hero->plot[15] == 0) && (sGlobal->hero->plot[17] == 1))
	//				   sGlobal->caseNum = 39;
	//			   else if ((sGlobal->hero->plot[16] == 1) && (sGlobal->hero->plot[13] == 0) && (sGlobal->hero->plot[2] == 0) && (sGlobal->hero->plot[6] == 0) && (sGlobal->hero->plot[7] == 1) && (sGlobal->hero->plot[8] == 0) && (sGlobal->hero->plot[15] == 0) && (sGlobal->hero->plot[17] == 1))
	//				   sGlobal->caseNum = 19;
	//			   else if ((sGlobal->hero->plot[16] == 0) && (sGlobal->hero->plot[13] == 0) && (sGlobal->hero->plot[2] == 1) && (sGlobal->hero->plot[6] == 0) && (sGlobal->hero->plot[7] == 1) && (sGlobal->hero->plot[8] == 0) && (sGlobal->hero->plot[15] == 1) && (sGlobal->hero->plot[17] == 0))
	//				   sGlobal->caseNum = 45;
	//			   else if ((sGlobal->hero->plot[16] == 0) && (sGlobal->hero->plot[13] == 1) && (sGlobal->hero->plot[2] == 1) && (sGlobal->hero->plot[6] == 0) && (sGlobal->hero->plot[7] == 1) && (sGlobal->hero->plot[8] == 0) && (sGlobal->hero->plot[15] == 1) && (sGlobal->hero->plot[17] == 0))
	//				   sGlobal->caseNum = 22;
	//			   else if ((sGlobal->hero->plot[16] == 1) && (sGlobal->hero->plot[13] == 0) && (sGlobal->hero->plot[2] == 0) && (sGlobal->hero->plot[6] == 0) && (sGlobal->hero->plot[7] == 1) && (sGlobal->hero->plot[8] == 0) && (sGlobal->hero->plot[15] == 0) && (sGlobal->hero->plot[17] == 1))
	//				   sGlobal->caseNum = 48;
	//			   else if ((sGlobal->hero->plot[16] == 0) && (sGlobal->hero->plot[13] == 1) && (sGlobal->hero->plot[2] == 1) && (sGlobal->hero->plot[6] == 0) && (sGlobal->hero->plot[7] == 0) && (sGlobal->hero->plot[8] == 1) && (sGlobal->hero->plot[15] == 1) && (sGlobal->hero->plot[17] == 0))
	//				   sGlobal->caseNum = 28;
	//			   else if ((sGlobal->hero->plot[16] == 1) && (sGlobal->hero->plot[13] == 1) && (sGlobal->hero->plot[2] == 1) && (sGlobal->hero->plot[6] == 0) && (sGlobal->hero->plot[7] == 0) && (sGlobal->hero->plot[8] == 1) && (sGlobal->hero->plot[15] == 1) && (sGlobal->hero->plot[17] == 1))
	//				   sGlobal->caseNum = 51;
	//		   }


	//		   else if (sGlobal->hero->plot[5] == 1)
	//		   {
	//			   sGlobal->caseNum = 32;
	//		   }
	//		   break;
	//}
	//case 4:{
	//		   this->setPoint((this->transmitPoint[0]), 19, 22);
	//		   this->setDestination(0, 3, 22, 34);
	//		   this->setPoint((this->transmitPoint[1]), 29, 11);
	//		   this->setDestination(1, 7, 10, 31);
	//		   this->setPoint((this->transmitPoint[2]), 22, 8);
	//		   this->setDestination(2, 10, 8, 17);
	//		   this->setPoint((this->transmitPoint[3]), 16, 8);
	//		   this->setDestination(3, 9, 5, 14);
	//		   if ((sGlobal->hero->plot[0] == 0) && (sGlobal->hero->plot[7] == 0) && (sGlobal->hero->plot[15] == 0) && (sGlobal->hero->plot[1] == 0))
	//			   sGlobal->caseNum = 4;
	//		   else if ((sGlobal->hero->plot[0] == 1) && (sGlobal->hero->plot[7] == 1) && (sGlobal->hero->plot[15] == 0) && (sGlobal->hero->plot[1] == 0))
	//			   sGlobal->caseNum = 11;
	//		   else if ((sGlobal->hero->plot[0] == 0) && (sGlobal->hero->plot[7] == 1) && (sGlobal->hero->plot[15] == 0) && (sGlobal->hero->plot[1] == 0))
	//			   sGlobal->caseNum = 37;
	//		   else if ((sGlobal->hero->plot[0] == 1) && (sGlobal->hero->plot[7] == 1) && (sGlobal->hero->plot[15] == 1) && (sGlobal->hero->plot[1] == 0))
	//			   sGlobal->caseNum = 12;
	//		   else if ((sGlobal->hero->plot[0] == 1) && (sGlobal->hero->plot[7] == 1) && (sGlobal->hero->plot[15] == 1) && (sGlobal->hero->plot[1] == 1))
	//			   sGlobal->caseNum = 14;
	//		   else if ((sGlobal->hero->plot[0] == 0) && (sGlobal->hero->plot[7] == 1) && (sGlobal->hero->plot[15] == 0) && (sGlobal->hero->plot[1] == 1))
	//			   sGlobal->caseNum = 40;
	//		   break;
	//}
	//case 5:{
	//		   this->setPoint((this->transmitPoint[0]), 8, 27);
	//		   this->setDestination(0, 3, 15, 12);
	//		   this->setPoint((this->transmitPoint[1]), 15, 12);
	//		   this->setDestination(1, 12, 52, 30);
	//		   this->setPoint((this->transmitPoint[2]), 15, 11);
	//		   this->setDestination(2, 13, 9, 7);
	//		   if ((sGlobal->hero->plot[5] == 0) && (sGlobal->hero->plot[10] == 0) && (sGlobal->hero->plot[11] == 0))
	//			   sGlobal->caseNum = 25;
	//		   else if ((sGlobal->hero->plot[5] == 0) && (sGlobal->hero->plot[10] == 1) && (sGlobal->hero->plot[11] == 0))
	//			   sGlobal->caseNum = 29;
	//		   else if ((sGlobal->hero->plot[5] == 0) && (sGlobal->hero->plot[10] == 1) && (sGlobal->hero->plot[11] == 1))
	//			   sGlobal->caseNum = 31;
	//		   else if ((sGlobal->hero->plot[5] == 1) && (sGlobal->hero->plot[10] == 1) && (sGlobal->hero->plot[11] == 1))
	//			   sGlobal->caseNum = 50;
	//		   break;
	//}
	//case 6:{
	//		   this->setPoint((this->transmitPoint[0]), 3, 12);
	//		   this->setDestination(0, 3, 38, 31);
	//		   if ((sGlobal->hero->plot[7] == 0) && (sGlobal->hero->plot[8] == 0) && (sGlobal->hero->plot[9] == 0) && (sGlobal->hero->plot[10] == 0) && (sGlobal->hero->plot[1] == 0) && (sGlobal->hero->plot[16] == 0) && (sGlobal->hero->plot[5] == 0))
	//			   sGlobal->caseNum = 6;
	//		   else if ((sGlobal->hero->plot[7] == 1) && (sGlobal->hero->plot[8] == 0) && (sGlobal->hero->plot[9] == 0) && (sGlobal->hero->plot[10] == 0) && (sGlobal->hero->plot[1] == 0) && (sGlobal->hero->plot[16] == 0) && (sGlobal->hero->plot[5] == 0))
	//			   sGlobal->caseNum = 7;
	//		   else if ((sGlobal->hero->plot[7] == 1) && (sGlobal->hero->plot[8] == 0) && (sGlobal->hero->plot[9] == 0) && (sGlobal->hero->plot[10] == 0) && (sGlobal->hero->plot[1] == 1) && (sGlobal->hero->plot[16] == 0) && (sGlobal->hero->plot[5] == 0))
	//			   sGlobal->caseNum = 23;
	//		   else if ((sGlobal->hero->plot[7] == 1) && (sGlobal->hero->plot[8] == 0) && (sGlobal->hero->plot[9] == 0) && (sGlobal->hero->plot[10] == 0) && (sGlobal->hero->plot[1] == 0) && (sGlobal->hero->plot[16] == 1) && (sGlobal->hero->plot[5] == 0))
	//			   sGlobal->caseNum = 49;
	//		   else if ((sGlobal->hero->plot[7] == 0) && (sGlobal->hero->plot[8] == 1) && (sGlobal->hero->plot[9] == 0) && (sGlobal->hero->plot[10] == 0) && (sGlobal->hero->plot[1] == 1) && (sGlobal->hero->plot[16] == 1) && (sGlobal->hero->plot[5] == 0))
	//			   sGlobal->caseNum = 24;
	//		   else if ((sGlobal->hero->plot[7] == 0) && (sGlobal->hero->plot[8] == 1) && (sGlobal->hero->plot[9] == 0) && (sGlobal->hero->plot[10] == 1) && (sGlobal->hero->plot[1] == 1) && (sGlobal->hero->plot[16] == 1) && (sGlobal->hero->plot[5] == 1))
	//			   sGlobal->caseNum = 33;
	//		   else if ((sGlobal->hero->plot[7] == 0) && (sGlobal->hero->plot[8] == 1) && (sGlobal->hero->plot[9] == 0) && (sGlobal->hero->plot[10] == 1) && (sGlobal->hero->plot[1] == 1) && (sGlobal->hero->plot[16] == 1) && (sGlobal->hero->plot[5] == 0))
	//			   sGlobal->caseNum = 52;
	//		   else if ((sGlobal->hero->plot[7] == 0) && (sGlobal->hero->plot[8] == 0) && (sGlobal->hero->plot[9] == 1) && (sGlobal->hero->plot[10] == 1) && (sGlobal->hero->plot[1] == 1) && (sGlobal->hero->plot[16] == 1) && (sGlobal->hero->plot[5] == 1))
	//			   sGlobal->caseNum = 34;


	//		   break;
	//}
	//case 7:{
	//		   this->setPoint((this->transmitPoint[0]), 10, 32);
	//		   this->setDestination(0, 4, 29, 12);
	//		   this->setPoint((this->transmitPoint[1]), 23, 5);
	//		   this->setDestination(1, 8, 1, 5);
	//		   if ((sGlobal->hero->plot[0] == 0) && (sGlobal->hero->plot[14] == 0) && (sGlobal->hero->plot[1] == 0))
	//			   sGlobal->caseNum = 9;
	//		   else if ((sGlobal->hero->plot[0] == 1) && (sGlobal->hero->plot[14] == 1) && (sGlobal->hero->plot[1] == 0))
	//			   sGlobal->caseNum = 10;
	//		   else if ((sGlobal->hero->plot[0] == 0) && (sGlobal->hero->plot[14] == 1) && (sGlobal->hero->plot[1] == 0))
	//			   sGlobal->caseNum = 36;
	//		   else if ((sGlobal->hero->plot[0] == 1) && (sGlobal->hero->plot[14] == 1) && (sGlobal->hero->plot[1] == 1))
	//			   sGlobal->caseNum = 16;
	//		   else if ((sGlobal->hero->plot[0] == 0) && (sGlobal->hero->plot[14] == 1) && (sGlobal->hero->plot[1] == 1))
	//			   sGlobal->caseNum = 42;
	//		   break;
	//}
	//case 8:{
	//		   this->setPoint((this->transmitPoint[0]), 0, 5);
	//		   this->setDestination(0, 7, 22, 5);
	//		   if (sGlobal->hero->plot[0] == 0)
	//			   sGlobal->caseNum = 17;
	//		   else if (sGlobal->hero->plot[0] == 1)
	//			   sGlobal->caseNum = 43;
	//		   break;
	//}
	//case 9:{
	//		   this->setPoint((this->transmitPoint[0]), 5, 15);
	//		   this->setDestination(0, 4, 16, 9);
	//		   if (sGlobal->hero->plot[0] == 0)
	//			   sGlobal->caseNum = 41;
	//		   else if (sGlobal->hero->plot[0] == 1)
	//			   sGlobal->caseNum = 15;
	//		   break;
	//}
	//case 10:{
	//			this->setPoint((this->transmitPoint[0]), 8, 18);
	//			this->setDestination(0, 4, 22, 9);
	//			if ((sGlobal->hero->plot[5] == 1) && (sGlobal->hero->plot[0] == 0) && (sGlobal->hero->plot[3] == 1))
	//				sGlobal->caseNum = 35;
	//			else if ((sGlobal->hero->plot[5] == 0) && (sGlobal->hero->plot[0] == 1) && (sGlobal->hero->plot[2] == 1))
	//				sGlobal->caseNum = 54;
	//			else if ((sGlobal->hero->plot[5] == 0) && (sGlobal->hero->plot[0] == 0) && (sGlobal->hero->plot[3] == 1))
	//				sGlobal->caseNum = 53;
	//			else if ((sGlobal->hero->plot[5] == 1) && (sGlobal->hero->plot[0] == 1) && (sGlobal->hero->plot[2] == 1))
	//				sGlobal->caseNum = 53;
	//			break;
	//}
	//case 11:{
	//			this->setPoint((this->transmitPoint[0]), 12, 7);
	//			this->setDestination(0, 3, 14, 23);
	//			sGlobal->caseNum = 5;
	//			break;
	//}
	//case 12:{
	//			this->setPoint((this->transmitPoint[0]), 51, 30);
	//			this->setDestination(0, 5, 14, 12);
	//			if (sGlobal->hero->plot[0] == 0)
	//				sGlobal->caseNum = 18;
	//			else if (sGlobal->hero->plot[0] == 1)
	//				sGlobal->caseNum = 44;
	//			break;
	//}
	//case 13:{
				//this->setPoint((this->transmitPoint[0]), 21,8);
				//this->setDestination(0,13,29,10);
				//this->setPoint((this->transmitPoint[1]), 42,9);
				//this->setDestination(1, 13,49,27);
				//this->setPoint((this->transmitPoint[2]), 67,26);
				//this->setDestination(2, 13,36,39);
				//this->setPoint((this->transmitPoint[3]), 34,50);
				//this->setDestination(3, 13, 70,41);
				//this->setPoint((this->transmitPoint[4]), 48,43);
				//this->setDestination(4, 13, 10,55);
				//this->setPoint((this->transmitPoint[5]), 16,70);
				//this->setDestination(5, 1, 9, 11);
				//this->setPoint((this->transmitPoint[6]),21,8);
				//this->setDestination(6, 13,9,7);
				//this->setPoint((this->transmitPoint[7]), 10,25);
				//this->setDestination(7, 13, 9, 7);
				//this->setPoint((this->transmitPoint[8]), 31,24);
				//this->setDestination(8, 13, 9, 7);
				//this->setPoint((this->transmitPoint[9]),41,22);
				//this->setDestination(9, 13, 9, 7);
				//this->setPoint((this->transmitPoint[10]), 59,13);
				//this->setDestination(10, 13, 9, 7);
				//this->setPoint((this->transmitPoint[11]), 69,8);
				//this->setDestination(11, 13, 9, 7);
				//this->setPoint((this->transmitPoint[12]), 18,38);
				//this->setDestination(12, 13, 9, 7);
				//this->setPoint((this->transmitPoint[13]), 10,50);
				//this->setDestination(13, 13, 9, 7);
				//this->setPoint((this->transmitPoint[14]), 61,57);
				//this->setDestination(14, 13, 9, 7);
				//this->setPoint((this->transmitPoint[15]), 69, 71);
				//this->setDestination(15, 1, 9, 11);
				//this->setPoint((this->transmitPoint[16]), 19, 28);
				//this->setDestination(16, 13, 9, 7);
	//			sGlobal->hero->plot[11] = 1;
	//			sGlobal->caseNum = 30;
	//			break;
	//}
	//}
switch (sGlobal->mapNum){
case 0:{
		   CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("caidianddixiashi.mp3");
		   CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("iss.mp3");

		   CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("litang.mp3");
		   CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("qinshiandshangdian.mp3");
		   CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("tushuguan.mp3");
		   CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("xuedi.mp3");
		   this->setPoint((this->transmitPoint[0]), 9, 9);
		   this->setDestination(0, 1, 10, 9);
		   sGlobal->caseNum = 0;
		   CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("backgroundBGM.mp3", true);
		   break;
}
case 1:{
		   CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("caidianddixiashi.mp3");
		   CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("iss.mp3");

		   CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("litang.mp3");
		   CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("qinshiandshangdian.mp3");
		   CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("tushuguan.mp3");
		   CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("xuedi.mp3");
		   this->setPoint((this->transmitPoint[0]), 9, 9);
		   this->setDestination(0, 0, 8, 9);
		   this->setPoint((this->transmitPoint[1]), 9, 10);
		   this->setDestination(1, 2, 8, 10);
		   //�˴�Ϊ���Ҳ���
		   /*sGlobal->hero->plot[8] = 1;*/
		   if (sGlobal->hero->plot[8] == 1)
			   sGlobal->caseNum = 27;
		   else if (sGlobal->hero->plot[8] == 0)
			   sGlobal->caseNum = 1;
		   CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("jiaoxuelou.mp3", true);
		   break;
}
case 2:{
		   CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("caidianddixiashi.mp3");
		   CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("iss.mp3");

		   CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("litang.mp3");
		   CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("qinshiandshangdian.mp3");
		   CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("tushuguan.mp3");
		   CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("xuedi.mp3");
		   this->setPoint((this->transmitPoint[0]), 9, 10);
		   this->setDestination(0, 1, 10, 10);
		   this->setPoint((this->transmitPoint[1]), 9, 15);
		   this->setDestination(1, 3, 27, 16);
		   if ((sGlobal->hero->plot[0] == 0) && (sGlobal->hero->plot[8] == 0) && (sGlobal->hero->plot[12] == 0) && (sGlobal->hero->plot[13] == 0) && (sGlobal->hero->plot[6] == 0))
			   sGlobal->caseNum = 20;
		   else if ((sGlobal->hero->plot[0] == 1) && (sGlobal->hero->plot[8] == 0) && (sGlobal->hero->plot[12] == 1) && (sGlobal->hero->plot[13] == 0) && (sGlobal->hero->plot[6] == 0))
			   sGlobal->caseNum = 46;
		   else if ((sGlobal->hero->plot[0] == 1) && (sGlobal->hero->plot[8] == 0) && (sGlobal->hero->plot[12] == 1) && (sGlobal->hero->plot[13] == 0) && (sGlobal->hero->plot[6] == 0))
			   sGlobal->caseNum = 21;
		   else if ((sGlobal->hero->plot[0] == 0) && (sGlobal->hero->plot[8] == 0) && (sGlobal->hero->plot[12] == 1) && (sGlobal->hero->plot[13] == 1) && (sGlobal->hero->plot[6] == 0))
			   sGlobal->caseNum = 47;
		   else if ((sGlobal->hero->plot[8] == 1) && (sGlobal->hero->plot[6] == 0))
			   sGlobal->caseNum = 26;
		   else if ((sGlobal->hero->plot[6] == 1) && (sGlobal->hero->plot[8] == 0))
			   sGlobal->caseNum = 2;
		   CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("jiaoxuelou.mp3", true);
		   break;
}
case 3:{
		   CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("caidianddixiashi.mp3");

		   CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("jiaoxuelou.mp3");
		   CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("litang.mp3");
		   CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("qinshiandshangdian.mp3");
		   CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("tushuguan.mp3");
		   CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("xuedi.mp3");
		   this->setPoint((this->transmitPoint[0]), 27, 15);
		   this->setDestination(0, 2, 9, 14);
		   this->setPoint((this->transmitPoint[1]), 15, 11);
		   this->setDestination(1, 5, 8, 26);
		   this->setPoint((this->transmitPoint[2]), 38, 30);
		   this->setDestination(2, 6, 3, 11);
		   this->setPoint((this->transmitPoint[3]), 13, 23);
		   this->setDestination(3, 11, 13, 7);
		   this->setPoint((this->transmitPoint[4]), 22, 36);
		   this->setDestination(4, 4, 19, 20);
		   if (sGlobal->hero->plot[5] == 0)//����sister
		   {
			   if ((sGlobal->hero->plot[16] == 0) && (sGlobal->hero->plot[13] == 0) && (sGlobal->hero->plot[2] == 0) && (sGlobal->hero->plot[6] == 1) && (sGlobal->hero->plot[7] == 0) && (sGlobal->hero->plot[8] == 0) && (sGlobal->hero->plot[15] == 0) && (sGlobal->hero->plot[17] == 0))
				   sGlobal->caseNum = 3;
			   else if ((sGlobal->hero->plot[16] == 0) && (sGlobal->hero->plot[13] == 0) && (sGlobal->hero->plot[2] == 0) && (sGlobal->hero->plot[6] == 0) && (sGlobal->hero->plot[7] == 1) && (sGlobal->hero->plot[8] == 0) && (sGlobal->hero->plot[15] == 0) && (sGlobal->hero->plot[17] == 0))
				   sGlobal->caseNum = 8;
			   else if ((sGlobal->hero->plot[16] == 0) && (sGlobal->hero->plot[13] == 0) && (sGlobal->hero->plot[2] == 0) && (sGlobal->hero->plot[6] == 0) && (sGlobal->hero->plot[7] == 1) && (sGlobal->hero->plot[8] == 0) && (sGlobal->hero->plot[15] == 1) && (sGlobal->hero->plot[17] == 0))
				   sGlobal->caseNum = 13;
			   else if ((sGlobal->hero->plot[16] == 0) && (sGlobal->hero->plot[13] == 0) && (sGlobal->hero->plot[2] == 0) && (sGlobal->hero->plot[6] == 0) && (sGlobal->hero->plot[7] == 1) && (sGlobal->hero->plot[8] == 0) && (sGlobal->hero->plot[15] == 0) && (sGlobal->hero->plot[17] == 1))
				   sGlobal->caseNum = 39;
			   else if ((sGlobal->hero->plot[16] == 1) && (sGlobal->hero->plot[13] == 0) && (sGlobal->hero->plot[2] == 0) && (sGlobal->hero->plot[6] == 0) && (sGlobal->hero->plot[7] == 1) && (sGlobal->hero->plot[8] == 0) && (sGlobal->hero->plot[15] == 0) && (sGlobal->hero->plot[17] == 1))
				   sGlobal->caseNum = 19;
			   else if ((sGlobal->hero->plot[16] == 0) && (sGlobal->hero->plot[13] == 0) && (sGlobal->hero->plot[2] == 1) && (sGlobal->hero->plot[6] == 0) && (sGlobal->hero->plot[7] == 1) && (sGlobal->hero->plot[8] == 0) && (sGlobal->hero->plot[15] == 1) && (sGlobal->hero->plot[17] == 0))
				   sGlobal->caseNum = 45;
			   else if ((sGlobal->hero->plot[16] == 0) && (sGlobal->hero->plot[13] == 1) && (sGlobal->hero->plot[2] == 1) && (sGlobal->hero->plot[6] == 0) && (sGlobal->hero->plot[7] == 1) && (sGlobal->hero->plot[8] == 0) && (sGlobal->hero->plot[15] == 1) && (sGlobal->hero->plot[17] == 0))
				   sGlobal->caseNum = 22;
			   else if ((sGlobal->hero->plot[16] == 1) && (sGlobal->hero->plot[13] == 0) && (sGlobal->hero->plot[2] == 0) && (sGlobal->hero->plot[6] == 0) && (sGlobal->hero->plot[7] == 1) && (sGlobal->hero->plot[8] == 0) && (sGlobal->hero->plot[15] == 0) && (sGlobal->hero->plot[17] == 1))
				   sGlobal->caseNum = 48;
			   else if ((sGlobal->hero->plot[16] == 0) && (sGlobal->hero->plot[13] == 1) && (sGlobal->hero->plot[2] == 1) && (sGlobal->hero->plot[6] == 0) && (sGlobal->hero->plot[7] == 0) && (sGlobal->hero->plot[8] == 1) && (sGlobal->hero->plot[15] == 1) && (sGlobal->hero->plot[17] == 0))
				   sGlobal->caseNum = 28;
			   else if ((sGlobal->hero->plot[16] == 1) && (sGlobal->hero->plot[13] == 1) && (sGlobal->hero->plot[2] == 1) && (sGlobal->hero->plot[6] == 0) && (sGlobal->hero->plot[7] == 0) && (sGlobal->hero->plot[8] == 1) && (sGlobal->hero->plot[15] == 1) && (sGlobal->hero->plot[17] == 1))
				   sGlobal->caseNum = 51;
		   }


		   else if (sGlobal->hero->plot[5] == 1)
		   {
			   sGlobal->caseNum = 32;
		   }
		   CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("iss.mp3", true);
		   break;
}
case 4:{
		   CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("caidianddixiashi.mp3");

		   CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("jiaoxuelou.mp3");
		   CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("litang.mp3");
		   CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("qinshiandshangdian.mp3");
		   CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("tushuguan.mp3");
		   CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("xuedi.mp3");
		   this->setPoint((this->transmitPoint[0]), 19, 22);
		   this->setDestination(0, 3, 22, 34);
		   this->setPoint((this->transmitPoint[1]), 29, 11);
		   this->setDestination(1, 7, 10, 31);
		   this->setPoint((this->transmitPoint[2]), 22, 8);
		   this->setDestination(2, 10, 8, 17);
		   this->setPoint((this->transmitPoint[3]), 16, 8);
		   this->setDestination(3, 9, 5, 14);
		   if ((sGlobal->hero->plot[0] == 0) && (sGlobal->hero->plot[7] == 0) && (sGlobal->hero->plot[15] == 0) && (sGlobal->hero->plot[1] == 0))
			   sGlobal->caseNum = 4;
		   else if ((sGlobal->hero->plot[0] == 1) && (sGlobal->hero->plot[7] == 1) && (sGlobal->hero->plot[15] == 0) && (sGlobal->hero->plot[1] == 0))
			   sGlobal->caseNum = 11;
		   else if ((sGlobal->hero->plot[0] == 0) && (sGlobal->hero->plot[7] == 1) && (sGlobal->hero->plot[15] == 0) && (sGlobal->hero->plot[1] == 0))
			   sGlobal->caseNum = 37;
		   else if ((sGlobal->hero->plot[0] == 1) && (sGlobal->hero->plot[7] == 1) && (sGlobal->hero->plot[15] == 1) && (sGlobal->hero->plot[1] == 0))
			   sGlobal->caseNum = 12;
		   else if ((sGlobal->hero->plot[0] == 1) && (sGlobal->hero->plot[7] == 1) && (sGlobal->hero->plot[15] == 1) && (sGlobal->hero->plot[1] == 1))
			   sGlobal->caseNum = 14;
		   else if ((sGlobal->hero->plot[0] == 0) && (sGlobal->hero->plot[7] == 1) && (sGlobal->hero->plot[15] == 0) && (sGlobal->hero->plot[1] == 1))
			   sGlobal->caseNum = 40;
		   CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("iss.mp3", true);
		   break;
}
case 5:{
		   CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("caidianddixiashi.mp3");
		   CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("iss.mp3");
		   CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("jiaoxuelou.mp3");

		   CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("qinshiandshangdian.mp3");
		   CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("tushuguan.mp3");
		   CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("xuedi.mp3");
		   this->setPoint((this->transmitPoint[0]), 8, 27);
		   this->setDestination(0, 3, 15, 12);
		   this->setPoint((this->transmitPoint[1]), 15, 12);
		   this->setDestination(1, 12, 52, 30);
		   this->setPoint((this->transmitPoint[2]), 15, 11);
		   this->setDestination(2, 13, 9, 7);
		   if ((sGlobal->hero->plot[5] == 0) && (sGlobal->hero->plot[10] == 0) && (sGlobal->hero->plot[11] == 0))
			   sGlobal->caseNum = 25;
		   else if ((sGlobal->hero->plot[5] == 0) && (sGlobal->hero->plot[10] == 1) && (sGlobal->hero->plot[11] == 0))
			   sGlobal->caseNum = 29;
		   else if ((sGlobal->hero->plot[5] == 0) && (sGlobal->hero->plot[10] == 1) && (sGlobal->hero->plot[11] == 1))
			   sGlobal->caseNum = 31;
		   else if ((sGlobal->hero->plot[5] == 1) && (sGlobal->hero->plot[10] == 1) && (sGlobal->hero->plot[11] == 1))
			   sGlobal->caseNum = 50;
		   CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("litang.mp3", true);
		   break;
}
case 6:{
		   CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("caidianddixiashi.mp3");
		   CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("iss.mp3");
		   CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("jiaoxuelou.mp3");
		   CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("litang.mp3");

		   CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("tushuguan.mp3");
		   CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("xuedi.mp3");
		   this->setPoint((this->transmitPoint[0]), 3, 12);
		   this->setDestination(0, 3, 38, 31);
		   if ((sGlobal->hero->plot[7] == 0) && (sGlobal->hero->plot[8] == 0) && (sGlobal->hero->plot[9] == 0) && (sGlobal->hero->plot[10] == 0) && (sGlobal->hero->plot[1] == 0) && (sGlobal->hero->plot[16] == 0) && (sGlobal->hero->plot[5] == 0))
			   sGlobal->caseNum = 6;
		   else if ((sGlobal->hero->plot[7] == 1) && (sGlobal->hero->plot[8] == 0) && (sGlobal->hero->plot[9] == 0) && (sGlobal->hero->plot[10] == 0) && (sGlobal->hero->plot[1] == 0) && (sGlobal->hero->plot[16] == 0) && (sGlobal->hero->plot[5] == 0))
			   sGlobal->caseNum = 7;
		   else if ((sGlobal->hero->plot[7] == 1) && (sGlobal->hero->plot[8] == 0) && (sGlobal->hero->plot[9] == 0) && (sGlobal->hero->plot[10] == 0) && (sGlobal->hero->plot[1] == 1) && (sGlobal->hero->plot[16] == 0) && (sGlobal->hero->plot[5] == 0))
			   sGlobal->caseNum = 23;
		   else if ((sGlobal->hero->plot[7] == 1) && (sGlobal->hero->plot[8] == 0) && (sGlobal->hero->plot[9] == 0) && (sGlobal->hero->plot[10] == 0) && (sGlobal->hero->plot[1] == 0) && (sGlobal->hero->plot[16] == 1) && (sGlobal->hero->plot[5] == 0))
			   sGlobal->caseNum = 49;
		   else if ((sGlobal->hero->plot[7] == 0) && (sGlobal->hero->plot[8] == 1) && (sGlobal->hero->plot[9] == 0) && (sGlobal->hero->plot[10] == 0) && (sGlobal->hero->plot[1] == 1) && (sGlobal->hero->plot[16] == 1) && (sGlobal->hero->plot[5] == 0))
			   sGlobal->caseNum = 24;
		   else if ((sGlobal->hero->plot[7] == 0) && (sGlobal->hero->plot[8] == 1) && (sGlobal->hero->plot[9] == 0) && (sGlobal->hero->plot[10] == 1) && (sGlobal->hero->plot[1] == 1) && (sGlobal->hero->plot[16] == 1) && (sGlobal->hero->plot[5] == 1))
			   sGlobal->caseNum = 33;
		   else if ((sGlobal->hero->plot[7] == 0) && (sGlobal->hero->plot[8] == 1) && (sGlobal->hero->plot[9] == 0) && (sGlobal->hero->plot[10] == 1) && (sGlobal->hero->plot[1] == 1) && (sGlobal->hero->plot[16] == 1) && (sGlobal->hero->plot[5] == 0))
			   sGlobal->caseNum = 52;
		   else if ((sGlobal->hero->plot[7] == 0) && (sGlobal->hero->plot[8] == 0) && (sGlobal->hero->plot[9] == 1) && (sGlobal->hero->plot[10] == 1) && (sGlobal->hero->plot[1] == 1) && (sGlobal->hero->plot[16] == 1) && (sGlobal->hero->plot[5] == 1))
			   sGlobal->caseNum = 34;

		   CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("qinshiandshangdian.mp3", true);
		   break;
}
case 7:{
		   CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("caidianddixiashi.mp3");
		   CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("iss.mp3");
		   CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("jiaoxuelou.mp3");
		   CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("litang.mp3");
		   CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("qinshiandshangdian.mp3");

		   CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("xuedi.mp3");
		   this->setPoint((this->transmitPoint[0]), 10, 32);
		   this->setDestination(0, 4, 29, 12);
		   this->setPoint((this->transmitPoint[1]), 23, 5);
		   this->setDestination(1, 8, 1, 5);
		   if ((sGlobal->hero->plot[0] == 0) && (sGlobal->hero->plot[14] == 0) && (sGlobal->hero->plot[1] == 0))
			   sGlobal->caseNum = 9;
		   else if ((sGlobal->hero->plot[0] == 1) && (sGlobal->hero->plot[14] == 1) && (sGlobal->hero->plot[1] == 0))
			   sGlobal->caseNum = 10;
		   else if ((sGlobal->hero->plot[0] == 0) && (sGlobal->hero->plot[14] == 1) && (sGlobal->hero->plot[1] == 0))
			   sGlobal->caseNum = 36;
		   else if ((sGlobal->hero->plot[0] == 1) && (sGlobal->hero->plot[14] == 1) && (sGlobal->hero->plot[1] == 1))
			   sGlobal->caseNum = 16;
		   else if ((sGlobal->hero->plot[0] == 0) && (sGlobal->hero->plot[14] == 1) && (sGlobal->hero->plot[1] == 1))
			   sGlobal->caseNum = 42;
		   CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("tushuguan.mp3", true);
		   break;
}
case 8:{
		   CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("caidianddixiashi.mp3");
		   CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("iss.mp3");
		   CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("jiaoxuelou.mp3");
		   CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("litang.mp3");
		   CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("qinshiandshangdian.mp3");

		   CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("xuedi.mp3");
		   this->setPoint((this->transmitPoint[0]), 0, 5);
		   this->setDestination(0, 7, 22, 5);
		   if (sGlobal->hero->plot[0] == 0)
			   sGlobal->caseNum = 17;
		   else if (sGlobal->hero->plot[0] == 1)
			   sGlobal->caseNum = 43;
		   CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("tushuguan.mp3", true);
		   break;
}
case 9:{
		   CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("caidianddixiashi.mp3");
		   CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("iss.mp3");
		   CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("jiaoxuelou.mp3");
		   CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("litang.mp3");

		   CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("tushuguan.mp3");
		   CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("xuedi.mp3");
		   this->setPoint((this->transmitPoint[0]), 5, 15);
		   this->setDestination(0, 4, 16, 9);
		   if (sGlobal->hero->plot[0] == 0)
			   sGlobal->caseNum = 41;
		   else if (sGlobal->hero->plot[0] == 1)
			   sGlobal->caseNum = 15;
		   CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("qinshiandshangdian.mp3", true);
		   break;
}
case 10:{
			CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("caidianddixiashi.mp3");
			CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("iss.mp3");
			CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("jiaoxuelou.mp3");
			CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("litang.mp3");

			CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("tushuguan.mp3");
			CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("xuedi.mp3");
			this->setPoint((this->transmitPoint[0]), 8, 18);
			this->setDestination(0, 4, 22, 9);
			if ((sGlobal->hero->plot[5] == 1) && (sGlobal->hero->plot[0] == 0) && (sGlobal->hero->plot[3] == 1))
				sGlobal->caseNum = 35;
			else if ((sGlobal->hero->plot[5] == 0) && (sGlobal->hero->plot[0] == 1) && (sGlobal->hero->plot[2] == 1))
				sGlobal->caseNum = 54;
			else if ((sGlobal->hero->plot[5] == 0) && (sGlobal->hero->plot[0] == 0) && (sGlobal->hero->plot[3] == 1))
				sGlobal->caseNum = 53;
			else if ((sGlobal->hero->plot[5] == 1) && (sGlobal->hero->plot[0] == 1) && (sGlobal->hero->plot[2] == 1))
				sGlobal->caseNum = 53;
			CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("qinshiandshangdian.mp3", true);
			break;
}
case 11:{

			CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("iss.mp3");
			CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("jiaoxuelou.mp3");
			CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("litang.mp3");
			CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("qinshiandshangdian.mp3");
			CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("tushuguan.mp3");
			CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("xuedi.mp3");
			this->setPoint((this->transmitPoint[0]), 12, 7);
			this->setDestination(0, 3, 14, 23);
			sGlobal->caseNum = 5;
			CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("caidianddixiashi.mp3", true);
			break;
}
case 12:{

			CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("iss.mp3");
			CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("jiaoxuelou.mp3");
			CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("litang.mp3");
			CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("qinshiandshangdian.mp3");
			CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("tushuguan.mp3");
			CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("xuedi.mp3");
			this->setPoint((this->transmitPoint[0]), 51, 30);
			this->setDestination(0, 5, 14, 12);
			if (sGlobal->hero->plot[0] == 0)
				sGlobal->caseNum = 18;
			else if (sGlobal->hero->plot[0] == 1)
				sGlobal->caseNum = 44;
			CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("caidianddixiashi.mp3", true);
			break;
}
case 13:{
			CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("caidianddixiashi.mp3");
			CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("iss.mp3");
			CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("jiaoxuelou.mp3");
			CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("litang.mp3");
			CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("qinshiandshangdian.mp3");
			CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("tushuguan.mp3");

			this->setPoint((this->transmitPoint[0]), 21, 8);
			this->setDestination(0, 13, 29, 10);
			this->setPoint((this->transmitPoint[1]), 42, 9);
			this->setDestination(1, 13, 49, 27);
			this->setPoint((this->transmitPoint[2]), 67, 26);
			this->setDestination(2, 13, 36, 39);
			this->setPoint((this->transmitPoint[3]), 34, 50);
			this->setDestination(3, 13, 70, 41);
			this->setPoint((this->transmitPoint[4]), 48, 43);
			this->setDestination(4, 13, 10, 55);
			this->setPoint((this->transmitPoint[5]), 16, 70);
			this->setDestination(5, 1, 9, 11);
			this->setPoint((this->transmitPoint[6]), 21, 8);
			this->setDestination(6, 13, 9, 7);
			this->setPoint((this->transmitPoint[7]), 10, 25);
			this->setDestination(7, 13, 9, 7);
			this->setPoint((this->transmitPoint[8]), 31, 24);
			this->setDestination(8, 13, 9, 7);
			this->setPoint((this->transmitPoint[9]), 41, 22);
			this->setDestination(9, 13, 9, 7);
			this->setPoint((this->transmitPoint[10]), 59, 13);
			this->setDestination(10, 13, 9, 7);
			this->setPoint((this->transmitPoint[11]), 69, 8);
			this->setDestination(11, 13, 9, 7);
			this->setPoint((this->transmitPoint[12]), 18, 38);
			this->setDestination(12, 13, 9, 7);
			this->setPoint((this->transmitPoint[13]), 10, 50);
			this->setDestination(13, 13, 9, 7);
			this->setPoint((this->transmitPoint[14]), 61, 57);
			this->setDestination(14, 13, 9, 7);
			this->setPoint((this->transmitPoint[15]), 69, 71);
			this->setDestination(15, 1, 9, 11);
			this->setPoint((this->transmitPoint[16]), 19, 28);
			this->setDestination(16, 13, 9, 7);
			//this->setPoint((this->transmitPoint[0]), 9,6);
			//this->setDestination(0, 5,14,11);
			sGlobal->caseNum = 30;
			CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("xuedi.mp3", true);
			break;
}
}
	this->setAllNPC();

	return true;


}

void MyMap::setPoint(Point& point, int x, int y){
	point.x = x;
	point.y = y;
}

void MyMap::setDestination(int point, int map, int x, int y){
	this->destination[point].mapNum = map;
	this->destination[point].startPosition.x = x;
	this->destination[point].startPosition.y = y;
}

void MyMap::setNPC(int NumInMap,int NPCNum, int positionX, int positionY, int keyStart, int keyEnd){
	this->npc[NumInMap].keyEnd = keyEnd;
	this->npc[NumInMap].keyStart = keyStart;
	this->npc[NumInMap].NPCNum = NPCNum;
	this->npc[NumInMap].NPCPosition.x = positionX;
	this->npc[NumInMap].NPCPosition.y = positionY;
	this->npc[NumInMap].NumInMap = NumInMap;
}

//void MyMap::changeMap(Point transmitPoint){
//	for (int i = 0; i <= 4; i++){
//		if (transmitPoint == this->transmitPoint[i]){
//			this->removeChildByTag(sGlobal->mapNum);
//			TMXTiledMap*NewMap = TMXTiledMap::create(StringUtils::format("scene%d.tmx", this->destination[i].mapNum));
//			this->addChild(NewMap, 2, this->destination[i].mapNum);
//			sGlobal->hero = Hero::create();
//			Sprite*heroSprite = Sprite::create("Hero_Down_0.png");
//			sGlobal->hero->bindSprite(heroSprite);
//			sGlobal->hero->setPosition(this->positionForTileCoord(this->destination[i].startPosition));
//			NewMap->addChild(sGlobal->hero);
//			sGlobal->map = NewMap;
//			sGlobal->mapNum = this->destination[i].mapNum;
//			break;
//		}
//	}
//}

Point MyMap::positionForTileCoord(Point tileCoord)
{
	Point pos = Point(((tileCoord.x+0.5) * 32), (((this->m_map->getMapSize().height - tileCoord.y+0.5) - 1) * this->m_map->getTileSize().height));
	return pos;
}

//�����￪ʼ����д
void MyMap::setAllNPC(){
	int i = sGlobal->caseNum;
	//switch (sGlobal->caseNum)  {
	//case 0:{
	//		   this->setNPC(0, 0, 1, 4, 29, 29);
	//		   Sprite*NPC_0 = Sprite::create("6.png");
	//		   NPC_0->setPosition(this->positionForTileCoord(Point(1, 4)));
	//		   this->m_map->addChild(NPC_0);

	//		   this->setNPC(1, 1, 4, 3, 30, 30);
	//		   Sprite*NPC_1 = Sprite::create("2.png");
	//		   NPC_1->setPosition(this->positionForTileCoord(Point(4, 3)));
	//		   this->m_map->addChild(NPC_1);
	//		   break;
	//}
	//case 1:{
	//		   this->setNPC(0, 2, 10, 4, 33, 33);
	//		   Sprite*NPC_2 = Sprite::create("6.png");
	//		   NPC_2->setPosition(this->positionForTileCoord(Point(10, 4)));
	//		   this->m_map->addChild(NPC_2);

	//		   this->setNPC(1, 3, 13, 4, 34, 34);
	//		   Sprite*NPC_3 = Sprite::create("3.png");
	//		   NPC_3->setPosition(this->positionForTileCoord(Point(13, 4)));
	//		   this->m_map->addChild(NPC_3);
	//		   break;
	//}
	//case 2:{
	//		   this->setNPC(0, 4, 3, 13, 35, 35);
	//		   Sprite*NPC_4 = Sprite::create("6.png");
	//		   NPC_4->setPosition(this->positionForTileCoord(Point(3, 13)));
	//		   this->m_map->addChild(NPC_4);

	//		   this->setNPC(1, 5, 3, 11, 36, 36);
	//		   Sprite*NPC_5 = Sprite::create("3.png");
	//		   NPC_5->setPosition(this->positionForTileCoord(Point(3, 11)));
	//		   this->m_map->addChild(NPC_5);
	//		   break;
	//}
	//case 3:{
	//		   this->setNPC(0, 6, 31, 17, 45, 45);
	//		   Sprite*NPC_6 = Sprite::create("s.png");
	//		   NPC_6->setPosition(this->positionForTileCoord(Point(31, 17)));
	//		   this->m_map->addChild(NPC_6);

	//		   this->setNPC(1, 7, 6, 30, 46, 46);
	//		   Sprite*NPC_7 = Sprite::create("s.png");
	//		   NPC_7->setPosition(this->positionForTileCoord(Point(6, 30)));
	//		   this->m_map->addChild(NPC_7);

	//		   this->setNPC(2, 8, 28, 30, 47, 47);
	//		   Sprite*NPC_8 = Sprite::create("s.png");
	//		   NPC_8->setPosition(this->positionForTileCoord(Point(28, 30)));
	//		   this->m_map->addChild(NPC_8);

	//		   this->setNPC(3, 9, 41, 17, 54, 54);
	//		   Sprite*NPC_9 = Sprite::create("5.png");
	//		   NPC_9->setPosition(this->positionForTileCoord(Point(41, 17)));
	//		   this->m_map->addChild(NPC_9);
	//		   break;
	//}
	//case 4:{
	//		   this->setNPC(0, 10, 19, 1, 50, 51);
	//		   Sprite*NPC_10 = Sprite::create("s.png");
	//		   NPC_10->setPosition(this->positionForTileCoord(Point(19, 1)));
	//		   this->m_map->addChild(NPC_10);

	//		   this->setNPC(1, 11, 16, 19, 48, 48);
	//		   Sprite*NPC_11 = Sprite::create("s.png");
	//		   NPC_11->setPosition(this->positionForTileCoord(Point(16, 19)));
	//		   this->m_map->addChild(NPC_11);

	//		   this->setNPC(2, 12, 31, 13, 49, 49);
	//		   Sprite*NPC_12 = Sprite::create("s.png");
	//		   NPC_12->setPosition(this->positionForTileCoord(Point(31, 13)));
	//		   this->m_map->addChild(NPC_12);

	//		   this->setNPC(3, 13, 14, 11, 57, 57);
	//		   Sprite*NPC_13 = Sprite::create("2.png");
	//		   NPC_13->setPosition(this->positionForTileCoord(Point(14, 11)));
	//		   this->m_map->addChild(NPC_13);

	//		   break;

	//}
	//case 5:{

	//		   this->setNPC(0, 14, 70, 11, 58, 63);
	//		   Sprite*NPC_14 = Sprite::create("3.png");
	//		   NPC_14->setPosition(this->positionForTileCoord(Point(70, 11)));
	//		   this->m_map->addChild(NPC_14);

	//		   this->setNPC(1, 15, 48, 68, 500, 500);
	//		   Sprite*NPC_15 = Sprite::create("5.png");
	//		   NPC_15->setPosition(this->positionForTileCoord(Point(48, 68)));
	//		   this->m_map->addChild(NPC_15);

	//		   this->setNPC(2, 16, 49, 68, 501, 501);
	//		   Sprite*NPC_16 = Sprite::create("3.png");
	//		   NPC_16->setPosition(this->positionForTileCoord(Point(49, 68)));
	//		   this->m_map->addChild(NPC_16);

	//		   break;

	//}

	//case 6:{

	//		   this->setNPC(0, 17, 7, 4, 64, 64);
	//		   Sprite*NPC_17 = Sprite::create("3.png");
	//		   NPC_17->setPosition(this->positionForTileCoord(Point(7, 4)));
	//		   this->m_map->addChild(NPC_17);

	//		   this->setNPC(1, 18, 5, 4, 65, 69);
	//		   Sprite*NPC_18 = Sprite::create("c.png");
	//		   NPC_18->setPosition(this->positionForTileCoord(Point(5, 4)));
	//		   this->m_map->addChild(NPC_18);

	//		   break;
	//}

	//case 7:{
	//	this->setNPC(0, 19, 5, 4, 102, 103);
	//	Sprite* NPC_19 = Sprite::create("c.png");
	//	NPC_19->setPosition(this->positionForTileCoord(Point(5, 4)));
	//	this->m_map->addChild(NPC_19);
	//	break;
	//}
	//case 8:{
	//	this->setNPC(0, 20, 28, 32, 106, 107);
	//	Sprite* NPC_20 = Sprite::create("2.png");
	//	NPC_20->setPosition(this->positionForTileCoord(Point(28, 32)));
	//	this->m_map->addChild(NPC_20);
	//	break;
	//}
	//case 9:{
	//	this->setNPC(0, 21, 8, 21, 108, 109);
	//	Sprite* NPC_21 = Sprite::create("4.png");
	//	NPC_21->setPosition(this->positionForTileCoord(Point(8, 21)));
	//	this->m_map->addChild(NPC_21);
	//	break;
	//}
	//case 10:{
	//	this->setNPC(0, 22, 8, 21, 110, 110);
	//	Sprite* NPC_22 = Sprite::create("4.png");
	//	NPC_22->setPosition(this->positionForTileCoord(Point(8, 21)));
	//	this->m_map->addChild(NPC_22);

	//	break;
	//}
	//case 36:{

	//	this->setNPC(0, 23, 19, 4, 137, 138);
	//	Sprite* NPC_23 = Sprite::create("2.png");
	//	NPC_23->setPosition(this->positionForTileCoord(Point(19, 4)));
	//	this->m_map->addChild(NPC_23);

	//	break;
	//}

	//case 11:{
	//	this->setNPC(0, 24, 16, 9, 113, 114);
	//	Sprite* NPC_24 = Sprite::create("5.png");
	//	NPC_24->setPosition(this->positionForTileCoord(Point(16, 9)));
	//	this->m_map->addChild(NPC_24);

	//	break;
	//}
	//case 12:{
	//	this->setNPC(0, 25, 16, 9, 115, 116);
	//	Sprite* NPC_25 = Sprite::create("5.png");
	//	NPC_25->setPosition(this->positionForTileCoord(Point(16, 9)));
	//	this->m_map->addChild(NPC_25);
	//	break;
	//}
	//case 37: {
	//	break;
	//}
	//case 38: {
	//	break;
	//}
	//case 39: {
	//	break;
	//}
	//case 40: {
	//	break;
	//}
	//case41: {
	//	break;
	//}
	//case 42: {
	//	break;
	//}
	//case 43: {
	//	break;
	//}
	//case 44: {
	//	break;
	//}
	//case 45: {

	//	break;
	//}
	//case 46: {
	//	this->setNPC(0, 61, 7, 13, 129, 129);
	//	Sprite* NPC_61 = Sprite::create("2.png");
	//	NPC_61->setPosition(this->positionForTileCoord(Point(7, 13)));
	//	this->m_map->addChild(NPC_61);
	//	break;

	//}
	//case 13:{
	//	this->setNPC(0, 26, 12, 3, 1000, 1001);
	//	Sprite* NPC_26 = Sprite::create("b.png");
	//	NPC_26->setPosition(this->positionForTileCoord(Point(12, 3)));
	//	this->m_map->addChild(NPC_26);
	//	break;
	//}
	//case 14:{
	//	this->setNPC(0, 27, 17, 9, 117, 117);
	//	Sprite* NPC_27 = Sprite::create("5.png");
	//	NPC_27->setPosition(this->positionForTileCoord(Point(17, 9)));
	//	this->m_map->addChild(NPC_27);
	//	break;
	//}
	//case 15:{
	//	this->setNPC(0, 28, 7, 4, 119, 119);
	//	Sprite* NPC_28 = Sprite::create("6.png");
	//	NPC_28->setPosition(this->positionForTileCoord(Point(7, 4)));
	//	this->m_map->addChild(NPC_28);


	//	this->setNPC(1, 29, 7, 9, 120, 120);
	//	Sprite* NPC_29 = Sprite::create("c.png");//��ϻ��
	//	NPC_29->setPosition(this->positionForTileCoord(Point(7, 9)));
	//	this->m_map->addChild(NPC_29);

	//	break;
	//}
	//case 16:{
	//	this->setNPC(0, 30, 8, 21, 121, 121);
	//	Sprite* NPC_30 = Sprite::create("4.png");
	//	NPC_30->setPosition(this->positionForTileCoord(Point(8, 21)));
	//	this->m_map->addChild(NPC_30);
	//	break;
	//}
	//case 17:{
	//	this->setNPC(0, 31, 4, 22, 139, 140);
	//	Sprite* NPC_31 = Sprite::create("7.png");
	//	NPC_31->setPosition(this->positionForTileCoord(Point(4, 22)));
	//	this->m_map->addChild(NPC_31);
	//	break;
	//}
	//case 18:{
	//	this->setNPC(0, 32, 8, 5, 503, 503);
	//	Sprite* NPC_32 = Sprite::create("c.png");//ѧ�Աʼ�
	//	NPC_32->setPosition(this->positionForTileCoord(Point(8, 5)));
	//	this->m_map->addChild(NPC_32);
	//	break;
	//}
	//case 19:{
	//			//6����ֵ�����ҷֱ�Ϊ��npc�ڵ�ͼ�еı�ţ�0~9���⣬�������ظ�����npc���ܱ��,�������꣨��tmx��ͼ�в��ң����Ի��Ŀ�ʼkeyֵ�ͽ���keyֵ
	//			//�м���npc��ͬ�ĵ�ͼд����case
	//			//��Ҫ����break
	//			this->setNPC(0, 33, 14, 13, 504, 504);
	//			Sprite* NPC_33 = Sprite::create("2.png");
	//			NPC_33->setPosition(this->positionForTileCoord(Point(14, 13)));
	//			this->m_map->addChild(NPC_33);

	//			//�ж�ȡ���ĸ�NPC��KEYֵ�������Ի���
	//			break;
	//}
	//case 20:{

	//			this->setNPC(0, 34, 7, 13, 129, 129);
	//			Sprite* NPC_34 = Sprite::create("2.png");
	//			NPC_34->setPosition(this->positionForTileCoord(Point(7, 13)));
	//			this->m_map->addChild(NPC_34);

	//			this->setNPC(1, 35, 7, 13, 129, 129);
	//			Sprite* NPC_35 = Sprite::create("2.png");
	//			NPC_35->setPosition(this->positionForTileCoord(Point(7, 13)));
	//			this->m_map->addChild(NPC_35);

	//			break;
	//}
	//case 21:{

	//			this->setNPC(0, 36, 7, 13, 124, 125);
	//			Sprite* NPC_36 = Sprite::create("3.png");
	//			NPC_36->setPosition(this->positionForTileCoord(Point(7, 13)));
	//			this->m_map->addChild(NPC_36);


	//			break;
	//}
	//case 47:{
	//			this->setNPC(0, 37, 7, 13, 129, 129);
	//			Sprite* NPC_37 = Sprite::create("2.png");
	//			NPC_37->setPosition(this->positionForTileCoord(Point(7, 13)));
	//			this->m_map->addChild(NPC_37);
	//			break;
	//}
	//case 22:{
	//			this->setNPC(0, 38, 26, 17, 126, 127);
	//			Sprite* NPC_38 = Sprite::create("2.png");
	//			NPC_38->setPosition(this->positionForTileCoord(Point(26, 17)));
	//			this->m_map->addChild(NPC_38);


	//			break;
	//}
	//case 48:{

	//			this->setNPC(0, 39, 26, 17, 127, 128);
	//			Sprite* NPC_39 = Sprite::create("2.png");
	//			NPC_39->setPosition(this->positionForTileCoord(Point(26, 17)));
	//			this->m_map->addChild(NPC_39);
	//			break;
	//}
	//case 23:{

	//			this->setNPC(0, 40, 5, 4, 131, 136);
	//			Sprite* NPC_40 = Sprite::create("c.png");//��
	//			NPC_40->setPosition(this->positionForTileCoord(Point(5, 4)));
	//			this->m_map->addChild(NPC_40);


	//			break;
	//}
	//case 49:{
	//			this->setNPC(0, 41, 5, 4, 144, 149);
	//			Sprite* NPC_41 = Sprite::create("c.png");//��
	//			NPC_41->setPosition(this->positionForTileCoord(Point(5, 4)));
	//			this->m_map->addChild(NPC_41);
	//			break;
	//}
	//case 24:{

	//			this->setNPC(0, 42, 5, 4, 201, 202);
	//			Sprite* NPC_42 = Sprite::create("c.png");//��
	//			NPC_42->setPosition(this->positionForTileCoord(Point(5, 4)));
	//			this->m_map->addChild(NPC_42);
	//			break;
	//}
	//case 25:{

	//			this->setNPC(0, 43, 7, 19, 204, 204);
	//			Sprite* NPC_43 = Sprite::create("3.png");
	//			NPC_43->setPosition(this->positionForTileCoord(Point(7, 19)));
	//			this->m_map->addChild(NPC_43);

	//			this->setNPC(1, 44, 4, 11, 206, 207);
	//			Sprite* NPC_44 = Sprite::create("11.png");
	//			NPC_44->setPosition(this->positionForTileCoord(Point(4, 11)));
	//			this->m_map->addChild(NPC_44);
	//			break;
	//}
	//case 26:{

	//			this->setNPC(0, 45, 11, 12, 214, 214);
	//			Sprite* NPC_45 = Sprite::create("s.png");//������
	//			NPC_45->setPosition(this->positionForTileCoord(Point(11, 12)));
	//			this->m_map->addChild(NPC_45);
	//			break;
	//}
	//case 27:{

	//			this->setNPC(0, 46, 10, 4, 213, 213);
	//			Sprite* NPC_46 = Sprite::create("6.png");
	//			NPC_46->setPosition(this->positionForTileCoord(Point(10, 4)));
	//			this->m_map->addChild(NPC_46);
	//			break;
	//}
	//case 28:{

	//			this->setNPC(0, 47, 12, 29, 218, 218);
	//			Sprite* NPC_47 = Sprite::create("6.png");
	//			NPC_47->setPosition(this->positionForTileCoord(Point(12, 29)));
	//			this->m_map->addChild(NPC_47);
	//			break;
	//}
	//case 29:{

	//			this->setNPC(0, 48, 4, 11, 219, 219);
	//			Sprite* NPC_48 = Sprite::create("11.png");
	//			NPC_48->setPosition(this->positionForTileCoord(Point(4, 11)));
	//			this->m_map->addChild(NPC_48);

	//			this->setNPC(1, 49, 2, 9, 220, 221);
	//			Sprite* NPC_49 = Sprite::create("11.png");
	//			NPC_49->setPosition(this->positionForTileCoord(Point(2, 9)));
	//			this->m_map->addChild(NPC_49);

	//			this->setNPC(2, 50, 13, 11, 223, 224);
	//			Sprite* NPC_50 = Sprite::create("2.png");
	//			NPC_50->setPosition(this->positionForTileCoord(Point(13, 11)));
	//			this->m_map->addChild(NPC_50);
	//			break;
	//}
	//case 30:{

	//			this->setNPC(0, 51, 44, 70, 232, 233);
	//			Sprite* NPC_51 = Sprite::create("s.png");//������
	//			NPC_51->setPosition(this->positionForTileCoord(Point(44, 70)));
	//			this->m_map->addChild(NPC_51);
	//			break;
	//}
	//case 31:{
	//			this->setNPC(0, 52, 2, 9, 203, 203);
	//			Sprite* NPC_52 = Sprite::create("11.png");
	//			NPC_52->setPosition(this->positionForTileCoord(Point(2, 9)));
	//			this->m_map->addChild(NPC_52);


	//			break;
	//}
	//case 50:{
	//			this->setNPC(0, 53, 2, 9, 235, 237);
	//			Sprite* NPC_53 = Sprite::create("11.png");
	//			NPC_53->setPosition(this->positionForTileCoord(Point(2, 9)));
	//			this->m_map->addChild(NPC_53);
	//			break;
	//}
	//case 32:{

	//			this->setNPC(0, 54, 15, 13, 238, 238);
	//			Sprite* NPC_54 = Sprite::create("3.png");
	//			NPC_54->setPosition(this->positionForTileCoord(Point(15, 13)));
	//			this->m_map->addChild(NPC_54);
	//			break;
	//}
	//case 51:{
	//			this->setNPC(0, 62, 15, 13, 238, 238);
	//			Sprite* NPC_62 = Sprite::create("3.png");
	//			NPC_62->setPosition(this->positionForTileCoord(Point(15, 13)));
	//			this->m_map->addChild(NPC_62);
	//			break;
	//}
	//case 33:{

	//			this->setNPC(0, 55, 5, 4, 245, 249);
	//			Sprite* NPC_55 = Sprite::create("c.png");//��
	//			NPC_55->setPosition(this->positionForTileCoord(Point(5, 4)));
	//			this->m_map->addChild(NPC_55);


	//			break;
	//}
	//case 52:{
	//			this->setNPC(0, 56, 5, 4, 242, 244);
	//			Sprite* NPC_56 = Sprite::create("c.png");//��
	//			NPC_56->setPosition(this->positionForTileCoord(Point(5, 4)));
	//			this->m_map->addChild(NPC_56);
	//			break;
	//}
	//case 34:{

	//			this->setNPC(0, 57, 5, 4, 301, 306);
	//			Sprite* NPC_57 = Sprite::create("c.png");//��
	//			NPC_57->setPosition(this->positionForTileCoord(Point(5, 4)));
	//			this->m_map->addChild(NPC_57);
	//			break;
	//}
	//case 35:{
	//			this->setNPC(0, 58, 8, 14, 309, 309);
	//			Sprite* NPC_58 = Sprite::create("s.png");//������
	//			NPC_58->setPosition(this->positionForTileCoord(Point(8, 14)));
	//			this->m_map->addChild(NPC_58);



	//			break;
	//}
	//case 53:{
	//			this->setNPC(0, 59, 8, 14, 309, 309);
	//			Sprite* NPC_59 = Sprite::create("s.png");//������
	//			NPC_59->setPosition(this->positionForTileCoord(Point(8, 14)));
	//			this->m_map->addChild(NPC_59);

	//			break;
	//}
	//case 54:{
	//			this->setNPC(0, 60, 8, 14, 309, 309);
	//			Sprite* NPC_60 = Sprite::create("s.png");//������
	//			NPC_60->setPosition(this->positionForTileCoord(Point(8, 14)));
	//			this->m_map->addChild(NPC_60);
	//			break;
	//}
	//}
switch (sGlobal->caseNum)  {
case 0:{
		   this->setNPC(0, 0, 1, 4, 29, 29);
		   Sprite*NPC_0 = Sprite::create("6.png");
		   NPC_0->setPosition(this->positionForTileCoord(Point(1, 4)));
		   this->m_map->addChild(NPC_0);

		   this->setNPC(1, 1, 4, 3, 30, 30);
		   Sprite*NPC_1 = Sprite::create("2.png");
		   NPC_1->setPosition(this->positionForTileCoord(Point(4, 3)));
		   this->m_map->addChild(NPC_1);
		   break;
}
case 1:{
		   this->setNPC(0, 2, 10, 4, 33, 33);
		   Sprite*NPC_2 = Sprite::create("6.png");
		   NPC_2->setPosition(this->positionForTileCoord(Point(10, 4)));
		   this->m_map->addChild(NPC_2);

		   this->setNPC(1, 3, 13, 4, 34, 34);
		   Sprite*NPC_3 = Sprite::create("3.png");
		   NPC_3->setPosition(this->positionForTileCoord(Point(13, 4)));
		   this->m_map->addChild(NPC_3);
		   break;
}
case 2:{
		   this->setNPC(0, 4, 3, 13, 35, 35);
		   Sprite*NPC_4 = Sprite::create("6.png");
		   NPC_4->setPosition(this->positionForTileCoord(Point(3, 13)));
		   this->m_map->addChild(NPC_4);

		   this->setNPC(1, 5, 3, 11, 36, 36);
		   Sprite*NPC_5 = Sprite::create("3.png");
		   NPC_5->setPosition(this->positionForTileCoord(Point(3, 11)));
		   this->m_map->addChild(NPC_5);
		   break;
}
case 3:{
		   this->setNPC(0, 6, 31, 17, 45, 45);
		   Sprite*NPC_6 = Sprite::create("s.png");
		   NPC_6->setPosition(this->positionForTileCoord(Point(31, 17)));
		   this->m_map->addChild(NPC_6);

		   this->setNPC(1, 7, 6, 30, 46, 46);
		   Sprite*NPC_7 = Sprite::create("s.png");
		   NPC_7->setPosition(this->positionForTileCoord(Point(6, 30)));
		   this->m_map->addChild(NPC_7);

		   this->setNPC(2, 8, 28, 30, 47, 47);
		   Sprite*NPC_8 = Sprite::create("s.png");
		   NPC_8->setPosition(this->positionForTileCoord(Point(28, 30)));
		   this->m_map->addChild(NPC_8);

		   this->setNPC(3, 9, 41, 17, 54, 54);
		   Sprite*NPC_9 = Sprite::create("5.png");
		   NPC_9->setPosition(this->positionForTileCoord(Point(41, 17)));
		   this->m_map->addChild(NPC_9);
		   break;
}
case 4:{
		   this->setNPC(0, 10, 19, 1, 50, 51);
		   Sprite*NPC_10 = Sprite::create("s.png");
		   NPC_10->setPosition(this->positionForTileCoord(Point(19, 1)));
		   this->m_map->addChild(NPC_10);

		   this->setNPC(1, 11, 16, 19, 48, 48);
		   Sprite*NPC_11 = Sprite::create("s.png");
		   NPC_11->setPosition(this->positionForTileCoord(Point(16, 19)));
		   this->m_map->addChild(NPC_11);

		   this->setNPC(2, 12, 31, 13, 49, 49);
		   Sprite*NPC_12 = Sprite::create("s.png");
		   NPC_12->setPosition(this->positionForTileCoord(Point(31, 13)));
		   this->m_map->addChild(NPC_12);

		   this->setNPC(3, 13, 14, 11, 57, 57);
		   Sprite*NPC_13 = Sprite::create("2.png");
		   NPC_13->setPosition(this->positionForTileCoord(Point(14, 11)));
		   this->m_map->addChild(NPC_13);

		   break;

}
case 5:{

		   this->setNPC(0, 14, 70, 11, 58, 63);
		   Sprite*NPC_14 = Sprite::create("3.png");
		   NPC_14->setPosition(this->positionForTileCoord(Point(70, 11)));
		   this->m_map->addChild(NPC_14);

		   this->setNPC(1, 15, 48, 68, 500, 500);
		   Sprite*NPC_15 = Sprite::create("5.png");
		   NPC_15->setPosition(this->positionForTileCoord(Point(48, 68)));
		   this->m_map->addChild(NPC_15);

		   this->setNPC(2, 16, 49, 68, 501, 501);
		   Sprite*NPC_16 = Sprite::create("3.png");
		   NPC_16->setPosition(this->positionForTileCoord(Point(49, 68)));
		   this->m_map->addChild(NPC_16);

		   break;

}

case 6:{

		   this->setNPC(0, 17, 7, 4, 64, 64);
		   Sprite*NPC_17 = Sprite::create("3.png");
		   NPC_17->setPosition(this->positionForTileCoord(Point(7, 4)));
		   this->m_map->addChild(NPC_17);

		   this->setNPC(1, 18, 5, 4, 65, 69);
		   Sprite*NPC_18 = Sprite::create("c.png");
		   NPC_18->setPosition(this->positionForTileCoord(Point(5, 4)));
		   this->m_map->addChild(NPC_18);

		   break;
}

case 7:{
		   this->setNPC(0, 19, 5, 4, 102, 104);
		   Sprite* NPC_19 = Sprite::create("c.png");
		   NPC_19->setPosition(this->positionForTileCoord(Point(5, 4)));
		   this->m_map->addChild(NPC_19);
		   break;
}
case 8:{
		   this->setNPC(0, 20, 28, 32, 106, 107);
		   Sprite* NPC_20 = Sprite::create("2.png");
		   NPC_20->setPosition(this->positionForTileCoord(Point(28, 32)));
		   this->m_map->addChild(NPC_20);
		   break;
}
case 9:{
		   this->setNPC(0, 21, 8, 21, 108, 109);
		   Sprite* NPC_21 = Sprite::create("4.png");
		   NPC_21->setPosition(this->positionForTileCoord(Point(8, 21)));
		   this->m_map->addChild(NPC_21);
		   break;
}
case 10:{
			this->setNPC(0, 22, 8, 21, 110, 110);
			Sprite* NPC_22 = Sprite::create("4.png");
			NPC_22->setPosition(this->positionForTileCoord(Point(8, 21)));
			this->m_map->addChild(NPC_22);

			break;
}
case 36:{

			this->setNPC(0, 23, 19, 4, 137, 138);
			Sprite* NPC_23 = Sprite::create("2.png");
			NPC_23->setPosition(this->positionForTileCoord(Point(19, 4)));
			this->m_map->addChild(NPC_23);

			break;
}

case 11:{
			this->setNPC(0, 24, 16, 9, 113, 114);
			Sprite* NPC_24 = Sprite::create("5.png");
			NPC_24->setPosition(this->positionForTileCoord(Point(16, 9)));
			this->m_map->addChild(NPC_24);

			break;
}
case 12:{
			this->setNPC(0, 25, 16, 9, 115, 116);
			Sprite* NPC_25 = Sprite::create("5.png");
			NPC_25->setPosition(this->positionForTileCoord(Point(16, 9)));
			this->m_map->addChild(NPC_25);
			break;
}
case 37: {
			 break;
}
case 38: {
			 break;
}
case 39: {
			 break;
}
case 40: {
			 break;
}
case 41: {
			 break;
}
case 42: {
			 break;
}
case 43: {
			 break;
}
case 44: {
			 break;
}
case 55: {
			 break;
}case 56: {
			 break;
}case 57: {
	break;
}case 58: {
	break;
}case 59: {
	break;
}case 60: {
	break;
}case 61: {
	break;
}case 62: {
	break;
}case 63: {
	break;
}case 64: {
	break;
}
case 45: {
			 this->setNPC(0, 63, 14, 13, 504, 504);
			 Sprite* NPC_63 = Sprite::create("7.png");
			 NPC_63->setPosition(this->positionForTileCoord(Point(14, 13)));
			 this->m_map->addChild(NPC_63);
			 break;
}
case 46: {
			 this->setNPC(0, 61, 7, 13, 129, 129);
			 Sprite* NPC_61 = Sprite::create("2.png");
			 NPC_61->setPosition(this->positionForTileCoord(Point(7, 13)));
			 this->m_map->addChild(NPC_61);
			 break;

}
case 13:{
			this->setNPC(0, 26, 12, 3, 1000, 1001);
			Sprite* NPC_26 = Sprite::create("b.png");
			NPC_26->setPosition(this->positionForTileCoord(Point(12, 3)));
			this->m_map->addChild(NPC_26);
			break;
}
case 14:{
			this->setNPC(0, 27, 17, 9, 117, 117);
			Sprite* NPC_27 = Sprite::create("5.png");
			NPC_27->setPosition(this->positionForTileCoord(Point(17, 9)));
			this->m_map->addChild(NPC_27);
			break;
}
case 15:{
			this->setNPC(0, 28, 7, 4, 119, 119);
			Sprite* NPC_28 = Sprite::create("6.png");
			NPC_28->setPosition(this->positionForTileCoord(Point(7, 4)));
			this->m_map->addChild(NPC_28);


			this->setNPC(1, 29, 7, 9, 120, 120);
			Sprite* NPC_29 = Sprite::create("box.png");//��ϻ��
			NPC_29->setPosition(this->positionForTileCoord(Point(7, 9)));
			this->m_map->addChild(NPC_29);

			break;
}
case 16:{
			this->setNPC(0, 30, 8, 21, 121, 121);
			Sprite* NPC_30 = Sprite::create("4.png");
			NPC_30->setPosition(this->positionForTileCoord(Point(8, 21)));
			this->m_map->addChild(NPC_30);
			break;
}
case 17:{
			this->setNPC(0, 31, 4, 22, 139, 140);
			Sprite* NPC_31 = Sprite::create("7.png");
			NPC_31->setPosition(this->positionForTileCoord(Point(4, 22)));
			this->m_map->addChild(NPC_31);
			break;
}
case 18:{
			this->setNPC(0, 32, 8, 5, 503, 503);
			Sprite* NPC_32 = Sprite::create("note.png");//ѧ�Աʼ�
			NPC_32->setPosition(this->positionForTileCoord(Point(8, 5)));
			this->m_map->addChild(NPC_32);
			break;
}
case 19:{
			//6����ֵ�����ҷֱ�Ϊ��npc�ڵ�ͼ�еı�ţ�0~9���⣬�������ظ�����npc���ܱ��,�������꣨��tmx��ͼ�в��ң����Ի��Ŀ�ʼkeyֵ�ͽ���keyֵ
			//�м���npc��ͬ�ĵ�ͼд����case
			//��Ҫ����break
			this->setNPC(0, 33, 14, 13, 504, 504);
			Sprite* NPC_33 = Sprite::create("2.png");
			NPC_33->setPosition(this->positionForTileCoord(Point(14, 13)));
			this->m_map->addChild(NPC_33);

			//�ж�ȡ���ĸ�NPC��KEYֵ�������Ի���
			break;
}
case 20:{
			this->setNPC(0, 35, 7, 13, 129, 129);
			Sprite* NPC_35 = Sprite::create("2.png");
			NPC_35->setPosition(this->positionForTileCoord(Point(7, 13)));
			this->m_map->addChild(NPC_35);

			break;
}
case 21:{

			this->setNPC(0, 36, 7, 13, 123, 125);
			Sprite* NPC_36 = Sprite::create("3.png");
			NPC_36->setPosition(this->positionForTileCoord(Point(7, 13)));
			this->m_map->addChild(NPC_36);


			break;
}
case 47:{
			this->setNPC(0, 37, 7, 13, 129, 129);
			Sprite* NPC_37 = Sprite::create("2.png");
			NPC_37->setPosition(this->positionForTileCoord(Point(7, 13)));
			this->m_map->addChild(NPC_37);
			break;
}
case 22:{
			this->setNPC(0, 38, 26, 17, 126, 127);
			Sprite* NPC_38 = Sprite::create("2.png");
			NPC_38->setPosition(this->positionForTileCoord(Point(26, 17)));
			this->m_map->addChild(NPC_38);


			break;
}
case 48:{

			this->setNPC(0, 39, 26, 17, 127, 128);
			Sprite* NPC_39 = Sprite::create("2.png");
			NPC_39->setPosition(this->positionForTileCoord(Point(26, 17)));
			this->m_map->addChild(NPC_39);
			break;
}
case 23:{

			this->setNPC(0, 40, 5, 4, 131, 136);
			Sprite* NPC_40 = Sprite::create("c.png");//��
			NPC_40->setPosition(this->positionForTileCoord(Point(5, 4)));
			this->m_map->addChild(NPC_40);


			break;
}
case 49:{
			this->setNPC(0, 41, 5, 4, 144, 149);
			Sprite* NPC_41 = Sprite::create("c.png");//��
			NPC_41->setPosition(this->positionForTileCoord(Point(5, 4)));
			this->m_map->addChild(NPC_41);
			break;
}
case 24:{

			this->setNPC(0, 42, 5, 4, 201, 202);
			Sprite* NPC_42 = Sprite::create("c.png");//��
			NPC_42->setPosition(this->positionForTileCoord(Point(5, 4)));
			this->m_map->addChild(NPC_42);
			break;
}
case 25:{

			this->setNPC(0, 43, 7, 19, 204, 204);
			Sprite* NPC_43 = Sprite::create("3.png");
			NPC_43->setPosition(this->positionForTileCoord(Point(7, 19)));
			this->m_map->addChild(NPC_43);

			this->setNPC(1, 44, 4, 11, 206, 207);
			Sprite* NPC_44 = Sprite::create("11.png");
			NPC_44->setPosition(this->positionForTileCoord(Point(4, 11)));
			this->m_map->addChild(NPC_44);
			break;
}
case 26:{

			this->setNPC(0, 45, 11, 12, 214, 214);
			Sprite* NPC_45 = Sprite::create("s.png");//������
			NPC_45->setPosition(this->positionForTileCoord(Point(11, 12)));
			this->m_map->addChild(NPC_45);
			break;
}
case 27:{

			this->setNPC(0, 46, 10, 4, 213, 213);
			Sprite* NPC_46 = Sprite::create("6.png");
			NPC_46->setPosition(this->positionForTileCoord(Point(10, 4)));
			this->m_map->addChild(NPC_46);
			break;
}
case 28:{

			this->setNPC(0, 47, 12, 29, 218, 218);
			Sprite* NPC_47 = Sprite::create("6.png");
			NPC_47->setPosition(this->positionForTileCoord(Point(12, 29)));
			this->m_map->addChild(NPC_47);
			break;
}
case 29:{

			this->setNPC(0, 48, 4, 11, 219, 219);
			Sprite* NPC_48 = Sprite::create("11.png");
			NPC_48->setPosition(this->positionForTileCoord(Point(4, 11)));
			this->m_map->addChild(NPC_48);

			this->setNPC(1, 49, 2, 9, 220, 221);
			Sprite* NPC_49 = Sprite::create("11.png");
			NPC_49->setPosition(this->positionForTileCoord(Point(2, 9)));
			this->m_map->addChild(NPC_49);

			this->setNPC(2, 50, 13, 11, 223, 224);
			Sprite* NPC_50 = Sprite::create("2.png");
			NPC_50->setPosition(this->positionForTileCoord(Point(13, 11)));
			this->m_map->addChild(NPC_50);
			break;
}
case 30:{

			this->setNPC(0, 51, 44, 70, 232, 233);
			Sprite* NPC_51 = Sprite::create("s.png");//������
			NPC_51->setPosition(this->positionForTileCoord(Point(44, 70)));
			this->m_map->addChild(NPC_51);
			break;
}
case 31:{
			this->setNPC(0, 52, 2, 9, 203, 203);
			Sprite* NPC_52 = Sprite::create("11.png");
			NPC_52->setPosition(this->positionForTileCoord(Point(2, 9)));
			this->m_map->addChild(NPC_52);


			break;
}
case 50:{
			this->setNPC(0, 53, 2, 9, 235, 237);
			Sprite* NPC_53 = Sprite::create("11.png");
			NPC_53->setPosition(this->positionForTileCoord(Point(2, 9)));
			this->m_map->addChild(NPC_53);
			break;
}
case 32:{

			this->setNPC(0, 54, 15, 13, 238, 238);
			Sprite* NPC_54 = Sprite::create("3.png");
			NPC_54->setPosition(this->positionForTileCoord(Point(15, 13)));
			this->m_map->addChild(NPC_54);
			break;
}
case 51:{
			this->setNPC(0, 62, 15, 13, 238, 238);
			Sprite* NPC_62 = Sprite::create("3.png");
			NPC_62->setPosition(this->positionForTileCoord(Point(15, 13)));
			this->m_map->addChild(NPC_62);
			break;
}
case 33:{

			this->setNPC(0, 55, 5, 4, 245, 249);
			Sprite* NPC_55 = Sprite::create("c.png");//��
			NPC_55->setPosition(this->positionForTileCoord(Point(5, 4)));
			this->m_map->addChild(NPC_55);


			break;
}
case 52:{
			this->setNPC(0, 56, 5, 4, 242, 244);
			Sprite* NPC_56 = Sprite::create("c.png");//��
			NPC_56->setPosition(this->positionForTileCoord(Point(5, 4)));
			this->m_map->addChild(NPC_56);
			break;
}
case 34:{

			this->setNPC(0, 57, 5, 4, 301, 306);
			Sprite* NPC_57 = Sprite::create("c.png");//��
			NPC_57->setPosition(this->positionForTileCoord(Point(5, 4)));
			this->m_map->addChild(NPC_57);
			break;
}
case 35:{
			this->setNPC(0, 58, 8, 14, 309, 309);
			Sprite* NPC_58 = Sprite::create("s.png");//������
			NPC_58->setPosition(this->positionForTileCoord(Point(8, 14)));
			this->m_map->addChild(NPC_58);



			break;
}
case 53:{
			this->setNPC(0, 59, 8, 14, 309, 309);
			Sprite* NPC_59 = Sprite::create("s.png");//������
			NPC_59->setPosition(this->positionForTileCoord(Point(8, 14)));
			this->m_map->addChild(NPC_59);

			break;
}
case 54:{
			this->setNPC(0, 60, 8, 14, 309, 309);
			Sprite* NPC_60 = Sprite::create("s.png");//������
			NPC_60->setPosition(this->positionForTileCoord(Point(8, 14)));
			this->m_map->addChild(NPC_60);
			break;
}
}
}

bool MyMap::showDialogBox(Point NPCPosition){
	//��ȡ���ڴ�С
	Size visibleSize = Director::getInstance()->getVisibleSize();
	sGlobal->visibleSize = visibleSize;

	int i = 0;
	for (i=0; i <= 9; i++){
		if (NPCPosition == this->npc[i].NPCPosition){
			//����npc����ʾ�Ի���
			sGlobal->hero->speekOrNot = 1;
			Sprite*backGround = Sprite::create("TalkBackGround.png");
			backGround->setAnchorPoint(Point(0, 0));
			backGround->setPosition(Point(0, 0));
			this->addChild(backGround, 3, "backGround");
			backGround->setGlobalZOrder(200);
			this->setNPCPortrait(visibleSize, i);
			this->outDialog(visibleSize, i);
			//�Բ�Ѱ����npc���н���
			/*this->unusualNPC(visibleSize,this->npc[i].NPCNum);*/
			//bool i = sGlobal->hero->plot[mySchedule];
			//bool i2 = sGlobal->hero->plot[6];
			//bool i3 = sGlobal->hero->plot[7];
			break;
		}
	}
	if (i < 9){
		return true;
	}
	else{ return false; }
}

void MyMap::setNPCPortrait(Size visibleSize, int NPCNum){
	//switch (NPCNum){
	//	//����Ϊ������3
	//case 1:
	//case 13:
	//case 20:
	//case 23:
	//case 33:
	//case 34:
	//case 35:
	//case 37:
	//case 38:
	//case 39:
	//case 50:{
	//			Sprite*portrait = Sprite::create("3F.png");
	//			portrait->setAnchorPoint(Point(0, 0));
	//			portrait->setPosition(Point(visibleSize.width*0.1, visibleSize.height*0.15));
	//			this->addChild(portrait,4,"portrait");
	//			portrait->setGlobalZOrder(201);
	//			break;
	//}
	//case 3:
	//case 5:
	//case 14:
	//case 16:
	//case 17:
	//case 36:
	//case 43:
	//case 54:{
	//			Sprite*portrait = Sprite::create("2F.png");
	//			portrait->setAnchorPoint(Point(0, 0));
	//			portrait->setPosition(Point(visibleSize.width*0.1, visibleSize.height*0.15));
	//			this->addChild(portrait, 4, "portrait");
	//			portrait->setGlobalZOrder(201);
	//			break;
	//}
	//case 21:
	//case 22:
	//case 30:{
	//			Sprite*portrait = Sprite::create("3F.png");
	//			portrait->setAnchorPoint(Point(0, 0));
	//			portrait->setPosition(Point(visibleSize.width*0.1, visibleSize.height*0.15));
	//			this->addChild(portrait, 4, "portrait");
	//			portrait->setGlobalZOrder(201);
	//			break;
	//}
	//case 9:
	//case 15:
	//case 24:
	//case 25:
	//case 27:{
	//			Sprite*portrait = Sprite::create("4F.png");
	//			portrait->setAnchorPoint(Point(0, 0));
	//			portrait->setPosition(Point(visibleSize.width*0.1, visibleSize.height*0.15));
	//			this->addChild(portrait, 4, "portrait");
	//			portrait->setGlobalZOrder(201);
	//			break;
	//}
	//case 0:
	//case 2:
	//case 4:
	//case 28:
	//case 46:
	//case 47:{
	//			Sprite*portrait = Sprite::create("5F.png");
	//			portrait->setAnchorPoint(Point(0, 0));
	//			portrait->setPosition(Point(visibleSize.width*0.1, visibleSize.height*0.15));
	//			this->addChild(portrait, 4, "portrait");
	//			portrait->setGlobalZOrder(201);
	//			break;
	//}
	//case 31:{
	//			Sprite*portrait = Sprite::create("6F.png");
	//			portrait->setAnchorPoint(Point(0, 0));
	//			portrait->setPosition(Point(visibleSize.width*0.1, visibleSize.height*0.15));
	//			this->addChild(portrait, 4, "portrait");
	//			portrait->setGlobalZOrder(201);
	//			break;
	//}
	//case 44:
	//case 48:
	//case 49:
	//case 52:
	//case 53:
	//{
	//		   Sprite*portrait = Sprite::create("7F.png");
	//		   portrait->setAnchorPoint(Point(0, 0));
	//		   portrait->setPosition(Point(visibleSize.width*0.1, visibleSize.height*0.15));
	//		   this->addChild(portrait, 4, "portrait");
	//		   portrait->setGlobalZOrder(201);
	//		   break;
	//}
	//case 18:
	//case 19:
	//case 29:
	//case 32:
	//case 40:
	//case 41:
	//case 42:
	//case 55:
	//case 56:
	//case 57:{
	//			Sprite*portrait = Sprite::create("11F.png");
	//			portrait->setAnchorPoint(Point(0, 0));
	//			portrait->setPosition(Point(visibleSize.width*0.1, visibleSize.height*0.15));
	//			this->addChild(portrait, 4, "portrait");
	//			portrait->setGlobalZOrder(201);
	//			break;
	//}
	//case 26:{
	//			Sprite*portrait = Sprite::create("c.png");
	//			portrait->setAnchorPoint(Point(0, 0));
	//			portrait->setPosition(Point(visibleSize.width*0.1, visibleSize.height*0.15));
	//			this->addChild(portrait, 4, "portrait");
	//			portrait->setGlobalZOrder(201);
	//			break;
	//}
	//case 6:
	//case 7:
	//case 8:
	//case 10:
	//case 11:
	//case 12:
	//case 45:
	//case 51:
	//case 58:
	//case 59:
	//case 60:{
	//			Sprite*portrait = Sprite::create("b.png");
	//			portrait->setAnchorPoint(Point(0, 0));
	//			portrait->setPosition(Point(visibleSize.width*0.1, visibleSize.height*0.15));
	//			this->addChild(portrait, 4, "portrait");
	//			portrait->setGlobalZOrder(201);
	//			break;
	//}
	//}
switch (NPCNum){
	//����Ϊ������3
case 1:
case 13:
case 20:
case 23:
case 33:
case 61:
case 35:
case 37:
case 38:
case 39:
case 50:{
			Sprite*portrait = Sprite::create("2F.png");
			portrait->setAnchorPoint(Point(0, 0));
			portrait->setPosition(Point(0,0));
			this->addChild(portrait, 4, "portrait");
			portrait->setGlobalZOrder(201);
			break;
}
case 3:
case 5:
case 14:
case 16:
case 17:
case 36:
case 43:
case 54:
case 62:{
			Sprite*portrait = Sprite::create("3F.png");
			portrait->setAnchorPoint(Point(0, 0));
			portrait->setPosition(Point(0,0));
			this->addChild(portrait, 4, "portrait");
			portrait->setGlobalZOrder(201);
			break;
}
case 21:
case 22:
case 30:{
			Sprite*portrait = Sprite::create("4F.png");
			portrait->setAnchorPoint(Point(0, 0));
			portrait->setPosition(Point(0,0));
			this->addChild(portrait, 4, "portrait");
			portrait->setGlobalZOrder(201);
			break;
}
case 9:
case 15:
case 24:
case 25:
case 27:{
			Sprite*portrait = Sprite::create("5F.png");
			portrait->setAnchorPoint(Point(0, 0));
			portrait->setPosition(Point(0,0));
			this->addChild(portrait, 4, "portrait");
			portrait->setGlobalZOrder(201);
			break;
}
case 0:
case 2:
case 4:
case 28:
case 29:
case 46:
case 47:{
			Sprite*portrait = Sprite::create("6F.png");
			portrait->setAnchorPoint(Point(0, 0));
			portrait->setPosition(Point(0,0));
			this->addChild(portrait, 4, "portrait");
			portrait->setGlobalZOrder(201);
			break;
}
case 31:
case 63:{
			Sprite*portrait = Sprite::create("7F.png");
			portrait->setAnchorPoint(Point(0, 0));
			portrait->setPosition(Point(0,0));
			this->addChild(portrait, 4, "portrait");
			portrait->setGlobalZOrder(201);
			break;
}
case 44:
case 48:
case 49:
case 52:
case 53:
{
		   Sprite*portrait = Sprite::create("11F.png");
		   portrait->setAnchorPoint(Point(0, 0));
		   portrait->setPosition(Point(0,0));
		   this->addChild(portrait, 4, "portrait");
		   portrait->setGlobalZOrder(201);
		   break;
}
case 18:
case 19:
case 40:
case 41:
case 42:
case 55:
case 56:
case 57:{
			Sprite*portrait = Sprite::create("F.png");
			portrait->setAnchorPoint(Point(0, 0));
			portrait->setPosition(Point(0,0));
			this->addChild(portrait, 4, "portrait");
			portrait->setGlobalZOrder(201);
			break;
}
case 26:{
			Sprite*portrait = Sprite::create("F.png");
			portrait->setAnchorPoint(Point(0, 0));
			portrait->setPosition(Point(0,0));
			this->addChild(portrait, 4, "portrait");
			portrait->setGlobalZOrder(201);
			break;
}
case 6:
case 7:
case 8:
case 10:
case 11:
case 12:
case 45:
case 51:
case 58:
case 59:
case 60:{
			Sprite*portrait = Sprite::create("F.png");
			portrait->setAnchorPoint(Point(0, 0));
			portrait->setPosition(Point(0,0));
			this->addChild(portrait, 4, "portrait");
			portrait->setGlobalZOrder(201);
			break;
}
case 65:{
			break;
}
}
}





//�����Ǵ�����TalkLayer�����ʵ��
//��������
//ʮ���ź�����ʱ��Ҫ�������¼ܹ�
void MyMap::outDialog(Size visibleSize, int NPCNum){
	sGlobal->NPCNum = this->npc[NPCNum].NPCNum;
	//��ȡnpc�Ի���xml�ļ��е�keyֵ
	int keyStart = this->npc[NPCNum].keyStart;
	int keyEnd = this->npc[NPCNum].keyEnd;
	//����sGlobal�д����keyֵ
	//Ϊ�˷�ֹ�����¼��д����ֵ��Ī��������޸�
	//���Խ����ֵ���뵽��ȫ�ֱ�����
	sGlobal->dialogStartNum = keyStart-1;
	sGlobal->dialogEndNum = keyEnd;




	FadeIn* fadeIn = FadeIn::create(0.1f);

	sGlobal->dialogStartNum++;
	String* cKey = String::createWithFormat("%d", sGlobal->dialogStartNum);
	std::string key = cKey->_string;
	Dictionary*dialogDictionary = Dictionary::createWithContentsOfFile("wenben.xml");
	const char*dialog = ((String*)dialogDictionary->objectForKey(key))->getCString();

	//auto label = Label::createWithTTF(dialog, "ziti.TTF", 24);
	////����ط�������ĳ�visibleSize
	////���ǿ��ǵ�����lambda����������ֵ��ı�
	////Ӧ�ÿ�����ָ�봫��
	////���ǱȽ��鷳���Ҳ�������
	////����Ҫ�Ļ������Լ��İ�
	////��������
	//label->setPosition(Point(960 * 0.21, 640 * 0.25));
	//this->addChild(label, 500, 1);
	//label->setGlobalZOrder(201);
	//label->runAction(fadeIn);



	auto label = Label::createWithTTF(dialog, "ziti.TTF", 26);
	//����ط�������ĳ�visibleSize
	//���ǿ��ǵ�����lambda����������ֵ��ı�
	//Ӧ�ÿ�����ָ�봫��
	//���ǱȽ��鷳���Ҳ�������
	//����Ҫ�Ļ������Լ��İ�
	//��������
	
	label->setAnchorPoint(Point(0, 0));
	label->setPosition(Point(100, 100 ));
	this->addChild(label, 500, 1);
	label->setGlobalZOrder(201);
	label->runAction(fadeIn);

	//���������¼�
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = [&](Touch *touch, Event *event){
		//�Ҳ���֪����仰��ʲô��
		//���ǲ˵�����û����仰����ֺ���ֵ�bug
		//������Ȼ�����ò������ָ�뵫���Ǵ�������ֵ��
		auto target = static_cast<Sprite*>(event->getCurrentTarget());
		//ɾ����һ��Ի�
		this->removeChildByTag(1);
		return true;
	};
	
	listener->onTouchEnded = [&](Touch *touch, Event *event){
		auto target = static_cast<Sprite*>(event->getCurrentTarget());
		if ((sGlobal->dialogStartNum) < (sGlobal->dialogEndNum)){
			FadeIn* fadeIn = FadeIn::create(0.1f);
			
			sGlobal->dialogStartNum++;
			String* cKey = String::createWithFormat("%d", sGlobal->dialogStartNum);
			std::string key = cKey->_string;
			Dictionary*dialogDictionary = Dictionary::createWithContentsOfFile("wenben.xml");
			const char*dialog = ((String*)dialogDictionary->objectForKey(key))->getCString();

			//auto label = Label::createWithTTF(dialog, "ziti.TTF", 24);
			////����ط�������ĳ�visibleSize
			////���ǿ��ǵ�����lambda����������ֵ��ı�
			////Ӧ�ÿ�����ָ�봫��
			////���ǱȽ��鷳���Ҳ�������
			////����Ҫ�Ļ������Լ��İ�
			////��������
			//label->setPosition(Point(960 * 0.21, 640 * 0.25));
			//this->addChild(label, 500, 1);
			//label->setGlobalZOrder(201);
			//label->runAction(fadeIn);
			Sprite*portrait5 = Sprite::create("F.png");
			auto label = Label::createWithTTF(dialog, "ziti.TTF", 26);
			//����ط�������ĳ�visibleSize
			//���ǿ��ǵ�����lambda����������ֵ��ı�
			//Ӧ�ÿ�����ָ�봫��
			//���ǱȽ��鷳���Ҳ�������
			//����Ҫ�Ļ������Լ��İ�
			//��������
			label->setAnchorPoint(Point(0, 0));
			label->setPosition(Point(portrait5->getContentSize().width / 4, portrait5->getContentSize().height / 4));
			this->addChild(label, 500, 1);
			label->setGlobalZOrder(201);
			label->runAction(fadeIn);


		}
		else {
			//�˴�����
			this->removeChildByTag(1);
			this->removeChildByName("backGround");
			this->removeChildByName("portrait");
			sGlobal->hero->speekOrNot = 0;
			int i = sGlobal->dialogStartNum;
			int i2 = sGlobal->dialogEndNum;
			
			this->unusualNPC(sGlobal->visibleSize, /*this->npc[].*/sGlobal->NPCNum);
		}
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this->getChildByName("backGround"));
	//int i = sGlobal->dialogStartNum;
	//int i2 = sGlobal->dialogEndNum;
	//if (sGlobal->dialogStartNum == sGlobal->dialogEndNum){
	//	this->unusualNPC(visibleSize, /*this->npc[].*/NPCNum);
	//}
}

void MyMap::makeChoice(Size visibleSize, int NPCNum){
	if (sGlobal->hero->madeChoiceOrNot == 0){
		Sprite *choiceYes = Sprite::create("Choose1.png");
		
		this->getParent()->addChild(choiceYes, 25,"choiceYes");

		choiceYes->setPosition(Point(visibleSize.width*0.25, visibleSize.height*0.5));
		Sprite *choiceNo = Sprite::create("Choose2.png");
		
		this->getParent()->addChild(choiceNo, 25, "choiceNo");
		choiceNo->setPosition(Point(visibleSize.width*0.75, visibleSize.height*0.5));
		//��yes�ļ����¼�
		auto listenerYes = EventListenerTouchOneByOne::create();
		listenerYes->onTouchBegan = [&](Touch*youch, Event*event){
			sGlobal->hero->plot[1] = 1;
			sGlobal->hero->madeChoiceOrNot = 1;
			return true;
		};
		listenerYes->onTouchEnded = [&](Touch*touch, Event*event){
			this->getParent()-> removeChildByName("choiceYes");
			this->getParent()-> removeChildByName("choiceNo");
		};
		_eventDispatcher->addEventListenerWithSceneGraphPriority(listenerYes, choiceYes);
		//��no�ļ����¼�
		auto listenerNo = EventListenerTouchOneByOne::create();
		listenerNo->onTouchBegan = [&](Touch*youch, Event*event){
			sGlobal->hero->plot[1] = 0;
			sGlobal->hero->madeChoiceOrNot = 1;
			return true;
		};
		listenerNo->onTouchEnded = [&](Touch*touch, Event*event){
			this->removeChildByName("choiceYes");
			this->removeChildByName("choiceNo");
		};
		_eventDispatcher->addEventListenerWithSceneGraphPriority(listenerNo, choiceNo);

	}
}

void MyMap::getButterfly(){
	if (sGlobal->hero->plot[butterfly] == 0){
		//���������������Ϊtag
		this->removeChildByTag(250);
		sGlobal->hero->plot[butterfly] = 1;
	}
}

void MyMap::getBox(){
	if (sGlobal->hero->plot[box] == 0){
		//���������������Ϊtag
		this->removeChildByTag(250);
		sGlobal->hero->plot[box] = 1;
	}
}

void MyMap::getNote(){
	if (sGlobal->hero->plot[note] == 0){
		//���������������Ϊtag
		this->removeChildByTag(250);
		sGlobal->hero->plot[note] = 1;
	}
}

void MyMap::getSchedule(){
	if (sGlobal->hero->plot[mySchedule] == 0){
		//���������������Ϊtag
		this->removeChildByTag(250);
		sGlobal->hero->plot[mySchedule] = 1;
	}
}

void MyMap::getSister(){
	if (sGlobal->hero->plot[sister] == 0){
		//���������������Ϊtag
		this->removeChildByTag(250);
		sGlobal->hero->plot[sister] = 1;
	}
}

void MyMap::setDay(int day){
	if (sGlobal->hero->plot[sister+day] == 0){
		//���������������Ϊtag
		this->removeChildByTag(250);
		sGlobal->hero->plot[sister + day] = 1;
	}
}

int MyMap::getMapNum(int sceneNum){
	switch (sceneNum) {
	case 0:{
			   return 0;
			   break; 
	}
	case 1:
	case 27:{
				return 1;
				break; 
	}
	case 2:
	case 20:
	case 21:
	case 26:
	case 46:
	case 47:{
				return 2;
				break; 
	}
	case 3:
	case 8:
	case 13:
	case 19:
	case 22:
	case 28:
	case 32:
	case 39:
	case 45:
	case 48:
	case 51:{
				return 3;
				break; 
	}
	case 4:
	case 11:
	case 12:
	case 14:
	case 37:
	case 38:
	case 40:{
				return 4;
				break; 
	}
	case 25:
	case 29:
	case 31:
	case 50:{
				return 5;
				break; 
	}
	case 6:
	case 7:
	case 23:
	case 24:
	case 33:
	case 34:
	case 49:
	case 52:{
				return 6;
				break; 
	}
	case 9:
	case 10:
	case 16:
	case 36:
	case 42:{
				return 7;
				break; 
	}
	case 17:
	case 43:{
				return 8;
				break; 
	}
	case 15:
	case 41:
	case 44:{
				return 9;
				break; 
	}
	case 35:
	case 53:
	case 54:{
				return 10;
				break; 
	}
	case 5:{
			   return 11;
			   break; 
	}
	case 18:{
				return 12;
				break; 
	}
	case 30:{
				return 13;
				break; 
	}
	}
}

void MyMap::unusualNPC(Size visibleSize,int NPCNum){
	switch (NPCNum){
		//����
	case 26:{
				this->getButterfly();
				break;
	}
		//����
	case 29:{
				this->getBox();
				break;
	}
		//�ʼ�
	case 32:{
				this->getNote();
				break;
	}
		//�ճ̱�
	case 14:{
				this->getSchedule();
				break;
	}
		//��ѡ��
	case 21:{
				sGlobal->hero->plot[14] = 1;
				this->makeChoice(visibleSize,NPCNum);
				break;
	}
		//�ҵ�ѧ��
	case 51:{
				this->getSister();
				break;
	}
		//ת���ڶ���
	case 18:{
				sGlobal->hero->plot[7] = 1;
				sGlobal->hero->plot[6] = 0;
				sGlobal->gameScene->changeMap(Point(4, 4), 6);
				break;
	}
		//ת��������
	case 41:
	case 40:{
				sGlobal->hero->plot[8] = 1;
				sGlobal->hero->plot[7] = 0;
				sGlobal->gameScene->changeMap(Point(4, 4), 6);
				break;
	}
		//ת��������
	case 55:
	case 56:{
				sGlobal->hero->plot[8] = 0;
				sGlobal->hero->plot[9] = 0;
				sGlobal->gameScene->changeMap(Point(4, 4), 6);
				break;
	}
		//�¸�
	case 47:{
				sGlobal->hero->plot[10] = 1;
				break;
	}
		//����Ϊ�Ҳ�������Ĵ�������
	case 35:{
				sGlobal->hero->plot[12] = 1;
				break;
	}
	case 61:{
				sGlobal->hero->plot[13] = 1;
				break;
	}
	case 24:{
				sGlobal->hero->plot[15] = 1;
				break;
	}
	case 31:{
				sGlobal->hero->plot[16] = 1;
				break;
	}
	case 23:{
				sGlobal->hero->plot[17] = 1;
	}
	}
}
