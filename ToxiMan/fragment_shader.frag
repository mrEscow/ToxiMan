varying in vec4 vert_pos;

uniform sampler2D texture;
uniform bool hasTexture;
//uniform vec2 lightPos;


//may
#extension GL_OES_standard_derivatives : enable

precision highp float;

uniform float time;
uniform vec2 resolution;

uniform vec2 pos;
uniform vec2 size;


void main()
{
	//Ambient light
	//vec4 ambient = vec4(0.02, 0.02, 0.5, 1.0);
	
	//Convert light to view coords
	//lightPos = (gl_ModelViewProjectionMatrix * vec4(lightPos, 0, 1)).xy;
	
	//Calculate the vector from light to pixel (Make circular)
	//vec2 lightToFrag = lightPos - vert_pos.xy;
	//lightToFrag.y = lightToFrag.y / 1.7;

	//Length of the vector (distance)
	//float vecLength = clamp(length(lightToFrag) * 2, 0, 1);

    // lookup the pixel in the texture
    vec4 pixel = texture2D(texture, gl_TexCoord[0].xy); 

	// may
	//vec2 p = (gl_FragCoord.xy * 2.0 - resolution) / min(resolution.x, resolution.y);
	//vec2 p = (gl_FragCoord.xy * 1.0 - (resolution )) / min(size.x, size.y);
	vec2 p = (gl_FragCoord.xy * 1.0 - size) / min(size.x, size.y);


	float l = 10. * abs(sin(time * 1.0)) / length(p);
	vec4 my_test = vec4(vec3(l), 1.0);

    // multiply it by the color and lighting
	if(hasTexture == true)
	{
		// may test
		//gl_FragColor = 1,0, 0, 1;
		gl_FragColor = gl_Color * pixel * my_test;
		//gl_FragColor =  my_test;

		//gl_FragColor = gl_Color * pixel * (clamp(ambient + vec4(1-vecLength, 1-vecLength, 1-vecLength, 1), 0, 1));  //cool
	}
	else
	{
		gl_FragColor = gl_Color;
	}
}