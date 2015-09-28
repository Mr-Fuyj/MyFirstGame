#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "cocos2d.h"
#include "ControllerListener.h"
using namespace cocos2d;

class Controller :public Node{
public:
	//…Ë÷√º‡Ã˝∂‘œÛ
	void setControllerListener(ControllerListener *controllerListener);
protected:
	ControllerListener *m_controllerListener;
};

#endif