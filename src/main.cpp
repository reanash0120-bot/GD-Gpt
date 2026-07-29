#include <Geode/Geode.hpp>
#include <Geode/modify/EditorUI.hpp>

using namespace geode::prelude;

class GDGPTPopup : public FLAlertLayer {
protected:
    bool init() {
        if (!FLAlertLayer::init(
            nullptr,
            "GD GPT v1.00",
            "Welcome to GD GPT!\n\n"
            "AI level creation is coming soon.\n"
            "Ask me to create gameplay, designs,\n"
            "triggers, particles, or gimmicks!",
            "Close",
            nullptr,
            420.f,
            true,
            200.f,
            1.f
        )) {
            return false;
        }

        return true;
    }

public:
    static GDGPTPopup* create() {
        auto ret = new GDGPTPopup();

        if (ret && ret->init()) {
            ret->autorelease();
            return ret;
        }

        delete ret;
        return nullptr;
    }
};

class $modify(GDGPTEditorUI, EditorUI) {
public:
    bool init(LevelEditorLayer* editor) {
        if (!EditorUI::init(editor))
            return false;

        return true;
    }

    void onGDGPT(CCObject*) {
        GDGPTPopup::create()->show();
    }
};
