#include "Hero.h"
#include"AnimationUtil.h"
#include "Global.h"


bool Hero::init(){
	//绑定全局变量
	this->retain();
	sGlobal->hero = this;
	//初始化剧情与物品
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
	//将图片加载到缓存池，这是共用的缓存池
	SpriteFrameCache*frameCache = SpriteFrameCache::getInstance();
	frameCache->addSpriteFramesWithFile("Hero.plist", "Hero.png");
	//用所创建的动画工具类创建动画
	Animation*animation = AnimationUtil::createWithSingleFrameNameSmall("Hero", direction, 0.1f, -1);
	//设置，行走
	m_sprite->runAction(Animate::create(animation));
}

void Hero::setViewPointByPlayer(){
	if (m_sprite == NULL){
		return;
	}
	Layer*parent = (Layer*)this->getParent()/*->getChildByName("map")*/;
	//地图方格的数量
	Size mapTiledNum = m_map->getMapSize();
	//地图单个方格大小
	Size tiledSize = m_map->getTileSize();
	//地图大小
	Size mapSize = Size(
		mapTiledNum.width*tiledSize.width,
		mapTiledNum.height*tiledSize.height);
	//屏幕大小
	Size visibleSize = Director::getInstance()->getVisibleSize();
	//主角坐标
	Point spritePos = getPosition();
	//主角坐标小于屏幕一半，取屏幕中点；否则取主角坐标
	float x = std::max(spritePos.x, visibleSize.width / 2);
	float y = std::max(spritePos.y, visibleSize.height / 2);
	//判断是否出界
	x = std::min(x, mapSize.width - visibleSize.width / 2);
	y = std::min(y, mapSize.height - visibleSize.height / 2);
	//目标点
	Point destPos = Point(x, y);
	//屏幕中点
	Point centerPos = Point(visibleSize.width / 2, visibleSize.height / 2);
	//计算屏幕中点和移动距离
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
	//hero下一步要到达的位置
	/*Point mapPos = sGlobal->map->convertToNodeSpace(Point(x, y));*/
	//Point dstPos = Point(mapPos.x + (sGlobal->moveController->m_speedX) * 16, mapPos.y + 16 * (sGlobal->moveController->m_speedY));
	Point dstPos = Point(x + (sGlobal->moveController->m_speedX)/**16*/, y+/*16**/(sGlobal->moveController->m_speedY));
	//获取该位置上的格子坐标
	Point tiledPosition = tileCoordForPosition(dstPos);

	//判断是否出界
	if ((tiledPosition.x > m_map->getMapSize().width-1) || (tiledPosition.x<0) || (tiledPosition.y>m_map->getMapSize().height-1) || (tiledPosition.y < 0)){
		return;
	}

	//判断是否遇到npc
	if (sGlobal->myMap->showDialogBox(tiledPosition)){
		return;
	}



	//获取格子的标识
	int tiledGid = meta->getTileGIDAt(tiledPosition)-1/*89*/;

	//不为0则存在格子
	//此处为穿墙外挂
	if (tiledGid != -1){
		return;
	//	获取地图格子的属性
	//	Value properties = m_map->getPropertiesForGID(tiledGid);
	//	ValueMap propValueMap = properties.asValueMap();
	//	if (1 > 2){}

	//		std::string collision = propValueMap["Collidable"].asString();
	//	  if (collision == "true") { //碰撞检测成功   
	//				/*return;*/
	//	/*	}*/
	//	/*Value prop = properties.asValueMap().at("Collidable");*/
	//	判断Collidable属性
	///*	if (prop.asString().compare("true") == 0){
	//		return;
	//	}*/
	}


	//以下代码用于场景切换触发点
	for (int i = 0; i <= 19;i++){
		if (sGlobal->myMap->transmitPoint[i] == tiledPosition){
			sGlobal->gameScene->changeMap(sGlobal->myMap->destination[i].startPosition, sGlobal->myMap->destination[i].mapNum);
			return;
		}
	}
		Entity::setTagPosition(x, y);
		//是地图跟着主角滚动
		setViewPointByPlayer();
}

Point Hero::tileCoordForPosition(Point position){
	//获取瓦片地图信息
	Size mapTiledNum = m_map->getMapSize();
	Size tiledSize = m_map->getTileSize();
	//计算得到格子坐标
	int x = position.x / tiledSize.width;
	int y = (mapTiledNum.height*32 - position.y) / tiledSize.height;
	//1的微调
	if (x > 0){
		x += 0;
	}
	if (y > 0){
		y +=0 ;
	}
	return Point(x, y);
}