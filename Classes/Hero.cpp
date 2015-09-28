#include "Hero.h"
#include"AnimationUtil.h"
#include "Global.h"


bool Hero::init(){
	//��ȫ�ֱ���
	this->retain();
	sGlobal->hero = this;
	//��ʼ����������Ʒ
	for (int i = 0; i <= 17; i++){
		this->plot[i] = 0;
	/*	if (i <= 3){
			this->possession[i] = 0;
		}*/
	}
	plot[6] = 1;
	speekOrNot = 0;
	madeChoiceOrNot = 0;
	return true;
}

void Hero::run(char*direction){
	//��ͼƬ���ص�����أ����ǹ��õĻ����
	SpriteFrameCache*frameCache = SpriteFrameCache::getInstance();
	frameCache->addSpriteFramesWithFile("Hero.plist", "Hero.png");
	//���������Ķ��������ഴ������
	Animation*animation = AnimationUtil::createWithSingleFrameNameSmall("Hero", direction, 0.1f, -1);
	//���ã�����
	m_sprite->runAction(Animate::create(animation));
}

void Hero::setViewPointByPlayer(){
	if (m_sprite == NULL){
		return;
	}
	Layer*parent = (Layer*)this->getParent()/*->getChildByName("map")*/;
	//��ͼ���������
	Size mapTiledNum = m_map->getMapSize();
	//��ͼ���������С
	Size tiledSize = m_map->getTileSize();
	//��ͼ��С
	Size mapSize = Size(
		mapTiledNum.width*tiledSize.width,
		mapTiledNum.height*tiledSize.height);
	//��Ļ��С
	Size visibleSize = Director::getInstance()->getVisibleSize();
	//��������
	Point spritePos = getPosition();
	//��������С����Ļһ�룬ȡ��Ļ�е㣻����ȡ��������
	float x = std::max(spritePos.x, visibleSize.width / 2);
	float y = std::max(spritePos.y, visibleSize.height / 2);
	//�ж��Ƿ����
	x = std::min(x, mapSize.width - visibleSize.width / 2);
	y = std::min(y, mapSize.height - visibleSize.height / 2);
	//Ŀ���
	Point destPos = Point(x, y);
	//��Ļ�е�
	Point centerPos = Point(visibleSize.width / 2, visibleSize.height / 2);
	//������Ļ�е���ƶ�����
	Point viewPos = centerPos - destPos;
	parent->setPosition(viewPos);
}

void Hero::setTiledMap(TMXTiledMap*map){
	this->m_map = map;
	this->meta = m_map->getLayer("meta");
	this->meta->setVisible(false);
}

void Hero::setTagPosition(int x, int y){
	/*Entity::setTagPosition(x, y);*/
	/*setViewPointByPlayer();*/
	Size spriteSize = m_sprite->getContentSize();
	//hero��һ��Ҫ�����λ��
	/*Point mapPos = sGlobal->map->convertToNodeSpace(Point(x, y));*/
	//Point dstPos = Point(mapPos.x + (sGlobal->moveController->m_speedX) * 16, mapPos.y + 16 * (sGlobal->moveController->m_speedY));
	Point dstPos = Point(x + (sGlobal->moveController->m_speedX)/**16*/, y+/*16**/(sGlobal->moveController->m_speedY));
	//��ȡ��λ���ϵĸ�������
	Point tiledPosition = tileCoordForPosition(dstPos);

	//�ж��Ƿ����
	if ((tiledPosition.x > m_map->getMapSize().width-1) || (tiledPosition.x<0) || (tiledPosition.y>m_map->getMapSize().height-1) || (tiledPosition.y < 0)){
		return;
	}

	//�ж��Ƿ�����npc
	if (sGlobal->myMap->showDialogBox(tiledPosition)){
		return;
	}



	//��ȡ���ӵı�ʶ
	int tiledGid = meta->getTileGIDAt(tiledPosition)-1/*89*/;

	//��Ϊ0����ڸ���
	//�˴�Ϊ��ǽ���
	if (tiledGid != -1){
		return;
	//	��ȡ��ͼ���ӵ�����
	//	Value properties = m_map->getPropertiesForGID(tiledGid);
	//	ValueMap propValueMap = properties.asValueMap();
	//	if (1 > 2){}

	//		std::string collision = propValueMap["Collidable"].asString();
	//	  if (collision == "true") { //��ײ���ɹ�   
	//				/*return;*/
	//	/*	}*/
	//	/*Value prop = properties.asValueMap().at("Collidable");*/
	//	�ж�Collidable����
	///*	if (prop.asString().compare("true") == 0){
	//		return;
	//	}*/
	}


	//���´������ڳ����л�������
	for (int i = 0; i <= 19;i++){
		if (sGlobal->myMap->transmitPoint[i] == tiledPosition){
			sGlobal->gameScene->changeMap(sGlobal->myMap->destination[i].startPosition, sGlobal->myMap->destination[i].mapNum);
			return;
		}
	}
		Entity::setTagPosition(x, y);
		//�ǵ�ͼ�������ǹ���
		setViewPointByPlayer();
}

Point Hero::tileCoordForPosition(Point position){
	//��ȡ��Ƭ��ͼ��Ϣ
	Size mapTiledNum = m_map->getMapSize();
	Size tiledSize = m_map->getTileSize();
	//����õ���������
	int x = position.x / tiledSize.width;
	int y = (mapTiledNum.height*32 - position.y) / tiledSize.height;
	//1��΢��
	if (x > 0){
		x += 0;
	}
	if (y > 0){
		y +=0 ;
	}
	return Point(x, y);
}