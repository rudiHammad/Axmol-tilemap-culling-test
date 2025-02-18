#include "MainScene.h"

USING_NS_AX;



bool MainScene::init()
{

    if (!Scene::init())
    {
        return false;
    }

    auto visibleSize = _director->getVisibleSize();
    auto origin = _director->getVisibleOrigin();
    auto safeArea = _director->getSafeAreaRect();
    auto safeOrigin = safeArea.origin;


    visibleSize = Director::getInstance()->getVisibleSize();
    auto camera = Camera::createOrthographic(visibleSize.width * 2, visibleSize.height * 2, -1024, 1024);
    camera->setCameraFlag(CameraFlag::USER1);


    tileMap = new ax::FastTMXTiledMap();
    tileMap->initWithTMXFile("tilemaps/myTilemap.tmx");

    camera->addChild(tileMap);
    this->addChild(camera);

    auto sequence = Sequence::create(MoveBy::create(5, Vec2(-1300, 0)), MoveBy::create(5, Vec2(1300, 0)), nullptr);
    camera->runAction(sequence);

    //camera->setZoom(1.5);
    //camera->setZoom(0.5); no effect
    //camera->applyZoom();

    return true;
}

void MainScene::update(float delta)
{}


