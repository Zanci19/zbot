#include <imgui-cocos.hpp>
#include "gui.hpp"
#include "zBot.hpp"
#include <Geode/loader/SettingV3.hpp>
#include <Geode/Bindings.hpp>
#include <Geode/modify/LoadingLayer.hpp>
using namespace geode::prelude;

$execute {
    zBot* mgr = zBot::get();

    geode::listenForKeybindSettingPresses("gui_toggle", [=](Keybind const& keybind, bool down, bool repeat, double timestamp) {
        if (down && !repeat && !ImGui::GetIO().WantCaptureKeyboard) {
            GUI* gui = GUI::get();
            gui->visible = !gui->visible;

            auto pl = PlayLayer::get();

            if (!gui->visible && pl && !pl->m_isPaused) {
                PlatformToolbox::hideCursor();
            }
        }

        return ListenerResult::Propagate;
    });

    geode::listenForKeybindSettingPresses("frame_advance", [=](Keybind const& keybind, bool down, bool repeat, double timestamp) {
        if (down && !repeat && !ImGui::GetIO().WantCaptureKeyboard) {
            mgr->frameAdvance = !mgr->frameAdvance;
        }

        return ListenerResult::Propagate;
    });

    geode::listenForKeybindSettingPresses("advance_frame", [=](Keybind const& keybind, bool down, bool repeat, double timestamp) {
        mgr->doAdvance = down && !ImGui::GetIO().WantCaptureKeyboard;

        return ListenerResult::Propagate;
    });
}
