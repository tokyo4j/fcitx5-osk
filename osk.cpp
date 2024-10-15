#include <fcitx/addonfactory.h>
#include <fcitx/addoninstance.h>
#include <fcitx/addonmanager.h>
#include <fcitx/inputcontext.h>
#include <fcitx/instance.h>
#include <fcitx/userinterface.h>

struct OskUI : public fcitx::UserInterface {
    fcitx::Instance *instance;
    std::vector<std::unique_ptr<fcitx::HandlerTableEntry<fcitx::EventHandler>>>
        eventHandlers;

    OskUI(fcitx::Instance *instance) : instance(instance) {
        FCITX_ERROR() << "OskUI() ";
        eventHandlers.emplace_back(instance->watchEvent(
            fcitx::EventType::InputContextInputMethodActivated,
            fcitx::EventWatcherPhase::Default, [](fcitx::Event event) {
                FCITX_ERROR() << "InputContextInputMethodActivated";
            }));
    }

    ~OskUI() {
        FCITX_ERROR() << "~OskUI()";
        eventHandlers.clear();
    }

    void update(fcitx::UserInterfaceComponent component,
                fcitx::InputContext *inputContext) {
        FCITX_ERROR() << "update()";
    }

    bool available() {
        FCITX_ERROR() << "suspend()";
        return true;
    }

    void suspend() { FCITX_ERROR() << "suspend()"; }

    void resume() { FCITX_ERROR() << "resume()"; }
};

class OskAddonFactory : public fcitx::AddonFactory {
    fcitx::AddonInstance *create(fcitx::AddonManager *manager) {
        return new OskUI(manager->instance());
    }
};

FCITX_ADDON_FACTORY(OskAddonFactory)
