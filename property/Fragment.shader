#version 460 core

uniform sampler2D Texture;
in vec2 f_texture;

uniform vec3 f_color;

out vec4 FragColor;

void main(){
    if( f_texture.x != 0 || f_texture.y != 0 ){
        FragColor = texture(Texture, f_texture) * vec4(f_color, 1.0);
    }else{
        FragColor = vec4(f_color, 1.0); 
    }
}