//
// Created by engin on 22.09.2019.
//

#ifndef LIMONENGINE_QUADRENDERER_H
#define LIMONENGINE_QUADRENDERER_H

#include <cstdint>
#include <vector>
#include <map>
#include <string>
#include <memory>

class OpenGLGraphics;
class GLSLProgram;

class QuadRender {
    uint_fast32_t vao, ebo;
    std::vector<uint32_t> bufferObjects;

protected:
    OpenGLGraphics* glHelper = nullptr;
public:
    QuadRender(OpenGLGraphics* glHelper);

    void render(std::shared_ptr<GLSLProgram> renderProgram);

};


#endif //LIMONENGINE_QUADRENDERER_H
