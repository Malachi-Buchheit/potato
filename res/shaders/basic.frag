#version 330 core

layout (location = 0) out vec4 color;

uniform vec4 light_color;
uniform vec2 light_pos;
uniform float light_brightness = 1.0;

in DATA { 
    vec4 pos;
    vec4 color;
} fs_in;

void main() {
    float intensity = light_brightness / length(fs_in.pos.xy - light_pos);
    //color = light_color * intensity;
    color = fs_in.color * light_color * intensity;
}
