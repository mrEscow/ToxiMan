precision mediump float;
uniform float time;
//uniform vec2  mouse;
//uniform vec2  resolution;

uniform vec2 pos;


uniform int myContSize = 3;

const int mySize = 1000; // static_cast<const int>(myContSize);

uniform vec2 positions[mySize];// = new vec2[mySize];

uniform vec2 V2positions[mySize];

uniform vec2 size;
uniform sampler2D texture;

#define PI 3.14159265359

mat2 rotate2d(float angle){
	return mat2(cos(angle), -sin(angle), sin(angle), cos(angle));
}

void main(void){

	vec2 clear = vec2(10000,10000);
	vec2 clear2 = vec2(0,0);

	for(int i = 0; i < mySize;i++)
	{
		positions[i]=clear;
	}

	positions = V2positions;



    //vec4 pixel = texture2D(texture, gl_TexCoord[0].xy); 


	//vec2 wnd = vec2(1920,1080);
	//vec2 mypos = (resolution / 2.) + vec2(mouse.x,-mouse.y);
	//vec2 mypos = (resolution / 2.) + vec2(pos.x,pos.y);

	vec2 mypos = pos;
	
	//positions[0] = pos;
	//positions[1] = vec2(100,1000);
	//positions[2] = vec2(1000,1000);

	int it = 0;

	vec4 myGiperVec = vec4(0); //  = gl_FragColor(0);

	vec4[mySize] myGiperVecMatrix;

	vec2 mySizeEfect = vec2(200,200);

	for(int i = 0; i < mySize;i++)
	{
		if(positions[i] != clear && positions[i] != clear2)
		{
			vec2 mypos = positions[i];
			vec2 p = (gl_FragCoord.xy * 1.0 - vec2(mypos.x , -mypos.y)) / min(mySizeEfect.x / 5 , mySizeEfect.y / 5 );
			p = rotate2d((time * 1.0) * PI) * p;
			float thickness = 0.256;
			float t = thickness / abs(abs(sin(time)) - length(p));
			float t2 = thickness / abs(abs(sin(time)) - length(p));
			vec4 mayvec4 = vec4(vec3(t),t2);
			myGiperVec += (vec4( vec3(p.x,p.y,1.0) , 1.) * mayvec4 - gl_Color);
		}
	}



	//for(int i = 0; i < mySize;i++)
	{
		{
			//vec2 mypos = positions[0];

			//vec2 p = (gl_FragCoord.xy * 1.0 - positions[0]) / min(size.x / 2.5 , size.y / 2.5 );

			//vec2 p = (gl_FragCoord.xy * 1.0 - mypos) / min(size.x / 2.5 , size.y / 2.5 );
			//vec2 p = 1 / 10;

			//p = rotate2d((time * 1.0) * PI) * p;

			//float thickness = 0.256;

			//float t = thickness / abs(abs(sin(time)) - length(p));
			//float t2 = thickness / abs(abs(sin(time)) - length(p));

			//vec4 mayvec4 = vec4(vec3(t),t2);

			//myGiperVec += vec4( vec3(p.x,p.y,1.0) , 1.) * mayvec4 - gl_Color ;
		}

		////////////////////////////////
		{
			//vec2 p = (gl_FragCoord.xy * 1.0 - positions[1]) / min(size.x / 2.5 , size.y / 2.5 );
			//p = rotate2d((time * 1.0) * PI) * p;
			//float thickness = 0.256;
			//float t = thickness / abs(abs(sin(time)) - length(p));
			//float t2 = thickness / abs(abs(sin(time)) - length(p));
			//vec4 mayvec4 = vec4(vec3(t),t2);
			//myGiperVec += vec4( vec3(p.x,p.y,1.0) , 1.) * mayvec4 - gl_Color ;
		}

		/////////////////////////////
	}

	//gl_FragColor = vec4(0);

	//for(int i = 0; i < mySize; i++)
	//{
		//myGiperVec += myGiperVecMatrix[i];
	//}




	gl_FragColor = myGiperVec;
}