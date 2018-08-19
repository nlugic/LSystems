#ifndef OGLCAMERA_H
#define OGLCAMERA_H

#include "..\..\include\glm\glm.hpp"

namespace lrend
{

	enum MovementDirection
	{
		FORWARD, BACKWARD, LEFT, RIGHT
	};

	class OGLCamera
	{
	private:
		glm::vec3 position, front, right;
		glm::vec3 up, worldUp;

		float pitch, yaw;
		float speed, sensitivity, zoom;

		void updateCameraVectors();

	public:
		OGLCamera(glm::vec3 pos = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f),
			float y = -90.0f, float p = 0.0f);
		OGLCamera(float posX, float posY, float posZ, float upX, float upY, float upZ, float y, float p);
		glm::mat4 getViewMatrix();
		void processKeyboard(MovementDirection direction, float deltaTime);
		void processMouseMovement(float xOffset, float yOffset, bool constrainPitch = true);
		void processMouseScroll(float yOffset);
	};

}

#endif
