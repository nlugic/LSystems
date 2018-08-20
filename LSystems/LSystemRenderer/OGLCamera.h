#ifndef OGLCAMERA_H
#define OGLCAMERA_H

#include "..\..\include\glm\glm.hpp"

namespace lrend
{

	enum MovementDirection
	{
		FORWARD, BACKWARDS, LEFT, RIGHT
	};

	class OGLCamera
	{
	private:
		glm::vec3 position, front, right;
		glm::vec3 up, worldUp;

		float pitch, yaw;
		float speed, sensitivity, fov;

		void updateCameraVectors();

	public:
		OGLCamera(glm::vec3 pos = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f),
			float y = -90.0f, float p = 0.0f);
		~OGLCamera() = default;

		glm::mat4 getViewMatrix();
		void move(MovementDirection direction, float deltaTime);
		void look(float xOffset, float yOffset, bool constrainPitch = true);
		void zoom(float yOffset);
	};

}

#endif
