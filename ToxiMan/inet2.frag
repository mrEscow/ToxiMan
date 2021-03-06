precision mediump float;
uniform float time;
//uniform vec2  mouse;
//uniform vec2  resolution;
uniform vec2  pos;
uniform vec2  size;
uniform sampler2D texture;

#define PI 3.14159265359

mat2 rotate2d(float angle){
	return mat2(cos(angle), -sin(angle), sin(angle), cos(angle));
}

void main(void){
    //vec4 pixel = texture2D(texture, gl_TexCoord[0].xy); 


	//vec2 wnd = vec2(1920,1080);
	//vec2 mypos = (resolution / 2.) + vec2(mouse.x,-mouse.y);
	//vec2 mypos = (resolution / 2.) + vec2(pos.x,pos.y);
	vec2 mypos = pos;

	vec2 p = (gl_FragCoord.xy * 1.0 - mypos) / min(size.x / 2.5 , size.y / 2.5 );
	//vec2 p = 1 / 10;

	p = rotate2d((time * 1.0) * PI) * p;

	float thickness = 0.256;

	float t = thickness / abs(abs(sin(time)) - length(p));
	float t2 = thickness / abs(abs(sin(time)) - length(p));

	vec4 mayvec4 = vec4(vec3(t),t2);

    gl_FragColor = vec4( vec3(p.x,p.y,1.0) , 1.) * mayvec4 - gl_Color ;
}