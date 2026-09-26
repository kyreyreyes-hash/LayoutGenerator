#include <Geode/Geode.hpp>
#include <Geode/modify/EditorUI.hpp>

using namespace geode::prelude;

class $modify(LayoutGeneratorEditorUI, EditorUI) {
    bool init(LevelEditorLayer* lel) {
        if (!EditorUI::init(lel))
            return false;

        auto button = CCMenuItemSpriteExtra::create(
            CCSprite::createWithSpriteFrameName("GJ_plusBtn_001.png"),
            this,
            menu_selector(LayoutGeneratorEditorUI::onGenerateLayout)
        );

        button->setID("generate-layout-button"_spr);

        if (auto menu = this->getChildByID("bottom-menu")) {
            menu->addChild(button);
            menu->updateLayout();
        }

        return true;
    }

    void onGenerateLayout(CCObject*) {
        FLAlertLayer::create(
            "Layout Generator",
            "The Layout Generator button works!",
            "OK"
        )->show();
    }
};
