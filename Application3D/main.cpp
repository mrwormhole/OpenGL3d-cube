#include <vector>
#include "Display.h"
#include "tmp_data.h"

int main()
{
	//loadThePowahOfCplusplus();
	loadThePowahOfCplusplus_textured();

	/*
	1- Fix texture bug now
	1- Think about the mesh simplification and mass drawing
	2- Optimized drawing for cube
	3- support multiple textures
	*/

	Display display;
	display.initialize();
	display.create();
	display.makeContext();
	display.logStatus();
	
	ShaderUtil shaderUtil;
	//shaderUtil.load("res/basicShader.v", "res/basicShader.f", 0);
	shaderUtil.load("res/texturedShader.v", "res/texturedShader.f", 0);

	TextureUtil textureUtil;
	//textureUtil.load("res/illuminati.png", 0);
	textureUtil.load("res/tile_1.png", 0);
	textureUtil.load("res/tile_2.png", 1);
	textureUtil.load("res/tile_3.png", 2); 

	MeshUtil meshUtil;
	Gameobject cubes[21];

	//meshUtil.create(triangleVertices, textureCoordinates, 3);
	/*meshUtil.createCube(cubeDataChunk_0_0, &cubes[0]);
	meshUtil.createCube(cubeDataChunk_1_0, &cubes[1]);
	meshUtil.createCube(cubeDataChunk_neg1_0, &cubes[2]);
	meshUtil.createCube(cubeDataChunk_0_neg1, &cubes[3]);
	meshUtil.createCube(cubeDataChunk_0_1, &cubes[4]);
	meshUtil.createCube(cubeDataChunk_4_0, &cubes[5]);
	meshUtil.createCube(cubeDataChunk_4_1, &cubes[6]);
	meshUtil.createCube(cubeDataChunk_4_neg1, &cubes[7]);
	meshUtil.createCube(cubeDataChunk_3_0, &cubes[8]);
	meshUtil.createCube(cubeDataChunk_5_0, &cubes[9]);
	meshUtil.createCube(cubeDataChunk_neg3_2, &cubes[10]);
	meshUtil.createCube(cubeDataChunk_neg3_neg2, &cubes[11]);
	meshUtil.createCube(cubeDataChunk_neg4_3, &cubes[12]);
	meshUtil.createCube(cubeDataChunk_neg4_neg3, &cubes[13]);
	meshUtil.createCube(cubeDataChunk_neg5_3, &cubes[14]);
	meshUtil.createCube(cubeDataChunk_neg5_neg3, &cubes[15]);
	meshUtil.createCube(cubeDataChunk_neg6_2, &cubes[16]);
	meshUtil.createCube(cubeDataChunk_neg6_1, &cubes[17]);
	meshUtil.createCube(cubeDataChunk_neg6_0, &cubes[18]);
	meshUtil.createCube(cubeDataChunk_neg6_neg1, &cubes[19]);
	meshUtil.createCube(cubeDataChunk_neg6_neg2, &cubes[20]);*/
	
	for (int i = 0; i < 21; i++) {
		meshUtil.createCube(massTexturedCubeDataCollection[i], &cubes[i]);

	}

	Camera camera(vec3(0, 0, 10), 70.0f, (float)(800 / 600), 0.01f, 1000.0f);

	Renderer renderer(shaderUtil, textureUtil, meshUtil, camera);
	//renderer.addGameobject(cubes[0]);
	for (int i = 0; i < 21; i++) {
		renderer.addGameobject(cubes[i]);
	}
	
	display.setCamera(camera);
	display.setRenderer(renderer);
	display.update();
	
	display.destroy();
	return 1;
}


