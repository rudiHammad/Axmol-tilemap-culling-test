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

    auto driverNode = Node::create();
    addChild(driverNode);
    tileMap = new ax::FastTMXTiledMap();
    tileMap->initWithTMXFile("tilemaps/myTilemap.tmx");
    driverNode->addChild(tileMap);

    auto sequence = Sequence::create(MoveBy::create(5, Vec2(-1300, 0)), MoveBy::create(5, Vec2(1300, 0)), nullptr);
    driverNode->runAction(sequence);

    // scheduleUpdate() is required to ensure update(float) is called on every loop
    scheduleUpdate();

    return true;
}

void MainScene::update(float delta)
{}


