#extension GL_OES_standard_derivatives : enable

precision mediump float;

uniform vec2 resolution;
//uniform vec2 mouse;
uniform float time;

void main(){
	//vec2 pos = ( gl_FragCoord.xy / resolution.xy )*8.-vec2(4.,4.);

	vec2 pos1 = ( gl_FragCoord.xy - resolution.xy )/min(10., 10.);
	vec2 pos2 = ( gl_FragCoord.xy - resolution.xy )/min(10., 10.);

	if (pos1.y>-6.) {
		pos1.y += 0.9*fract(sin(time*20000.));
	}
	if (pos2.y>-6.) {
		pos2.y += 0.9*fract(sin(time*20000.));
	}

	pos1.x *= (resolution.x/resolution.y) * 0.6;
	pos2.x *= (resolution.x/resolution.y) * 0.6;

	pos1.x += 2;
	pos2.x -= 2;


	vec3 color = vec3(0.,0.,0.0);

	float p =.4;
	float y = pow((abs(pos1.x) * abs(pos2.x)),6.2)/(2.*p)*3.3;// * (pow(abs(pos2.x),3.2)/(2.*p)*3.3));

	float dir = length((pos1 + vec2(pos1.x,y)) * (pos2 + vec2(pos2.x,y)))*sin(0.26);// * length(pos2+vec2(pos2.x,y))*sin(0.26);

	if (dir < 0.7) {
		color.rg += smoothstep(0.4,1.,.7-dir);
		color.g /=2.4;
	}
	
	color += pow(color.r,1.1);
	
	// red flame
	float p1 = .15;
        float y1 = (pow(abs(pos1.x + pos2.x),3.2)/(2.*p1)*3.3);// + (pow(abs(pos2.x),3.2)/(2.*p1)*3.3);
        float d = length(pos1+vec2(pos1.x * pos2.x,y1+2.3))*sin(0.8);// + length(pos2+vec2(pos2.x,y1+2.3))*sin(0.28) ;
        color.b += smoothstep(-.9,.9,0.27-d);
        color.g += smoothstep(-.9,.9,0.17-d);
	
	gl_FragColor = ( vec4(color,color)) ;
}