#include "simple_2d_renderer.h"

using namespace graphics;

void Simple2DRenderer::submit(const Renderable2D *renderable) {
    render_queue.push_back((StaticSprite*)renderable);
}

void Simple2DRenderer::flush() {
    while(!render_queue.empty()) {
        const StaticSprite *r = render_queue.front();
        r->getVAO()->bind();
        r->getIBO()->bind();

        r->getShader().setUniformMat4("ml_matrix", math::mat4::translation(r->getPos()));
        glDrawElements(GL_TRIANGLES, r->getIBO()->getCount(), GL_UNSIGNED_SHORT, nullptr);

        r->getIBO()->unbind();
        r->getVAO()->unbind();
        render_queue.pop_front();
    }
}
