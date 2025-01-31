#ifndef _SINGLETON_H
#define _SINGLETON_H

template <class T>
class Singleton
{
public:
	//获取类的唯一实例
	static inline T* instance();
	//释放类的唯一实例
	void release();
protected:
	Singleton(void){}
	~Singleton(void){}
	static T* _instance;
};

template <class T>
inline T* Singleton<T>::instance()
{
	if (!_instance)
		_instance = new T;
	return _instance;
}

template <class T>
void Singleton<T>::release()
{
	if (!_instance)
		return;
	delete _instance;
	_instance = 0;
}

//cpp文件中需要先声明静态变量
#define DECLARE_SINGLETON_MEMBER(_Ty)	\
	template <> _Ty* Singleton<_Ty>::_instance = NULL;

#endif//_SINGLETON_H
