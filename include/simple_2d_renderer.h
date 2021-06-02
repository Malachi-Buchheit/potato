#pragma once
#include "renderer2d.h"
#include "static_sprite.h"
#include <deque>

namespace graphics {

class Simple2DRenderer : public Renderer2D {
    private:
    std::deque<const StaticSprite*> render_queue;

    public:
    void submit(const Renderable2D *renderable) override;
    void flush() override;
};

};
