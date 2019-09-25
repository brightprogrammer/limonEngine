//
// Created by Engin Manap on 23.03.2016.
//

#ifndef LIMONENGINE_GUILAYER_H
#define LIMONENGINE_GUILAYER_H

#include <tinyxml2.h>
#include "Graphics/OpenGLGraphics.h"

class BulletDebugDrawer;
class GUIRenderable;
class GameObject;

class GUILayer {
    OpenGLGraphics *glHelper;
    BulletDebugDrawer* debugDrawer;
    uint32_t level;
    bool isDebug;
    enum class RenderTypes {TEXT, IMAGE };
    std::vector<std::pair<GUIRenderable *, RenderTypes>> guiElements;

public:
    GUILayer(OpenGLGraphics *glHelper, BulletDebugDrawer* debugDrawer, uint32_t level) : glHelper(glHelper), debugDrawer(debugDrawer), level(level), isDebug(false) { };

    uint32_t getLevel() { return level; }

    bool getDebug() const {
        return isDebug;
    }

    void setDebug(bool isDebug) {
        GUILayer::isDebug = isDebug;
    }

    void addGuiElement(GUIRenderable *guiElement);

    void removeGuiElement(uint32_t guiElementID);

    std::vector<GameObject*> getGuiElements();

    void renderTextWithProgram(std::shared_ptr<GLSLProgram> renderProgram);
    void renderImageWithProgram(std::shared_ptr<GLSLProgram> renderProgram);

    void setupForTime(long time);

    bool serialize(tinyxml2::XMLDocument &document, tinyxml2::XMLElement *LayersListNode, Options *options);

    GUIRenderable* getRenderableFromCoordinate(const glm::vec2& coordinates);
};


#endif //LIMONENGINE_GUILAYER_H
